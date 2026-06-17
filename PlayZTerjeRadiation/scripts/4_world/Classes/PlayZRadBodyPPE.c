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

	static float GetSickness(PlayerBase player)
	{
		if (!player)
		{
			return 0;
		}

		return player.PlayZGetRadSicknessForPPE();
	}

	static float GetVignetteWeight(float bufferDose, float sickValue)
	{
		if (!PlayZRadPPE.Cfg().m_EnableBodyVignette)
		{
			return 0;
		}

		PlayZRadiationConfig cfg = PlayZRadPPE.Cfg();
		return PlayZRadPPE.MaxTierWeight(bufferDose, cfg.m_BodyVignetteMin, cfg.m_BodyVignetteMax, sickValue, cfg.m_SickVignetteMin, cfg.m_SickVignetteMax);
	}

	static float GetVignetteIntensity(float weight)
	{
		return weight * PlayZRadPPE.Cfg().m_BodyVignetteIntensityMax;
	}

	static float GetFeverWeight(float bufferDose, float sickValue)
	{
		if (!PlayZRadPPE.Cfg().m_EnableBodyFever)
		{
			return 0;
		}

		PlayZRadiationConfig cfg = PlayZRadPPE.Cfg();
		return PlayZRadPPE.MaxTierWeight(bufferDose, cfg.m_BodyFeverMin, cfg.m_BodyFeverMax, sickValue, cfg.m_SickFeverMin, cfg.m_SickFeverMax);
	}

	static float GetFeverIntensity(float weight)
	{
		return weight * PlayZRadPPE.Cfg().m_BodyFeverIntensityMax;
	}

	static float GetRadialWeight(float bufferDose, float sickValue)
	{
		if (!PlayZRadPPE.Cfg().m_EnableBodyRadial)
		{
			return 0;
		}

		PlayZRadiationConfig cfg = PlayZRadPPE.Cfg();
		return PlayZRadPPE.MaxTierWeight(bufferDose, cfg.m_BodyRadialMin, cfg.m_BodyRadialMax, sickValue, cfg.m_SickRadialMin, cfg.m_SickRadialMax);
	}

	static float GetRadialPower(float weight)
	{
		return weight * PlayZRadPPE.Cfg().m_BodyRadialPowerMax;
	}

	static float GetGhostWeight(float bufferDose, float sickValue)
	{
		if (!PlayZRadPPE.Cfg().m_EnableBodyGhost)
		{
			return 0;
		}

		PlayZRadiationConfig cfg = PlayZRadPPE.Cfg();
		return PlayZRadPPE.MaxTierWeight(bufferDose, cfg.m_BodyGhostMin, cfg.m_BodyGhostMax, sickValue, cfg.m_SickGhostMin, cfg.m_SickGhostMax);
	}

	static float GetGhostPulseProgress(float elapsedTime, float weight)
	{
		float phase = elapsedTime * GHOST_PULSE_SPEED * Math.Lerp(0.5, 1.0, weight);
		float wave = Math.Sin(phase);
		return (wave + 1.0) * 0.5 * weight;
	}

	static bool HasAnyEffect(float bufferDose, float sickValue)
	{
		if (GetVignetteWeight(bufferDose, sickValue) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		if (GetFeverWeight(bufferDose, sickValue) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		if (GetRadialWeight(bufferDose, sickValue) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		if (GetGhostWeight(bufferDose, sickValue) > PlayZRadPPE.EPSILON)
		{
			return true;
		}

		return false;
	}
}
