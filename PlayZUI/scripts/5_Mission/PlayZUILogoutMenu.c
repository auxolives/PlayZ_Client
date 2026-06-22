modded class LogoutMenu
{
	override Widget Init()
	{
		layoutRoot = g_Game.GetWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_LOGOUT);

		m_LogoutTimeText = TextWidget.Cast(layoutRoot.FindAnyWidget("txtLogoutTime"));
		m_DescriptionText = TextWidget.Cast(layoutRoot.FindAnyWidget("txtDescription"));
		m_bLogoutNow = ButtonWidget.Cast(layoutRoot.FindAnyWidget("bLogoutNow"));
		m_bCancel = ButtonWidget.Cast(layoutRoot.FindAnyWidget("bCancel"));

		#ifdef PLATFORM_CONSOLE
		m_bCancelConsole = ButtonWidget.Cast(layoutRoot.FindAnyWidget("bCancelConsole"));
		m_bCancel.Show(false);
		m_bLogoutNow.Show(false);
		#else
		m_bCancel.Show(true);
		m_bLogoutNow.Show(true);
		layoutRoot.FindAnyWidget("toolbar_bg").Show(false);
		#endif

		UpdateInfo();

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
}
