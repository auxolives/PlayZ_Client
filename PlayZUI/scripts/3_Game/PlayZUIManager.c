class PlayZUIManager
{
	static string m_CurrentBackground = "";
	static const string LOGO_TEXTURE = "PlayZ_Client/PlayZUI/gui/textures/LOGOTEXT.edds";
	static const string DEFAULT_BACKGROUND = "PlayZ_Client/PlayZUI/gui/textures/Background01.edds";

	// Layout tint color 0 0.824 1 1 on PlayZ backgrounds, accent 00D2FF.
	static int SignatureAccent()
	{
		return ARGB(255, 0, 210, 255);
	}

	static void ApplyPlayZLogo(ImageWidget logo)
	{
		if (!logo)
		{
			return;
		}
		logo.LoadImageFile(0, LOGO_TEXTURE);
		logo.SetColor(ARGB(255, 255, 255, 255));
	}

	static void ApplyPlayZLogoOnRoot(Widget root)
	{
		if (!root)
		{
			return;
		}
		ApplyPlayZLogo(ImageWidget.Cast(root.FindAnyWidget("ImageLogo")));
		ApplyPlayZLogo(ImageWidget.Cast(root.FindAnyWidget("play_image")));
	}

	static string GetRandomBackground()
	{
		if (m_CurrentBackground == "")
		{
			m_CurrentBackground = DEFAULT_BACKGROUND;
		}

		return m_CurrentBackground;
	}

	static void ResetBackground()
	{
		m_CurrentBackground = "";
	}
}
