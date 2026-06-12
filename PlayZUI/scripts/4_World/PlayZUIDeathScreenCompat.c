bool PlayZDeathScreen_IsTerjeMaintenanceDeath()
{
	if (!g_Game || !g_Game.IsClient())
	{
		return false;
	}

	PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
	if (!player)
	{
		return false;
	}

	if (!player.m_terjeStartScreenClientReady)
	{
		return true;
	}

	if (player.HasActiveTerjeStartScreen())
	{
		return true;
	}

	if (player.GetTerjeMaintenanceMode())
	{
		return true;
	}

	return false;
}

bool PlayZDeathScreen_ShouldUseCustomFlow()
{
	if (!g_Game || !g_Game.IsClient())
	{
		return false;
	}

	if (PlayZDeathScreen_IsTerjeMaintenanceDeath())
	{
		return false;
	}

	return true;
}
