modded class PrepareFish
{
	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		// Run base mod logic (Terje's perk-based logic — perks are disabled in our config)
		super.Do(ingredients, player, results, specialty_weight);

		// PlayZ Override: modifier-based fillet yield scaling
		// masterfmod_plz: 0.035/level. Level 0 = 0.0, Level 30 = 1.05 (clamped to 1.0)
		// Yield range: initQuantity (floor) → 1.0 (max at high skill)
		if (!GetGame().IsDedicatedServer() || !player || !player.IsAlive() || !player.GetTerjeSkills())
			return;

		float masterfMod = 0;
		player.GetTerjeSkills().GetSkillModifierValue("fish", "masterfmod_plz", masterfMod);

		// Fetch the server-configured floor. Falls back to 15% if setting missing.
		float initQuantity = 0.15;
		GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_FISHING_OVERRIDE_FILLET_MIN_QUANTITY, initQuantity);

		// Scale: starts at initQuantity, reaches 1.0 when masterfMod >= 1.0 (level 29+)
		float totalQuantity = Math.Clamp(initQuantity + masterfMod, initQuantity, 1.0);

		int count = results.Count();
		for (int i = 0; i < count; i++)
		{
			ItemBase item_result = ItemBase.Cast(results.Get(i));
			if (item_result && item_result.HasQuantity())
			{
				// Per-item jitter: +/- 5% of full stack (normalized), same idea as meat/fat
				float jitter = (Math.RandomFloat01() * 2.0 - 1.0) * 0.05;
				float qtyNorm = Math.Clamp(totalQuantity + jitter, initQuantity, 1.0);
				item_result.SetQuantityNormalized(Math.Clamp(qtyNorm, 0.01, 1.0));
			}
		}
	}
}
