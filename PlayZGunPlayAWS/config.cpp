class CfgPatches
{
	class sGunplay_AWS
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"sGunplay",
			"AD_ACOG",
			"AD_B13Mount",
			"AD_DHF5",
			"AD_LeupoldMk4",
			"AD_NFATACR",
			"AD_NFATACR_1_8",
			"AD_Pilad",
			"AD_PVS4",
			"AD_RMR",
			"AD_SpecterDR",
			"AD_XPS34",
			"PlayZGunPlay_Gear"
		};
	};
};
class CfgMods
{
	class sGunplay_AWS
	{
		dir = "PlayZGunPlayAWS";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "sGunplay_AWS";
		credits = "simonvic"; // Thanks sir!
		author = "simonvic";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
	};
};
class cfgVehicles
{
	class ItemOptics_Base
	{
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
	};
	class AD_ACOG_Base: ItemOptics_Base
	{
        s_pipRadius = 0.35;
        s_pipMagnification = 0.5;
		s_pipBlur = 0.01;
		s_pipChromAber = 0.2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					healthLevels[] = {
						{1.0,{"DZ\weapons\attachments\data\scope_alpha_clear_ca.paa","DZ\weapons\attachments\optics\data\lensglass_standard.rvmat","AdvancedWeaponScopes\ACOG\data\ACOGFO.rvmat","AdvancedWeaponScopes\ACOG\data\ACOG_FiberOptic.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_ACOG.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_MRD_ACOG_Rear_damaged.rvmat"}},
						{0.7,{}},
						{0.5,{"DZ\weapons\attachments\data\scope_alpha_damaged_ca.paa","DZ\weapons\attachments\optics\data\lensglass_standard_damage.rvmat","AdvancedWeaponScopes\ACOG\data\ACOGFO_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\ACOG_FiberOptic_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_ACOG_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_MRD_ACOG_Rear_damaged.rvmat"}},
						{0.3,{"DZ\weapons\attachments\data\scope_alpha_destroyed_ca.paa","DZ\weapons\attachments\optics\data\lensglass_standard_destruct.rvmat","AdvancedWeaponScopes\ACOG\data\ACOGFO_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\ACOG_FiberOptic_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_ACOG_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_MRD_ACOG_Rear_damaged.rvmat"}},
						{0.0,{"DZ\weapons\attachments\data\scope_alpha_destroyed_ca.paa","DZ\weapons\attachments\optics\data\lensglass_standard_destruct.rvmat","AdvancedWeaponScopes\ACOG\data\ACOGFO_destruct.rvmat","AdvancedWeaponScopes\ACOG\data\ACOG_FiberOptic_destruct.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_ACOG_destruct.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_MRD_ACOG_Rear_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class AD_ACOG_RMR_Base: ItemOptics_Base
	{
        s_pipRadius = 0.35;
        s_pipMagnification = 0.5;
		s_pipBlur = 0.01;
		s_pipChromAber = 0.2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					healthLevels[] = {
						{1.0,{"DZ\weapons\attachments\data\scope_alpha_clear_ca.paa","DZ\weapons\attachments\optics\data\lensglass_standard.rvmat","AdvancedWeaponScopes\ACOG\data\ACOGFO.rvmat","AdvancedWeaponScopes\ACOG\data\ACOG_FiberOptic.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_ACOG.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_MRD_ACOG_Rear_damaged.rvmat"}},
						{0.7,{}},
						{0.5,{"DZ\weapons\attachments\data\scope_alpha_damaged_ca.paa","DZ\weapons\attachments\optics\data\lensglass_standard_damage.rvmat","AdvancedWeaponScopes\ACOG\data\ACOGFO_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\ACOG_FiberOptic_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_ACOG_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_MRD_ACOG_Rear_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\RMR_damaged.rvmat"}},
						{0.3,{"DZ\weapons\attachments\data\scope_alpha_destroyed_ca.paa","DZ\weapons\attachments\optics\data\lensglass_standard_destruct.rvmat","AdvancedWeaponScopes\ACOG\data\ACOGFO_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\ACOG_FiberOptic_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_ACOG_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_MRD_ACOG_Rear_damaged.rvmat","AdvancedWeaponScopes\ACOG\data\RMR_damaged.rvmat"}},
						{0.0,{"DZ\weapons\attachments\data\scope_alpha_destroyed_ca.paa","DZ\weapons\attachments\optics\data\lensglass_standard_destruct.rvmat","AdvancedWeaponScopes\ACOG\data\ACOGFO_destruct.rvmat","AdvancedWeaponScopes\ACOG\data\ACOG_FiberOptic_destruct.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_ACOG_destruct.rvmat","AdvancedWeaponScopes\ACOG\data\Mount_MRD_ACOG_Rear_destruct.rvmat","AdvancedWeaponScopes\ACOG\data\RMR_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class AD_DHF5_Base: ItemOptics_Base
	{
		s_isFullscreen = 1;
		s_showEnterMisalignment = 1;
		s_pipRadius = 2;
		s_pipMagnification = 0.1;
		s_pipBlur = 0.001;
		s_pipChromAber = 0.5;
	};
	class AD_LeupoldMk4_Base: ItemOptics_Base
	{
		s_isFullscreen = 1;
		s_showEnterMisalignment = 1;
		s_pipRadius = 2;
		s_pipMagnification = 0.1;
		s_pipBlur = 0.001;
		s_pipChromAber = 0.5;
	};
	class AD_NFATACR_Base: ItemOptics_Base
	{
		s_isFullscreen = 1;
		s_showEnterMisalignment = 1;
		s_pipRadius = 2;
		s_pipMagnification = 0.1;
		s_pipBlur = 0.001;
		s_pipChromAber = 0.5;
	};
	class AD_NFATACR_B13_RMR: AD_NFATACR_Base
	{
		s_isFullscreen = 1;
		s_showEnterMisalignment = 1;
		s_pipRadius = 2;
		s_pipMagnification = 0.1;
		s_pipBlur = 0.001;
		s_pipChromAber = 0.5;
	};
	class AD_NFATACR_1_8_Base: ItemOptics_Base
	{
		s_isFullscreen = 1;
		s_showEnterMisalignment = 1;
		s_pipRadius = 3;
		s_pipMagnification = 0.1;
		s_pipBlur = 0.001;
		s_pipChromAber = 0.5;
	};
	class AD_Pilad_Base: ItemOptics_Base
	{
		s_isFullscreen = 1;
		s_showEnterMisalignment = 1;
		s_pipRadius = 2;
		s_pipMagnification = 0.1;
		s_pipBlur = 0.001;
		s_pipChromAber = 0.5;
	};
	class AD_PVS4_Base: ItemOptics_Base
	{
		s_isFullscreen = 1;
		s_showEnterMisalignment = 1;
		s_pipRadius = 2;
		s_pipMagnification = -0.3;
		s_pipBlur = 0.05;
		s_pipChromAber = 0.01;
	};
	class AD_SpecterDR_Base: ItemOptics_Base
	{
		s_pipRadius = 0.5;
		s_pipMagnification = 0.3;
		s_pipBlur = 0.01;
		s_pipChromAber = 0.3;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					healthLevels[] = {
						{1.0,{"DZ\weapons\attachments\data\scope_alpha_clear_ca.paa","DZ\weapons\attachments\optics\data\lensglass_standard.rvmat","AdvancedWeaponScopes\SpecterDR\data\specterdr.rvmat"}},
						{0.7,{}},
						{0.5,{"DZ\weapons\attachments\data\scope_alpha_damaged_ca.paa","DZ\weapons\attachments\optics\data\lensglass_standard_damage.rvmat","AdvancedWeaponScopes\SpecterDR\data\specterdr_damage.rvmat"}},
						{0.3,{}},
						{0.0,{"DZ\weapons\attachments\data\scope_alpha_destroyed_ca.paa","DZ\weapons\attachments\optics\data\lensglass_standard_destruct.rvmat","AdvancedWeaponScopes\SpecterDR\data\specterdr_destruct.rvmat"}}
					};
				};
			};
		};
		class OpticsInfo
		{
			opticsZoomMin = "0.3926/1.5";
			opticsZoomMax = "0.3926/6";
			opticsZoomInit = "0.3926/1.5";
			discretefov[] = {
				"0.3926/1.5",
				"0.3926/6"
			};
		};
	};
	class AD_XPS34_HHS_Base: ItemOptics_Base
	{
		s_pipOffset[] = {
			0,
			0.03
		};
		s_pipLensOffset[] = {
			0,
			-0.03
		};
		s_pipRadius = 0.5;
		s_pipMagnification = 0.3;
		s_pipBlur = 0.02;
		s_pipChromAber = 0.2;
	};
	class AD_G33_Base: ItemOptics_Base
	{
		s_pipRadius = 0.35;
		s_pipMagnification = 0.3;
		s_pipBlur = 0.02;
		s_pipChromAber = 0.3;
	};
};