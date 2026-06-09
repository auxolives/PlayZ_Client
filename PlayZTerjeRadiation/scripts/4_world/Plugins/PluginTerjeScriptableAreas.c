modded class PluginTerjeScriptableAreas
{
	float PlayZGetEnvironmentRadiationWithRain(EntityAI entity)
	{
		float environmentRadiation = CalculateTerjeEffectValue(entity, "rad");
		float rainRadiation = GetEnvironmentRainRadioactivity();
		if (rainRadiation > 0)
		{
			EntityAI root = entity.GetHierarchyRoot();
			if (!root)
			{
				root = entity;
			}

			if (root && !MiscGameplayFunctions.IsUnderRoof(root))
			{
				environmentRadiation = environmentRadiation + rainRadiation;
			}
		}

		return environmentRadiation;
	}
}
