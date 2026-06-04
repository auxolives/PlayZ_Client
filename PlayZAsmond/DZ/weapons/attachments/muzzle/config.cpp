class CfgPatches
{
	class PlayZAsmond_attachments_muzzle
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Weapons_Muzzles",
			"PlayZAsmond",
			"AsmondWeapons",
		};
	};
};

class cfgVehicles
{
	class AK_Suppressor;
	class M4_Suppressor;
	class PistolSuppressor;

	class Asmond_Suppressor_EAST_Winter;
	class AK_Suppressor_Winter: Asmond_Suppressor_EAST_Winter { scope=2; };

	class Asmond_Suppressor_EAST_Black;
	class AK_Suppressor_Black: Asmond_Suppressor_EAST_Black { scope=2; };

	class Asmond_Suppressor_NATO_Black;
	class M4_Suppressor_Black: Asmond_Suppressor_NATO_Black { scope=2; };

	class Asmond_Suppressor_NATO_Tan;
	class M4_Suppressor_Tan: Asmond_Suppressor_NATO_Tan { scope=2; };

	class Asmond_Suppressor_NATO_Green;
	class M4_Suppressor_Green: Asmond_Suppressor_NATO_Green { scope=2; };

	class Asmond_Suppressor_NATO_Winter;
	class M4_Suppressor_Winter: Asmond_Suppressor_NATO_Winter { scope=2; };

	class Asmond_Suppressor_Pistol_Black;
	class PistolSuppressor_Black: Asmond_Suppressor_Pistol_Black { scope=2; };

	class Asmond_Suppressor_Pistol_Tan;
	class PistolSuppressor_Tan: Asmond_Suppressor_Pistol_Tan { scope=2; };

};
