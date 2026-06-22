class PlayZNotificationManager
{
	protected static ref PlayZNotificationManager s_Instance;

	protected ref PlayZNotificationOverlay m_ActiveOverlay;

	void PlayZNotificationManager()
	{
	}

	static PlayZNotificationManager Get()
	{
		if (!s_Instance)
		{
			s_Instance = new PlayZNotificationManager();
		}

		return s_Instance;
	}

	void Update(float timeslice)
	{
		if (GetGame().IsDedicatedServer())
		{
			return;
		}

		if (!PlayZNotificationClientState.HasConfig())
		{
			return;
		}

		if (!PlayZNotificationConfig.IsEnabled())
		{
			return;
		}

		float nowMs = GetGame().GetTickTime() * 1000.0;
		PlayZNotificationQueue queue = PlayZNotificationQueue.Get();

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		bool toastReady = PlayZMissionClientGate.IsToastReady(player);

		if (!toastReady)
		{
			queue.PurgeStaleBlocked(nowMs);
		}

		if (m_ActiveOverlay)
		{
			m_ActiveOverlay.Update(timeslice);

			if (m_ActiveOverlay.IsFinished())
			{
				delete m_ActiveOverlay;
				m_ActiveOverlay = null;
			}
		}

		if (m_ActiveOverlay)
		{
			return;
		}

		if (!toastReady)
		{
			return;
		}

		if (queue.IsEmpty())
		{
			return;
		}

		PlayZNotificationConfig config = PlayZNotificationClientState.GetConfig();
		if (!config)
		{
			return;
		}

		while (!queue.IsEmpty())
		{
			PlayZNotificationEntry entry = queue.Dequeue();
			if (!entry)
			{
				continue;
			}

			if (!entry.HasVisibleContent(config.UsesShowTitle(), config.UsesShowMessage()))
			{
				continue;
			}

			m_ActiveOverlay = new PlayZNotificationOverlay(entry, config);
			return;
		}
	}
}
