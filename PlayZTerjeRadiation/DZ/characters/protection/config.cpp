class CfgPatches
{
	class PlayZTerjeRadiation_VanillaProtection
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"TerjeRadiation_Protection",
			"DZ_Characters_Shoes",
			"DZ_Characters_Gloves",
			"DZ_Characters_Masks",
			"DZ_Characters_Tops"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	class Wellies_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.18;
		};
	};
	class SurgicalGloves_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.18;
		};
	};
	class SkiGloves_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class SurgicalMask: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class Raincoat_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.20;
		};
	};
};
