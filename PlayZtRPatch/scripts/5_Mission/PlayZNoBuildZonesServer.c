modded class MissionServer
{
	protected ref PlayZNoBuildZonesConfig m_PlayZNoBuildZonesConfig;

	override void OnInit()
	{
		super.OnInit();
		PlayZNoBuildZones_LoadConfig();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		if (!player || !identity)
			return;

		PlayZNoBuildZones_LoadConfig();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayZNoBuildZones_SendConfig, 500, false, player, identity);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayZNoBuildZones_SendConfig, 2500, false, player, identity);
	}

	protected void PlayZNoBuildZones_LoadConfig()
	{
		m_PlayZNoBuildZonesConfig = PlayZNoBuildZonesConfig.LoadFromProfile();
		PlayZNoBuildZonesState.SetConfig(m_PlayZNoBuildZonesConfig);
	}

	protected void PlayZNoBuildZones_SendConfig(PlayerBase player, PlayerIdentity identity)
	{
		if (!player || !identity)
			return;

		if (!m_PlayZNoBuildZonesConfig)
			PlayZNoBuildZones_LoadConfig();

		if (!m_PlayZNoBuildZonesConfig)
			return;

		GetGame().RPCSingleParam(player, PlayZNoBuildZonesRPCs.SYNC_CONFIG, new Param1<PlayZNoBuildZonesConfig>(m_PlayZNoBuildZonesConfig), true, identity);
	}
}
