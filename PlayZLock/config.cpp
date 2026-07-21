class CfgPatches
{
	class PlayZLock
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"JM_CF_Scripts"
		};
	};
};

class CfgMods
{
	class PlayZLock
	{
		dir = "PlayZLock";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Lock";
		credits = "Based on ZenComboLocks by Zenarchist";
		author = "Olivier";
		type = "mod";
		storageVersion = 1;
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
					"PlayZ_Client/PlayZLock/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZLock/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZLock/scripts/5_Mission"
				};
			};
		};
	};
};
