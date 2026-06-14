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
	class RadDesactivator
	{
		displayName = "#STR_PLAYZ_RAD_D1_DEACT_SOLUTION";
		liquidFreezeThreshold = -5;
		liquidThawThreshold = -3;
	};
};
