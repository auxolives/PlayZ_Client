class CfgPatches
{
	class PlayZNotification
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"PlayZCore",
			"DayZExpansion_Core_Scripts",
			"TerjeCore",
			"TerjeSkills",
			"TerjeMedicine",
			"TerjeRadiation"
		};
	};
};

class CfgMods
{
	class PlayZNotification
	{
		dir = "PlayZNotification";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Notification";
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
			class gameScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZNotification/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZNotification/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZNotification/scripts/5_Mission"
				};
			};
		};
	};
};
