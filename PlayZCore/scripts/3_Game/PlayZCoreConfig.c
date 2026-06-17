class PlayZCoreConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/Core.json";

	bool HideAttachedBackpackCargo = true;
	bool EnableTakeBackpackFromBack = true;

	bool BlockEatingWithMouthCover = true;
	bool EnableMouthBlockerShortcut = true;

	bool m_EnableDyingPPE = true;
	float m_DyingHealthStart = 5.0;
	float m_DyingHealthEnd = 0.0;
	float m_DyingMaxVignette = 0.9;
	float m_DyingMaxGauss = 0.6;
	float m_DyingMaxOverlay = 0.25;
	float m_DyingMaxExposure = -3.0;
	float m_DyingPulseFreqMin = 0.5;
	float m_DyingPulseFreqMax = 2.5;
	float m_DyingPulseStrength = 0.7;

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
		ValidateDyingPPE();
	}

	void Save()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}
		JsonFileLoader<PlayZCoreConfig>.JsonSaveFile(CONFIG_PATH, this);
	}

	void ValidateDyingPPE()
	{
		if (m_DyingHealthEnd < 0)
		{
			m_DyingHealthEnd = 0;
		}
		if (m_DyingHealthStart <= m_DyingHealthEnd)
		{
			m_DyingHealthStart = 5.0;
		}
		if (m_DyingHealthStart > 10)
		{
			m_DyingHealthStart = 5.0;
		}
		if (m_DyingMaxVignette < 0)
		{
			m_DyingMaxVignette = 0;
		}
		if (m_DyingMaxGauss < 0)
		{
			m_DyingMaxGauss = 0;
		}
		if (m_DyingMaxOverlay < 0)
		{
			m_DyingMaxOverlay = 0;
		}
		if (m_DyingPulseFreqMin < 0.1)
		{
			m_DyingPulseFreqMin = 0.1;
		}
		if (m_DyingPulseFreqMax < m_DyingPulseFreqMin)
		{
			m_DyingPulseFreqMax = m_DyingPulseFreqMin;
		}
		if (m_DyingPulseStrength < 0)
		{
			m_DyingPulseStrength = 0;
		}
		if (m_DyingPulseStrength > 1)
		{
			m_DyingPulseStrength = 1;
		}
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
		rpc.Write(config.m_EnableDyingPPE);
		rpc.Write(config.m_DyingHealthStart);
		rpc.Write(config.m_DyingHealthEnd);
		rpc.Write(config.m_DyingMaxVignette);
		rpc.Write(config.m_DyingMaxGauss);
		rpc.Write(config.m_DyingMaxOverlay);
		rpc.Write(config.m_DyingMaxExposure);
		rpc.Write(config.m_DyingPulseFreqMin);
		rpc.Write(config.m_DyingPulseFreqMax);
		rpc.Write(config.m_DyingPulseStrength);
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
		if (!ctx.Read(config.m_EnableDyingPPE))
		{
			return;
		}
		if (!ctx.Read(config.m_DyingHealthStart))
		{
			return;
		}
		if (!ctx.Read(config.m_DyingHealthEnd))
		{
			return;
		}
		if (!ctx.Read(config.m_DyingMaxVignette))
		{
			return;
		}
		if (!ctx.Read(config.m_DyingMaxGauss))
		{
			return;
		}
		if (!ctx.Read(config.m_DyingMaxOverlay))
		{
			return;
		}
		if (!ctx.Read(config.m_DyingMaxExposure))
		{
			return;
		}
		if (!ctx.Read(config.m_DyingPulseFreqMin))
		{
			return;
		}
		if (!ctx.Read(config.m_DyingPulseFreqMax))
		{
			return;
		}
		if (!ctx.Read(config.m_DyingPulseStrength))
		{
			return;
		}
		config.ValidateDyingPPE();
	}
}
