static const string PLAYZ_EXPANSION_PROFILE_DIR = "$profile:PlayZ/";
static const string PLAYZ_EXPANSION_CONFIG_PATH = PLAYZ_EXPANSION_PROFILE_DIR + "Expansion.json";

class PlayZExpansionConfig
{
	float GraveCrossBlockRadiusMeters = 30.0;
	int GraveCrossRetryIntervalSeconds = 60;

	private static ref PlayZExpansionConfig s_Instance;

	static PlayZExpansionConfig Get()
	{
		if (!s_Instance)
		{
			s_Instance = new PlayZExpansionConfig();
			if (g_Game && g_Game.IsServer())
				s_Instance.Load();
		}
		return s_Instance;
	}

	void Load()
	{
		if (!g_Game || !g_Game.IsServer())
			return;

		if (!FileExist(PLAYZ_EXPANSION_PROFILE_DIR))
			MakeDirectory(PLAYZ_EXPANSION_PROFILE_DIR);

		if (!FileExist(PLAYZ_EXPANSION_CONFIG_PATH))
		{
			Save();
			return;
		}

		JsonFileLoader<PlayZExpansionConfig>.JsonLoadFile(PLAYZ_EXPANSION_CONFIG_PATH, this);

		if (GraveCrossBlockRadiusMeters < 0.0)
			GraveCrossBlockRadiusMeters = 0.0;

		if (GraveCrossRetryIntervalSeconds < 1)
			GraveCrossRetryIntervalSeconds = 1;
	}

	void Save()
	{
		if (!g_Game || !g_Game.IsServer())
			return;

		JsonFileLoader<PlayZExpansionConfig>.JsonSaveFile(PLAYZ_EXPANSION_CONFIG_PATH, this);
	}
}
