class CfgPatches
{
	class PlayZInfected
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"InediaInfectedAI"
		};
	};
};

class CfgMods
{
	class PlayZInfected
	{
		dir = "PlayZInfected";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Infected";
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
					"PlayZ_Client/PlayZInfected/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZInfected/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZInfected/scripts/5_Mission"
				};
			};
		};
	};
};
