class CfgPatches
{
	class PlayZExpansion
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Camping",
			"DayZExpansion_Vehicles_Objects_Gear",
			"TerjeCore",
			"TerjeStartScreen",
			"PlayZUI",
			"DayZExpansion_Core_Scripts",
			"DayZExpansion_Scripts",
			"DayZExpansion_Market_Scripts",
			"DayZExpansion_P2PMarket_Scripts",
			"DayZExpansion_Chat_Scripts",
			"DayZExpansion_NameTags_Scripts",
			"DayZExpansion_AI_Scripts"
		};
	};
};

class CfgMods
{
	class PlayZExpansion
	{
		dir = "PlayZExpansion";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Expansion";
		credits = "";
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
					"PlayZ_Client/PlayZExpansion/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZExpansion/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZExpansion/scripts/5_Mission"
				};
			};
		};
	};
};
