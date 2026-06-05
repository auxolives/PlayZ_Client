modded class MissionGameplay
{
	protected ref PPERequester_PlayZRadioactiveRain m_PlayZRadRainPPE;
	protected float m_PlayZRadRainWeightSmoothed;
	protected float m_PlayZRadRainLastR = 1.0;
	protected float m_PlayZRadRainLastG = 1.0;
	protected float m_PlayZRadRainLastB = 1.0;

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

		float r;
		float g;
		float b;
		PlayZRadioactiveRainPPE.GetColorizationForWeight(m_PlayZRadRainWeightSmoothed, r, g, b);

		const float EPSILON = 0.001;
		if (Math.AbsFloat(r - m_PlayZRadRainLastR) > EPSILON || Math.AbsFloat(g - m_PlayZRadRainLastG) > EPSILON || Math.AbsFloat(b - m_PlayZRadRainLastB) > EPSILON)
		{
			m_PlayZRadRainPPE.SetColorization(r, g, b, 1.0);
			m_PlayZRadRainLastR = r;
			m_PlayZRadRainLastG = g;
			m_PlayZRadRainLastB = b;
		}
	}

	protected void PlayZ_StopRadRainPPE()
	{
		m_PlayZRadRainWeightSmoothed = 0;
		m_PlayZRadRainLastR = 1.0;
		m_PlayZRadRainLastG = 1.0;
		m_PlayZRadRainLastB = 1.0;

		if (m_PlayZRadRainPPE && m_PlayZRadRainPPE.IsRequesterRunning())
		{
			m_PlayZRadRainPPE.Stop();
		}
	}
}
