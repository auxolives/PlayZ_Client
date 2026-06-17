// Source Found: TerjeMedicine/Scripts/4_World/Classes/TerjeModifiers/TerjePlayerModifierMind.c:96
// Source Found: TerjeCore/Scripts/4_World/Classes/TerjePlayerModifierBase.c:34-36

modded class TerjePlayerModifierMind
{
	override void OnServerFixedTick(PlayerBase player, float deltaTime)
	{
		super.OnServerFixedTick(player, deltaTime);

		if (!GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_MIND_ENABLED))
		{
			return;
		}

		if (!player || !player.GetAllowDamage() || !player.GetTerjeStats())
		{
			return;
		}

		float health = GetPlayerHealth(player);
		if (health >= TerjeMedicineConstants.PLAYZ_LOW_HEALTH_MIND_THRESHOLD)
		{
			return;
		}

		float healthFactor = 1.0 - (health / TerjeMedicineConstants.PLAYZ_LOW_HEALTH_MIND_THRESHOLD);
		healthFactor = Math.Clamp(healthFactor, 0, 1);

		float perkIrmindDecMod = 1.0;
		if (player.GetTerjeSkills())
		{
			float perkIrnmindMod;
			if (player.GetTerjeSkills().GetPerkValue("immunity", "irnmind", perkIrnmindMod))
			{
				perkIrmindDecMod -= Math.Clamp(perkIrnmindMod, 0, 1);
			}
		}

		float drainPerSec = TerjeMedicineConstants.PLAYZ_LOW_HEALTH_MIND_DRAIN_MAX_PER_SEC * healthFactor * perkIrmindDecMod;
		float mindValue = player.GetTerjeStats().GetMindValue();
		mindValue -= drainPerSec * deltaTime;
		player.GetTerjeStats().SetMindValue(mindValue);
	}
}
