modded class JMWeatherModule
{
	void JMWeatherModule()
	{
		GetPermissionsManager().RegisterPermission("Weather.Scenario");
	}

	void SetPlayZScenario(string name)
	{
		if (g_Game.IsServer())
			PlayZWeatherDebug.Log("JMWeatherModule.SetPlayZScenario: " + name + " (server)");
		else
			PlayZWeatherDebug.Log("JMWeatherModule.SetPlayZScenario: " + name + " (client)");

		if (name == "")
		{
			PlayZWeatherDebug.Log("JMWeatherModule.SetPlayZScenario: aborted, empty name");
			return;
		}

		if (g_Game.IsServer())
		{
			Exec_SetPlayZScenario(name, NULL);
		}
		else
		{
			Send_SetPlayZScenario(name);
		}
	}

	private void Send_SetPlayZScenario(string name)
	{
		PlayZWeatherDebug.Log("JMWeatherModule.Send_SetPlayZScenario: rpc=" + PlayZRPCs.APPLY_SCENARIO + " name=" + name);

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(name);
		rpc.Send(NULL, PlayZRPCs.APPLY_SCENARIO, true, NULL);
	}

	private void Exec_SetPlayZScenario(string name, PlayerIdentity ident)
	{
		PlayZWeatherDebug.Log("JMWeatherModule.Exec_SetPlayZScenario: " + name);

		if (!PlayZWeatherAdmin.ApplyScenarioByName(name))
		{
			if (ident)
			{
				GetCommunityOnlineToolsBase().Log(ident, "Failed to apply PlayZ Weather Scenario " + name);
			}
			PlayZWeatherDebug.Log("JMWeatherModule.Exec_SetPlayZScenario: ApplyScenarioByName failed");
			return;
		}

		if (ident)
		{
			GetCommunityOnlineToolsBase().Log(ident, "Applied PlayZ Weather Scenario " + name);
		}
		PlayZWeatherDebug.Log("JMWeatherModule.Exec_SetPlayZScenario: success");
	}
}
