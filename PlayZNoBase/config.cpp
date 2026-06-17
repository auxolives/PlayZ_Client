class CfgPatches
{
	class PlayZNoBase
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
	class PlayZNoBase
	{
		dir = "PlayZNoBase";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ No Base";
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
					"PlayZ_Client/PlayZNoBase/scripts/4_World"
				};
			};
		};
	};
};
