modded class PlayerBase
{
	protected bool m_PlayZDosimeterTooltipDirty;

	void PlayZSetDosimeterTooltipDirty(bool dirty)
	{
		m_PlayZDosimeterTooltipDirty = dirty;
	}

	bool PlayZConsumeDosimeterTooltipDirty()
	{
		if (!m_PlayZDosimeterTooltipDirty)
		{
			return false;
		}

		m_PlayZDosimeterTooltipDirty = false;
		return true;
	}

	bool PlayZHasActiveDosimeterInHands()
	{
		EntityAI inHands = GetHumanInventory().GetEntityInHands();
		TerjeDosimetrBase dosimeter = TerjeDosimetrBase.Cast(inHands);
		if (!dosimeter || !dosimeter.HasEnergyManager())
		{
			return false;
		}

		return dosimeter.GetCompEM().IsWorking();
	}

	//! Client PPE reads NetSync accumulator (tm.rad_acc is server-only).
	float PlayZGetRadBodyBufferForPPE()
	{
		return GetTerjeRadiation();
	}

	//! Env PPE dose after gear + radres perk — same scaling as AddTerjeRadiationAdvanced.
	float PlayZGetRadEnvironmentExposureForPPE()
	{
		PluginTerjeScriptableAreas plugin = GetTerjeScriptableAreas();
		if (!plugin)
		{
			return 0;
		}

		float rawDose = plugin.PlayZGetRawEnvironmentDoseForPPE(this);
		if (rawDose <= 0)
		{
			return 0;
		}

		float protection = GetTerjeRadiationProtection(rawDose);
		return rawDose * (1.0 - protection);
	}

	override void UpdateTerjeRadiationAccumulated()
	{
		if (!GetGame().IsServer())
		{
			return;
		}

		if (!IsAlive() || !GetTerjeStats())
		{
			return;
		}

		int newValue = (int)Math.Round(GetTerjeStats().GetRadiationAccumulated() / TerjeRadiationConstants.RADIATION_PLAYER_ACCUMULATOR_SYNCH_DIVIDER);
		if (m_terjeRadiationSynch != newValue)
		{
			m_terjeRadiationSynch = newValue;
			SetSynchDirty();
		}
	}
}
