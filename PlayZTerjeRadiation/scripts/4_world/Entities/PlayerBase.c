modded class PlayerBase
{
	protected bool m_PlayZDosimeterTooltipDirty;
	protected int m_PlayZRadSicknessSynch = 0;

	protected void PlayZ_InvalidateTerjeBodyProtectionCache()
	{
		PluginTerjeScriptableAreas plugin = GetTerjeScriptableAreas();
		if (plugin)
		{
			plugin.PlayZ_InvalidateBodyProtectionCache(this);
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		PlayZ_InvalidateTerjeBodyProtectionCache();
		PlayZSetDosimeterTooltipDirty(true);
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		PlayZ_InvalidateTerjeBodyProtectionCache();
		PlayZSetDosimeterTooltipDirty(true);
	}

	override void Init()
	{
		super.Init();
		RegisterNetSyncVariableInt("m_PlayZRadSicknessSynch", 0, 500);
	}

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

	//! Terje radiation sickness value (0-5, tm.rad_v) — NetSync on client; stats on server only.
	float PlayZGetRadSicknessForPPE()
	{
		if (!IsAlive() || !IsTerjeLocalControlledPlayer())
		{
			return 0;
		}

		if (HasActiveTerjeStartScreen())
		{
			return 0;
		}

		if (GetGame().IsClient())
		{
			return m_PlayZRadSicknessSynch * 0.01;
		}

		TerjePlayerStats stats = GetTerjeStats();
		if (!stats)
		{
			return 0;
		}

		return stats.GetRadiationValue();
	}

	bool PlayZIsTerjeRadPPEPlayerReady()
	{
		if (!GetIdentity() || !IsTerjeLocalControlledPlayer())
		{
			return false;
		}

		return PlayZMissionClientGate.IsPPEReady(this);
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

		int newSickness = Math.Clamp(Math.Round(GetTerjeStats().GetRadiationValue() * 100), 0, 500);
		if (m_PlayZRadSicknessSynch != newSickness)
		{
			m_PlayZRadSicknessSynch = newSickness;
			SetSynchDirty();
		}
	}
}
