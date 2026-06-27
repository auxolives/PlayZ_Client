class PlayZInfectedConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/Infected.json";

	bool Enabled = true;
	float SpawnDeadChancePercent = 15.0;

	[NonSerialized()]
	private static ref PlayZInfectedConfig m_Instance;

	static PlayZInfectedConfig GetInstance()
	{
		if (!m_Instance)
		{
			m_Instance = new PlayZInfectedConfig();
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
			JsonFileLoader<PlayZInfectedConfig>.JsonLoadFile(CONFIG_PATH, this);
		}
		else
		{
			Save();
		}
		Validate();
	}

	void Save()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}
		JsonFileLoader<PlayZInfectedConfig>.JsonSaveFile(CONFIG_PATH, this);
	}

	void Validate()
	{
		if (SpawnDeadChancePercent < 0)
		{
			SpawnDeadChancePercent = 0;
		}
		if (SpawnDeadChancePercent > 100)
		{
			SpawnDeadChancePercent = 100;
		}
	}

	bool RollSpawnDead()
	{
		if (!Enabled)
		{
			return false;
		}
		if (SpawnDeadChancePercent <= 0)
		{
			return false;
		}
		return Math.RandomFloatInclusive(0, 100) <= SpawnDeadChancePercent;
	}
}
