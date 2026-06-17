modded class TerjeRadTentStatic
{
	protected EffectSound m_PumpSoundEffect;
	protected string m_PlayZSpawnerId;
	protected bool m_PlayZRestoreInProgress;
	protected bool m_PlayZHeatBridgeActive;

	override void EEInit()
	{
		super.EEInit();
		PlayZ_StartHeatBridge();
	}

	void PlayZ_StartHeatBridge()
	{
		if (!g_Game.IsDedicatedServer() || m_PlayZHeatBridgeActive)
			return;

		m_PlayZHeatBridgeActive = true;
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlayZ_HeatBridgeTick, 1000, true);
	}

	void PlayZ_StopHeatBridge()
	{
		if (!m_PlayZHeatBridgeActive)
			return;

		m_PlayZHeatBridgeActive = false;
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(PlayZ_HeatBridgeTick);
	}

	void PlayZ_HeatBridgeTick()
	{
		if (!GetInventory() || GetInventory().AttachmentCount() == 0)
			return;

		PlayZRadTentStaticHeatBridge.ProcessAttachments(this);
	}

	override void OnSpawnByObjectSpawner(ITEM_SpawnerObject item)
	{
		super.OnSpawnByObjectSpawner(item);

		if (!g_Game.IsDedicatedServer() || !item)
			return;

		if (item.customString == string.Empty)
			return;

		m_PlayZSpawnerId = item.customString;
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlayZ_RestoreAttachments, 1500, false);
	}

	void PlayZ_ClearAttachments()
	{
		GameInventory inv = GetInventory();
		if (!inv)
			return;

		for (int i = inv.AttachmentCount() - 1; i >= 0; i--)
		{
			EntityAI att = inv.GetAttachmentFromIndex(i);
			if (att)
				g_Game.ObjectDelete(att);
		}
	}

	void PlayZ_AppendSlotSnapshot(array<ref PlayZRadTentStaticAttachmentState> attachments, string slotName)
	{
		ref PlayZRadTentStaticAttachmentState attState = new PlayZRadTentStaticAttachmentState();
		attState.slot = slotName;

		ItemBase item = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString(slotName)));
		if (!item)
		{
			attachments.Insert(attState);
			return;
		}

		attState.type = item.GetType();
		attState.health = item.GetHealth01("", "");
		attState.quantity = item.GetQuantity();
		attState.temperature = item.GetTemperature();

		if (slotName == "CanisterGasoline" && item.GetLiquidType() == LIQUID_TERJE_CUSTOM)
			attState.terjeLiquid = item.GetTerjeLiquidClassname();

		attachments.Insert(attState);
	}

	void PlayZ_SnapshotAndScheduleSave()
	{
		if (!g_Game.IsDedicatedServer() || m_PlayZSpawnerId == string.Empty || m_PlayZRestoreInProgress)
			return;

		array<ref PlayZRadTentStaticAttachmentState> attachments = new array<ref PlayZRadTentStaticAttachmentState>();
		PlayZ_AppendSlotSnapshot(attachments, "CanisterGasoline");
		PlayZ_AppendSlotSnapshot(attachments, "CarBattery");
		PlayZRadTentStaticPersistence.SetEntry(m_PlayZSpawnerId, attachments);
	}

	void PlayZ_RestoreAttachments()
	{
		if (!g_Game.IsDedicatedServer() || m_PlayZSpawnerId == string.Empty)
			return;

		PlayZRadTentStaticEntry entry = PlayZRadTentStaticPersistence.GetEntry(m_PlayZSpawnerId);
		if (!entry || !entry.attachments)
			return;

		m_PlayZRestoreInProgress = true;
		PlayZ_ClearAttachments();

		foreach (ref PlayZRadTentStaticAttachmentState attState : entry.attachments)
		{
			if (!attState || attState.type == string.Empty)
				continue;

			int slotId = InventorySlots.GetSlotIdFromString(attState.slot);
			ItemBase item = ItemBase.Cast(GetInventory().CreateAttachmentEx(attState.type, slotId));
			if (!item)
				continue;

			item.SetHealth01("", "", attState.health);
			item.SetQuantity(attState.quantity);

			if (attState.terjeLiquid != string.Empty)
				item.SetTerjeLiquidClassname(attState.terjeLiquid);

			item.SetTemperatureDirect(attState.temperature, true);

			if (item.CanFreeze())
				item.SetFrozen(attState.temperature < item.GetTemperatureFreezeThreshold());
		}

		m_PlayZRestoreInProgress = false;
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		PlayZ_SnapshotAndScheduleSave();
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		PlayZ_SnapshotAndScheduleSave();
	}

	bool IsValidTerjeRadTentToWork()
	{
		ItemBase canister = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("CanisterGasoline")));
		ItemBase battery = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("CarBattery")));

		bool isValidCanister = false;
		if (canister && !canister.IsRuined() && canister.GetQuantity() > canister.GetQuantityMin())
		{
			if (!canister.GetIsFrozen() && ActionWashRadioactiveItems.GetTerjeRadiationCleanupForce(canister) > 0)
			{
				isValidCanister = true;
			}
		}

		bool isValidBattery = false;
		if (battery && !battery.IsRuined() && battery.GetQuantity() > battery.GetQuantityMin())
		{
			isValidBattery = true;
		}

		return isValidBattery && isValidCanister;
	}

	override bool IsTerjeRadTentWorking()
	{
		if (HasEnergyManager())
		{
			return GetCompEM().IsSwitchedOn();
		}

		return false;
	}

	override void SetTerjeRadTentWorking(bool state)
	{
		if (!HasEnergyManager())
		{
			return;
		}

		if (state)
		{
			if (IsValidTerjeRadTentToWork() && GetCompEM().CanSwitchOn())
			{
				GetCompEM().SwitchOn();
			}
		}
		else
		{
			if (GetCompEM().CanSwitchOff())
			{
				GetCompEM().SwitchOff();
			}
		}
	}

	void PlayZ_TerjeDestroyVisualEffects()
	{
		if (!g_Game.IsClient())
		{
			return;
		}

		if (m_ShowerSoundEffects != null)
		{
			foreach (EffectSound soundEffect : m_ShowerSoundEffects)
			{
				if (soundEffect)
				{
					SEffectManager.DestroyEffect(soundEffect);
				}
			}

			m_ShowerSoundEffects = null;
		}

		if (m_ShowerParticleEffects != null)
		{
			foreach (Particle particleEffect : m_ShowerParticleEffects)
			{
				if (particleEffect)
				{
					particleEffect.Stop();
				}
			}

			m_ShowerParticleEffects = null;
		}
	}

	void PlayZ_TerjeStartClientEffects()
	{
		if (!g_Game.IsClient())
		{
			return;
		}

		if (m_ShowerSoundEffects == null)
		{
			m_ShowerSoundEffects = new array<EffectSound>;
			for (int soundIndex = 1; soundIndex <= TERJE_SHOWERS_COUNT; soundIndex++)
			{
				EffectSound effectSound;
				PlaySoundSetAtMemoryPointLoopedSafe(effectSound, "TerjeRadTentShower_SoundSet", "particle_shower_" + soundIndex, 1, 1);
				m_ShowerSoundEffects.Insert(effectSound);
			}
		}

		if (m_ShowerParticleEffects == null)
		{
			m_ShowerParticleEffects = new array<Particle>;
			for (int particleIndex = 1; particleIndex <= TERJE_SHOWERS_COUNT; particleIndex++)
			{
				m_ShowerParticleEffects.Insert(ParticleManager.GetInstance().PlayOnObject(ParticleList.TERJE_RADIATION_SHOWER_EFFECT, this, GetMemoryPointPos("particle_shower_" + particleIndex)));
			}
		}
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}

	override void EEDelete(EntityAI parent)
	{
		PlayZ_StopHeatBridge();
		super.EEDelete(parent);
		PlayZ_TerjeDestroyVisualEffects();

		if (m_PumpSoundEffect)
		{
			SEffectManager.DestroyEffect(m_PumpSoundEffect);
		}
	}

	override void OnWorkStart()
	{
		super.OnWorkStart();
		m_terjeRadTentTimeout = 0;

		if (g_Game.IsClient())
		{
			PlaySoundSetAtMemoryPointLoopedSafe(m_PumpSoundEffect, "TerjeRadTentPump_SoundSet", "sound_pump", 1, 1);
			PlayZ_TerjeStartClientEffects();
		}
	}

	override void OnWork(float consumed_energy)
	{
		super.OnWork(consumed_energy);
		if (g_Game.IsDedicatedServer())
		{
			if (IsValidTerjeRadTentToWork())
			{
				OnWorkTerjeServerLogic();
			}
			else
			{
				if (HasEnergyManager() && GetCompEM().CanSwitchOff())
				{
					GetCompEM().SwitchOff();
				}
			}
		}
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
		m_terjeRadTentTimeout = 0;
		PlayZ_TerjeDestroyVisualEffects();

		if (m_PumpSoundEffect)
		{
			SEffectManager.DestroyEffect(m_PumpSoundEffect);
			m_PumpSoundEffect = null;
		}
	}

	override void OnWorkTerjeServerLogic()
	{
		ItemBase canister = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("CanisterGasoline")));
		if (!canister || !HasEnergyManager() || !GetCompEM().IsSwitchedOn())
		{
			if (HasEnergyManager() && GetCompEM().CanSwitchOff())
			{
				GetCompEM().SwitchOff();
			}
			return;
		}

		float cleanupForce = ActionWashRadioactiveItems.GetTerjeRadiationCleanupForce(canister);
		if (cleanupForce <= 0 || canister.GetIsFrozen())
		{
			if (GetCompEM().CanSwitchOff())
			{
				GetCompEM().SwitchOff();
			}
			return;
		}

		float consumeAmount = GetTerjeSettingFloat(TerjeSettingsCollection.RADIATION_RADTENT_CONSUME_LIQUID);
		if (consumeAmount > 0)
		{
			canister.AddQuantity(-consumeAmount);
		}

		float cleanupModifier = GetTerjeSettingFloat(TerjeSettingsCollection.RADIATION_RADTENT_EFFICIENCY_MOD);
		float cleanupTotal = cleanupForce * cleanupModifier;
		if (cleanupTotal > 0)
		{
			PluginTerjeScriptableAreas plugin = GetTerjeScriptableAreas();
			if (plugin)
			{
				plugin.TerjeDecontaminateRadioactiveEntitiesInside(this, TERJE_CLEAN_RADIUS, TERJE_SHOWERS_COUNT, cleanupTotal);
			}
		}

		m_terjeRadTentTimeout = m_terjeRadTentTimeout + 1;
		if (m_terjeRadTentTimeout > TERJE_SHOWERS_AUTOSTOP)
		{
			m_terjeRadTentTimeout = 0;
			if (GetCompEM().CanSwitchOff())
			{
				GetCompEM().SwitchOff();
			}
		}

		PlayZ_SnapshotAndScheduleSave();
	}

	override bool CanDisplayAttachmentSlot(int slot_id)
	{
		return true;
	}

	override bool IsInventoryVisible()
	{
		return true;
	}

	override bool CanObstruct()
	{
		return false;
	}

	override bool CanProxyObstruct()
	{
		return false;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!attachment)
		{
			return false;
		}

		if (GetHierarchyRootPlayer())
		{
			return false;
		}

		string slotName = InventorySlots.GetSlotName(slotId);
		if (slotName == "CarBattery")
		{
			if (!CarBattery.Cast(attachment))
			{
				return false;
			}

			return super.CanReceiveAttachment(attachment, slotId);
		}

		if (slotName == "CanisterGasoline")
		{
			return super.CanReceiveAttachment(attachment, slotId);
		}

		return super.CanReceiveAttachment(attachment, slotId);
	}
}
