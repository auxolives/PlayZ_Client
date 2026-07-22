//! Server-side suppress of trees/bushes + JSON ModelPrefixes clutter around supported bases/tents.
//! Uses GetSuppressedObjectManager (same API as DayZ Editor Loader).
class PlayZBaseClearanceManager
{
	protected static ref PlayZBaseClearanceManager s_Instance;

	protected ref PlayZBaseClearanceConfig m_Config;
	protected ref PlayZBaseClearanceDeletedData m_Deleted;
	protected ref map<int, ref array<string>> m_ClaimsByBaseId;
	protected bool m_SaveScheduled;
	protected bool m_WorldReady;

	void PlayZBaseClearanceManager()
	{
		m_ClaimsByBaseId = new map<int, ref array<string>>;
		m_SaveScheduled = false;
		m_WorldReady = false;
	}

	static PlayZBaseClearanceManager Get()
	{
		if (!s_Instance)
			s_Instance = new PlayZBaseClearanceManager();

		return s_Instance;
	}

	void Load()
	{
		//! Pull Entries out of old combined JSON before settings rewrite drops them.
		PlayZBaseClearanceLegacyFile.MigrateEntriesIfNeeded();
		m_Deleted = PlayZBaseClearanceDeletedData.LoadFromProfile();
		m_Config = PlayZBaseClearanceConfig.LoadFromProfile();
	}

	PlayZBaseClearanceConfig GetConfig()
	{
		if (!m_Config)
			Load();

		return m_Config;
	}

	PlayZBaseClearanceDeletedData GetDeleted()
	{
		if (!m_Deleted)
		{
			if (!m_Config)
				Load();
			else
				m_Deleted = PlayZBaseClearanceDeletedData.LoadFromProfile();
		}

		return m_Deleted;
	}

	bool IsEnabled()
	{
		PlayZBaseClearanceConfig config = GetConfig();
		return config && config.IsModEnabled();
	}

	//! Verified IsKindOf table — Corner is sibling of Stockade, not child.
	float GetClearRadius(EntityAI entity)
	{
		if (!entity || !IsEnabled())
			return 0;

		string typeName = entity.GetType();
		if (typeName == string.Empty)
			return 0;

		if (typeName.IndexOf("Kit") != -1)
			return 0;

		if (typeName.IndexOf("Placing") != -1)
			return 0;

		if (typeName.IndexOf("ClutterCutter") != -1)
			return 0;

		PlayZBaseClearanceConfig config = GetConfig();

		if (entity.IsKindOf("tR_StockadeCorner"))
			return ResolveRadius("tR_StockadeCorner", config);

		if (entity.IsKindOf("tR_Stockade"))
			return ResolveRadius("tR_Stockade", config);

		if (entity.IsKindOf("tR_Shed"))
			return ResolveRadius("tR_Shed", config);

		if (entity.IsKindOf("tR_ShieldSmall"))
			return ResolveRadius("tR_ShieldSmall", config);

		if (entity.IsKindOf("tR_NarrowDoor"))
			return ResolveRadius("tR_NarrowDoor", config);

		if (entity.IsKindOf("tR_MediumDoor"))
			return ResolveRadius("tR_MediumDoor", config);

		if (entity.IsKindOf("Fence"))
			return ResolveRadius("Fence", config);

		if (entity.IsKindOf("Watchtower"))
			return ResolveRadius("Watchtower", config);

		if (entity.IsKindOf("MediumTent"))
			return ResolveRadius("MediumTent", config);

		if (entity.IsKindOf("LargeTent"))
			return ResolveRadius("LargeTent", config);

		if (entity.IsKindOf("PartyTent"))
			return ResolveRadius("PartyTent", config);

		if (entity.IsKindOf("CarTent"))
			return ResolveRadius("CarTent", config);

		return 0;
	}

	protected float ResolveRadius(string key, PlayZBaseClearanceConfig config)
	{
		float configured = 0;
		if (config)
			configured = config.GetConfiguredRadius(key);

		if (configured > 0)
			return configured;

		return GetHardcodedRadius(key);
	}

	protected float GetHardcodedRadius(string key)
	{
		if (key == "tR_Shed")
			return 2.5;

		if (key == "tR_ShieldSmall")
			return 1.0;

		if (key == "tR_NarrowDoor")
			return 2.0;

		if (key == "tR_MediumDoor")
			return 3.0;

		if (key == "tR_Stockade")
			return 4.0;

		if (key == "tR_StockadeCorner")
			return 3.5;

		if (key == "Fence")
			return 3.0;

		if (key == "Watchtower")
			return 3.0;

		if (key == "MediumTent")
			return 2.0;

		if (key == "LargeTent")
			return 3.0;

		if (key == "PartyTent")
			return 2.0;

		if (key == "CarTent")
			return 3.5;

		return 0;
	}

	void OnBaseInit(EntityAI entity)
	{
		if (!g_Game.IsServer() || !entity)
			return;

		if (GetClearRadius(entity) <= 0)
			return;

		int delayMs = 1000;
		if (!m_WorldReady)
			delayMs = 8000;

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ClearAroundDeferred, delayMs, false, entity);
	}

	void ClearAroundDeferred(EntityAI entity)
	{
		if (!entity)
			return;

		ClearAround(entity);
	}

	void ClearAround(EntityAI entity)
	{
		if (!g_Game.IsServer() || !entity || !IsEnabled())
			return;

		float radius = GetClearRadius(entity);
		if (radius <= 0)
			return;

		int baseId = entity.GetID();
		if (!m_ClaimsByBaseId.Contains(baseId))
			m_ClaimsByBaseId.Set(baseId, new array<string>);

		array<string> claims = m_ClaimsByBaseId.Get(baseId);
		vector center = entity.GetPosition();

		array<Object> nearest = new array<Object>;
		array<CargoBase> proxy = new array<CargoBase>;
		g_Game.GetObjectsAtPosition(center, radius, nearest, proxy);

		foreach (Object obj : nearest)
		{
			if (!obj || obj == entity)
				continue;

			if (!ShouldClearObject(obj))
				continue;

			string key = MakeObjectKey(obj);
			if (key == string.Empty)
				continue;

			if (claims.Find(key) != -1)
				continue;

			SuppressObject(obj);
			IncrementEntry(obj, key);
			claims.Insert(key);
		}

		ScheduleSave();
	}

	void OnBaseDeleted(EntityAI entity)
	{
		if (!g_Game.IsServer() || !entity)
			return;

		int baseId = entity.GetID();
		if (!m_ClaimsByBaseId.Contains(baseId))
			return;

		array<string> claims = m_ClaimsByBaseId.Get(baseId);
		if (claims)
		{
			for (int i = 0; i < claims.Count(); ++i)
			{
				string key = claims.Get(i);
				DecrementEntryByKey(key);
			}
		}

		m_ClaimsByBaseId.Remove(baseId);
		ScheduleSave();
	}

	void ReapplySavedSuppressions()
	{
		if (!g_Game.IsServer() || !IsEnabled())
			return;

		PlayZBaseClearanceDeletedData deleted = GetDeleted();
		if (!deleted || !deleted.Entries)
			return;

		foreach (PlayZBaseClearanceEntry entry : deleted.Entries)
		{
			if (!entry)
				continue;

			Object obj = FindClearedObject(entry);
			if (obj)
				SuppressObject(obj);

			entry.RefCount = 0;
		}

		m_ClaimsByBaseId.Clear();
		m_WorldReady = true;
		ScheduleSave();
	}

	void CleanupOrphans()
	{
		if (!g_Game.IsServer() || !IsEnabled())
			return;

		PlayZBaseClearanceDeletedData deleted = GetDeleted();
		if (!deleted || !deleted.Entries)
			return;

		for (int i = deleted.Entries.Count() - 1; i >= 0; --i)
		{
			PlayZBaseClearanceEntry entry = deleted.Entries.Get(i);
			if (!entry)
			{
				deleted.Entries.Remove(i);
				continue;
			}

			if (entry.RefCount > 0)
				continue;

			Object obj = FindClearedObject(entry);
			if (obj)
				UnsuppressObject(obj);

			deleted.Entries.Remove(i);
		}

		ScheduleSave();
	}

	protected bool ShouldClearObject(Object obj)
	{
		if (!obj)
			return false;

		//! Hard rule: Land_* map buildings/props are never cleared (e.g. Land_Misc_Toilet_Dry).
		string typeName = obj.GetType();
		if (typeName != string.Empty)
		{
			string typeLower = typeName;
			typeLower.ToLower();
			if (typeLower.IndexOf("land_") != -1)
				return false;
		}

		PlayZBaseClearanceConfig config = GetConfig();
		if (!config)
			return false;

		if (config.ClearsTreesAndBushes() && (obj.IsTree() || obj.IsBush()))
			return true;

		if (config.MatchesModelPrefix(obj.GetShapeName()))
			return true;

		if (config.MatchesModelPrefix(typeName))
			return true;

		return false;
	}

	protected string MakeObjectKey(Object obj)
	{
		if (!obj)
			return string.Empty;

		vector pos = obj.GetPosition();
		string model = obj.GetShapeName();
		return obj.GetType() + "|" + model + "|" + pos[0].ToString() + "|" + pos[2].ToString();
	}

	protected void IncrementEntry(Object obj, string key)
	{
		PlayZBaseClearanceDeletedData deleted = GetDeleted();
		if (!deleted)
			return;

		PlayZBaseClearanceEntry entry = FindEntryByKey(key);
		if (entry)
		{
			entry.RefCount = entry.RefCount + 1;
			return;
		}

		entry = new PlayZBaseClearanceEntry();
		entry.Set(obj.GetType(), obj.GetShapeName(), obj.GetPosition(), 1);
		deleted.Entries.Insert(entry);
	}

	protected void DecrementEntryByKey(string key)
	{
		PlayZBaseClearanceDeletedData deleted = GetDeleted();
		if (!deleted || !deleted.Entries)
			return;

		for (int i = 0; i < deleted.Entries.Count(); ++i)
		{
			PlayZBaseClearanceEntry entry = deleted.Entries.Get(i);
			if (!entry || entry.MakeKey() != key)
				continue;

			entry.RefCount = entry.RefCount - 1;
			if (entry.RefCount > 0)
				return;

			Object obj = FindClearedObject(entry);
			if (obj)
				UnsuppressObject(obj);

			deleted.Entries.Remove(i);
			return;
		}
	}

	protected PlayZBaseClearanceEntry FindEntryByKey(string key)
	{
		PlayZBaseClearanceDeletedData deleted = GetDeleted();
		if (!deleted || !deleted.Entries)
			return null;

		foreach (PlayZBaseClearanceEntry entry : deleted.Entries)
		{
			if (entry && entry.MakeKey() == key)
				return entry;
		}

		return null;
	}

	protected Object FindClearedObject(PlayZBaseClearanceEntry entry)
	{
		if (!entry)
			return null;

		PlayZBaseClearanceConfig config = GetConfig();
		float epsilon = 0.75;
		if (config)
			epsilon = config.FindEpsilonM;

		vector center = entry.GetPosition();
		array<Object> nearest = new array<Object>;
		array<CargoBase> proxy = new array<CargoBase>;
		g_Game.GetObjectsAtPosition(center, Math.Max(2.0, epsilon * 2.0), nearest, proxy);

		Object best;
		float bestDist = 100000.0;

		foreach (Object obj : nearest)
		{
			if (!obj)
				continue;

			bool modelMatch = (entry.Model != string.Empty && obj.GetShapeName() == entry.Model);
			bool typeMatch = (entry.Type != string.Empty && obj.GetType() == entry.Type);
			if (!modelMatch && !typeMatch)
				continue;

			float dist = vector.Distance(Vector(obj.GetPosition()[0], 0, obj.GetPosition()[2]), Vector(center[0], 0, center[2]));
			if (dist > epsilon)
				continue;

			if (dist < bestDist)
			{
				bestDist = dist;
				best = obj;
			}
		}

		return best;
	}

	protected void SuppressObject(Object obj)
	{
		if (!obj || !g_Game)
			return;

		if (!g_Game.GetSuppressedObjectManager())
			return;

		if (g_Game.GetSuppressedObjectManager().IsSuppressed(obj))
			return;

		g_Game.GetSuppressedObjectManager().Suppress(obj);
	}

	protected void UnsuppressObject(Object obj)
	{
		if (!obj || !g_Game)
			return;

		if (!g_Game.GetSuppressedObjectManager())
			return;

		g_Game.GetSuppressedObjectManager().Unsupress(obj);
	}

	protected void ScheduleSave()
	{
		if (m_SaveScheduled)
			return;

		m_SaveScheduled = true;
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(FlushSave, 3000, false);
	}

	void FlushSave()
	{
		m_SaveScheduled = false;

		PlayZBaseClearanceConfig config = GetConfig();
		if (config)
			config.SaveToProfile();

		PlayZBaseClearanceDeletedData deleted = GetDeleted();
		if (deleted)
			deleted.SaveToProfile();
	}
}
