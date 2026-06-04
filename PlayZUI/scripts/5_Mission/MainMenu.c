// PlayZ main menu: custom layout PlayZ_main_menu.layout (minimal vs vanilla main_menu.layout).
// Play uses ButtonWidget "play" + play_panel + play_label so ColorHighlight/ColorNormal apply like vanilla — Source Found: scripts/5_Mission/GUI/NewUI/MainMenu/MainMenu.c:610-637, gui/layouts/new_ui/main_menu.layout (ButtonWidgetClass play)
// Link icons: child names playz_*_button_image so ImagenSetColor finds them — MainMenu.c:666-676
// PayPal: playz_paypal_button + playz_paypal_button_image; default white tint in PlayZApplyLinkIconDefaultColors
// Play hover: vanilla ColorHighlight sets play_panel to opaque black ARGB(255,0,0,0) — MainMenu.c:611-622 — override for transparent panel, keep red label
// Intro scene: MissionMainMenu + DayZIntroScenePC — Source Found: scripts/5_Mission/mission/missionMainMenu.c:43-49
// Vanilla mods strip: MainMenu.LoadMods — Source Found: scripts/5_Mission/GUI/NewUI/MainMenu/MainMenu.c:148-168
// External links: playz_website_button / playz_discord_button (ButtonWidget + image child) — g_Game.OpenURL — Source Found: scripts/3_Game/Global/Game.c:1377, MainMenuNewsfeed.c:66-71
// Play: vanilla calls ConnectLastSession / ConnectBestServer — MainMenu.c:413-422,564-577; join uses ConnectFromServerBrowserEx — DayZGame.c:2769-2772 (steam query 0 → IP-only path DayZGame.c:2680-2683)

modded class MainMenu
{
	protected Widget PlayZResolveLinkButtonForHover(Widget w)
	{
		if (!w)
		{
			return null;
		}
		string wn = w.GetName();
		if (wn == "playz_website_button" || wn == "playz_discord_button" || wn == "playz_paypal_button")
		{
			return w;
		}
		if (wn == "playz_website_button_image" || wn == "playz_discord_button_image" || wn == "playz_paypal_button_image")
		{
			return w.GetParent();
		}
		return null;
	}

	protected void PlayZLinkButtonSetImageColor(Widget w, int color)
	{
		if (!w)
		{
			return;
		}
		Widget img = w.FindWidget(w.GetName() + "_image");
		if (img)
		{
			img.SetColor(color);
		}
	}

	protected void PlayZApplyLinkIconDefaultColors()
	{
		if (!layoutRoot)
		{
			return;
		}
		int white = PlayZMenuStyle.IconNormal();
		array<string> names = new array<string>();
		names.Insert("playz_website_button");
		names.Insert("playz_discord_button");
		names.Insert("playz_paypal_button");
		names.Insert("settings_button");
		names.Insert("exit_button");
		names.Insert("tutorial_button");
		names.Insert("message_button");
		names.Insert("feedback_button");
		int i;
		int n = names.Count();
		for (i = 0; i < n; i++)
		{
			string bn = names.Get(i);
			Widget btn = layoutRoot.FindAnyWidget(bn);
			if (!btn)
			{
				continue;
			}
			Widget img = btn.FindWidget(bn + "_image");
			if (img)
			{
				img.SetColor(white);
			}
		}
	}

	override void Play()
	{
		g_Game.GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "PlayZConnectHardcodedServer");
	}

	protected void PlayZConnectHardcodedServer()
	{
		g_Game.ConnectFromServerBrowserEx("127.0.0.1", 2502, 27018, "");
	}

	override Widget Init()
	{
		layoutRoot = g_Game.GetWorkspace().CreateWidgets("PlayZ_Client/PlayZUI/gui/layouts/PlayZ_main_menu.layout");

		m_Play						= layoutRoot.FindAnyWidget("play");
		if (!m_Play)
		{
			m_Play					= layoutRoot.FindAnyWidget("ImageLogo");
		}
		m_ChooseServer				= layoutRoot.FindAnyWidget("choose_server");
		m_CustomizeCharacter		= layoutRoot.FindAnyWidget("customize_character");
		m_PlayVideo					= layoutRoot.FindAnyWidget("play_video");
		m_Feedback					= layoutRoot.FindAnyWidget("feedback_button");
		m_Tutorials					= layoutRoot.FindAnyWidget("tutorials");
		m_TutorialButton			= layoutRoot.FindAnyWidget("tutorial_button");
		m_MessageButton				= layoutRoot.FindAnyWidget("message_button");
		m_SettingsButton			= layoutRoot.FindAnyWidget("settings_button");
		m_Exit						= layoutRoot.FindAnyWidget("exit_button");
		m_PrevCharacter				= layoutRoot.FindAnyWidget("prev_character");
		m_NextCharacter				= layoutRoot.FindAnyWidget("next_character");

		m_DlcFrame 					= layoutRoot.FindAnyWidget("dlc_Frame");
		m_NewsCarouselFrame 		= layoutRoot.FindAnyWidget("carousel_Frame");
		m_Version					= TextWidget.Cast(layoutRoot.FindAnyWidget("version"));
		m_ModdedWarning				= TextWidget.Cast(layoutRoot.FindAnyWidget("ModdedWarning"));
		m_CharacterRotationFrame	= layoutRoot.FindAnyWidget("character_rotation_frame");

		m_LastPlayedTooltip			= layoutRoot.FindAnyWidget("last_server_info");
		if (m_LastPlayedTooltip)
		{
			m_LastPlayedTooltip.Show(false);
			m_LastPlayedTooltipLabel	= m_LastPlayedTooltip.FindAnyWidget("last_server_info_label");
			m_LastPlayedTooltipName 	= TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_name"));
			m_LastPlayedTooltipIP		= TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_ip"));
			m_LastPlayedTooltipPort		= TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_port"));
		}

		m_LastPlayedTooltipTimer	= new WidgetFadeTimer();

		if (layoutRoot.FindAnyWidget("character_stats_root"))
		{
			m_Stats						= new MainMenuStats(layoutRoot.FindAnyWidget("character_stats_root"));
		}

		m_Mission					= MissionMainMenu.Cast(g_Game.GetMission());

		m_LastFocusedButton 		= m_Play;
		if (!m_LastFocusedButton && m_SettingsButton)
		{
			m_LastFocusedButton = m_SettingsButton;
		}
		if (!m_LastFocusedButton && m_Exit)
		{
			m_LastFocusedButton = m_Exit;
		}

		m_ScenePC					= m_Mission.GetIntroScenePC();
		if (m_ScenePC)
		{
			m_ScenePC.ResetIntroCamera();
		}

		if (m_PlayVideo)
		{
			m_PlayVideo.Show(false);
		}

		m_PlayerName				= TextWidget.Cast(layoutRoot.FindAnyWidget("character_name_text"));
		if (m_Play)
		{
			ColorNormal(m_Play);
		}

		string version;
		g_Game.GetVersion(version);
		if (m_Version)
		{
			m_Version.SetText("#main_menu_version" + " " + version);
		}

		g_Game.GetUIManager().ScreenFadeOut(0);

		SetFocus(null);

		Refresh();

		LoadMods();

		CheckWidth();

		#ifndef BUILD_EXPERIMENTAL
		if (m_NewsCarouselFrame)
		{
			m_NewsCarousel = new NewsCarousel(m_NewsCarouselFrame, this);
		}
		else
		{
			m_NewsCarousel = null;
		}
		#else
		m_NewsCarousel = null;
		#endif

		ShowNewsCarousel(true);

		g_Game.GetMission().GetOnModMenuVisibilityChanged().Insert(ShowNewsCarousel);
		GetDayZGame().GetBacklit().MainMenu_OnShow();

		g_Game.SetLoadState(DayZLoadState.MAIN_MENU_CONTROLLER_SELECT);

		PlayZApplyLinkIconDefaultColors();

		return layoutRoot;
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT && w)
		{
			string wn = w.GetName();
			if (wn == "playz_website_button" || wn == "playz_website_button_image")
			{
				g_Game.OpenURL("https://playzthegoat.com/");
				return true;
			}
			if (wn == "playz_discord_button" || wn == "playz_discord_button_image")
			{
				g_Game.OpenURL("https://discord.gg/SgNhCNtb5N");
				return true;
			}
			if (wn == "playz_paypal_button" || wn == "playz_paypal_button_image")
			{
				g_Game.OpenURL("https://www.paypal.com/donate/?hosted_button_id=S4UW3CKQFG7US");
				return true;
			}
			if (wn == "play" || wn == "play_image" || wn == "ImageLogo")
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
		if (m_ModsSimple)
		{
			delete m_ModsSimple;
		}
		m_ModsSimple = null;
		if (m_ModsDetailed)
		{
			delete m_ModsDetailed;
		}
		m_ModsDetailed = null;
		if (m_ModsTooltip)
		{
			delete m_ModsTooltip;
		}
		m_ModsTooltip = null;

		if (m_ModdedWarning)
		{
			m_ModdedWarning.Show(g_Game.GetModToBeReported());
		}

		MainMenuData.LoadMods();

		Widget wModsSimple = layoutRoot.FindAnyWidget("ModsSimple");
		if (wModsSimple)
		{
			wModsSimple.Show(false);
		}
		Widget wModsDetailed = layoutRoot.FindAnyWidget("ModsDetailed");
		if (wModsDetailed)
		{
			wModsDetailed.Show(false);
		}
	}

	override void ShowNewsCarousel(bool show)
	{
		if (m_NewsCarouselFrame)
		{
			m_NewsCarouselFrame.Show(show);
		}
		if (m_NewsCarousel)
		{
			m_NewsCarousel.ShowNewsCarousel(show);
		}
	}

	override void OnChangeCharacter(bool create_character = true)
	{
		if (m_ScenePC && m_ScenePC.GetIntroCharacter())
		{
			int charID = m_ScenePC.GetIntroCharacter().GetCharacterID();
			if (create_character)
			{
				m_ScenePC.GetIntroCharacter().CreateNewCharacterById(charID);
			}
			if (m_PlayerName)
			{
				m_PlayerName.SetText(m_ScenePC.GetIntroCharacter().GetCharacterNameById(charID));
			}

			if (m_CustomizeCharacter)
			{
				Widget w = m_CustomizeCharacter.FindAnyWidget(m_CustomizeCharacter.GetName() + "_label");
				if (w)
				{
					TextWidget text = TextWidget.Cast(w);
					if (text)
					{
						if (m_ScenePC.GetIntroCharacter().IsDefaultCharacter())
						{
							text.SetText("#layout_main_menu_customize_char");
						}
						else
						{
							text.SetText("#layout_main_menu_rename");
						}
					}
				}
			}
			if (m_ScenePC.GetIntroCharacter().GetCharacterObj())
			{
				if (m_ScenePC.GetIntroCharacter().GetCharacterObj().IsMale())
				{
					m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Male);
				}
				else
				{
					m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Female);
				}
			}

			if (m_Stats)
			{
				m_Stats.UpdateStats();
			}
		}
	}

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (w == m_Play)
		{
			string ip = "";
			string name = "";
			int port = 0;

			if (m_ScenePC && !m_ScenePC.GetIntroCharacter().IsDefaultCharacter())
			{
				if (m_LastPlayedTooltipName && m_LastPlayedTooltipIP && m_LastPlayedTooltipPort && m_LastPlayedTooltip)
				{
					int charID = m_ScenePC.GetIntroCharacter().GetCharacterID();
					m_ScenePC.GetIntroCharacter().GetLastPlayedServer(charID, ip, name, port);

					m_LastPlayedTooltipName.SetText("#server_details_name " + name);
					m_LastPlayedTooltipIP.SetText("#main_menu_IP " + ip);
					m_LastPlayedTooltipPort.SetText("#main_menu_port " + port);

					m_LastPlayedTooltipTimer.FadeIn(m_LastPlayedTooltip, 0.3, true);
				}
			}
		}

		if (IsFocusable(w))
		{
			ColorHighlight(w);
			return true;
		}
		return false;
	}

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (w == m_Play)
		{
			if (m_LastPlayedTooltip && m_LastPlayedTooltipTimer)
			{
				m_LastPlayedTooltipTimer.FadeOut(m_LastPlayedTooltip, 0.3, true);
			}
		}

		if (IsFocusable(w))
		{
			ColorNormal(w);
			return true;
		}
		return false;
	}

	override bool IsFocusable(Widget w)
	{
		if (w)
		{
			string wn = w.GetName();
			if (wn == "play" || wn == "play_image" || wn == "ImageLogo" || wn == "playz_website_button" || wn == "playz_discord_button" || wn == "playz_paypal_button" || wn == "playz_website_button_image" || wn == "playz_discord_button_image" || wn == "playz_paypal_button_image")
			{
				return true;
			}
		}
		return super.IsFocusable(w);
	}

	override void CheckWidth()
	{
		int w;
		int h;
		ScreenWidthType widthType;
		GetScreenSize(w, h);

		if (h > 0)
		{
			float ratio = w / h;
			if (ratio > 1.75)
			{
				widthType = ScreenWidthType.WIDE;
			}
			else if (ratio > 1.5)
			{
				widthType = ScreenWidthType.MEDIUM;
			}
			else
			{
				widthType = ScreenWidthType.NARROW;
			}
		}

		m_Width = w;
		m_Height = h;

		if (m_PrevWidth != m_Width || m_PrevHeight != m_Height)
		{
			if (m_NewsCarousel && m_NewsCarouselFrame)
			{
				m_NewsCarousel.Destroy();
				m_NewsCarousel = null;
				m_NewsCarousel = new NewsCarousel(m_NewsCarouselFrame, this);
			}

			m_PrevWidth = w;
			m_PrevHeight = h;
		}
	}

	override void Refresh()
	{
		string name;
		if (m_ScenePC && g_Game.GetGameState() == DayZGameState.MAIN_MENU)
		{
			OnChangeCharacter();
		}

		string version;
		g_Game.GetVersion(version);
		if (m_Version)
		{
			m_Version.SetText("#main_menu_version" + " " + version);
		}

		if (m_DisplayedDlcHandler)
		{
			m_DisplayedDlcHandler.UpdateAllPromotionInfo();
		}
	}

	override void OnShow()
	{
		if (m_DisplayedDlcHandler)
		{
			m_DisplayedDlcHandler.ShowInfoPanel(true);
		}

		SetFocus(null);
		OnChangeCharacter(false);
		if (m_Stats)
		{
			m_Stats.UpdateStats();
		}
		LoadMods();
	}

	override void OnHide()
	{
		if (m_DisplayedDlcHandler)
		{
			m_DisplayedDlcHandler.ShowInfoPanel(false);
		}

		GetDayZGame().GetBacklit().MainMenu_OnHide();
	}

	override void ColorHighlight(Widget w)
	{
		if (!w)
		{
			return;
		}
		Widget linkBtn = PlayZResolveLinkButtonForHover(w);
		if (linkBtn)
		{
			ButtonSetColor(linkBtn, PlayZMenuStyle.PanelTransparent());
			ButtonSetTextColor(linkBtn, PlayZMenuStyle.AccentColor());
			PlayZLinkButtonSetImageColor(linkBtn, PlayZMenuStyle.AccentColor());
			return;
		}
		if (w.GetName() == "play" || w.GetName() == "play_image")
		{
			int color_pnl = PlayZMenuStyle.PanelTransparent();
			int color_lbl = PlayZMenuStyle.AccentColor();
			int color_img = PlayZMenuStyle.AccentColor();
			ButtonSetColor(w, color_pnl);
			ButtonSetTextColor(w, color_lbl);
			ImagenSetColor(w, color_img);
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
		Widget linkBtn = PlayZResolveLinkButtonForHover(w);
		if (linkBtn)
		{
			ButtonSetColor(linkBtn, PlayZMenuStyle.PanelTransparent());
			ButtonSetTextColor(linkBtn, PlayZMenuStyle.TextNormal());
			PlayZLinkButtonSetImageColor(linkBtn, PlayZMenuStyle.IconNormal());
			return;
		}
		if (w.GetName() == "play" || w.GetName() == "play_image")
		{
			int color_pnl = PlayZMenuStyle.PanelTransparent();
			int color_lbl = PlayZMenuStyle.TextNormal();
			int color_img = PlayZMenuStyle.IconNormal();
			ButtonSetColor(w, color_pnl);
			ButtonSetTextColor(w, color_lbl);
			ImagenSetColor(w, color_img);
			return;
		}
		super.ColorNormal(w);
	}
}
