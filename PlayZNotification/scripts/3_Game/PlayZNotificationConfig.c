class PlayZNotificationConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/Notification.json";

	int Enabled;
	int ShowTitle;
	int ShowMessage;

	int MarginX;
	int MarginY;
	int ScaleToScreen;
	int ReferenceScreenWidth;
	int ReferenceScreenHeight;

	int TitleTextSize;
	int BodyTextSize;
	string TitleTextColor;
	string BodyTextColor;

	int FadeInMs;
	int FadeOutMs;
	int UsePayloadDuration;
	float FixedHoldSeconds;
	float MinHoldSeconds;
	float MaxHoldSeconds;

	int MaxQueueSize;
	int BlockedQueueStaleSeconds;

	void PlayZNotificationConfig()
	{
		SetDefaults();
	}

	void SetDefaults()
	{
		Enabled = 1;
		ShowTitle = 1;
		ShowMessage = 1;

		MarginX = 0;
		MarginY = 0;
		ScaleToScreen = 1;
		ReferenceScreenWidth = 3440;
		ReferenceScreenHeight = 1440;

		TitleTextSize = 32;
		BodyTextSize = 24;
		TitleTextColor = "FFFFFF";
		BodyTextColor = "E8E8E8";

		FadeInMs = 400;
		FadeOutMs = 600;
		UsePayloadDuration = 1;
		FixedHoldSeconds = 5.0;
		MinHoldSeconds = 2.0;
		MaxHoldSeconds = 15.0;

		MaxQueueSize = 5;
		BlockedQueueStaleSeconds = 30;
	}

	bool IsModEnabled()
	{
		return Enabled != 0;
	}

	bool UsesShowTitle()
	{
		return ShowTitle != 0;
	}

	bool UsesShowMessage()
	{
		return ShowMessage != 0;
	}

	bool UsesScaleToScreen()
	{
		return ScaleToScreen != 0;
	}

	bool UsesPayloadDuration()
	{
		return UsePayloadDuration != 0;
	}

	void Normalize()
	{
		// Pixel offset from screen center (positive = right/down, negative = left/up).
		ReferenceScreenWidth = Math.Max(1, ReferenceScreenWidth);
		ReferenceScreenHeight = Math.Max(1, ReferenceScreenHeight);
		TitleTextSize = Math.Max(1, TitleTextSize);
		BodyTextSize = Math.Max(1, BodyTextSize);
		FadeInMs = Math.Max(0, FadeInMs);
		FadeOutMs = Math.Max(1, FadeOutMs);
		FixedHoldSeconds = Math.Max(0.1, FixedHoldSeconds);
		MinHoldSeconds = Math.Max(0.1, MinHoldSeconds);
		MaxHoldSeconds = Math.Max(MinHoldSeconds, MaxHoldSeconds);
		MaxQueueSize = Math.Max(1, MaxQueueSize);
		BlockedQueueStaleSeconds = Math.Max(1, BlockedQueueStaleSeconds);

		if (TitleTextColor == "")
		{
			TitleTextColor = "FFFFFF";
		}

		if (BodyTextColor == "")
		{
			BodyTextColor = "E8E8E8";
		}
	}

	static void EnsureProfileDir()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}
	}

	static PlayZNotificationConfig LoadFromProfile()
	{
		PlayZNotificationConfig config = new PlayZNotificationConfig();
		EnsureProfileDir();

		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZNotificationConfig>.JsonLoadFile(CONFIG_PATH, config);
			config.Normalize();
			return config;
		}

		config.Normalize();
		JsonFileLoader<PlayZNotificationConfig>.JsonSaveFile(CONFIG_PATH, config);
		return config;
	}

	static bool IsEnabled()
	{
		if (!PlayZNotificationClientState.HasConfig())
		{
			return false;
		}

		PlayZNotificationConfig config = PlayZNotificationClientState.GetConfig();
		if (!config)
		{
			return false;
		}

		return config.IsModEnabled();
	}
}
