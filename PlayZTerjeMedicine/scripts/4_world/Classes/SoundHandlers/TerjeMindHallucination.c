enum TMH_Cond
{
    NONE = 0,
    INSIDE_BUILDING_ONLY = 1,
    OUTSIDE_ONLY = 2,
    ALT_GE_200_ONLY = 4
}

class TMH_SoundEntry
{
    string m_Name;
    float m_Rmin;
    float m_Rmax;
    int m_Cond;
    float m_Weight;
    bool m_IsCfgSound;

    void TMH_SoundEntry(string name, float rmin, float rmax, int cond = TMH_Cond.NONE, float weight = 1.0, bool isCfgSound = false)
    {
        m_Name = name;
        m_Rmin = rmin;
        m_Rmax = rmax;
        m_Cond = cond;
        m_Weight = weight;
        m_IsCfgSound = isCfgSound;
    }
}

class TerjeMindHallucinationClient
{
    // Level 5 (Highest insanity)
    const float L5_MIN_SEC = 5.0;
    const float L5_MAX_SEC = 30.0;

    // Level 4
    const float L4_MIN_SEC = 10.0;
    const float L4_MAX_SEC = 60.0;

    // Level 3
    const float L3_MIN_SEC = 15.0;
    const float L3_MAX_SEC = 90.0;

    // --------------------------------------------------------

    protected PlayerBase m_Player;
    protected float m_NextTime;

    // Pre-filtered pools built once at init — eliminates per-play O(n) scan over all 142 entries.
    // m_InsideBuildingPool : entries valid when INSIDE a building (NONE + INSIDE_BUILDING_ONLY)
    // m_OutsidePool        : entries valid when OUTSIDE (NONE only)
    // m_AltPool            : entries requiring altitude >= 200m (ALT_GE_200_ONLY)
    protected ref array<ref TMH_SoundEntry> m_InsideBuildingPool;
    protected float m_InsideBuildingPoolWeight;
    protected ref array<ref TMH_SoundEntry> m_OutsidePool;
    protected float m_OutsidePoolWeight;
    protected ref array<ref TMH_SoundEntry> m_AltPool;
    protected float m_AltPoolWeight;

    static const float PI2 = Math.PI * 2.0;

    void TerjeMindHallucinationClient(PlayerBase player)
    {
        m_Player      = player;
        m_NextTime    = 0;

        m_InsideBuildingPool = new array<ref TMH_SoundEntry>();
        m_OutsidePool        = new array<ref TMH_SoundEntry>();
        m_AltPool            = new array<ref TMH_SoundEntry>();

        m_InsideBuildingPoolWeight = 0;
        m_OutsidePoolWeight        = 0;
        m_AltPoolWeight            = 0;

        // GUN JAMMING (INSIDE ONLY)
        AddEntry(new TMH_SoundEntry("Mosin_jamming1_SoundSet", 4, 12, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));
        AddEntry(new TMH_SoundEntry("Famas_jamming1_SoundSet", 4, 12, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));
        AddEntry(new TMH_SoundEntry("CZ550_jamming1_SoundSet", 4, 12, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));
        AddEntry(new TMH_SoundEntry("SVD_jamming1_SoundSet", 4, 12, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));
        AddEntry(new TMH_SoundEntry("IZH43_jamming1_SoundSet", 4, 12, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));
        AddEntry(new TMH_SoundEntry("CZ61_jamming1_SoundSet", 4, 12, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));
        AddEntry(new TMH_SoundEntry("ump45_jamming1_SoundSet", 4, 12, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));
        AddEntry(new TMH_SoundEntry("M14_jamming1_SoundSet", 4, 12, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));

        // OTHERS (INSIDE ONLY)
        AddEntry(new TMH_SoundEntry("ShoulderL_Hide_Rifle_SoundSet", 2, 6, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));
        AddEntry(new TMH_SoundEntry("Bodyfall_asphalt_int_Char_SoundSet", 2, 6, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));

        // ANIMALS
        AddEntry(new TMH_SoundEntry("DeerRoarX5_SoundSet", 150, 400, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("DeerFemRoarX5_SoundSet", 150, 400, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("DoeBarkX5_SoundSet", 150, 500, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("WolfHowl6_tailDistant_SoundSet", 250, 700, TMH_Cond.NONE, 0.75, true));
        AddEntry(new TMH_SoundEntry("WolfHowl5_tailDistant_SoundSet", 250, 700, TMH_Cond.NONE, 0.75, true));
        AddEntry(new TMH_SoundEntry("WolfHowl4_tailDistant_SoundSet", 250, 700, TMH_Cond.NONE, 0.75, true));
        AddEntry(new TMH_SoundEntry("WolfHowl3_tailDistant_SoundSet", 250, 700, TMH_Cond.NONE, 0.75, true));
        AddEntry(new TMH_SoundEntry("WolfHowl2_tailDistant_SoundSet", 250, 700, TMH_Cond.NONE, 0.75, true));

        // INFECTED
        AddEntry(new TMH_SoundEntry("ZmbM_Normal_CallToArmsShort_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbF_Normal_CallToArmsShort_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbM_Skinny_CallToArmsShort_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbF_Skinny_CallToArmsShort_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbM_HikerSkinny_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbM__Runner_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbM_MechanicSkinny_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbM_PatientSkinny_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbM_priestPopSkinny_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbM_FirefighterNormal_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbM_Soldier_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbM_MotobikerFat_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbF_JournalistNormal_LT_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbF_SurvivorNormal_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbF_MechanicNormal_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbF_Clerk_Normal_LT_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbF_CitizenBSkinny_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("ZmbF_Runner_Base_DisturbedIdle_Soundset", 20, 60, TMH_Cond.NONE, 1.0, true));

        // BOLT RIFLES
        AddEntry(new TMH_SoundEntry("Mosin9130_Shot_SoundSet", 30, 1000, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("SKS_Shot_SoundSet", 30, 1000, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("CR527_Shot_SoundSet", 30, 1000, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("B95_Shot_SoundSet", 30, 1000, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("Repeater_Shot_SoundSet", 30, 1000, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("CZ550_Shot_SoundSet", 30, 1000, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("SVD_Shot_SoundSet", 30, 1000, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("Winchester70_Shot_SoundSet", 30, 1000, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("IZH43Double_Shot_SoundSet", 10, 200, TMH_Cond.NONE, 1.0, true));

        // PISTOLS
        AddEntry(new TMH_SoundEntry("Glock19_Shot_SoundSet", 5, 200, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("FNX45_Shot_SoundSet", 5, 200, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("CZ75_Shot_SoundSet", 5, 200, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("Colt1911_Shot_SoundSet", 5, 200, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("Makarov_Shot_SoundSet", 5, 200, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("Magnum_Shot_SoundSet", 5, 200, TMH_Cond.NONE, 1.0, true));

        // BEARS (ALTITUDE ONLY)
        AddEntry(new TMH_SoundEntry("BearGrowl_SoundSet", 50, 140, TMH_Cond.ALT_GE_200_ONLY, 1.5, true));
        AddEntry(new TMH_SoundEntry("BearGrowl_4_SoundSet", 50, 250, TMH_Cond.ALT_GE_200_ONLY, 1.5, true));

        // SPOOKY
        AddEntry(new TMH_SoundEntry("SpookyArea_Badger_SoundSet", 5, 20, TMH_Cond.NONE, 1.5, true));
        AddEntry(new TMH_SoundEntry("SpookyArea_Hedgehog_SoundSet", 5, 20, TMH_Cond.NONE, 1.5, true));
        AddEntry(new TMH_SoundEntry("SpookyArea_IntenseFoliageRustle_SoundSet", 5, 20, TMH_Cond.NONE, 1.5, true));
        AddEntry(new TMH_SoundEntry("SpookyArea_RunOnConcrete_SoundSet", 5, 20, TMH_Cond.INSIDE_BUILDING_ONLY, 1.5, true));

        // OTHERS
        AddEntry(new TMH_SoundEntry("HeliCrash_Distant_SoundSet", 400, 1200, TMH_Cond.NONE, 1.2, true));
        AddEntry(new TMH_SoundEntry("Sakhal_CaveWaterDrops_SoundSet", 1, 5, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));
        AddEntry(new TMH_SoundEntry("WindObjectInner4Metal2_Hi_SoundSet", 15, 50, TMH_Cond.INSIDE_BUILDING_ONLY, 1.0, true));
        AddEntry(new TMH_SoundEntry("CivilianSedan_engine_start_SoundSet", 15, 50, TMH_Cond.NONE, 0.75, true));
        AddEntry(new TMH_SoundEntry("Hatchback_02_engine_start_SoundSet", 15, 50, TMH_Cond.NONE, 0.75, true));
        AddEntry(new TMH_SoundEntry("Landmine_Explosion_SoundSet", 100, 800, TMH_Cond.NONE, 1.0, true));
        AddEntry(new TMH_SoundEntry("Grenade_explosion_SoundSet", 100, 800, TMH_Cond.NONE, 1.0, true));
    }

    // Classify one entry into the correct pre-filtered pool(s) at init time.
    protected void AddEntry(TMH_SoundEntry e)
    {
        float w = Math.Max(e.m_Weight, 0.01);

        if ((e.m_Cond & TMH_Cond.ALT_GE_200_ONLY) != 0)
        {
            m_AltPool.Insert(e);
            m_AltPoolWeight += w;
            return;
        }

        // Entry is valid outside (NONE = no restriction, or OUTSIDE_ONLY)
        if ((e.m_Cond & TMH_Cond.INSIDE_BUILDING_ONLY) == 0)
        {
            m_OutsidePool.Insert(e);
            m_OutsidePoolWeight += w;
        }

        // Entry is valid inside (NONE or INSIDE_BUILDING_ONLY)
        m_InsideBuildingPool.Insert(e);
        m_InsideBuildingPoolWeight += w;
    }

    private bool IsLocalPlayerOwned()
    {
        if (GetGame().IsDedicatedServer())
            return false;

        PlayerBase ownerPB;
        Class.CastTo(ownerPB, GetGame().GetPlayer());
        if (!ownerPB)
            return false;

        return (ownerPB == m_Player);
    }

    void Update()
    {
        if (!m_Player) return;
        if (!m_Player.IsAlive()) return;
        if (m_Player.IsUnconscious()) return;
        if (!IsLocalPlayerOwned()) return;

        TerjePlayerStats stats = m_Player.GetTerjeStats();
        if (!stats) return;

        int mindLevel = stats.GetMindLevel();

        float intervalMin;
        float intervalMax;

        // Determine interval based on hardcoded constants
        if (mindLevel >= 5)
        {
            intervalMin = L5_MIN_SEC;
            intervalMax = L5_MAX_SEC;
        }
        else if (mindLevel >= 4)
        {
            intervalMin = L4_MIN_SEC;
            intervalMax = L4_MAX_SEC;
        }
        else if (mindLevel >= 3)
        {
            intervalMin = L3_MIN_SEC;
            intervalMax = L3_MAX_SEC;
        }
        else
        {
            m_NextTime = 0;
            return;
        }

        float now = GetGame().GetTime();

        if (m_NextTime <= 0)
        {
            float firstInterval = Math.RandomFloatInclusive(intervalMin, intervalMax);
            m_NextTime = now + firstInterval * 1000.0;
            return;
        }

        // Early exit before expensive spatial queries.
        // GetPosition() and IsSoundInsideBuilding() only run when a sound is actually about to play.
        if (now < m_NextTime) return;

        vector pos = m_Player.GetPosition();
        bool insideBuilding = m_Player.IsSoundInsideBuilding();
        bool altOK = pos[1] >= 200;

        TryPlay(pos, insideBuilding, altOK);

        float interval = Math.RandomFloatInclusive(intervalMin, intervalMax);
        m_NextTime = now + interval * 1000.0;
    }

    // Pick and play one hallucination sound using the pre-filtered pools.
    // No per-call scan over the full entry list — O(1) pool selection, O(k) weighted pick.
    protected void TryPlay(vector origin, bool insideBuilding, bool altOK)
    {
        array<ref TMH_SoundEntry> generalPool;
        float totalGeneral;

        if (insideBuilding)
        {
            generalPool  = m_InsideBuildingPool;
            totalGeneral = m_InsideBuildingPoolWeight;
        }
        else
        {
            generalPool  = m_OutsidePool;
            totalGeneral = m_OutsidePoolWeight;
        }

        int generalCount = generalPool.Count();
        if (generalCount > 0)
        {
            float r1 = Math.RandomFloat01() * totalGeneral;
            TMH_SoundEntry pick1 = generalPool[generalCount - 1];
            float a1 = 0;
            for (int j1 = 0; j1 < generalCount; j1++)
            {
                pick1 = generalPool[j1];
                a1 += Math.Max(pick1.m_Weight, 0.01);
                if (r1 <= a1)
                    break;
            }
            float rad1 = Math.RandomFloatInclusive(pick1.m_Rmin, pick1.m_Rmax);
            PlayHallucinationAtOffset(pick1, origin, rad1);
        }
        else if (altOK && m_AltPool.Count() > 0)
        {
            float r2 = Math.RandomFloat01() * m_AltPoolWeight;
            int altCount = m_AltPool.Count();
            TMH_SoundEntry pick2 = m_AltPool[altCount - 1];
            float a2 = 0;
            for (int j2 = 0; j2 < altCount; j2++)
            {
                pick2 = m_AltPool[j2];
                a2 += Math.Max(pick2.m_Weight, 0.01);
                if (r2 <= a2)
                    break;
            }
            float rad2 = Math.RandomFloatInclusive(pick2.m_Rmin, pick2.m_Rmax);
            PlayHallucinationAtOffset(pick2, origin, rad2);
        }
    }

    protected void PlayHallucinationAtOffset(TMH_SoundEntry entry, vector origin, float radius)
    {
        float theta = Math.RandomFloat01() * PI2;
        vector offset = Vector(Math.Cos(theta) * radius, 0, Math.Sin(theta) * radius);
        vector targetPos = origin + offset;

        if (entry.m_IsCfgSound)
        {
            SoundParams params = new SoundParams(entry.m_Name);
            SoundObjectBuilder builder = new SoundObjectBuilder(params);
            builder.AddEnvSoundVariables(targetPos);
            SoundObject so = builder.BuildSoundObject();

            if (so)
            {
                so.SetPosition(targetPos);
                GetGame().GetSoundScene().Play3D(so, builder);
            }
        }
        else
        {
            EffectSound s = SEffectManager.PlaySound(entry.m_Name, targetPos, 0.0, 0.25, false);
            if (s)
            {
                s.SetAutodestroy(true);
            }
        }
    }
}
