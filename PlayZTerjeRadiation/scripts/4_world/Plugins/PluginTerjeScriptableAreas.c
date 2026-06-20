modded class PluginTerjeScriptableAreas
{
	protected ref PlayZRadProtectionCache m_PlayZRadProtectionCache;

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

	void PlayZ_InvalidateBodyProtectionCache(PlayerBase player)
	{
		if (!m_PlayZRadProtectionCache)
		{
			m_PlayZRadProtectionCache = new PlayZRadProtectionCache();
		}

		m_PlayZRadProtectionCache.Invalidate(player);
	}

	override float CalculatePlayerBodyProtection(PlayerBase player, string protectionType, float power)
	{
		if (!player)
		{
			return 0;
		}

		if (!m_PlayZRadProtectionCache)
		{
			m_PlayZRadProtectionCache = new PlayZRadProtectionCache();
		}

		string fingerprint = PlayZRadProtectionCache.BuildFingerprint(player);
		bool hit;
		float cached = m_PlayZRadProtectionCache.GetCached(player, protectionType, power, fingerprint, hit);
		if (hit)
		{
			return cached;
		}

		float result = super.CalculatePlayerBodyProtection(player, protectionType, power);
		m_PlayZRadProtectionCache.Store(player, protectionType, power, fingerprint, result);
		return result;
	}
}
