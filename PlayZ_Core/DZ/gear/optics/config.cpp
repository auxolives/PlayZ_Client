class CfgPatches
{
	class DZ_Gear_Optics_PlayZ_Core
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Gear_Optics"
		};
	};
};

class CfgVehicles
{
	class ItemOptics;
	class Binoculars: ItemOptics
	{
		inventorySlot[] += {
			"Belt_Left"
		};
	};
};
