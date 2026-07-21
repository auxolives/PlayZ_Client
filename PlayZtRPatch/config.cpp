class CfgPatches
{
	class PlayZtRPatch
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"tR_Dependence",
			"tR_Stockade",
			"tR_Modules",
			"tR_Custom",
			"tR_Stockade_Custom",
			"tR_Modules_Custom",
			"DayZExpansion_BaseBuilding_Scripts",
			"PlayZNotes"
		};
	};
};

class CfgMods
{
	class PlayZtRPatch
	{
		dir = "PlayZtRPatch";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ tR Placement Patch";
		credits = "PlayZ + Tierro tR";
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
					"PlayZ_Client/PlayZtRPatch/scripts/4_World"
				};
			};
		};
	};
};
