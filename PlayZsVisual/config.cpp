class CfgPatches
{
	class PlayZsVisual
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"sFramework",
			"sVisual"
		};
	};
};

class CfgMods
{
	class PlayZsVisual
	{
		dir = "PlayZsVisual";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ sVisual Compat";
		credits = "";
		author = "Olivier";
		type = "mod";
		dependencies[] = {
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZsVisual/scripts/4_World"
				};
			};
		};
	};
};
