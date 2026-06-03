class CfgPatches
{
	class TerjeMedicine_Salves_PlayZ
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"TerjeMedicine",
			"TerjeMedicine_Salves"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class TerjeSalveBase;
	class TerjeSalveFinalgon: TerjeSalveBase
	{
		displayName = "#STR_PLAYZ_MED_SALVE_FINALGON";
		// ReviewName: Finalginum Salve
		medHematomaHeal = 1;
		medHematomaHealTimeSec = 300;
	};
	class TerjeSalveCapsicum: TerjeSalveBase
	{
		displayName = "#STR_PLAYZ_MED_SALVE_CAPSICUM";
		// ReviewName: Capsaicinum Salve
		medHematomaHeal = 1;
		medHematomaHealTimeSec = 400;
	};
	class TerjeSalveViprosal: TerjeSalveBase
	{
		displayName = "#STR_PLAYZ_MED_SALVE_VIPROSAL";
		// ReviewName: Viprosalinum Salve
		medHematomaHeal = 1;
		medHematomaHealTimeSec = 600;
	};
};
