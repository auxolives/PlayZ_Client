class CfgPatches
{
	class PlayZTerjeStartScreen
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"PlayZCore",
			"TerjeCore",
			"TerjeStartScreen",
			"PlayZTerjeCore"
		};
	};
};

class CfgMods
{
	class PlayZTerjeStartScreen
	{
		dir = "PlayZTerjeStartScreen";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Terje Start Screen";
		credits = "";
		author = "Olivier";
		type = "mod";
		dependencies[] = {
			"Game",
			"World",
			"Mission",
			"gui"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeStartScreen/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeStartScreen/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeStartScreen/scripts/5_Mission"
				};
			};
		};
	};
};
