class CfgPatches
{
	class PlayZsGunplay
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"sFramework",
			"sGunplay",
			"sVisual"
		};
	};
};

class CfgMods
{
	class PlayZsGunplay
	{
		dir = "PlayZsGunplay";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ sGunplay Compat";
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
					"PlayZ_Client/PlayZsGunplay/scripts/4_World"
				};
			};
		};
	};
};
