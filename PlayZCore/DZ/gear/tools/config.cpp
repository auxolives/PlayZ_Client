class CfgPatches
{
	class DZ_Gear_Tools_PlayZCore
	{
		units[] = {"Flashlight_IR"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Melee","DZ_Gear_Tools"};
	};
};

class CfgVehicles
{
	class Flashlight;
	class Flashlight_IR: Flashlight
	{
		scope = 2;
		displayName = "$STR_PlayZ_Flashlight_IR0";
		descriptionShort = "$STR_PlayZ_Flashlight_IR1";
	};

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
