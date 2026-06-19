class ActionPlayZWritePaperCB : ActionContinuousBaseCB {}

class ActionPlayZWritePaper : ActionContinuousBase
{
	void ActionPlayZWritePaper()
	{
		m_CallbackClass = ActionPlayZWritePaperCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWNOTE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
		m_Text = "#write_note";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined(1.2);
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!item || !target.GetObject())
		{
			return false;
		}

		if (item.IsInherited(PlayZNote) || target.GetObject().IsInherited(PlayZNote))
		{
			return false;
		}

		if ((item.ConfigIsExisting("penColor") && Paper.Cast(target.GetObject())) || (target.GetObject().ConfigIsExisting("penColor") && Paper.Cast(item)))
		{
			return true;
		}

		return false;
	}

	override void OnStartClient(ActionData action_data)
	{
		PlayZNoteGUI gui = PlayZNoteGUI.Cast(GetGame().GetUIManager().EnterScriptedMenu(PlayZNotesMenu.NOTE_GUI, NULL));
		if (!gui)
		{
			return;
		}

		Paper paper = Paper.Cast(action_data.m_MainItem);
		if (!paper)
		{
			paper = Paper.Cast(action_data.m_Target.GetObject());
		}

		Pen_ColorBase pen = Pen_ColorBase.Cast(action_data.m_MainItem);
		if (!pen)
		{
			pen = Pen_ColorBase.Cast(action_data.m_Target.GetObject());
		}

		gui.SetPaper(paper);
		gui.SetReadOnly(false);
		gui.SetPenColour(GetPenColour(pen));
	}

	override void OnStartServer(ActionData action_data)
	{
		Paper paper = Paper.Cast(action_data.m_MainItem);
		if (!paper)
		{
			paper = Paper.Cast(action_data.m_Target.GetObject());
		}

		Pen_ColorBase pen = Pen_ColorBase.Cast(action_data.m_MainItem);
		if (!pen)
		{
			pen = Pen_ColorBase.Cast(action_data.m_Target.GetObject());
		}

		if (!paper || !pen)
		{
			return;
		}

		PlayZNotesConfig cfg = PlayZNotesConfig.Get();
		if (cfg.PenConsumeQuantity > 0)
		{
			paper.SetPlayZPen(pen);
		}

		if (!cfg.NoteDateFormat || cfg.NoteDateFormat.Format == 0)
		{
			return;
		}

		Param1<string> data = new Param1<string>(cfg.GetDate());
		paper.RPCSingleParam(PlayZNotesRPCs.RECEIVE_NOTE_DATE, data, true, action_data.m_Player.GetIdentity());
	}

	static int GetPenColour(Pen_ColorBase pen)
	{
		if (!pen)
		{
			return ARGB(255, 10, 10, 10);
		}

		TIntArray rgbArray = new TIntArray();
		pen.ConfigGetIntArray("penColor", rgbArray);
		if (rgbArray.Count() < 3)
		{
			return ARGB(255, 10, 10, 10);
		}

		return ARGB(255, rgbArray.Get(0), rgbArray.Get(1), rgbArray.Get(2));
	}
}
