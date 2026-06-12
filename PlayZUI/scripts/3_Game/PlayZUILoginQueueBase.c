modded class LoginQueueBase
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_QUEUE);

		m_txtPosition = TextWidget.Cast(layoutRoot.FindAnyWidget("txtPosition"));
		m_txtNote = TextWidget.Cast(layoutRoot.FindAnyWidget("txtNote"));
		m_btnLeave = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnLeave"));

		ImageWidget bg = ImageWidget.Cast(layoutRoot.FindAnyWidget("Background"));
		if (bg)
		{
			bg.LoadImageFile(0, PlayZUIPaths.TEX_BACKGROUND);
		}

		if (m_txtNote)
		{
			m_txtNote.Show(false);
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
}
