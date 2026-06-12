class PlayZWeatherState
{
	string m_Name;
	int m_EndTimestamp;
}

// Sakhal missions use SakhalData (missionBase.c sakhal map id -> new SakhalData()).
modded class SakhalData
{
	static const string STATE_PATH = "$profile:PlayZ/WeatherState.json";
	int m_LastScenarioIndex = -1;
	float m_NextScenarioTimer = 0;
	int m_ScenarioEndTimestamp = 0;

	ref array<ref PlayZWeatherScenario> m_Scenarios;
	ref PlayZWeatherScenario m_CurrentScenario;
	bool m_IsSnowMode = false;

	override void Init()
	{
		super.Init();

		m_WorldWindCoef = 0.65;
		m_TemperaturePerHeightReductionModifier = 0.025;

		InitScenarios();

		// Weather authoring (scenario picking + vol fog writes) is strictly server-side.
		// Clients receive overcast/rain/snow/wind through engine replication and vol fog
		// through the SYNC_SCENARIO RPC. Touching vol fog or running the scenario picker
		// on clients causes desync (different random picks, stale local vol fog, silent
		// null-derefs in PickNextScenario's debug log on empty client m_Scenarios).
		if (!GetGame().IsServer())
			return;

		m_Weather.SetDynVolFogHeightBias(0);

		// Initialize/Resume Scenario deferred to allow time processing
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(InitScenarioDeferred, 5000, false);
	}

	void InitScenarioDeferred()
	{
		if (!GetGame().IsServer())
			return;

		if (!LoadState())
		{
			PickNextScenario();
			ApplyScenario();
		}
	}

	void InitScenarios()
	{
		m_Scenarios = PlayZConfig.GetWeather().m_Scenarios;
	}

	int GetMaxScenarioDuration()
	{
		int maxDur = 900000;
		if (m_Scenarios)
		{
			int count = m_Scenarios.Count();
			for (int i = 0; i < count; i++)
			{
				int candidateMs = m_Scenarios[i].m_DurationMax * 1000;
				if (candidateMs > maxDur)
					maxDur = candidateMs;
			}
		}
		return maxDur;
	}

	void SaveState()
	{
		if (!GetGame().IsServer())
			return;

		PlayZWeatherState state = new PlayZWeatherState();
		if (m_CurrentScenario)
			state.m_Name = m_CurrentScenario.m_Name;
		else
			state.m_Name = "Clear";
		state.m_EndTimestamp = m_ScenarioEndTimestamp;
		JsonFileLoader<PlayZWeatherState>.JsonSaveFile(STATE_PATH, state);
	}

	bool LoadState()
	{
		if (!GetGame().IsServer())
			return false;

		if (FileExist(STATE_PATH))
		{
			PlayZWeatherState state = new PlayZWeatherState();
			JsonFileLoader<PlayZWeatherState>.JsonLoadFile(STATE_PATH, state);
			
			int currentTime = GetGame().GetTime();
			int remaining = state.m_EndTimestamp - currentTime;
			int maxDuration = GetMaxScenarioDuration();
			if (remaining > 0 && remaining <= maxDuration)
			{
				foreach (PlayZWeatherScenario sc : m_Scenarios)
				{
					if (sc.m_Name == state.m_Name)
					{
						m_CurrentScenario = sc;
						m_ScenarioEndTimestamp = state.m_EndTimestamp;
						
						Debug.WeatherLog("PlayZWeather:: Resuming Scenario: " + m_CurrentScenario.m_Name);
						ApplyScenario(remaining);
						return true;
					}
				}
			}
			else
			{
				Debug.WeatherLog(string.Format("PlayZWeather:: Discarding stale state (remaining: %1ms, max: %2ms)", remaining, maxDuration));
			}
		}
		return false;
	}

	void PickNextScenario()
	{
		if (!GetGame().IsServer())
			return;

		if (!m_Scenarios || m_Scenarios.Count() == 0)
			return;

		string prevName = "";
		if (m_CurrentScenario)
			prevName = m_CurrentScenario.m_Name;

		if (PlayZConfig.GetWeather().m_DebugCycleScenarios)
		{
			m_LastScenarioIndex++;
			if (m_LastScenarioIndex >= m_Scenarios.Count())
				m_LastScenarioIndex = 0;
			
			// Skip if it causes a heatwave/coldwave sequential conflict
			string nextName = m_Scenarios[m_LastScenarioIndex].m_Name;
			if ((prevName == "Heatwave" && nextName == "Coldwave") || (prevName == "Coldwave" && nextName == "Heatwave"))
			{
				m_LastScenarioIndex++;
				if (m_LastScenarioIndex >= m_Scenarios.Count())
					m_LastScenarioIndex = 0;
			}
				
			m_CurrentScenario = m_Scenarios[m_LastScenarioIndex];
			Debug.WeatherLog(string.Format("PlayZWeather:: DEBUG CYCLE: Scenario index %1 selected: %2", m_LastScenarioIndex, m_CurrentScenario.m_Name));
			return;
		}

		// If current weather is very clear, we must go through a cloudy/foggy transition before rain.
		bool currentIsClear = false;
		if (m_CurrentScenario && (m_CurrentScenario.m_Name == "Clear" || m_CurrentScenario.m_Name == "Gale" || m_CurrentScenario.m_Name == "Heatwave" || m_CurrentScenario.m_Name == "Coldwave"))
			currentIsClear = true;

		float totalProb = 0;
		foreach (PlayZWeatherScenario sc : m_Scenarios)
		{
			if (currentIsClear && (sc.m_Name == "Squall" || sc.m_Name == "Heavy Falls" || sc.m_Name == "Light Falls"))
				continue; // Skip rainy scenarios if we are currently clear

			// Prevent sequential Heatwave/Coldwave conflict
			if ((prevName == "Heatwave" && sc.m_Name == "Coldwave") || (prevName == "Coldwave" && sc.m_Name == "Heatwave"))
				continue;

			totalProb += sc.m_Probability;
		}

		float roll = Math.RandomFloat(0, totalProb);
		float currentProb = 0;
		
		foreach (PlayZWeatherScenario sc2 : m_Scenarios)
		{
			if (currentIsClear && (sc2.m_Name == "Squall" || sc2.m_Name == "Heavy Falls" || sc2.m_Name == "Light Falls"))
				continue;

			if ((prevName == "Heatwave" && sc2.m_Name == "Coldwave") || (prevName == "Coldwave" && sc2.m_Name == "Heatwave"))
				continue;

			currentProb += sc2.m_Probability;
			if (roll <= currentProb)
			{
				m_CurrentScenario = sc2;
				break;
			}
		}

		if (!m_CurrentScenario)
			m_CurrentScenario = m_Scenarios[0]; // fallback

		if (m_CurrentScenario)
			Debug.WeatherLog(string.Format("PlayZWeather:: Scenario selected: %1 (Clear restricted: %2)", m_CurrentScenario.m_Name, currentIsClear));
	}

	override bool WeatherOnBeforeChange( EWeatherPhenomenon type, float actual, float change, float time )
	{
		if (!PlayZConfig.GetWeather().m_EnablePlayZWeather)
			return super.WeatherOnBeforeChange(type, actual, change, time);

		// Clients have no scenario table (config loads server-side only). Do not pick or
		// author phenomena locally; accept engine replication and SYNC_SCENARIO vol fog.
		if (!GetGame().IsServer())
		{
			m_Weather.GetRain().SetLimits(0, 1);
			m_Weather.GetOvercast().SetLimits(0.07, 1);
			m_Weather.GetSnowfall().SetLimits(0, 1);

			if (type == EWeatherPhenomenon.FOG)
			{
				m_Weather.GetFog().Set(0.0, 10, 1000);
				return true;
			}

			if (type == EWeatherPhenomenon.WIND_DIRECTION || type == EWeatherPhenomenon.VOLFOG_HEIGHT_DENSITY || type == EWeatherPhenomenon.VOLFOG_DISTANCE_DENSITY || type == EWeatherPhenomenon.VOLFOG_HEIGHT_BIAS)
				return true;

			return false;
		}

		// Sakhal vanilla pins rain to 0; widen limits so PlayZ scenarios can drive snowfall/rain.
		m_Weather.GetRain().SetLimits(0, 1);
		m_Weather.GetOvercast().SetLimits(0.07, 1);
		m_Weather.GetSnowfall().SetLimits(0, 1);

		if (m_CurrentScenario && m_CurrentScenario.m_RainMax > 0.0 && GetBaseEnvTemperature() < 5.0)
			m_IsSnowMode = true;
		else
			m_IsSnowMode = false;

		// 1. Maintain Vanilla Thresholds (Since we bypass 'super' often)
		m_Weather.SetStorm( 1.0, m_WeatherDefaultSettings.m_StormThreshold, 45 );
		m_Weather.SetRainThresholds( 0.0, 1.0, 60 ); // Overridden to 0.0-1.0 so our mod has full control of rain
		m_Weather.SetSnowfallThresholds( 0.0, 1.0, 60 ); // Full control of snowfall
		m_Weather.SetWindMaximumSpeed( 20 );
		
		// 2. Disable Vanilla Phenomena we don't want or completely control
		if (type == EWeatherPhenomenon.FOG)
		{
			m_Weather.GetFog().Set(0.0, 10, 1000);
			return true;
		}
		
		if (type == EWeatherPhenomenon.SNOWFALL)
		{
			if (m_IsSnowMode && m_CurrentScenario)
			{
				float newSnow = Math.RandomFloatInclusive(m_CurrentScenario.m_RainMin, m_CurrentScenario.m_RainMax);
				float timeChangeS = Math.RandomFloatInclusive(60, 120);
				float lengthChangeS = Math.RandomFloatInclusive(300, 600);
				if (PlayZConfig.GetWeather().m_DebugCycleScenarios)
				{
					timeChangeS = 5;
					lengthChangeS = 25;
				}
				m_Weather.GetSnowfall().Set(newSnow, timeChangeS, lengthChangeS);
			}
			else
			{
				m_Weather.GetSnowfall().Set(0.0, 10, 1000);
			}
			return true;
		}
		
		// 3. Block Engine from randomizing Volumetric Fog and Wind Direction 
		// (We manually set these during OVERCAST transitions)
		if (type == EWeatherPhenomenon.WIND_DIRECTION || type == EWeatherPhenomenon.VOLFOG_HEIGHT_DENSITY || type == EWeatherPhenomenon.VOLFOG_DISTANCE_DENSITY || type == EWeatherPhenomenon.VOLFOG_HEIGHT_BIAS)
		{
			return true; 
		}

		if (type == EWeatherPhenomenon.OVERCAST)
		{
			// Prevent rapid scenario skipping (especially in debug mode)
			// Wait at least 5 seconds before allowing another scenario change via overcast event
			if (GetGame().GetTime() < m_NextScenarioTimer)
				return true;
				
			m_NextScenarioTimer = GetGame().GetTime() + 5000; // 5 second lock
			
			PickNextScenario();
			ApplyScenario();
			return true;
		}
		
		if (type == EWeatherPhenomenon.RAIN)
		{
			if (m_IsSnowMode)
			{
				m_Weather.GetRain().Set(0.0, 10, 1000);
			}
			else if (m_CurrentScenario)
			{
				float newRain = Math.RandomFloatInclusive(m_CurrentScenario.m_RainMin, m_CurrentScenario.m_RainMax);
				float timeChange = Math.RandomFloatInclusive(60, 120);
				float lengthChange = Math.RandomFloatInclusive(300, 600);
				if (PlayZConfig.GetWeather().m_DebugCycleScenarios)
				{
					timeChange = 5;
					lengthChange = 25;
				}
				m_Weather.GetRain().Set(newRain, timeChange, lengthChange);
			}
			return true;
		}
		
		if (type == EWeatherPhenomenon.WIND_MAGNITUDE)
		{
			if (m_CurrentScenario)
			{
				float newWind = Math.RandomFloatInclusive(m_CurrentScenario.m_WindMin, m_CurrentScenario.m_WindMax);
				float timeChangeW = Math.RandomFloatInclusive(60, 120);
				float lengthChangeW = Math.RandomFloatInclusive(300, 600);
				if (PlayZConfig.GetWeather().m_DebugCycleScenarios)
				{
					timeChangeW = 5;
					lengthChangeW = 25;
				}
				m_Weather.GetWindMagnitude().Set(newWind, timeChangeW, lengthChangeW);
			}
			return true;
		}

		return super.WeatherOnBeforeChange(type, actual, change, time);
	}
	
	void ApplyScenario(int forceDuration = -1)
	{
		if (!GetGame().IsServer())
			return;

		if (m_CurrentScenario)
		{
			// Determine snow mode: if ambient temp < 5°C and this is a precipitation scenario
			string displayName = m_CurrentScenario.m_Name;
			m_IsSnowMode = false;
			if (m_CurrentScenario.m_RainMax > 0.0 && GetBaseEnvTemperature() < 5.0)
			{
				m_IsSnowMode = true;
				if (m_CurrentScenario.m_Name == "Light Falls") displayName = "Light Snowfall";
				else if (m_CurrentScenario.m_Name == "Heavy Falls") displayName = "Heavy Snowfall";
				else if (m_CurrentScenario.m_Name == "Squall") displayName = "Blizzard";
			}

			PlayZConfig.m_CurrentScenarioName = displayName;
			PlayZConfig.m_CurrentScenarioTempMod = PlayZConfig.GetTempModifierByName(displayName);

			int totalDuration;
			if (forceDuration != -1)
				totalDuration = forceDuration / 1000; // back to seconds
			else
				totalDuration = Math.RandomIntInclusive(m_CurrentScenario.m_DurationMin, m_CurrentScenario.m_DurationMax);
				
			if (PlayZConfig.GetWeather().m_DebugCycleScenarios)
				totalDuration = 30; // for debug cycle
			
			m_ScenarioEndTimestamp = GetGame().GetTime() + (totalDuration * 1000);
			SaveState();

			float phmnTime = totalDuration / 3.0;
			float phmnLength = totalDuration - phmnTime;
			
			float targetOvercast = Math.RandomFloatInclusive(m_CurrentScenario.m_OvercastMin, m_CurrentScenario.m_OvercastMax);
			float targetRain = Math.RandomFloatInclusive(m_CurrentScenario.m_RainMin, m_CurrentScenario.m_RainMax);
			float targetWind = Math.RandomFloatInclusive(m_CurrentScenario.m_WindMin, m_CurrentScenario.m_WindMax);
			float windDirection = Math.RandomFloatInclusive(-3.14, 3.14);
			
			float targetVolFogDist = Math.RandomFloatInclusive(m_CurrentScenario.m_VolFogDistanceMin, m_CurrentScenario.m_VolFogDistanceMax);
			float targetVolFogHeight = Math.RandomFloatInclusive(m_CurrentScenario.m_VolFogHeightMin, m_CurrentScenario.m_VolFogHeightMax);
			float targetVolFogBias = Math.RandomFloatInclusive(m_CurrentScenario.m_VolFogBiasMin, m_CurrentScenario.m_VolFogBiasMax);
			
			m_Weather.GetOvercast().Set(targetOvercast, phmnTime, phmnLength);

			if (m_IsSnowMode)
			{
				m_Weather.GetRain().Set(0.0, phmnTime, phmnLength * 0.5);
				m_Weather.GetSnowfall().Set(targetRain, phmnTime, phmnLength * 0.5);
			}
			else
			{
				m_Weather.GetRain().Set(targetRain, phmnTime, phmnLength * 0.5);
				m_Weather.GetSnowfall().Set(0.0, phmnTime, phmnLength * 0.5);
			}
			m_Weather.GetWindMagnitude().Set(targetWind, phmnTime, phmnLength * 0.5);
			m_Weather.GetWindDirection().Set(windDirection, phmnTime, phmnLength);
			
			m_Weather.SetDynVolFogDistanceDensity(targetVolFogDist, phmnTime);
			m_Weather.SetDynVolFogHeightDensity(targetVolFogHeight, phmnTime);
			m_Weather.SetDynVolFogHeightBias(targetVolFogBias, phmnTime);

			PlayZConfig.m_ServerScenarioTintWeight = PlayZWeatherPPE.GetScenarioTintWeightRaw(displayName, m_Weather);

			PlayZConfig.SyncScenario(displayName, PlayZConfig.m_CurrentScenarioTempMod, targetVolFogDist, targetVolFogHeight, targetVolFogBias, phmnTime);
			
			Debug.WeatherLog(string.Format("PlayZWeather:: Applying Scenario: %1 (snow: %2), Overcast: %3, Precip: %4, Wind: %5, FogDist: %6, Duration: %7", displayName, m_IsSnowMode, targetOvercast, targetRain, targetWind, targetVolFogDist, totalDuration));
		}
	}

	override void CalculateVolFog(float lerpValue, float windMagnitude, float changeTime) {}
}
