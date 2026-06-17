class CfgPatches
{
	class PlayZTerjeRadiation_Liquids
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"TerjeRadiation",
			"TerjeRadiation_Liquids",
			"PlayZTerjeCore"
		};
	};
};

class CfgTerjeCustomLiquids
{
	class SoapyWater
	{
		// TerjeRadiation/Liquids defaults (reference)
		// displayName = "#STR_TERJERAD_SOAPY_WATER";
		// flammability = -10;
		// liquidFreezeThreshold = 0;
		// liquidThawThreshold = 0;
		// liquidBoilingThreshold = 150;
		// terjeRadiationCleanupForce = 10;
		terjeRadiationCleanupForce = 75;
		liquidFreezeThreshold = 0;
		liquidThawThreshold = 2;
		// liquidBoilingThreshold = 150;
	};
	class RadDesactivator
	{
		// TerjeRadiation/Liquids defaults (reference)
		// displayName = "#STR_TERJERAD_RAD_DISACTIVATOR";
		// flammability = -10;
		// liquidFreezeThreshold = 0;
		// liquidThawThreshold = 0;
		// liquidBoilingThreshold = 150;
		// terjeRadiationCleanupForce = 50;
		// terjeOverrideLiquidColor = -10267848;
		displayName = "#STR_PLAYZ_RAD_D1_DEACT_SOLUTION";
		liquidFreezeThreshold = -50;
		liquidThawThreshold = -40;
		terjeRadiationCleanupForce = 400;
		// liquidBoilingThreshold = 150;
	};
};
