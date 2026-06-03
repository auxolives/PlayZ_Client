modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();

		// Force initialization of configurations on server start
		// This ensures JSON files are created in the profile folder immediately
		PlayZConfig.GetWeather();
		PlayZConfig.GetPPE();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		// Sync PlayZ configurations to the joining player
		PlayZConfig.SyncConfig(identity);
	}
}
