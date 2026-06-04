class PlayZUIManager
{
	static string m_CurrentBackground = "";

	// Add Background02–05 paths here when .edds assets are ready.
	static const ref array<string> BACKGROUNDS = {
		"PlayZ_Client/PlayZUI/gui/textures/Background01.edds"
	};

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
