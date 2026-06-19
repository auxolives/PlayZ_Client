class ActionPlayZReadNoteTarget : ActionInteractBase
{
	void ActionPlayZReadNoteTarget()
	{
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		m_Text = "#read";
	}

	override string GetText()
	{
		return "#read";
	}

	override bool IsInstant()
	{
		return true;
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (target && target.GetObject().IsInherited(PlayZNote))
		{
			return !player.IsPlacingLocal();
		}

		return false;
	}

	override void OnStartServer(ActionData action_data)
	{
		PlayZNote note = PlayZNote.Cast(action_data.m_Target.GetObject());
		if (!note)
		{
			return;
		}

		Param1<ref PlayZNoteData> data = new Param1<ref PlayZNoteData>(note.GetNoteData());
		note.RPCSingleParam(PlayZNotesRPCs.RECEIVE_WRITTEN_NOTE, data, true, action_data.m_Player.GetIdentity());
		note.IncreaseLifetime();
	}
}
