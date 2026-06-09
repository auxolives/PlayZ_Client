// PlayZ ingame menu: layout PlayZ_ingamemenu.layout — link buttons playz_website_button / playz_discord_button / playz_paypal_button + *_image
// g_Game.OpenURL — Source Found: scripts/3_Game/Global/Game.c:1377
// Hover: vanilla uses opaque black panel + red text (InGameMenu.c:365-372) — overridden: transparent panel, black text/icons (main menu keeps red via MainMenu.c)
// Image tint: PlayZLinkButtonSetImageColor — child name + _image suffix — Source Found: scripts/5_Mission/GUI/InGameMenu.c:403-408
// Layout must use playz_paypal_button + playz_paypal_button_image (not *_button0) so FindWidget finds the image
// Hover may target *_image child — resolve parent via GetParent — Source Found: scripts/1_Core/proto/EnWidgets.c:158
// SetBold on labels after SetColor — Source Found: scripts/1_Core/proto/EnWidgets.c:206

modded class InGameMenu
{
	protected Widget m_PlayZLifeStatsButton;
	protected bool m_PlayZLifeStatsDataReady;
	protected bool m_PlayZLifeStatsPanelOpen;
	protected Widget m_PlayZLifeStatsOverlayRoot;
	protected Widget m_PlayZLifeStatsPanel;
	protected Widget m_PlayZMenuPanel;

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

	protected void PlayZApplyBoldToMenuTextButtons()
	{
		if (!layoutRoot)
		{
			return;
		}
		array<string> ids = new array<string>();
		ids.Insert("continuebtn");
		ids.Insert("exitbtn");
		ids.Insert("restartbtn");
		ids.Insert("feedbackbtn");
		ids.Insert("optionsbtn");
		ids.Insert("life_stats_button");
		int i;
		int c = ids.Count();
		for (i = 0; i < c; i++)
		{
			string bid = ids.Get(i);
			Widget b = layoutRoot.FindAnyWidget(bid);
			if (!b)
			{
				continue;
			}
			TextWidget tw = TextWidget.Cast(b.FindAnyWidget(bid + "_label"));
			if (tw)
			{
				tw.SetBold(true);
			}
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

	protected void PlayZInitLifeStatsButton()
	{
		if (!layoutRoot)
		{
			return;
		}
		m_PlayZMenuPanel = layoutRoot.FindAnyWidget("play_panel_root");
		m_PlayZLifeStatsButton = layoutRoot.FindAnyWidget("life_stats_button");
		if (m_PlayZLifeStatsButton)
		{
			m_PlayZLifeStatsButton.Show(false);
		}
	}

	protected void PlayZOnInitLifeStatsIntegration()
	{
	}

	protected void PlayZRefreshLifeStatsData()
	{
	}

	protected bool PlayZOnLifeStatsMenuClick(Widget w)
	{
		return false;
	}

	protected void PlayZSetMenuPanelVisible(bool show)
	{
		if (m_PlayZMenuPanel)
		{
			m_PlayZMenuPanel.Show(show);
		}
	}

	protected void PlayZCloseLifeStatsPanel()
	{
		m_PlayZLifeStatsPanelOpen = false;
		PlayZSetMenuPanelVisible(true);

		if (m_PlayZLifeStatsPanel)
		{
			m_PlayZLifeStatsPanel.Show(false);
		}
		if (m_PlayZLifeStatsOverlayRoot)
		{
			m_PlayZLifeStatsOverlayRoot.Show(false);
		}
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT && w)
		{
			if (PlayZOnLifeStatsMenuClick(w))
			{
				return true;
			}
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
		}
		return super.OnClick(w, x, y, button);
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
			ButtonSetTextColor(linkBtn, PlayZMenuStyle.HoverBlack());
			PlayZLinkButtonSetImageColor(linkBtn, PlayZMenuStyle.HoverBlack());
			return;
		}
		ButtonSetColor(w, PlayZMenuStyle.PanelTransparent());
		ButtonSetTextColor(w, PlayZMenuStyle.HoverBlack());
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
			ButtonSetColor(linkBtn, ARGB(0, 0, 0, 0));
			ButtonSetTextColor(linkBtn, PlayZMenuStyle.TextNormal());
			PlayZLinkButtonSetImageColor(linkBtn, PlayZMenuStyle.IconNormal());
			return;
		}
		super.ColorNormal(w);
	}

	override protected void ButtonSetTextColor(Widget w, int color)
	{
		super.ButtonSetTextColor(w, color);
		TextWidget label = TextWidget.Cast(w.FindAnyWidget(w.GetName() + "_label"));
		if (!label)
		{
			return;
		}
		if (color == ColorManager.COLOR_DISABLED_TEXT)
		{
			label.SetBold(false);
		}
		else
		{
			label.SetBold(true);
		}
	}

	override Widget Init()
	{
		layoutRoot = g_Game.GetWorkspace().CreateWidgets("PlayZ_Client/PlayZUI/gui/layouts/PlayZ_ingamemenu.layout");

		m_ContinueButton			= layoutRoot.FindAnyWidget("continuebtn");
		m_SeparatorPanel			= layoutRoot.FindAnyWidget("separator_red");
		m_ExitButton				= layoutRoot.FindAnyWidget("exitbtn");
		m_RestartButton				= layoutRoot.FindAnyWidget("restartbtn");
		m_RespawnButton 			= layoutRoot.FindAnyWidget("respawn_button");
		m_RestartDeadRandomButton	= layoutRoot.FindAnyWidget("respawn_button_random");
		m_RestartDeadCustomButton	= layoutRoot.FindAnyWidget("respawn_button_custom");
		m_OptionsButton				= layoutRoot.FindAnyWidget("optionsbtn");
		m_ModdedWarning				= TextWidget.Cast(layoutRoot.FindAnyWidget("ModdedWarning"));
		Widget hintFrame = layoutRoot.FindAnyWidget("hint_frame");
		if (hintFrame)
		{
			m_HintPanel = new UiHintPanel(hintFrame);
		}
		m_ServerInfoPanel 			= layoutRoot.FindAnyWidget("server_info");
		m_ServerIP 					= TextWidget.Cast(layoutRoot.FindAnyWidget("server_ip"));
		m_ServerPort 				= TextWidget.Cast(layoutRoot.FindAnyWidget("server_port"));
		m_ServerName 				= TextWidget.Cast(layoutRoot.FindAnyWidget("server_name"));
		m_FavoriteImage 			= layoutRoot.FindAnyWidget("favorite_image");
		m_UnfavoriteImage 			= layoutRoot.FindAnyWidget("unfavorite_image");
		m_CopyInfoButton 			= layoutRoot.FindAnyWidget("copy_button");
		m_FeedbackButton			= layoutRoot.FindAnyWidget("feedbackbtn");

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
		SetServerInfoVisibility(SetServerInfo() && g_Game.GetProfileOption(EDayZProfilesOptions.SERVERINFO_DISPLAY));
		if (m_ModdedWarning)
		{
			m_ModdedWarning.Show(g_Game.ReportModded());
		}

		Mission mission = g_Game.GetMission();
		if (mission)
		{
			mission.Pause();
		}

		PlayZInitLifeStatsButton();
		PlayZOnInitLifeStatsIntegration();
		PlayZApplyLinkIconDefaultColors();
		PlayZApplyBoldToMenuTextButtons();
		PlayZUIManager.ApplyPlayZLogoOnRoot(layoutRoot);

		return layoutRoot;
	}

	override void OnShow()
	{
		super.OnShow();
		PlayZRefreshLifeStatsData();
	}

	override void OnHide()
	{
		PlayZCloseLifeStatsPanel();
		super.OnHide();
	}

	override protected void SetGameVersion()
	{
		TextWidget version_widget = TextWidget.Cast(layoutRoot.FindAnyWidget("version"));
		if (!version_widget)
		{
			return;
		}

		super.SetGameVersion();
	}

	override protected bool SetServerInfo()
	{
		if (!m_ServerIP || !m_ServerPort || !m_ServerName || !m_FavoriteImage || !m_UnfavoriteImage)
		{
			return false;
		}

		return super.SetServerInfo();
	}

	override void SetServerInfoVisibility(bool show)
	{
		if (!m_ServerInfoPanel)
		{
			return;
		}

		super.SetServerInfoVisibility(show);
	}

	override protected void UpdateGUI()
	{
		#ifdef BULDOZER
		m_RestartButton.Show(false);
		m_RespawnButton.Show(false);
		if (m_PlayZLifeStatsButton)
		{
			m_PlayZLifeStatsButton.Show(false);
		}
		#else
		Man player = g_Game.GetPlayer();
		bool playerAlive = player && player.GetPlayerState() == EPlayerStates.ALIVE;
		bool playerDead = player && !playerAlive;

		if (g_Game.IsMultiplayer())
		{
			m_RestartButton.Show(playerAlive && player.IsUnconscious() && !CfgGameplayHandler.GetDisableRespawnInUnconsciousness());
			m_RespawnButton.Show(playerDead);
		}
		else
		{
			m_RestartButton.Show(true);
			m_RespawnButton.Show(false);
			if (m_SeparatorPanel)
			{
				m_SeparatorPanel.Show(playerAlive);
			}
		}

		m_ContinueButton.Show(playerAlive);

		if (m_PlayZLifeStatsButton && !m_PlayZLifeStatsPanelOpen)
		{
			bool showLifeStats = playerDead && g_Game.IsMultiplayer() && m_PlayZLifeStatsDataReady;
			m_PlayZLifeStatsButton.Show(showLifeStats);
		}

		if (m_PlayZMenuPanel && !m_PlayZLifeStatsPanelOpen)
		{
			m_PlayZMenuPanel.Show(true);
		}
		#endif
	}
}
