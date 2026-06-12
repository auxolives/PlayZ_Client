modded class LoadingScreen
{
	void LoadingScreen(DayZGame game)
	{
		if (m_WidgetRoot)
		{
			m_WidgetRoot.Unlink();
			m_WidgetRoot = null;
		}

		m_DayZGame = game;
		m_WidgetRoot = game.GetLoadingWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_LOADING);

		m_ImageLogoMid = ImageWidget.Cast(m_WidgetRoot.FindAnyWidget("ImageLogoMid"));
		m_ImageLogoCorner = ImageWidget.Cast(m_WidgetRoot.FindAnyWidget("ImageLogoCorner"));
		m_TextWidgetTitle = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("TextWidget"));
		m_TextWidgetStatus = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("StatusText"));
		m_ImageWidgetBackground = ImageWidget.Cast(m_WidgetRoot.FindAnyWidget("ImageBackground"));
		m_ImageLoadingIcon = ImageWidget.Cast(m_WidgetRoot.FindAnyWidget("ImageLoadingIcon"));
		m_ModdedWarning = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("ModdedWarning"));
		m_ImageBackground = m_ImageWidgetBackground;
		m_ProgressLoading = ProgressBarWidget.Cast(m_WidgetRoot.FindAnyWidget("LoadingBar"));
		m_ProgressText = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("ProgressText"));

		string tmp;
		if (GetGame() && m_ProgressText)
		{
			m_ProgressText.Show(GetGame().CommandlineGetParam("loadingTest", tmp));
		}

		Widget notificationRoot = m_WidgetRoot.FindAnyWidget("notification_root");
		if (notificationRoot)
		{
			notificationRoot.Show(false);
		}

		if (m_ImageBackground)
		{
			m_ImageBackground.LoadImageFile(0, PlayZUIPaths.TEX_BACKGROUND);
			m_ImageBackground.Show(true);
		}

		if (m_ImageLogoMid)
		{
			m_ImageLogoMid.LoadImageFile(0, PlayZUIPaths.TEX_LOGO);
			m_ImageLogoMid.Show(true);
		}

		if (m_ImageLogoCorner)
		{
			m_ImageLogoCorner.Show(false);
		}

		if (m_ModdedWarning)
		{
			m_ModdedWarning.Show(false);
		}

		m_Counter = 0;
		game.GetBacklit().LoadingAnim();

		if (m_ProgressLoading)
		{
			m_ProgressLoading.SetColor(ARGB(255, 255, 255, 255));
			ProgressAsync.SetProgressData(m_ProgressLoading);
		}

		if (m_ImageBackground)
		{
			ProgressAsync.SetUserData(m_ImageBackground);
		}
	}

	override void SetTitle(string title)
	{
		if (m_TextWidgetTitle)
		{
			m_TextWidgetTitle.SetText(title);
		}
	}

	override void SetStatus(string status)
	{
		if (m_TextWidgetStatus)
		{
			m_TextWidgetStatus.SetText(status);
		}
	}

	override void ShowEx(DayZGame game)
	{
		Show();
	}

	override void Show()
	{
		if (!m_WidgetRoot)
		{
			return;
		}

		if (!m_WidgetRoot.IsVisible())
		{
			if (m_DayZGame.GetUIManager().IsDialogVisible())
			{
				m_DayZGame.GetUIManager().HideDialog();
			}

			m_WidgetRoot.Show(true);
		}

		if (m_ProgressLoading)
		{
			m_ProgressLoading.SetCurrent(0.0);
		}

		ProgressAsync.SetProgressData(m_ProgressLoading);
		ProgressAsync.SetUserData(m_ImageBackground);
	}

	override void Hide(bool force)
	{
		if (force)
		{
			while (m_Counter > 0)
			{
				Dec();
			}
		}

		if (m_Counter <= 0)
		{
			if (m_WidgetRoot)
			{
				m_WidgetRoot.Show(false);
			}

			ProgressAsync.SetUserData(null);
			ProgressAsync.SetProgressData(null);
			m_HintPanel = null;
		}
	}
}
