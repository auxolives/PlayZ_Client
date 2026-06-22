modded class MissionServer
{
	protected ref PlayZNotificationConfig m_PlayZNotificationConfig;

	override void OnInit()
	{
		super.OnInit();
		PlayZNotification_LoadConfig();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		if (!player || !identity)
		{
			return;
		}

		PlayZNotification_LoadConfig();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayZNotification_SendConfig, 500, false, player, identity);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayZNotification_SendConfig, 2500, false, player, identity);
	}

	protected void PlayZNotification_LoadConfig()
	{
		m_PlayZNotificationConfig = PlayZNotificationConfig.LoadFromProfile();
	}

	protected void PlayZNotification_SendConfig(PlayerBase player, PlayerIdentity identity)
	{
		if (!player || !identity)
		{
			return;
		}

		if (!m_PlayZNotificationConfig)
		{
			PlayZNotification_LoadConfig();
		}

		if (!m_PlayZNotificationConfig)
		{
			return;
		}

		GetGame().RPCSingleParam(player, PlayZNotificationRPCs.SYNC_CONFIG, new Param1<PlayZNotificationConfig>(m_PlayZNotificationConfig), true, identity);
	}
}
