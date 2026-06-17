class CfgPatches
{
	class PlayZCOTWeather
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"JM_COT_Scripts",
			"PlayZWeather",
		};
	};
};
class CfgMods
{
	class PlayZCOTWeather
	{
		dir = "PlayZCOTWeather";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ COT Weather";
		credits = "";
		author = "Olivier";
		type = "mod";
		dependencies[] = {
			"Mission",
		};
		class defs
		{
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZCOTWeather/scripts/5_Mission"
				};
			};
		};
	};
};
