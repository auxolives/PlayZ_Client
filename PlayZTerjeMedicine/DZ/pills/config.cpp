class CfgPatches
{
	class TerjeMedicine_Pills_PlayZ
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"TerjeMedicine",
			"TerjeMedicine_Pills"
		};
	};
};
class CfgVehicles
{
	class Edible_Base;
	class TerjePillsBase;
	class TerjePills_Capsule;
	class TerjePills_Oval;
	class TerjePills_Circle;
	class TerjePillsPotassiumCyanide: TerjePills_Circle
	{
		displayName = "#STR_PLAYZ_MED_PILLS_POTASSIUM_CYANIDE";
		// ReviewName: Cyanide Pills
		medFoodPoisonIncrement = 5;
		overdosedIncrement = 1.5;
	};
	class TerjePillsArsenic: TerjePills_Circle
	{
		displayName = "#STR_PLAYZ_MED_PILLS_ARSENIC";
		// ReviewName: Arsenic Pills
		medFoodPoisonIncrement = 3.5;
		overdosedIncrement = 2.5;
	};
	class TerjePillsIrovit: TerjePills_Circle
	{
		displayName = "#STR_PLAYZ_MED_PILLS_IROVIT";
		// ReviewName: Ferrous Blood Pills
		medBloodRegenValue = 1;
		medBloodRegenTimeSec = 120;
		overdosedIncrement = 0.3;
	};
	class TerjePillsAdepress: TerjePills_Capsule
	{
		displayName = "#STR_PLAYZ_MED_PILLS_ADEPRESS";
		// ReviewName: Alprazolam Pills
		medAntidepresantLevel = 1;
		medAntidepresantTimer = 150;
		overdosedIncrement = 0.2;
	};
	class TerjePillsNoopept: TerjePills_Circle
	{
		displayName = "#STR_PLAYZ_MED_PILLS_NOOPEPT";
		// ReviewName: Concussion Focus Pills
		medPainkillerLevel = 1;
		medPainkillerTimeSec = 380;
		medConcussionHealTimeSec = 380;
		overdosedIncrement = 0.35;
	};
	class TetracyclineAntibiotics: Edible_Base
	{
		medAntibioticLevel=3;
		medAntisepsisTimeSec = 300;
	};
	class TerjePillsTetracyclineAntibiotics: TerjePills_Capsule
	{
		// ReviewName: Broad-Spectrum Antibiotic Pills
		medAntibioticLevel=3;
		medAntisepsisTimeSec = 300;
	};
	class TerjePillsIbuprofen: TerjePills_Capsule
	{
		// ReviewName: Ibuprofen Plus Pills
		medPainkillerLevel = 1;
		medPainkillerTimeSec = 600;
		medAntibioticLevel = 2;
		medAntibioticsTimeSec = 600;
	};
	class TerjePillsAmoxiclav: TerjePills_Oval
	{
		// ReviewName: Antiseptic Booster Pills
		medAntisepsisTimeSec = 180;
	};
};