modded class MissionGameplay
{
	protected ref PPERequester_PlayZRadEnvironment m_PlayZRadEnvPPE;
	protected float m_PlayZRadEnvDoseSmoothed;
	protected float m_PlayZRadEnvLastSat = 1.0;
	protected float m_PlayZRadEnvLastGrainSharp;
	protected float m_PlayZRadEnvLastGrainSize = 2.75;
	protected float m_PlayZRadEnvLastNoiseMult;

	protected ref PPERequester_PlayZRadBody m_PlayZRadBodyPPE;
	protected float m_PlayZRadBodyDoseSmoothed;
	protected float m_PlayZRadBodyVignetteSmoothed;
	protected float m_PlayZRadBodyFeverSmoothed;
	protected float m_PlayZRadBodyRadialSmoothed;
	protected float m_PlayZRadBodyLastVignette;
	protected float m_PlayZRadBodyLastFever;
	protected float m_PlayZRadBodyLastRadial;

	protected ref PPERequester_HMPGhosts m_PlayZRadGhostPPE;
	protected float m_PlayZRadGhostElapsed;
	protected bool m_PlayZRadGhostStopping;
	protected bool m_PlayZRadEnvPPEWarned;
	protected bool m_PlayZRadBodyPPEWarned;

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		UpdatePlayZRadEnvironmentPPE(timeslice);
		UpdatePlayZRadBodyPPE(timeslice);
		UpdatePlayZDosimeterTooltipRefresh();
	}

	protected void UpdatePlayZDosimeterTooltipRefresh()
	{
		if (GetGame().IsDedicatedServer())
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player || !player.PlayZConsumeDosimeterTooltipDirty())
		{
			return;
		}

		ItemManager itemManager = ItemManager.GetInstance();
		if (itemManager)
		{
			itemManager.PlayZRefreshHoveredItemTooltip();
		}
	}

	protected void UpdatePlayZRadEnvironmentPPE(float timeslice)
	{
		if (GetGame().IsDedicatedServer())
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		float targetDose = 0;
		if (player)
		{
			targetDose = PlayZRadEnvironmentPPE.GetDose(player);
		}

		m_PlayZRadEnvDoseSmoothed = PlayZRadPPE.EnvFadeLerp(m_PlayZRadEnvDoseSmoothed, targetDose, timeslice);

		if (!PlayZRadEnvironmentPPE.HasAnyEffect(m_PlayZRadEnvDoseSmoothed))
		{
			PlayZ_StopRadEnvironmentPPE();
			return;
		}

		if (!m_PlayZRadEnvPPE)
		{
			m_PlayZRadEnvPPE = PPERequester_PlayZRadEnvironment.Cast(PPERequesterBank.GetRequester(PPERequester_PlayZRadEnvironment));
		}

		if (!m_PlayZRadEnvPPE)
		{
			if (!m_PlayZRadEnvPPEWarned)
			{
				m_PlayZRadEnvPPEWarned = true;
				Error("PlayZTerjeRadiation: PPERequester_PlayZRadEnvironment not in bank — rebuild and deploy @PlayZTerjeRadiation on the client.");
			}
			return;
		}

		if (!m_PlayZRadEnvPPE.IsRequesterRunning())
		{
			m_PlayZRadEnvPPE.Start();
		}

		float satWeight = PlayZRadEnvironmentPPE.GetSaturationWeight(m_PlayZRadEnvDoseSmoothed);
		float grainWeight = PlayZRadEnvironmentPPE.GetGrainWeight(m_PlayZRadEnvDoseSmoothed);
		float saturation = PlayZRadEnvironmentPPE.GetSaturationForWeight(satWeight);
		float grainSharp = PlayZRadEnvironmentPPE.GetGrainSharpnessForWeight(grainWeight);
		float grainSize = PlayZRadEnvironmentPPE.GetGrainSizeForWeight(grainWeight);
		float noiseMult = PlayZRadEnvironmentPPE.GetNoiseMultForWeight(grainWeight);

		if (Math.AbsFloat(saturation - m_PlayZRadEnvLastSat) > PlayZRadPPE.EPSILON)
		{
			m_PlayZRadEnvPPE.SetSaturation(saturation);
			m_PlayZRadEnvLastSat = saturation;
		}

		if (Math.AbsFloat(grainSharp - m_PlayZRadEnvLastGrainSharp) > PlayZRadPPE.EPSILON)
		{
			m_PlayZRadEnvPPE.SetFilmGrain(grainSharp, grainSize);
			m_PlayZRadEnvLastGrainSharp = grainSharp;
			m_PlayZRadEnvLastGrainSize = grainSize;
		}
		else
		{
			if (Math.AbsFloat(grainSize - m_PlayZRadEnvLastGrainSize) > PlayZRadPPE.EPSILON)
			{
				m_PlayZRadEnvPPE.SetFilmGrain(grainSharp, grainSize);
				m_PlayZRadEnvLastGrainSize = grainSize;
			}
		}

		if (Math.AbsFloat(noiseMult - m_PlayZRadEnvLastNoiseMult) > PlayZRadPPE.EPSILON)
		{
			m_PlayZRadEnvPPE.SetNoiseMult(noiseMult);
			m_PlayZRadEnvLastNoiseMult = noiseMult;
		}

		m_PlayZRadEnvPPE.SetRequesterUpdating(true);
	}

	protected void PlayZ_StopRadEnvironmentPPE()
	{
		m_PlayZRadEnvLastSat = 1.0;
		m_PlayZRadEnvLastGrainSharp = 0;
		m_PlayZRadEnvLastGrainSize = PlayZRadPPE.ENV_GRAIN_SIZE_DEFAULT;
		m_PlayZRadEnvLastNoiseMult = 0;

		if (m_PlayZRadEnvPPE && m_PlayZRadEnvPPE.IsRequesterRunning())
		{
			m_PlayZRadEnvPPE.Stop();
		}
	}

	protected void UpdatePlayZRadBodyPPE(float timeslice)
	{
		if (GetGame().IsDedicatedServer())
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		float targetDose = 0;
		if (player)
		{
			targetDose = PlayZRadBodyPPE.GetDose(player);
		}

		m_PlayZRadBodyDoseSmoothed = PlayZRadPPE.BodyFadeLerp(m_PlayZRadBodyDoseSmoothed, targetDose, timeslice);

		float targetVignette = PlayZRadBodyPPE.GetVignetteIntensity(PlayZRadBodyPPE.GetVignetteWeight(m_PlayZRadBodyDoseSmoothed));
		float targetFever = PlayZRadBodyPPE.GetFeverIntensity(PlayZRadBodyPPE.GetFeverWeight(m_PlayZRadBodyDoseSmoothed));
		float targetRadial = PlayZRadBodyPPE.GetRadialPower(PlayZRadBodyPPE.GetRadialWeight(m_PlayZRadBodyDoseSmoothed));
		float ghostWeight = PlayZRadBodyPPE.GetGhostWeight(m_PlayZRadBodyDoseSmoothed);

		m_PlayZRadBodyVignetteSmoothed = PlayZRadPPE.BodyFadeLerp(m_PlayZRadBodyVignetteSmoothed, targetVignette, timeslice);
		m_PlayZRadBodyFeverSmoothed = PlayZRadPPE.BodyFadeLerp(m_PlayZRadBodyFeverSmoothed, targetFever, timeslice);
		m_PlayZRadBodyRadialSmoothed = PlayZRadPPE.BodyFadeLerp(m_PlayZRadBodyRadialSmoothed, targetRadial, timeslice);

		bool bodyVisualActive = m_PlayZRadBodyVignetteSmoothed > PlayZRadPPE.EPSILON;
		if (!bodyVisualActive)
		{
			if (m_PlayZRadBodyFeverSmoothed > PlayZRadPPE.EPSILON)
			{
				bodyVisualActive = true;
			}
		}
		if (!bodyVisualActive)
		{
			if (m_PlayZRadBodyRadialSmoothed > PlayZRadPPE.EPSILON)
			{
				bodyVisualActive = true;
			}
		}

		bool ghostActive = ghostWeight > PlayZRadPPE.EPSILON;

		if (!bodyVisualActive && !ghostActive && !m_PlayZRadGhostStopping)
		{
			PlayZ_StopRadBodyPPE();
			PlayZ_StopRadGhostPPE();
			return;
		}

		if (bodyVisualActive)
		{
			if (!m_PlayZRadBodyPPE)
			{
				m_PlayZRadBodyPPE = PPERequester_PlayZRadBody.Cast(PPERequesterBank.GetRequester(PPERequester_PlayZRadBody));
			}

			if (!m_PlayZRadBodyPPE)
			{
				if (!m_PlayZRadBodyPPEWarned)
				{
					m_PlayZRadBodyPPEWarned = true;
					Error("PlayZTerjeRadiation: PPERequester_PlayZRadBody not in bank — rebuild and deploy @PlayZTerjeRadiation on the client.");
				}
			}

			if (m_PlayZRadBodyPPE)
			{
				if (!m_PlayZRadBodyPPE.IsRequesterRunning())
				{
					m_PlayZRadBodyPPE.Start();
				}

				if (Math.AbsFloat(m_PlayZRadBodyVignetteSmoothed - m_PlayZRadBodyLastVignette) > PlayZRadPPE.EPSILON)
				{
					m_PlayZRadBodyPPE.SetVignette(m_PlayZRadBodyVignetteSmoothed);
					m_PlayZRadBodyLastVignette = m_PlayZRadBodyVignetteSmoothed;
				}

				if (Math.AbsFloat(m_PlayZRadBodyFeverSmoothed - m_PlayZRadBodyLastFever) > PlayZRadPPE.EPSILON)
				{
					m_PlayZRadBodyPPE.SetGaussBlur(m_PlayZRadBodyFeverSmoothed);
					m_PlayZRadBodyLastFever = m_PlayZRadBodyFeverSmoothed;
				}

				if (Math.AbsFloat(m_PlayZRadBodyRadialSmoothed - m_PlayZRadBodyLastRadial) > PlayZRadPPE.EPSILON)
				{
					m_PlayZRadBodyPPE.SetRadialBlur(m_PlayZRadBodyRadialSmoothed);
					m_PlayZRadBodyLastRadial = m_PlayZRadBodyRadialSmoothed;
				}

				m_PlayZRadBodyPPE.SetRequesterUpdating(true);
			}
		}
		else
		{
			if (m_PlayZRadBodyPPE && m_PlayZRadBodyPPE.IsRequesterRunning())
			{
				m_PlayZRadBodyPPE.Stop();
			}
		}

		UpdatePlayZRadGhostPPE(timeslice, ghostWeight, ghostActive);
	}

	protected void UpdatePlayZRadGhostPPE(float timeslice, float ghostWeight, bool ghostActive)
	{
		if (!ghostActive)
		{
			if (m_PlayZRadGhostPPE && m_PlayZRadGhostPPE.IsRequesterRunning() && !m_PlayZRadGhostStopping)
			{
				m_PlayZRadGhostPPE.FadeOutEffect(3.0);
				m_PlayZRadGhostStopping = true;
			}

			if (m_PlayZRadGhostStopping)
			{
				if (m_PlayZRadGhostPPE)
				{
					if (!m_PlayZRadGhostPPE.IsRequesterRunning())
					{
						m_PlayZRadGhostStopping = false;
					}
					else
					{
						m_PlayZRadGhostPPE.SetRequesterUpdating(true);
					}
				}
			}

			return;
		}

		m_PlayZRadGhostStopping = false;

		if (!m_PlayZRadGhostPPE)
		{
			m_PlayZRadGhostPPE = PPERequester_HMPGhosts.Cast(PPERequesterBank.GetRequester(PPERequester_HMPGhosts));
		}

		if (!m_PlayZRadGhostPPE)
		{
			return;
		}

		if (!m_PlayZRadGhostPPE.IsRequesterRunning())
		{
			m_PlayZRadGhostPPE.Start();
			m_PlayZRadGhostElapsed = 0;
		}

		m_PlayZRadGhostElapsed = m_PlayZRadGhostElapsed + timeslice;
		float pulse = PlayZRadBodyPPE.GetGhostPulseProgress(m_PlayZRadGhostElapsed, ghostWeight);
		m_PlayZRadGhostPPE.SetPulseProgress(pulse);
		m_PlayZRadGhostPPE.SetRequesterUpdating(true);
	}

	protected void PlayZ_StopRadBodyPPE()
	{
		m_PlayZRadBodyLastVignette = 0;
		m_PlayZRadBodyLastFever = 0;
		m_PlayZRadBodyLastRadial = 0;

		if (m_PlayZRadBodyPPE && m_PlayZRadBodyPPE.IsRequesterRunning())
		{
			m_PlayZRadBodyPPE.Stop();
		}
	}

	protected void PlayZ_StopRadGhostPPE()
	{
		m_PlayZRadGhostElapsed = 0;
		m_PlayZRadGhostStopping = false;

		if (m_PlayZRadGhostPPE && m_PlayZRadGhostPPE.IsRequesterRunning())
		{
			m_PlayZRadGhostPPE.Stop();
		}
	}
}
