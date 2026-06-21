modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		PlayZOverdoseConfig.GetInstance();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		PlayZOverdoseConfig.SyncConfig(identity);
	}
}
