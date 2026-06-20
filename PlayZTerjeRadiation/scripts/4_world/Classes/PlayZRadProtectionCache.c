//! Per-player cache for Terje CalculatePlayerBodyProtection (Phase 3 perf).
class PlayZRadProtectionCacheEntry
{
	string m_ProtectionType;
	float m_Power;
	string m_Fingerprint;
	float m_Result;
	int m_TimeMs;
}

class PlayZRadProtectionCache
{
	static const float TTL_MS = 400.0;

	protected ref map<PlayerBase, ref PlayZRadProtectionCacheEntry> m_Entries;

	void Invalidate(PlayerBase player)
	{
		if (!player || !m_Entries)
		{
			return;
		}

		m_Entries.Remove(player);
	}

	float GetCached(PlayerBase player, string protectionType, float power, string fingerprint, out bool hit)
	{
		hit = false;
		if (!player || !m_Entries)
		{
			return 0;
		}

		PlayZRadProtectionCacheEntry entry;
		if (!m_Entries.Find(player, entry) || !entry)
		{
			return 0;
		}

		int now = GetGame().GetTime();
		if (entry.m_ProtectionType != protectionType)
		{
			return 0;
		}

		if (Math.AbsFloat(entry.m_Power - power) > 0.0001)
		{
			return 0;
		}

		if (entry.m_Fingerprint != fingerprint)
		{
			return 0;
		}

		if ((now - entry.m_TimeMs) >= TTL_MS)
		{
			return 0;
		}

		hit = true;
		return entry.m_Result;
	}

	void Store(PlayerBase player, string protectionType, float power, string fingerprint, float result)
	{
		if (!player)
		{
			return;
		}

		if (!m_Entries)
		{
			m_Entries = new map<PlayerBase, ref PlayZRadProtectionCacheEntry>();
		}

		PlayZRadProtectionCacheEntry entry = new PlayZRadProtectionCacheEntry();
		entry.m_ProtectionType = protectionType;
		entry.m_Power = power;
		entry.m_Fingerprint = fingerprint;
		entry.m_Result = result;
		entry.m_TimeMs = GetGame().GetTime();
		m_Entries.Set(player, entry);
	}

	static string BuildFingerprint(PlayerBase player)
	{
		if (!player)
		{
			return "";
		}

		string fp = "";
		fp = PlayZRadProtectionCache.AppendSlot(fp, player, InventorySlots.FEET);
		fp = PlayZRadProtectionCache.AppendSlot(fp, player, InventorySlots.LEGS);
		fp = PlayZRadProtectionCache.AppendSlot(fp, player, InventorySlots.BODY);
		fp = PlayZRadProtectionCache.AppendSlot(fp, player, InventorySlots.GLOVES);
		fp = PlayZRadProtectionCache.AppendSlot(fp, player, InventorySlots.HEADGEAR);
		fp = PlayZRadProtectionCache.AppendSlot(fp, player, InventorySlots.ARMBAND);
		fp = PlayZRadProtectionCache.AppendSlot(fp, player, InventorySlots.BACK);
		fp = PlayZRadProtectionCache.AppendSlot(fp, player, InventorySlots.MASK);
		fp = PlayZRadProtectionCache.AppendSlot(fp, player, InventorySlots.EYEWEAR);
		return fp;
	}

	protected static string AppendSlot(string fp, PlayerBase player, int slot)
	{
		ItemBase item = ItemBase.Cast(player.GetInventory().FindAttachment(slot));
		if (!item)
		{
			return fp + "|0";
		}

		fp = fp + "|" + item.GetType() + ":" + item.GetHealthLevel();

		MaskBase mask = MaskBase.Cast(item);
		if (mask)
		{
			ItemBase filter = ItemBase.Cast(mask.GetExternalFilter());
			if (filter)
			{
				fp = fp + "+f" + filter.GetType() + ":" + filter.GetHealthLevel();
			}
		}

		return fp;
	}
}
