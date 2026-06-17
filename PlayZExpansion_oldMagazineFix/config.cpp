class CfgPatches
{
	class PlayZExpansion_oldMagazineFix
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"DayZExpansion_AI_Scripts"
		};
	};
};

class CfgMods
{
	class PlayZExpansion_oldMagazineFix
	{
		dir = "PlayZExpansion_oldMagazineFix";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Expansion old magazine fix";
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
					"PlayZ_Client/PlayZExpansion_oldMagazineFix/scripts/4_World"
				};
			};
		};
	};
};
