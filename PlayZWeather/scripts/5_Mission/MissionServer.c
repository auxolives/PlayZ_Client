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

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		if (!GetGame().IsServer())
		{
			return;
		}

		Weather weather = GetGame().GetWeather();
		if (!weather)
		{
			return;
		}

		float targetWeight = PlayZWeatherPPE.GetScenarioTintWeight(weather);
		float interp = PlayZConfig.GetPPE().m_WeatherFadeSpeed * timeslice;
		if (PlayZConfig.GetWeather().m_DebugCycleScenarios)
		{
			interp = 2.0 * timeslice;
		}
		PlayZConfig.m_ServerScenarioTintWeight = Math.Lerp(PlayZConfig.m_ServerScenarioTintWeight, targetWeight, interp);
		PlayZWeatherPPE.TryCompleteScenarioEventTintFadeOut();
	}
}
