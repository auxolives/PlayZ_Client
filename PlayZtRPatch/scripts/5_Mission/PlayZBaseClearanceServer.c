modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		PlayZBaseClearance_OnServerInit();
	}

	protected void PlayZBaseClearance_OnServerInit()
	{
		PlayZBaseClearanceManager.Get().Load();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayZBaseClearance_Reapply, 3000, false);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayZBaseClearance_CleanupOrphans, 60000, false);
	}

	protected void PlayZBaseClearance_Reapply()
	{
		PlayZBaseClearanceManager.Get().ReapplySavedSuppressions();
	}

	protected void PlayZBaseClearance_CleanupOrphans()
	{
		PlayZBaseClearanceManager.Get().CleanupOrphans();
		PlayZBaseClearanceManager.Get().FlushSave();
	}
}
