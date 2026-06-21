//! Tunables: $profile:PlayZ/Overdose.json (server load, client sync via RPC).

class PlayZOverdoseConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/Overdose.json";

	bool m_EnableOverdosePPE = true;
	float m_TierValueMin = 1.2;
	float m_TierValueMax = 3.5;
	float m_RotPowerMax = 0.07;
	float m_RotMinAngle = 15.0;
	float m_RotMaxAngle = 80.0;
	float m_RotMinDepth = 2.5;
	float m_RotMaxDepth = 4.5;
	float m_DistortMax = -0.45;
	float m_DistortCenterMax = 0.12;
	float m_PulseMix = 0.35;

	[NonSerialized()]
	private static ref PlayZOverdoseConfig m_Instance;

	static PlayZOverdoseConfig GetInstance()
	{
		if (!m_Instance)
		{
			m_Instance = new PlayZOverdoseConfig();
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
			JsonFileLoader<PlayZOverdoseConfig>.JsonLoadFile(CONFIG_PATH, this);
		}
		else
		{
			SetDefaults();
			Save();
		}
		ValidateOverdosePPE();
	}

	void Save()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}
		JsonFileLoader<PlayZOverdoseConfig>.JsonSaveFile(CONFIG_PATH, this);
	}

	void SetDefaults()
	{
		m_EnableOverdosePPE = true;
		m_TierValueMin = 1.2;
		m_TierValueMax = 3.5;
		m_RotPowerMax = 0.07;
		m_RotMinAngle = 15.0;
		m_RotMaxAngle = 80.0;
		m_RotMinDepth = 2.5;
		m_RotMaxDepth = 4.5;
		m_DistortMax = -0.45;
		m_DistortCenterMax = 0.12;
		m_PulseMix = 0.35;
	}

	void ValidateOverdosePPE()
	{
		if (m_TierValueMin < 0)
		{
			m_TierValueMin = 0;
		}
		if (m_TierValueMax <= m_TierValueMin)
		{
			m_TierValueMax = m_TierValueMin + 0.1;
		}
		if (m_RotPowerMax < 0)
		{
			m_RotPowerMax = 0;
		}
		if (m_RotPowerMax > 0.09)
		{
			m_RotPowerMax = 0.09;
		}
		if (m_RotMinAngle < 0)
		{
			m_RotMinAngle = 0;
		}
		if (m_RotMaxAngle < m_RotMinAngle)
		{
			m_RotMaxAngle = m_RotMinAngle;
		}
		if (m_RotMinDepth < 0)
		{
			m_RotMinDepth = 0;
		}
		if (m_RotMaxDepth < m_RotMinDepth)
		{
			m_RotMaxDepth = m_RotMinDepth;
		}
		if (m_DistortCenterMax < 0)
		{
			m_DistortCenterMax = 0;
		}
		if (m_PulseMix < 0)
		{
			m_PulseMix = 0;
		}
		if (m_PulseMix > 1)
		{
			m_PulseMix = 1;
		}
	}

	static void SyncConfig(PlayerIdentity identity = null)
	{
		if (!GetGame().IsServer())
		{
			return;
		}

		PlayZOverdoseConfig config = GetInstance();

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(config.m_EnableOverdosePPE);
		rpc.Write(config.m_TierValueMin);
		rpc.Write(config.m_TierValueMax);
		rpc.Write(config.m_RotPowerMax);
		rpc.Write(config.m_RotMinAngle);
		rpc.Write(config.m_RotMaxAngle);
		rpc.Write(config.m_RotMinDepth);
		rpc.Write(config.m_RotMaxDepth);
		rpc.Write(config.m_DistortMax);
		rpc.Write(config.m_DistortCenterMax);
		rpc.Write(config.m_PulseMix);
		rpc.Send(null, PlayZOverdoseRPCs.SYNC_OVERDOSE_CONFIG, true, identity);
	}

	static void OnRPC(ParamsReadContext ctx)
	{
		PlayZOverdoseConfig config = GetInstance();
		if (!ctx.Read(config.m_EnableOverdosePPE))
		{
			return;
		}
		if (!ctx.Read(config.m_TierValueMin))
		{
			return;
		}
		if (!ctx.Read(config.m_TierValueMax))
		{
			return;
		}
		if (!ctx.Read(config.m_RotPowerMax))
		{
			return;
		}
		if (!ctx.Read(config.m_RotMinAngle))
		{
			return;
		}
		if (!ctx.Read(config.m_RotMaxAngle))
		{
			return;
		}
		if (!ctx.Read(config.m_RotMinDepth))
		{
			return;
		}
		if (!ctx.Read(config.m_RotMaxDepth))
		{
			return;
		}
		if (!ctx.Read(config.m_DistortMax))
		{
			return;
		}
		if (!ctx.Read(config.m_DistortCenterMax))
		{
			return;
		}
		if (!ctx.Read(config.m_PulseMix))
		{
			return;
		}
		config.ValidateOverdosePPE();
	}
}
