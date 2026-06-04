//! Client-side weight for radioactive precipitation tint (matches Terje rain rad logic + shelter).

class PlayZRadioactiveRainPPE
{
	static const float PRECIP_MIN = 0.3;
	static const float PRECIP_MAX = 1.0;
	static const float FADE_SPEED = 0.05;

	// Full-strength sickly green (same order of magnitude as PlayZ heatwave / coldwave tints).
	static const float COLOR_R = 0.62;
	static const float COLOR_G = 1.42;
	static const float COLOR_B = 0.68;

	static float GetTargetWeight()
	{
		if (GetTerjeSettingFloat(TerjeSettingsCollection.RADIATION_RADRAIN_POWER) <= 0)
		{
			return 0;
		}

		Weather weather = GetGame().GetWeather();
		if (!weather)
		{
			return 0;
		}

		float precip = 0;
		Rain rain = weather.GetRain();
		if (rain)
		{
			precip = Math.Max(precip, rain.GetActual());
		}

		Snowfall snowfall = weather.GetSnowfall();
		if (snowfall)
		{
			precip = Math.Max(precip, snowfall.GetActual());
		}

		if (precip < PRECIP_MIN)
		{
			return 0;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player)
		{
			EntityAI root = player.GetHierarchyRoot();
			if (!root)
			{
				root = player;
			}

			if (root && MiscGameplayFunctions.IsUnderRoof(root))
			{
				return 0;
			}
		}

		return Math.InverseLerp(PRECIP_MIN, PRECIP_MAX, precip);
	}

	static void GetColorizationForWeight(float weight, out float r, out float g, out float b)
	{
		r = Math.Lerp(1.0, COLOR_R, weight);
		g = Math.Lerp(1.0, COLOR_G, weight);
		b = Math.Lerp(1.0, COLOR_B, weight);
	}
}
