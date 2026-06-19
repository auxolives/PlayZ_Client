class ActionPlayZReadNoteHandsCB : ActionContinuousBaseCB {}

class ActionPlayZReadNoteHands : ActionContinuousBase
{
	void ActionPlayZReadNoteHands()
	{
		m_CallbackClass = ActionPlayZReadNoteHandsCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWNOTE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
		m_Text = "#read";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		#ifdef SERVER
		return true;
		#endif

		if (target.GetObject())
		{
			return false;
		}

		return item && item.IsInherited(PlayZNote) && !player.IsPlacingLocal();
	}

	override void OnStartServer(ActionData action_data)
	{
		PlayZNote note = PlayZNote.Cast(action_data.m_MainItem);
		if (!note)
		{
			return;
		}

		Param1<ref PlayZNoteData> data = new Param1<ref PlayZNoteData>(note.GetNoteData());
		note.RPCSingleParam(PlayZNotesRPCs.RECEIVE_WRITTEN_NOTE, data, true, action_data.m_Player.GetIdentity());
		note.IncreaseLifetime();
	}
}
