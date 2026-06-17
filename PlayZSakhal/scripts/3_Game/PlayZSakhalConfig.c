class PlayZSakhalConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/Sakhal.json";

	bool m_EnableHypoxiaPPE = true;
	bool m_EnableHypoxiaStamina = true;

	float m_AltStartM = 250.0;
	float m_AltFullM = 600.0;
	float m_ClientChromMax = 0.01;
	float m_ClientBlurMax = 0.10;
	float m_ClientVignetteMax = 0.70;

	void Load()
	{
		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZSakhalConfig>.JsonLoadFile(CONFIG_PATH, this);
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
			MakeDirectory(CONFIG_ROOT);

		JsonFileLoader<PlayZSakhalConfig>.JsonSaveFile(CONFIG_PATH, this);
	}

	void SetDefaults()
	{
		m_EnableHypoxiaPPE = true;
		m_EnableHypoxiaStamina = true;
		m_AltStartM = 300.0;
		m_AltFullM = 600.0;
		m_ClientChromMax = 0.10;
		m_ClientBlurMax = 0.15;
		m_ClientVignetteMax = 0.70;
	}
}
