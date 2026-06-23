modded class BatteryCharger
{
	protected ItemBase PlayZ_GetAttachedChargingBattery()
	{
		ItemBase battery = ItemBase.Cast(FindAttachmentBySlotName("LargeBattery"));
		if (battery)
		{
			return battery;
		}

		return ItemBase.Cast(FindAttachmentBySlotName("ExpansionHelicopterBattery"));
	}

	override void OnWork(float consumed_energy)
	{
		if (GetCompEM().GetPluggedDevice())
		{
			super.OnWork(consumed_energy);
			return;
		}

		ItemBase battery = PlayZ_GetAttachedChargingBattery();
		if (!battery)
		{
			super.OnWork(consumed_energy);
			return;
		}

		if (!g_Game.IsServer())
		{
			return;
		}

		float battery_capacity = battery.GetCompEM().GetEnergyMax();

		if (battery.GetCompEM().GetEnergy() < battery_capacity)
		{
			float charger_health = GetHealth("", "");
			float energy_add = m_ChargeEnergyPerSecond * (consumed_energy / GetCompEM().GetEnergyUsage());

			#ifdef DIAG_DEVELOPER
			if (FeatureTimeAccel.GetFeatureTimeAccelEnabled(ETimeAccelCategories.ENERGY_RECHARGE))
			{
				float timeAccel = FeatureTimeAccel.GetFeatureTimeAccelValue();
				energy_add *= timeAccel;
			}
			#endif

			if (GetCompEM().ConsumeEnergy(energy_add))
			{
				energy_add = energy_add * (0.5 + charger_health * 0.005);
			}
			else
			{
				energy_add = 0;
			}

			battery.GetCompEM().AddEnergy(energy_add);
		}
		else
		{
			battery.GetCompEM().SetEnergy(battery_capacity);
		}

		m_BatteryEnergy0To100 = battery.GetCompEM().GetEnergy0To100();
		SetSynchDirty();
	}

	override void OnOwnSocketTaken(EntityAI device)
	{
		string att_type = device.GetType();

		if (att_type == "ExpansionHelicopterBattery")
		{
			HideAttachedClipsStates();
			ShowSelection(SEL_CLIPS_CAR);
			HideSelection(SEL_CLIPS_DETACHED);
			HideSelection(SEL_CLIPS_FOLDED);
			return;
		}

		super.OnOwnSocketTaken(device);
	}

	override void RefreshPhysics()
	{
		super.RefreshPhysics();

		if (!GetAttachmentByType(CarBattery) && FindAttachmentBySlotName("ExpansionHelicopterBattery"))
		{
			RemoveProxyPhysics("battery");
			AddProxyPhysics("battery");
		}
	}
}
