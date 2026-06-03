modded class ActionSkinningCB 
{
	override void CreateActionComponent()
	{
		super.CreateActionComponent();
		
		// PlayZ Override: Handle level-based quick skinning modifier
		if (m_ActionData.m_Player && m_ActionData.m_Player.IsAlive() && m_ActionData.m_Player.GetTerjeSkills() != null)
		{
			float quickcutMod = 0;
			if (m_ActionData.m_Player.GetTerjeSkills().GetSkillModifierValue("hunt", "quickcutmod_plz", quickcutMod))
			{
				float overrideSkinningTime = -1;
				if (GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_HUNTING_OVERRIDE_SKINNING_TIME, overrideSkinningTime) && overrideSkinningTime > 0)
				{
					// Apply our modifier (e.g. -75% at level 30)
					float terjeSkinningTime = overrideSkinningTime * Math.Clamp(1.0 + quickcutMod, 0.1, 1);
					
					// Re-apply item and animal modifiers to stay consistent with base mod mechanics
					if (m_ActionData.m_MainItem)
					{
						string toolType = m_ActionData.m_MainItem.GetType();
						if (GetTerjeGameConfig().ConfigIsExisting("CfgVehicles " + toolType + " terjeSkinningTimeModifier"))
							terjeSkinningTime *= GetTerjeGameConfig().ConfigGetFloat("CfgVehicles " + toolType + " terjeSkinningTimeModifier");
						
						if (GetTerjeGameConfig().ConfigIsExisting("CfgVehicles " + toolType + " terjeSkinningTimeModifierOverride"))
							terjeSkinningTime = GetTerjeGameConfig().ConfigGetFloat("CfgVehicles " + toolType + " terjeSkinningTimeModifierOverride");
					}
					
					if (m_ActionData.m_Target != null)
					{
						AnimalBase animalBody = AnimalBase.Cast(m_ActionData.m_Target.GetObject());
						if (animalBody && GetTerjeGameConfig().ConfigIsExisting("CfgVehicles " + animalBody.GetType() + " terjeSkinningTimeModifier"))
							terjeSkinningTime *= GetTerjeGameConfig().ConfigGetFloat("CfgVehicles " + animalBody.GetType() + " terjeSkinningTimeModifier");
					}

					m_ActionData.m_ActionComponent = new CAContinuousTime(terjeSkinningTime);
				}
			}
		}
	}
}

modded class ActionSkinning
{
	override void TerjeProcessServerSpawnedItems(PlayerBase player)
	{
		if (!player || !player.GetTerjeSkills() || !m_terjeSpawnedItemsCache)
			return;

		// Run base mod logic (Terje's perk-based adjustments). Our config disables those perks,
		// so we apply our modifier-based yield/quality scaling after super() to restore expected behavior.
		super.TerjeProcessServerSpawnedItems(player);

		float meathuntSkill = 0;
		player.GetTerjeSkills().GetSkillModifierValue("hunt", "meathuntmod_plz", meathuntSkill);

		float plmasterSkill = 0;
		player.GetTerjeSkills().GetSkillModifierValue("hunt", "plmastermod_plz", plmasterSkill);

		float meathunterInitSetting = 0.15;
		GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_HUNTING_OVERRIDE_MEAT_INIT_QUANTITY, meathunterInitSetting);

		float meathunterMinSetting = 0.15;
		GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_HUNTING_OVERRIDE_MEAT_MIN_QUANTITY, meathunterMinSetting);

		float bonesInitHP = 0.5;
		GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_HUNTING_OVERRIDE_BONES_INIT_HP, bonesInitHP);

		PlayZTerjeSkills_HuntingHelper.ProcessHuntingSkills(player, m_terjeSpawnedItemsCache, meathuntSkill, plmasterSkill, meathunterInitSetting, meathunterMinSetting, bonesInitHP);

		// Custom item post-processing (delegate to base hook)
		foreach (ItemBase item : m_terjeSpawnedItemsCache)
		{
			if (item && !item.IsMeat() && !item.IsPeltBase() && !item.IsInherited(Bone))
			{
				TerjeProcessServerSpawnedCustomItem(player, item);
			}
		}
	}
}
