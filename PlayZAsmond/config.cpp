class CfgPatches
{
	class PlayZAsmond
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"AsmondClothing",
			"AsmondWeapons"
		};
	};
};

class CfgMods
{
	class PlayZAsmond
	{
		dir = "PlayZAsmond";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Asmond";
		credits = "";
		author = "Olivier";
		type = "mod";
		dependencies[] = {
			"Game",
			"World",
			"Mission"
		};
	};
};
