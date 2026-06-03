modded class FireplaceBase
{
	override void CreateAreaDamage()
	{
		//destroy area damage if some already exists
		DestroyAreaDamage();
		
		//create new area damage
		m_AreaDamage = new AreaDamageLoopedDeferred(this);
		m_AreaDamage.SetDamageComponentType(AreaDamageComponentTypes.HITZONE);
		m_AreaDamage.SetExtents("-0.30 0 -0.30", "0.30 0.75 0.30");
		m_AreaDamage.SetLoopInterval(0.5);
		m_AreaDamage.SetDeferDuration(0.5);
		m_AreaDamage.SetHitZones({ "Torso","LeftHand","LeftLeg","LeftFoot","RightHand","RightLeg","RightFoot" });
		m_AreaDamage.SetAmmoName("FireDamageFix");
		m_AreaDamage.Spawn();
	}
	
	override void StopFire(FireplaceFireState fire_state = FireplaceFireState.END_FIRE)
	{
		super.StopFire(fire_state);
		
		// Immediately destroy area damage instead of waiting for the cooling phase to finish
		DestroyAreaDamage();
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		DestroyAreaDamage();
	}
}
