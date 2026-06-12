modded class LoginTimeBase
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_LOGIN_TIME);

		m_txtDescription = TextWidget.Cast(layoutRoot.FindAnyWidget("txtDescription"));
		m_txtLabel = TextWidget.Cast(layoutRoot.FindAnyWidget("txtLabel"));
		m_btnLeave = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnLeave"));

		ImageWidget bg = ImageWidget.Cast(layoutRoot.FindAnyWidget("Background"));
		if (bg)
		{
			bg.LoadImageFile(0, PlayZUIPaths.TEX_BACKGROUND);
		}

		if (m_txtDescription)
		{
			m_txtDescription.Show(true);
		}

		Widget notificationRoot = layoutRoot.FindAnyWidget("notification_root");
		if (notificationRoot)
		{
			notificationRoot.Show(false);
		}

		#ifdef PLATFORM_CONSOLE
		Widget toolbarBg = layoutRoot.FindAnyWidget("toolbar_bg");
		if (toolbarBg)
		{
			bool showToolbar = !g_Game.GetInput().IsEnabledMouseAndKeyboardEvenOnServer() || g_Game.GetInput().GetCurrentInputDevice() == EInputDeviceType.CONTROLLER;
			toolbarBg.Show(showToolbar);
		}

		RichTextWidget toolbarB = RichTextWidget.Cast(layoutRoot.FindAnyWidget("BackIcon"));
		if (toolbarB)
		{
			toolbarB.SetText(InputUtils.GetRichtextButtonIconFromInputAction("UAUIBack", "", EUAINPUT_DEVICE_CONTROLLER, InputUtils.ICON_SCALE_TOOLBAR));
		}
		#endif

		return layoutRoot;
	}

	override void Show()
	{
		if (layoutRoot)
		{
			layoutRoot.Show(true);
		}
	}
}
