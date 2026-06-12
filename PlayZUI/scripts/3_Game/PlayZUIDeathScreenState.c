bool g_PlayZDeathIntroActive;
bool g_PlayZDeathMenuMode;

void PlayZDeathScreen_SetIntroActive(bool active)
{
	g_PlayZDeathIntroActive = active;
}

bool PlayZDeathScreen_IsIntroActive()
{
	return g_PlayZDeathIntroActive;
}

void PlayZDeathScreen_SetMenuMode(bool active)
{
	g_PlayZDeathMenuMode = active;
}

bool PlayZDeathScreen_IsMenuMode()
{
	return g_PlayZDeathMenuMode;
}

bool PlayZDeathScreen_IsCustomDeathActive()
{
	if (!g_Game || !g_Game.IsClient())
	{
		return false;
	}

	return g_PlayZDeathIntroActive || g_PlayZDeathMenuMode;
}

void PlayZDeathScreen_SilenceWorldAudio()
{
	if (!g_Game)
	{
		return;
	}

	AbstractSoundScene scene = g_Game.GetSoundScene();
	scene.SetSoundVolume(0, 0);
	scene.SetSpeechExVolume(0, 0);
	scene.SetVOIPVolume(0, 0);
	scene.SetRadioVolume(0, 0);
}

void PlayZDeathScreen_StopDynamicMusic()
{
	if (!g_Game)
	{
		return;
	}

	Mission mission = g_Game.GetMission();
	if (!mission)
	{
		return;
	}

	DynamicMusicPlayer musicPlayer = mission.GetDynamicMusicPlayer();
	if (musicPlayer)
	{
		musicPlayer.SetCategory(EDynamicMusicPlayerCategory.NONE, true);
	}
}

void PlayZDeathScreen_Reset()
{
	PlayZDeathScreen_StopBlackout();
	g_PlayZDeathIntroActive = false;
	g_PlayZDeathMenuMode = false;
}

void PlayZDeathScreen_StopBlackout()
{
	if (!g_Game)
	{
		return;
	}

	PPERequesterBank.GetRequester(PPERequester_DeathDarkening).Stop();
}

void PlayZDeathScreen_ClearEngineFade()
{
	if (!g_Game)
	{
		return;
	}

	UIManager ui = g_Game.GetUIManager();
	if (ui && ui.ScreenFadeVisible())
	{
		ui.ScreenFadeOut(0);
	}
}

void PlayZDeathScreen_MaintainDeathMenuView()
{
	PlayZDeathScreen_StopBlackout();
	PlayZDeathScreen_ClearEngineFade();
}

void PlayZDeathScreen_BeginBlackout()
{
	if (!g_Game || !g_Game.IsClient())
	{
		return;
	}

	PlayZDeathScreen_StopBlackout();
	PlayZDeathScreen_StopDynamicMusic();
	PlayZDeathScreen_SilenceWorldAudio();

	UIManager ui = g_Game.GetUIManager();
	if (ui)
	{
		ui.ScreenFadeOut(0);
		ui.ScreenFadeIn(0, " ", FadeColors.BLACK, FadeColors.WHITE);
	}
}

bool PlayZDeathScreen_ShouldBlockPause()
{
	if (g_PlayZDeathIntroActive)
	{
		return true;
	}

	if (!g_Game)
	{
		return false;
	}

	Man player = g_Game.GetPlayer();
	if (player && !player.IsAlive())
	{
		return true;
	}

	return false;
}

bool PlayZDeathScreen_ShouldBlockContinue()
{
	if (!g_Game)
	{
		return false;
	}

	Man player = g_Game.GetPlayer();
	if (player && !player.IsAlive())
	{
		return true;
	}

	return false;
}

void PlayZDeathScreen_OpenMenu()
{
	if (!g_Game || !g_Game.IsClient())
	{
		return;
	}

	Man player = g_Game.GetPlayer();
	if (!player || player.IsAlive())
	{
		PlayZDeathScreen_Reset();
		return;
	}

	if (g_Game.GetUIManager().IsMenuOpen(MENU_INGAME))
	{
		return;
	}

	PlayZDeathScreen_SetMenuMode(true);
	g_Game.GetUIManager().EnterScriptedMenu(MENU_INGAME, null);
}
