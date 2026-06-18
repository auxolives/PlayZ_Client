class CfgPatches
{
	class PlayZWelcomeMessage
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
	class PlayZWelcomeMessage
	{
		dir = "PlayZWelcomeMessage";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Welcome Message";
		credits = "Based on Ironhorde Welcome Message by DeafFeliciaPlaysDayZ";
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
					"PlayZ_Client/PlayZWelcomeMessage/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZWelcomeMessage/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZWelcomeMessage/scripts/5_Mission"
				};
			};
		};
	};
};
