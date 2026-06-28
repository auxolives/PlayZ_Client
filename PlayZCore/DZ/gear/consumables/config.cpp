class CfgPatches
{
	class DZ_Gear_Consumables_PlayZCore
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Gear_Consumables",
			"DZ_Gear_Crafting"
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
	class GasMask_Filter: Inventory_Base
	{
		inventorySlot[] += {
			"NBC_Filter1",
			"NBC_Filter2",
			"NBC_Filter3",
			"NBC_Filter4"
		};
	};
	class GasMask_Filter_Improvised: Inventory_Base
	{
		inventorySlot[] += {
			"NBC_Filter1",
			"NBC_Filter2",
			"NBC_Filter3",
			"NBC_Filter4"
		};
	};
};
