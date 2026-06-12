modded class MainMenu
{
	override Widget Init()
	{
		layoutRoot = g_Game.GetWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_MAIN_MENU);

		m_Play = layoutRoot.FindAnyWidget("play");
		m_Feedback = layoutRoot.FindAnyWidget("feedback_button");
		m_TutorialButton = layoutRoot.FindAnyWidget("tutorial_button");
		m_MessageButton = layoutRoot.FindAnyWidget("message_button");
		m_SettingsButton = layoutRoot.FindAnyWidget("settings_button");
		m_Exit = layoutRoot.FindAnyWidget("exit_button");
		m_Version = TextWidget.Cast(layoutRoot.FindAnyWidget("version"));

		m_Mission = MissionMainMenu.Cast(g_Game.GetMission());
		m_LastFocusedButton = m_Play;

		if (m_Play)
		{
			ColorNormal(m_Play);
		}

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

	override void Play()
	{
		g_Game.GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "PlayZConnectHardcodedServer");
	}

	protected void PlayZConnectHardcodedServer()
	{
		g_Game.ConnectFromServerBrowserEx(PlayZUIPaths.SERVER_IP, PlayZUIPaths.SERVER_GAME_PORT, PlayZUIPaths.SERVER_STEAM_QUERY_PORT, "");
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT && w)
		{
			string wn = w.GetName();
			if (wn == "play" || wn == "play_image")
			{
				m_LastFocusedButton = m_Play;
				Play();
				return true;
			}
		}

		return super.OnClick(w, x, y, button);
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

		string wn = w.GetName();
		if (wn == "play" || wn == "play_image")
		{
			return true;
		}

		if (w == m_TutorialButton || w == m_MessageButton || w == m_SettingsButton)
		{
			return true;
		}

		if (w == m_Exit || w == m_Feedback)
		{
			return true;
		}

		return false;
	}

	override void ColorHighlight(Widget w)
	{
		if (!w)
		{
			return;
		}

		string wn = w.GetName();
		if (wn == "play" || wn == "play_image")
		{
			Widget playBtn = w;
			if (wn == "play_image")
			{
				playBtn = w.GetParent();
			}

			int color_pnl = ARGB(0, 0, 0, 0);
			int color_img = ARGB(255, 200, 0, 0);
			ButtonSetColor(playBtn, color_pnl);
			ImagenSetColor(playBtn, color_img);
			return;
		}

		super.ColorHighlight(w);
	}

	override void ColorNormal(Widget w)
	{
		if (!w)
		{
			return;
		}

		string wn = w.GetName();
		if (wn == "play" || wn == "play_image")
		{
			Widget playBtn = w;
			if (wn == "play_image")
			{
				playBtn = w.GetParent();
			}

			int color_pnl = ARGB(0, 0, 0, 0);
			int color_img = ARGB(255, 255, 255, 255);
			ButtonSetColor(playBtn, color_pnl);
			ImagenSetColor(playBtn, color_img);
			return;
		}

		super.ColorNormal(w);
	}
}
