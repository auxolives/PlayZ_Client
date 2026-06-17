class CfgPatches
{
	class PlayZTerjeRadiation_Tools
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"TerjeRadiation",
			"TerjeRadiation_Tools",
			"PlayZTerjeCore"
		};
	};
};

class CfgVehicles
{
	class Bottle_Base;
	class CanisterGasoline: Bottle_Base
	{
		varTemperatureFreezeTime = 3600;
		varTemperatureThawTime = 3600;
	};
	class TerjeCanisterChemical: CanisterGasoline
	{
		displayName = "#STR_PLAYZ_RAD_D1_CANISTER_NAME";
		descriptionShort = "#STR_PLAYZ_RAD_D1_CANISTER_DESC";
		// CanisterGasoline (DZ parent) temperature defaults (reference)
		// varTemperatureInit = 0;            // unset on parent
		// varTemperatureMin = 0;             // unset on parent → engine default 0
		// varTemperatureMax = 150;
		// varTemperatureFreezePoint = -200;  // container cfg; Terje liquid threshold used when filled
		// varTemperatureThawPoint = -200;
		// varTemperatureFreezeTime = 4752;
		// varTemperatureThawTime = 4752;
		// temperaturePerQuantityWeight = 8;
		varTemperatureMin = -100;
	};
};
