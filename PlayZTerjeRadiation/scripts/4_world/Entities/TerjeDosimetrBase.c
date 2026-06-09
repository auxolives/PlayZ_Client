modded class TerjeDosimetrBase
{
	static const int PLAYZ_DISPLAY_SMOOTH_STEPS = 3;

	protected int m_PlayZDisplayValue;
	protected int m_PlayZDisplayTarget;
	protected int m_PlayZDisplaySmoothStart;
	protected int m_PlayZDisplaySmoothStep;

	override void OnWorkStart()
	{
		super.OnWorkStart();
		PlayZResetSmoothedDisplay();
		PlayZMarkDosimeterTooltipDirty();
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
		PlayZResetSmoothedDisplay();
		PlayZMarkDosimeterTooltipDirty();
	}

	override void OnWork(float consumed_energy)
	{
		super.OnWork(consumed_energy);

		if (!g_Game.IsClient())
		{
			return;
		}

		float radioactiveValue = Math.Clamp(CalculateTerjeEnvironmentRadiation() * TerjeGeigerRadiationModifier(), 0, TerjeGeigerMaxLimit());
		int displayValue = PlayZAdvanceSmoothedDisplay((int)radioactiveValue);
		TerjeUpdateDisplayValueClient(displayValue);
	}

	protected void PlayZResetSmoothedDisplay()
	{
		m_PlayZDisplayValue = 0;
		m_PlayZDisplayTarget = 0;
		m_PlayZDisplaySmoothStart = 0;
		m_PlayZDisplaySmoothStep = PLAYZ_DISPLAY_SMOOTH_STEPS;
	}

	protected int PlayZAdvanceSmoothedDisplay(int targetValue)
	{
		if (targetValue != m_PlayZDisplayTarget)
		{
			m_PlayZDisplaySmoothStart = m_PlayZDisplayValue;
			m_PlayZDisplayTarget = targetValue;
			m_PlayZDisplaySmoothStep = 0;
		}

		if (m_PlayZDisplaySmoothStep < PLAYZ_DISPLAY_SMOOTH_STEPS)
		{
			m_PlayZDisplaySmoothStep = m_PlayZDisplaySmoothStep + 1;
		}

		float blend = m_PlayZDisplaySmoothStep / (float)PLAYZ_DISPLAY_SMOOTH_STEPS;
		m_PlayZDisplayValue = Math.Round(Math.Lerp(m_PlayZDisplaySmoothStart, m_PlayZDisplayTarget, blend));
		return m_PlayZDisplayValue;
	}

	protected void PlayZMarkDosimeterTooltipDirty()
	{
		if (!g_Game.IsClient())
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (player)
		{
			player.PlayZSetDosimeterTooltipDirty(true);
		}
	}
}
