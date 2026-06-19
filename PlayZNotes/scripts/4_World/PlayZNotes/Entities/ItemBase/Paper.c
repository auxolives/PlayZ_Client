modded class Paper
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionPlayZWritePaper);
	}

	private int m_PlayZNotePickupTries = 0;
	Pen_ColorBase m_PlayZPen;

	void SetPlayZPen(Pen_ColorBase pen)
	{
		m_PlayZPen = pen;
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == PlayZNotesRPCs.RECEIVE_NOTE_DATE)
		{
			Param1<string> dataFromServer;
			if (ctx.Read(dataFromServer))
			{
				PlayZNoteGUI.DATE_TEXT = dataFromServer.param1;
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(UpdatePlayZNoteGUI, 50, false);
			}
			return;
		}

		if (rpc_type != PlayZNotesRPCs.SEND_WRITTEN_NOTE)
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(sender.GetPlayer());
		if (!player || !sender)
		{
			return;
		}

		Param1<ref PlayZNoteData> dataFromClient;
		if (!ctx.Read(dataFromClient) || !dataFromClient.param1)
		{
			return;
		}

		PlayZNotesConfig cfg = PlayZNotesConfig.Get();
		string validationErr;
		if (!cfg.ValidateNoteText(dataFromClient.param1.m_NoteText, validationErr))
		{
			return;
		}

		if (!IsPlayZPaperAccessibleToPlayer(player))
		{
			return;
		}

		PlayZNoteData noteData = new PlayZNoteData();
		noteData.m_FontIndex = 0;
		noteData.m_DateText = dataFromClient.param1.m_DateText;
		noteData.m_NoteText = dataFromClient.param1.m_NoteText;
		noteData.m_ARGBColour = dataFromClient.param1.m_ARGBColour;

		if (GetQuantity() == 1)
		{
			PlayZReplacePaperWithNoteLambda lambda = new PlayZReplacePaperWithNoteLambda(this, "PlayZNote", noteData);
			if (player.GetItemInHands() == this)
			{
				player.ServerReplaceItemInHandsWithNew(lambda);
			}
			else
			{
				player.ServerReplaceItemWithNew(lambda);
			}
		}
		else
		{
			SetQuantity(GetQuantity() - 1);

			PlayZNote noteGround = PlayZNote.Cast(GetGame().CreateObjectEx("PlayZNote", GetPosition(), ECE_PLACE_ON_SURFACE));
			if (!noteGround)
			{
				return;
			}

			noteGround.SetNoteData(noteData);
			MiscGameplayFunctions.TransferItemProperties(this, noteGround);

			if (player.GetItemInHands() == this)
			{
				HumanInventory inventory = player.GetHumanInventory();
				if (inventory)
				{
					InventoryLocation locDst = new InventoryLocation();
					int reservedIndex = inventory.FindUserReservedLocationIndex(this);
					inventory.GetUserReservedLocation(reservedIndex, locDst);

					InventoryLocation locSrc = new InventoryLocation();
					GetInventory().GetCurrentInventoryLocation(locSrc);

					if (reservedIndex == -1 || !player.ServerTakeToDst(locSrc, locDst))
					{
						player.ServerTakeEntityToInventory(FindInventoryLocationType.ANY_CARGO, this);
					}
				}

				m_PlayZNotePickupTries = 0;
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(TakePlayZNoteToHands, 200, true, player, noteGround);
			}
		}

		if (cfg.PenConsumeQuantity > 0 && m_PlayZPen)
		{
			m_PlayZPen.SetQuantity(m_PlayZPen.GetQuantity() - cfg.PenConsumeQuantity);
		}

		vector logPos = GetPosition();
		string logPlayerId = sender.GetId();
		string logPlayerName = player.GetCachedName();
		PlayZNotesLogBridge.LogNoteWritten(logPlayerId, logPlayerName, noteData.m_NoteText, logPos);
	}

	bool IsPlayZPaperAccessibleToPlayer(PlayerBase player)
	{
		if (!player)
		{
			return false;
		}

		if (player.GetItemInHands() == this)
		{
			return true;
		}

		EntityAI root = player.GetHierarchyRoot();
		if (root && GetHierarchyRoot() == root)
		{
			return true;
		}

		if (vector.DistanceSq(player.GetPosition(), GetPosition()) <= 4.0)
		{
			return true;
		}

		return false;
	}

	private void TakePlayZNoteToHands(PlayerBase player, EntityAI item)
	{
		if (item && player && player.IsAlive() && !player.IsUnconscious() && !player.IsPlayerDisconnected())
		{
			InventoryLocation locSrc = new InventoryLocation();
			item.GetInventory().GetCurrentInventoryLocation(locSrc);

			InventoryLocation locDst = new InventoryLocation();
			locDst.Copy(locSrc);
			locDst.SetHands(player, item);

			player.ServerTakeToDst(locSrc, locDst);

			m_PlayZNotePickupTries++;
			if (m_PlayZNotePickupTries >= 5)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(TakePlayZNoteToHands);
			}
		}
		else
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(TakePlayZNoteToHands);
		}
	}

	void UpdatePlayZNoteGUI()
	{
		UIScriptedMenu menu = GetGame().GetUIManager().GetMenu();
		if (!menu)
		{
			return;
		}

		PlayZNoteGUI noteMenu = PlayZNoteGUI.Cast(menu);
		if (noteMenu)
		{
			noteMenu.SetDate();
		}
	}
}

class PlayZReplacePaperWithNoteLambda extends ReplaceItemWithNewLambdaBase
{
	ref PlayZNoteData m_NoteData;

	void PlayZReplacePaperWithNoteLambda(EntityAI old_item, string new_item_type, PlayZNoteData data)
	{
		m_NoteData = data;
	}

	override void CopyOldPropertiesToNew(notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);

		PlayZNote note = PlayZNote.Cast(new_item);
		if (!note)
		{
			return;
		}

		note.SetNoteData(m_NoteData);
		MiscGameplayFunctions.TransferItemProperties(old_item, note);

		if (!note.GetParent())
		{
			note.SetOrientation(old_item.GetOrientation());
			note.SetPosition(old_item.GetPosition());
		}
	}
}
