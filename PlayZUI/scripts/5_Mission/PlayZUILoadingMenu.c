modded class LoadingMenu
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_LOADING);

		m_label = TextWidget.Cast(layoutRoot.FindAnyWidget("TextWidget"));
		m_progressBar = ProgressBarWidget.Cast(layoutRoot.FindAnyWidget("LoadingBar"));
		if (!m_progressBar)
		{
			m_progressBar = ProgressBarWidget.Cast(layoutRoot.FindAnyWidget("ProgressBarWidget"));
		}

		m_image = ImageWidget.Cast(layoutRoot.FindAnyWidget("ImageBackground"));
		if (m_image)
		{
			m_image.LoadImageFile(0, PlayZUIPaths.TEX_BACKGROUND);
			m_image.Show(true);
		}

		Widget notificationRoot = layoutRoot.FindAnyWidget("notification_root");
		if (notificationRoot)
		{
			notificationRoot.Show(false);
		}

		return layoutRoot;
	}
}
