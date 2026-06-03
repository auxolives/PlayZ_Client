//! Source Found: scripts/4_World/Entities/DayZPlayerImplement.c:1469 (EvaluateDamageHitAnimation)
//! Source Found: scripts/4_World/Entities/DayZPlayerSyncJunctures.c:99 (SendDamageHitEx)
//!
//! InediaInfectedAI `EEHitBy` can call `InediaInfectedAI_Kill()` before `super.EEHitBy`, which sets `m_InediaInfectedAI_Killed`
//! and skips the inner `super` call — so `DayZPlayerImplement.EEHitBy` never runs `DayZPlayerSyncJunctures.SendDamageHitEx`
//! for that hit (death is applied ~50ms later via `InediaInfectedAI_ProcessKill`). Observers then see shots / effects
//! without the victim reacting until much later.
//!
//! This mod must load AFTER `InediaInfectedAI` in the merged `PlayerBase` chain (typically: list PlayZInedia after Inedia
//! on `-mod=` or depend on Inedia only so the patch sorts after it). Then `super.EEHitBy` returns here after Inedia runs;
//! we replay the damage-hit juncture only in the delayed-kill window: killed flag set, player still alive.
modded class PlayerBase
{
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);

		if (!GetGame().IsDedicatedServer())
			return;
		if (!damageResult || !source)
			return;
		if (!m_InediaInfectedAI_Killed)
			return;
		if (!IsAlive())
			return;

		int animType;
		float animHitDir;
		bool animHitFullbody;
		if (!EvaluateDamageHitAnimation(damageResult, damageType, source, dmgZone, ammo, modelPos, animType, animHitDir, animHitFullbody))
			return;

		DayZPlayer dzPlayer;
		if (!Class.CastTo(dzPlayer, this))
			return;

		DayZPlayerSyncJunctures.SendDamageHitEx(dzPlayer, animType, animHitDir, animHitFullbody, damageResult, damageType, source, dmgZone, ammo, modelPos);
	}
}
