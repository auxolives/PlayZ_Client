modded class TerjePlayerSkillsAccessor
{
	override void AddSkillExperience(string skillId, int value, bool affectModifiers = true, bool showNotification = true)
	{
		int highBefore = 0;
		ref TerjeSkillCfg skillCfg;

		bool trackLevelUp = showNotification && m_Player && m_Player.GetTerjeProfile() && m_Player.GetIdentity();
		if (trackLevelUp && GetTerjeSkillsRegistry().FindSkill(skillId, skillCfg))
		{
			highBefore = m_Player.GetTerjeProfile().GetSkillHighRangeLevel(skillId);
		}
		else
		{
			trackLevelUp = false;
		}

		super.AddSkillExperience(skillId, value, affectModifiers, false);

		if (!trackLevelUp || !skillCfg)
		{
			return;
		}

		int highAfter = m_Player.GetTerjeProfile().GetSkillHighRangeLevel(skillId);
		if (highAfter <= highBefore)
		{
			return;
		}

		string message = skillCfg.GetDisplayName() + ": " + highAfter.ToString();
		NotificationSystem.SendNotificationToPlayerIdentityExtended(m_Player.GetIdentity(), 8, "", message, skillCfg.GetIcon());
	}
}
