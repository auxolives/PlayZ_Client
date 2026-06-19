modded class PlayerBase
{
	override void OnUnconsciousStart()
	{
		super.OnUnconsciousStart();

		#ifndef SERVER
		UIScriptedMenu menu = GetGame().GetUIManager().GetMenu();
		if (!menu)
		{
			return;
		}

		PlayZNoteGUI noteMenu = PlayZNoteGUI.Cast(menu);
		if (noteMenu)
		{
			noteMenu.OnExitBtnClick();
		}
		#endif
	}
}
