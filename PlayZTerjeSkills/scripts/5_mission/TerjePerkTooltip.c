modded class TerjePerkTooltip
{
	static ref Widget GetPerkTooltipWidget(TerjePerkCfg perkCfg, int perkLevel, int perkActiveLevel, bool canBeUpgraded)
	{
		if (m_perkTooltipInstance)
		{
			m_perkTooltipInstance.Show(false);
			m_perkTooltipInstance.Unlink();
			m_perkTooltipInstance = null;
		}

		return super.GetPerkTooltipWidget(perkCfg, perkLevel, perkActiveLevel, canBeUpgraded);
	}
}
