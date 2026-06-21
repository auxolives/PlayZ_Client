//! Rotblur + distort channel math for Terje overdose — reads $profile:PlayZ/Overdose.json.

class PlayZOverdosePPE
{
	static const float EPSILON = 0.001;

	static PlayZOverdoseConfig Cfg()
	{
		PlayZOverdoseConfig cfg = PlayZOverdoseConfig.GetInstance();
		cfg.ValidateOverdosePPE();
		return cfg;
	}

	static float GetTierWeight(float overdoseValue)
	{
		PlayZOverdoseConfig cfg = Cfg();
		if (overdoseValue < cfg.m_TierValueMin)
		{
			return 0;
		}
		if (overdoseValue >= cfg.m_TierValueMax)
		{
			return 1.0;
		}
		return Math.Clamp(Math.InverseLerp(cfg.m_TierValueMin, cfg.m_TierValueMax, overdoseValue), 0.0, 1.0);
	}

	//! Terje heartbeat envelope from m_OverdosedOffset (0..12 cycle).
	static float PulseFromOffset(float offset)
	{
		float sinusVal = Math.Clamp(offset, 0, 12);
		if (sinusVal >= 2)
		{
			sinusVal = Math.Cos((sinusVal - 2) * Math.PI_HALF * 0.1);
		}
		else
		{
			sinusVal = Math.AbsFloat(Math.Sin(sinusVal * Math.PI * 0.75));
		}
		return sinusVal;
	}

	static float GetEffectiveStrength(float weight, float pulse, float mod)
	{
		PlayZOverdoseConfig cfg = Cfg();
		float base = 1.0 - cfg.m_PulseMix;
		float mix = base + pulse * cfg.m_PulseMix;
		return weight * mod * mix;
	}

	static void ComputeRotBlur(float weight, float pulse, float mod, out float power, out float minAngle, out float maxAngle, out float minDepth, out float maxDepth)
	{
		PlayZOverdoseConfig cfg = Cfg();
		float strength = GetEffectiveStrength(weight, pulse, mod);
		power = strength * cfg.m_RotPowerMax;
		minAngle = Math.Lerp(0, cfg.m_RotMinAngle, weight) * mod;
		maxAngle = Math.Lerp(0, cfg.m_RotMaxAngle, weight) * mod;
		minDepth = cfg.m_RotMinDepth;
		maxDepth = cfg.m_RotMaxDepth;
	}

	static void ComputeDistort(float weight, float pulse, float mod, out float distort, out float centerX, out float centerY)
	{
		PlayZOverdoseConfig cfg = Cfg();
		float strength = GetEffectiveStrength(weight, pulse, mod);
		distort = strength * cfg.m_DistortMax;
		centerX = pulse * cfg.m_DistortCenterMax * weight * mod;
		centerY = pulse * cfg.m_DistortCenterMax * weight * mod * 0.6;
	}

	static bool HasAnyEffect(float weight)
	{
		return weight > EPSILON;
	}
}
