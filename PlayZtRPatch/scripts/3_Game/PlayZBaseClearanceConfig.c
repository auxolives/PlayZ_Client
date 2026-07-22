class PlayZBaseClearanceRadius
{
	string Type;
	float Radius;

	void PlayZBaseClearanceRadius()
	{
		Type = "";
		Radius = 0;
	}

	void Set(string typeName, float radius)
	{
		Type = typeName;
		Radius = radius;
	}
}

class PlayZBaseClearanceEntry
{
	string Type;
	string Model;
	float X;
	float Y;
	float Z;
	int RefCount;

	void PlayZBaseClearanceEntry()
	{
		Type = "";
		Model = "";
		X = 0;
		Y = 0;
		Z = 0;
		RefCount = 0;
	}

	void Set(string typeName, string model, vector pos, int refCount)
	{
		Type = typeName;
		Model = model;
		X = pos[0];
		Y = pos[1];
		Z = pos[2];
		RefCount = refCount;
	}

	vector GetPosition()
	{
		return Vector(X, Y, Z);
	}

	string MakeKey()
	{
		return Type + "|" + Model + "|" + X.ToString() + "|" + Z.ToString();
	}

	bool IsLandType()
	{
		if (Type == string.Empty)
			return false;

		string typeLower = Type;
		typeLower.ToLower();
		return typeLower.IndexOf("land_") != -1;
	}
}

//! Runtime suppressed-object list — $profile:PlayZ/BaseClearance/Deleted.json
class PlayZBaseClearanceDeletedData
{
	static const string DELETED_DIR = "$profile:PlayZ/BaseClearance/";
	static const string DELETED_PATH = "$profile:PlayZ/BaseClearance/Deleted.json";

	ref array<ref PlayZBaseClearanceEntry> Entries;

	void PlayZBaseClearanceDeletedData()
	{
		Entries = new array<ref PlayZBaseClearanceEntry>;
	}

	void Normalize()
	{
		if (!Entries)
			Entries = new array<ref PlayZBaseClearanceEntry>;

		//! Drop Land_* leftovers from before the hard exclude rule.
		for (int i = Entries.Count() - 1; i >= 0; --i)
		{
			PlayZBaseClearanceEntry entry = Entries.Get(i);
			if (!entry || entry.IsLandType())
				Entries.Remove(i);
		}
	}

	static void EnsureDeletedDir()
	{
		if (!FileExist(PlayZBaseClearanceConfig.CONFIG_ROOT))
			MakeDirectory(PlayZBaseClearanceConfig.CONFIG_ROOT);

		if (!FileExist(DELETED_DIR))
			MakeDirectory(DELETED_DIR);
	}

	static PlayZBaseClearanceDeletedData LoadFromProfile()
	{
		PlayZBaseClearanceDeletedData data = new PlayZBaseClearanceDeletedData();
		EnsureDeletedDir();

		if (FileExist(DELETED_PATH))
		{
			JsonFileLoader<PlayZBaseClearanceDeletedData>.JsonLoadFile(DELETED_PATH, data);
			data.Normalize();
			return data;
		}

		data.Normalize();
		return data;
	}

	void SaveToProfile()
	{
		EnsureDeletedDir();
		Normalize();
		JsonFileLoader<PlayZBaseClearanceDeletedData>.JsonSaveFile(DELETED_PATH, this);
	}
}

//! Settings only — $profile:PlayZ/BaseClearance.json (no Entries).
class PlayZBaseClearanceConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/BaseClearance.json";
	static const string LEGACY_CONFIG_PATH = "$profile:PlayZ/VegetationClear.json";

	int Enabled;
	int ClearTreesBushes;
	float FindEpsilonM;
	ref array<ref PlayZBaseClearanceRadius> Radii;
	//! Lowercase shape/type substrings. Matched against GetShapeName() and GetType().
	ref array<string> ModelPrefixes;

	void PlayZBaseClearanceConfig()
	{
		Radii = new array<ref PlayZBaseClearanceRadius>;
		ModelPrefixes = new array<string>;
		SetDefaults();
	}

	void SetDefaults()
	{
		Enabled = 1;
		ClearTreesBushes = 1;
		FindEpsilonM = 0.75;
		Radii.Clear();
		FillDefaultRadii();
		FillDefaultModelPrefixes();
	}

	void FillDefaultRadii()
	{
		Radii.Clear();
		AddRadius("tR_Shed", 3.5);
		AddRadius("tR_ShieldSmall", 1.0);
		AddRadius("tR_NarrowDoor", 3.0);
		AddRadius("tR_MediumDoor", 4.0);
		AddRadius("tR_Stockade", 5.0);
		AddRadius("tR_StockadeCorner", 4.5);
		AddRadius("Fence", 4.0);
		AddRadius("Watchtower", 4.0);
		AddRadius("MediumTent", 3.0);
		AddRadius("LargeTent", 4.0);
		AddRadius("PartyTent", 3.0);
		AddRadius("CarTent", 4.5);
	}

	void FillDefaultModelPrefixes()
	{
		ModelPrefixes.Clear();
		ModelPrefixes.Insert("wall_woodf_");
		ModelPrefixes.Insert("_dz");
		ModelPrefixes.Insert("table_");
		ModelPrefixes.Insert("chair_");
		ModelPrefixes.Insert("metalcrate");
		ModelPrefixes.Insert("wall_stone2");
		ModelPrefixes.Insert("wall_wood2");
		ModelPrefixes.Insert("wall_wood1");
		ModelPrefixes.Insert("wall_tin8");
		ModelPrefixes.Insert("misc_");
		ModelPrefixes.Insert("box_");
		ModelPrefixes.Insert("garbage_");
		ModelPrefixes.Insert("washing_");
		ModelPrefixes.Insert("wheel_cart");
		ModelPrefixes.Insert("fridge");
		ModelPrefixes.Insert("racks");
	}

	protected void AddRadius(string typeName, float radius)
	{
		PlayZBaseClearanceRadius entry = new PlayZBaseClearanceRadius();
		entry.Set(typeName, radius);
		Radii.Insert(entry);
	}

	bool IsModEnabled()
	{
		return Enabled != 0;
	}

	bool ClearsTreesAndBushes()
	{
		return ClearTreesBushes != 0;
	}

	void Normalize()
	{
		FindEpsilonM = Math.Max(0.1, FindEpsilonM);

		if (!Radii)
			Radii = new array<ref PlayZBaseClearanceRadius>;

		if (!ModelPrefixes)
			ModelPrefixes = new array<string>;

		if (Radii.Count() == 0)
			FillDefaultRadii();

		bool seededPrefixes = false;
		if (ModelPrefixes.Count() == 0)
		{
			FillDefaultModelPrefixes();
			seededPrefixes = true;
		}

		if (seededPrefixes)
			ClearTreesBushes = 1;

		array<string> normalizedPrefixes = new array<string>;
		foreach (string rawPrefix : ModelPrefixes)
		{
			string prefix = rawPrefix;
			prefix.ToLower();
			if (prefix != string.Empty)
				normalizedPrefixes.Insert(prefix);
		}
		ModelPrefixes = normalizedPrefixes;
	}

	bool MatchesModelPrefix(string token)
	{
		if (token == string.Empty || !ModelPrefixes || ModelPrefixes.Count() == 0)
			return false;

		token.ToLower();

		foreach (string prefix : ModelPrefixes)
		{
			if (prefix != string.Empty && token.IndexOf(prefix) != -1)
				return true;
		}

		return false;
	}

	float GetConfiguredRadius(string typeName)
	{
		if (!Radii || typeName == string.Empty)
			return 0;

		foreach (PlayZBaseClearanceRadius entry : Radii)
		{
			if (entry && entry.Type == typeName)
				return entry.Radius;
		}

		return 0;
	}

	static void EnsureProfileDir()
	{
		if (!FileExist(CONFIG_ROOT))
			MakeDirectory(CONFIG_ROOT);
	}

	static PlayZBaseClearanceConfig LoadFromProfile()
	{
		PlayZBaseClearanceConfig config = new PlayZBaseClearanceConfig();
		EnsureProfileDir();

		string path = CONFIG_PATH;
		if (!FileExist(path) && FileExist(LEGACY_CONFIG_PATH))
			path = LEGACY_CONFIG_PATH;

		if (FileExist(path))
		{
			JsonFileLoader<PlayZBaseClearanceConfig>.JsonLoadFile(path, config);
			config.Normalize();
			JsonFileLoader<PlayZBaseClearanceConfig>.JsonSaveFile(CONFIG_PATH, config);
			return config;
		}

		config.Normalize();
		JsonFileLoader<PlayZBaseClearanceConfig>.JsonSaveFile(CONFIG_PATH, config);
		return config;
	}

	void SaveToProfile()
	{
		EnsureProfileDir();
		Normalize();
		JsonFileLoader<PlayZBaseClearanceConfig>.JsonSaveFile(CONFIG_PATH, this);
	}
}

//! One-shot loader for old combined BaseClearance.json / VegetationClear.json that still had Entries.
class PlayZBaseClearanceLegacyFile
{
	ref array<ref PlayZBaseClearanceEntry> Entries;

	void PlayZBaseClearanceLegacyFile()
	{
		Entries = new array<ref PlayZBaseClearanceEntry>;
	}

	static void MigrateEntriesIfNeeded()
	{
		if (FileExist(PlayZBaseClearanceDeletedData.DELETED_PATH))
			return;

		string path = PlayZBaseClearanceConfig.CONFIG_PATH;
		if (!FileExist(path))
			path = PlayZBaseClearanceConfig.LEGACY_CONFIG_PATH;

		if (!FileExist(path))
			return;

		PlayZBaseClearanceLegacyFile legacy = new PlayZBaseClearanceLegacyFile();
		JsonFileLoader<PlayZBaseClearanceLegacyFile>.JsonLoadFile(path, legacy);
		if (!legacy.Entries || legacy.Entries.Count() == 0)
			return;

		PlayZBaseClearanceDeletedData deleted = new PlayZBaseClearanceDeletedData();
		deleted.Entries = legacy.Entries;
		deleted.Normalize();
		deleted.SaveToProfile();
	}
}
