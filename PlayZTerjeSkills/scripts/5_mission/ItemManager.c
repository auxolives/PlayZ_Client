modded class ItemManager
{
	override void HideTooltip()
	{
		if (m_terjeSkillsTooltip != null)
		{
			m_terjeSkillsTooltip.Show(false);
		}

		super.HideTooltip();
	}
}
