modded class MissionGameplay
{
	override void OnKeyPress(int key)
	{
		super.OnKeyPress(key);

		if (key != KeyCode.KC_ESCAPE)
		{
			return;
		}

		UIScriptedMenu menu = m_UIManager.GetMenu();
		if (!menu)
		{
			return;
		}

		PlayZNoteGUI noteMenu = PlayZNoteGUI.Cast(menu);
		if (noteMenu)
		{
			noteMenu.OnExitBtnClick();
		}
	}
}
