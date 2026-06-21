class CfgPatches
{
	class DZ_Gear_Food_Terje_PlayZ
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Gear_Food"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Edible_Base;
	class MushroomBase;
	class WolfSteakMeat: Edible_Base
	{
		medRabiesInfectionChance = 0.1;
	};
	class PsilocybeMushroom: MushroomBase
	{
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD","Trap_Bait_2"};
		overdosedIncrement = 0.01;
	};
	class AmanitaMushroom: MushroomBase
	{
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD","Trap_Bait_2"};
		medFoodPoisonIncrement = 0.01;
		overdosedIncrement = 0.012;
	};
};