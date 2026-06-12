class CfgPatches
{
	class PlayZUI
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"TerjeCore",
			"TerjeStartScreen",
			"DayZExpansion_Core_Scripts",
			"DayZExpansion_Scripts"
		};
	};
};

class CfgMods
{
	class PlayZUI
	{
		dir = "PlayZUI";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ UI";
		credits = "";
		author = "Olivier";
		type = "mod";
		dependencies[] = {
			"Game",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZUI/scripts/3_Game"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZUI/scripts/5_Mission"
				};
			};
		};
	};
};
