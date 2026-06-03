class PlayZPPEConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/WeatherPPE.json";

	bool m_EnableWeatherPPE = true;

	float m_SaturationMin = 0.8;
	float m_SaturationMax = 1.0;
	float m_SaturationBoostClear = 1.10;
	
	float m_ContrastMin = 0.95;
	float m_ContrastMax = 1.05;

	float m_GrainIntensity = 0.15;
	float m_ChromIntensity = 0.005;
	float m_GodRaysIntensity = 0.8;
	float m_MaxWindPPE = 20.0;

	float m_ShelterFadeSpeed = 0.5;
	float m_WeatherFadeSpeed = 0.05;

	float m_ColorClearR = 1.07;
	float m_ColorClearG = 1.03;
	float m_ColorClearB = 0.95;

	float m_ColorGloomyR = 0.92;
	float m_ColorGloomyG = 0.95;
	float m_ColorGloomyB = 1.10;

	float m_ColorHeatwaveR = 1.50;
	float m_ColorHeatwaveG = 0.85;
	float m_ColorHeatwaveB = 0.60;

	float m_ColorColdwaveR = 0.55;
	float m_ColorColdwaveG = 0.72;
	float m_ColorColdwaveB = 1.60;

	float m_ColorSnowR = 0.88;
	float m_ColorSnowG = 0.94;
	float m_ColorSnowB = 1.10;

	void Load()
	{
		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZPPEConfig>.JsonLoadFile(CONFIG_PATH, this);
		}
		else
		{
			Save();
		}
	}

	void Save()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}
		JsonFileLoader<PlayZPPEConfig>.JsonSaveFile(CONFIG_PATH, this);
	}
}
