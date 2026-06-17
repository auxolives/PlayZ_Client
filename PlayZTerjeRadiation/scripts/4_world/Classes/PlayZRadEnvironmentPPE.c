//! Client-side environmental exposure dose (raw env × protection), for PPE tiers.

class PlayZRadEnvironmentPPE
{
	static float GetDose(PlayerBase player)
	{
		if (!player)
		{
			return 0;
		}

		return player.PlayZGetRadEnvironmentExposureForPPE();
	}

	static float GetSickness(PlayerBase player)
	{
		if (!player)
		{
			return 0;
		}

		return player.PlayZGetRadSicknessForPPE();
	}

	static float GetSaturationWeight(float envDose, float sickValue)
	{
		if (!PlayZRadPPE.Cfg().m_EnableEnvSaturation)
		{
			return 0;
		}

		PlayZRadiationConfig cfg = PlayZRadPPE.Cfg();
		return PlayZRadPPE.MaxTierWeight(envDose, cfg.m_EnvSatDoseMin, cfg.m_EnvSatDoseMax, sickValue, cfg.m_SickSatMin, cfg.m_SickSatMax);
	}

	static float GetSaturationForWeight(float weight)
	{
		return Math.Lerp(1.0, 0.0, weight);
	}

	static float GetGrainWeight(float envDose, float sickValue)
	{
		if (!PlayZRadPPE.Cfg().m_EnableEnvGrain)
		{
			return 0;
		}

		PlayZRadiationConfig cfg = PlayZRadPPE.Cfg();
		return PlayZRadPPE.MaxTierWeight(envDose, cfg.m_EnvGrainDoseMin, cfg.m_EnvGrainDoseMax, sickValue, cfg.m_SickGrainMin, cfg.m_SickGrainMax);
	}

	static float GetGrainSharpnessForWeight(float weight)
	{
		return Math.Lerp(0.0, PlayZRadPPE.Cfg().m_EnvGrainSharpnessMax, weight);
	}

	static float GetGrainSizeForWeight(float weight)
	{
		PlayZRadiationConfig cfg = PlayZRadPPE.Cfg();
		return Math.Lerp(cfg.m_EnvGrainSizeDefault, cfg.m_EnvGrainSizeMin, weight);
	}

	static float GetNoiseMultForWeight(float weight)
	{
		return Math.Lerp(0.0, PlayZRadPPE.Cfg().m_EnvNoiseMultMax, weight);
	}

	static bool HasAnyEffect(float envDose, float sickValue)
	{
		if (GetSaturationWeight(envDose, sickValue) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		if (GetGrainWeight(envDose, sickValue) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		return false;
	}
}
