class PlayZWeatherConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/Weather.json";

	bool m_EnablePlayZWeather = true;
	bool m_DebugCycleScenarios = false;
	ref array<ref PlayZWeatherScenario> m_Scenarios = new array<ref PlayZWeatherScenario>();

	void PlayZWeatherConfig()
	{
		// Default scenarios if nothing is loaded
	}

	void Load()
	{
		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZWeatherConfig>.JsonLoadFile(CONFIG_PATH, this);
		}
		else
		{
			SetDefaults();
			Save();
		}
	}

	void Save()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}
		JsonFileLoader<PlayZWeatherConfig>.JsonSaveFile(CONFIG_PATH, this);
	}

	void SetDefaults()
	{
		m_Scenarios.Clear();
		// PlayZWeatherScenario(name, weight, overcast/rain/wind/volfog min-max pairs, duration min-max)
		m_Scenarios.Insert(new PlayZWeatherScenario("Heatwave", 4.0, 0.0, 0.1, 0.0, 0.0, 0.0, 2.0, 0.0, 0.00, 1.0, 1.0, 0.0, 0.0, 600, 900));
		m_Scenarios.Insert(new PlayZWeatherScenario("Clear", 14.0, 0.0, 0.2, 0.0, 0.0, 0.0, 2.0, 0.0, 0.2, 0.0, 0.2, 0.0, 0.0, 600, 900));
		m_Scenarios.Insert(new PlayZWeatherScenario("Coldwave", 4.0, 0.1, 0.3, 0.0, 0.0, 14.0, 18.0, 0.0, 0.3, 0.0, 0.3, 0.0, 0.0, 600, 900));
		m_Scenarios.Insert(new PlayZWeatherScenario("Partly Cloudy", 22.0, 0.3, 0.5, 0.0, 0.0, 2.0, 5.0, 0.0, 0.1, 0.0, 0.1, 0.0, 0.0, 600, 900));
		m_Scenarios.Insert(new PlayZWeatherScenario("Very Cloudy", 15.0, 0.6, 0.8, 0.0, 0.0, 4.0, 7.0, 0.0, 0.01, 1.0, 1.0, 0.0, 0.0, 600, 900));
		m_Scenarios.Insert(new PlayZWeatherScenario("Light Falls", 10.0, 0.7, 0.9, 0.1, 0.3, 2.0, 6.0, 0.02, 0.05, 1.0, 1.0, 0.0, 0.0, 600, 900));
		m_Scenarios.Insert(new PlayZWeatherScenario("Heavy Falls", 8.0, 0.9, 1.0, 0.8, 1.0, 10.0, 15.0, 0.07, 0.10, 1.0, 1.0, 0.0, 0.0, 600, 900));
		m_Scenarios.Insert(new PlayZWeatherScenario("Heavy Fog", 8.0, 0.4, 0.7, 0.0, 0.0, 0.0, 2.0, 0.30, 0.70, 1.0, 1.0, 0.0, 0.0, 600, 900));
		m_Scenarios.Insert(new PlayZWeatherScenario("Gale", 3.0, 0.1, 0.3, 0.0, 0.0, 15.0, 20.0, 0.00, 0.00, 1.0, 1.0, 0.0, 0.0, 600, 900));
		m_Scenarios.Insert(new PlayZWeatherScenario("Squall", 7.0, 0.9, 1.0, 0.5, 0.9, 12.0, 18.0, 0.30, 0.60, 1.0, 1.0, 0.0, 0.0, 600, 900));
	}
}
