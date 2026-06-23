modded class VehicleBattery
{
	protected float m_PlayZRadDrainAccum;

	override bool IsTerjeRadiationAccumulated()
	{
		return false;
	}

	override void ProcessVariables()
	{
		super.ProcessVariables();
		PlayZ_TickZoneEnergyDrain();
	}

	protected void PlayZ_TickZoneEnergyDrain()
	{
		if (!g_Game.IsDedicatedServer())
		{
			return;
		}

		PlayZRadiationConfig cfg = PlayZRadiationManager.GetRadiation();
		if (!cfg.m_BatteryZoneDrainEnabled)
		{
			return;
		}

		if (IsRuined())
		{
			return;
		}

		if (!HasEnergyManager())
		{
			return;
		}

		m_PlayZRadDrainAccum = m_PlayZRadDrainAccum + m_ElapsedSinceLastUpdate;
		if (m_PlayZRadDrainAccum < cfg.m_BatteryZoneDrainTickSeconds)
		{
			return;
		}

		float dt = m_PlayZRadDrainAccum;
		m_PlayZRadDrainAccum = 0;

		PluginTerjeScriptableAreas plugin = GetTerjeScriptableAreas();
		if (!plugin)
		{
			return;
		}

		float rawZone = plugin.CalculateTerjeEffectValue(this, "rad");
		rawZone = Math.Min(rawZone, cfg.m_BatteryZoneDrainMaxZone);

		float isolation = PlayZ_GetTerjeHierarchyIsolation();
		float effectiveZone = rawZone * (1.0 - isolation);

		if (effectiveZone <= cfg.m_BatteryZoneDrainThreshold)
		{
			return;
		}

		float divisor = cfg.m_BatteryZoneDrainDivisor;
		if (divisor <= 0)
		{
			return;
		}

		float drainEnergy = (effectiveZone / divisor) * dt;
		if (drainEnergy <= 0)
		{
			return;
		}

		float currentEnergy = GetCompEM().GetEnergy();
		if (drainEnergy > currentEnergy)
		{
			drainEnergy = currentEnergy;
		}

		GetCompEM().ConsumeEnergy(drainEnergy);
	}
}
