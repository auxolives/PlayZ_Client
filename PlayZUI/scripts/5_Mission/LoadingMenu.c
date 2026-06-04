modded class LoadingMenu
{
	override Widget Init()
	{
		// Use our custom layout
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("PlayZ_Client/PlayZUI/gui/layouts/PlayZ_loading.layout");
		
		m_label = TextWidget.Cast( layoutRoot.FindAnyWidget("TextWidget") );
		m_progressBar = ProgressBarWidget.Cast( layoutRoot.FindAnyWidget("LoadingBar") );
		m_image = ImageWidget.Cast( layoutRoot.FindAnyWidget("ImageBackground") );
		
		// Background is handled by script now
		if (m_image)
		{
			m_image.LoadImageFile(0, PlayZUIManager.GetRandomBackground());
			m_image.Show(true);
		}
		
		return layoutRoot;
	}
}
