class CfgPatches
{
	class PlayZNotes
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Consumables",
			"DZ_Gear_Tools",
			"PlayZTerjeCore"
		};
	};
};

class CfgMods
{
	class PlayZNotes
	{
		dir = "PlayZNotes";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Notes";
		credits = "Based on ZenNotes by Zenarchist";
		author = "Olivier";
		type = "mod";
		dependencies[] = {
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZNotes/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZNotes/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZNotes/scripts/5_Mission"
				};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Paper: Inventory_Base
	{
		canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 5;
		varStackMax = 5;
		varQuantityDestroyOnMin = 1;
	};

	class PunchedCard: Paper
	{
		canBeSplit = 0;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 1;
		varStackMax = 1;
		varQuantityDestroyOnMin = 1;
	};

	class PlayZNote: Paper
	{
		scope = 2;
		displayName = "$STR_PLAYZ_NOTES_ITEM_NAME";
		descriptionShort = "$STR_PLAYZ_NOTES_ITEM_DESC";
		canBeSplit = 0;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 1;
		varStackMax = 1;
	};

	class Pen_ColorBase: Inventory_Base
	{
		quantityBar = 1;
		varQuantityInit = 100;
		varQuantityMin = 0;
		varQuantityMax = 100;
		stackedUnit = "percentage";
	};

	class Pen_Black: Pen_ColorBase
	{
		penColor[] = {10, 10, 10};
	};

	class Pen_Red: Pen_ColorBase
	{
		penColor[] = {200, 20, 20};
	};

	class Pen_Green: Pen_ColorBase
	{
		penColor[] = {24, 150, 24};
	};

	class Pen_Blue: Pen_ColorBase
	{
		penColor[] = {0, 65, 200};
	};
};
