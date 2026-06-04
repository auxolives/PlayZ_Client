class CfgPatches
{
	class PlayZTerjeRadiation
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"PlayZCore",
			"TerjeCore",
			"TerjeRadiation",
			"TerjeRadiation_Protection",
			"PlayZTerjeCore"
		};
	};
};
class CfgMods
{
	class PlayZTerjeRadiation
	{
		dir = "PlayZTerjeRadiation";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Terje Radiation";
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
					"PlayZ_Client/PlayZTerjeRadiation/scripts/4_world"
				};
			};
		};
	};
};
