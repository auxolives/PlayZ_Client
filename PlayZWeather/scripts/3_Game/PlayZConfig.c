class PlayZConfig
{
	static string m_CurrentScenarioName = "";
	static float m_CurrentScenarioTempMod = 0;

	// Last authoritative vol fog target broadcast to all clients (server-only state).
	// Used to re-sync joining players with the correct remaining transition time so they
	// interpolate to the same endpoint as everyone else, instead of locking to a mid-
	// transition snapshot and staying desynced until the next scenario change.
	static float m_LastVolFogDistTarget = 0;
	static float m_LastVolFogHeightTarget = 0;
	static float m_LastVolFogBiasTarget = 0;
	static int m_LastVolFogTransitionStartMs = 0;
	static float m_LastVolFogTransitionTimeSec = 0;

	// Server: smoothed heatwave/coldwave tint weight + temp mod for join resync.
	static float m_ServerScenarioTintWeight = 0.0;
	static float m_AuthoritativeTempMod = 0.0;

	private static ref PlayZWeatherConfig m_Weather;
	private static ref PlayZPPEConfig m_PPE;

	static PlayZWeatherConfig GetWeather()
	{
		if (!m_Weather)
		{
			m_Weather = new PlayZWeatherConfig();
			if (GetGame().IsServer())
			{
				m_Weather.Load();
			}
		}
		return m_Weather;
	}

	static PlayZPPEConfig GetPPE()
	{
		if (!m_PPE)
		{
			m_PPE = new PlayZPPEConfig();
			if (GetGame().IsServer())
			{
				m_PPE.Load();
			}
		}
		return m_PPE;
	}

	static void SyncConfig(PlayerIdentity identity = null)
	{
		if (GetGame().IsServer())
		{
			ScriptRPC rpc = new ScriptRPC();
			
			// Weather Sync
			rpc.Write(GetWeather().m_EnablePlayZWeather);
			rpc.Write(GetWeather().m_DebugCycleScenarios);
			
			// PPE Sync
			PlayZPPEConfig ppe = GetPPE();
			rpc.Write(ppe.m_EnableWeatherPPE);
			rpc.Write(ppe.m_SaturationMin);
			rpc.Write(ppe.m_SaturationMax);
			rpc.Write(ppe.m_SaturationBoostClear);
			rpc.Write(ppe.m_ContrastMin);
			rpc.Write(ppe.m_ContrastMax);
			rpc.Write(ppe.m_GrainIntensity);
			rpc.Write(ppe.m_ChromIntensity);
			rpc.Write(ppe.m_GodRaysIntensity);
			rpc.Write(ppe.m_ShelterFadeSpeed);
			rpc.Write(ppe.m_WeatherFadeSpeed);
			rpc.Write(ppe.m_ColorClearR);
			rpc.Write(ppe.m_ColorClearG);
			rpc.Write(ppe.m_ColorClearB);
			rpc.Write(ppe.m_ColorGloomyR);
			rpc.Write(ppe.m_ColorGloomyG);
			rpc.Write(ppe.m_ColorGloomyB);

			rpc.Write(ppe.m_ColorHeatwaveR);
			rpc.Write(ppe.m_ColorHeatwaveG);
			rpc.Write(ppe.m_ColorHeatwaveB);

			rpc.Write(ppe.m_ColorColdwaveR);
			rpc.Write(ppe.m_ColorColdwaveG);
			rpc.Write(ppe.m_ColorColdwaveB);

			rpc.Write(ppe.m_ColorSnowR);
			rpc.Write(ppe.m_ColorSnowG);
			rpc.Write(ppe.m_ColorSnowB);

			rpc.Send(null, PlayZRPCs.SYNC_CONFIG, true, identity);

			// Join resync: cached target + remaining transition time, plus the server's
			// current interpolated vol fog (read in SyncScenario). Client snaps to
			// current then continues the transition — target+remaining alone is not
			// enough because SetDynVolFog lerps from the client's local value.
			float remainingSec = 0;
			if (m_LastVolFogTransitionTimeSec > 0)
			{
				int elapsedMs = GetGame().GetTime() - m_LastVolFogTransitionStartMs;
				float elapsedSec = elapsedMs / 1000.0;
				remainingSec = m_LastVolFogTransitionTimeSec - elapsedSec;
				if (remainingSec < 0)
					remainingSec = 0;
			}

			SyncScenario(m_CurrentScenarioName, m_CurrentScenarioTempMod, m_LastVolFogDistTarget, m_LastVolFogHeightTarget, m_LastVolFogBiasTarget, remainingSec, identity);
		}
	}

	static void SyncScenario(string name, float tempMod, float volFogDist, float volFogHeight, float volFogBias, float volFogTransitionTime, PlayerIdentity identity = null)
	{
		if (!GetGame().IsServer())
			return;

		// Cache target + start-time whenever this is an authoritative broadcast
		// (identity == null means send to all). Per-player resends (identity set) use
		// the cached values and must NOT overwrite them with their own remaining time.
		if (!identity)
		{
			m_LastVolFogDistTarget = volFogDist;
			m_LastVolFogHeightTarget = volFogHeight;
			m_LastVolFogBiasTarget = volFogBias;
			m_LastVolFogTransitionStartMs = GetGame().GetTime();
			m_LastVolFogTransitionTimeSec = volFogTransitionTime;
		}

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(name);
		rpc.Write(tempMod);
		rpc.Write(volFogDist);
		rpc.Write(volFogHeight);
		rpc.Write(volFogBias);
		rpc.Write(volFogTransitionTime);

		bool isJoinResync = false;
		if (identity)
		{
			isJoinResync = true;
		}
		rpc.Write(isJoinResync);
		if (isJoinResync)
		{
			float curDist = 0;
			float curHeight = 0;
			float curBias = 0;
			Weather weather = GetGame().GetWeather();
			if (weather)
			{
				curDist = weather.GetDynVolFogDistanceDensity();
				curHeight = weather.GetDynVolFogHeightDensity();
				curBias = weather.GetDynVolFogHeightBias();
			}
			rpc.Write(curDist);
			rpc.Write(curHeight);
			rpc.Write(curBias);
			rpc.Write(m_ServerScenarioTintWeight);
			rpc.Write(m_AuthoritativeTempMod);
		}

		rpc.Send(null, PlayZRPCs.SYNC_SCENARIO, true, identity);
	}

	//! Clients only: apply server-authoritative vol fog + zero classic fog (PlayZ replaces fog with volumetric).
	//! Returns false when weather is not ready yet (caller may retry).
	static bool ApplyClientScenarioVolFog(float volFogDist, float volFogHeight, float volFogBias, float transitionTime, bool joinResync = false, float curDist = 0, float curHeight = 0, float curBias = 0)
	{
		if (GetGame().IsServer())
			return true;

		Weather w = GetGame().GetWeather();
		if (!w)
			return false;

		if (joinResync && transitionTime > 0)
		{
			w.SetDynVolFogDistanceDensity(curDist, 0);
			w.SetDynVolFogHeightDensity(curHeight, 0);
			w.SetDynVolFogHeightBias(curBias, 0);
		}

		w.SetDynVolFogDistanceDensity(volFogDist, transitionTime);
		w.SetDynVolFogHeightDensity(volFogHeight, transitionTime);
		w.SetDynVolFogHeightBias(volFogBias, transitionTime);
		w.GetFog().SetLimits(0.0, 1.0);
		w.GetFog().Set(0.0, 10, 1000);
		return true;
	}

	static float GetTempModifierByName(string scenarioName)
	{
		if (scenarioName == "Heatwave") return 14.0;
		if (scenarioName == "Coldwave") return -12.0;
		if (scenarioName == "Light Snowfall") return -3.0;
		if (scenarioName == "Heavy Snowfall") return -6.0;
		if (scenarioName == "Blizzard") return -10.0;
		return 0.0;
	}

	static void OnRPC(ParamsReadContext ctx)
	{
		// Weather Sync
		if (!ctx.Read(GetWeather().m_EnablePlayZWeather)) return;
		if (!ctx.Read(GetWeather().m_DebugCycleScenarios)) return;
		
		// PPE Sync
		PlayZPPEConfig ppe = GetPPE();
		if (!ctx.Read(ppe.m_EnableWeatherPPE)) return;
		if (!ctx.Read(ppe.m_SaturationMin)) return;
		if (!ctx.Read(ppe.m_SaturationMax)) return;
		if (!ctx.Read(ppe.m_SaturationBoostClear)) return;
		if (!ctx.Read(ppe.m_ContrastMin)) return;
		if (!ctx.Read(ppe.m_ContrastMax)) return;
		if (!ctx.Read(ppe.m_GrainIntensity)) return;
		if (!ctx.Read(ppe.m_ChromIntensity)) return;
		if (!ctx.Read(ppe.m_GodRaysIntensity)) return;
		if (!ctx.Read(ppe.m_ShelterFadeSpeed)) return;
		if (!ctx.Read(ppe.m_WeatherFadeSpeed)) return;
		if (!ctx.Read(ppe.m_ColorClearR)) return;
		if (!ctx.Read(ppe.m_ColorClearG)) return;
		if (!ctx.Read(ppe.m_ColorClearB)) return;
		if (!ctx.Read(ppe.m_ColorGloomyR)) return;
		if (!ctx.Read(ppe.m_ColorGloomyG)) return;
		if (!ctx.Read(ppe.m_ColorGloomyB)) return;

		if (!ctx.Read(ppe.m_ColorHeatwaveR)) return;
		if (!ctx.Read(ppe.m_ColorHeatwaveG)) return;
		if (!ctx.Read(ppe.m_ColorHeatwaveB)) return;

		if (!ctx.Read(ppe.m_ColorColdwaveR)) return;
		if (!ctx.Read(ppe.m_ColorColdwaveG)) return;
		if (!ctx.Read(ppe.m_ColorColdwaveB)) return;

		if (!ctx.Read(ppe.m_ColorSnowR)) return;
		if (!ctx.Read(ppe.m_ColorSnowG)) return;
		if (!ctx.Read(ppe.m_ColorSnowB)) return;

		Debug.WeatherLog("PlayZWeather:: Configs Synced from server.");
	}
}
