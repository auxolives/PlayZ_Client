modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();

		if (GetGame().IsServer())
		{
			DayZGame.Event_OnRPC.Insert(OnPlayZCOTWeatherServerRPC);
			PlayZWeatherDebug.Log("MissionServer: registered APPLY_SCENARIO RPC handler");
		}
	}

	void ~MissionServer()
	{
		if (DayZGame.Event_OnRPC)
		{
			DayZGame.Event_OnRPC.Remove(OnPlayZCOTWeatherServerRPC);
		}
	}

	void OnPlayZCOTWeatherServerRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if (!GetGame().IsServer())
			return;

		if (rpc_type != PlayZRPCs.APPLY_SCENARIO)
			return;

		PlayZWeatherDebug.Log("MissionServer.OnPlayZCOTWeatherServerRPC: APPLY_SCENARIO received");

		string scenarioName;
		if (!ctx.Read(scenarioName))
		{
			PlayZWeatherDebug.Log("MissionServer.OnPlayZCOTWeatherServerRPC: ctx.Read failed");
			return;
		}

		PlayZWeatherDebug.Log("MissionServer.OnPlayZCOTWeatherServerRPC: scenario=" + scenarioName);

		if (!GetPermissionsManager().HasPermission("Weather.Scenario", sender))
		{
			PlayZWeatherDebug.Log("MissionServer.OnPlayZCOTWeatherServerRPC: Weather.Scenario denied");
			return;
		}

		if (!PlayZWeatherAdmin.ApplyScenarioByName(scenarioName))
		{
			if (sender)
			{
				GetCommunityOnlineToolsBase().Log(sender, "Failed to apply PlayZ Weather Scenario " + scenarioName);
			}
			PlayZWeatherDebug.Log("MissionServer.OnPlayZCOTWeatherServerRPC: ApplyScenarioByName failed");
			return;
		}

		if (sender)
		{
			GetCommunityOnlineToolsBase().Log(sender, "Applied PlayZ Weather Scenario " + scenarioName);
		}
		PlayZWeatherDebug.Log("MissionServer.OnPlayZCOTWeatherServerRPC: success");
	}
}
