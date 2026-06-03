// Shared hunting skill processing logic used by ActionSkinning and PrepareAnimal.
class PlayZTerjeSkills_HuntingHelper
{
	// Applies meat quantity, pelt quality, and bone quality scaling based on
	// hunt skill modifiers. NEVER calls item.Delete() — items must be zeroed
	// via SetQuantity(0)/SetHealth(0) so the engine manages lifecycle safely.
	static void ProcessHuntingSkills(PlayerBase player, array<ItemBase> spawnedItems, float meathuntModifier, float plmasterModifier, float meathunterInitSetting, float meathunterMinSetting, float bonesInitHP)
	{
		if (!player || !spawnedItems)
			return;

		int count = spawnedItems.Count();
		for (int i = 0; i < count; i++)
		{
			ItemBase item = spawnedItems.Get(i);
			if (!item)
				continue;

			if (item.IsMeat() && item.HasQuantity())
			{
				float qMax = item.GetQuantityMax();
				float quantMin = qMax * meathunterMinSetting;
				float quantBase = qMax * meathunterInitSetting;
				float quantBonus = (qMax - quantMin) * Math.Clamp(meathuntModifier, 0, 1);
				float quantFinal = Math.Clamp(quantBase + quantBonus, quantMin, qMax);
				// Per-item jitter: +/- 5% of full stack (percentage points), stay within [min, max]
				float jitter = (Math.RandomFloat01() * 2.0 - 1.0) * (qMax * 0.05);
				quantFinal = Math.Clamp(quantFinal + jitter, quantMin, qMax);
				item.SetQuantity(quantFinal);
			}
			else if (item.IsPeltBase())
			{
				float peltQuality = Math.Clamp(plmasterModifier, 0.05, 1.0);
				item.SetHealth01("", "", peltQuality);
				if (item.HasQuantity())
					item.SetQuantityNormalized(peltQuality);
			}
			else if (item.IsInherited(Bone))
			{
				float boneQuality = Math.Clamp(Math.Max(bonesInitHP, Math.Max(meathuntModifier, plmasterModifier)), 0.05, 1.0);
				item.SetHealth01("", "", boneQuality);
			}
		}
	}
}
