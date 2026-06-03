class CfgPatches
{
	class DZ_Gear_Drinks_PlayZCore
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Gear_Drinks"
		};
	};
};

class CfgVehicles
{
	class Bottle_Base;
	class GlassBottle: Bottle_Base
	{
		varLiquidTypeInit = 2048; // LIQUID_VODKA
		varQuantityInit = 750;
		varQuantityMin = 0;
		varQuantityMax = 750;
	};
};
