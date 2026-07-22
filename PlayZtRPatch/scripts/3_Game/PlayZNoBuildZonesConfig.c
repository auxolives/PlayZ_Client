class PlayZNoBuildZonesConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/NoBuildZones.json";

	int Enabled;
	float NotifyCooldownSeconds;
	ref array<ref PlayZNoBuildZone> Zones;

	void PlayZNoBuildZonesConfig()
	{
		Zones = new array<ref PlayZNoBuildZone>;
		SetDefaults();
	}

	void SetDefaults()
	{
		Enabled = 1;
		NotifyCooldownSeconds = 8.0;
		Zones.Clear();

		AddDefaultZone("Zone1", 12714, 0, 5279, 1000);
		AddDefaultZone("Zone2", 10038, 500, 12030, 700);
		AddDefaultZone("Zone3", 11017, 350, 11497, 500);
		AddDefaultZone("Zone4", 8347, 270, 10271, 350);
		AddDefaultZone("Zone5", 6963, 0, 7308, 450);
		AddDefaultZone("Zone6", 2746, 25, 5913, 500);
		AddDefaultZone("Zone7", 1795, 0, 1955, 200);
		AddDefaultZone("Zone8", 5366, 0, 10653, 1000);
		AddDefaultZone("Zone9", 5437, 0, 12427, 1000);
		AddDefaultZone("Zone10", 6476, 0, 13106, 1000);
	}

	protected void AddDefaultZone(string name, float x, float y, float z, float radius)
	{
		PlayZNoBuildZone zone = new PlayZNoBuildZone();
		zone.Set(name, x, y, z, radius);
		Zones.Insert(zone);
	}

	bool IsModEnabled()
	{
		return Enabled != 0;
	}

	void Normalize()
	{
		NotifyCooldownSeconds = Math.Max(1.0, NotifyCooldownSeconds);

		if (!Zones)
			Zones = new array<ref PlayZNoBuildZone>;

		for (int i = Zones.Count() - 1; i >= 0; --i)
		{
			PlayZNoBuildZone zone = Zones.Get(i);
			if (!zone || zone.Radius <= 0)
				Zones.Remove(i);
		}
	}

	bool IsInside(vector pos)
	{
		if (!IsModEnabled() || !Zones)
			return false;

		foreach (PlayZNoBuildZone zone : Zones)
		{
			if (zone && zone.ContainsHorizontal(pos))
				return true;
		}

		return false;
	}

	static void EnsureProfileDir()
	{
		if (!FileExist(CONFIG_ROOT))
			MakeDirectory(CONFIG_ROOT);
	}

	static PlayZNoBuildZonesConfig LoadFromProfile()
	{
		PlayZNoBuildZonesConfig config = new PlayZNoBuildZonesConfig();
		EnsureProfileDir();

		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZNoBuildZonesConfig>.JsonLoadFile(CONFIG_PATH, config);
			config.Normalize();
			return config;
		}

		config.Normalize();
		JsonFileLoader<PlayZNoBuildZonesConfig>.JsonSaveFile(CONFIG_PATH, config);
		return config;
	}
}
