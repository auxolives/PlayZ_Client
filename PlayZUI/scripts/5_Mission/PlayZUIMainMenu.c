modded class MainMenu
{
	override Widget Init()
	{
		layoutRoot = g_Game.GetWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_MAIN_MENU);

		m_Play				= layoutRoot.FindAnyWidget("play");
		m_Feedback			= layoutRoot.FindAnyWidget("feedback_button");
		m_TutorialButton	= layoutRoot.FindAnyWidget("tutorial_button");
		m_MessageButton		= layoutRoot.FindAnyWidget("message_button");
		m_SettingsButton	= layoutRoot.FindAnyWidget("settings_button");
		m_Exit				= layoutRoot.FindAnyWidget("exit_button");
		m_Version			= TextWidget.Cast(layoutRoot.FindAnyWidget("version"));

		m_LastPlayedTooltip = layoutRoot.FindAnyWidget("last_server_info");
		if (m_LastPlayedTooltip)
		{
			m_LastPlayedTooltip.Show(false);
			m_LastPlayedTooltipLabel = m_LastPlayedTooltip.FindAnyWidget("last_server_info_label");
			m_LastPlayedTooltipName = TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_name"));
			m_LastPlayedTooltipIP = TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_ip"));
			m_LastPlayedTooltipPort = TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_port"));
			m_LastPlayedTooltipTimer = new WidgetFadeTimer();
		}

		m_Mission = MissionMainMenu.Cast(g_Game.GetMission());
		m_LastFocusedButton = m_Play;

		string version;
		g_Game.GetVersion(version);
		m_Version.SetText("#main_menu_version" + " " + version);

		g_Game.GetUIManager().ScreenFadeOut(0);
		SetFocus(null);

		Refresh();
		LoadMods();
		CheckWidth();

		GetDayZGame().GetBacklit().MainMenu_OnShow();
		g_Game.SetLoadState(DayZLoadState.MAIN_MENU_CONTROLLER_SELECT);

		return layoutRoot;
	}

	override void LoadMods()
	{
	}

	override void ShowNewsCarousel(bool show)
	{
	}

	override void OnChangeCharacter(bool create_character = true)
	{
	}

	override void Refresh()
	{
		string version;
		g_Game.GetVersion(version);
		if (m_Version)
		{
			m_Version.SetText("#main_menu_version" + " " + version);
		}

		GetDayZGame().Expansion_SetGameVersionText(m_Version);
	}

	override void OnShow()
	{
		SetFocus(null);
		LoadMods();
	}

	override void CheckWidth()
	{
		int w, h;
		GetScreenSize(w, h);
		m_Width = w;
		m_Height = h;
		m_PrevWidth = w;
		m_PrevHeight = h;
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);

		CheckWidth();

		if (g_Game && GetUApi().GetInputByID(UAUIBack).LocalPress())
		{
			if (!g_Game.GetUIManager().IsDialogHiding())
			{
				Exit();
			}
		}
	}

	override void ConnectLastSession()
	{
		string ip = "";
		int port = 0;

		if (TryConnectLastSession(ip, port))
		{
			g_Game.ConnectFromServerBrowserEx(ip, port, 0, "");
			return;
		}

		OpenMenuServerBrowser();
	}

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (IsFocusable(w))
		{
			ColorHighlight(w);
			return true;
		}

		return false;
	}

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (IsFocusable(w))
		{
			ColorNormal(w);
			return true;
		}

		return false;
	}

	override bool IsFocusable(Widget w)
	{
		if (!w)
		{
			return false;
		}

		if (w == m_Play || w == m_TutorialButton || w == m_MessageButton || w == m_SettingsButton)
		{
			return true;
		}

		if (w == m_Exit || w == m_Feedback)
		{
			return true;
		}

		return false;
	}
}
