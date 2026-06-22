class PlayZNotificationClientState
{
	protected static ref PlayZNotificationConfig m_Config;
	protected static bool m_HasConfig;

	static void SetConfig(PlayZNotificationConfig config)
	{
		m_Config = config;
		m_HasConfig = m_Config != null;

		if (m_HasConfig)
		{
			PlayZNotificationQueue.Get().FlushPending();
		}
	}

	static bool HasConfig()
	{
		return m_HasConfig && m_Config != null;
	}

	static PlayZNotificationConfig GetConfig()
	{
		if (!m_HasConfig || !m_Config)
		{
			return null;
		}

		return m_Config;
	}

	static void Clear()
	{
		m_Config = null;
		m_HasConfig = false;
		PlayZNotificationQueue.Get().ClearPending();
	}
}
