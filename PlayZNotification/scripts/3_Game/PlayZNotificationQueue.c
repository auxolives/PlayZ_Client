class PlayZNotificationQueue
{
	protected static ref PlayZNotificationQueue s_Instance;

	protected ref array<ref PlayZNotificationEntry> m_Queue;
	protected ref array<ref NotificationRuntimeData> m_PendingUntilConfig;

	protected static const int PENDING_CAP = 5;

	void PlayZNotificationQueue()
	{
		m_Queue = new array<ref PlayZNotificationEntry>();
		m_PendingUntilConfig = new array<ref NotificationRuntimeData>();
	}

	static PlayZNotificationQueue Get()
	{
		if (!s_Instance)
		{
			s_Instance = new PlayZNotificationQueue();
		}

		return s_Instance;
	}

	int Count()
	{
		return m_Queue.Count();
	}

	bool IsEmpty()
	{
		return m_Queue.Count() == 0;
	}

	PlayZNotificationEntry Peek()
	{
		if (m_Queue.Count() == 0)
		{
			return null;
		}

		return m_Queue.Get(0);
	}

	PlayZNotificationEntry Dequeue()
	{
		if (m_Queue.Count() == 0)
		{
			return null;
		}

		PlayZNotificationEntry entry = m_Queue.Get(0);
		m_Queue.RemoveOrdered(0);
		return entry;
	}

	void Enqueue(PlayZNotificationEntry entry)
	{
		if (!entry)
		{
			return;
		}

		PlayZNotificationConfig config = PlayZNotificationClientState.GetConfig();
		if (!config)
		{
			return;
		}

		if (!entry.HasVisibleContent(config.UsesShowTitle(), config.UsesShowMessage()))
		{
			return;
		}

		while (m_Queue.Count() >= config.MaxQueueSize)
		{
			m_Queue.RemoveOrdered(0);
		}

		m_Queue.Insert(entry);
	}

	void EnqueuePending(NotificationRuntimeData data)
	{
		if (!data)
		{
			return;
		}

		while (m_PendingUntilConfig.Count() >= PENDING_CAP)
		{
			m_PendingUntilConfig.RemoveOrdered(0);
		}

		m_PendingUntilConfig.Insert(data);
	}

	void FlushPending()
	{
		if (!PlayZNotificationClientState.HasConfig())
		{
			return;
		}

		if (!PlayZNotificationConfig.IsEnabled())
		{
			m_PendingUntilConfig.Clear();
			return;
		}

		for (int i = 0; i < m_PendingUntilConfig.Count(); i++)
		{
			NotificationRuntimeData pending = m_PendingUntilConfig.Get(i);
			if (!pending)
			{
				continue;
			}

			if (IsKillfeedNotification(pending))
			{
				continue;
			}

			PlayZNotificationEntry entry = Normalize(pending);
			if (entry)
			{
				Enqueue(entry);
			}
		}

		m_PendingUntilConfig.Clear();
	}

	void ClearPending()
	{
		m_PendingUntilConfig.Clear();
	}

	void PurgeStaleBlocked(float nowMs)
	{
		PlayZNotificationConfig config = PlayZNotificationClientState.GetConfig();
		if (!config)
		{
			return;
		}

		float staleMs = config.BlockedQueueStaleSeconds * 1000.0;

		for (int i = m_Queue.Count() - 1; i >= 0; i--)
		{
			PlayZNotificationEntry entry = m_Queue.Get(i);
			if (!entry)
			{
				m_Queue.RemoveOrdered(i);
				continue;
			}

			if ((nowMs - entry.EnqueuedAtMs) > staleMs)
			{
				m_Queue.RemoveOrdered(i);
			}
		}
	}

	static PlayZNotificationEntry Normalize(NotificationRuntimeData data)
	{
		if (!data)
		{
			return null;
		}

		PlayZNotificationConfig config = PlayZNotificationClientState.GetConfig();
		if (!config)
		{
			return null;
		}

		string title = ResolveTextKey(data.GetTitleText());
		string message = ResolveTextKey(data.GetDetailText());
		message = FormatSkillLevelUpMessage(message);

		if (config.UsesShowTitle() && IsPlaceholderTitle(title))
		{
			title = "";
		}

		if (title != "" && message != "" && title == message)
		{
			if (config.UsesShowMessage())
			{
				title = "";
			}
			else
			{
				message = "";
			}
		}

		float holdSeconds = config.FixedHoldSeconds;
		if (config.UsesPayloadDuration())
		{
			holdSeconds = data.GetTime() - NotificationSystem.NOTIFICATION_FADE_TIME;
		}

		holdSeconds = Math.Clamp(holdSeconds, config.MinHoldSeconds, config.MaxHoldSeconds);

		float nowMs = GetGame().GetTickTime() * 1000.0;
		return new PlayZNotificationEntry(title, message, holdSeconds, nowMs);
	}

	static bool IsKillfeedNotification(NotificationRuntimeData data)
	{
		if (!data)
		{
			return false;
		}

		int notifType = 0;
		if (EnScript.GetClassVar(data, "m_Type", 0, notifType))
		{
			if (notifType == 8)
			{
				return true;
			}
		}

		string title = data.GetTitleText();
		if (title == "#STR_EXPANSION_KILLFEED_TITLE")
		{
			return true;
		}

		if (title == "STR_EXPANSION_KILLFEED_TITLE")
		{
			return true;
		}

		string killfeedLabel = Widget.TranslateString("#STR_EXPANSION_KILLFEED_TITLE");
		if (title == killfeedLabel)
		{
			return true;
		}

		return false;
	}

	static bool IsPlaceholderTitle(string title)
	{
		if (title == "")
		{
			return true;
		}

		string trimmed = title;
		trimmed.TrimInPlace();

		if (trimmed == "")
		{
			return true;
		}

		if (trimmed == "...")
		{
			return true;
		}

		if (trimmed == "..")
		{
			return true;
		}

		if (trimmed == "…")
		{
			return true;
		}

		return false;
	}

	static string FormatSkillLevelUpMessage(string message)
	{
		if (message == "")
		{
			return message;
		}

		int colonIndex = message.LastIndexOf(": ");
		if (colonIndex < 0)
		{
			return message;
		}

		string skillKey = message.Substring(0, colonIndex);
		string level = message.Substring(colonIndex + 2, message.Length() - colonIndex - 2);

		if (skillKey.IndexOf("STR_TERJESKILL_") < 0 || skillKey.IndexOf("_NAME") < 0)
		{
			return message;
		}

		skillKey = ResolveTextKey(skillKey);
		return Widget.TranslateString(skillKey) + ": " + level;
	}

	static string ResolveTextKey(string key)
	{
		if (key == "")
		{
			return "";
		}

		if (key.Substring(0, 1) == "#")
		{
			return key;
		}

		return "#" + key;
	}
}
