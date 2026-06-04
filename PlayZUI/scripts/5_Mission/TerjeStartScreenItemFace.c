// Source Found: TerjeStartScreen/Scripts/5_Mission/TerjeStartScreenItemFace.c:24
modded class TerjeStartScreenItemFace
{
	override string GetNativeLayout()
	{
		return "PlayZ_Client/PlayZUI/gui/layouts/PlayZ_terje_item_face.layout";
	}

	override void OnCommand(TerjeWidgetCommand command, float timeslice)
	{
		// Keep original command handling first.
		super.OnCommand(command, timeslice);

		if (command.IsInherited(TerjeWidgetCommand_FaceSelect))
		{
			if (!m_valid)
			{
				m_buttonBackground.SetColor(ARGB(255, 112, 45, 45));
				m_buttonForeground.SetColor(ARGB(255, 112, 45, 45));
			}
			else if (TerjeWidgetCommand_FaceSelect.Cast(command).m_state)
			{
				m_buttonBackground.SetColor(ARGB(255, 255, 48, 0));
				m_buttonForeground.SetColor(ARGB(255, 255, 48, 0));
			}
			else
			{
				m_buttonBackground.SetColor(ARGB(255, 60, 60, 60));
				m_buttonForeground.SetColor(ARGB(255, 60, 60, 60));
			}

			return;
		}

		if (command.IsInherited(TerjeWidgetCommand_FaceValid))
		{
			m_buttonLocked.SetColor(ARGB(120, 255, 255, 255));
			return;
		}
	}
}
