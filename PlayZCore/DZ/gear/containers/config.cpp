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
		class DamageSystem;
	};
	class FirstAidKit_NBC: FirstAidKit
	{
		scope = 2;
		displayName = "$STR_PlayZ_FirstAidKit_NBC0";
		descriptionShort = "$STR_PlayZ_FirstAidKit_NBC1";
		itemsCargoSize[] = {0,0};
		allowOwnedCargoManipulation = 0;
		randomQuantity = 0;
		attachments[] = {
			"HazmatBag_Jacket",
			"HazmatBag_Pants",
			"HazmatBag_Hood",
			"HazmatBag_Gloves",
			"HazmatBag_Boots",
			"HazmatBag_GasMask",
			"HazmatBag_Filter1",
			"HazmatBag_Filter2"
		};
		class GUIInventoryAttachmentsProps
		{
			class NBCKit
			{
				name = "NBC";
				description = "";
				attachmentSlots[] = {
					"HazmatBag_Jacket",
					"HazmatBag_Pants",
					"HazmatBag_Hood",
					"HazmatBag_Gloves",
					"HazmatBag_Boots",
					"HazmatBag_GasMask",
					"HazmatBag_Filter1",
					"HazmatBag_Filter2"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					healthLevels[] = {
						{1.0,{"PlayZCore\DZ\gear\containers\data\firsaidkit_nbc.rvmat"}},
						{0.7,{"PlayZCore\DZ\gear\containers\data\firsaidkit_nbc.rvmat"}},
						{0.5,{"PlayZCore\DZ\gear\containers\data\firsaidkit_nbc_damage.rvmat"}},
						{0.3,{"PlayZCore\DZ\gear\containers\data\firsaidkit_nbc_damage.rvmat"}},
						{0.0,{"PlayZCore\DZ\gear\containers\data\firsaidkit_nbc_destruct.rvmat"}}
					};
				};
			};
		};
	};
};
