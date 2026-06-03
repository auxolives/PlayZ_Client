modded class TerjePlayerSkillsAccessor
{
	override int GetSkillPerkPoints(string skillId)
	{
		if (!m_Player || !m_Player.GetTerjeProfile())
			return 0;

		// Points are now calculated dynamically from all levels and perk status
		return m_Player.GetTerjeProfile().GetPlayZGlobalPerkPoints();
	}

	override void AddPerkLevel(string skillId, string perkId)
	{
		if (!m_Player || !m_Player.GetTerjeProfile())
			return;

		ref TerjeSkillCfg skillCfg;
		if (!GetTerjeSkillsRegistry().FindSkill(skillId, skillCfg)) return;

		ref TerjePerkCfg perkCfg;
		if (!skillCfg.FindPerk(perkId, perkCfg)) return;

		int currentLevel = m_Player.GetTerjeProfile().GetSkillPerk(skillId, perkId);
		int newLevel = currentLevel + 1;
		
		if (newLevel > perkCfg.GetStagesCount()) return;

		int requiredPoints = perkCfg.GetRequiredPerkPoints(newLevel - 1);
		int globalPoints = m_Player.GetTerjeProfile().GetPlayZGlobalPerkPoints();

		// Only check requirement. Once 'SetSkillPerk' is called, the 
		// dynamic calculation in TerjePlayerProfile will account for the cost.
		if (globalPoints >= requiredPoints)
		{
			m_Player.GetTerjeProfile().SetSkillPerk(skillId, perkId, newLevel);
		}
	}

	override void GetPerkStatus(string skillId, string perkId, out int perkLevel, out int activePerkLevel, out bool canBeUpgraded)
	{
		super.GetPerkStatus(skillId, perkId, perkLevel, activePerkLevel, canBeUpgraded);

		if (!m_Player || !m_Player.GetTerjeProfile()) return;

		ref TerjeSkillCfg skillCfg;
		if (!GetTerjeSkillsRegistry().FindSkill(skillId, skillCfg)) return;

		ref TerjePerkCfg perkCfg;
		if (!skillCfg.FindPerk(perkId, perkCfg)) return;

		int currentSkillExp = m_Player.GetTerjeProfile().GetSkillExperience(skillId);
		int currentSkillLevel = skillCfg.GetLevelFromExp(currentSkillExp);
		
		if (perkLevel >= 0 && perkLevel < perkCfg.GetStagesCount())
		{
			int requiredPerkPoints = perkCfg.GetRequiredPerkPoints(perkLevel);
			int requiredSkillLevel = perkCfg.GetRequiredSkillLevel(perkLevel);
			int globalPoints = m_Player.GetTerjeProfile().GetPlayZGlobalPerkPoints();

			canBeUpgraded = (requiredPerkPoints >= 0 && requiredPerkPoints <= globalPoints && currentSkillLevel >= requiredSkillLevel);
		}
	}
}
