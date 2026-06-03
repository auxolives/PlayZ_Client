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
	protected float m_TargetUpdateTimer = 0.0;
	protected float m_TargetSat     = 1.0;
	protected float m_TargetCon     = 1.0;
	protected float m_TargetGrain   = 0.0;
	protected float m_TargetChrom   = 0.0;
	protected float m_TargetGodRays = 0.0;
	protected float m_TargetSunVis  = 1.0;
	protected float m_TargetR       = 1.0;
	protected float m_TargetG       = 1.0;
	protected float m_TargetB       = 1.0;

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
			if (ctx.Read(scenarioName) && ctx.Read(tempMod) && ctx.Read(volFogDist) && ctx.Read(volFogHeight) && ctx.Read(volFogBias) && ctx.Read(volFogTransitionTime))
			{
				PlayZConfig.m_CurrentScenarioName = scenarioName;
				PlayZConfig.m_CurrentScenarioTempMod = tempMod;
				PlayZConfig.ApplyClientScenarioVolFog(volFogDist, volFogHeight, volFogBias, volFogTransitionTime);
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

	void UpdateWeatherPPE(float timeslice)
	{
		float namOverallW = PlayZWeatherNamalskPPEBridge.GetOverallWeight();
		float namColorW = PlayZWeatherNamalskPPEBridge.GetGlowColorWeight();

		Weather weather = GetGame().GetWeather();
		if (!weather) return;

		PlayZPPEConfig ppe = PlayZConfig.GetPPE();

		if (!m_PlayZWeatherPPE)
		{
			m_PlayZWeatherPPE = PPERequester_PlayZWeather.Cast(PPERequesterBank.GetRequester(PPERequester_PlayZWeather));
		}

		if (!m_PlayZWeatherPPE.IsRequesterRunning())
			m_PlayZWeatherPPE.Start();

		// 1. Calculate Target Values based on synced weather phenomena (5Hz Throttle)
		m_TargetUpdateTimer += timeslice;
		if (m_TargetUpdateTimer >= 0.2) // 5Hz
		{
			m_TargetUpdateTimer = 0;
			
			float overcast = weather.GetOvercast().GetActual();
			float rain = weather.GetRain().GetActual();
			float snowfall = weather.GetSnowfall().GetActual();
			float windNormalized = GetNormalizedWindMagnitude(weather);

			// Logic for Saturation/Contrast: Desaturate as it gets cloudier/rainier
			m_TargetSat = Math.Lerp(ppe.m_SaturationMax, ppe.m_SaturationMin, overcast);
			m_TargetCon = Math.Lerp(ppe.m_ContrastMin, ppe.m_ContrastMax, overcast); // More dramatic contrast when dark

			// Logic for Tints
			if (PlayZConfig.m_CurrentScenarioName == "Heatwave")
			{
				m_TargetR = ppe.m_ColorHeatwaveR; m_TargetG = ppe.m_ColorHeatwaveG; m_TargetB = ppe.m_ColorHeatwaveB;
			}
			else if (PlayZConfig.m_CurrentScenarioName == "Coldwave")
			{
				m_TargetR = ppe.m_ColorColdwaveR; m_TargetG = ppe.m_ColorColdwaveG; m_TargetB = ppe.m_ColorColdwaveB;
			}
			else if (overcast < 0.3) // Clear/Sunny
			{
				m_TargetR = ppe.m_ColorClearR; m_TargetG = ppe.m_ColorClearG; m_TargetB = ppe.m_ColorClearB;
				m_TargetSat = ppe.m_SaturationBoostClear; 
			}
			else if (snowfall > 0.1) // Snowy
			{
				m_TargetR = ppe.m_ColorSnowR; m_TargetG = ppe.m_ColorSnowG; m_TargetB = ppe.m_ColorSnowB;
			}
			else if (rain > 0.1 || overcast > 0.8) // Rainy/Gloomy
			{
				m_TargetR = ppe.m_ColorGloomyR; m_TargetG = ppe.m_ColorGloomyG; m_TargetB = ppe.m_ColorGloomyB;
			}

			// Logic for Film Grain: Scales with Rain (Power Progression)
			m_TargetGrain = Math.Pow(rain, 2.0) * ppe.m_GrainIntensity;
			
			// Logic for Chromatic Aberration: Scales with Wind
			m_TargetChrom = 0;
			if (windNormalized > 0.5)
			{
				m_TargetChrom = Math.InverseLerp(0.7, 1.0, windNormalized) * ppe.m_ChromIntensity;
			}

			// Logic for God Rays: High in sunny days, diffused in light fog, 0 in storms
			m_TargetGodRays = Math.Clamp(1.0 - overcast, 0.0, ppe.m_GodRaysIntensity);
			m_TargetSunVis = Math.Clamp(1.0 - overcast, 0.0, 1.0);
			
			if (overcast > 0.6) // Too cloudy for god rays
			{
				m_TargetGodRays = 0;
				m_TargetSunVis = 0;
			}

			// Logic for Shelter: Disable effects if covered
			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
			if (player)
			{
				// Interval Raycast Check (Every 3.0s) for Roof Detection
				m_RoofCheckTimer += 0.2; // We are in a 0.2s block
				if (m_RoofCheckTimer >= 3.0)
				{
					m_RoofCheckTimer = 0;

					// P0 Optimization: Use sound-engine building state first (very cheap bit-check)
					m_IsUnderRoof = player.IsSoundInsideBuilding();

					// If sound-engine says we are "outside", we might still be under a static roof (carport, shed)
					if (!m_IsUnderRoof)
					{
						vector curPos = player.GetPosition();

						// P1 Optimization: Skip raycast if player has not moved since last check.
						// Static roofs don't change — if position is the same, result is the same.
						if (vector.DistanceSq(curPos, m_LastRoofCheckPos) > 0.25)
						{
							m_LastRoofCheckPos = curPos;

							vector from = curPos;
							vector to = from + "0 15 0"; // Check 15m above head (sufficient for most structures)

							Object hitObject;
							vector hitPos;
							vector hitNormal;
							float hitFraction;

							// Raycast against buildings, vehicles, and large items (tents)
							m_IsUnderRoof = DayZPhysics.RayCastBullet(from, to, PhxInteractionLayers.BUILDING|PhxInteractionLayers.VEHICLE|PhxInteractionLayers.ITEM_LARGE, null, hitObject, hitPos, hitNormal, hitFraction);
						}
					}
				}

				// Grain (Noise) is blocked by ANY roof
				if (m_IsUnderRoof)
				{
					m_TargetGrain = 0; 
				}

				// Chromatic Aberration (Wind) is only blocked if actually INSIDE a building volume
				if (player.IsSoundInsideBuilding())
				{
					m_TargetChrom = 0;
				}
			}
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
		const float EPSILON = 0.001;

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
