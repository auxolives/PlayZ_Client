modded class Weapon_Base
{
	override bool CanDisplayAttachmentSlot(int slot_id)
	{
		int slotMp5 = InventorySlots.GetSlotIdFromString("weaponMuzzleMP5");
		if (slot_id == slotMp5)
		{
			MP5K_Base mp5k;
			if (Class.CastTo(mp5k, this))
				return super.CanDisplayAttachmentSlot(slot_id);
			return false;
		}

		int slotPistol = InventorySlots.GetSlotIdFromString("pistolMuzzle");
		int slotImpro = InventorySlots.GetSlotIdFromString("suppressorImpro");
		int slotAk = InventorySlots.GetSlotIdFromString("weaponMuzzleAK");
		int slotM4 = InventorySlots.GetSlotIdFromString("weaponMuzzleM4");
		int slotMosin = InventorySlots.GetSlotIdFromString("weaponMuzzleMosin");
		if (slot_id == slotMosin)
		{
			Mosin9130_Base mosin;
			if (Class.CastTo(mosin, this))
				return super.CanDisplayAttachmentSlot(slot_id);
			return false;
		}

		if (slot_id == slotPistol)
			return false;
		if (slot_id == slotImpro)
			return false;
		if (slot_id == slotAk)
			return false;
		if (slot_id == slotM4)
			return false;
		return super.CanDisplayAttachmentSlot(slot_id);
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;

		if (attachment && attachment.IsInherited(MP5_Compensator))
			return true;
		if (attachment && attachment.IsInherited(Mosin_Compensator))
			return true;

		ItemSuppressor sup;
		if (!Class.CastTo(sup, attachment))
			return true;

		int slotPistol = InventorySlots.GetSlotIdFromString("pistolMuzzle");
		int slotImpro = InventorySlots.GetSlotIdFromString("suppressorImpro");
		int slotMuzzle = InventorySlots.GetSlotIdFromString("weaponMuzzle");
		int slotAk = InventorySlots.GetSlotIdFromString("weaponMuzzleAK");
		int slotM4 = InventorySlots.GetSlotIdFromString("weaponMuzzleM4");
		int slotMp5 = InventorySlots.GetSlotIdFromString("weaponMuzzleMP5");
		int slotMosin = InventorySlots.GetSlotIdFromString("weaponMuzzleMosin");
		if (slotId == slotPistol)
			return false;
		if (slotId == slotImpro)
			return false;
		if (slotId == slotMuzzle)
			return false;
		if (slotId == slotAk)
			return false;
		if (slotId == slotM4)
			return false;
		if (slotId == slotMp5)
			return false;
		if (slotId == slotMosin)
			return false;
		return true;
	}

	bool m_PlayZPauseCombatRPC = false;
	static const float PLAYZ_ACL_RPC_DELAY_MS = 3000;

	float GetAntiCombatLogWeaponDistance()
	{
		return 250;
	}

	override void OnFire(int muzzle_index)
	{
		super.OnFire(muzzle_index);

		if (g_Game.IsServer())
		{
			if (PlayZAntiCombatLogConfig.Get().TriggerOnGunshot)
			{
				PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
				if (player)
				{
					player.SetCombatLogTimer(player, null);
				}
			}
			return;
		}

		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayZ_DetectPlayerShot, 1, false);
	}

	private void PlayZ_DetectPlayerShot()
	{
		if (m_PlayZPauseCombatRPC)
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (!player || !player.IsControlledPlayer())
		{
			return;
		}

		float distance = GetAntiCombatLogWeaponDistance();
		vector start;
		vector direction;

		if (player.GetInputController().CameraIsFreeLook())
		{
			if (player.m_DirectionToCursor != vector.Zero)
			{
				direction = player.m_DirectionToCursor;
			}
			else
			{
				direction = MiscGameplayFunctions.GetHeadingVector(player);
			}
		}
		else
		{
			direction = GetGame().GetCurrentCameraDirection();
		}

		int idx = player.GetBoneIndexByName("Neck");
		if (idx == -1)
		{
			start = player.GetPosition()[1] + 1.5;
		}
		else
		{
			start = player.GetBonePositionWS(idx);
		}

		vector end = start + (direction * distance);
		float raycastRadius = 5.0;
		RaycastRVParams rayInput = new RaycastRVParams(start, end, player, raycastRadius);
		rayInput.flags = CollisionFlags.ALLOBJECTS;
		array<ref RaycastRVResult> results = new array<ref RaycastRVResult>;
		array<PlayerBase> informedPlayers = new array<PlayerBase>;

		if (DayZPhysics.RaycastRVProxy(rayInput, results))
		{
			if (results.Count() > 0)
			{
				bool skip = false;
				bool sentRPC = false;
				int i;
				int resultCount = results.Count();
				for (i = 0; i < resultCount; i++)
				{
					RaycastRVResult res = results.Get(i);
					if ((results[i].obj && !results[i].obj.IsMan()) && (!res.parent || !res.parent.IsMan()))
					{
						continue;
					}

					PlayerBase otherPlayer = PlayerBase.Cast(results[i].obj);
					if (!otherPlayer && res.parent && res.parent.IsMan())
					{
						otherPlayer = PlayerBase.Cast(res.parent);
					}

					if (otherPlayer)
					{
						if (otherPlayer.IsControlledPlayer())
						{
							continue;
						}

						skip = false;
						int x;
						int informedCount = informedPlayers.Count();
						for (x = 0; x < informedCount; x++)
						{
							if (informedPlayers.Get(x) == otherPlayer)
							{
								skip = true;
							}
						}

						if (!skip)
						{
							player.InformServerThatWeShotAt(otherPlayer);
							informedPlayers.Insert(otherPlayer);
							sentRPC = true;
						}
					}
				}

				if (sentRPC)
				{
					m_PlayZPauseCombatRPC = true;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlayZ_ResetCombatRPC, PLAYZ_ACL_RPC_DELAY_MS, false);
				}
			}
		}
	}

	private void PlayZ_ResetCombatRPC()
	{
		m_PlayZPauseCombatRPC = false;
	}

	void ~Weapon_Base()
	{
		if (GetGame() && GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM))
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(PlayZ_ResetCombatRPC);
		}
	}
}
