//! Active config on server (after profile load) and client (after RPC sync).
class PlayZNoBuildZonesState
{
	protected static ref PlayZNoBuildZonesConfig m_Config;
	protected static bool m_HasConfig;
	protected static float m_LastNotifyTime;

	static void SetConfig(PlayZNoBuildZonesConfig config)
	{
		m_Config = config;
		m_HasConfig = m_Config != null;
	}

	static bool HasConfig()
	{
		return m_HasConfig && m_Config != null;
	}

	static PlayZNoBuildZonesConfig GetConfig()
	{
		if (!m_HasConfig || !m_Config)
			return null;

		return m_Config;
	}

	static void Clear()
	{
		m_Config = null;
		m_HasConfig = false;
		m_LastNotifyTime = 0;
	}

	static bool IsPositionRestricted(vector pos)
	{
		PlayZNoBuildZonesConfig config = GetConfig();
		if (!config)
			return false;

		return config.IsInside(pos);
	}

	//! Client-only toast; throttled by NotifyCooldownSeconds.
	static void NotifyRestrictedThrottled()
	{
		if (!g_Game.IsClient())
			return;

		PlayZNoBuildZonesConfig config = GetConfig();
		if (!config || !config.IsModEnabled())
			return;

		float now = g_Game.GetTickTime();
		float cooldown = config.NotifyCooldownSeconds;
		if (m_LastNotifyTime > 0 && (now - m_LastNotifyTime) < cooldown)
			return;

		m_LastNotifyTime = now;
		NotificationSystem.AddNotificationExtended(5.0, "#STR_PlayZ_NoBuild_Title", "#STR_PlayZ_NoBuild_Message", "");
	}
}
