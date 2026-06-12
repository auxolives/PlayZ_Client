modded class DayZPlayerImplement
{
	override void StopDeathDarkeningEffect()
	{
		if (m_DeathEffectTimer)
		{
			m_DeathEffectTimer.Stop();
			m_DeathEffectTimer = null;
		}

		PlayZDeathScreen_StopBlackout();
	}

	override void SimulateDeath(bool state)
	{
		if (state && PlayZDeathScreen_ShouldUseCustomFlow())
		{
			if (PlayZDeathScreen_IsCustomDeathActive())
			{
				return;
			}

			if (g_Game.GetMissionState() != DayZGame.MISSION_STATE_GAME)
			{
				return;
			}

			StopDeathDarkeningEffect();
			LockControls(state);
			ShowDeadScreen(state, 0);

			g_Game.GetSoundScene().SetSoundVolume(0, 0);
			g_Game.GetSoundScene().SetSpeechExVolume(0, 0);
			g_Game.GetSoundScene().SetMusicVolume(0, 0);
			g_Game.GetSoundScene().SetVOIPVolume(0, 0);
			g_Game.GetSoundScene().SetRadioVolume(0, 0);
			return;
		}

		super.SimulateDeath(state);
	}

	override void ShowDeadScreen(bool show, float duration)
	{
		#ifndef NO_GUI
		if (show && IsPlayerSelected())
		{
			if (!PlayZDeathScreen_ShouldUseCustomFlow())
			{
				super.ShowDeadScreen(show, duration);
				return;
			}

			if (PlayZDeathScreen_IsCustomDeathActive())
			{
				return;
			}

			StopDeathDarkeningEffect();

			PlayZDeathScreen_SetIntroActive(true);
			PlayZDeathScreen_SetMenuMode(false);

			g_Game.GetCallQueue(CALL_CATEGORY_GUI).Call(PlayZDeathScreen_BeginBlackout);

			int holdMs = (int)(PlayZUIPaths.DEATH_BLACK_HOLD_SEC * 1000);
			g_Game.GetCallQueue(CALL_CATEGORY_GUI).CallLater(PlayZDeathScreen_OpenMenu, holdMs, false);
			return;
		}

		StopDeathDarkeningEffect();
		PlayZDeathScreen_Reset();
		super.ShowDeadScreen(show, duration);
		#endif
	}
}
