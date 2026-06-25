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
			"sFramework"
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

	class ItemOptics
	{
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
	};
	class ItemOptics_Base: ItemOptics
	{
		s_pipOffset[] = {0,0};
		s_pipLensOffset[] = {0,0};
		s_pipRadius = 0;
		s_pipMagnification = 0;
		s_pipBlur = 0.01;
		s_pipChromAber = 0.01;
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
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
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
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
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
	};

	class StarlightOptic: ItemOptics_Base
	{
		s_isFullscreen = 1;
		s_showEnterMisalignment = 1;
		s_pipRadius = 1;
		s_pipMagnification = -0.3;
		s_pipBlur = 0.05;
		s_pipChromAber = 0.01;
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
	};

	class AugOptic: ItemOptics
	{
		s_pipRadius = 0.6;
		s_pipMagnification = 0.25;
		s_pipBlur = 0.01;
		s_pipChromAber = 0.1;
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
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
};
