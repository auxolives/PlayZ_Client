modded class InGameMenu
{
	protected bool m_PlayZDeathMode;
	protected bool m_PlayZDeathRevealActive;
	protected float m_PlayZDeathPictureCoverLevel;
	protected float m_PlayZDeathButtonsCoverLevel;
	protected float m_PlayZDeathRevealElapsed;
	protected float m_PlayZDeathRevealTimerSlice;
	protected ImageWidget m_PlayZDeathBackground;
	protected Widget m_PlayZDeathPictureCover;
	protected Widget m_PlayZDeathButtonsCover;
	protected Widget m_WebsiteButton;
	protected Widget m_DiscordButton;
	protected Widget m_StatisticsButton;
	protected bool m_PlayZDeathStatsButtonResolved;

	protected void PlayZBindInGameMenuWidgets()
	{
		m_ContinueButton = layoutRoot.FindAnyWidget("continuebtn");
		m_SeparatorPanel = layoutRoot.FindAnyWidget("separator_red");
		m_ExitButton = layoutRoot.FindAnyWidget("exitbtn");
		m_RestartButton = layoutRoot.FindAnyWidget("restartbtn");
		m_RespawnButton = layoutRoot.FindAnyWidget("respawn_button");
		m_RestartDeadRandomButton = layoutRoot.FindAnyWidget("respawn_button_random");
		m_RestartDeadCustomButton = layoutRoot.FindAnyWidget("respawn_button_custom");
		m_OptionsButton = layoutRoot.FindAnyWidget("optionsbtn");
		m_ModdedWarning = TextWidget.Cast(layoutRoot.FindAnyWidget("ModdedWarning"));
		m_FeedbackButton = layoutRoot.FindAnyWidget("feedbackbtn");
		m_WebsiteButton = layoutRoot.FindAnyWidget("websitebtn");
		m_DiscordButton = layoutRoot.FindAnyWidget("discordbtn");
		m_HintPanel = null;
	}

	protected void PlayZBindDeathMenuWidgets()
	{
		m_ExitButton = layoutRoot.FindAnyWidget("exitbtn");
		m_RespawnButton = layoutRoot.FindAnyWidget("respawn_button");
		m_StatisticsButton = layoutRoot.FindAnyWidget("statistics_button");
		m_ContinueButton = null;
		m_SeparatorPanel = null;
		m_RestartButton = null;
		m_RestartDeadRandomButton = null;
		m_RestartDeadCustomButton = null;
		m_OptionsButton = null;
		m_ModdedWarning = null;
		m_FeedbackButton = null;
		m_WebsiteButton = null;
		m_DiscordButton = null;
		m_HintPanel = null;
	}

	protected void PlayZInitPauseOverlays()
	{
		m_Logo = ImageWidget.Cast(layoutRoot.FindAnyWidget("dayz_logo"));

		m_Licensing = WrapSpacerWidget.Cast(layoutRoot.FindAnyWidget("Licensing"));
		if (m_Licensing)
		{
			m_Licensing.Show(true);

			Widget version = m_Licensing.FindAnyWidget("version");
			if (version)
			{
				version.Show(true);
			}

			Widget copyright = m_Licensing.FindAnyWidget("copyright");
			if (copyright)
			{
				copyright.Show(true);
			}
		}

		m_NewsFeed = new ExpansionNewsFeed();
		Widget newsFeedRoot = m_NewsFeed.GetLayoutRoot();
		if (newsFeedRoot)
		{
			layoutRoot.AddChild(newsFeedRoot, true);
			newsFeedRoot.Show(false);
		}

		if (GetExpansionSettings().GetGeneral(false).IsLoaded())
		{
			Expansion_OnGeneralSettingsUpdated();
		}
	}

	protected Widget PlayZInitPauseMenu()
	{
		layoutRoot = g_Game.GetWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_INGAME);
		PlayZBindInGameMenuWidgets();

		if (g_Game.IsMultiplayer())
		{
			ButtonSetText(m_RestartButton, "#main_menu_respawn");
		}
		else
		{
			ButtonSetText(m_RestartButton, "#main_menu_restart");
		}

		HudShow(false);
		SetGameVersion();

		if (m_ModdedWarning)
		{
			m_ModdedWarning.Show(false);
		}

		PlayZInitPauseOverlays();

		Mission mission = g_Game.GetMission();
		if (mission)
		{
			mission.Pause();
		}

		return layoutRoot;
	}

	protected void PlayZDeathRevealApplyCovers()
	{
		if (m_PlayZDeathPictureCover)
		{
			m_PlayZDeathPictureCover.SetAlpha(m_PlayZDeathPictureCoverLevel);
		}

		if (m_PlayZDeathButtonsCover)
		{
			m_PlayZDeathButtonsCover.SetAlpha(m_PlayZDeathButtonsCoverLevel);
		}
	}

	protected void PlayZDeathRevealFinish()
	{
		m_PlayZDeathRevealActive = false;
		m_PlayZDeathPictureCoverLevel = 0;
		m_PlayZDeathButtonsCoverLevel = 0;
		PlayZDeathScreen_SetIntroActive(false);
		PlayZDeathRevealApplyCovers();
		PlayZDeathScreen_MaintainDeathMenuView();
	}

	protected bool PlayZDeathRevealIsComplete()
	{
		return m_PlayZDeathPictureCoverLevel <= 0 && m_PlayZDeathButtonsCoverLevel <= 0;
	}

	protected void PlayZInitExpansionDeathStatsOverlay()
	{
		m_DeadScreenRoot = g_Game.GetWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_EXPANSION_DEATH_STATISTICS, layoutRoot);
		if (!m_DeadScreenRoot)
		{
			return;
		}

		m_DeadScreenRoot.SetAlpha(1);
		m_DeadScreenRoot.Show(false);

		m_DeadScreen = m_DeadScreenRoot.FindAnyWidget("dead_screen");
		if (m_DeadScreen)
		{
			m_DeadScreen.Show(false);
		}

		m_DeadScreenImage = ImageWidget.Cast(m_DeadScreenRoot.FindAnyWidget("dead_screen_image"));
		if (m_DeadScreenImage)
		{
			m_DeadScreenImage.Show(false);
		}

		m_DeadSceenStatsButtonPanel = m_DeadScreenRoot.FindAnyWidget("ButtonPanel");
		if (m_DeadSceenStatsButtonPanel)
		{
			m_DeadSceenStatsButtonPanel.Show(false);
		}

		m_DeadSceenStatsPanel = m_DeadScreenRoot.FindAnyWidget("PlayerStatisticsPanel");
		m_DeadSceenStatsPanelTitle = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("Caption"));
		TextWidget timeSurvivedLabel = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("TimeSurvivedLabel"));
		if (timeSurvivedLabel)
		{
			timeSurvivedLabel.SetText("#STR_PlayZ_DeathStats_TimeSurvived");
		}

		TextWidget animalsKilledLabel = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("AnimalsKilledLabel"));
		if (animalsKilledLabel)
		{
			animalsKilledLabel.SetText("#STR_PlayZ_DeathStats_AnimalKills");
		}

		m_DeadSourceVal = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("DeadSourceValue"));
		m_LongestShotVal = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("LongRangeShotValue"));
		m_DistanceVal = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("DistanceTraveledValue"));
		m_AnimalsKilledVal = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("AnimalsKilledValue"));
		m_InfectedKilledVal = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("InfectedKilledValue"));
		m_PlayersKilledVal = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("PlayersKilledValue"));
	#ifdef ENFUSION_AI_PROJECT
		m_AIKilledVal = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("AIKilledValue"));
	#endif
		m_TimeSurvivedVal = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("TimeSurvivedValue"));
		m_DeadScreenStatsHideButton = ButtonWidget.Cast(m_DeadScreenRoot.FindAnyWidget("bHide"));
		TextWidget hideStatsLabel = TextWidget.Cast(m_DeadScreenRoot.FindAnyWidget("bHideLable"));
		if (hideStatsLabel)
		{
			hideStatsLabel.SetText("#STR_PlayZ_DeathStats_Close");
		}

		if (m_DeadSceenStatsPanel)
		{
			m_DeadSceenStatsPanel.Show(false);
		}
	}

	protected void PlayZRefreshDeathStatisticsButton()
	{
		if (!m_StatisticsButton)
		{
			return;
		}

		bool showButton = GetValuesFromMonitor();
		m_StatisticsButton.Show(showButton);
		if (showButton)
		{
			m_PlayZDeathStatsButtonResolved = true;
		}
	}

	protected void PlayZShowDeathStatistics()
	{
		if (!GetValuesFromMonitor())
		{
			return;
		}

		if (!m_DeadScreenRoot || !m_DeadSceenStatsPanel)
		{
			return;
		}

		UpdatePlayerStatValues();
		m_DeadScreenRoot.Show(true);
		m_DeadSceenStatsPanel.Show(true);
	}

	protected void PlayZHideDeathStatistics()
	{
		if (m_DeadSceenStatsPanel)
		{
			m_DeadSceenStatsPanel.Show(false);
		}

		if (m_DeadScreenRoot)
		{
			m_DeadScreenRoot.Show(false);
		}
	}

	protected string PlayZResolveDeathStatsPlayerName(PlayerBase player)
	{
		if (!player)
		{
			return string.Empty;
		}

		string terjeName = player.GetTerjeCharacterName();
		if (terjeName != string.Empty)
		{
			return terjeName;
		}

		if (player.GetIdentity())
		{
			return player.GetIdentity().GetName();
		}

		return string.Empty;
	}

	protected Widget PlayZInitDeathMenu()
	{
		layoutRoot = g_Game.GetWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_DEATH_SCREEN);
		PlayZBindDeathMenuWidgets();

		m_PlayZDeathBackground = ImageWidget.Cast(layoutRoot.FindAnyWidget("death_background"));
		m_PlayZDeathPictureCover = layoutRoot.FindAnyWidget("death_picture_cover");
		m_PlayZDeathButtonsCover = layoutRoot.FindAnyWidget("death_buttons_cover");

		if (m_PlayZDeathBackground)
		{
			m_PlayZDeathBackground.LoadImageFile(0, PlayZUIPaths.TEX_DEATHSCREEN);
		}

		m_PlayZDeathPictureCoverLevel = 1;
		m_PlayZDeathButtonsCoverLevel = 1;
		PlayZDeathRevealApplyCovers();

		m_PlayZDeathRevealElapsed = 0;
		m_PlayZDeathRevealTimerSlice = 0;
		m_PlayZDeathRevealActive = true;
		m_PlayZDeathStatsButtonResolved = false;

		PlayZInitExpansionDeathStatsOverlay();
		PlayZRefreshDeathStatisticsButton();

		HudShow(false);
		PlayZDeathScreen_MaintainDeathMenuView();

		Mission mission = g_Game.GetMission();
		if (mission)
		{
			mission.Pause();
		}

		return layoutRoot;
	}

	override protected void UpdatePlayerStatValues()
	{
		super.UpdatePlayerStatValues();

		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!player || !m_DeadSceenStatsPanelTitle)
		{
			return;
		}

		string name = PlayZResolveDeathStatsPlayerName(player);
		if (name == string.Empty)
		{
			return;
		}

		StringLocaliser player_name = new StringLocaliser("STR_EXPANSION_DEADSCREEN_STATS_TITLE", name);
		m_DeadSceenStatsPanelTitle.SetText(player_name.Format());
	}

	protected void PlayZDeathRevealShow(float timeslice)
	{
		if (!m_PlayZDeathRevealActive)
		{
			return;
		}

		m_PlayZDeathRevealElapsed = m_PlayZDeathRevealElapsed + timeslice;

		if (m_PlayZDeathPictureCoverLevel > 0)
		{
			float newPictureCover = m_PlayZDeathPictureCoverLevel - (1 / PlayZUIPaths.DEATH_REVEAL_PICTURE_SEC) * timeslice;
			if (newPictureCover > 0)
			{
				m_PlayZDeathPictureCoverLevel = newPictureCover;
			}
			else
			{
				m_PlayZDeathPictureCoverLevel = 0;
			}
		}

		if (m_PlayZDeathRevealElapsed >= PlayZUIPaths.DEATH_REVEAL_BUTTONS_DELAY_SEC && m_PlayZDeathButtonsCoverLevel > 0)
		{
			float newButtonsCover = m_PlayZDeathButtonsCoverLevel - (1 / PlayZUIPaths.DEATH_REVEAL_BUTTONS_SEC) * timeslice;
			if (newButtonsCover > 0)
			{
				m_PlayZDeathButtonsCoverLevel = newButtonsCover;
			}
			else
			{
				m_PlayZDeathButtonsCoverLevel = 0;
			}
		}

		PlayZDeathRevealApplyCovers();

		if (PlayZDeathRevealIsComplete())
		{
			PlayZDeathRevealFinish();
		}
	}

	override Widget Init()
	{
		m_PlayZDeathMode = PlayZDeathScreen_IsMenuMode();

		if (m_PlayZDeathMode)
		{
			return PlayZInitDeathMenu();
		}

		return PlayZInitPauseMenu();
	}

	void Expansion_OnGeneralSettingsUpdated()
	{
		if (m_NewsFeed && !GetExpansionSettings().GetGeneral().UseNewsFeedInGameMenu)
		{
			Widget newsFeedRoot = m_NewsFeed.GetLayoutRoot();
			if (newsFeedRoot)
			{
				newsFeedRoot.Show(false);
			}
		}
	}

	void OnSettingChanged()
	{
	}

	override void SetServerInfoVisibility(bool show)
	{
	}

	override protected bool SetServerInfo()
	{
		return false;
	}

	override void Update(float timeslice)
	{
		if (m_PlayZDeathMode)
		{
			PlayZDeathScreen_MaintainDeathMenuView();

			if (m_PlayZDeathRevealActive)
			{
				m_PlayZDeathRevealTimerSlice = m_PlayZDeathRevealTimerSlice + timeslice;
				if (m_PlayZDeathRevealTimerSlice >= 0.01)
				{
					PlayZDeathRevealShow(timeslice);
					m_PlayZDeathRevealTimerSlice = 0;
				}
			}
			else
			{
				PlayZDeathRevealApplyCovers();
			}

			if (!m_PlayZDeathStatsButtonResolved)
			{
				PlayZRefreshDeathStatisticsButton();
			}
		}

		super.Update(timeslice);
	}

	override void UpdateGUI()
	{
		if (m_PlayZDeathMode)
		{
			return;
		}

		super.UpdateGUI();
	}

	override protected void GameRespawn(bool random)
	{
		PlayZDeathScreen_Reset();
		super.GameRespawn(random);
	}

	override protected void OnClick_Exit()
	{
		if (m_PlayZDeathMode)
		{
			PlayZDeathScreen_Reset();
		}

		super.OnClick_Exit();
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (m_PlayZDeathMode && button == MouseState.LEFT)
		{
			if (w == m_StatisticsButton)
			{
				PlayZShowDeathStatistics();
				return true;
			}

			if (w == m_DeadScreenStatsHideButton)
			{
				PlayZHideDeathStatistics();
				return true;
			}
		}

		if (!m_PlayZDeathMode && button == MouseState.LEFT)
		{
			if (w == m_WebsiteButton)
			{
				g_Game.OpenURL(PlayZUIPaths.URL_WEBSITE);
				return true;
			}

			if (w == m_DiscordButton)
			{
				g_Game.OpenURL(PlayZUIPaths.URL_DISCORD);
				return true;
			}
		}

		return super.OnClick(w, x, y, button);
	}
}
