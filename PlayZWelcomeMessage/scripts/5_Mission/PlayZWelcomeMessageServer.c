modded class MissionServer
{
	protected ref PlayZWelcomeMessageConfig m_PlayZWelcomeMessageConfig;
	protected ref array<string> m_PlayZWelcomeMessageSentIdentities;

	override void OnInit()
	{
		super.OnInit();
		m_PlayZWelcomeMessageSentIdentities = new array<string>();
		PlayZWelcomeMessage_LoadConfig();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		if (!player || !identity)
		{
			return;
		}

		string identityId = identity.GetId();
		if (identityId == "")
		{
			return;
		}

		PlayZWelcomeMessage_EnsureSessionState();
		if (m_PlayZWelcomeMessageSentIdentities.Find(identityId) > -1)
		{
			return;
		}

		m_PlayZWelcomeMessageSentIdentities.Insert(identityId);

		if (!m_PlayZWelcomeMessageConfig)
		{
			PlayZWelcomeMessage_LoadConfig();
		}

		if (!m_PlayZWelcomeMessageConfig || !m_PlayZWelcomeMessageConfig.Enabled)
		{
			return;
		}

		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayZWelcomeMessage_SendConfig, 5000, false, player, identity);
	}

	override void InvokeOnDisconnect(PlayerBase player)
	{
		string identityId = "";
		if (player && player.GetIdentity())
		{
			identityId = player.GetIdentity().GetId();
		}

		super.InvokeOnDisconnect(player);

		if (identityId == "")
		{
			return;
		}

		PlayZWelcomeMessage_EnsureSessionState();

		int identityIndex = m_PlayZWelcomeMessageSentIdentities.Find(identityId);
		if (identityIndex > -1)
		{
			m_PlayZWelcomeMessageSentIdentities.Remove(identityIndex);
		}
	}

	protected void PlayZWelcomeMessage_SendConfig(PlayerBase player, PlayerIdentity identity)
	{
		if (!player || !identity || !m_PlayZWelcomeMessageConfig)
		{
			return;
		}

		if (!m_PlayZWelcomeMessageConfig.Enabled)
		{
			return;
		}

		GetGame().RPCSingleParam(player, PlayZWelcomeMessageRPCs.SYNC_CONFIG, new Param1<PlayZWelcomeMessageConfig>(m_PlayZWelcomeMessageConfig), true, identity);
	}

	protected void PlayZWelcomeMessage_LoadConfig()
	{
		m_PlayZWelcomeMessageConfig = PlayZWelcomeMessageConfig.LoadFromProfile();
	}

	protected void PlayZWelcomeMessage_EnsureSessionState()
	{
		if (!m_PlayZWelcomeMessageSentIdentities)
		{
			m_PlayZWelcomeMessageSentIdentities = new array<string>();
		}
	}
}
