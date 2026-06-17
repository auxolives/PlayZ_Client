modded class JMWeatherForm
{
	private GridSpacerWidget m_PanelPlayZScenarios;
	private UIActionButtonToggle m_TogglePlayZScenarios;
	private ref array<ref UIActionButton> m_PlayZScenarioButtons;
	private ref array<string> m_PlayZScenarioButtonNames;

	override void InitRightPanel(Widget parent)
	{
		super.InitRightPanel(parent);
		InitPlayZScenarioWidgets(m_PanelWeatherActions);
		ToggleMenus();
	}

	private void InitPlayZScenarioWidgets(Widget actionsParent)
	{
		m_PlayZScenarioButtons = new array<ref UIActionButton>;
		m_PlayZScenarioButtonNames = new array<string>;

		m_PanelPlayZScenarios = GridSpacerWidget.Cast(UIActionManager.CreateGridSpacer(actionsParent, 2, 1));

		UIActionManager.CreateText(m_PanelPlayZScenarios, "scenario:", "Apply PlayZ weather scenarios with natural transition");

		Widget rowOne = UIActionManager.CreateGridSpacer(m_PanelPlayZScenarios, 1, 5);
		Widget rowTwo = UIActionManager.CreateGridSpacer(m_PanelPlayZScenarios, 1, 5);

		array<string> scenarioNames = PlayZWeatherScenarioNames.GetDefaultNames();
		int count = scenarioNames.Count();
		int i;
		for (i = 0; i < count; i++)
		{
			Widget rowParent = rowOne;
			if (i >= 5)
				rowParent = rowTwo;

			string scenarioName = scenarioNames[i];
			UIActionButton button = UIActionManager.CreateButton(rowParent, scenarioName, this, "OnClick_PlayZScenario");
			m_PlayZScenarioButtons.Insert(button);
			m_PlayZScenarioButtonNames.Insert(scenarioName);
		}

		UIActionManager.CreatePanel(m_PanelPlayZScenarios, 0xFF000000, 1);
	}

	override void InitTogglesWidgets(Widget actionsParent)
	{
		super.InitTogglesWidgets(actionsParent);

		Widget togglesRow = UIActionManager.CreateGridSpacer(m_PanelToggles, 1, 4);
		m_TogglePlayZScenarios = UIActionManager.CreateButtonToggle(togglesRow, "[  ] Scenario", "[×] Scenario", this, "OnClick_Toggle");
		m_TogglePlayZScenarios.SetToggle(true);
	}

	override void ToggleMenus()
	{
		super.ToggleMenus();

		if (!m_PanelPlayZScenarios)
			return;

		if (m_TogglePlayZScenarios && m_TogglePlayZScenarios.IsToggled() && !m_PresetsShown)
			m_PanelPlayZScenarios.Show(true);
		else
			m_PanelPlayZScenarios.Show(false);
	}

	override void UpdateStates()
	{
		super.UpdateStates();
		UpdatePlayZScenarioButtonStates();
	}

	private void UpdatePlayZScenarioButtonStates()
	{
		if (!m_PlayZScenarioButtons)
			return;

		bool hasNotSelectedPreset = false;
		if (m_PresetsShown)
			hasNotSelectedPreset = m_SelectedPreset == "";

		bool shouldDisable = hasNotSelectedPreset;

		int count = m_PlayZScenarioButtons.Count();
		int i;
		for (i = 0; i < count; i++)
		{
			UpdateActionState(m_PlayZScenarioButtons[i], "Weather.View", shouldDisable);
		}

		if (m_TogglePlayZScenarios)
			UpdateActionState(m_TogglePlayZScenarios, "Weather.View", hasNotSelectedPreset);
	}

	void OnClick_PlayZScenario(UIEvent eid, UIActionBase action)
	{
		PlayZWeatherDebug.Log("JMWeatherForm.OnClick_PlayZScenario: eid=" + eid);

		if (eid != UIEvent.CLICK)
			return;

		if (m_PresetsShown)
		{
			PlayZWeatherDebug.Log("JMWeatherForm.OnClick_PlayZScenario: presets shown, ignored");
			return;
		}

		if (!m_PlayZScenarioButtons || !m_PlayZScenarioButtonNames)
		{
			PlayZWeatherDebug.Log("JMWeatherForm.OnClick_PlayZScenario: button arrays null");
			return;
		}

		if (!m_Module)
		{
			PlayZWeatherDebug.Log("JMWeatherForm.OnClick_PlayZScenario: m_Module null");
			return;
		}

		int count = m_PlayZScenarioButtons.Count();
		int i;
		for (i = 0; i < count; i++)
		{
			if (action != m_PlayZScenarioButtons[i])
				continue;

			string scenarioName = m_PlayZScenarioButtonNames[i];
			PlayZWeatherDebug.Log("JMWeatherForm.OnClick_PlayZScenario: matched " + scenarioName);
			m_Module.SetPlayZScenario(scenarioName);
			return;
		}

		PlayZWeatherDebug.Log("JMWeatherForm.OnClick_PlayZScenario: no button match");
	}
}
