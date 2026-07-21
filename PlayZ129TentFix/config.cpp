class CfgPatches
{
	class PlayZ129TentFix
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
	class PlayZ129TentFix
	{
		dir = "PlayZ129TentFix";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ 1.29 Tent Fix";
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
					"PlayZ_Client/PlayZ129TentFix/scripts/4_World"
				};
			};
		};
	};
};
