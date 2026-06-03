modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();

		// Force initialization of GunPlay config on server start
		// This ensures GunPlay.json is created in the profile folder immediately
		PlayZGunPlayManager.GetGunPlay();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		// Sync GunPlay config to the joining player
		PlayZGunPlayManager.SyncGunPlay(identity);
	}
}
