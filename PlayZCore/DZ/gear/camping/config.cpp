class CfgPatches
{
	class DZ_Gear_Camping_PlayZCore
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Gear_Camping"
		};
	};
};

class CfgVehicles
{
	class Container_Base;
	class TentBase: Container_Base
	{
		inventorySlot[] += {"VestBackpack"};
	};

	class MediumTent: TentBase
	{
		weight = 24000;
		descriptionShort = "#STR_PlayZ_MediumTent_Desc";
	};
	class LargeTent: TentBase
	{
		weight = 35000;
		descriptionShort = "#STR_PlayZ_LargeTent_Desc";
	};
	class CarTent: TentBase
	{
		weight = 38000;
		descriptionShort = "#STR_PlayZ_CarTent_Desc";
	};
	class PartyTent: TentBase
	{
		weight = 21000;
		descriptionShort = "#STR_PlayZ_PartyTent_Desc";
	};
};
