modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		PlayZSakhalManager.GetSakhal();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		PlayZSakhalManager.SyncSakhal(identity);
	}
}
