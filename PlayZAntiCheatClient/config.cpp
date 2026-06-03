class CfgPatches
{
	class PlayZAntiCheatClient
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods
{
	class PlayZAntiCheatClient
	{
		dir = "PlayZAntiCheatClient";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ AntiCheat Client";
		credits = "";
		author = "Olivier";
		type = "mod";
		dependencies[] = {
			"Game",
			"World"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZAntiCheatClient/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZAntiCheatClient/scripts/4_World"
				};
			};
		};
	};
};
