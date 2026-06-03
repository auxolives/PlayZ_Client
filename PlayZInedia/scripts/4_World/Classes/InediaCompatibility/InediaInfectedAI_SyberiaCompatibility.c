modded class InediaInfectedAI_SyberiaCompatibility
{
	override static float GetSyberiaStealthNoiseMultiplier(PlayerBase player)
	{
		float result = super.GetSyberiaStealthNoiseMultiplier(player);
		float invismanMultiplier = InediaInvismanCompat.GetNoiseMultiplier(player);
		
		return Math.Clamp(result * invismanMultiplier, 0.1, 2.0);
	}
	
	override static float GetSyberiaStealthVisibilityMultiplier(PlayerBase player)
	{
		float result = super.GetSyberiaStealthVisibilityMultiplier(player);
		float perkValue = 0;
		
		if (InediaInvismanCompat.TryGetInvismanPerkValue(player, perkValue))
		{
#ifdef TERJE_SKILLS_MOD
			// Neutralize legacy Inedia/Terje invisman contribution from super, then apply PlayZ authority.
			float legacyMultiplier = Math.Clamp(1.0 + perkValue, 0.3, 1.0);
			if (legacyMultiplier > 0)
			{
				result = result / legacyMultiplier;
			}
#endif
			
			result = result * InediaInvismanCompat.GetVisionMultiplier(player);
		}
		
		return Math.Clamp(result, 0.3, 1.0);
	}
}
