modded class InGameMenu
{
	protected void PlayZRebindInGameMenuWidgets()
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
		m_ServerInfoPanel = layoutRoot.FindAnyWidget("server_info");
		m_ServerIP = TextWidget.Cast(layoutRoot.FindAnyWidget("server_ip"));
		m_ServerPort = TextWidget.Cast(layoutRoot.FindAnyWidget("server_port"));
		m_ServerName = TextWidget.Cast(layoutRoot.FindAnyWidget("server_name"));
		m_FavoriteImage = layoutRoot.FindAnyWidget("favorite_image");
		m_UnfavoriteImage = layoutRoot.FindAnyWidget("unfavorite_image");
		m_CopyInfoButton = layoutRoot.FindAnyWidget("copy_button");
		m_FeedbackButton = layoutRoot.FindAnyWidget("feedbackbtn");
		m_HintPanel = null;
	}

	protected void PlayZReparentExpansionWidgets(Widget playzRoot)
	{
		if (m_DeadScreenRoot)
		{
			Widget deadParent = m_DeadScreenRoot.GetParent();
			if (deadParent)
			{
				deadParent.RemoveChild(m_DeadScreenRoot);
			}
			playzRoot.AddChild(m_DeadScreenRoot, true);
		}

		if (m_NewsFeed)
		{
			Widget newsFeedRoot = m_NewsFeed.GetLayoutRoot();
			if (newsFeedRoot)
			{
				Widget newsParent = newsFeedRoot.GetParent();
				if (newsParent)
				{
					newsParent.RemoveChild(newsFeedRoot);
				}
				playzRoot.AddChild(newsFeedRoot, true);
			}
		}
	}

	protected Widget PlayZSwapToPlayZLayout()
	{
		Widget oldRoot = layoutRoot;
		Widget playzRoot = g_Game.GetWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_INGAME);

		PlayZReparentExpansionWidgets(playzRoot);

		if (oldRoot)
		{
			oldRoot.Unlink();
		}

		layoutRoot = playzRoot;
		PlayZRebindInGameMenuWidgets();

		if (m_ModdedWarning)
		{
			m_ModdedWarning.Show(false);
		}

		SetServerInfoVisibility(SetServerInfo() && g_Game.GetProfileOption(EDayZProfilesOptions.SERVERINFO_DISPLAY));

		m_Logo = ImageWidget.Cast(layoutRoot.FindAnyWidget("dayz_logo"));

		return layoutRoot;
	}

	protected bool PlayZIsLinkWidget(Widget w, string linkName)
	{
		if (!w)
		{
			return false;
		}

		string wn = w.GetName();
		if (wn == linkName)
		{
			return true;
		}

		if (wn == linkName + "_label")
		{
			return true;
		}

		return false;
	}

	override Widget Init()
	{
		layoutRoot = super.Init();
		return PlayZSwapToPlayZLayout();
	}

	void Expansion_OnGeneralSettingsUpdated()
	{
		if (!GetExpansionSettings().GetGeneral().UseDeathScreenStatistics || !GetValuesFromMonitor())
		{
			m_DeadSceenStatsButtonPanel.Show(false);
		}

		if (m_NewsFeed && !GetExpansionSettings().GetGeneral().UseNewsFeedInGameMenu)
		{
			Widget newsFeedRoot = m_NewsFeed.GetLayoutRoot();
			if (newsFeedRoot)
			{
				newsFeedRoot.Show(false);
			}
		}
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT)
		{
			if (PlayZIsLinkWidget(w, "playz_website_link"))
			{
				g_Game.OpenURL("https://playzthegoat.com/");
				return true;
			}

			if (PlayZIsLinkWidget(w, "playz_discord_link"))
			{
				g_Game.OpenURL("https://discord.gg/SgNhCNtb5N");
				return true;
			}
		}

		return super.OnClick(w, x, y, button);
	}
}
