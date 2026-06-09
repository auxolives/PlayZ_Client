//! Shared weather-event PPE helpers (3_Game — server + client).

class PlayZWeatherPPE
{
	static float GetScenarioTintWeightRaw(string scenarioName, Weather weather)
	{
		if (!weather)
		{
			return 0.0;
		}

		if (scenarioName == "Coldwave")
		{
			float wind = weather.GetWindSpeed();
			return Math.Clamp(Math.InverseLerp(12.0, 18.0, wind), 0.0, 1.0);
		}

		if (scenarioName == "Heatwave")
		{
			float overcast = weather.GetOvercast().GetActual();
			return Math.Clamp(1.0 - Math.InverseLerp(0.0, 0.12, overcast), 0.0, 1.0);
		}

		return 0.0;
	}
}
