class CfgPatches
{
	class TerjeMedicine_Ampouls_PlayZ
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"TerjeMedicine",
			"TerjeMedicine_Ampouls"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class TerjeAmpouleBase;
	class TerjeAmpouleAlcohol: TerjeAmpouleBase
	{
		displayName = "#STR_PLAYZ_MED_AMPOULE_ALCOHOL";
		// ReviewName: Alcohol Ampoule
		varQuantityInit = 10;
		varQuantityMin = 0;
		varQuantityMax = 10;
		overdosedIncrement = 4;
		medSkillExpAddToSelf = 0;
		medicalAmpoulsCategory = 0;
	};
	class TerjeAmpouleNeirox: TerjeAmpouleBase
	{
		displayName = "#STR_PLAYZ_MED_AMPOULE_NEIROX";
		// ReviewName: Concussion Relief Ampoule
		medConcussionHealTimeSec = 600;
		overdosedIncrement = 0.6;
	};
	class TerjeAmpouleHeptral: TerjeAmpouleBase
	{
		displayName = "#STR_PLAYZ_MED_AMPOULE_HEPTRAL";
		// ReviewName: Atropine Ampoule
		medAntipoisonLevel = 3;
		medAntipoisonTimeSec = 600;
		overdosedIncrement = 0.6;
	};
	class TerjeAmpoulePotassiumCyanide: TerjeAmpouleBase
	{
		displayName = "#STR_PLAYZ_MED_AMPOULE_POTASSIUM_CYANIDE";
		// ReviewName: Cyanide Ampoule
		overdosedIncrement = 3.5;
		medFoodPoisonIncrement = 3.2;
		terjeAddWater = -1500;
		terjeAddEnergy = -1500;
	};
	class TerjeAmpouleKonyin: TerjeAmpouleBase
	{
		displayName = "#STR_PLAYZ_MED_AMPOULE_KONYIN";
		// ReviewName: Deep Sedative Ampoule
		overdosedIncrement = 1.8;
		medSleepDamageValue = 100;
		medSleepDamageTime = 160;
	};
	class TerjeAmpouleBeladonna: TerjeAmpouleBase
	{
		displayName = "#STR_PLAYZ_MED_AMPOULE_BELADONNA";
		// ReviewName: Belladonna Extract Ampoule
		overdosedIncrement = 3.4;
		medPainSet = 5;
		medContussionLight = 1;
	};
	class TerjeAmpouleAdrenalin: TerjeAmpouleBase
	{
		displayName = "#STR_PLAYZ_MED_AMPOULE_ADRENALIN";
		// ReviewName: Adrenaline Ampoule
		medAdrenalinTimeSec = 220;
		overdosedIncrement = 0.15;
		medSkillExpAddToSelf = 10;
	};
	class TerjeAmpouleNovacaine: TerjeAmpouleBase
	{
		displayName = "#STR_PLAYZ_MED_AMPOULE_NOVACAINE";
		// ReviewName: Lidocaine Ampoule
		medPainkillerLevel = 2;
		medPainkillerTimeSec = 1200;
		overdosedIncrement = 0.4;
	};
	class TerjeAmpouleMorphine: TerjeAmpouleBase
	{
		displayName = "#STR_PLAYZ_MED_AMPOULE_MORPHINE";
		// ReviewName: Morphine Ampoule
		medPainkillerLevel = 3;
		medPainkillerTimeSec = 850;
		overdosedIncrement = 0.52;
	};
	class TerjeAmpouleRabivax: TerjeAmpouleBase
	{
		displayName = "#STR_PLAYZ_MED_AMPOULE_RABIVAX";
		// ReviewName: Rabies Vaccine Ampoule
		medRabiesVacineTime = 14400;
		overdosedIncrement = 0.7;
		medSkillExpAddToSelf = 100;
	};
};