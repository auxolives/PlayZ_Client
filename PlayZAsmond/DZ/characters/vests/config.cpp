class CfgPatches
{
	class PlayZAsmond_vests
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters_Vests",
			"DZ_Gear_Containers",
			"PlayZAsmond",
			"AsmondClothing",
		};
	};
};

class CfgVehicles
{
	class ChestHolster;
	class Chestplate;
	class HighCapacityVest_ColorBase;
	class HuntingVest;
	class PlateCarrierHolster;
	class PlateCarrierPouches;
	class PlateCarrierVest;
	class PoliceVest;
	class PressVest_ColorBase;
	class SmershVest;
	class UKAssVest_ColorBase;

	class Asmond_ChestHolster_Black;
	class ChestHolster_Black: Asmond_ChestHolster_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\data\chest_holster.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\ChestHolster\Data\Asmond_ChestHolster_Plane.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\ChestHolster\Data\Asmond_ChestHolster_Plane_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\ChestHolster\Data\Asmond_ChestHolster_Plane_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\ChestHolster\Data\Asmond_ChestHolster_Plane_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_ChestHolster_Tan;
	class ChestHolster_Tan: Asmond_ChestHolster_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\data\chest_holster.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\ChestHolster\Data\Asmond_ChestHolster_Plane.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\ChestHolster\Data\Asmond_ChestHolster_Plane_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\ChestHolster\Data\Asmond_ChestHolster_Plane_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\ChestHolster\Data\Asmond_ChestHolster_Plane_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Chestplate_Rebels;
	class Chestplate_Rebels: Asmond_Chestplate_Rebels { scope=2; };

	class Asmond_Chestplate_RebelsRed;
	class Chestplate_RebelsRed: Asmond_Chestplate_RebelsRed { scope=2; };

	class Asmond_Chestplate_King;
	class Chestplate_King: Asmond_Chestplate_King { scope=2; };

	class Asmond_HighCapacityVest_Tiger;
	class HighCapacityVest_Tiger: Asmond_HighCapacityVest_Tiger { scope=2; };

	class Asmond_HighCapacityVest_Arctic;
	class HighCapacityVest_Arctic: Asmond_HighCapacityVest_Arctic { scope=2; };

	class Asmond_HighCapacityVest_VSRFlora;
	class HighCapacityVest_VSRFlora: Asmond_HighCapacityVest_VSRFlora { scope=2; };

	class Asmond_HighCapacityVest_ACU;
	class HighCapacityVest_ACU: Asmond_HighCapacityVest_ACU { scope=2; };

	class Asmond_HighCapacityVest_EMR;
	class HighCapacityVest_EMR: Asmond_HighCapacityVest_EMR { scope=2; };

	class Asmond_HighCapacityVest_Woodland;
	class HighCapacityVest_Woodland: Asmond_HighCapacityVest_Woodland { scope=2; };

	class Asmond_HighCapacityVest_Multicam;
	class HighCapacityVest_Multicam: Asmond_HighCapacityVest_Multicam { scope=2; };

	class Asmond_HighCapacityVest_Partizan;
	class HighCapacityVest_Partizan: Asmond_HighCapacityVest_Partizan { scope=2; };

	class Asmond_HighCapacityVest_BDU;
	class HighCapacityVest_BDU: Asmond_HighCapacityVest_BDU { scope=2; };

	class Asmond_HighCapacityVest_Tan;
	class HighCapacityVest_Tan: Asmond_HighCapacityVest_Tan { scope=2; };

	class Asmond_HighCapacityVest_Orel;
	class HighCapacityVest_Orel: Asmond_HighCapacityVest_Orel
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\TacticalVest2.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\HighCapacityVest\Data\Asmond_HighCapacityVest_Orel.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\HighCapacityVest\Data\Asmond_HighCapacityVest_Orel_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\HighCapacityVest\Data\Asmond_HighCapacityVest_Orel_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\HighCapacityVest\Data\Asmond_HighCapacityVest_Orel_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Melee
						{
							class Health
							{
								damage = 0.8;
							};
							class Blood
							{
								damage = 0.4;
							};
							class Shock
							{
								damage = 0.8;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.8;
							};
							class Blood
							{
								damage = 0.4;
							};
							class Shock
							{
								damage = 0.8;
							};
						};
					};
				};
	};

	class Asmond_HighCapacityVest_TTSKO;
	class HighCapacityVest_TTSKO: Asmond_HighCapacityVest_TTSKO { scope=2; };

	class Asmond_HighCapacityVest_Winter;
	class HighCapacityVest_Winter: Asmond_HighCapacityVest_Winter { scope=2; };

	class Asmond_HighCapacityVest_Desert;
	class HighCapacityVest_Desert: Asmond_HighCapacityVest_Desert { scope=2; };

	class Asmond_HuntingVest_PolarBearPelt;
	class HuntingVest_PolarBearPelt: Asmond_HuntingVest_PolarBearPelt
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\Hunting_vest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_BearPelt.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_BearPelt_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_BearPelt_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_BearPelt_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Melee
						{
							class Health
							{
								damage = 0.8;
							};
							class Blood
							{
								damage = 0.4;
							};
							class Shock
							{
								damage = 0.8;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.8;
							};
							class Blood
							{
								damage = 0.4;
							};
							class Shock
							{
								damage = 0.8;
							};
						};
					};
				};
	};

	class Asmond_HuntingVest_WolfPelt;
	class HuntingVest_WolfPelt: Asmond_HuntingVest_WolfPelt
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\Hunting_vest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_WolfPelt.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_WolfPelt_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_WolfPelt_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_WolfPelt_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Melee
						{
							class Health
							{
								damage = 0.8;
							};
							class Blood
							{
								damage = 0.4;
							};
							class Shock
							{
								damage = 0.8;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.8;
							};
							class Blood
							{
								damage = 0.4;
							};
							class Shock
							{
								damage = 0.8;
							};
						};
					};
				};
	};

	class Asmond_HuntingVest_BearPelt;
	class HuntingVest_BearPelt: Asmond_HuntingVest_BearPelt
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\Hunting_vest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_BearPelt.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_BearPelt_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_BearPelt_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\HuntingVest\Data\Asmond_HuntingVest_BearPelt_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Melee
						{
							class Health
							{
								damage = 0.8;
							};
							class Blood
							{
								damage = 0.4;
							};
							class Shock
							{
								damage = 0.8;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.8;
							};
							class Blood
							{
								damage = 0.4;
							};
							class Shock
							{
								damage = 0.8;
							};
						};
					};
				};
	};

	class Asmond_HuntingVest_Grey;
	class HuntingVest_Grey: Asmond_HuntingVest_Grey { scope=2; };

	class Asmond_HuntingVest_Winter;
	class HuntingVest_Winter_2: Asmond_HuntingVest_Winter { scope=2; };

	class Asmond_HuntingVest_Brown;
	class HuntingVest_Brown: Asmond_HuntingVest_Brown { scope=2; };

	class Asmond_HuntingVest_Beige;
	class HuntingVest_Beige: Asmond_HuntingVest_Beige { scope=2; };

	class Asmond_PlateCarrierVest_UN;
	class PlateCarrierVest_UN: Asmond_PlateCarrierVest_UN
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 225;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\BallisticVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_UN.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_UN_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_UN_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_UN_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.6;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.25;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.25;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.26;
							};
						};
					};
				};
	};

	class Asmond_PlateCarrierVest_Arctic;
	class PlateCarrierVest_Arctic: Asmond_PlateCarrierVest_Arctic
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 225;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\BallisticVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_Patch.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_Patch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_Patch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_Patch_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.6;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.25;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.25;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.26;
							};
						};
					};
				};
	};

	class Asmond_PlateCarrierVest_BDU;
	class PlateCarrierVest_BDU: Asmond_PlateCarrierVest_BDU
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 225;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\BallisticVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_Patch.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_Patch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_Patch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PlateCarrierVest\Data\Asmond_PlateCarrierVest_Patch_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.6;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.25;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.25;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.26;
							};
						};
					};
				};
	};

	class Asmond_PlateCarrierVest_EMR;
	class PlateCarrierVest_EMR: Asmond_PlateCarrierVest_EMR { scope=2; };

	class Asmond_PlateCarrierVest_Woodland;
	class PlateCarrierVest_Woodland: Asmond_PlateCarrierVest_Woodland { scope=2; };

	class Asmond_PlateCarrierVest_Desert;
	class PlateCarrierVest_Desert: Asmond_PlateCarrierVest_Desert { scope=2; };

	class Asmond_PlateCarrierVest_White;
	class PlateCarrierVest_White: Asmond_PlateCarrierVest_White { scope=2; };

	class Asmond_PlateCarrierVest_Brown;
	class PlateCarrierVest_Brown: Asmond_PlateCarrierVest_Brown { scope=2; };

	class Asmond_PlateCarrierVest_Surpat;
	class PlateCarrierVest_Surpat: Asmond_PlateCarrierVest_Surpat { scope=2; };

	class Asmond_PlateCarrierPouches_Arctic;
	class PlateCarrierPouches_Arctic: Asmond_PlateCarrierPouches_Arctic { scope=2; };

	class Asmond_PlateCarrierPouches_BDU;
	class PlateCarrierPouches_BDU: Asmond_PlateCarrierPouches_BDU { scope=2; };

	class Asmond_PlateCarrierPouches_Desert;
	class PlateCarrierPouches_Desert: Asmond_PlateCarrierPouches_Desert { scope=2; };

	class Asmond_PlateCarrierPouches_EMR;
	class PlateCarrierPouches_EMR: Asmond_PlateCarrierPouches_EMR { scope=2; };

	class Asmond_PlateCarrierPouches_Woodland;
	class PlateCarrierPouches_Woodland: Asmond_PlateCarrierPouches_Woodland { scope=2; };

	class Asmond_PlateCarrierPouches_Brown;
	class PlateCarrierPouches_Brown: Asmond_PlateCarrierPouches_Brown { scope=2; };

	class Asmond_PlateCarrierPouches_Surpat;
	class PlateCarrierPouches_Surpat: Asmond_PlateCarrierPouches_Surpat { scope=2; };

	class Asmond_PlateCarrierPouches_White;
	class PlateCarrierPouches_White: Asmond_PlateCarrierPouches_White { scope=2; };

	class Asmond_PlateCarrierHolster_Arctic;
	class PlateCarrierHolster_Arctic: Asmond_PlateCarrierHolster_Arctic { scope=2; };

	class Asmond_PlateCarrierHolster_BDU;
	class PlateCarrierHolster_BDU: Asmond_PlateCarrierHolster_BDU { scope=2; };

	class Asmond_PlateCarrierHolster_Desert;
	class PlateCarrierHolster_Desert: Asmond_PlateCarrierHolster_Desert { scope=2; };

	class Asmond_PlateCarrierHolster_EMR;
	class PlateCarrierHolster_EMR: Asmond_PlateCarrierHolster_EMR { scope=2; };

	class Asmond_PlateCarrierHolster_Woodland;
	class PlateCarrierHolster_Woodland: Asmond_PlateCarrierHolster_Woodland { scope=2; };

	class Asmond_PlateCarrierHolster_Brown;
	class PlateCarrierHolster_Brown: Asmond_PlateCarrierHolster_Brown { scope=2; };

	class Asmond_PlateCarrierHolster_Surpat;
	class PlateCarrierHolster_Surpat: Asmond_PlateCarrierHolster_Surpat { scope=2; };

	class Asmond_PlateCarrierHolster_White;
	class PlateCarrierHolster_White: Asmond_PlateCarrierHolster_White { scope=2; };

	class Asmond_PoliceVest_Orel;
	class PoliceVest_Orel: Asmond_PoliceVest_Orel
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 105;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\PoliceVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Orel.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Orel_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Orel_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Orel_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.75;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
					};
				};
	};

	class Asmond_PoliceVest_Black;
	class PoliceVest_Black: Asmond_PoliceVest_Black { scope=2; };

	class Asmond_PoliceVest_Tan;
	class PoliceVest_Tan: Asmond_PoliceVest_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 105;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\PoliceVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.75;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
					};
				};
	};

	class Asmond_PoliceVest_VSRFlora;
	class PoliceVest_VSRFlora: Asmond_PoliceVest_VSRFlora
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 105;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\PoliceVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.75;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
					};
				};
	};

	class Asmond_PoliceVest_Green;
	class PoliceVest_Green: Asmond_PoliceVest_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 105;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\PoliceVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.75;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
					};
				};
	};

	class Asmond_PoliceVest_Winter;
	class PoliceVest_Winter: Asmond_PoliceVest_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 105;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\PoliceVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PoliceVest\Data\Asmond_PoliceVest_Patch_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.75;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
					};
				};
	};

	class Asmond_PressVest_Grey;
	class PressVest_Grey: Asmond_PressVest_Grey { scope=2; };

	class Asmond_PressVest_Black;
	class PressVest_Black: Asmond_PressVest_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 170;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\PressVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.75;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
					};
				};
	};

	class Asmond_PressVest_AAN;
	class PressVest_AAN: Asmond_PressVest_AAN
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 170;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\PressVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.75;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
					};
				};
	};

	class Asmond_PressVest_Police;
	class PressVest_Police: Asmond_PressVest_Police
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 170;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\PressVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.75;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
					};
				};
	};

	class Asmond_PressVest_Green;
	class PressVest_Green: Asmond_PressVest_Green { scope=2; };

	class Asmond_PressVest_TTSKO;
	class PressVest_TTSKO: Asmond_PressVest_TTSKO
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 170;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\PressVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_Black_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.75;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
					};
				};
	};

	class Asmond_PressVest_UN;
	class PressVest_UN: Asmond_PressVest_UN
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 170;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\PressVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_UN.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_UN_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_UN_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_UN_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.75;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
					};
				};
	};

	class Asmond_PressVest_UNA;
	class PressVest_UNA: Asmond_PressVest_UNA
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 170;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\characters\vests\Data\PressVest.rvmat"}},{0.7,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_UN.rvmat"}},{0.5,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_UN_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_UN_Damage.rvmat"}},{0,{"AsmondClothing\Data\Vests\PressVest\Data\Asmond_PressVest_UN_Destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.75;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.55;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
					};
				};
	};

	class Asmond_SmershVest_ACU;
	class SmershVest_ACU: Asmond_SmershVest_ACU { scope=2; };

	class Asmond_SmershVest_EMR;
	class SmershVest_EMR: Asmond_SmershVest_EMR { scope=2; };

	class Asmond_SmershVest_Woodland;
	class SmershVest_Woodland: Asmond_SmershVest_Woodland { scope=2; };

	class Asmond_SmershVest_Orel;
	class SmershVest_Orel: Asmond_SmershVest_Orel { scope=2; };

	class Asmond_SmershVest_Tan;
	class SmershVest_Tan: Asmond_SmershVest_Tan { scope=2; };

	class Asmond_SmershVest_TTSKO;
	class SmershVest_TTSKO: Asmond_SmershVest_TTSKO { scope=2; };

	class Asmond_SmershVest_Black;
	class SmershVest_Black: Asmond_SmershVest_Black { scope=2; };

	class Asmond_SmershVest_Grey;
	class SmershVest_Grey: Asmond_SmershVest_Grey { scope=2; };

	class Asmond_SmershVest_Winter;
	class SmershVest_Winter: Asmond_SmershVest_Winter { scope=2; };

	class Asmond_SmershVest_Desert;
	class SmershVest_Desert: Asmond_SmershVest_Desert { scope=2; };

	class Asmond_UKAssaultVest_VSRFlora;
	class UKAssaultVest_VSRFlora: Asmond_UKAssaultVest_VSRFlora { scope=2; };

	class Asmond_UKAssaultVest_M05;
	class UKAssaultVest_M05: Asmond_UKAssaultVest_M05 { scope=2; };

	class Asmond_UKAssaultVest_MulticamDark;
	class UKAssaultVest_MulticamDark: Asmond_UKAssaultVest_MulticamDark { scope=2; };

	class Asmond_UKAssaultVest_Snow;
	class UKAssaultVest_Snow: Asmond_UKAssaultVest_Snow { scope=2; };

	class Asmond_UKAssaultVest_ACU;
	class UKAssaultVest_ACU: Asmond_UKAssaultVest_ACU { scope=2; };

	class Asmond_UKAssaultVest_EMR;
	class UKAssaultVest_EMR: Asmond_UKAssaultVest_EMR { scope=2; };

	class Asmond_UKAssaultVest_Woodland;
	class UKAssaultVest_Woodland: Asmond_UKAssaultVest_Woodland { scope=2; };

	class Asmond_UKAssaultVest_Orel;
	class UKAssaultVest_Orel: Asmond_UKAssaultVest_Orel { scope=2; };

	class Asmond_UKAssaultVest_Tan;
	class UKAssaultVest_Tan: Asmond_UKAssaultVest_Tan { scope=2; };

	class Asmond_UKAssaultVest_BDU;
	class UKAssaultVest_BDU: Asmond_UKAssaultVest_BDU { scope=2; };

	class Asmond_UKAssaultVest_TTSKO;
	class UKAssaultVest_TTSKO: Asmond_UKAssaultVest_TTSKO { scope=2; };

	class Asmond_UKAssaultVest_Desert;
	class UKAssaultVest_Desert: Asmond_UKAssaultVest_Desert { scope=2; };

};
