modded class LogoutMenu
{
	// Source Found: scripts/5_Mission/GUI/LogoutMenu.c:169
	// ZenAntiCombatLogout overrides this flow and can tint description red.
	// Keep PlayZ dialog copy consistently readable with white body text.
	protected void PlayZEnsureLogoutDescriptionWhite()
	{
		if (m_DescriptionText)
		{
			m_DescriptionText.SetColor(ARGB(255, 255, 255, 255));
		}
	}

	override Widget Init()
	{
		layoutRoot = g_Game.GetWorkspace().CreateWidgets("PlayZ_Client/PlayZUI/gui/layouts/PlayZ_day_z_logout_dialog.layout");
		
		m_LogoutTimeText 	= TextWidget.Cast(layoutRoot.FindAnyWidget("txtLogoutTime"));
		m_DescriptionText 	= TextWidget.Cast(layoutRoot.FindAnyWidget("txtDescription"));
		m_bLogoutNow 		= ButtonWidget.Cast(layoutRoot.FindAnyWidget("bLogoutNow"));
		m_bCancel 			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("bCancel"));
		
		#ifdef PLATFORM_CONSOLE
		m_bCancelConsole	= ButtonWidget.Cast(layoutRoot.FindAnyWidget("bCancelConsole"));
		m_bCancel.Show(false);
		m_bLogoutNow.Show(false);
		#else
		m_bCancel.Show(true);
		m_bLogoutNow.Show(true);
		layoutRoot.FindAnyWidget("toolbar_bg").Show(false);
		#endif
		
		UpdateInfo();
		PlayZEnsureLogoutDescriptionWhite();
		
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (player.GetEmoteManager() && !player.IsRestrained() && !player.IsUnconscious()) 
		{
			player.GetEmoteManager().SetClientLoggingOut(true);
		}

		#ifdef PLATFORM_CONSOLE
		if (g_Game.GetMission())
		{
			g_Game.GetMission().GetOnInputDeviceChanged().Insert(OnInputDeviceChanged);
		}
		
		OnInputDeviceChanged(g_Game.GetInput().GetCurrentInputDevice());
		#endif

		return layoutRoot;
	}

	override void UpdateInfo()
	{
		super.UpdateInfo();
		PlayZEnsureLogoutDescriptionWhite();
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);
		PlayZEnsureLogoutDescriptionWhite();
	}
}
