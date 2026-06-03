modded class BleedingSourcesManagerServer
{
	override bool TerjeOverrideProcessHit_Melee(float damage, EntityAI source, int component, string zone, string ammo, vector modelPos, inout bool playerTakeDammage)
	{
		if (ammo == "FireDamageFix")
		{
			// Explicitly block TerjeMedicine wounds like hematoma (bruising) for this ammo type to prevent Immunity XP farming.
			return false;
		}
		
		return super.TerjeOverrideProcessHit_Melee(damage, source, component, zone, ammo, modelPos, playerTakeDammage);
	}
}
