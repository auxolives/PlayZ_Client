class PlayZCarsConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/Cars.json";

	ref array<ref PlayZCarVehicleEntry> m_Vehicles;

	void PlayZCarsConfig()
	{
		m_Vehicles = new array<ref PlayZCarVehicleEntry>;
	}

	static void EnsureProfileDir()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}
	}

	void Load()
	{
		PlayZCarsConfig loaded = LoadFromProfile();
		m_Vehicles = loaded.m_Vehicles;
	}

	static PlayZCarsConfig LoadFromProfile()
	{
		PlayZCarsConfig config = new PlayZCarsConfig();
		EnsureProfileDir();

		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZCarsConfig>.JsonLoadFile(CONFIG_PATH, config);
			if (config.Normalize())
			{
				config.Save();
			}
			return config;
		}

		config.SetDefaults();
		config.Save();
		Print("[PlayZCars] Created settings file: " + CONFIG_PATH);
		return config;
	}

	void Save()
	{
		EnsureProfileDir();
		JsonFileLoader<PlayZCarsConfig>.JsonSaveFile(CONFIG_PATH, this);
	}

	void SetDefaults()
	{
		m_Vehicles = new array<ref PlayZCarVehicleEntry>;
		PlayZCarVehicleEntry offroad = new PlayZCarVehicleEntry();
		offroad.m_ClassName = "Offroad_02";
		m_Vehicles.Insert(offroad);

		PlayZCarVehicleEntry ada = new PlayZCarVehicleEntry();
		ada.m_ClassName = "OffroadHatchback";
		m_Vehicles.Insert(ada);

		PlayZCarVehicleEntry olga = new PlayZCarVehicleEntry();
		olga.m_ClassName = "CivilianSedan";
		m_Vehicles.Insert(olga);

		PlayZCarVehicleEntry gunter = new PlayZCarVehicleEntry();
		gunter.m_ClassName = "Hatchback_02";
		m_Vehicles.Insert(gunter);

		PlayZCarVehicleEntry sarka = new PlayZCarVehicleEntry();
		sarka.m_ClassName = "Sedan_02";
		m_Vehicles.Insert(sarka);

		PlayZCarVehicleEntry v3sCovered = new PlayZCarVehicleEntry();
		v3sCovered.m_ClassName = "Truck_01_Covered";
		m_Vehicles.Insert(v3sCovered);

		PlayZCarVehicleEntry v3sCargo = new PlayZCarVehicleEntry();
		v3sCargo.m_ClassName = "Truck_01_Cargo";
		m_Vehicles.Insert(v3sCargo);
	}

	bool Normalize()
	{
		bool changed = false;

		if (!m_Vehicles)
		{
			m_Vehicles = new array<ref PlayZCarVehicleEntry>;
			changed = true;
		}

		if (m_Vehicles.Count() == 0)
		{
			SetDefaults();
			return true;
		}

		for (int i = 0; i < m_Vehicles.Count(); i++)
		{
			PlayZCarVehicleEntry entry = m_Vehicles.Get(i);
			if (!entry)
			{
				continue;
			}

			if (entry.m_HillAssistStrength < 0.0)
			{
				entry.m_HillAssistStrength = 0.0;
				changed = true;
			}
			else if (entry.m_HillAssistStrength > 5.0)
			{
				entry.m_HillAssistStrength = 5.0;
				changed = true;
			}
		}

		return changed;
	}

	PlayZCarVehicleEntry GetEntry(string className)
	{
		if (!m_Vehicles || className == "")
		{
			return null;
		}

		for (int i = 0; i < m_Vehicles.Count(); i++)
		{
			PlayZCarVehicleEntry entry = m_Vehicles.Get(i);
			if (!entry)
			{
				continue;
			}

			if (entry.m_ClassName == className)
			{
				return entry;
			}
		}

		return null;
	}
}
