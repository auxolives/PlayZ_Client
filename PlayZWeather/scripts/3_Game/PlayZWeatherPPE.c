//! Shared weather-event PPE helpers (3_Game — server + client).

class PlayZWeatherPPE
{
	static bool IsEventTintScenario(string scenarioName)
	{
		return scenarioName == "Heatwave" || scenarioName == "Coldwave";
	}

	static float GetScenarioEventTintFadeSec()
	{
		float fadeSec = PlayZConfig.GetPPE().m_ScenarioEventTintFadeSec;
		if (fadeSec <= 0)
		{
			return 180.0;
		}

		if (PlayZConfig.GetWeather().m_DebugCycleScenarios)
		{
			return 10.0;
		}

		return fadeSec;
	}

	static string GetActiveEventTintScenarioName()
	{
		if (IsEventTintScenario(PlayZConfig.m_CurrentScenarioName))
		{
			return PlayZConfig.m_CurrentScenarioName;
		}

		if (PlayZConfig.m_ScenarioEventTintFadeOutStartMs > 0 && PlayZConfig.m_EventTintScenarioName != "")
		{
			return PlayZConfig.m_EventTintScenarioName;
		}

		return "";
	}

	static bool IsEventTintVisualActive()
	{
		return GetActiveEventTintScenarioName() != "";
	}

	static float GetScenarioTintEnvelope(int startMs, float fadeSec)
	{
		if (startMs <= 0 || fadeSec <= 0)
		{
			return 0.0;
		}

		float elapsedSec = (GetGame().GetTime() - startMs) / 1000.0;
		return Math.Clamp(elapsedSec / fadeSec, 0.0, 1.0);
	}

	static float GetScenarioTintFadeOutEnvelope(int fadeOutStartMs, float fadeSec)
	{
		if (fadeOutStartMs <= 0 || fadeSec <= 0)
		{
			return 0.0;
		}

		float elapsedSec = (GetGame().GetTime() - fadeOutStartMs) / 1000.0;
		return Math.Clamp(1.0 - elapsedSec / fadeSec, 0.0, 1.0);
	}

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

	static float GetScenarioTintWeight(Weather weather)
	{
		string eventName = GetActiveEventTintScenarioName();
		if (eventName == "")
		{
			return 0.0;
		}

		float fadeSec = GetScenarioEventTintFadeSec();

		if (PlayZConfig.m_ScenarioEventTintFadeOutStartMs > 0)
		{
			float envelope = GetScenarioTintFadeOutEnvelope(PlayZConfig.m_ScenarioEventTintFadeOutStartMs, fadeSec);
			return PlayZConfig.m_EventTintFadeOutWeightPeak * envelope;
		}

		float fadeInEnvelope = GetScenarioTintEnvelope(PlayZConfig.m_ScenarioEventTintStartMs, fadeSec);
		float weatherFactor = GetScenarioTintWeightRaw(eventName, weather);
		return weatherFactor * fadeInEnvelope;
	}

	static void BeginScenarioEventTintFadeIn(string displayName)
	{
		PlayZConfig.m_ScenarioEventTintStartMs = GetGame().GetTime();
		PlayZConfig.m_ScenarioEventTintFadeOutStartMs = 0;
		PlayZConfig.m_EventTintScenarioName = displayName;
		PlayZConfig.m_EventTintFadeOutWeightPeak = 0.0;
		PlayZConfig.m_ServerScenarioTintWeight = 0.0;
	}

	static void BeginScenarioEventTintFadeOut()
	{
		if (PlayZConfig.m_EventTintScenarioName == "")
		{
			return;
		}

		PlayZConfig.m_EventTintFadeOutWeightPeak = PlayZConfig.m_ServerScenarioTintWeight;
		PlayZConfig.m_ScenarioEventTintFadeOutStartMs = GetGame().GetTime();
		PlayZConfig.m_ScenarioEventTintStartMs = 0;
	}

	static void ClearScenarioEventTintState()
	{
		PlayZConfig.m_ScenarioEventTintStartMs = 0;
		PlayZConfig.m_ScenarioEventTintFadeOutStartMs = 0;
		PlayZConfig.m_EventTintScenarioName = "";
		PlayZConfig.m_EventTintFadeOutWeightPeak = 0.0;
	}

	static void TryCompleteScenarioEventTintFadeOut()
	{
		if (PlayZConfig.m_ScenarioEventTintFadeOutStartMs <= 0)
		{
			return;
		}

		float fadeSec = GetScenarioEventTintFadeSec();
		float envelope = GetScenarioTintFadeOutEnvelope(PlayZConfig.m_ScenarioEventTintFadeOutStartMs, fadeSec);
		if (envelope <= 0.0)
		{
			ClearScenarioEventTintState();
		}
	}
}
