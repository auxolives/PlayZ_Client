modded class TerjeSkillWidget
{
	private TextWidget m_PlayZ_PointsLabel;
	private int m_PlayZ_LastPointsValue = -1;

	private void PlayZ_RefreshSkillsView()
	{
		TerjeSkillsContainer skillsContainer = TerjeSkillsContainer.Cast(m_Parent);
		if (skillsContainer)
		{
			skillsContainer.Refresh();
			return;
		}

		Refresh();
	}

	override void OnResetSkillModalDialogResult(bool result)
	{
		super.OnResetSkillModalDialogResult(result);

		if (result)
		{
			PlayZ_RefreshSkillsView();
		}
	}

	override void OnPerkMouseUp(Widget w, int x, int y, int button)
	{
		super.OnPerkMouseUp(w, x, y, button);

		if (w && m_Player && m_Player.GetIdentity() && m_Player.IsAlive() && m_Player.GetTerjeSkills() && m_Skill != null)
		{
			PlayZ_RefreshSkillsView();
			OnPerkMouseEnter(w, x, y);
		}
	}

	override void OnPerkMouseDown(Widget w, int x, int y, int button)
	{
		if (!w)
			return;

		Widget highlightWidget = w.FindAnyWidget("terje_perk_highlight");
		if (highlightWidget)
		{
			highlightWidget.SetColor(ARGB(120, 0, 0, 0));
		}
	}

	override void Refresh()
	{
		super.Refresh();

		// Hide the per-category points label
		if (!m_PlayZ_PointsLabel)
			m_PlayZ_PointsLabel = TextWidget.Cast(GetMainWidget().FindAnyWidget("terje_skill_header_points"));
		if (m_PlayZ_PointsLabel)
			m_PlayZ_PointsLabel.Show(false);

		// Only update if value changed
		if (m_CurrentPerkPoints == m_PlayZ_LastPointsValue)
			return;
		m_PlayZ_LastPointsValue = m_CurrentPerkPoints;

		TerjeSkillsContainer skillsContainer = TerjeSkillsContainer.Cast(m_Parent);
		if (!skillsContainer)
			return;

		Header mainHeader = skillsContainer.GetHeader();
		if (!mainHeader)
			return;

		// Plain text: "SKILLS (12 Points Available)"
		string pts = Widget.TranslateString("#STR_PLAYZ_GLOBAL_PTS_LABEL");
		mainHeader.SetName("#STR_TERJESKILL_HEADER (" + m_CurrentPerkPoints + " " + pts + ")");
	}
}
