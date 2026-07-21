//! tR_ShieldSmall: wood build also creates sashes; sash hits deal 0 and block repair.
//! Apply equivalent wood-zone damage on sash hits (EEHitBy — after engine resolves the sash hit).
//! Source Found: scripts/4_World/Entities/ItemBase.c:1522 (EEHitBy)
//! Source Found: scripts/3_Game/Entities/Object.c:1023 (AddHealth)
//! Source Found: scripts/3_Game/DamageSystem.c:10 (DamageType)
modded class BaseBuildingBase
{
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);

		if (!GetGame().IsServer())
			return;

		if (GetType() != "tR_ShieldSmall")
			return;

		if (dmgZone != "tR_Sashes")
			return;

		PlayZ_RedirectShieldSashDamage(damageType, ammo, speedCoef);
	}

	void PlayZ_RedirectShieldSashDamage(int damageType, string ammo, float speedCoef)
	{
		if (ammo == string.Empty)
			return;

		float baseDmg = GetGame().ConfigGetFloat("CfgAmmo " + ammo + " DamageApplied Health damage");
		if (baseDmg <= 0)
			return;

		string armorType = "Projectile";
		if (damageType == DamageType.CLOSE_COMBAT)
			armorType = "Melee";
		else if (damageType == DamageType.EXPLOSION)
			armorType = "FragGrenade";

		float armor = GetGame().ConfigGetFloat("CfgVehicles tR_ShieldSmall DamageSystem DamageZones tR_Wood ArmorType " + armorType + " Health damage");
		if (armor <= 0)
			armor = 1.0;

		float applied = baseDmg * armor * speedCoef;
		if (applied <= 0)
			return;

		AddHealth("tR_Wood", "Health", -applied);
	}
}
