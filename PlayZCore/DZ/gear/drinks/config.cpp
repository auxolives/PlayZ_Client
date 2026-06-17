class CfgPatches
{
	class DZ_Gear_Drinks_PlayZCore
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Gear_Drinks",
			"DZ_Gear_Cooking",
			"DZ_Vehicles_Parts",
			"DZ_Gear_Containers"
		};
	};
};

class CfgVehicles
{
	class Bottle_Base;
	class Container_Base;
	class GlassBottle: Bottle_Base
	{
		varLiquidTypeInit = 2048;
		varQuantityInit = 750;
		varQuantityMin = 0;
		varQuantityMax = 750;
		varTemperatureMin = -100;
		varTemperatureFreezeTime = 1120;
		varTemperatureThawTime = 1120;
	};
	class Canteen: Bottle_Base
	{
		varTemperatureMin = -100;
		varTemperatureFreezeTime = 1200;
		varTemperatureThawTime = 1200;
	};
	class WaterBottle: Bottle_Base
	{
		varTemperatureMin = -100;
		varTemperatureFreezeTime = 1200;
		varTemperatureThawTime = 1200;
	};
	class WaterPouch_ColorBase: Bottle_Base
	{
		varTemperatureMin = -100;
		varTemperatureFreezeTime = 1270;
		varTemperatureThawTime = 1270;
	};
	class FilteringBottle: Bottle_Base
	{
		varTemperatureMin = -100;
		varTemperatureFreezeTime = 1080;
		varTemperatureThawTime = 1080;
	};
	class Pot: Bottle_Base
	{
		varTemperatureMin = -100;
		varTemperatureFreezeTime = 1430;
		varTemperatureThawTime = 1430;
	};
	class Cauldron: Bottle_Base
	{
		varTemperatureMin = -100;
		varTemperatureFreezeTime = 1430;
		varTemperatureThawTime = 1430;
	};
	class CanisterGasoline: Bottle_Base
	{
		varTemperatureMin = -100;
		varTemperatureFreezeTime = 2540;
		varTemperatureThawTime = 2540;
	};
	class Barrel_ColorBase: Container_Base
	{
		varTemperatureMin = -100;
		varTemperatureFreezeTime = 4520;
		varTemperatureThawTime = 4520;
	};
};
