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
	class CanisterGasoline;
	class TerjeCanisterChemical: CanisterGasoline
	{
		displayName = "#STR_PLAYZ_RAD_D1_CANISTER_NAME";
		descriptionShort = "#STR_PLAYZ_RAD_D1_CANISTER_DESC";
		varTemperatureMin = -100;
		varTemperatureFreezeTime = 2540;
		varTemperatureThawTime = 2540;
	};
};
