class CfgPatches
{
	class TerjeMedicine_Tools_PlayZ
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"TerjeMedicine",
			"TerjeMedicine_Tools"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BandageDressing;
	class TerjeBandageHemostatic: BandageDressing
	{
		medBloodHemostaticTimeSec = 2400;
	};
	class TerjeSurgicalKit: Inventory_Base
	{
		terjeSurgeryVisceraEffectivity = 0.4;
		varQuantityInit = 10;
		varQuantityMin = 0;
		varQuantityMax = 10;
		itemSize[] = {
			3,
			2
		};
		inventorySlot[] += {
			"Belt_Left"
		};
	};
	class TerjeSurgicalTool_ColorBase;
	class TerjeSurgicalTool_White: TerjeSurgicalTool_ColorBase
	{
		itemSize[] = {
			2,
			2
		};
	};
	class TerjeSurgicalTool_Ceramic: TerjeSurgicalTool_ColorBase
	{
		itemSize[] = {
			2,
			2
		};
	};
};