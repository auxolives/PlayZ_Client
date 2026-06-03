modded class PlayerBase
{
    float m_PlayZGunPlay_VegExitTimer = 0;
    bool  m_PlayZGunPlay_IsInsideVeg  = false;
    static ref map<string, bool> s_PlayZGunPlay_VegTypeCache;
    
    protected bool PlayZGunPlay_IsVehicleTransitionState(int pCurrentCommandID)
    {
        if (pCurrentCommandID == DayZPlayerConstants.COMMANDID_VEHICLE)
            return true;
        
        if (GetCommand_Vehicle())
            return true;
        
        Object parentObj = GetParent();
        if (parentObj && parentObj.IsInherited(Transport))
            return true;
        
        return false;
    }

    override void OnCommandHandlerTick(float delta_time, int pCurrentCommandID)
    {
        super.OnCommandHandlerTick(delta_time, pCurrentCommandID);

        if (!IsAlive()) return;
        if (!m_MovementState) return;
        if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;

        PlayZGunPlayConfig cfg = PlayZGunPlayManager.GetGunPlay();
        if (!cfg || !cfg.m_EnableVegetationSwayPenalty) return;

        // Skip calculations if swimming, driving, or on ladders
        if (pCurrentCommandID == DayZPlayerConstants.COMMANDID_SWIM || pCurrentCommandID == DayZPlayerConstants.COMMANDID_LADDER || PlayZGunPlay_IsVehicleTransitionState(pCurrentCommandID))
        {
            m_PlayZGunPlay_IsInsideVeg = false;
            return;
        }

        // Only check vegetation if holding a firearm
        Weapon_Base weapon = Weapon_Base.Cast(GetHumanInventory().GetEntityInHands());
        if (!weapon)
        {
            m_PlayZGunPlay_IsInsideVeg = false;
            return;
        }

        // --- 1Hz Throttled Vegetation Check ---
        m_PlayZGunPlay_VegExitTimer -= delta_time;
        if (m_PlayZGunPlay_VegExitTimer <= 0)
        {
            m_PlayZGunPlay_VegExitTimer = 1.0;
            m_PlayZGunPlay_IsInsideVeg = PlayZGunPlay_IsCollidingWithVegetationAiming();
        }
    }

    bool PlayZGunPlay_IsCollidingWithVegetationAiming()
    {
        vector orientation = Vector(0, 0, 0);
        vector edgeLength  = Vector(1.85, 1.5, 1.85);
        array<Object> excludedObjects = new array<Object>;
        excludedObjects.Insert(this);
        array<Object> collidedObjects = new array<Object>;

        if (GetGame().IsBoxColliding(GetPosition(), orientation, edgeLength, excludedObjects, collidedObjects))
        {
            if (!s_PlayZGunPlay_VegTypeCache)
                s_PlayZGunPlay_VegTypeCache = new map<string, bool>();

            int collidedCount = collidedObjects.Count();
            for (int i = 0; i < collidedCount; ++i)
            {
                WoodBase colObject = WoodBase.Cast(collidedObjects.Get(i));
                if (colObject)
                {
                    string className = colObject.GetType();
                    bool isVeg = false;

                    if (s_PlayZGunPlay_VegTypeCache.Find(className, isVeg))
                    {
                        if (isVeg) return true;
                        continue;
                    }

                    // Cache miss — run string checks once and store result
                    string lowerClass = className;
                    lowerClass.ToLower();

                    int len = lowerClass.Length();
                    if (len >= 3)
                    {
                        string suffix3 = lowerClass.Substring(len - 3, 3);

                        if (suffix3 == "_1s" || suffix3 == "_1f")
                        {
                            if (len >= 4 && lowerClass.Substring(len - 4, 4) == "_1sb")
                            {
                                s_PlayZGunPlay_VegTypeCache.Insert(className, false);
                                continue;
                            }

                            s_PlayZGunPlay_VegTypeCache.Insert(className, true);
                            return true;
                        }
                    }

                    if (lowerClass.Contains("_2s_") || lowerClass.Contains("_2sb_") || lowerClass.Contains("_1f_") || lowerClass.Contains("_1sb_") || lowerClass.Contains("_1s_"))
                    {
                        s_PlayZGunPlay_VegTypeCache.Insert(className, true);
                        return true;
                    }

                    s_PlayZGunPlay_VegTypeCache.Insert(className, false);
                }
            }
        }
        return false;
    }
}
