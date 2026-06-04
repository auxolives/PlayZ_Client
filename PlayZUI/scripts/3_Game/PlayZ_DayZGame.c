modded class LoadingScreen
{
	void LoadingScreen(DayZGame game)
	{
		// The vanilla constructor already ran and created widgets from gui/layouts/loading.layout.
		// We MUST destroy those old widgets before creating our own to avoid double rendering.
		if (m_WidgetRoot)
		{
			m_WidgetRoot.Unlink();
			m_WidgetRoot = null;
		}
		
		m_DayZGame = game;
		m_WidgetRoot = game.GetLoadingWorkspace().CreateWidgets("PlayZ_Client/PlayZUI/gui/layouts/PlayZ_loading.layout");
		
		m_TextWidgetTitle = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("TextWidget"));
		m_TextWidgetStatus = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("StatusText"));
		m_ImageBackground = ImageWidget.Cast(m_WidgetRoot.FindAnyWidget("ImageBackground"));
		m_ImageWidgetBackground = m_ImageBackground; // Fix for vanilla Show() crash if not overridden
		m_ProgressLoading = ProgressBarWidget.Cast(m_WidgetRoot.FindAnyWidget("LoadingBar"));
		m_ProgressText = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("ProgressText"));
		
		string tmp;
		if (GetGame() && m_ProgressText)
			m_ProgressText.Show(GetGame().CommandlineGetParam("loadingTest", tmp));
		
		if (m_ImageBackground)
		{
			m_ImageBackground.LoadImageFile(0, PlayZUIManager.GetRandomBackground());
			m_ImageBackground.Show(true);
		}
		
		// Map remaining vanilla refs to avoid NULL crashes in case any other mod/vanilla script touches them
		m_ImageLogoMid = ImageWidget.Cast(m_WidgetRoot.FindAnyWidget("ImageLogo"));
		m_ImageLogoCorner = null;
		m_ImageLoadingIcon = null;
		m_ModdedWarning = null;
		
		m_Counter = 0;
		game.GetBacklit().LoadingAnim();
		
		if (m_ProgressLoading)
		{
			m_ProgressLoading.SetColor(ARGB(255, 255, 255, 255));
			ProgressAsync.SetProgressData(m_ProgressLoading);
		}
		
		if (m_ImageBackground)
			ProgressAsync.SetUserData(m_ImageBackground);
	}

	override void SetTitle(string title)
	{
		if (m_TextWidgetTitle)
			m_TextWidgetTitle.SetText(title);
	}

	override void SetStatus(string status)
	{
		if (m_TextWidgetStatus)
			m_TextWidgetStatus.SetText(status);
	}

	override void ShowEx(DayZGame game)
	{
		// Bypass UiHintPanelLoading creation completely
		Show();
	}

	override void Show()

	{
		if (!m_WidgetRoot) return;
		
		if (!m_WidgetRoot.IsVisible())
		{
			if (m_DayZGame.GetUIManager().IsDialogVisible())
				m_DayZGame.GetUIManager().HideDialog();
			
			m_WidgetRoot.Show(true);
		}
		
		if (m_ProgressLoading)
			m_ProgressLoading.SetCurrent(0.0);

		ProgressAsync.SetProgressData(m_ProgressLoading);
		ProgressAsync.SetUserData(m_ImageBackground);
	}

	override void Hide(bool force)
	{
		if (force)
		{
			while (m_Counter > 0)
				Dec();
		}

		if (m_Counter <= 0)
		{
			if (m_WidgetRoot) m_WidgetRoot.Show(false);
			ProgressAsync.SetUserData(null);
			ProgressAsync.SetProgressData(null);
			PlayZUIManager.ResetBackground();
		}
	}
}

modded class LoginQueueBase
{
	override Widget Init()
	{		
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("PlayZ_Client/PlayZUI/gui/layouts/PlayZ_dialog_queue_position.layout");
		
		m_txtPosition	= TextWidget.Cast(layoutRoot.FindAnyWidget("txtPosition"));
		m_txtNote 		= TextWidget.Cast(layoutRoot.FindAnyWidget("txtNote"));
		m_btnLeave 		= ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnLeave"));
		
		ImageWidget bg = ImageWidget.Cast(layoutRoot.FindAnyWidget("Background"));
		if (bg)
		{
			bg.LoadImageFile(0, PlayZUIManager.GetRandomBackground());
		}
		
		if (m_txtNote)
			m_txtNote.Show(true);

		return layoutRoot;
	}
}

modded class LoginTimeBase
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("PlayZ_Client/PlayZUI/gui/layouts/PlayZ_dialog_login_time.layout");
		
		m_txtDescription 	= TextWidget.Cast(layoutRoot.FindAnyWidget("txtDescription"));
		m_txtLabel 			= TextWidget.Cast(layoutRoot.FindAnyWidget("txtLabel"));
		m_btnLeave 			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnLeave"));
		
		ImageWidget bg = ImageWidget.Cast(layoutRoot.FindAnyWidget("Background"));
		if (bg)
		{
			bg.LoadImageFile(0, PlayZUIManager.GetRandomBackground());
		}
		
		if (m_txtDescription)
			m_txtDescription.Show(true);

		return layoutRoot;
	}
}
