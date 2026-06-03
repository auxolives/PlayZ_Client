modded class PlayerBase
{
    protected float m_PlayZ_CachedTerjeWeightMod = 0;
    protected float m_PlayZ_TerjeModCacheTimestamp = -1;

    override float PlayZMovement_GetTerjeWeightModifier()
    {
        float modValue = super.PlayZMovement_GetTerjeWeightModifier();
        
        float currentTime = GetGame().GetTime();
        if (m_PlayZ_TerjeModCacheTimestamp < 0 || (currentTime - m_PlayZ_TerjeModCacheTimestamp) > 10000)
        {
            if (GetTerjeSkills())
            {
                float maxWeightMod = 0;
                if (GetTerjeSkills().GetPerkValue("strng", "maxweightmod", maxWeightMod))
                {
                    m_PlayZ_CachedTerjeWeightMod = maxWeightMod;
                    m_PlayZ_TerjeModCacheTimestamp = currentTime;
                }
            }
        }
        
        modValue += m_PlayZ_CachedTerjeWeightMod;
        return modValue;
    }
}
