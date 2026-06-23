class CfgPatches
{
	class DayZExpansion_Vehicles_Objects_Gear_PlayZExpansion
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DayZExpansion_Vehicles_Objects_Gear"
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class ExpansionHelicopterBattery: Inventory_Base
	{
		inventorySlot[] = {"ExpansionHelicopterBattery", "LargeBattery"};
		class EnergyManager
		{
			energyStorageMax = 900;
			energyAtSpawn = 900;
		};
	};
};
