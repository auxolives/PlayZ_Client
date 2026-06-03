class CfgPatches
{
	class TerjeMedicine_Drinks_PlayZ
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Gear_Drinks",
			"TerjeMedicine"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Edible_Base;
	class SodaCan_ColorBase;
	class SodaCan_Pipsi: SodaCan_ColorBase
	{
		medSleepingIncrementValue = 4;
		medSleepingIncrementTimeSec = 1.0;
	};
	class SodaCan_Cola: SodaCan_ColorBase
	{
		medSleepingIncrementValue = 5;
		medSleepingIncrementTimeSec = 1.0;
	};
	class SodaCan_Spite: SodaCan_ColorBase
	{
		medSleepingIncrementValue = 3;
		medSleepingIncrementTimeSec = 1.0;
	};
	class SodaCan_Fronta: SodaCan_ColorBase
	{
		medSleepingIncrementValue = 4;
		medSleepingIncrementTimeSec = 1.0;
	};
	class SodaCan_Kvass: SodaCan_ColorBase
	{
		medSleepingIncrementValue = -7;
		medSleepingIncrementTimeSec = 1.0;
		overdosedIncrement = 0.0007;
		medPainkillerLevel = 1;
		medPainkillerTimeSec = 1;
	};
};







