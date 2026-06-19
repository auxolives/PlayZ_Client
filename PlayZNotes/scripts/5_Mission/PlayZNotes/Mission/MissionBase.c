modded class MissionBase
{
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		UIScriptedMenu menu = super.CreateScriptedMenu(id);
		if (!menu && id == PlayZNotesMenu.NOTE_GUI)
		{
			menu = new PlayZNoteGUI();
		}
		return menu;
	}
}
