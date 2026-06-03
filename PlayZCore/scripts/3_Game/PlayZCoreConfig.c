class PlayZCoreConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/Core.json";

	bool HideAttachedBackpackCargo = true;
	bool EnableTakeBackpackFromBack = true;

	bool BlockEatingWithMouthCover = true;
	bool EnableMouthBlockerShortcut = true;

	[NonSerialized()]
	private static ref PlayZCoreConfig m_Instance;

	static PlayZCoreConfig GetInstance()
	{
		if (!m_Instance)
		{
			m_Instance = new PlayZCoreConfig();
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
			JsonFileLoader<PlayZCoreConfig>.JsonLoadFile(CONFIG_PATH, this);
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
		JsonFileLoader<PlayZCoreConfig>.JsonSaveFile(CONFIG_PATH, this);
	}

	static void SyncConfig(PlayerIdentity identity = null)
	{
		if (!GetGame().IsServer())
		{
			return;
		}

		PlayZCoreConfig config = GetInstance();

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(config.HideAttachedBackpackCargo);
		rpc.Write(config.EnableTakeBackpackFromBack);
		rpc.Write(config.BlockEatingWithMouthCover);
		rpc.Write(config.EnableMouthBlockerShortcut);
		rpc.Send(null, PlayZCoreRPCs.SYNC_CORE_CONFIG, true, identity);
	}

	static void OnRPC(ParamsReadContext ctx)
	{
		PlayZCoreConfig config = GetInstance();
		if (!ctx.Read(config.HideAttachedBackpackCargo))
		{
			return;
		}
		if (!ctx.Read(config.EnableTakeBackpackFromBack))
		{
			return;
		}
		if (!ctx.Read(config.BlockEatingWithMouthCover))
		{
			return;
		}
		if (!ctx.Read(config.EnableMouthBlockerShortcut))
		{
			return;
		}
	}
}
