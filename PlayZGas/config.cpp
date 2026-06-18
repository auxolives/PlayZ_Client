class CfgPatches
{
	class PlayZGas
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
	class PlayZGas
	{
		dir = "PlayZGas";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Gas";
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
					"PlayZ_Client/PlayZGas/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZGas/scripts/4_World"
				};
			};
		};
	};
};
