// Vegetation aim-disruption filter for sGunplay.
// Amplifies base sway when the player's weapon is inside bushes or trees,
// and fires random branch-snag jolts at wind-modulated intervals.
// Plugs into the sGunplay AimingModelFilterBase pipeline via
// DayZPlayerImplementAiming.registerFilters().
class AimingModelFilterVegetation extends AimingModelFilterBase
{
    // Smooth-damp state for the penalty buildup (0 = clear, peaks at 0.75)
    protected float m_VegPenaltyCurrent;
    protected float m_VegPenaltyVel[1];

    // Cached wind ratio (0..1) — updated every 500ms to avoid per-snag GetWeather() calls
    protected float m_CachedWindRatio = 0;
    protected float m_WindUpdateTimer = 0;

    // Snag logic state
    protected float m_VegSnagTimer;
    protected float m_VegSnagTargetX;
    protected float m_VegSnagTargetY;
    protected float m_VegSnagCurrentX;
    protected float m_VegSnagCurrentY;
    protected float m_VegSnagVelX[1];
    protected float m_VegSnagVelY[1];

    void AimingModelFilterVegetation(DayZPlayerImplementAiming aimingModel)
    {
        m_aimingModel = aimingModel;
    }

    override void onRaiseBegin()
    {
        // If the player lowered their weapon and walked out of the bush,
        // instantly clear the penalty so it doesn't artificially fade in
        // the next time they raise their weapon.
        PlayerBase pb = getPlayer();
        if (!pb || !pb.m_PlayZGunPlay_IsInsideVeg)
        {
            m_VegPenaltyCurrent  = 0;
            m_VegPenaltyVel[0]   = 0;
            m_VegSnagTimer       = 0;
            m_VegSnagTargetX     = 0;
            m_VegSnagTargetY     = 0;
            m_VegSnagCurrentX    = 0;
            m_VegSnagCurrentY    = 0;
            m_VegSnagVelX[0]     = 0;
            m_VegSnagVelY[0]     = 0;
        }
    }

    override bool isActive()
    {
        PlayZGunPlayConfig cfg = PlayZGunPlayManager.GetGunPlay();
        if (!cfg) return false;
        return cfg.m_EnableVegetationSwayPenalty;
    }

    override void onUpdate(float pDt, SDayZPlayerAimingModel pModel, int stanceIndex)
    {
        PlayerBase pb = getPlayer();
        if (!pb) return;
        if (pb.GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;

        PlayZGunPlayConfig cfg = PlayZGunPlayManager.GetGunPlay();
        if (!cfg) return;

        float targetVeg = 0;
        if (pb.m_PlayZGunPlay_IsInsideVeg)
            targetVeg = 0.75;

        // Build up slowly over 2 seconds, drop back out just as slowly
        m_VegPenaltyCurrent = Math.SmoothCD(m_VegPenaltyCurrent, targetVeg, m_VegPenaltyVel, 2.0, 1000, pDt);

        if (m_VegPenaltyCurrent > 0.01)
        {
            // Update cached wind ratio every 500ms
            m_WindUpdateTimer -= pDt;
            if (m_WindUpdateTimer <= 0)
            {
                m_WindUpdateTimer = 0.5;
                Weather windWeather = GetGame().GetWeather();
                if (windWeather && windWeather.GetWindMaximumSpeed() > 0)
                    m_CachedWindRatio = Math.Clamp(windWeather.GetWindSpeed() / windWeather.GetWindMaximumSpeed(), 0, 1);
                else
                    m_CachedWindRatio = 0;
            }

            // --- Sway amplification (suppressible by hold-breath) ---
            // Scales whatever sway the earlier breathing/movement filters already added.
            float vegMul = 1.0 + (m_VegPenaltyCurrent * (cfg.m_VegetationSwayPenaltyScale - 1.0));
            pModel.m_fAimXHandsOffset = pModel.m_fAimXHandsOffset * vegMul;
            pModel.m_fAimYHandsOffset = pModel.m_fAimYHandsOffset * vegMul;

            // --- Branch snag intensity, scaled by stance ---
            // Crouching or going prone inside a bush makes it worse.
            float snagIntensity = m_VegPenaltyCurrent;

            if (pb.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDPRONE | DayZPlayerConstants.STANCEMASK_PRONE))
                snagIntensity *= 2.0;
            else if (pb.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDCROUCH | DayZPlayerConstants.STANCEMASK_CROUCH))
                snagIntensity *= 1.5;

            // --- Snag timer: fire a jolt, then wait a wind-modulated interval ---
            m_VegSnagTimer -= pDt;
            if (m_VegSnagTimer <= 0)
            {
                float wind01 = m_CachedWindRatio;

                // High wind = more frequent snags
                float maxInterval = Math.Lerp(cfg.m_VegSnagMaxInterval, cfg.m_VegSnagMinInterval * 3.0, wind01);
                m_VegSnagTimer = Math.RandomFloat(cfg.m_VegSnagMinInterval, maxInterval);

                // Generate a random directional jolt; wind adds force
                float windForceScale = Math.Lerp(1.0, cfg.m_VegSnagWindScale, wind01);
                float snagForce = Math.RandomFloat(1.0, 3.0) * snagIntensity * windForceScale * cfg.m_VegSnagIntensityScale;
                float angle = Math.RandomFloat(0, Math.PI * 2);
                m_VegSnagTargetX = Math.Cos(angle) * snagForce;
                m_VegSnagTargetY = Math.Sin(angle) * snagForce;
            }

            // Rapidly decay the target back to 0 — jolt is a burst, not a sustained drift
            m_VegSnagTargetX = Math.Lerp(m_VegSnagTargetX, 0, pDt * 4.0);
            m_VegSnagTargetY = Math.Lerp(m_VegSnagTargetY, 0, pDt * 4.0);

            // Smoothly chase the decaying target
            m_VegSnagCurrentX = Math.SmoothCD(m_VegSnagCurrentX, m_VegSnagTargetX, m_VegSnagVelX, 0.15, 1000, pDt);
            m_VegSnagCurrentY = Math.SmoothCD(m_VegSnagCurrentY, m_VegSnagTargetY, m_VegSnagVelY, 0.15, 1000, pDt);

            // Apply snag directly (additive, NOT suppressible by hold-breath)
            pModel.m_fAimXHandsOffset += m_VegSnagCurrentX;
            pModel.m_fAimYHandsOffset += m_VegSnagCurrentY;
        }
    }
}
