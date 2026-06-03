modded class DayZGame
{
	override void FirearmEffects(Object source, Object directHit, int componentIndex, string surface, vector pos, vector surfNormal, vector exitPos, vector inSpeed, vector outSpeed, bool isWater, bool deflected, string ammoType)
	{
		super.FirearmEffects(source, directHit, componentIndex, surface, pos, surfNormal, exitPos, inSpeed, outSpeed, isWater, deflected, ammoType);

		if (!g_Game || !g_Game.IsServer())
		{
			return;
		}

		PlayZAntiCombatLogConfig cfg = PlayZAntiCombatLogConfig.Get();
		vector spawnPos = pos + "0 100 0";

		if ((ammoType == "Bullet_40mm_Explosive" || ammoType == "AType_Bullet_40mm_ChemGas") && cfg.TriggerOnExplosiveRadius > 0)
		{
			GetGame().CreateObjectEx("PlayZ_CombatLogExplosiveTrigger", spawnPos, ECE_KEEPHEIGHT);
			return;
		}

		if (cfg.TriggerOnBulletImpactRadius > 0)
		{
			GetGame().CreateObjectEx("PlayZ_CombatLogTrigger", spawnPos, ECE_KEEPHEIGHT);
		}
	}
}
