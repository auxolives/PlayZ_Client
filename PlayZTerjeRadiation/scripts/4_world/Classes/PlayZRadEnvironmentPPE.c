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

	static float GetSaturationWeight(float dose)
	{
		return PlayZRadPPE.TierWeight(PlayZRadPPE.ENV_SAT_DOSE_MIN, PlayZRadPPE.ENV_SAT_DOSE_MAX, dose);
	}

	static float GetSaturationForWeight(float weight)
	{
		return Math.Lerp(1.0, 0.0, weight);
	}

	static float GetGrainWeight(float dose)
	{
		return PlayZRadPPE.TierWeight(PlayZRadPPE.ENV_GRAIN_DOSE_MIN, PlayZRadPPE.ENV_GRAIN_DOSE_MAX, dose);
	}

	static float GetGrainSharpnessForWeight(float weight)
	{
		return Math.Lerp(0.0, PlayZRadPPE.ENV_GRAIN_SHARPNESS_MAX, weight);
	}

	static float GetGrainSizeForWeight(float weight)
	{
		return Math.Lerp(PlayZRadPPE.ENV_GRAIN_SIZE_DEFAULT, PlayZRadPPE.ENV_GRAIN_SIZE_MIN, weight);
	}

	static float GetNoiseMultForWeight(float weight)
	{
		return Math.Lerp(0.0, PlayZRadPPE.ENV_NOISE_MULT_MAX, weight);
	}

	static bool HasAnyEffect(float dose)
	{
		if (GetSaturationWeight(dose) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		if (GetGrainWeight(dose) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		return false;
	}
}
