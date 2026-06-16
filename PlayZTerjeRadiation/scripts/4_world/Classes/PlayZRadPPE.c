//! Shared tier weights and fade constants for PlayZ radiation PPE stacks.

class PlayZRadPPE
{
	static const float EPSILON = 0.001;
	static const float ENV_FADE_SPEED = 0.05;
	static const float BODY_FADE_SEC = 1.0;

	static const float ENV_SAT_DOSE_MIN = 0.4;
	static const float ENV_SAT_DOSE_MAX = 1.0;
	static const float ENV_GRAIN_DOSE_MIN = 0.8;
	static const float ENV_GRAIN_DOSE_MAX = 3.0;

	static const float BODY_VIGNETTE_MIN = 400.0;
	static const float BODY_VIGNETTE_MAX = 1500.0;
	static const float BODY_FEVER_MIN = 600.0;
	static const float BODY_FEVER_MAX = 2500.0;
	static const float BODY_RADIAL_MIN = 1000.0;
	static const float BODY_RADIAL_MAX = 5000.0;
	static const float BODY_GHOST_MIN = 2000.0;
	static const float BODY_GHOST_MAX = 5000.0;

	static const float BODY_VIGNETTE_INTENSITY_MAX = 1.0;
	static const float BODY_FEVER_INTENSITY_MAX = 0.4;
	static const float BODY_RADIAL_POWER_MAX = 0.25;

	static const float ENV_GRAIN_SHARPNESS_MAX = 10.0;
	static const float ENV_GRAIN_SIZE_MIN = 1.0;
	static const float ENV_GRAIN_SIZE_DEFAULT = 2.75;
	static const float ENV_NOISE_MULT_MAX = 0.15;

	static float TierWeight(float minDose, float maxDose, float dose)
	{
		return Math.Clamp(Math.InverseLerp(minDose, maxDose, dose), 0.0, 1.0);
	}

	static float EnvFadeLerp(float current, float target, float timeslice)
	{
		return Math.Lerp(current, target, ENV_FADE_SPEED * timeslice);
	}

	static float BodyFadeLerp(float current, float target, float timeslice)
	{
		float k = timeslice / BODY_FADE_SEC;
		if (k > 1.0)
		{
			k = 1.0;
		}

		return Math.Lerp(current, target, k);
	}
}
