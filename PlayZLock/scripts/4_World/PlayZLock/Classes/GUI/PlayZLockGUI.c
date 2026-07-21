class PlayZLockGUI extends Managed
{
	static const string LAYOUT_FILE = "PlayZ_Client/PlayZLock/data/gui/layouts/PlayZLocksHUD.layout";

	ref Widget m_LayoutRoot;
	ref TextWidget m_ComboLockWidget;
	ref WidgetFadeTimer m_FadeTimer;

	void PlayZLockGUI()
	{
		m_LayoutRoot = GetGame().GetWorkspace().CreateWidgets(LAYOUT_FILE);

		if (!m_LayoutRoot)
			return;

		m_LayoutRoot.Show(true);
		m_ComboLockWidget = TextWidget.Cast(m_LayoutRoot.FindAnyWidget("ComboLockDial"));

		if (m_ComboLockWidget)
		{
			m_ComboLockWidget.SetText("");

			if (PlayZLockConfig.Get().ClientSyncConfig && PlayZLockConfig.Get().ClientSyncConfig.DisplayDigits == 2)
			{
				float x;
				float y;
				m_ComboLockWidget.GetPos(x, y);
				m_ComboLockWidget.SetPos(x, y + 1);
			}
		}

		m_FadeTimer = new WidgetFadeTimer();
	}

	void ~PlayZLockGUI()
	{
		if (!GetGame())
			return;

		if (m_FadeTimer && m_FadeTimer.IsRunning())
			m_FadeTimer.Stop();

		if (m_ComboLockWidget)
			m_ComboLockWidget.Show(false);

		delete m_ComboLockWidget;
		delete m_FadeTimer;
		delete m_LayoutRoot;
	}

	void SetText(string text)
	{
		if (m_ComboLockWidget)
		{
			m_ComboLockWidget.SetText(text);
			m_FadeTimer.FadeOut(m_ComboLockWidget, 1, false);
			ScheduleDeletion(5000);
		}
	}

	void ScheduleDeletion(int ms)
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.DeleteWidget);
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.DeleteWidget, ms, false);
	}

	void DeleteWidget()
	{
		delete this;
	}
}
