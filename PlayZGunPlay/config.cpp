class CfgPatches
{
	class PlayZGunPlay
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"PlayZCore",
			"sFramework",
			"sGunplay",
			"sVisual"
		};
	};
};
class CfgMods
{
	class PlayZGunPlay
	{
		dir = "PlayZGunPlay";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ GunPlay";
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
					"PlayZ_Client/PlayZGunPlay/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZGunPlay/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZGunPlay/scripts/5_Mission"
				};
			};
		};
	};
};
