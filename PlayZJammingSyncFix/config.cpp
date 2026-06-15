class CfgPatches
{
	class PlayZJammingSyncFix
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
	class PlayZJammingSyncFix
	{
		dir = "PlayZJammingSyncFix";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Jamming Sync Fix";
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
					"PlayZ_Client/PlayZJammingSyncFix/scripts/4_World"
				};
			};
		};
	};
};
