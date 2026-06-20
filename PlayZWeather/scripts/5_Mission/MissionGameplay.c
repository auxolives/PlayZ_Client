modded class MissionGameplay
{
	protected PPERequester_PlayZWeather m_PlayZWeatherPPE;
	
	protected float m_RoofCheckTimer = 0.0;
	protected bool m_IsUnderRoof = false;
	protected vector m_LastRoofCheckPos;

	protected float m_PPE_Saturation = 1.0;
	protected float m_PPE_Contrast = 1.0;
	protected float m_PPE_Grain = 0.0;
	protected float m_PPE_Chrom = 0.0;
	protected float m_PPE_GodRays = 0.0;
	protected float m_PPE_SunVis = 1.0;
	protected float m_PPE_ColorR = 1.0;
	protected float m_PPE_ColorG = 1.0;
	protected float m_PPE_ColorB = 1.0;
	
	// Throttled target variables
	// Last applied values to requester
	protected float m_LastSat		= -1.0;
	protected float m_LastCon		= -1.0;
	protected float m_LastGrain		= -1.0;
	protected float m_LastChrom		= -1.0;
	protected float m_LastGodRays	= -1.0;
	protected float m_LastSunVis	= -1.0;
	protected float m_LastR			= -1.0;
	protected float m_LastG			= -1.0;
	protected float m_LastB			= -1.0;
	
	// Throttled target variables for interpolation
	protected float m_TargetSat     = 1.0;
	protected ref PlayZPPEUpdateGate m_PlayZWeatherPPESampleGate;

	protected bool PlayZ_ShouldSampleWeatherPPE(float timeslice)
	{
		if (!m_PlayZWeatherPPESampleGate)
		{
			m_PlayZWeatherPPESampleGate = new PlayZPPEUpdateGate();
		}

		return m_PlayZWeatherPPESampleGate.ConsumeSampleTick(timeslice);
	}
	protected float m_TargetCon     = 1.0;
	protected float m_TargetGrain   = 0.0;
	protected float m_TargetChrom   = 0.0;
	protected float m_TargetGodRays = 0.0;
	protected float m_TargetSunVis  = 1.0;
	protected float m_TargetR       = 1.0;
	protected float m_TargetG       = 1.0;
	protected float m_TargetB       = 1.0;
	protected float m_PlayZScenarioTintWeight = 0.0;
	protected bool m_PlayZPendingJoinWeatherSync = false;
	protected float m_PlayZPendingJoinTintWeight = 0.0;
	protected float m_PlayZPendingJoinTempMod = 0.0;

	override void OnInit()
	{
		super.OnInit();
		DayZGame.Event_OnRPC.Insert(OnPlayZWeatherRPC);
	}

	void ~MissionGameplay()
	{
		if (DayZGame.Event_OnRPC)
		{
			DayZGame.Event_OnRPC.Remove(OnPlayZWeatherRPC);
		}
	}

	void OnPlayZWeatherRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if (rpc_type == PlayZRPCs.SYNC_CONFIG)
		{
			PlayZConfig.OnRPC(ctx);
		}
		else if (rpc_type == PlayZRPCs.SYNC_SCENARIO)
		{
			string scenarioName;
			float tempMod;
			float volFogDist;
			float volFogHeight;
			float volFogBias;
			float volFogTransitionTime;
			bool isJoinResync;
			if (!ctx.Read(scenarioName)) return;
			if (!ctx.Read(tempMod)) return;
			if (!ctx.Read(volFogDist)) return;
			if (!ctx.Read(volFogHeight)) return;
			if (!ctx.Read(volFogBias)) return;
			if (!ctx.Read(volFogTransitionTime)) return;
			if (!ctx.Read(isJoinResync)) return;

			PlayZConfig.m_CurrentScenarioName = scenarioName;
			PlayZConfig.m_CurrentScenarioTempMod = tempMod;
			PlayZConfig.ApplyClientScenarioVolFog(volFogDist, volFogHeight, volFogBias, volFogTransitionTime);

			if (isJoinResync)
			{
				float scenarioTintWeight;
				float syncedTempMod;
				if (!ctx.Read(scenarioTintWeight)) return;
				if (!ctx.Read(syncedTempMod)) return;
				m_PlayZPendingJoinTintWeight = scenarioTintWeight;
				m_PlayZPendingJoinTempMod = syncedTempMod;
				m_PlayZPendingJoinWeatherSync = true;
				PlayZ_TryApplyPendingJoinWeatherState();
			}
		}
	}

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		PlayZWeatherNamalskPPEBridge.OnTick(timeslice);

		if (!PlayZConfig.GetPPE().m_EnableWeatherPPE)
		{
			if (m_PlayZWeatherPPE && m_PlayZWeatherPPE.IsRequesterRunning())
				m_PlayZWeatherPPE.Stop();
			return;
		}

		UpdateWeatherPPE(timeslice);
	}

	float GetNormalizedWindMagnitude(Weather weather)
	{
		float wind = weather.GetWindSpeed();
		float maxWind = PlayZConfig.GetPPE().m_MaxWindPPE;
		if (maxWind <= 0) return 0;
		return wind / maxWind;
	}

	void PlayZ_ApplyWeatherTintTargets(float overcast, float rain, float snowfall, float scenarioTintWeight, PlayZPPEConfig ppe)
	{
		float baseR = m_TargetR;
		float baseG = m_TargetG;
		float baseB = m_TargetB;

		if (overcast < 0.3)
		{
			baseR = ppe.m_ColorClearR;
			baseG = ppe.m_ColorClearG;
			baseB = ppe.m_ColorClearB;
		}
		else if (snowfall > 0.1)
		{
			baseR = ppe.m_ColorSnowR;
			baseG = ppe.m_ColorSnowG;
			baseB = ppe.m_ColorSnowB;
		}
		else if (rain > 0.1 || overcast > 0.8)
		{
			baseR = ppe.m_ColorGloomyR;
			baseG = ppe.m_ColorGloomyG;
			baseB = ppe.m_ColorGloomyB;
		}

		float eventR = baseR;
		float eventG = baseG;
		float eventB = baseB;
		string scenarioName = PlayZConfig.m_CurrentScenarioName;

		if (scenarioName == "Heatwave")
		{
			eventR = ppe.m_ColorHeatwaveR;
			eventG = ppe.m_ColorHeatwaveG;
			eventB = ppe.m_ColorHeatwaveB;
		}
		else if (scenarioName == "Coldwave")
		{
			eventR = ppe.m_ColorColdwaveR;
			eventG = ppe.m_ColorColdwaveG;
			eventB = ppe.m_ColorColdwaveB;
		}

		m_TargetR = Math.Lerp(baseR, eventR, scenarioTintWeight);
		m_TargetG = Math.Lerp(baseG, eventG, scenarioTintWeight);
		m_TargetB = Math.Lerp(baseB, eventB, scenarioTintWeight);
	}

	void PlayZ_RecalculatePPETargets(Weather weather, PlayZPPEConfig ppe)
	{
		float overcast = weather.GetOvercast().GetActual();
		float rain = weather.GetRain().GetActual();
		float snowfall = weather.GetSnowfall().GetActual();
		float windNormalized = GetNormalizedWindMagnitude(weather);

		m_TargetSat = Math.Lerp(ppe.m_SaturationMax, ppe.m_SaturationMin, overcast);
		m_TargetCon = Math.Lerp(ppe.m_ContrastMin, ppe.m_ContrastMax, overcast);

		PlayZ_ApplyWeatherTintTargets(overcast, rain, snowfall, m_PlayZScenarioTintWeight, ppe);

		if (overcast < 0.3 && m_PlayZScenarioTintWeight < 0.01)
		{
			m_TargetSat = ppe.m_SaturationBoostClear;
		}

		m_TargetGrain = Math.Pow(rain, 2.0) * ppe.m_GrainIntensity;

		m_TargetChrom = 0;
		if (windNormalized > 0.5)
		{
			m_TargetChrom = Math.InverseLerp(0.7, 1.0, windNormalized) * ppe.m_ChromIntensity;
		}

		m_TargetGodRays = Math.Clamp(1.0 - overcast, 0.0, ppe.m_GodRaysIntensity);
		m_TargetSunVis = Math.Clamp(1.0 - overcast, 0.0, 1.0);

		if (overcast > 0.6)
		{
			m_TargetGodRays = 0;
			m_TargetSunVis = 0;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player && PlayZMissionClientGate.IsPPEReady(player))
		{
			m_RoofCheckTimer += 0.2;
			if (m_RoofCheckTimer >= 3.0)
			{
				m_RoofCheckTimer = 0;
				m_IsUnderRoof = player.IsSoundInsideBuilding();

				if (!m_IsUnderRoof)
				{
					vector curPos = player.GetPosition();
					if (vector.DistanceSq(curPos, m_LastRoofCheckPos) > 0.25)
					{
						m_LastRoofCheckPos = curPos;
						vector from = curPos;
						vector to = from + "0 15 0";
						Object hitObject;
						vector hitPos;
						vector hitNormal;
						float hitFraction;
						m_IsUnderRoof = DayZPhysics.RayCastBullet(from, to, PhxInteractionLayers.BUILDING|PhxInteractionLayers.VEHICLE|PhxInteractionLayers.ITEM_LARGE, null, hitObject, hitPos, hitNormal, hitFraction);
					}
				}
			}

			if (m_IsUnderRoof)
			{
				m_TargetGrain = 0;
			}

			if (player.IsSoundInsideBuilding())
			{
				m_TargetChrom = 0;
			}
		}
	}

	void PlayZ_ResetPPELastApplied()
	{
		m_LastSat = -1.0;
		m_LastCon = -1.0;
		m_LastGrain = -1.0;
		m_LastChrom = -1.0;
		m_LastGodRays = -1.0;
		m_LastSunVis = -1.0;
		m_LastR = -1.0;
		m_LastG = -1.0;
		m_LastB = -1.0;
	}

	protected bool PlayZ_WeatherPPEChannelDeltaAtRest(float smoothed, float target, float epsilon)
	{
		return Math.AbsFloat(smoothed - target) <= epsilon;
	}

	protected bool PlayZ_WeatherPPEChannelsAtRest(float scenarioTintTarget, float epsilon)
	{
		if (m_PlayZPendingJoinWeatherSync)
		{
			return false;
		}

		if (!PlayZ_WeatherPPEChannelDeltaAtRest(m_PlayZScenarioTintWeight, scenarioTintTarget, epsilon))
		{
			return false;
		}

		if (!PlayZ_WeatherPPEChannelDeltaAtRest(m_PPE_Saturation, m_TargetSat, epsilon))
		{
			return false;
		}

		if (!PlayZ_WeatherPPEChannelDeltaAtRest(m_PPE_Contrast, m_TargetCon, epsilon))
		{
			return false;
		}

		if (!PlayZ_WeatherPPEChannelDeltaAtRest(m_PPE_Grain, m_TargetGrain, epsilon))
		{
			return false;
		}

		if (!PlayZ_WeatherPPEChannelDeltaAtRest(m_PPE_Chrom, m_TargetChrom, epsilon))
		{
			return false;
		}

		if (!PlayZ_WeatherPPEChannelDeltaAtRest(m_PPE_GodRays, m_TargetGodRays, epsilon))
		{
			return false;
		}

		if (!PlayZ_WeatherPPEChannelDeltaAtRest(m_PPE_SunVis, m_TargetSunVis, epsilon))
		{
			return false;
		}

		if (!PlayZ_WeatherPPEChannelDeltaAtRest(m_PPE_ColorR, m_TargetR, epsilon))
		{
			return false;
		}

		if (!PlayZ_WeatherPPEChannelDeltaAtRest(m_PPE_ColorG, m_TargetG, epsilon))
		{
			return false;
		}

		if (!PlayZ_WeatherPPEChannelDeltaAtRest(m_PPE_ColorB, m_TargetB, epsilon))
		{
			return false;
		}

		return true;
	}

	void PlayZ_TryApplyPendingJoinWeatherState()
	{
		if (!m_PlayZPendingJoinWeatherSync)
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player)
		{
			return;
		}

		PlayZ_ApplyJoinWeatherState(m_PlayZPendingJoinTintWeight, m_PlayZPendingJoinTempMod);
		m_PlayZPendingJoinWeatherSync = false;
	}

	void PlayZ_ApplyJoinWeatherState(float scenarioTintWeight, float syncedTempMod)
	{
		m_PlayZScenarioTintWeight = scenarioTintWeight;

		Weather weather = GetGame().GetWeather();
		if (weather)
		{
			PlayZPPEConfig ppe = PlayZConfig.GetPPE();
			PlayZ_RecalculatePPETargets(weather, ppe);

			m_PPE_Saturation = m_TargetSat;
			m_PPE_Contrast = m_TargetCon;
			m_PPE_Grain = m_TargetGrain;
			m_PPE_Chrom = m_TargetChrom;
			m_PPE_GodRays = m_TargetGodRays;
			m_PPE_SunVis = m_TargetSunVis;
			m_PPE_ColorR = m_TargetR;
			m_PPE_ColorG = m_TargetG;
			m_PPE_ColorB = m_TargetB;
			PlayZ_ResetPPELastApplied();
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player)
		{
			player.PlayZ_ApplySyncedWeatherTempMod(syncedTempMod);
		}
	}

	void UpdateWeatherPPE(float timeslice)
	{
		PlayZ_TryApplyPendingJoinWeatherState();

		float namOverallW = PlayZWeatherNamalskPPEBridge.GetOverallWeight();
		float namColorW = PlayZWeatherNamalskPPEBridge.GetGlowColorWeight();

		Weather weather = GetGame().GetWeather();
		if (!weather) return;

		PlayZPPEConfig ppe = PlayZConfig.GetPPE();
		const float EPSILON = 0.001;

		if (!m_PlayZWeatherPPE)
		{
			m_PlayZWeatherPPE = PPERequester_PlayZWeather.Cast(PPERequesterBank.GetRequester(PPERequesterBank.REQ_PLAYZ_WEATHER));
		}

		float scenarioTintTarget = PlayZWeatherPPE.GetScenarioTintWeightRaw(PlayZConfig.m_CurrentScenarioName, weather);
		float scenarioTintInterp = ppe.m_WeatherFadeSpeed * timeslice;
		if (PlayZConfig.GetWeather().m_DebugCycleScenarios)
		{
			scenarioTintInterp = 2.0 * timeslice;
		}

		if (!PlayZ_WeatherPPEChannelDeltaAtRest(m_PlayZScenarioTintWeight, scenarioTintTarget, EPSILON))
		{
			m_PlayZScenarioTintWeight = Math.Lerp(m_PlayZScenarioTintWeight, scenarioTintTarget, scenarioTintInterp);
		}

		// 1. Calculate target values from synced weather (1 Hz — shared PlayZ PPE sample gate)
		if (PlayZ_ShouldSampleWeatherPPE(timeslice))
		{
			PlayZ_RecalculatePPETargets(weather, ppe);
		}

		if (PlayZ_WeatherPPEChannelsAtRest(scenarioTintTarget, EPSILON))
		{
			return;
		}

		if (!m_PlayZWeatherPPE.IsRequesterRunning())
		{
			m_PlayZWeatherPPE.Start();
		}

		// 2. Smooth Interpolation
		// Use time-sliced interpolation for frame-rate independence
		float visualInterpSpeed = ppe.m_WeatherFadeSpeed * timeslice;
		float physicalInterpSpeed = ppe.m_ShelterFadeSpeed * timeslice;

		if (PlayZConfig.GetWeather().m_DebugCycleScenarios)
		{
			visualInterpSpeed = 2.0 * timeslice;
			physicalInterpSpeed = 2.0 * timeslice;
		}

		// Visuals (Atmosphere)
		m_PPE_Saturation = Math.Lerp(m_PPE_Saturation, m_TargetSat, visualInterpSpeed);
		m_PPE_Contrast = Math.Lerp(m_PPE_Contrast, m_TargetCon, visualInterpSpeed);
		m_PPE_GodRays = Math.Lerp(m_PPE_GodRays, m_TargetGodRays, visualInterpSpeed);
		m_PPE_SunVis = Math.Lerp(m_PPE_SunVis, m_TargetSunVis, visualInterpSpeed);
		m_PPE_ColorR = Math.Lerp(m_PPE_ColorR, m_TargetR, visualInterpSpeed);
		m_PPE_ColorG = Math.Lerp(m_PPE_ColorG, m_TargetG, visualInterpSpeed);
		m_PPE_ColorB = Math.Lerp(m_PPE_ColorB, m_TargetB, visualInterpSpeed);

		// Physical (Shelter/Lens/Wind)
		m_PPE_Grain = Math.Lerp(m_PPE_Grain, m_TargetGrain, physicalInterpSpeed);
		m_PPE_Chrom = Math.Lerp(m_PPE_Chrom, m_TargetChrom, physicalInterpSpeed);

		// Namalsk bridge: blend toward identity (no PlayZ weather grading) — stronger for Glow color (Option B).
		float outSat = Math.Lerp(1.0, m_PPE_Saturation, namOverallW);
		float outCon = Math.Lerp(1.0, m_PPE_Contrast, namOverallW);
		float outGrain = Math.Lerp(0.0, m_PPE_Grain, namOverallW);
		float outChrom = Math.Lerp(0.0, m_PPE_Chrom, namOverallW);
		float outGod = Math.Lerp(0.0, m_PPE_GodRays, namOverallW);
		float outSunVis = Math.Lerp(1.0, m_PPE_SunVis, namOverallW);
		float outR = Math.Lerp(1.0, m_PPE_ColorR, namColorW);
		float outG = Math.Lerp(1.0, m_PPE_ColorG, namColorW);
		float outB = Math.Lerp(1.0, m_PPE_ColorB, namColorW);

		// 3. Apply to Requester (Throttled by Epsilon Delta)

		if (Math.AbsFloat(outSat - m_LastSat) > EPSILON)
		{
			m_PlayZWeatherPPE.SetSaturation(outSat);
			m_LastSat = outSat;
		}

		if (Math.AbsFloat(outCon - m_LastCon) > EPSILON)
		{
			m_PlayZWeatherPPE.SetContrast(outCon);
			m_LastCon = outCon;
		}

		if (Math.AbsFloat(outR - m_LastR) > EPSILON || Math.AbsFloat(outG - m_LastG) > EPSILON || Math.AbsFloat(outB - m_LastB) > EPSILON)
		{
			m_PlayZWeatherPPE.SetColorization(outR, outG, outB, 1.0);
			m_LastR = outR; m_LastG = outG; m_LastB = outB;
		}

		if (Math.AbsFloat(outGrain - m_LastGrain) > EPSILON)
		{
			m_PlayZWeatherPPE.SetFilmGrain(outGrain);
			m_LastGrain = outGrain;
		}

		if (Math.AbsFloat(outChrom - m_LastChrom) > EPSILON)
		{
			m_PlayZWeatherPPE.SetChromAber(outChrom);
			m_LastChrom = outChrom;
		}

		if (Math.AbsFloat(outGod - m_LastGodRays) > EPSILON || Math.AbsFloat(outSunVis - m_LastSunVis) > EPSILON)
		{
			m_PlayZWeatherPPE.SetGodRays(outGod, outSunVis);
			m_LastGodRays = outGod; m_LastSunVis = outSunVis;
		}
	}
}
