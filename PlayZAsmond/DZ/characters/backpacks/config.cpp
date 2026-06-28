class CfgPatches
{
	class PlayZAsmond_backpacks
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters_Backpacks",
			"PlayZAsmond",
			"AsmondClothing",
		};
	};
};

class CfgSlots
{
	class Slot_NBC_Jacket
	{
		name = "NBC_Jacket";
		displayName = "#STR_CfgBody0";
		ghostIcon = "set:dayz_inventory image:body";
	};
	class Slot_NBC_Pants
	{
		name = "NBC_Pants";
		displayName = "#STR_CfgLegs0";
		ghostIcon = "set:dayz_inventory image:legs";
	};
	class Slot_NBC_Hood
	{
		name = "NBC_Hood";
		displayName = "#STR_CfgHeadgear0";
		ghostIcon = "set:dayz_inventory image:headgear";
	};
	class Slot_NBC_Gloves
	{
		name = "NBC_Gloves";
		displayName = "#STR_CfgGloves0";
		ghostIcon = "set:dayz_inventory image:gloves";
	};
	class Slot_NBC_Boots
	{
		name = "NBC_Boots";
		displayName = "#STR_CfgFeet0";
		ghostIcon = "set:dayz_inventory image:feet";
	};
	class Slot_NBC_GasMask
	{
		name = "NBC_GasMask";
		displayName = "#STR_CfgMask0";
		ghostIcon = "set:dayz_inventory image:mask";
	};
	class Slot_NBC_Filter1
	{
		name = "NBC_Filter1";
		displayName = "#STR_GasMask_Filter0";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
	class Slot_NBC_Filter2
	{
		name = "NBC_Filter2";
		displayName = "#STR_GasMask_Filter0";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
	class Slot_NBC_Filter3
	{
		name = "NBC_Filter3";
		displayName = "#STR_GasMask_Filter0";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
	class Slot_NBC_Filter4
	{
		name = "NBC_Filter4";
		displayName = "#STR_GasMask_Filter0";
		ghostIcon = "set:dayz_inventory image:gasmaskfilter";
	};
};

class CfgVehicles
{
	class AliceBag_ColorBase;
	class ArmyPouch_ColorBase;
	class AssaultBag_ColorBase;
	class Attack2Bag_ColorBase;
	class ChildBag_ColorBase;
	class CoyoteBag_ColorBase;
	class DryBag_ColorBase;
	class DuffelBagSmall_ColorBase;
	class HuntingBag;
	class MountainBag_ColorBase;
	class SmershBag;
	class TaloonBag_ColorBase;
	class TortillaBag;

	class Asmond_AliceBag_ACU;
	class AliceBag_ACU: Asmond_AliceBag_ACU { scope=2; };

	class Asmond_AliceBag_Snow;
	class AliceBag_Snow: Asmond_AliceBag_Snow { scope=2; };

	class Asmond_AliceBag_EMR;
	class AliceBag_EMR: Asmond_AliceBag_EMR { scope=2; };

	class Asmond_AliceBag_Woodland;
	class AliceBag_Woodland: Asmond_AliceBag_Woodland { scope=2; };

	class Asmond_AliceBag_TTSKO;
	class AliceBag_TTSKO: Asmond_AliceBag_TTSKO { scope=2; };

	class Asmond_AliceBag_Brown;
	class AliceBag_Brown: Asmond_AliceBag_Brown { scope=2; };

	class Asmond_AliceBag_Winter;
	class AliceBag_Winter: Asmond_AliceBag_Winter { scope=2; };

	class Asmond_AliceBag_Desert;
	class AliceBag_Desert: Asmond_AliceBag_Desert { scope=2; };

	class Asmond_ArmyPouch_Winter;
	class ArmyPouch_Winter: Asmond_ArmyPouch_Winter { scope=2; };

	class Asmond_ArmyPouch_Desert;
	class ArmyPouch_Desert: Asmond_ArmyPouch_Desert { scope=2; };

	class Asmond_AssaultBag_ACU;
	class AssaultBag_ACU: Asmond_AssaultBag_ACU { scope=2; };

	class Asmond_AssaultBag_Snow;
	class AssaultBag_Snow: Asmond_AssaultBag_Snow { scope=2; };

	class Asmond_AssaultBag_EMR;
	class AssaultBag_EMR: Asmond_AssaultBag_EMR { scope=2; };

	class Asmond_AssaultBag_Woodland;
	class AssaultBag_Woodland: Asmond_AssaultBag_Woodland { scope=2; };

	class Asmond_AssaultBag_Tan;
	class AssaultBag_Tan: Asmond_AssaultBag_Tan { scope=2; };

	class Asmond_AssaultBag_BDU;
	class AssaultBag_BDU: Asmond_AssaultBag_BDU { scope=2; };

	class Asmond_AssaultBag_Hunter;
	class AssaultBag_Hunter: Asmond_AssaultBag_Hunter { scope=2; };

	class Asmond_AssaultBag_Desert;
	class AssaultBag_Desert: Asmond_AssaultBag_Desert { scope=2; };

	class Asmond_Attack2Bag_Arctic;
	class Attack2Bag_Arctic: Asmond_Attack2Bag_Arctic { scope=2; };

	class Asmond_Attack2Bag_M05;
	class Attack2Bag_M05: Asmond_Attack2Bag_M05 { scope=2; };

	class Asmond_Attack2Bag_Snow;
	class Attack2Bag_Snow: Asmond_Attack2Bag_Snow { scope=2; };

	class Asmond_Attack2Bag_BDU;
	class Attack2Bag_BDU: Asmond_Attack2Bag_BDU { scope=2; };

	class Asmond_Attack2Bag_Desert;
	class Attack2Bag_Desert: Asmond_Attack2Bag_Desert { scope=2; };

	class Asmond_Attack2Bag_EMR;
	class Attack2Bag_EMR: Asmond_Attack2Bag_EMR { scope=2; };

	class Asmond_ChildBag_Pink;
	class ChildBag_Pink: Asmond_ChildBag_Pink { scope=2; };

	class Asmond_ChildBag_Grey;
	class ChildBag_Grey: Asmond_ChildBag_Grey { scope=2; };

	class Asmond_ChildBag_Beige;
	class ChildBag_Beige: Asmond_ChildBag_Beige { scope=2; };

	class Asmond_ChildBag_Olive;
	class ChildBag_Olive: Asmond_ChildBag_Olive { scope=2; };

	class Asmond_CoyoteBag_ACU;
	class CoyoteBag_ACU: Asmond_CoyoteBag_ACU { scope=2; };

	class Asmond_CoyoteBag_Snow;
	class CoyoteBag_Snow: Asmond_CoyoteBag_Snow { scope=2; };

	class Asmond_CoyoteBag_BDU;
	class CoyoteBag_BDU: Asmond_CoyoteBag_BDU { scope=2; };

	class Asmond_CoyoteBag_EMR;
	class CoyoteBag_EMR: Asmond_CoyoteBag_EMR { scope=2; };

	class Asmond_CoyoteBag_Woodland;
	class CoyoteBag_Woodland: Asmond_CoyoteBag_Woodland { scope=2; };

	class Asmond_CoyoteBag_Desert;
	class CoyoteBag_Desert: Asmond_CoyoteBag_Desert { scope=2; };

	class Asmond_CoyoteBag_TTSKO;
	class CoyoteBag_TTSKO: Asmond_CoyoteBag_TTSKO { scope=2; };

	class Asmond_CoyoteBag_Hero;
	class CoyoteBag_Hero: Asmond_CoyoteBag_Hero { scope=2; };

	class Asmond_DryBag_Camo;
	class DryBag_Camo: Asmond_DryBag_Camo { scope=2; };

	class Asmond_DryBag_Grey;
	class DryBag_Grey: Asmond_DryBag_Grey { scope=2; };

	class Asmond_DryBag_White;
	class DryBag_White: Asmond_DryBag_White { scope=2; };

	class Asmond_DryBag_Brown;
	class DryBag_Brown: Asmond_DryBag_Brown { scope=2; };

	class Asmond_DryBag_Hazmat;
	class DryBag_Hazmat: Asmond_DryBag_Hazmat
	{
		scope = 2;
		itemsCargoSize[] = {6,5};
		attachments[] = {
			"Chemlight",
			"WalkieTalkie",
			"Backpack_1",
			"NBC_Jacket",
			"NBC_Pants",
			"NBC_Hood",
			"NBC_Gloves",
			"NBC_Boots",
			"NBC_GasMask",
			"NBC_Filter1",
			"NBC_Filter2",
			"NBC_Filter3",
			"NBC_Filter4"
		};
		class GUIInventoryAttachmentsProps
		{
			class NBCKit
			{
				name = "NBC";
				description = "";
				attachmentSlots[] = {
					"NBC_Jacket",
					"NBC_Pants",
					"NBC_Hood",
					"NBC_Gloves",
					"NBC_Boots",
					"NBC_GasMask",
					"NBC_Filter1",
					"NBC_Filter2",
					"NBC_Filter3",
					"NBC_Filter4"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
				view_index = 1;
			};
			class Accessories
			{
				name = "$STR_attachment_accessories";
				description = "";
				attachmentSlots[] = {
					"Chemlight",
					"WalkieTalkie",
					"Backpack_1"
				};
				icon = "set:dayz_inventory image:cat_fp_tents";
				view_index = 2;
			};
		};
	};

	class Asmond_DuffelBagSmall_Leather;
	class DuffelBagSmall_Leather: Asmond_DuffelBagSmall_Leather
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\Characters\backpacks\data\DuffelBagSmall.rvmat"}},{0.7,{"AsmondClothing\Data\Backpacks\DuffelBagSmall\Data\Asmond_DuffelBagSmall_Opaque.rvmat"}},{0.5,{"AsmondClothing\Data\Backpacks\DuffelBagSmall\Data\Asmond_DuffelBagSmall_Opaque_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Backpacks\DuffelBagSmall\Data\Asmond_DuffelBagSmall_Opaque_Damage.rvmat"}},{0,{"AsmondClothing\Data\Backpacks\DuffelBagSmall\Data\Asmond_DuffelBagSmall_Opaque_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_DuffelBagSmall_Winter;
	class DuffelBagSmall_Winter: Asmond_DuffelBagSmall_Winter { scope=2; };

	class Asmond_DuffelBagSmall_Desert;
	class DuffelBagSmall_Desert: Asmond_DuffelBagSmall_Desert { scope=2; };

	class Asmond_HuntingBag_BDU;
	class HuntingBag_BDU: Asmond_HuntingBag_BDU { scope=2; };

	class Asmond_HuntingBag_Beige;
	class HuntingBag_Beige: Asmond_HuntingBag_Beige { scope=2; };

	class Asmond_HuntingBag_Green;
	class HuntingBag_Green: Asmond_HuntingBag_Green { scope=2; };

	class Asmond_HuntingBag_White;
	class HuntingBag_White: Asmond_HuntingBag_White { scope=2; };

	class Asmond_HuntingBag_Winter;
	class HuntingBag_Winter: Asmond_HuntingBag_Winter { scope=2; };

	class Asmond_HuntingBag_TTSKO;
	class HuntingBag_TTSKO: Asmond_HuntingBag_TTSKO { scope=2; };

	class Asmond_HuntingBag_Hunter;
	class HuntingBag_Hunter: Asmond_HuntingBag_Hunter { scope=2; };

	class Asmond_HuntingBag_YellowKing;
	class HuntingBag_YellowKing: Asmond_HuntingBag_YellowKing
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\Characters\backpacks\data\hunting.rvmat"}},{0.7,{"AsmondClothing\Data\Backpacks\HuntingBag\Data\Asmond_HuntingBag_YellowKing.rvmat"}},{0.5,{"AsmondClothing\Data\Backpacks\HuntingBag\Data\Asmond_HuntingBag_YellowKing_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Backpacks\HuntingBag\Data\Asmond_HuntingBag_YellowKing_Damage.rvmat"}},{0,{"AsmondClothing\Data\Backpacks\HuntingBag\Data\Asmond_HuntingBag_YellowKing_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_HuntingBag_Desert;
	class HuntingBag_Desert: Asmond_HuntingBag_Desert { scope=2; };

	class Asmond_MountainBag_Orange;
	class MountainBag_Orange_2: Asmond_MountainBag_Orange { scope=2; };

	class Asmond_MountainBag_BrownBlack;
	class MountainBag_BrownBlack: Asmond_MountainBag_BrownBlack { scope=2; };

	class Asmond_MountainBag_White;
	class MountainBag_White: Asmond_MountainBag_White { scope=2; };

	class Asmond_MountainBag_Winter;
	class MountainBag_Winter: Asmond_MountainBag_Winter { scope=2; };

	class Asmond_MountainBag_BlackBlue;
	class MountainBag_BlackBlue: Asmond_MountainBag_BlackBlue { scope=2; };

	class Asmond_MountainBag_Hunter;
	class MountainBag_Hunter: Asmond_MountainBag_Hunter { scope=2; };

	class Asmond_MountainBag_Paramedic;
	class MountainBag_Paramedic: Asmond_MountainBag_Paramedic
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\Characters\backpacks\data\mountain.rvmat"}},{0.7,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo.rvmat"}},{0.5,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MountainBag_Jungle;
	class MountainBag_Jungle: Asmond_MountainBag_Jungle
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\Characters\backpacks\data\mountain.rvmat"}},{0.7,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo.rvmat"}},{0.5,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MountainBag_BrownGreen;
	class MountainBag_BrownGreen: Asmond_MountainBag_BrownGreen
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\Characters\backpacks\data\mountain.rvmat"}},{0.7,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo.rvmat"}},{0.5,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MountainBag_BDU;
	class MountainBag_BDU: Asmond_MountainBag_BDU
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\Characters\backpacks\data\mountain.rvmat"}},{0.7,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo.rvmat"}},{0.5,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MountainBag_TTSKO;
	class MountainBag_TTSKO: Asmond_MountainBag_TTSKO
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\Characters\backpacks\data\mountain.rvmat"}},{0.7,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo.rvmat"}},{0.5,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MountainBag_Multicam;
	class MountainBag_Multicam: Asmond_MountainBag_Multicam
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							transferToAttachmentsCoef = 0.5;
							healthLevels[] = {{1,{"DZ\Characters\backpacks\data\mountain.rvmat"}},{0.7,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo.rvmat"}},{0.5,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Damage.rvmat"}},{0,{"AsmondClothing\Data\Backpacks\MountainBag\Data\Asmond_MountainBag_NoLogo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SmershBag_ACU;
	class SmershBag_ACU: Asmond_SmershBag_ACU { scope=2; };

	class Asmond_SmershBag_EMR;
	class SmershBag_EMR: Asmond_SmershBag_EMR { scope=2; };

	class Asmond_SmershBag_Woodland;
	class SmershBag_Woodland: Asmond_SmershBag_Woodland { scope=2; };

	class Asmond_SmershBag_Orel;
	class SmershBag_Orel: Asmond_SmershBag_Orel { scope=2; };

	class Asmond_SmershBag_Tan;
	class SmershBag_Tan: Asmond_SmershBag_Tan { scope=2; };

	class Asmond_SmershBag_TTSKO;
	class SmershBag_TTSKO: Asmond_SmershBag_TTSKO { scope=2; };

	class Asmond_SmershBag_Black;
	class SmershBag_Black: Asmond_SmershBag_Black { scope=2; };

	class Asmond_SmershBag_Grey;
	class SmershBag_Grey: Asmond_SmershBag_Grey { scope=2; };

	class Asmond_SmershBag_Winter;
	class SmershBag_Winter: Asmond_SmershBag_Winter { scope=2; };

	class Asmond_SmershBag_Desert;
	class SmershBag_Desert: Asmond_SmershBag_Desert { scope=2; };

	class Asmond_TaloonBag_Grey;
	class TaloonBag_Grey: Asmond_TaloonBag_Grey { scope=2; };

	class Asmond_TaloonBag_White;
	class TaloonBag_White: Asmond_TaloonBag_White { scope=2; };

	class Asmond_TaloonBag_Red;
	class TaloonBag_Red: Asmond_TaloonBag_Red { scope=2; };

	class Asmond_TaloonBag_Black;
	class TaloonBag_Black: Asmond_TaloonBag_Black { scope=2; };

	class Asmond_TaloonBag_DarkBlue;
	class TaloonBag_DarkBlue: Asmond_TaloonBag_DarkBlue { scope=2; };

	class Asmond_TaloonBag_DarkGreen;
	class TaloonBag_DarkGreen: Asmond_TaloonBag_DarkGreen { scope=2; };

	class Asmond_TaloonBag_Hunter;
	class TaloonBag_Hunter: Asmond_TaloonBag_Hunter { scope=2; };

	class Asmond_TaloonBag_LightBlue;
	class TaloonBag_LightBlue: Asmond_TaloonBag_LightBlue { scope=2; };

	class Asmond_TortillaBag_ACU;
	class TortillaBag_ACU: Asmond_TortillaBag_ACU { scope=2; };

	class Asmond_TortillaBag_Snow;
	class TortillaBag_Snow: Asmond_TortillaBag_Snow { scope=2; };

	class Asmond_TortillaBag_EMR;
	class TortillaBag_EMR: Asmond_TortillaBag_EMR { scope=2; };

	class Asmond_TortillaBag_Woodland;
	class TortillaBag_Woodland: Asmond_TortillaBag_Woodland { scope=2; };

	class Asmond_TortillaBag_BDU;
	class TortillaBag_BDU: Asmond_TortillaBag_BDU { scope=2; };

	class Asmond_TortillaBag_Black;
	class TortillaBag_Black: Asmond_TortillaBag_Black { scope=2; };

	class Asmond_TortillaBag_Brown;
	class TortillaBag_Brown: Asmond_TortillaBag_Brown { scope=2; };

	class Asmond_TortillaBag_TTSKO;
	class TortillaBag_TTSKO: Asmond_TortillaBag_TTSKO { scope=2; };

	class Asmond_TortillaBag_Grey;
	class TortillaBag_Grey: Asmond_TortillaBag_Grey { scope=2; };

	class Asmond_TortillaBag_Desert;
	class TortillaBag_Desert: Asmond_TortillaBag_Desert { scope=2; };

};
