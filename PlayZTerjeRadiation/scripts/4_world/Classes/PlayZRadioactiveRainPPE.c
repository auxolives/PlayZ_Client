//! Client-side weight for radioactive precipitation tint (matches Terje rain rad logic + shelter).
//! Website accent: PlayZ_Website/config/themes/sakhal.ts primary #5ECF6E

class PlayZRadioactiveRainPPE
{
	static const float PRECIP_MIN = 0.3;
	static const float PRECIP_MAX = 1.0;
	static const float FADE_SPEED = 0.05;

	static const float COLOR_RAIN_R = 0.62;
	static const float COLOR_RAIN_G = 1.42;
	static const float COLOR_RAIN_B = 0.68;

	static const float COLOR_SNOW_R = 0.58;
	static const float COLOR_SNOW_G = 1.38;
	static const float COLOR_SNOW_B = 0.88;

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

		float rain = 0;
		float snow = 0;
		Rain rainFx = weather.GetRain();
		if (rainFx)
		{
			rain = rainFx.GetActual();
		}

		Snowfall snowfall = weather.GetSnowfall();
		if (snowfall)
		{
			snow = snowfall.GetActual();
		}

		float precip = Math.Max(rain, snow);
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
		float targetR;
		float targetG;
		float targetB;
		GetColorTargetsForPrecip(targetR, targetG, targetB);

		r = Math.Lerp(1.0, targetR, weight);
		g = Math.Lerp(1.0, targetG, weight);
		b = Math.Lerp(1.0, targetB, weight);
	}

	protected static void GetColorTargetsForPrecip(out float r, out float g, out float b)
	{
		Weather weather = GetGame().GetWeather();
		float rain = 0;
		float snow = 0;

		if (weather)
		{
			Rain rainFx = weather.GetRain();
			if (rainFx)
			{
				rain = rainFx.GetActual();
			}

			Snowfall snowfall = weather.GetSnowfall();
			if (snowfall)
			{
				snow = snowfall.GetActual();
			}
		}

		if (snow >= rain)
		{
			r = COLOR_SNOW_R;
			g = COLOR_SNOW_G;
			b = COLOR_SNOW_B;
		}
		else
		{
			r = COLOR_RAIN_R;
			g = COLOR_RAIN_G;
			b = COLOR_RAIN_B;
		}
	}
}
