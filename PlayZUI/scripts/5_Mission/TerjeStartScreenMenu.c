// Source Found: TerjeStartScreen/Scripts/5_Mission/TerjeStartScreenMenu.c:13-29
// Terje applies white before setting BackgroundImage, so we re-apply PlayZ tint here.
modded class TerjeStartScreenMenu
{
	override void SetTerjeParams(TerjeStartScreenParams params)
	{
		super.SetTerjeParams(params);

		if (params == null)
		{
			return;
		}

		if (m_backgroundImage != null && params.m_background != "")
		{
			// Match PlayZ UI background tint: color 1 0.188 0 1
			m_backgroundImage.SetColor(ARGB(255, 255, 48, 0));
		}
	}
}
