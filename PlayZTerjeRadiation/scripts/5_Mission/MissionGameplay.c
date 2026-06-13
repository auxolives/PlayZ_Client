modded class MissionGameplay
{
	protected ref PPERequester_PlayZRadioactiveRain m_PlayZRadRainPPE;
	protected float m_PlayZRadRainWeightSmoothed;
	protected float m_PlayZRadRainLastSat = 1.0;

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		UpdatePlayZRadioactiveRainPPE(timeslice);
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

	protected void UpdatePlayZRadioactiveRainPPE(float timeslice)
	{
		if (GetGame().IsDedicatedServer())
		{
			return;
		}

		float targetWeight = PlayZRadioactiveRainPPE.GetTargetWeight();
		m_PlayZRadRainWeightSmoothed = Math.Lerp(m_PlayZRadRainWeightSmoothed, targetWeight, PlayZRadioactiveRainPPE.FADE_SPEED * timeslice);

		if (m_PlayZRadRainWeightSmoothed < 0.001)
		{
			PlayZ_StopRadRainPPE();
			return;
		}

		if (!m_PlayZRadRainPPE)
		{
			m_PlayZRadRainPPE = PPERequester_PlayZRadioactiveRain.Cast(PPERequesterBank.GetRequester(PPERequester_PlayZRadioactiveRain));
		}

		if (!m_PlayZRadRainPPE)
		{
			return;
		}

		if (!m_PlayZRadRainPPE.IsRequesterRunning())
		{
			m_PlayZRadRainPPE.Start();
		}

		float saturation = PlayZRadioactiveRainPPE.GetSaturationForWeight(m_PlayZRadRainWeightSmoothed);

		const float EPSILON = 0.001;
		if (Math.AbsFloat(saturation - m_PlayZRadRainLastSat) > EPSILON)
		{
			m_PlayZRadRainPPE.SetSaturation(saturation);
			m_PlayZRadRainLastSat = saturation;
		}
	}

	protected void PlayZ_StopRadRainPPE()
	{
		m_PlayZRadRainWeightSmoothed = 0;
		m_PlayZRadRainLastSat = 1.0;

		if (m_PlayZRadRainPPE && m_PlayZRadRainPPE.IsRequesterRunning())
		{
			m_PlayZRadRainPPE.Stop();
		}
	}
}
