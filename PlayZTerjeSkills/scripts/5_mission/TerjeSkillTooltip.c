modded class TerjeSkillTooltip
{
	static ref Widget GetSkillTooltipWidget(TerjeSkillCfg skillCfg, int exp, int points)
	{
		if (m_skillTooltipInstance)
		{
			m_skillTooltipInstance.Show(false);
			m_skillTooltipInstance.Unlink();
			m_skillTooltipInstance = null;
		}

		return super.GetSkillTooltipWidget(skillCfg, exp, points);
	}
}
