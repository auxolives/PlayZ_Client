modded class MissionGameplay
{
	int m_EarPlugsState = 0;

	bool m_EarPlugsSleepingDeafnessLastFrame = false;

	autoptr EarPlugsWidget m_earplugswidget = new EarPlugsWidget();

	override void OnInit()
	{
		super.OnInit();
		DayZGame.Event_OnRPC.Insert(OnPlayZCoreRPC);
	}

	void ~MissionGameplay()
	{
		if (DayZGame.Event_OnRPC)
		{
			DayZGame.Event_OnRPC.Remove(OnPlayZCoreRPC);
		}
	}

	void OnPlayZCoreRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if (rpc_type == PlayZCoreRPCs.SYNC_CORE_CONFIG)
		{
			PlayZCoreConfig.OnRPC(ctx);
		}
	}

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		bool sleepingDeafness = PlayZEarPlugsGate.IsSleepingDeafnessActive();
		if (m_EarPlugsSleepingDeafnessLastFrame && !sleepingDeafness)
		{
			m_EarPlugsState = 0;
		}
		m_EarPlugsSleepingDeafnessLastFrame = sleepingDeafness;

		if (!sleepingDeafness && GetGame().GetInput().LocalPress("UAEarPlugsToggle") && GetGame().GetUIManager().GetMenu() == NULL)
		{
			if (m_EarPlugsState == 0)
			{
				m_EarPlugsState++;
				GetGame().GetSoundScene().SetSoundVolume(0.50, 1);
				m_earplugswidget.SetIcon("PlayZ_Client/PlayZCore/gui/volume_mid.edds");
			}
			else if (m_EarPlugsState == 1)
			{
				m_EarPlugsState++;
				GetGame().GetSoundScene().SetSoundVolume(0.25, 1);
				m_earplugswidget.SetIcon("PlayZ_Client/PlayZCore/gui/volume_low.edds");
			}
			else if (m_EarPlugsState == 2)
			{
				m_EarPlugsState++;
				GetGame().GetSoundScene().SetSoundVolume(0.05, 1);
				m_earplugswidget.SetIcon("PlayZ_Client/PlayZCore/gui/volume_off.edds");
			}
			else if (m_EarPlugsState >= 3)
			{
				m_EarPlugsState = 0;
				GetGame().GetSoundScene().SetSoundVolume(1, 1);
				m_earplugswidget.SetIcon("PlayZ_Client/PlayZCore/gui/volume_full.edds");
			}
		}

		if (GetGame().GetInput().LocalPress("UAEmoteLyingDown") && GetGame().GetUIManager().GetMenu() == NULL)
		{
			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
			if (player && player.GetEmoteManager())
			{
				EmoteManager em = player.GetEmoteManager();
				if (em.CanPlayEmote(EmoteConstants.ID_EMOTE_LYINGDOWN) && !em.IsEmotePlaying())
				{
					em.CreateEmoteCBFromMenu(EmoteConstants.ID_EMOTE_LYINGDOWN);
				}
			}
		}

		if (GetGame().GetInput().LocalPress("UATakeBackpackToHands") && GetGame().GetUIManager().GetMenu() == NULL)
		{
			PlayZ_TryTakeBackpackToHands();
		}

		if (GetGame().GetInput().LocalPress("UATakeMouthBlockerToHands") && GetGame().GetUIManager().GetMenu() == NULL)
		{
			PlayZ_TryToggleMouthBlocker();
		}
	}

	protected void PlayZ_TryToggleMouthBlocker()
	{
		if (!PlayZCoreConfig.GetInstance().EnableMouthBlockerShortcut)
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player)
		{
			return;
		}
		if (!player.IsAlive())
		{
			return;
		}
		if (player.IsUnconscious())
		{
			return;
		}
		if (player.IsRestrained())
		{
			return;
		}
		if (player.GetCommand_Vehicle())
		{
			return;
		}
		if (player.IsEmotePlaying())
		{
			return;
		}

		EntityAI head = player.FindAttachmentBySlotName("Headgear");
		if (head && head.IsInherited(BurlapSackCover))
		{
			return;
		}

		EntityAI inHands = player.GetItemInHands();

		if (inHands && PlayZ_IsKnownBlockerInHands(inHands))
		{
			PlayZ_TryPutBackMouthBlocker(player, inHands);
			return;
		}

		if (head)
		{
			if (head.IsInherited(DirtBikeHelmet_ColorBase))
			{
				EntityAI mouthguard = head.FindAttachmentBySlotName(PlayZMouthBlocker.DIRTBIKE_MOUTHGUARD_SLOT);
				if (mouthguard)
				{
					PlayZ_SwapOrTakeToHands(player, mouthguard);
					return;
				}
			}
			else if (PlayZMouthBlocker.IsHeadBlocker(head))
			{
				PlayZ_SwapOrTakeToHands(player, head);
				return;
			}
		}

		EntityAI mask = player.FindAttachmentBySlotName("Mask");
		if (PlayZMouthBlocker.IsMaskBlocker(mask))
		{
			PlayZ_SwapOrTakeToHands(player, mask);
			return;
		}
	}

	protected bool PlayZ_IsKnownBlockerInHands(EntityAI item)
	{
		if (!item)
		{
			return false;
		}
		if (item.IsInherited(DirtBikeHelmet_Mouthguard))
		{
			return true;
		}
		if (PlayZMouthBlocker.IsHeadBlocker(item))
		{
			return true;
		}
		if (item.IsInherited(DirtBikeHelmet_ColorBase))
		{
			return true;
		}
		if (PlayZMouthBlocker.IsMaskBlocker(item))
		{
			return true;
		}
		return false;
	}

	protected void PlayZ_TryPutBackMouthBlocker(PlayerBase player, EntityAI inHands)
	{
		if (inHands.IsInherited(DirtBikeHelmet_Mouthguard))
		{
			EntityAI helmet = player.FindAttachmentBySlotName("Headgear");
			if (!helmet || !helmet.IsInherited(DirtBikeHelmet_ColorBase))
			{
				return;
			}
			if (helmet.FindAttachmentBySlotName(PlayZMouthBlocker.DIRTBIKE_MOUTHGUARD_SLOT))
			{
				return;
			}
			int dbSlotId = InventorySlots.GetSlotIdFromString(PlayZMouthBlocker.DIRTBIKE_MOUTHGUARD_SLOT);
			if (dbSlotId == InventorySlots.INVALID)
			{
				return;
			}
			player.PredictiveTakeEntityToTargetAttachmentEx(helmet, inHands, dbSlotId);
			return;
		}

		if (PlayZMouthBlocker.IsMaskBlocker(inHands))
		{
			if (player.FindAttachmentBySlotName("Mask"))
			{
				return;
			}
			player.PredictiveTakeEntityToTargetAttachmentEx(player, inHands, InventorySlots.MASK);
			return;
		}

		if (PlayZMouthBlocker.IsHeadBlocker(inHands) || inHands.IsInherited(DirtBikeHelmet_ColorBase))
		{
			if (player.FindAttachmentBySlotName("Headgear"))
			{
				return;
			}
			player.PredictiveTakeEntityToTargetAttachmentEx(player, inHands, InventorySlots.HEADGEAR);
			return;
		}
	}

	protected void PlayZ_TryTakeBackpackToHands()
	{
		if (!PlayZCoreConfig.GetInstance().EnableTakeBackpackFromBack)
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player)
		{
			return;
		}
		if (!player.IsAlive())
		{
			return;
		}
		if (player.IsUnconscious())
		{
			return;
		}
		if (player.IsRestrained())
		{
			return;
		}
		if (player.GetCommand_Vehicle())
		{
			return;
		}
		if (player.IsEmotePlaying())
		{
			return;
		}

		Backpack_Base bagInHands = Backpack_Base.Cast(player.GetItemInHands());
		if (bagInHands)
		{
			if (player.FindAttachmentBySlotName("Back"))
			{
				return;
			}
			player.PredictiveTakeEntityToTargetAttachmentEx(player, bagInHands, InventorySlots.BACK);
			return;
		}

		EntityAI backpack = player.FindAttachmentBySlotName("Back");
		if (!backpack)
		{
			return;
		}

		PlayZ_SwapOrTakeToHands(player, backpack);
	}

	protected void PlayZ_SwapOrTakeToHands(PlayerBase player, EntityAI newItem)
	{
		if (!newItem)
		{
			return;
		}

		InventoryLocation newItemOrigin = new InventoryLocation;
		if (newItem.GetInventory().GetCurrentInventoryLocation(newItemOrigin))
		{
			player.GetHumanInventory().SetUserReservedLocation(newItem, newItemOrigin);
		}

		EntityAI inHands = player.GetItemInHands();
		if (!inHands)
		{
			player.PredictiveTakeEntityToHands(newItem);
			return;
		}
		if (inHands == newItem)
		{
			return;
		}

		InventoryLocation handsLoc = new InventoryLocation;
		handsLoc.SetHands(player, newItem);

		InventoryLocation inHandsFSwapDst = new InventoryLocation;
		int rIdx = player.GetHumanInventory().FindUserReservedLocationIndex(inHands);
		if (rIdx >= 0)
		{
			player.GetHumanInventory().GetUserReservedLocation(rIdx, inHandsFSwapDst);
		}

		if (rIdx < 0 && GameInventory.CanSwapEntitiesEx(newItem, inHands))
		{
			player.PredictiveSwapEntities(newItem, inHands);
			return;
		}

		if (GameInventory.CanForceSwapEntitiesEx(newItem, handsLoc, inHands, inHandsFSwapDst))
		{
			player.PredictiveForceSwapEntities(newItem, inHands, inHandsFSwapDst);
			return;
		}
	}
}
