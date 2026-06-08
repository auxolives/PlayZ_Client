class PlayZUIManager
{
	static string m_CurrentBackground = "";
	static const string LOGO_TEXTURE = "PlayZ_Client/PlayZUI/gui/textures/LOGOTEXT.edds";

	// Add Background02–05 paths here when .edds assets are ready.
	static const ref array<string> BACKGROUNDS = {
		"PlayZ_Client/PlayZUI/gui/textures/Background01.edds"
	};

	// Matches layout tint "color 0 1 0.14 1" on PlayZ backgrounds.
	static int SignatureGreen()
	{
		return ARGB(255, 0, 255, 36);
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
			if (BACKGROUNDS.Count() == 1)
			{
				m_CurrentBackground = BACKGROUNDS.Get(0);
			}
			else
			{
				int randomIndex = Math.RandomInt(0, BACKGROUNDS.Count());
				m_CurrentBackground = BACKGROUNDS.Get(randomIndex);
			}
		}

		return m_CurrentBackground;
	}

	static void ResetBackground()
	{
		m_CurrentBackground = "";
	}
}
