// ADS entry offset filter for sGunplay.
// Each time the player raises their weapon into ADS (ironsights or optics),
// a small random X/Y aim offset is injected and smoothly decays to zero.
// This prevents reliable quick-scoping with a fixed fake crosshair overlay.
class AimingModelFilterADSEntryOffset extends AimingModelFilterBase
{
    protected float m_OffsetX;
    protected float m_OffsetY;
    protected float m_VelX[1];
    protected float m_VelY[1];
    protected bool  m_WasInADS;

    void AimingModelFilterADSEntryOffset(DayZPlayerImplementAiming aimingModel)
    {
        m_aimingModel = aimingModel;
    }

    override void onRaiseBegin()
    {
        // Clear state when weapon is lowered so a fresh offset fires on re-raise
        m_OffsetX      = 0;
        m_OffsetY      = 0;
        m_VelX[0]      = 0;
        m_VelY[0]      = 0;
        m_WasInADS     = false;
    }

    override bool isActive()
    {
        PlayZGunPlayConfig cfg = PlayZGunPlayManager.GetGunPlay();
        if (!cfg) return false;
        return cfg.m_EnableADSEntryOffset;
    }

    override void onUpdate(float pDt, SDayZPlayerAimingModel pModel, int stanceIndex)
    {
        PlayerBase pb = getPlayer();
        if (!pb) return;
        if (pb.GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;

        PlayZGunPlayConfig cfg = PlayZGunPlayManager.GetGunPlay();
        if (!cfg) return;

        bool inADS = pb.IsInOptics() || pb.IsInIronsights();

        if (inADS)
        {
            if (!m_WasInADS)
            {
                // First frame in ADS — fire a fresh random offset
                m_OffsetX  = Math.RandomFloat(-cfg.m_ADSEntryOffsetMaxX, cfg.m_ADSEntryOffsetMaxX);
                m_OffsetY  = Math.RandomFloat(-cfg.m_ADSEntryOffsetMaxY, cfg.m_ADSEntryOffsetMaxY);
                m_VelX[0]  = 0;
                m_VelY[0]  = 0;
            }

            // Decay toward zero
            m_OffsetX = Math.SmoothCD(m_OffsetX, 0, m_VelX, cfg.m_ADSEntryOffsetDecayTime, 1000, pDt);
            m_OffsetY = Math.SmoothCD(m_OffsetY, 0, m_VelY, cfg.m_ADSEntryOffsetDecayTime, 1000, pDt);

            pModel.m_fAimXHandsOffset += m_OffsetX;
            pModel.m_fAimYHandsOffset += m_OffsetY;
        }
        else
        {
            // Outside ADS — zero state so next entry always gets a fresh offset
            m_OffsetX  = 0;
            m_OffsetY  = 0;
            m_VelX[0]  = 0;
            m_VelY[0]  = 0;
        }

        m_WasInADS = inADS;
    }
}
