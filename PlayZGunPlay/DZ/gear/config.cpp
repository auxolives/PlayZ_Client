class CfgPatches
{
	class PlayZGunPlay_Gear
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"PlayZGunPlay",
			"sFramework",
			"optic_a",
			"weapon_a",
			"weapon_b",
			"weapon_c"
		};
	};
};

class cfgVehicles
{

		class Static;
		class Inventory_Base: Static
		{
			s_recoilControlMouseX = 0;
			s_recoilControlMouseY = 0;
			s_recoilControlStabilityX = 0;
			s_recoilControlStabilityY = 0;
			s_recoilControlMisalignmentX = 0;
			s_recoilControlMisalignmentY = 0;
			s_recoilControlKick = 0;
		};

		class ItemOptics;
		class ItemOptics_Base: ItemOptics
		{
			s_pipOffset[] = {0,0};
			s_pipLensOffset[] = {0,0};
			s_pipRadius = 0;
			s_pipMagnification = 0;
			s_pipBlur = 0.01;
			s_pipChromAber = 0.01;
		};

		class ItemSuppressor;

		class ACOGOptic: ItemOptics_Base
		{
			s_pipRadius = 0.314;
			s_pipMagnification = 0.314;
			s_pipBlur = 0.01;
			s_pipChromAber = 0.2;
		};

		class ACOGOptic_6x: ItemOptics_Base
		{
			s_pipRadius = 0.2;
			s_pipMagnification = 0.5;
			s_pipBlur = 0.01;
			s_pipChromAber = 0.01;
			s_nearPlaneOverride = 0.39;
		};

		class PUScopeOptic: ItemOptics_Base
		{
			s_pipRadius = 0.42;
			s_pipMagnification = 0.5;
			s_pipBlur = 0.007;
			s_pipChromAber = 0.2;
		};

		class SSG82Optic: ItemOptics
		{
			s_pipRadius = 0.25;
			s_pipMagnification = 0.5;
			s_pipBlur = 0.03;
			s_pipChromAber = 0.2;
			s_nearPlaneOverride = 0.23;
		};

		class KashtanOptic: ItemOptics_Base
		{
			s_pipRadius = 0.5;
			s_pipMagnification = 0.5;
			s_pipBlur = 0.05;
			s_pipChromAber = 0.2;
		};

		class HuntingOptic: ItemOptics_Base
		{
			s_showEnterMisalignment = 1;
			s_isFullscreen = 1;
			s_pipRadius = 0.7;
			s_pipMagnification = 0.1;
			s_pipBlur = 0.05;
			s_pipChromAber = 0.3;
		};

		class MK4Optic_ColorBase: ItemOptics_Base
		{
			s_showEnterMisalignment = 1;
			s_isFullscreen = 1;
			s_pipRadius = 0.7;
			s_pipMagnification = 0.1;
			s_pipBlur = 0.05;
			s_pipChromAber = 0.3;
		};

		class PistolOptic: ItemOptics_Base
		{
			s_pipRadius = 0.47;
			s_pipMagnification = 0.3;
			s_pipBlur = 0.005;
			s_pipChromAber = 0.001;
		};

		class SportingOptic: ItemOptics_Base
		{
			s_pipRadius = 0.4;
			s_pipMagnification = 0.314;
			s_pipBlur = 0.03;
			s_pipChromAber = 0.001;
		};

		class PSO1Optic: ItemOptics_Base
		{
			s_pipRadius = 0.45;
			s_pipMagnification = 0.314;
			s_pipBlur = 0.02;
			s_pipChromAber = 0.2;
			s_nearPlaneOverride = 0.15;
		};

		class PSO11Optic: ItemOptics_Base
		{
			s_pipRadius = 0.45;
			s_pipMagnification = 0.314;
			s_pipBlur = 0.02;
			s_pipChromAber = 0.2;
			s_nearPlaneOverride = 0.15;
		};

		class PSO6Optic: PSO1Optic
		{
			s_pipRadius = 0.26;
			s_pipMagnification = 0.1;
			s_pipBlur = 0.03;
			s_pipChromAber = 0.001;
			s_nearPlaneOverride = 0.25;
		};

		class KazuarOptic: ItemOptics_Base
		{
			s_isFullscreen = 1;
			s_showEnterMisalignment = 1;
			s_pipRadius = 1;
			s_pipMagnification = -0.3;
			s_pipBlur = 0.05;
			s_pipChromAber = 0.01;
		};

		class StarlightOptic: ItemOptics_Base
		{
			s_isFullscreen = 1;
			s_showEnterMisalignment = 1;
			s_pipRadius = 1;
			s_pipMagnification = -0.3;
			s_pipBlur = 0.05;
			s_pipChromAber = 0.01;
		};

		class AugOptic: ItemOptics
		{
			s_pipRadius = 0.6;
			s_pipMagnification = 0.25;
			s_pipBlur = 0.01;
			s_pipChromAber = 0.1;
		};

		class TF_OTs_14_GrozaOptic: ItemOptics
		{
			s_isFullscreen = 1;
			s_showEnterMisalignment = 1;
			s_pipRadius = 1;
			s_pipMagnification = 0.314;
			s_pipBlur = 0.01;
			s_pipChromAber = 0.2;
		};

		class TF_HAMROptic: ItemOptics
		{
			s_pipRadius = 0.4;
			s_pipMagnification = 0.314;
			s_pipBlur = 0.01;
			s_pipChromAber = 0.2;
		};

		class TF_ElcanSpecterDROptic_Base: ItemOptics
		{
			s_pipRadius = 0.5;
			s_pipMagnification = 0.314;
			s_pipBlur = 0.01;
			s_pipChromAber = 0.2;
			class OpticsInfo
			{
				opticsZoomMin = "0.3926/4";
				opticsZoomMax = "0.3926/4";
				opticsZoomInit = "0.3926/4";
				discretefov[] = {};
			};
		};

		class TF_ElcanSpecterDR_6xOptic_Base: ItemOptics
		{
			s_pipRadius = 0.3;
			s_pipMagnification = 0.5;
			s_pipBlur = 0.01;
			s_pipChromAber = 0.2;
			class OpticsInfo
			{
				opticsZoomMin = "0.3926/6";
				opticsZoomMax = "0.3926/6";
				opticsZoomInit = "0.3926/6";
				discretefov[] = {};
			};
		};

		class TF_EOTechXPSOptic_Base;
		class TF_EOTechXPSOpticUp_Black: TF_EOTechXPSOptic_Base
		{
			s_pipRadius = 0.7;
			s_pipMagnification = 0.4;
			s_pipBlur = 0.02;
			s_pipChromAber = 0.2;
		};

	class M4_OEBttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.16;
		s_recoilControlStabilityY = 0.15;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.10;
	};

	class M4_MPBttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.15;
		s_recoilControlStabilityY = 0.14;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.09;
	};

	class M4_CQBBttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.17;
		s_recoilControlStabilityY = 0.15;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.06;
		s_recoilControlKick = 0.11;
	};

	class AK_WoodBttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.16;
		s_recoilControlStabilityY = 0.15;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.10;
	};

	class AK_PlasticBttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.15;
		s_recoilControlStabilityY = 0.14;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.09;
	};

	class AK_FoldingBttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.14;
		s_recoilControlStabilityY = 0.13;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.08;
	};

	class AK74_WoodBttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.16;
		s_recoilControlStabilityY = 0.15;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.10;
	};

	class AKS74U_Bttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.14;
		s_recoilControlStabilityY = 0.13;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.08;
	};

	class MP5k_StockBttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.12;
		s_recoilControlStabilityY = 0.11;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.04;
		s_recoilControlKick = 0.08;
	};

	class Saiga_Bttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.14;
		s_recoilControlStabilityY = 0.12;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.09;
	};

	class Fal_OeBttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.15;
		s_recoilControlStabilityY = 0.13;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.09;
	};

	class Fal_FoldingBttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.13;
		s_recoilControlStabilityY = 0.12;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.08;
	};

	class PP19_Bttstck: Inventory_Base
	{
		s_recoilControlStabilityX = 0.10;
		s_recoilControlStabilityY = 0.08;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.08;
	};

	class TF_PKP_PlasticBttstck: Inventory_Base
	{

		s_recoilControlStabilityX = 0.10;
		s_recoilControlStabilityY = 0.11;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.09;
	};

	class TF_PKM_WoodBttstck: Inventory_Base
	{

		s_recoilControlStabilityX = 0.12;
		s_recoilControlStabilityY = 0.08;
		s_recoilControlMisalignmentX = 0.03;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.05;
	};

	class TF_PKM_ZenitPT2Bttstck: Inventory_Base
	{

		s_recoilControlStabilityX = 0.16;
		s_recoilControlStabilityY = 0.15;
		s_recoilControlMisalignmentX = 0.03;
		s_recoilControlMisalignmentY = 0.07;
		s_recoilControlKick = 0.11;
	};

	class TF_PKM_CNCC39Bttstck: Inventory_Base
	{

		s_recoilControlStabilityX = 0.14;
		s_recoilControlStabilityY = 0.11;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.08;
	};

	class TF_M4_B5PrecisionBttstck: Inventory_Base
	{

		s_recoilControlStabilityX = 0.16;
		s_recoilControlStabilityY = 0.15;
		s_recoilControlMisalignmentX = 0.03;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.11;
	};

	class TF_M4_MagpulPRSGen3Bttstck_Base: Inventory_Base
	{

		s_recoilControlStabilityX = 0.16;
		s_recoilControlStabilityY = 0.15;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.04;
		s_recoilControlKick = 0.11;
	};

	class TF_M16_Bttstck_Base: Inventory_Base
	{

		s_recoilControlStabilityX = 0.12;
		s_recoilControlStabilityY = 0.10;
		s_recoilControlMisalignmentX = 0.03;
		s_recoilControlMisalignmentY = 0.04;
		s_recoilControlKick = 0.09;
	};

	class TF_M4_FABDGLCoreBttstck: Inventory_Base
	{

		s_recoilControlStabilityX = 0.13;
		s_recoilControlStabilityY = 0.11;
		s_recoilControlMisalignmentX = 0.03;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.09;
	};

	class TF_AK_MagpulZhukovBttstck: Inventory_Base
	{

		s_recoilControlStabilityX = 0.16;
		s_recoilControlStabilityY = 0.14;
		s_recoilControlMisalignmentX = 0.03;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.10;
	};

	class TF_AK_MVRIBttstck: Inventory_Base
	{

		s_recoilControlStabilityX = 0.11;
		s_recoilControlStabilityY = 0.11;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.07;
	};

	class TF_AK_Zenit_PT1Bttstck: Inventory_Base
	{

		s_recoilControlStabilityX = 0.16;
		s_recoilControlStabilityY = 0.12;
		s_recoilControlMisalignmentX = 0.03;
		s_recoilControlMisalignmentY = 0.04;
		s_recoilControlKick = 0.10;
	};

	class TF_AN94_PlasticBttstck_Base: Inventory_Base
	{

		s_recoilControlStabilityX = 0.10;
		s_recoilControlStabilityY = 0.11;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.09;
	};

	class TF_MAR10_Bttstck_Base: Inventory_Base
	{

		s_recoilControlStabilityX = 0.11;
		s_recoilControlStabilityY = 0.10;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.07;
	};

	class TF_M4CraneBttstck: TF_MAR10_Bttstck_Base
	{

		s_recoilControlStabilityX = 0.12;
		s_recoilControlStabilityY = 0.12;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.06;
		s_recoilControlKick = 0.09;
	};

	class TF_M4_ADARBttstck_Base: Inventory_Base
	{

		s_recoilControlStabilityX = 0.13;
		s_recoilControlStabilityY = 0.13;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.04;
		s_recoilControlKick = 0.09;
	};

	class TF_M4_CMMG_RIPBttstck_Base: Inventory_Base
	{

		s_recoilControlStabilityX = 0.15;
		s_recoilControlStabilityY = 0.15;
		s_recoilControlMisalignmentX = 0.03;
		s_recoilControlMisalignmentY = 0.06;
		s_recoilControlKick = 0.08;
	};

	class TF_SCAR_Mk20Bttstck_Base: Inventory_Base
	{

		s_recoilControlStabilityX = 0.14;
		s_recoilControlStabilityY = 0.13;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.05;
		s_recoilControlKick = 0.09;
	};

	class TF_SCAR_StndBttstck_Base: Inventory_Base
	{

		s_recoilControlStabilityX = 0.13;
		s_recoilControlStabilityY = 0.12;
		s_recoilControlMisalignmentX = 0.02;
		s_recoilControlMisalignmentY = 0.04;
		s_recoilControlKick = 0.08;
	};

		class M4_PlasticHndgrd: Inventory_Base
		{
			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.08;
			s_recoilControlMisalignmentY = 0.07;
		};

		class M4_RISHndgrd: Inventory_Base
		{
			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.10;
			s_recoilControlMisalignmentY = 0.08;
		};

		class M4_MPHndgrd: Inventory_Base
		{
			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.09;
			s_recoilControlMisalignmentY = 0.08;
		};

		class AK_WoodHndgrd: Inventory_Base
		{
			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.09;
			s_recoilControlMisalignmentY = 0.08;
		};

		class AK_RailHndgrd: Inventory_Base
		{
			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.10;
			s_recoilControlMisalignmentY = 0.08;
		};

		class AK_PlasticHndgrd: Inventory_Base
		{
			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.08;
			s_recoilControlMisalignmentY = 0.07;
		};

		class AK74_Hndgrd: Inventory_Base
		{
			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.10;
			s_recoilControlMisalignmentY = 0.08;
		};

		class MP5_PlasticHndgrd: Inventory_Base
		{
			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.09;
			s_recoilControlMisalignmentY = 0.08;
		};

		class MP5_RailHndgrd: Inventory_Base
		{
			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.10;
			s_recoilControlMisalignmentY = 0.08;
		};

		class TF_PKP_CNCC46Hndgrd_RIS: Inventory_Base
		{

			s_recoilControlStabilityX = 0.07;
			s_recoilControlStabilityY = 0.06;
			s_recoilControlMisalignmentX = 0.08;
			s_recoilControlMisalignmentY = 0.09;
			s_recoilControlKick = 0.00;
		};

		class TF_PKM_ZenitB50Hndgrd_RIS: Inventory_Base
		{

			s_recoilControlStabilityX = 0.09;
			s_recoilControlStabilityY = 0.09;
			s_recoilControlMisalignmentX = 0.11;
			s_recoilControlMisalignmentY = 0.08;
			s_recoilControlKick = 0.00;
		};

		class TF_M16_KACHndgrd_RIS_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.10;
			s_recoilControlMisalignmentX = 0.07;
			s_recoilControlMisalignmentY = 0.09;
			s_recoilControlKick = 0.00;
		};

		class TF_AR10_URXHndgrd_MLOCK: Inventory_Base
		{

			s_recoilControlStabilityX = 0.10;
			s_recoilControlStabilityY = 0.10;
			s_recoilControlMisalignmentX = 0.12;
			s_recoilControlMisalignmentY = 0.07;
			s_recoilControlKick = 0.00;
		};

		class TF_AR10_NoveskeHndgrd_Short_RIS: Inventory_Base
		{

			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.08;
			s_recoilControlMisalignmentY = 0.08;
			s_recoilControlKick = 0.00;
		};

		class TF_AR10_NoveskeHndgrd_Long_RIS: Inventory_Base
		{

			s_recoilControlStabilityX = 0.10;
			s_recoilControlStabilityY = 0.10;
			s_recoilControlMisalignmentX = 0.07;
			s_recoilControlMisalignmentY = 0.06;
			s_recoilControlKick = 0.00;
		};

		class TF_AR10_LancerHndgrd_MLOCK: Inventory_Base
		{

			s_recoilControlStabilityX = 0.10;
			s_recoilControlStabilityY = 0.07;
			s_recoilControlMisalignmentX = 0.08;
			s_recoilControlMisalignmentY = 0.07;
			s_recoilControlKick = 0.00;
		};

		class TF_AR10_KACHndgrd_RIS: Inventory_Base
		{

			s_recoilControlStabilityX = 0.10;
			s_recoilControlStabilityY = 0.09;
			s_recoilControlMisalignmentX = 0.11;
			s_recoilControlMisalignmentY = 0.09;
			s_recoilControlKick = 0.00;
		};

		class TF_AK_ZenitB10MB19Hndgrd_RIS: Inventory_Base
		{

			s_recoilControlStabilityX = 0.10;
			s_recoilControlStabilityY = 0.10;
			s_recoilControlMisalignmentX = 0.11;
			s_recoilControlMisalignmentY = 0.10;
			s_recoilControlKick = 0.00;
		};

		class TF_AK_MagpulZhukovHndgrdU_MLOCK: Inventory_Base
		{

			s_recoilControlStabilityX = 0.10;
			s_recoilControlStabilityY = 0.10;
			s_recoilControlMisalignmentX = 0.08;
			s_recoilControlMisalignmentY = 0.09;
			s_recoilControlKick = 0.00;
		};

		class TF_AK_MagpulMOEHndgrd_MLOCK: Inventory_Base
		{

			s_recoilControlStabilityX = 0.06;
			s_recoilControlStabilityY = 0.07;
			s_recoilControlMisalignmentX = 0.08;
			s_recoilControlMisalignmentY = 0.08;
			s_recoilControlKick = 0.00;
		};

		class TF_SCAR_ADDHndgrd_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.07;
			s_recoilControlStabilityY = 0.07;
			s_recoilControlMisalignmentX = 0.09;
			s_recoilControlMisalignmentY = 0.09;
			s_recoilControlKick = 0.00;
		};

		class TF_AKS74U_WoodHndgrd: Inventory_Base
		{

			s_recoilControlStabilityX = 0.06;
			s_recoilControlStabilityY = 0.06;
			s_recoilControlMisalignmentX = 0.07;
			s_recoilControlMisalignmentY = 0.08;
			s_recoilControlKick = 0.00;
		};

		class TF_AKS74U_CAAHndgrd_RIS: Inventory_Base
		{

			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.07;
			s_recoilControlMisalignmentX = 0.07;
			s_recoilControlMisalignmentY = 0.06;
			s_recoilControlKick = 0.00;
		};

		class TF_AKS74U_ZenitB11PlasticHndgrd_RIS: Inventory_Base
		{

			s_recoilControlStabilityX = 0.10;
			s_recoilControlStabilityY = 0.10;
			s_recoilControlMisalignmentX = 0.12;
			s_recoilControlMisalignmentY = 0.07;
			s_recoilControlKick = 0.00;
		};

		class TF_AK_ZenitB30B31Hndgrd_RIS: Inventory_Base
		{

			s_recoilControlStabilityX = 0.10;
			s_recoilControlStabilityY = 0.10;
			s_recoilControlMisalignmentX = 0.12;
			s_recoilControlMisalignmentY = 0.09;
			s_recoilControlKick = 0.00;
		};

		class TF_AR10_CMMG15Hndgrd_MLOCK_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.10;
			s_recoilControlStabilityY = 0.10;
			s_recoilControlMisalignmentX = 0.12;
			s_recoilControlMisalignmentY = 0.07;
			s_recoilControlKick = 0.00;
		};

		class TF_AR10_CMMG9Hndgrd_MLOCK_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.10;
			s_recoilControlStabilityY = 0.09;
			s_recoilControlMisalignmentX = 0.08;
			s_recoilControlMisalignmentY = 0.08;
			s_recoilControlKick = 0.00;
		};

		class TF_Handguard_M4_ADAR_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.06;
			s_recoilControlStabilityY = 0.06;
			s_recoilControlMisalignmentX = 0.11;
			s_recoilControlMisalignmentY = 0.08;
			s_recoilControlKick = 0.00;
		};

		class TF_Handguard_M4_DD12_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.09;
			s_recoilControlStabilityY = 0.07;
			s_recoilControlMisalignmentX = 0.08;
			s_recoilControlMisalignmentY = 0.07;
			s_recoilControlKick = 0.00;
		};

		class TF_Handguard_M4_DD9_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.06;
			s_recoilControlMisalignmentX = 0.09;
			s_recoilControlMisalignmentY = 0.07;
			s_recoilControlKick = 0.00;
		};

		class TF_Handguard_M4_DD_FSP_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.07;
			s_recoilControlStabilityY = 0.06;
			s_recoilControlMisalignmentX = 0.06;
			s_recoilControlMisalignmentY = 0.08;
			s_recoilControlKick = 0.00;
		};

		class TF_Handguard_M4_SMR13_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.07;
			s_recoilControlStabilityY = 0.09;
			s_recoilControlMisalignmentX = 0.08;
			s_recoilControlMisalignmentY = 0.07;
			s_recoilControlKick = 0.00;
		};

		class TF_Handguard_M4_SMR9_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.09;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.10;
			s_recoilControlMisalignmentY = 0.05;
			s_recoilControlKick = 0.00;
		};

		class TF_M4_Hndgrd_RIS_FDE_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.10;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.07;
			s_recoilControlMisalignmentY = 0.09;
			s_recoilControlKick = 0.00;
		};

		class TF_SCAR_MREXHndgrd_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.06;
			s_recoilControlStabilityY = 0.09;
			s_recoilControlMisalignmentX = 0.08;
			s_recoilControlMisalignmentY = 0.08;
			s_recoilControlKick = 0.00;
		};

		class TF_SCAR_StndHndgrd_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.06;
			s_recoilControlStabilityY = 0.07;
			s_recoilControlMisalignmentX = 0.11;
			s_recoilControlMisalignmentY = 0.06;
			s_recoilControlKick = 0.00;
		};

		class TF_ZenitRK1B25U_RIS_Grip: Inventory_Base
		{

			s_recoilControlStabilityX = 0.02;
			s_recoilControlStabilityY = 0.02;
			s_recoilControlMisalignmentX = 0.03;
			s_recoilControlMisalignmentY = 0.04;
			s_recoilControlKick = 0.00;
		};

		class TF_AR_Grip_Base: Inventory_Base
		{
			s_recoilControlStabilityX = 0.05;
			s_recoilControlStabilityY = 0.02;
			s_recoilControlMisalignmentX = 0.02;
			s_recoilControlMisalignmentY = 0.04;
			s_recoilControlKick = 0.00;
		};

		class TF_AK_Grip_Base: Inventory_Base
		{
			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.03;
			s_recoilControlMisalignmentX = 0.02;
			s_recoilControlMisalignmentY = 0.04;
			s_recoilControlKick = 0.00;
		};

		class TF_SAW_RIS_Grip_Base: Inventory_Base
		{
			s_recoilControlStabilityX = 0.04;
			s_recoilControlStabilityY = 0.03;
			s_recoilControlMisalignmentX = 0.03;
			s_recoilControlMisalignmentY = 0.04;
			s_recoilControlKick = 0.00;
		};

		class TF_AFG_RIS_Grip_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.07;
			s_recoilControlStabilityY = 0.10;
			s_recoilControlMisalignmentX = 0.03;
			s_recoilControlMisalignmentY = 0.05;
			s_recoilControlKick = 0.00;
		};

		class TF_AFG_MLOCK_Grip_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.07;
			s_recoilControlStabilityY = 0.06;
			s_recoilControlMisalignmentX = 0.02;
			s_recoilControlMisalignmentY = 0.05;
			s_recoilControlKick = 0.00;
		};

		class TF_BCM_MLOCK_Grip_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.03;
			s_recoilControlStabilityY = 0.06;
			s_recoilControlMisalignmentX = 0.02;
			s_recoilControlMisalignmentY = 0.04;
			s_recoilControlKick = 0.00;
		};

		class TF_RVG_RIS_Grip_Base: Inventory_Base
		{

			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.03;
			s_recoilControlMisalignmentY = 0.03;
			s_recoilControlKick = 0.00;
		};

		class MP5_Compensator: ItemSuppressor
		{
			s_recoilControlMisalignmentX = 0.06;
			s_recoilControlMisalignmentY = 0.02;
		};

		class Mosin_Compensator: ItemSuppressor
		{
			s_recoilControlStabilityX = 0.03;
			s_recoilControlStabilityY = 0.05;
			s_recoilControlMisalignmentX = 0.03;
			s_recoilControlMisalignmentY = 0.06;
		};

		class TF_OTs_14_Groza_Barrel_Grip: ItemSuppressor
		{

			s_recoilControlStabilityX = 0.07;
			s_recoilControlStabilityY = 0.08;
			s_recoilControlMisalignmentX = 0.02;
			s_recoilControlMisalignmentY = 0.04;
			s_recoilControlKick = 0.00;
		};

		class TF_PKM_SAICompensator: ItemSuppressor
		{

			s_recoilControlStabilityX = 0.07;
			s_recoilControlStabilityY = 0.04;
			s_recoilControlMisalignmentX = 0.05;
			s_recoilControlMisalignmentY = 0.02;
			s_recoilControlKick = 0.00;
		};

		class TF_AK_ZenitDTK1Compensator: ItemSuppressor
		{

			s_recoilControlStabilityX = 0.06;
			s_recoilControlStabilityY = 0.04;
			s_recoilControlMisalignmentX = 0.04;
			s_recoilControlMisalignmentY = 0.02;
			s_recoilControlKick = 0.00;
		};

		class TF_AK_6p20Compensator: ItemSuppressor
		{

			s_recoilControlStabilityX = 0.06;
			s_recoilControlStabilityY = 0.04;
			s_recoilControlMisalignmentX = 0.06;
			s_recoilControlMisalignmentY = 0.02;
			s_recoilControlKick = 0.00;
		};

		class TF_PKM_6ch76Compensator: ItemSuppressor
		{

			s_recoilControlStabilityX = 0.05;
			s_recoilControlStabilityY = 0.05;
			s_recoilControlMisalignmentX = 0.03;
			s_recoilControlMisalignmentY = 0.02;
			s_recoilControlKick = 0.00;
		};

		class TF_PKM_6ch63Compensator: ItemSuppressor
		{

			s_recoilControlStabilityX = 0.07;
			s_recoilControlStabilityY = 0.02;
			s_recoilControlMisalignmentX = 0.04;
			s_recoilControlMisalignmentY = 0.03;
			s_recoilControlKick = 0.00;
		};

		class TF_PKM_6ch43Compensator: ItemSuppressor
		{

			s_recoilControlStabilityX = 0.08;
			s_recoilControlStabilityY = 0.03;
			s_recoilControlMisalignmentX = 0.04;
			s_recoilControlMisalignmentY = 0.02;
			s_recoilControlKick = 0.00;
		};
};
