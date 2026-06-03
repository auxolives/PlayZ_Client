//! PlayZ anti-combat-log settings — $profile:PlayZ/AntiCombatLog.json
class PlayZAntiCombatLogConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/AntiCombatLog.json";
	static const string CONFIG_VERSION = "1";

	string ConfigVersion = "";
	int CombatLogoutSecs = 300;
	int DisableExitButtonSecs = 5;
	bool NotifyPlayerOfPenalty = true;
	bool TriggerOnGunshot = false;
	bool TriggerForExpansionAI = false;
	int TriggerOnBulletImpactRadius = 0;
	int TriggerOnExplosiveRadius = 30;
	int DropFlareOnPlayer = 0;
	int KillPlayer = 0;

	[NonSerialized()]
	private static ref PlayZAntiCombatLogConfig m_Instance;

	static PlayZAntiCombatLogConfig Get()
	{
		if (!m_Instance)
		{
			m_Instance = new PlayZAntiCombatLogConfig();
			if (GetGame().IsServer())
			{
				m_Instance.Load();
			}
		}
		return m_Instance;
	}

	void Load()
	{
		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZAntiCombatLogConfig>.JsonLoadFile(CONFIG_PATH, this);

			if (ConfigVersion == CONFIG_VERSION)
			{
				return;
			}

			JsonFileLoader<PlayZAntiCombatLogConfig>.JsonSaveFile(CONFIG_PATH + ".old", this);
		}

		ConfigVersion = CONFIG_VERSION;
		Save();
	}

	void Save()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}
		JsonFileLoader<PlayZAntiCombatLogConfig>.JsonSaveFile(CONFIG_PATH, this);
	}
}
