//! Per-weapon raycast distances for anti-combat-log shot detection.

modded class Archery_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		return 150;
	}
}

modded class Izh43Shotgun_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		return 150;
	}
}

modded class Izh18Shotgun_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		return 150;
	}
}

modded class Mp133Shotgun_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		return 150;
	}
}

modded class R12_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		return 150;
	}
}

modded class Saiga_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		return 150;
	}
}

modded class Pistol_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		return 500;
	}
}

modded class Derringer_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		return 500;
	}
}

modded class Magnum_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		return 500;
	}
}

modded class LongHorn_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		if (FindAttachmentBySlotName("weaponOpticsCrossbow"))
		{
			return 800;
		}
		return 500;
	}
}

modded class Deagle_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		if (FindAttachmentBySlotName("weaponOpticsCrossbow"))
		{
			return 800;
		}
		return 500;
	}
}

modded class M79_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		return 500;
	}
}

modded class Rifle_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		if (FindAttachmentBySlotName("weaponOpticsHunting"))
		{
			return 1000;
		}
		return 500;
	}
}

modded class BoltRifle_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		if (FindAttachmentBySlotName("weaponOpticsHunting"))
		{
			return 1000;
		}
		return 500;
	}
}

modded class BoltActionRifle_Base
{
	override float GetAntiCombatLogWeaponDistance()
	{
		if (FindAttachmentBySlotName("weaponOpticsHunting"))
		{
			return 1000;
		}
		return 500;
	}
}
