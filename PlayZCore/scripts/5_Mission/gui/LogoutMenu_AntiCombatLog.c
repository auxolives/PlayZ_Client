modded class LogoutMenu
{
	int m_PlayZKilledOnLogoutCB = -1;

	override void UpdateInfo()
	{
		super.UpdateInfo();

		if (!GetGame())
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player)
		{
			return;
		}

		if (m_bLogoutNow)
		{
			m_bLogoutNow.Show(false);
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(PlayZ_EnableLogoutButton, 1000, false);
		}

		if (player.WillBePunishedForCombatLogging() >= 1)
		{
			if (player.WillBePunishedForCombatLogging() == 3)
			{
				m_DescriptionText.SetText("#STR_PlayZ_ACL_LogoutNote_Extended");
			}
			else
			{
				if (player.WillBePunishedForCombatLogging() == 1)
				{
					m_DescriptionText.SetText("#STR_PlayZ_ACL_LogoutNote_Killed");
				}
				else
				{
					m_DescriptionText.SetText("#STR_PlayZ_ACL_LogoutNote_Flare");
				}
			}

			m_DescriptionText.SetColor(ARGB(255, 255, 0, 0));
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(PlayZ_EnableLogoutButton);
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(PlayZ_EnableLogoutButton, player.GetDisableExitButtonSecs() * 1000, false);
		}
		else
		{
			m_DescriptionText.SetColor(ARGB(255, 255, 255, 255));
		}
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player && m_PlayZKilledOnLogoutCB != player.WillBePunishedForCombatLogging())
		{
			UpdateInfo();
			m_PlayZKilledOnLogoutCB = player.WillBePunishedForCombatLogging();
		}
	}

	private void PlayZ_EnableLogoutButton()
	{
		if (GetGame() && m_bLogoutNow)
		{
			m_bLogoutNow.Show(true);
		}
	}
}
