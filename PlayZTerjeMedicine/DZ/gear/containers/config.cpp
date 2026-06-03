class CfgPatches
{
	class DZ_Gear_Containers_PlayZ
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Containers",
			"TerjeMedicine",
			"TerjeMedicine_FirstAidKit"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class FirstAidKit: Container_Base
	{
		itemSize[]={3,3};
		itemsCargoSize[]={3,4};
	};
	class TerjeFirstAidKitAdvancedBase: Container_Base
	{
		itemSize[]={4,4};
		itemsCargoSize[]={5,4};
	};
	class TerjeFirstAidKitAdvance_Black: TerjeFirstAidKitAdvancedBase {};
	class TerjeFirstAidKitAdvance_Brown: TerjeFirstAidKitAdvancedBase {};
	class TerjeFirstAidKitAdvance_Green: TerjeFirstAidKitAdvancedBase {};
	class TerjeFirstAidKitAdvance_Camo: TerjeFirstAidKitAdvancedBase {};
	class TerjeFirstAidKitIndividualBase: Container_Base
	{
		itemSize[]={3,3};
		itemsCargoSize[]={4,3};
	};
	class TerjeFirstAidKitIndividual_Black: TerjeFirstAidKitIndividualBase {};
	class TerjeFirstAidKitIndividual_Brown: TerjeFirstAidKitIndividualBase {};
	class TerjeFirstAidKitIndividual_Green: TerjeFirstAidKitIndividualBase {};
	class TerjeFirstAidKitIndividual_Camo: TerjeFirstAidKitIndividualBase {};
	class TerjeFirstAidKitMedium: Container_Base
	{
		itemSize[]={4,4};
		itemsCargoSize[]={5,5};
	};
	class TerjeFirstAidKitLarge: Container_Base
	{
		itemSize[]={5,5};
		itemsCargoSize[]={6,6};
	};
};
