class CfgPatches
{
	class PlayZTerjeCore
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"TerjeCore",
            "PlayZMovement"
		};
	};
};
class CfgMods
{
	class PlayZTerjeCore
	{
		dir = "PlayZTerjeCore";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Terje Core";
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
					"PlayZ_Client/PlayZTerjeCore/scripts/3_game",
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeCore/scripts/4_world",
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeCore/scripts/5_mission"
				};
			};
		};
	};
};
