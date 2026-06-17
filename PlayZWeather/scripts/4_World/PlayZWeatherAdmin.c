class PlayZWeatherAdmin
{
	static bool ApplyScenarioByName(string name)
	{
		PlayZWeatherDebug.Log("PlayZWeatherAdmin.ApplyScenarioByName: " + name);

		if (!GetGame().IsServer())
		{
			PlayZWeatherDebug.Log("PlayZWeatherAdmin: not server");
			return false;
		}

		Mission mission = GetGame().GetMission();
		if (!mission)
		{
			PlayZWeatherDebug.Log("PlayZWeatherAdmin: mission is null");
			return false;
		}

		WorldData worldData = mission.GetWorldData();
		if (!worldData)
		{
			PlayZWeatherDebug.Log("PlayZWeatherAdmin: WorldData is null");
			return false;
		}

		SakhalData sakhalData = SakhalData.Cast(worldData);
		if (!sakhalData)
		{
			PlayZWeatherDebug.Log("PlayZWeatherAdmin: WorldData is not SakhalData");
			return false;
		}

		return sakhalData.ForceScenarioByName(name);
	}
}
