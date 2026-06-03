modded class MissionServer
{
	private ref map<PlayerBase, bool> m_PlayZLogoutQueueCombatInitial;

	override void OnInit()
	{
		super.OnInit();
		PlayZCoreConfig.GetInstance();
		PlayZAntiCombatLogConfig.Get();
		m_PlayZLogoutQueueCombatInitial = new map<PlayerBase, bool>;
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		PlayZCoreConfig.SyncConfig(identity);
	}

	protected bool PlayZ_ShouldForceInstantLogoutForKickReason(int kickReason)
	{
		if (kickReason == EClientKicked.KICK_ALL_ADMIN)
		{
			return true;
		}
		if (kickReason == EClientKicked.KICK_ALL_SERVER)
		{
			return true;
		}
		if (kickReason == EClientKicked.TIMEOUT)
		{
			return true;
		}
		if (kickReason == EClientKicked.KICK)
		{
			return true;
		}
		if (kickReason == EClientKicked.BAN)
		{
			return true;
		}
		if (kickReason == EClientKicked.PING)
		{
			return true;
		}
		if (kickReason == EClientKicked.UNSTABLE_NETWORK)
		{
			return true;
		}
		if (kickReason == EClientKicked.SERVER_SHUTDOWN)
		{
			return true;
		}
		if (kickReason == EClientKicked.ADMIN_KICK)
		{
			return true;
		}
		if (kickReason == EClientKicked.BATTLEYE)
		{
			return true;
		}
		return false;
	}

	override void OnClientDisconnectedEvent(PlayerIdentity identity, PlayerBase player, int logoutTime, bool authFailed)
	{
		int origTime = logoutTime;

		if (!authFailed && player)
		{
			int kickReason = player.GetKickOffReason();
			if (PlayZ_ShouldForceInstantLogoutForKickReason(kickReason))
			{
				player.ResetCombatLogTimer();
				logoutTime = 0;
			}
		}

		if (GetGame() && player && player.GetCombatLogTimer() > 0 && player.IsAlive())
		{
			if (GetGame().GetTime() > player.GetCombatLogTimer())
			{
				player.ResetCombatLogTimer();
			}
			else
			{
				int combatLogoutSecs = (player.GetCombatLogTimer() - GetGame().GetTime()) / 1000;
				if (combatLogoutSecs > logoutTime)
				{
					logoutTime = combatLogoutSecs;
				}
			}
		}

		super.OnClientDisconnectedEvent(identity, player, logoutTime, authFailed);
	}

	override void OnEvent(EventType eventTypeId, Param params)
	{
		super.OnEvent(eventTypeId, params);

		PlayerIdentity identity;
		PlayerBase player;
		PlayZAntiCombatLogConfig cfg = PlayZAntiCombatLogConfig.Get();

		if (eventTypeId == ClientDisconnectedEventTypeID)
		{
			ClientDisconnectedEventParams discoParams;
			Class.CastTo(discoParams, params);

			identity = discoParams.param1;
			player = PlayerBase.Cast(discoParams.param2);
			bool logoutTimeExpired = PlayZ_IsCombatLogoutTimeExpired(player);

			if (player && (!m_PlayZLogoutQueueCombatInitial.Get(player) || !m_PlayZLogoutQueueCombatInitial.Contains(player)))
			{
				m_PlayZLogoutQueueCombatInitial.Insert(player, true);

				if (player.IsAlive() && cfg.NotifyPlayerOfPenalty)
				{
					if (logoutTimeExpired)
					{
						player.InformPlayerOfCombatLogout(0);
					}
					else
					{
						if (cfg.KillPlayer > 0)
						{
							player.InformPlayerOfCombatLogout(1);
						}
						else
						{
							if (cfg.DropFlareOnPlayer == 1)
							{
								player.InformPlayerOfCombatLogout(2);
							}
							else
							{
								player.InformPlayerOfCombatLogout(3);
							}
						}
					}
				}
			}
			else
			{
				if (!logoutTimeExpired)
				{
					if (player)
					{
						m_PlayZLogoutQueueCombatInitial.Remove(player);

						if (player.IsAlive())
						{
							if (cfg.DropFlareOnPlayer == 1)
							{
								PlayZ_CombatLogFlare flare = PlayZ_CombatLogFlare.Cast(GetGame().CreateObjectEx("PlayZ_CombatLogFlare", player.GetPosition(), ECE_PLACE_ON_SURFACE));
								if (flare)
								{
									flare.SetOrientation(player.GetOrientation());
								}
							}

							if (cfg.KillPlayer == 2)
							{
								player.SetHealth(0);
							}
						}
					}
				}
			}
		}
		else
		{
			if (eventTypeId == LogoutCancelEventTypeID)
			{
				LogoutCancelEventParams logoutCancelParams;
				Class.CastTo(logoutCancelParams, params);
				Class.CastTo(player, logoutCancelParams.param1);

				if (player)
				{
					m_PlayZLogoutQueueCombatInitial.Remove(player);
				}
			}
		}
	}

	override void InvokeOnDisconnect(PlayerBase player)
	{
		super.InvokeOnDisconnect(player);

		if (player)
		{
			m_PlayZLogoutQueueCombatInitial.Remove(player);
		}
	}

	bool PlayZ_IsCombatLogoutTimeExpired(PlayerBase player)
	{
		if (!player)
		{
			return true;
		}

		if (player.GetCombatLogTimer() == 0)
		{
			return true;
		}

		LogoutInfo logoutParams = m_LogoutPlayers.Get(player);
		if (!logoutParams)
		{
			logoutParams = m_NewLogoutPlayers.Get(player);
		}

		if (logoutParams && GetGame().GetTime() > logoutParams.param1)
		{
			return true;
		}

		return false;
	}

	override bool ShouldPlayerBeKilled(PlayerBase player)
	{
		bool killPlayer = super.ShouldPlayerBeKilled(player);

		if (killPlayer)
		{
			return true;
		}

		if (player.WillBePunishedForCombatLogging() == 1 && !PlayZ_IsCombatLogoutTimeExpired(player))
		{
			switch (player.GetKickOffReason())
			{
				case EClientKicked.SERVER_EXIT:
					killPlayer = false;
					break;
				case EClientKicked.KICK_ALL_ADMIN:
					killPlayer = false;
					break;
				case EClientKicked.KICK_ALL_SERVER:
					killPlayer = false;
					break;
				case EClientKicked.SERVER_SHUTDOWN:
					killPlayer = false;
					break;
				default:
					killPlayer = true;
			}
		}

		PlayZAntiCombatLogConfig cfg = PlayZAntiCombatLogConfig.Get();
		if (killPlayer && player.IsAlive() && cfg.DropFlareOnPlayer == 2)
		{
			PlayZ_CombatLogFlare flare = PlayZ_CombatLogFlare.Cast(GetGame().CreateObjectEx("PlayZ_CombatLogFlare", player.GetPosition(), ECE_PLACE_ON_SURFACE));
			if (flare)
			{
				flare.SetOrientation(player.GetOrientation());
			}
		}

		if (player && player.GetIdentity() && killPlayer)
		{
			Print("[PlayZCore] Player " + player.GetCachedID() + " killed for combat logging.");
		}

		return killPlayer;
	}
}
