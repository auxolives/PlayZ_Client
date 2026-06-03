class CfgPatches
{
	class DZ_Gear_Crafting_PlayZ_Core
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",			"DZ_Gear_Crafting"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
    class Torch: Inventory_Base
	{
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.6;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.6;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.2;
			};
			class Default_SwitchedOn
			{
				ammo = "MeleeLightBlunt";
				range = 1.6;
			};
			class Heavy_SwitchedOn
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.6;
			};
			class Sprint_SwitchedOn
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.2;
			};
		};
    };
	class LongTorch: Torch {};
};