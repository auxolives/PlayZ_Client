modded class MissionServer
{
	override void OnInit()
	{
		PlayZRadTentStaticPersistence.Load();
		super.OnInit();
		PlayZRadiationManager.GetRadiation();
	}

	override void OnMissionFinish()
	{
		PlayZRadTentStaticPersistence.Shutdown();
		super.OnMissionFinish();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		PlayZRadiationManager.SyncRadiation(identity);
	}
}
