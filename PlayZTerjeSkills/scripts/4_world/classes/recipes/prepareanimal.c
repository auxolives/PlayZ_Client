modded class PrepareAnimal
{
	override protected void TerjeSkillsSpecificLogic(ItemBase ingredients[], PlayerBase player, array<ItemBase> results)
	{
		if (!player || !player.IsAlive() || !player.GetTerjeSkills())
			return;

		// --- Hoist Modifier Values -------------------------------------------
		// meathuntmod_plz: per-level meat quantity bonus (0.035/level, 30 levels = 1.05 max)
		float meathuntModifier = 0;
		player.GetTerjeSkills().GetSkillModifierValue("hunt", "meathuntmod_plz", meathuntModifier);

		// plmastermod_plz: per-level pelt quality bonus (0.033/level, 30 levels = ~0.99 max)
		float plmasterModifier = 0;
		player.GetTerjeSkills().GetSkillModifierValue("hunt", "plmastermod_plz", plmasterModifier);

		// --- Hoist Settings --------------------------------------------------
		float meathunterInitSetting = 0.15;
		GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_HUNTING_OVERRIDE_MEAT_INIT_QUANTITY, meathunterInitSetting);

		float meathunterMinSetting = 0.15;
		GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_HUNTING_OVERRIDE_MEAT_MIN_QUANTITY, meathunterMinSetting);

		float bonesInitHP = 0.5;
		GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_HUNTING_OVERRIDE_BONES_INIT_HP, bonesInitHP);

		// --- Build item list (results + ground-spawned cache) ----------------
		// NOTE: We iterate but NEVER delete items here. The engine's spawned_objects
		// array is still referenced on the call stack above Do(). Deletion causes
		// Access Violation as the C++ frame unwinds. We only modify values.
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

		// --- Apply per-item scaling ------------------------------------------
		foreach (ItemBase item : resultItems)
		{
			if (!item)
				continue;

			// Meat: scale quantity based on meathuntmod_plz modifier
			// Base is meathunterInitSetting, scales up linearly with skill
			if (item.IsMeat() && item.HasQuantity())
			{
				float qMax = item.GetQuantityMax();
				float quantMin = qMax * meathunterMinSetting;
				float quantBase = qMax * meathunterInitSetting;
				float quantBonus = (qMax - quantMin) * Math.Clamp(meathuntModifier, 0, 1);
				float quantFinal = Math.Clamp(quantBase + quantBonus, quantMin, qMax);
				float jitter = (Math.RandomFloat01() * 2.0 - 1.0) * (qMax * 0.05);
				quantFinal = Math.Clamp(quantFinal + jitter, quantMin, qMax);
				item.SetQuantity(quantFinal);
			}
			// Pelt: health and quantity scale with plmastermod_plz modifier
			else if (item.IsPeltBase())
			{
				float peltQuality = Math.Clamp(plmasterModifier, 0.05, 1.0);
				item.SetHealth01("", "", peltQuality);
				if (item.HasQuantity())
					item.SetQuantityNormalized(peltQuality);
			}
			// Bones: scale with the higher of the two modifiers
			else if (item.IsInherited(Bone))
			{
				float boneQuality = Math.Clamp(Math.Max(bonesInitHP, Math.Max(meathuntModifier, plmasterModifier)), 0.05, 1.0);
				item.SetHealth01("", "", boneQuality);
			}
		}

		// --- Experience Gain -------------------------------------------------
		ItemBase animalBody = ingredients[0];
		if (animalBody)
		{
			float expGainModifier;
			if (GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_HUNTING_BUTCH_ANIMAL_EXP_GAIN_MODIFIER, expGainModifier))
			{
				int expBase = GetGame().ConfigGetInt("CfgVehicles " + animalBody.GetType() + " terjeOnButchHuntingExp");
				int huntExp = (int)(expBase * expGainModifier);
				if (huntExp > 0)
					player.GetTerjeSkills().AddSkillExperience("hunt", huntExp);
			}
		}
	}
}