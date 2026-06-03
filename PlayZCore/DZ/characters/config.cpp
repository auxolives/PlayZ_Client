class CfgPatches
{
	class DZ_Characters_PlayZCore
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Tops",
			"DZ_Characters_Pants",
			"DZ_Characters_Gloves",
			"DZ_Characters_Backpacks",
			"DZ_Characters_Headgear",
			"DZ_Characters_Shoes"
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Clothing_Base;
	class Clothing;

	class LeatherSack_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {15.0};
	};
	class LeatherSack_Natural: LeatherSack_ColorBase {};
	class LeatherSack_Black: LeatherSack_ColorBase {};
	class LeatherSack_Beige: LeatherSack_ColorBase {};
	class LeatherSack_Brown: LeatherSack_ColorBase {};

	class LeatherJacket_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		itemsCargoSize[] = {6,4};
	};
	class LeatherJacket_Natural: LeatherJacket_ColorBase {};
	class LeatherJacket_Beige: LeatherJacket_ColorBase {};
	class LeatherJacket_Brown: LeatherJacket_ColorBase {};
	class LeatherJacket_Black: LeatherJacket_ColorBase {};

	class LeatherPants_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {20.0};
		itemsCargoSize[] = {5,4};
	};
	class LeatherPants_Natural: LeatherPants_ColorBase {};
	class LeatherPants_Beige: LeatherPants_ColorBase {};
	class LeatherPants_Brown: LeatherPants_ColorBase {};
	class LeatherPants_Black: LeatherPants_ColorBase {};

	class LeatherHat_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {15.0};
	};
	class LeatherHat_Natural: LeatherHat_ColorBase {};
	class LeatherHat_Beige: LeatherHat_ColorBase {};
	class LeatherHat_Brown: LeatherHat_ColorBase {};
	class LeatherHat_Black: LeatherHat_ColorBase {};	

	class LeatherShoes_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {15.0};
	};
	class LeatherShoes_Natural: LeatherShoes_ColorBase {};
	class LeatherShoes_Beige: LeatherShoes_ColorBase {};
	class LeatherShoes_Brown: LeatherShoes_ColorBase {};
	class LeatherShoes_Black: LeatherShoes_ColorBase {};

	class LeatherGloves_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {15.0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
				};
			};
		};
	};
	class LeatherGloves_Brown: LeatherGloves_ColorBase {};
	class LeatherGloves_Natural: LeatherGloves_ColorBase {};
	class LeatherGloves_Beige: LeatherGloves_ColorBase {};
	class LeatherGloves_Black: LeatherGloves_ColorBase {};
};
