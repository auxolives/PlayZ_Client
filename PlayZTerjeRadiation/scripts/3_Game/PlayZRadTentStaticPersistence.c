class PlayZRadTentStaticAttachmentState
{
	string slot;
	string type;
	float health;
	float quantity;
	float temperature;
	string terjeLiquid;
}

class PlayZRadTentStaticEntry
{
	string id;
	ref array<ref PlayZRadTentStaticAttachmentState> attachments;

	void PlayZRadTentStaticEntry()
	{
		attachments = new array<ref PlayZRadTentStaticAttachmentState>();
	}
}

class PlayZRadTentStaticStateFile
{
	ref array<ref PlayZRadTentStaticEntry> entries;

	void PlayZRadTentStaticStateFile()
	{
		entries = new array<ref PlayZRadTentStaticEntry>();
	}
}

class PlayZRadTentStaticPersistence
{
	static const string PROFILE_PATH = "$profile:PlayZ/RadTentStatic.json";
	static const float SAVE_DEBOUNCE_SEC = 5.0;

	protected static ref map<string, ref PlayZRadTentStaticEntry> s_Entries;
	protected static bool s_Dirty;
	protected static bool s_SaveScheduled;

	static void Load()
	{
		if (!GetGame() || !GetGame().IsServer())
			return;

		if (!s_Entries)
			s_Entries = new map<string, ref PlayZRadTentStaticEntry>();
		else
			s_Entries.Clear();

		if (!FileExist(PROFILE_PATH))
		{
			s_Dirty = false;
			return;
		}

		ref PlayZRadTentStaticStateFile fileData = new PlayZRadTentStaticStateFile();
		JsonFileLoader<PlayZRadTentStaticStateFile>.JsonLoadFile(PROFILE_PATH, fileData);

		if (fileData && fileData.entries)
		{
			foreach (ref PlayZRadTentStaticEntry entry : fileData.entries)
			{
				if (!entry || entry.id == string.Empty)
					continue;

				s_Entries.Set(entry.id, entry);
			}
		}

		s_Dirty = false;
	}

	static void Shutdown()
	{
		if (!GetGame() || !GetGame().IsServer())
			return;

		if (s_Dirty)
			SaveNow();
	}

	static PlayZRadTentStaticEntry GetEntry(string id)
	{
		if (!s_Entries || id == string.Empty)
			return null;

		return s_Entries.Get(id);
	}

	static void SetEntry(string id, array<ref PlayZRadTentStaticAttachmentState> attachments)
	{
		if (!GetGame() || !GetGame().IsServer())
			return;

		if (id == string.Empty)
			return;

		if (!s_Entries)
			s_Entries = new map<string, ref PlayZRadTentStaticEntry>();

		ref PlayZRadTentStaticEntry entry = s_Entries.Get(id);
		if (!entry)
		{
			entry = new PlayZRadTentStaticEntry();
			entry.id = id;
			s_Entries.Set(id, entry);
		}

		entry.attachments.Clear();
		if (attachments)
		{
			foreach (ref PlayZRadTentStaticAttachmentState attState : attachments)
			{
				if (attState)
					entry.attachments.Insert(attState);
			}
		}

		ScheduleSave();
	}

	static void ScheduleSave()
	{
		if (!GetGame() || !GetGame().IsServer())
			return;

		s_Dirty = true;

		if (s_SaveScheduled)
			return;

		s_SaveScheduled = true;
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SaveNowDebounced, SAVE_DEBOUNCE_SEC * 1000, false);
	}

	protected static void SaveNowDebounced()
	{
		s_SaveScheduled = false;
		if (s_Dirty)
			SaveNow();
	}

	protected static void SaveNow()
	{
		if (!s_Entries)
			return;

		if (!FileExist(PlayZRadiationConfig.CONFIG_ROOT))
			MakeDirectory(PlayZRadiationConfig.CONFIG_ROOT);

		ref PlayZRadTentStaticStateFile fileData = new PlayZRadTentStaticStateFile();
		foreach (string entryId, ref PlayZRadTentStaticEntry entry : s_Entries)
		{
			if (entry)
				fileData.entries.Insert(entry);
		}

		JsonFileLoader<PlayZRadTentStaticStateFile>.JsonSaveFile(PROFILE_PATH, fileData);
		s_Dirty = false;
	}
}
