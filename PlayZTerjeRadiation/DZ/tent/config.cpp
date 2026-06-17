class CfgPatches
{
	class PlayZTerjeRadiation_Tent
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"TerjeRadiation_Tent",
			"PlayZTerjeRadiation"
		};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class TerjeRadTentStatic: HouseNoDestruct
	{
		scope = 2;
		model = "TerjeRadiation\Tent\RadTentStatic.p3d";
		displayName = "#STR_TERJERAD_RADTENT";
		descriptionShort = "#STR_TERJERAD_RADTENT_DESC";
		physLayer = "item_large";
		carveNavmesh = 1;
		attachments[] = {
			"CanisterGasoline",
			"CarBattery"
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_attachment_accessories";
				description = "";
				attachmentSlots[] = {
					"CanisterGasoline",
					"CarBattery"
				};
				icon = "set:dayz_inventory image:cat_fp_tents";
				view_index = 1;
			};
		};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			autoSwitchOffWhenInCargo = 1;
			energyUsagePerSecond = 0.05;
			plugType = 5;
			attachmentAction = 1;
			updateInterval = 1.0;
		};
	};
};
