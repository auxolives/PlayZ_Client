class CfgPatches
{
	class DZ_Gear_Consumables_PlayZCore
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Gear_Consumables"
		};
	};
};

class CfgVehicles
{
	class Box_Base;
	class NailBox: Box_Base
	{
		weight = 700;
	};

	class Inventory_Base;
	class Nail: Inventory_Base
	{
		weight = 10;
	};
};
