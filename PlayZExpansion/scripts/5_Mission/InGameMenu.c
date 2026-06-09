// Expansion life statistics overlay for PlayZ ingame menu (dead players only).
// Source Found: DayZExpansion/DayZExpansion/Scripts/5_Mission/DayZExpansion/GUI/InGameMenu.c
// Bypasses UseDeathScreen / UseDeathScreenStatistics — stats from ExpansionMonitorModule.

modded class InGameMenu
{
	protected float m_PlayZLifeStatsDistance;
	protected float m_PlayZLifeStatsPlaytime;
	protected float m_PlayZLifeStatsPlayersKilled;
	protected float m_PlayZLifeStatsAIKilled;
	protected float m_PlayZLifeStatsInfectedKilled;
	protected float m_PlayZLifeStatsAnimalsKilled;
	protected float m_PlayZLifeStatsLongestShot;

	protected TextWidget m_PlayZLifeStatsPanelTitle;
	protected TextWidget m_PlayZLifeStatsLongestShotVal;
	protected TextWidget m_PlayZLifeStatsDistanceVal;
	protected TextWidget m_PlayZLifeStatsAnimalsKilledVal;
	protected TextWidget m_PlayZLifeStatsInfectedKilledVal;
	protected TextWidget m_PlayZLifeStatsPlayersKilledVal;
	protected TextWidget m_PlayZLifeStatsAIKilledVal;
	protected TextWidget m_PlayZLifeStatsTimeSurvivedVal;
	protected TextWidget m_PlayZLifeStatsAnimalsKilledLabel;
	protected ButtonWidget m_PlayZLifeStatsHideButton;
	protected bool m_PlayZLifeStatsInvokerRegistered;

	override void OnShow()
	{
		super.OnShow();
	#ifdef EXPANSIONMONITORMODULE
		if (!m_PlayZLifeStatsInvokerRegistered)
		{
			ExpansionMonitorModule monitor;
			if (CF_Modules<ExpansionMonitorModule>.Get(monitor))
			{
				monitor.m_StatsInvoker.Insert(PlayZOnLifeStatsDataReceived);
				m_PlayZLifeStatsInvokerRegistered = true;
			}
		}
		PlayZRefreshLifeStatsData();
	#endif
	}

	override void OnHide()
	{
		PlayZCloseLifeStatsPanel();
	#ifdef EXPANSIONMONITORMODULE
		if (m_PlayZLifeStatsInvokerRegistered)
		{
			ExpansionMonitorModule monitor;
			if (CF_Modules<ExpansionMonitorModule>.Get(monitor))
			{
				monitor.m_StatsInvoker.Remove(PlayZOnLifeStatsDataReceived);
			}
			m_PlayZLifeStatsInvokerRegistered = false;
		}
	#endif
		super.OnHide();
	}

	override protected void PlayZOnInitLifeStatsIntegration()
	{
	#ifdef EXPANSIONMONITORMODULE
		if (!layoutRoot)
		{
			return;
		}

		m_PlayZLifeStatsOverlayRoot = g_Game.GetWorkspace().CreateWidgets("DayZExpansion/GUI/layouts/ui/expansion_dead_screen.layout", layoutRoot);
		if (!m_PlayZLifeStatsOverlayRoot)
		{
			return;
		}

		m_PlayZLifeStatsOverlayRoot.Show(false);

		Widget deadScreen = m_PlayZLifeStatsOverlayRoot.FindAnyWidget("dead_screen");
		if (deadScreen)
		{
			deadScreen.Show(false);
		}

		Widget statsButtonPanel = m_PlayZLifeStatsOverlayRoot.FindAnyWidget("ButtonPanel");
		if (statsButtonPanel)
		{
			statsButtonPanel.Show(false);
		}

		m_PlayZLifeStatsPanel = m_PlayZLifeStatsOverlayRoot.FindAnyWidget("PlayerStatisticsPanel");
		if (m_PlayZLifeStatsPanel)
		{
			m_PlayZLifeStatsPanel.Show(false);
		}

		m_PlayZLifeStatsPanelTitle = TextWidget.Cast(m_PlayZLifeStatsOverlayRoot.FindAnyWidget("Caption"));
		m_PlayZLifeStatsLongestShotVal = TextWidget.Cast(m_PlayZLifeStatsOverlayRoot.FindAnyWidget("LongRangeShotValue"));
		m_PlayZLifeStatsDistanceVal = TextWidget.Cast(m_PlayZLifeStatsOverlayRoot.FindAnyWidget("DistanceTraveledValue"));
		m_PlayZLifeStatsAnimalsKilledVal = TextWidget.Cast(m_PlayZLifeStatsOverlayRoot.FindAnyWidget("AnimalsKilledValue"));
		m_PlayZLifeStatsInfectedKilledVal = TextWidget.Cast(m_PlayZLifeStatsOverlayRoot.FindAnyWidget("InfectedKilledValue"));
		m_PlayZLifeStatsPlayersKilledVal = TextWidget.Cast(m_PlayZLifeStatsOverlayRoot.FindAnyWidget("PlayersKilledValue"));
		m_PlayZLifeStatsAIKilledVal = TextWidget.Cast(m_PlayZLifeStatsOverlayRoot.FindAnyWidget("AIKilledValue"));
		m_PlayZLifeStatsTimeSurvivedVal = TextWidget.Cast(m_PlayZLifeStatsOverlayRoot.FindAnyWidget("TimeSurvivedValue"));
		m_PlayZLifeStatsAnimalsKilledLabel = TextWidget.Cast(m_PlayZLifeStatsOverlayRoot.FindAnyWidget("AnimalsKilledLabel"));
		m_PlayZLifeStatsHideButton = ButtonWidget.Cast(m_PlayZLifeStatsOverlayRoot.FindAnyWidget("bHide"));

		if (m_PlayZLifeStatsAnimalsKilledLabel)
		{
			m_PlayZLifeStatsAnimalsKilledLabel.SetText("#STR_PlayZ_Animals_killed");
		}

		PlayZTryLoadLifeStatsFromMonitor();
	#endif
	}

	override protected void PlayZRefreshLifeStatsData()
	{
	#ifdef EXPANSIONMONITORMODULE
		PlayZTryLoadLifeStatsFromMonitor();
	#endif
	}

	override protected bool PlayZOnLifeStatsMenuClick(Widget w)
	{
	#ifdef EXPANSIONMONITORMODULE
		if (!w)
		{
			return false;
		}

		string wn = w.GetName();
		if (wn == "life_stats_button" || wn == "life_stats_button_label")
		{
			PlayZUpdateLifeStatValues();
			PlayZOpenLifeStatsPanel();
			return true;
		}

		if (w == m_PlayZLifeStatsHideButton || wn == "bHideLable")
		{
			PlayZCloseLifeStatsPanel();
			return true;
		}
	#endif

		return false;
	}

	override protected void PlayZCloseLifeStatsPanel()
	{
	#ifdef EXPANSIONMONITORMODULE
		if (m_PlayZLifeStatsPanel)
		{
			m_PlayZLifeStatsPanel.Show(false);
		}

		if (m_PlayZLifeStatsOverlayRoot)
		{
			m_PlayZLifeStatsOverlayRoot.Show(false);
		}
	#endif
		super.PlayZCloseLifeStatsPanel();
	}

#ifdef EXPANSIONMONITORMODULE
	protected void PlayZOnLifeStatsDataReceived(ExpansionSyncedPlayerStats player_stats)
	{
		if (!player_stats || !player_stats.m_HasRegisteredStats)
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!player || !player.GetIdentity())
		{
			return;
		}

		if (player.GetIdentity().Expansion_GetPlainId() != player_stats.m_PlainID)
		{
			return;
		}

		if (PlayZTryLoadLifeStatsFromMonitor())
		{
			UpdateGUI();
		}
	}

	protected bool PlayZTryLoadLifeStatsFromMonitor()
	{
		ExpansionMonitorModule monitor;
		if (!CF_Modules<ExpansionMonitorModule>.Get(monitor))
		{
			m_PlayZLifeStatsDataReady = false;
			return false;
		}

		ExpansionSyncedPlayerStats player_stats = monitor.GetClientStats();
		if (!player_stats || !player_stats.m_HasRegisteredStats)
		{
			m_PlayZLifeStatsDataReady = false;
			return false;
		}

		m_PlayZLifeStatsDistance = player_stats.m_Distance;
		m_PlayZLifeStatsPlaytime = player_stats.m_Playtime;
		m_PlayZLifeStatsPlayersKilled = player_stats.m_PlayersKilled;
	#ifdef ENFUSION_AI_PROJECT
		m_PlayZLifeStatsAIKilled = player_stats.m_AIKilled;
	#endif
		m_PlayZLifeStatsInfectedKilled = player_stats.m_InfectedKilled;
		m_PlayZLifeStatsAnimalsKilled = player_stats.m_AnimalsKilled;
		m_PlayZLifeStatsLongestShot = player_stats.m_LongestShot;
		m_PlayZLifeStatsDataReady = true;
		return true;
	}

	protected string PlayZGetLifeStatsDisplayName(PlayerBase player)
	{
		if (!player)
		{
			return string.Empty;
		}

		if (player.GetTerjeProfile() != null)
		{
			string firstName = player.GetTerjeProfile().GetFirstName();
			if (firstName != string.Empty)
			{
				return firstName;
			}
		}

		if (player.GetIdentity())
		{
			return player.GetIdentity().GetName();
		}

		return string.Empty;
	}

	protected void PlayZUpdateLifeStatValues()
	{
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!player)
		{
			return;
		}

		if (m_PlayZLifeStatsPanelTitle)
		{
			string name = PlayZGetLifeStatsDisplayName(player);
			if (name != string.Empty)
			{
				StringLocaliser player_name = new StringLocaliser("STR_EXPANSION_DEADSCREEN_STATS_TITLE", name);
				m_PlayZLifeStatsPanelTitle.SetText(player_name.Format());
			}
		}

		if (m_PlayZLifeStatsLongestShotVal)
		{
			m_PlayZLifeStatsLongestShotVal.SetText(ExpansionStatic.GetDistanceString(m_PlayZLifeStatsLongestShot));
		}

		if (m_PlayZLifeStatsDistanceVal)
		{
			m_PlayZLifeStatsDistanceVal.SetText(ExpansionStatic.GetDistanceString(m_PlayZLifeStatsDistance));
		}

		if (m_PlayZLifeStatsAnimalsKilledVal)
		{
			m_PlayZLifeStatsAnimalsKilledVal.SetText(ExpansionStatic.GetValueString(m_PlayZLifeStatsAnimalsKilled));
		}

		if (m_PlayZLifeStatsInfectedKilledVal)
		{
			m_PlayZLifeStatsInfectedKilledVal.SetText(ExpansionStatic.GetValueString(m_PlayZLifeStatsInfectedKilled));
		}

		if (m_PlayZLifeStatsPlayersKilledVal)
		{
			m_PlayZLifeStatsPlayersKilledVal.SetText(ExpansionStatic.GetValueString(m_PlayZLifeStatsPlayersKilled));
		}

	#ifdef ENFUSION_AI_PROJECT
		if (m_PlayZLifeStatsAIKilledVal)
		{
			m_PlayZLifeStatsAIKilledVal.SetText(ExpansionStatic.GetValueString(m_PlayZLifeStatsAIKilled));
			m_PlayZLifeStatsAIKilledVal.Show(true);
		}
	#else
		if (m_PlayZLifeStatsAIKilledVal)
		{
			m_PlayZLifeStatsAIKilledVal.Show(false);
		}
	#endif

		if (m_PlayZLifeStatsTimeSurvivedVal)
		{
			m_PlayZLifeStatsTimeSurvivedVal.SetText(ExpansionStatic.GetTimeString(m_PlayZLifeStatsPlaytime));
		}
	}

	protected void PlayZOpenLifeStatsPanel()
	{
		if (!m_PlayZLifeStatsOverlayRoot || !m_PlayZLifeStatsPanel)
		{
			return;
		}

		m_PlayZLifeStatsPanelOpen = true;
		PlayZSetMenuPanelVisible(false);
		m_PlayZLifeStatsOverlayRoot.Show(true);
		m_PlayZLifeStatsPanel.Show(true);
		m_PlayZLifeStatsOverlayRoot.SetSort(1024);
		m_PlayZLifeStatsPanel.SetSort(1025);
	}
#endif
}
