class CfgPatches
{
	class PlayZmCommandWeaponsFix
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"DayZExpansion_Core_Scripts",
			"DayZExpansion_Vehicles_Scripts",
			"sFramework",
			"sGunplay",
			"sVisual",
			"TerjeCore"
		};
	};
};

class CfgMods
{
	class PlayZmCommandWeaponsFix
	{
		dir = "PlayZmCommandWeaponsFix";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ mCommandWeapons Fix";
		credits = "";
		author = "Olivier";
		type = "mod";
		dependencies[] = {
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZmCommandWeaponsFix/scripts/4_World"
				};
			};
		};
	};
};
