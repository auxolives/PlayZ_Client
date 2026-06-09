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
			"DayZExpansion_Market_Scripts"
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
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZExpansion/scripts/4_World"
				};
			};
		};
	};
};
