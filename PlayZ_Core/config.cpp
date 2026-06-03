class CfgPatches
{
	class PlayZ_Core
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
	class PlayZ_Core
	{
		dir = "PlayZ_Core";
		hideName = 0;
		hidePicture = 1;
		name = "PlayZ Core";
		credits = "";
		author = "PlayZ";
		type = "mod";
		inputs = "PlayZ_Client/PlayZ_Core/inputs.xml";
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
					"PlayZ_Client/PlayZ_Core/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZ_Core/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZ_Core/scripts/5_Mission"
				};
			};
		};
	};
};
