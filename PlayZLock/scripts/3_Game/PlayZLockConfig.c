class PlayZLockClientConfig
{
	bool AllowAdminOpen = true;
	bool InteractAnywhere = true;
	bool InstantOpen = false;
	bool DismantleWithLock = false;
	int DisplayDigits = 2;
	float DialTime = 0.5;
	bool OwnerCanRemoveLockWithoutCode = false;
}

class PlayZLockServerConfig
{
	bool PrintLogs = true;
	bool UnlockOnOpen = false;
	int DigitMultiplier = 1;
}

class PlayZLockConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/Lock.json";

	ref PlayZLockClientConfig ClientSyncConfig;
	ref PlayZLockServerConfig ServerConfig;
	ref array<string> AdminIDs;

	[NonSerialized()]
	private static ref PlayZLockConfig m_Instance;

	static PlayZLockConfig Get()
	{
		if (!m_Instance)
		{
			m_Instance = new PlayZLockConfig();
			m_Instance.SetDefaults();
			if (GetGame() && GetGame().IsServer())
			{
				m_Instance.Load();
			}
		}
		return m_Instance;
	}

	void SetDefaults()
	{
		ClientSyncConfig = new PlayZLockClientConfig();
		ServerConfig = new PlayZLockServerConfig();
		AdminIDs = new array<string>;
	}

	void Load()
	{
		EnsureProfileDir();
		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZLockConfig>.JsonLoadFile(CONFIG_PATH, this);
		}
		else
		{
			SetDefaults();
			Save();
		}

		if (!ClientSyncConfig)
		{
			ClientSyncConfig = new PlayZLockClientConfig();
		}
		if (!ServerConfig)
		{
			ServerConfig = new PlayZLockServerConfig();
		}
		if (!AdminIDs)
		{
			AdminIDs = new array<string>;
		}
	}

	void Save()
	{
		EnsureProfileDir();
		JsonFileLoader<PlayZLockConfig>.JsonSaveFile(CONFIG_PATH, this);
	}

	static void EnsureProfileDir()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}
	}

	void ApplyClientSync(PlayZLockClientConfig cfg)
	{
		if (!cfg)
		{
			return;
		}
		ClientSyncConfig = cfg;
	}

	bool IsAdmin(string uid)
	{
		if (!AdminIDs || uid == "")
		{
			return false;
		}
		return AdminIDs.Find(uid) != -1;
	}

	bool IsAdmin(PlayerIdentity id)
	{
		if (!id)
		{
			return false;
		}
		if (IsAdmin(id.GetId()))
		{
			return true;
		}
		if (IsAdmin(id.GetPlainId()))
		{
			return true;
		}
		return false;
	}
}
