class CfgPatches
{
	class PlayZLocktRPatch
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"PlayZLock",
			"tR_Custom",
			"tR_Stockade_Custom",
			"tR_Modules_Custom"
		};
	};
};

class CfgMods
{
	class PlayZLocktRPatch
	{
		dir = "PlayZLocktRPatch";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Lock tR Patch";
		credits = "PlayZLock + Tierro tR";
		author = "Olivier";
		type = "mod";
		dependencies[] = {
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZLocktRPatch/scripts/4_World"
				};
			};
		};
	};
};
