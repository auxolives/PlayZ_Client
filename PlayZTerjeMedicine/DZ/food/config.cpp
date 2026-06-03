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
		//Handle via PsilocybeMushroom.c
		overdosedIncrement = 0.01;
	};
	class AmanitaMushroom: MushroomBase
	{
		//Handle via PsilocybeMushroom.c
		overdosedIncrement = 0.02;
	};
};