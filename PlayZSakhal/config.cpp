class CfgPatches
{
	class PlayZSakhal
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"PlayZCore"
		};
	};
};
class CfgMods
{
	class PlayZSakhal
	{
		dir = "PlayZSakhal";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Sakhal";
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
					"PlayZ_Client/PlayZSakhal/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZSakhal/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZSakhal/scripts/5_Mission"
				};
			};
		};
	};
};
