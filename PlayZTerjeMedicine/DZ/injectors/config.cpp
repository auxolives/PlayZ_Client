class CfgPatches
{
	class TerjeMedicine_Injectors_PlayZ
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"TerjeMedicine",
			"TerjeMedicine_Injectors"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class TerjeInjectorBase;
	class TerjeInjectorNovichek: TerjeInjectorBase
	{
		displayName = "#STR_PLAYZ_MED_INJECTOR_NOVICHEK";
		// ReviewName: Novichok Injector
		overdosedIncrement = 5;
		biohazardIncrement = 5;
		terjeAddShock = -100;
		medSkillExpAddToSelf = 10;
	};
	class TerjeInjectorErytromixelin: TerjeInjectorBase
	{
		displayName = "#STR_PLAYZ_MED_INJECTOR_ERYTROMIXELIN";
		// ReviewName: Erythrostat Injector
		medBloodHemostaticValue = 3;
		medBloodHemostaticTimeSec = 300;
		medBloodRegenValue = 2;
		medBloodRegenTimeSec = 150;
		overdosedIncrement = 0.32;
	};
	class TerjeInjectorRabinucoline: TerjeInjectorBase
	{
		displayName = "#STR_PLAYZ_MED_INJECTOR_RABINUCOLINE";
		// ReviewName: Rabies Antiserum Injector
		medRabiesAntibioticLevel = 3;
		medRabiesAntibioticTimeSec = 900;
		overdosedIncrement = 1.46;
	};
};
