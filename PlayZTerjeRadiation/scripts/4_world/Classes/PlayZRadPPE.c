//! Shared tier weights and fade constants for PlayZ radiation PPE stacks.
//! Tunables: $profile:PlayZ/Radiation.json (synced from server).

class PlayZRadPPE
{
	static const float EPSILON = 0.001;
	static const float ENV_FADE_SPEED = 0.05;
	static const float BODY_FADE_SEC = 1.0;

	static PlayZRadiationConfig Cfg()
	{
		return PlayZRadiationManager.GetRadiation();
	}

	//! Ease-out cubic on inverse-lerp: fast ramp after min dose, slower approach to full weight at max.
	static float TierWeight(float minDose, float maxDose, float dose)
	{
		float linear = Math.Clamp(Math.InverseLerp(minDose, maxDose, dose), 0.0, 1.0);
		float inv = 1.0 - linear;
		return 1.0 - Math.Pow(inv, 3.0);
	}

	static float MaxTierWeight(float doseA, float minA, float maxA, float doseB, float minB, float maxB)
	{
		float wA = TierWeight(minA, maxA, doseA);
		float wB = TierWeight(minB, maxB, doseB);
		return Math.Max(wA, wB);
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
