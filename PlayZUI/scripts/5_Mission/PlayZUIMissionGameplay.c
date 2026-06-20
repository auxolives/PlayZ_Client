modded class MissionGameplay
{
	protected void PlayZUpdateRespawnTransitionCurtain(float timeslice)
	{
		Mission mission = g_Game.GetMission();
		bool shouldMaintainCurtain = PlayZDeathScreen_IsTransitionActive();
		if (!shouldMaintainCurtain && mission && mission.IsPlayerRespawning())
		{
			shouldMaintainCurtain = true;
		}

		if (!shouldMaintainCurtain)
		{
			return;
		}

		if (PlayZDeathScreen_IsTransitionActive())
		{
			g_PlayZUIRespawnTransitionElapsed = g_PlayZUIRespawnTransitionElapsed + timeslice;
		}

		PlayZDeathScreen_MaintainTransitionCurtain();

		if (!PlayZDeathScreen_IsTransitionActive())
		{
			return;
		}

		UIScriptedMenu menu = g_Game.GetUIManager().GetMenu();
		if (TerjeStartScreenMenu.Cast(menu))
		{
			PlayZDeathScreen_ScheduleEndTransitionCurtain();
			return;
		}

		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (player && player.IsAlive() && player.m_terjeStartScreenClientReady && menu == null)
		{
			PlayZDeathScreen_EndTransitionCurtain();
			return;
		}

		if (g_PlayZUIRespawnTransitionElapsed >= PlayZUIPaths.RESPAWN_TRANSITION_TIMEOUT_SEC)
		{
			Print("[PlayZUI] Respawn transition curtain timed out after " + PlayZUIPaths.RESPAWN_TRANSITION_TIMEOUT_SEC + "s");
			PlayZDeathScreen_EndTransitionCurtain();
		}
	}

	override void OnUpdate(float timeslice)
	{
		if (PlayZDeathScreen_IsMenuMode() && !PlayZDeathScreen_IsTransitionActive())
		{
			PlayZDeathScreen_MaintainDeathMenuView();
		}

		if (PlayZDeathScreen_IsIntroActive())
		{
			PlayZDeathScreen_SilenceWorldAudio();
		}

		PlayZUpdateRespawnTransitionCurtain(timeslice);

		super.OnUpdate(timeslice);
	}

	override void Pause()
	{
		if (!PlayZDeathScreen_IsTerjeMaintenanceDeath() && PlayZDeathScreen_ShouldBlockPause())
		{
			return;
		}

		super.Pause();
	}

	override void Continue()
	{
		if (!PlayZDeathScreen_IsTerjeMaintenanceDeath() && PlayZDeathScreen_ShouldBlockContinue())
		{
			return;
		}

		super.Continue();
	}

	override void OnPlayerRespawned(Man player)
	{
		super.OnPlayerRespawned(player);
	}
}
