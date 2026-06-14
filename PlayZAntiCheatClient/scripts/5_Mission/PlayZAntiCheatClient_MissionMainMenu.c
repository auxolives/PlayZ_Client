modded class MissionMainMenu
{
	override void OnMissionStart()
	{
		super.OnMissionStart();

		if (!GetGame() || GetGame().IsDedicatedServer())
			return;

		if (!PlayZACDeferredKickMessage.HasMessage())
			return;

		string reason = PlayZACDeferredKickMessage.GetAndClear();
		string body = "#STR_MP_KICKED_CLIENT\n" + reason;
		UIManager ui = GetGame().GetUIManager();
		ui.ShowDialog("#menu_warning", body, 1, DBT_OK, DBB_OK, DMT_WARNING, ui.GetMenu());
	}
}
