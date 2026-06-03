class CfgPatches
{
	class PlayZInedia
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"InediaInfectedAI"
		};
	};
};

class CfgMods
{
	class PlayZInedia
	{
		dir = "PlayZInedia";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Inedia";
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
					"PlayZ_Client/PlayZInedia/scripts/4_World"
				};
			};
		};
	};
};

class PathGraphFilters
{
	class ZombieAlerted
	{
		class Flags
		{
			include[] = {"walk","door","inside","jump","climb"};
			exclude[] = {"disabled","crawl","crouch"};
		};
	};
};
