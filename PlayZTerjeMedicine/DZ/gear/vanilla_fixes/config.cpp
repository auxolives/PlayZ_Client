class CfgPatches
{
	class Terje_Gears_PlayZ
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"TerjeMedicine_FixVanilla",
			"DZ_Data",
			"DZ_Gear_Crafting",
			"DZ_Gear_Consumables",
			"DZ_Characters_Tops",
			"DZ_Characters_Shoes",
			"DZ_Characters_Pants",
			"DZ_Characters_Masks",
			"DZ_Characters_Headgear",
			"DZ_Characters_Gloves"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Clothing;
	class LeatherJacket_ColorBase: Clothing
	{
		class Protection
		{
			melee = 0.2;
			firearm = 0.1;
		};
	};
	class Chestplate: Clothing
	{
		class Protection
		{
			melee = 0.65;
			firearm = 0.35;
		};
	};
	class Chainmail: Clothing
	{
		class Protection
		{
			melee = 0.6;
			firearm = 0.2;
		};
	};
	class LeatherPants_ColorBase: Clothing
	{
		class Protection
		{
			melee = 0.2;
			firearm = 0.1;
		};
	};
	class Chainmail_Leggings: Clothing
	{
		class Protection
		{
			melee = 0.5;
			firearm = 0.2;
		};
	};
	class PlateCarrierVest: Clothing
	{
		class Protection
		{
			melee = 0.6;
			firearm = 0.5;
		};
	};
	class PressVest_ColorBase: Clothing
	{
		class Protection
		{
			melee = 0.4;
			firearm = 0.3;
		};
	};
	class PoliceVest: Clothing
	{
		class Protection
		{
			melee = 0.3;
			firearm = 0.15;
		};
	};
	class Chainmail_Coif: Clothing
	{
		class Protection
		{
			melee = 0.5;
			firearm = 0.2;
		};
	};
	class BallisticHelmet_ColorBase: Clothing
	{
		class Protection
		{
			melee = 0.5;
			firearm = 0.35;
		};
	};
	class ZSh3PilotHelmet: Clothing
	{
		class Protection
		{
			melee = 0.5;
			firearm = 0.0;
		};
	};
	class ConstructionHelmet_ColorBase: Clothing
	{
		class Protection
		{
			melee = 0.5;
			firearm = 0.0;
		};
	};
	class MotoHelmet_ColorBase: Clothing
	{
		class Protection
		{
			melee = 0.8;
			firearm = 0.0;
		};
	};
	class DarkMotoHelmet_ColorBase: Clothing
	{
		class Protection
		{
			melee = 0.8;
			firearm = 0.0;
		};
	};
	class TankerHelmet: Clothing
	{
		class Protection
		{
			melee = 0.5;
			firearm = 0.0;
		};
	};
	class GorkaHelmet: Clothing
	{
		class Protection
		{
			melee = 0.6;
			firearm = 0.25;
		};
	};
	class GreatHelm: Clothing
	{
		class Protection
		{
			melee = 0.5;
			firearm = 0.2;
		};
	};
	class NorseHelm: Clothing
	{
		class Protection
		{
			melee = 0.5;
			firearm = 0.2;
		};
	};
	class FirefightersHelmet_ColorBase: Clothing
	{
		class Protection
		{
			melee = 0.5;
			firearm = 0.0;
		};
	};
	class SkateHelmet_ColorBase: Clothing
	{
		class Protection
		{
			melee = 0.5;
			firearm = 0.0;
		};
	};
	class Ssh68Helmet: Clothing
	{
		class Protection
		{
			melee = 0.5;
			firearm = 0.15;
		};
	};
	class DirtBikeHelmet_ColorBase: Clothing
	{
		class Protection
		{
			melee = 0.8;
			firearm = 0.0;
		};
	};
	class HockeyHelmet_ColorBase: Clothing
	{
		class Protection
		{
			melee = 0.8;
			firearm = 0.0;
		};
	};
	class Mich2001Helmet: Clothing
	{
		class Protection
		{
			melee = 0.7;
			firearm = 0.35;
		};
	};
};