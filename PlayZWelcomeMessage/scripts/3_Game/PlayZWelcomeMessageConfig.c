class PlayZWelcomeMessageConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/WelcomeMessage.json";

	bool Enabled;

	int StartX;
	int StartY;
	bool ScaleToScreen;
	int ReferenceScreenWidth;
	int ReferenceScreenHeight;

	int StartDelaySeconds;
	int FirstLineFadeInMs;
	int PauseBetweenFirstLineAndInformationTextMs;
	int InformationLineFadeInDelayMs;
	int FullyVisiblePauseSeconds;
	int FullyVisiblePauseMs;
	int FadeOutMs;

	string FirstLineTextColor;
	string InformationTextColor;

	string FirstLineTextKey;
	ref array<string> InformationTextLineKeys;

	void PlayZWelcomeMessageConfig()
	{
		InformationTextLineKeys = new array<string>();
		SetDefaults();
	}

	void SetDefaults()
	{
		Enabled = true;

		StartX = 100;
		StartY = 100;
		ScaleToScreen = true;
		ReferenceScreenWidth = 3440;
		ReferenceScreenHeight = 1440;

		StartDelaySeconds = 15;
		FirstLineFadeInMs = 2200;
		PauseBetweenFirstLineAndInformationTextMs = 500;
		InformationLineFadeInDelayMs = 950;
		FullyVisiblePauseSeconds = 15;
		FullyVisiblePauseMs = 0;
		FadeOutMs = 2600;

		FirstLineTextColor = "#FFFFFF";
		InformationTextColor = "#FFFFFF";

		FirstLineTextKey = "STR_PlayZ_Welcome_Title";

		InformationTextLineKeys.Clear();
		InformationTextLineKeys.Insert("STR_PlayZ_Welcome_Line1");
		InformationTextLineKeys.Insert("STR_PlayZ_Welcome_Line2");
		InformationTextLineKeys.Insert("STR_PlayZ_Welcome_Line3");
		InformationTextLineKeys.Insert("STR_PlayZ_Welcome_Line4");
		InformationTextLineKeys.Insert("STR_PlayZ_Welcome_GoodLuck");
	}

	void Normalize()
	{
		if (!InformationTextLineKeys)
		{
			InformationTextLineKeys = new array<string>();
		}

		FirstLineFadeInMs = Math.Max(0, FirstLineFadeInMs);
		StartDelaySeconds = Math.Max(0, StartDelaySeconds);
		StartX = Math.Max(0, StartX);
		StartY = Math.Max(0, StartY);
		ReferenceScreenWidth = Math.Max(1, ReferenceScreenWidth);
		ReferenceScreenHeight = Math.Max(1, ReferenceScreenHeight);
		PauseBetweenFirstLineAndInformationTextMs = Math.Max(0, PauseBetweenFirstLineAndInformationTextMs);
		InformationLineFadeInDelayMs = Math.Max(0, InformationLineFadeInDelayMs);
		FullyVisiblePauseSeconds = Math.Max(0, FullyVisiblePauseSeconds);
		if (FullyVisiblePauseSeconds == 0 && FullyVisiblePauseMs > 0)
		{
			FullyVisiblePauseSeconds = Math.Round(FullyVisiblePauseMs / 1000.0);
		}
		FullyVisiblePauseMs = 0;
		FadeOutMs = Math.Max(1, FadeOutMs);

		if (FirstLineTextColor == "")
		{
			FirstLineTextColor = "#FFFFFF";
		}

		if (InformationTextColor == "")
		{
			InformationTextColor = "#FFFFFF";
		}

		if (FirstLineTextKey == "")
		{
			FirstLineTextKey = "STR_PlayZ_Welcome_Title";
		}
	}

	static void EnsureProfileDir()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}
	}

	static PlayZWelcomeMessageConfig LoadFromProfile()
	{
		PlayZWelcomeMessageConfig config = new PlayZWelcomeMessageConfig();
		EnsureProfileDir();

		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZWelcomeMessageConfig>.JsonLoadFile(CONFIG_PATH, config);
			config.Normalize();
			return config;
		}

		config.Normalize();
		JsonFileLoader<PlayZWelcomeMessageConfig>.JsonSaveFile(CONFIG_PATH, config);
		return config;
	}
}

class PlayZWelcomeMessageClientState
{
	protected static ref PlayZWelcomeMessageConfig m_PendingConfig;

	static void SetPendingConfig(PlayZWelcomeMessageConfig config)
	{
		m_PendingConfig = config;
	}

	static bool HasPendingConfig()
	{
		return m_PendingConfig != null;
	}

	static PlayZWelcomeMessageConfig ConsumePendingConfig()
	{
		PlayZWelcomeMessageConfig config = m_PendingConfig;
		m_PendingConfig = null;
		return config;
	}
}
