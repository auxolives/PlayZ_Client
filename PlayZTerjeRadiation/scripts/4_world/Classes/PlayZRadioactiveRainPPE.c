//! Client-side weight for radioactive precipitation desaturation (matches Terje rain rad logic + shelter).

class PlayZRadioactiveRainPPE
{
	static const float PRECIP_MIN = 0.3;
	static const float PRECIP_MAX = 1.0;
	static const float FADE_SPEED = 0.05;

	//! Glow saturation at max precip (0.1 = 90% desaturated).
	static const float SATURATION_MIN = 0.1;
	static const float SATURATION_MAX = 1.0;

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

	static float GetSaturationForWeight(float weight)
	{
		return Math.Lerp(SATURATION_MAX, SATURATION_MIN, weight);
	}
}
