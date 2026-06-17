class PlayZWeatherDebug
{
	static void Log(string msg)
	{
		if (!PlayZConfig.GetWeather().m_DebugCycleScenarios)
			return;

		Print("[PlayZWeatherDBG] " + msg);
	}
}
