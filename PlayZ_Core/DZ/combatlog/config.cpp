class CfgPatches
{
	class PlayZ_Core_AntiCombatLog
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Gear_Consumables"
		};
	};
};

class CfgVehicles
{
	class Roadflare;
	class PlayZ_CombatLogFlare: Roadflare
	{
		scope = 2;
		varQuantityDestroyOnMin = 1;
		class EnergyManager
		{
			energyAtSpawn = 200;
			energyUsagePerSecond = 1;
			updateInterval = 10;
			convertEnergyToQuantity = 1;
		};
		class NoiseRoadFlare
		{
			strength = 0;
			type = "";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 9999;
				};
			};
		};
	};
	class Inventory_Base;
	class PlayZ_CombatLogTrigger: Inventory_Base
	{
		scope = 1;
		model = "\dz\gear\consumables\Stone.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,1,1,0,CA)"};
	};
	class PlayZ_CombatLogExplosiveTrigger: PlayZ_CombatLogTrigger
	{
		scope = 1;
	};
};
