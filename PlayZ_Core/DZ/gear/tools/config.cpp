class CfgPatches
{
	class DZ_Gear_Tools_PlayZ_Core
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Melee","DZ_Gear_Tools"};
	};
};

class CfgVehicles
{
	class FishingRod_Base_New;
	class FishingRod: FishingRod_Base_New
	{
		inventorySlot[] += {"Shoulder","Melee"};
	};
	class ImprovisedFishingRod: FishingRod_Base_New
	{
		inventorySlot[] += {"Shoulder","Melee"};
	};
};
