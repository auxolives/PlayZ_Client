class CfgPatches
{
	class PlayZLighting
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class PlayZLighting
	{
		dir = "PlayZLighting";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Lighting";
		credits = "";
		author = "Olivier";
		type = "mod";
		dependencies[] = {
			"Game"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZLighting/scripts/3_Game"
				};
			};
		};
	};
};
