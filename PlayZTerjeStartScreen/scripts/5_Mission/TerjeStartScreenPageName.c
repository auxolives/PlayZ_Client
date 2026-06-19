// LastNameEnabled=true: show last-name field, first name required, last name optional.
// Source Found: TerjeStartScreen/Scripts/5_Mission/TerjeStartScreenPageName.c:29-32

modded class TerjeStartScreenPageName
{
	override string GetNativeLayout()
	{
		return PlayZTerjeStartScreenPaths.LAYOUT_PAGE_NAME;
	}

	override void OnCommand(TerjeWidgetCommand command, float timeslice)
	{
		if (command.IsInherited(TerjeWidgetCommand_Clicked) && m_lastNameRequired)
		{
			if (!m_inputBlocked)
			{
				m_inputBlocked = true;
				if (!PlayZTrySubmitNameWithOptionalLastName())
				{
					m_inputBlocked = false;
				}
			}

			return;
		}

		super.OnCommand(command, timeslice);
	}

	protected bool PlayZTrySubmitNameWithOptionalLastName()
	{
		string firstInput = m_firstName.GetText();
		string lastInput = m_lastName.GetText();
		int lastLength = lastInput.LengthUtf8();

		if (!VerifyNameString(firstInput, m_outputFirstName))
		{
			if (lastLength > 0)
			{
				SetInfoMessage("#STR_PLAYZ_TERJESTARTSCREEN_NAME_FIRST_REQUIRED");
			}

			return false;
		}

		m_outputLastName = string.Empty;
		if (lastLength > 0)
		{
			if (!VerifyNameString(lastInput, m_outputLastName))
			{
				return false;
			}
		}

		string verifyName = m_outputFirstName;
		if (m_outputLastName != string.Empty)
		{
			verifyName = m_outputFirstName + " " + m_outputLastName;
		}

		GetTerjeRPC().SendToServer("startscreen.name.verify", new Param1<string>(verifyName));
		return true;
	}
}
