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

	//! Raw environmental dose (zone + rain + nearest entities). Dosimeter-aligned; apply protection separately for PPE.
	float PlayZGetRawEnvironmentDoseForPPE(EntityAI entity)
	{
		if (!entity)
		{
			return 0;
		}

		float result = PlayZGetEnvironmentRadiationWithRain(entity);

		float nearestRadius = GetTerjeSettingFloat(TerjeSettingsCollection.RADIATION_NEAREST_TRANSFER_RADIUS);
		if (nearestRadius > 0)
		{
			float nearest = CalculateTerjeRadiationFromNearestEntities(entity, nearestRadius, true);
			if (nearest > result)
			{
				result = nearest;
			}
		}

		return result;
	}
}
