modded class PrepareAnimal
{
	override protected void TerjeSkillsSpecificLogic(PlayerBase player, array<ItemBase> results, int huntExp)
	{
		super.TerjeSkillsSpecificLogic(player, results, huntExp);

		if (!player || !player.IsAlive() || !player.GetTerjeSkills())
			return;

		float meathuntModifier = 0;
		player.GetTerjeSkills().GetSkillModifierValue("hunt", "meathuntmod_plz", meathuntModifier);

		float plmasterModifier = 0;
		player.GetTerjeSkills().GetSkillModifierValue("hunt", "plmastermod_plz", plmasterModifier);

		float meathunterInitSetting = 0.15;
		GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_HUNTING_OVERRIDE_MEAT_INIT_QUANTITY, meathunterInitSetting);

		float meathunterMinSetting = 0.15;
		GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_HUNTING_OVERRIDE_MEAT_MIN_QUANTITY, meathunterMinSetting);

		float bonesInitHP = 0.5;
		GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_HUNTING_OVERRIDE_BONES_INIT_HP, bonesInitHP);

		array<ItemBase> resultItems = new array<ItemBase>;
		foreach (ItemBase resItem : results)
		{
			if (resItem && resultItems.Find(resItem) == -1)
				resultItems.Insert(resItem);
		}

		if (player.m_terjeSkillsSpawnEntityOnGroundCache != null)
		{
			foreach (ItemBase cacheItem : player.m_terjeSkillsSpawnEntityOnGroundCache)
			{
				if (cacheItem && resultItems.Find(cacheItem) == -1)
					resultItems.Insert(cacheItem);
			}
		}

		PlayZTerjeSkills_HuntingHelper.ProcessHuntingSkills(player, resultItems, meathuntModifier, plmasterModifier, meathunterInitSetting, meathunterMinSetting, bonesInitHP);
	}
}
