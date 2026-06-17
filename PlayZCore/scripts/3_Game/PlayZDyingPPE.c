class PlayZDyingPulseState
{
	float m_PhaseTime;
	float m_Duration;
	float m_BreakPoint;
	float m_Cooldown;
	float m_Jitter;

	void Reset()
	{
		m_PhaseTime = 0;
		m_Duration = 0;
		m_BreakPoint = 0;
		m_Cooldown = 0;
		m_Jitter = 1.0;
	}
}

class PlayZDyingPPE
{
	static const float EPSILON = 0.001;
	static const float FADE_SEC = 1.0;
	//! Envelope peak scales by ±this amount each beat (1.0 ± 0.35).
	static const float PULSE_ENVELOPE_JITTER = 0.35;
	//! Gap after each beat is base interval × random in [0.5, 1.5] (±50%).
	static const float PULSE_COOLDOWN_JITTER_MIN = 0.5;
	static const float PULSE_COOLDOWN_JITTER_MAX = 1.5;

	static PlayZCoreConfig Cfg()
	{
		PlayZCoreConfig cfg = PlayZCoreConfig.GetInstance();
		cfg.ValidateDyingPPE();
		return cfg;
	}

	static float TierWeight(float minVal, float maxVal, float value)
	{
		float linear = Math.Clamp(Math.InverseLerp(minVal, maxVal, value), 0.0, 1.0);
		float inv = 1.0 - linear;
		return 1.0 - Math.Pow(inv, 3.0);
	}

	static float GetTargetWeight(float health)
	{
		PlayZCoreConfig cfg = Cfg();
		if (!cfg.m_EnableDyingPPE)
		{
			return 0;
		}

		float start = cfg.m_DyingHealthStart;
		float end = cfg.m_DyingHealthEnd;
		if (health > start)
		{
			return 0;
		}
		if (health <= end)
		{
			return 1;
		}

		return TierWeight(start, end, health);
	}

	static float FadeLerp(float current, float target, float timeslice)
	{
		float k = timeslice / FADE_SEC;
		if (k > 1.0)
		{
			k = 1.0;
		}

		return Math.Lerp(current, target, k);
	}

	static float UpdatePulseEnvelope(PlayZDyingPulseState state, float timeslice, float weight)
	{
		if (weight <= EPSILON)
		{
			state.Reset();
			return 0;
		}

		PlayZCoreConfig cfg = Cfg();
		float freq = Math.Lerp(cfg.m_DyingPulseFreqMin, cfg.m_DyingPulseFreqMax, weight);

		if (state.m_Duration <= 0)
		{
			if (state.m_Cooldown > 0)
			{
				state.m_Cooldown = state.m_Cooldown - timeslice;
				if (state.m_Cooldown > 0)
				{
					return 0;
				}
			}

			state.m_Duration = Math.Lerp(0.9, 0.5, weight);
			state.m_BreakPoint = state.m_Duration * 0.2;
			state.m_PhaseTime = 0;
			state.m_Jitter = Math.RandomFloat(1.0 - PULSE_ENVELOPE_JITTER, 1.0 + PULSE_ENVELOPE_JITTER);
		}

		float envelope = 0;
		if (state.m_PhaseTime <= state.m_BreakPoint)
		{
			envelope = Math.InverseLerp(0, state.m_BreakPoint, state.m_PhaseTime);
		}
		else
		{
			float tmp = Math.InverseLerp(state.m_BreakPoint, state.m_Duration, state.m_PhaseTime);
			envelope = 1.0 - tmp;
		}

		envelope = Math.Clamp(envelope * state.m_Jitter, 0, 1);
		state.m_PhaseTime = state.m_PhaseTime + timeslice;

		if (state.m_PhaseTime >= state.m_Duration)
		{
			state.m_Duration = 0;
			state.m_PhaseTime = 0;
			if (freq > 0)
			{
				float baseInterval = 1.0 / freq;
				float timingJitter = Math.RandomFloat(PULSE_COOLDOWN_JITTER_MIN, PULSE_COOLDOWN_JITTER_MAX);
				state.m_Cooldown = baseInterval * timingJitter;
			}
		}

		return envelope;
	}

	static void ComputeChannels(float weight, float pulse, out float vignette, out float gauss, out float overlay, out float exposure)
	{
		PlayZCoreConfig cfg = Cfg();
		float pulseMix = pulse * cfg.m_DyingPulseStrength;

		vignette = weight * cfg.m_DyingMaxVignette + pulseMix * cfg.m_DyingMaxVignette;
		gauss = weight * cfg.m_DyingMaxGauss + pulseMix * cfg.m_DyingMaxGauss;
		overlay = weight * cfg.m_DyingMaxOverlay + pulseMix * cfg.m_DyingMaxOverlay;
		exposure = weight * cfg.m_DyingMaxExposure + pulseMix * cfg.m_DyingMaxExposure;
	}

	static bool HasAnyEffect(float weight)
	{
		return weight > EPSILON;
	}
}
