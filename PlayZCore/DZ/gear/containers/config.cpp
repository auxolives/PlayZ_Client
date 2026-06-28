class CfgPatches
{
	class DZ_Gear_Containers_PlayZCore
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Gear_Containers"
		};
	};
};

class CfgVehicles
{
	class Container_Base;
	class FirstAidKit: Container_Base
	{
		inventorySlot[] += {"Belt_Left"};
		class InventorySlotsOffsets
		{
			class Belt_Left
			{
				position[] = {0,-0.05,0};
				orientation[] = {0,180,180};
			};
		};
	};
	class FirstAidKit_NBC: Container_Base
	{
		scope = 2;
		displayName = "#STR_PlayZ_FirstAidKit_NBC0";
		descriptionShort = "#STR_PlayZ_FirstAidKit_NBC1";
		model = "\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags = 17;
		weight = 140;
		itemSize[] = {3,3};
		itemsCargoSize[] = {0,0};
		allowOwnedCargoManipulation = 0;
		randomQuantity = 0;
		canBeDigged = 1;
		repairableWithKits[] = {2};
		repairCosts[] = {25.0};
		isMeleeWeapon = 1;
		inventorySlot[] += {"Belt_Left"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\FirsAidKit.rvmat"};
		hiddenSelectionsTextures[] = {"PlayZ_Client\PlayZCore\DZ\gear\containers\data\firstaidkit_nbc_co.paa"};
		attachments[] = {
			"NBC_Jacket",
			"NBC_Pants",
			"NBC_Hood",
			"NBC_Gloves",
			"NBC_Boots",
			"NBC_GasMask",
			"NBC_Filter1",
			"NBC_Filter2"
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
					"NBC_Filter2"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 80;
					healthLevels[] = {
						{1.0,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.7,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.5,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0.3,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0.0,{"DZ\gear\containers\data\FirsAidKit_destruct.rvmat"}}
					};
				};
			};
		};
		soundImpactType = "textile";
		class InventorySlotsOffsets
		{
			class Belt_Left
			{
				position[] = {0,-0.05,0};
				orientation[] = {0,180,180};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
};
