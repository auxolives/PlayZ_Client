modded class MissionGameplay
{
	protected ref PlayZWelcomeMessageOverlay m_PlayZWelcomeMessageOverlay;

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		if (!m_PlayZWelcomeMessageOverlay && !PlayZWelcomeMessageClientState.HasPendingConfig())
		{
			return;
		}

		if (!m_PlayZWelcomeMessageOverlay && PlayZWelcomeMessageClientState.HasPendingConfig())
		{
			if (PlayZWelcomeMessage_ShouldShowOverlay())
			{
				PlayZWelcomeMessageConfig pendingConfig = PlayZWelcomeMessageClientState.ConsumePendingConfig();
				if (pendingConfig)
				{
					m_PlayZWelcomeMessageOverlay = new PlayZWelcomeMessageOverlay(pendingConfig);
				}
			}
		}

		if (m_PlayZWelcomeMessageOverlay)
		{
			m_PlayZWelcomeMessageOverlay.Update(timeslice);

			if (m_PlayZWelcomeMessageOverlay.IsFinished())
			{
				delete m_PlayZWelcomeMessageOverlay;
				m_PlayZWelcomeMessageOverlay = null;
			}
		}
	}

	protected bool PlayZWelcomeMessage_ShouldShowOverlay()
	{
		if (GetGame().GetUIManager().GetMenu())
		{
			return false;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player)
		{
			return false;
		}

		if (player.HasActiveTerjeStartScreen())
		{
			return false;
		}

		return true;
	}
}
