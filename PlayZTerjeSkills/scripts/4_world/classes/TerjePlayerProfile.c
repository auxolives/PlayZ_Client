modded class TerjePlayerProfile
{
	private int m_PlayZ_CachedGlobalPoints = 0;
	private float m_PlayZ_LastCalcTimestamp = -1.0;
	private bool m_PlayZ_ForceDirty = true;

	// Catch any local state change (like Perk Purchase) to flag 
	// the cache as dirty for instant UI feedback.
	override void SetIntValue(int id, int value)
	{
		super.SetIntValue(id, value);
		m_PlayZ_ForceDirty = true;
	}

	override void SetFloatValue(int id, float value)
	{
		super.SetFloatValue(id, value);
		m_PlayZ_ForceDirty = true;
	}

	override void SetBoolValue(int id, bool value)
	{
		super.SetBoolValue(id, value);
		m_PlayZ_ForceDirty = true;
	}

	override void SetStringValue(int id, string value)
	{
		super.SetStringValue(id, value);
		m_PlayZ_ForceDirty = true;
	}

	int GetPlayZGlobalPerkPoints()
	{
		float currentTime = GetGame().GetTickTime();
		
		// CPU Optimization (ENGINE_TRUTH: Update Frequency)
		// We implement a 50ms Throttle. The O(N*M) calculation will only run twice per second 
		// at most, which provides perfect accuracy with minimal CPU budget impact.
		// Local changes (m_PlayZ_ForceDirty) still trigger instant recalculation.
		if (m_PlayZ_ForceDirty || (currentTime - m_PlayZ_LastCalcTimestamp) > 0.05)
		{
			m_PlayZ_CachedGlobalPoints = CalculatePlayZGlobalPerkPoints();
			m_PlayZ_LastCalcTimestamp = currentTime;
			m_PlayZ_ForceDirty = false;
		}

		return m_PlayZ_CachedGlobalPoints;
	}

	private int CalculatePlayZGlobalPerkPoints()
	{
		int totalEarned = 0;
		int totalSpent = 0;

		ref array<ref TerjeSkillCfg> skillsList = new array<ref TerjeSkillCfg>;
		GetTerjeSkillsRegistry().GetSkills(skillsList);

		foreach (ref TerjeSkillCfg skillCfg : skillsList)
		{
			string skillId = skillCfg.GetId();
			
			// 1. Calculate Earned Points logic
			int exp = GetSkillExperience(skillId);
			int level = skillCfg.GetLevelFromExp(exp);
			totalEarned += level * skillCfg.GetPerkPointsPerLevel();

			// 2. Calculate Spent Points logic
			ref map<string, int> perkRecords;
			if (m_TerjeSkills_Perks.Find(skillId, perkRecords))
			{
				foreach (string perkId, int recordId : perkRecords)
				{
					int currentPerkLevel = GetIntValue(recordId);
					if (currentPerkLevel > 0)
					{
						ref TerjePerkCfg perkCfg;
						if (skillCfg.FindPerk(perkId, perkCfg))
						{
							for (int i = 0; i < currentPerkLevel; i++)
							{
								totalSpent += perkCfg.GetRequiredPerkPoints(i);
							}
						}
					}
				}
			}
		}

		return Math.Max(0, totalEarned - totalSpent);
	}

	// Legacy method kept for compatibility
	void SetPlayZGlobalPerkPoints(int value)
	{
		// No-op: Balance is derived from Skill Levels and Perk Status.
	}
}
