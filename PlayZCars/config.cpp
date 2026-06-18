class CfgPatches
{
	class PlayZCars
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Vehicles_Wheeled",
			"DZ_Vehicles_Wheeled_PlayZCars",
			"DZ_Surfaces_PlayZCars",
			"PlayZCore"
		};
	};
};

class CfgMods
{
	class PlayZCars
	{
		dir = "PlayZCars";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Cars";
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
					"PlayZ_Client/PlayZCars/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZCars/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZCars/scripts/5_Mission"
				};
			};
		};
	};
};
