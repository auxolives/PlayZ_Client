modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		PlayZNotesConfig.Get();
	}

	override void OnMissionFinish()
	{
		super.OnMissionFinish();

		PlayZNotesConfig cfg = PlayZNotesConfig.Get();
		if (cfg && cfg.DeleteAllNotes)
		{
			cfg.DeleteAllNotes = false;
			cfg.Save();
		}
	}
}
