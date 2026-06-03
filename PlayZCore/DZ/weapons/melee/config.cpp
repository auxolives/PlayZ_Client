class CfgPatches
{
	class DZ_Weapons_Melee_PlayZCore
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Weapons_Melee"
		};
	};
};
class CfgAmmo
{
	class MeleeDamage;
	class FireDamage: MeleeDamage
	{
		class DamageApplied;
	};
	class FireDamageFix: FireDamage
	{
		class DamageApplied: DamageApplied
		{
			class Health
			{
				damage = 1.5;
			};
			class Shock
			{
				damage = 1.5;
			};
		};
	};
};
