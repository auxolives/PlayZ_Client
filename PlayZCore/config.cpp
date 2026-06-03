class CfgPatches
{
	class PlayZCore
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
	class PlayZCore
	{
		dir = "PlayZCore";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Core";
		credits = "";
		author = "Olivier";
		type = "mod";
		inputs = "PlayZ_Client/PlayZCore/inputs.xml";
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
					"PlayZ_Client/PlayZCore/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZCore/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZCore/scripts/5_Mission"
				};
			};
		};
	};
};
