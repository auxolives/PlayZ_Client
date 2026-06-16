//! Client-side body radiation buffer PPE weights (0-5000, works indoors).

class PlayZRadBodyPPE
{
	static const float GHOST_PULSE_SPEED = 0.35;

	static float GetDose(PlayerBase player)
	{
		if (!player)
		{
			return 0;
		}

		return player.PlayZGetRadBodyBufferForPPE();
	}

	static float GetVignetteWeight(float dose)
	{
		return PlayZRadPPE.TierWeight(PlayZRadPPE.BODY_VIGNETTE_MIN, PlayZRadPPE.BODY_VIGNETTE_MAX, dose);
	}

	static float GetVignetteIntensity(float weight)
	{
		return weight * PlayZRadPPE.BODY_VIGNETTE_INTENSITY_MAX;
	}

	static float GetFeverWeight(float dose)
	{
		return PlayZRadPPE.TierWeight(PlayZRadPPE.BODY_FEVER_MIN, PlayZRadPPE.BODY_FEVER_MAX, dose);
	}

	static float GetFeverIntensity(float weight)
	{
		return weight * PlayZRadPPE.BODY_FEVER_INTENSITY_MAX;
	}

	static float GetRadialWeight(float dose)
	{
		return PlayZRadPPE.TierWeight(PlayZRadPPE.BODY_RADIAL_MIN, PlayZRadPPE.BODY_RADIAL_MAX, dose);
	}

	static float GetRadialPower(float weight)
	{
		return weight * PlayZRadPPE.BODY_RADIAL_POWER_MAX;
	}

	static float GetGhostWeight(float dose)
	{
		return PlayZRadPPE.TierWeight(PlayZRadPPE.BODY_GHOST_MIN, PlayZRadPPE.BODY_GHOST_MAX, dose);
	}

	static float GetGhostPulseProgress(float elapsedTime, float weight)
	{
		float phase = elapsedTime * GHOST_PULSE_SPEED * Math.Lerp(0.5, 1.0, weight);
		float wave = Math.Sin(phase);
		return (wave + 1.0) * 0.5 * weight;
	}

	static bool HasAnyEffect(float dose)
	{
		if (GetVignetteWeight(dose) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		if (GetFeverWeight(dose) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		if (GetRadialWeight(dose) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		if (GetGhostWeight(dose) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		return false;
	}
}
