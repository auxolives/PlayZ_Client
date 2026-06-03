class InediaInvismanCompat
{
	static bool TryGetInvismanPerkValue(PlayerBase player, out float perkValue)
	{
		perkValue = 0;
		
#ifdef TERJE_SKILLS_MOD
		if (player && player.GetTerjeSkills() && player.GetTerjeSkills().GetPerkValue("stlth", "invisman", perkValue))
		{
			return true;
		}
#endif
		
		return false;
	}
	
	static float GetVisionMultiplier(PlayerBase player)
	{
		float perkValue;
		if (!TryGetInvismanPerkValue(player, perkValue))
		{
			return 1.0;
		}
		
		// Conservative floor to avoid invalidating infected logic at high perk ranks.
		return Math.Clamp(1.0 + perkValue, 0.35, 1.0);
	}
	
	static float GetNoiseMultiplier(PlayerBase player)
	{
		float perkValue;
		if (!TryGetInvismanPerkValue(player, perkValue))
		{
			return 1.0;
		}
		
		// Keep noise reductions slightly less aggressive than vision.
		return Math.Clamp(1.0 + perkValue, 0.4, 1.0);
	}
	
	static float ApplySmellRadius(PlayerBase player, float defaultRadiusMeters)
	{
		float perkValue;
		if (!TryGetInvismanPerkValue(player, perkValue))
		{
			return defaultRadiusMeters;
		}
		
		float smellMultiplier = Math.Clamp(1.0 + perkValue, 0.45, 1.0);
		return defaultRadiusMeters * smellMultiplier;
	}
}
