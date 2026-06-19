class PlayZNote extends Paper
{
	protected ref PlayZNoteData m_PlayZNoteData;

	override void DeferredInit()
	{
		super.DeferredInit();

		if (GetGame().IsDedicatedServer())
		{
			PlayZNotesConfig cfg = PlayZNotesConfig.Get();
			if (cfg && cfg.DeleteAllNotes)
			{
				DeleteSafe();
			}
		}
	}

	override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionTakeItem);
		RemoveAction(ActionAttach);

		AddAction(ActionPlayZReadNoteHands);
		AddAction(ActionPlayZReadNoteTarget);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type != PlayZNotesRPCs.RECEIVE_WRITTEN_NOTE)
		{
			return;
		}

		Param1<ref PlayZNoteData> params = new Param1<ref PlayZNoteData>(m_PlayZNoteData);
		if (!ctx.Read(params) || !params.param1)
		{
			return;
		}

		SetNoteData(params.param1);

		if (!GetGame().GetUIManager())
		{
			return;
		}

		PlayZNoteGUI gui = PlayZNoteGUI.Cast(GetGame().GetUIManager().EnterScriptedMenu(PlayZNotesMenu.NOTE_GUI, GetGame().GetUIManager().GetMenu()));
		if (gui)
		{
			gui.SetPaper(this);
			gui.SetNoteData(m_PlayZNoteData);
			gui.SetReadOnly(true);
		}
	}

	PlayZNoteData GetNoteData()
	{
		return m_PlayZNoteData;
	}

	void SetNoteData(PlayZNoteData data)
	{
		m_PlayZNoteData = data;
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version))
		{
			return false;
		}

		if (!ctx.Read(m_PlayZNoteData))
		{
			return false;
		}

		return true;
	}

	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		ctx.Write(m_PlayZNoteData);
	}
}
