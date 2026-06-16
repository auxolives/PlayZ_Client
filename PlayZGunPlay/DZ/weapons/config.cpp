class CfgPatches
{
	class PlayZGunPlay_Weapons
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

class cfgWeapons
{
	class Pistol_Base;
	class Rifle_Base;
	class BoltActionRifle_Base;
	class BoltActionRifle_ExternalMagazine_Base;
	class BoltActionRifle_InnerMagazine_Base;
	class Shotgun_Base;

	class Glock19_Base: Pistol_Base
	{
		s_recoilControlStabilityX = 0.30;
		s_recoilControlStabilityY = 0.26;
		s_recoilControlMisalignmentX = 0.20;
		s_recoilControlMisalignmentY = 0.16;
		s_recoilControlKick = 0.26;
	};

	class CZ75_Base: Pistol_Base
	{
		s_recoilControlStabilityX = 0.27;
		s_recoilControlStabilityY = 0.23;
		s_recoilControlMisalignmentX = 0.17;
		s_recoilControlMisalignmentY = 0.13;
		s_recoilControlKick = 0.23;
	};

	class FNX45_Base: Pistol_Base
	{
		s_recoilControlStabilityX = 0.22;
		s_recoilControlStabilityY = 0.18;
		s_recoilControlMisalignmentX = 0.12;
		s_recoilControlMisalignmentY = 0.08;
		s_recoilControlKick = 0.18;
	};

	class Colt1911_Base: Pistol_Base
	{
		s_recoilControlStabilityX = 0.18;
		s_recoilControlStabilityY = 0.14;
		s_recoilControlMisalignmentX = 0.08;
		s_recoilControlMisalignmentY = 0.04;
		s_recoilControlKick = 0.14;
	};

	class MakarovIJ70_Base: Pistol_Base
	{
		s_recoilControlStabilityX = 0.40;
		s_recoilControlStabilityY = 0.36;
		s_recoilControlMisalignmentX = 0.32;
		s_recoilControlMisalignmentY = 0.28;
		s_recoilControlKick = 0.36;
	};

	class MakarovPB_Base: Pistol_Base
	{
		s_recoilControlStabilityX = 0.36;
		s_recoilControlStabilityY = 0.32;
		s_recoilControlMisalignmentX = 0.28;
		s_recoilControlMisalignmentY = 0.24;
		s_recoilControlKick = 0.32;
	};

	class P1_Base: Pistol_Base
	{
		s_recoilControlStabilityX = 0.08;
		s_recoilControlStabilityY = 0.04;
		s_recoilControlMisalignmentX = -0.02;
		s_recoilControlMisalignmentY = -0.06;
		s_recoilControlKick = 0.05;
	};

	class Deagle_Base: Pistol_Base
	{
		s_recoilControlStabilityX = -0.02;
		s_recoilControlStabilityY = -0.06;
		s_recoilControlMisalignmentX = -0.14;
		s_recoilControlMisalignmentY = -0.16;
		s_recoilControlKick = -0.04;
	};

	class Magnum_Base: Pistol_Base
	{
		s_recoilControlStabilityX = -0.06;
		s_recoilControlStabilityY = -0.10;
		s_recoilControlMisalignmentX = -0.18;
		s_recoilControlMisalignmentY = -0.20;
		s_recoilControlKick = -0.08;
	};


	class Derringer_Base: Pistol_Base
	{
		s_recoilControlStabilityX = -0.16;
		s_recoilControlStabilityY = -0.20;
		s_recoilControlMisalignmentX = -0.28;
		s_recoilControlMisalignmentY = -0.32;
		s_recoilControlKick = -0.18;
	};

	class Flaregun_Base: Pistol_Base
	{
		s_recoilControlStabilityX = 0.44;
		s_recoilControlStabilityY = 0.40;
		s_recoilControlMisalignmentX = 0.36;
		s_recoilControlMisalignmentY = 0.32;
		s_recoilControlKick = 0.40;
	};

	class CZ61_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.30;
		s_recoilControlStabilityY = 0.26;
		s_recoilControlMisalignmentX = 0.19;
		s_recoilControlMisalignmentY = 0.12;
		s_recoilControlKick = 0.26;
	};

	class MP5K_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.28;
		s_recoilControlStabilityY = 0.24;
		s_recoilControlMisalignmentX = 0.16;
		s_recoilControlMisalignmentY = 0.12;
		s_recoilControlKick = 0.18;
	};

	class PM73Rak_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.25;
		s_recoilControlStabilityY = 0.21;
		s_recoilControlMisalignmentX = -0.06;
		s_recoilControlMisalignmentY = -0.04;
		s_recoilControlKick = 0.22;
	};

	class PP19_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.50;
		s_recoilControlStabilityY = 0.46;
		s_recoilControlMisalignmentX = 0.36;
		s_recoilControlMisalignmentY = 0.32;
		s_recoilControlKick = 0.44;
	};

	class UMP45_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.56;
		s_recoilControlStabilityY = 0.52;
		s_recoilControlMisalignmentX = 0.42;
		s_recoilControlMisalignmentY = 0.38;
		s_recoilControlKick = 0.48;
	};

	class VSS_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.46;
		s_recoilControlStabilityY = 0.42;
		s_recoilControlMisalignmentX = 0.34;
		s_recoilControlMisalignmentY = 0.30;
		s_recoilControlKick = 0.32;
	};

	class Aug_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.40;
		s_recoilControlStabilityY = 0.36;
		s_recoilControlMisalignmentX = 0.30;
		s_recoilControlMisalignmentY = 0.26;
		s_recoilControlKick = 0.28;
	};

	class AugShort: Aug_Base
	{
		s_recoilControlStabilityX = 0.36;
		s_recoilControlStabilityY = 0.32;
		s_recoilControlMisalignmentX = 0.28;
		s_recoilControlMisalignmentY = 0.24;
		s_recoilControlKick = 0.14;
	};


	class Famas_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.42;
		s_recoilControlStabilityY = 0.38;
		s_recoilControlMisalignmentX = 0.30;
		s_recoilControlMisalignmentY = 0.26;
		s_recoilControlKick = 0.28;
	};

	class M16A2_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.44;
		s_recoilControlStabilityY = 0.40;
		s_recoilControlMisalignmentX = 0.32;
		s_recoilControlMisalignmentY = 0.28;
		s_recoilControlKick = 0.30;
	};

	class M4A1_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.20;
		s_recoilControlStabilityY = 0.18;
		s_recoilControlMisalignmentX = 0.12;
		s_recoilControlMisalignmentY = 0.10;
		s_recoilControlKick = 0.10;
	};

	class FAL_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.28;
		s_recoilControlStabilityY = 0.24;
		s_recoilControlMisalignmentX = 0.22;
		s_recoilControlMisalignmentY = 0.18;
		s_recoilControlKick = 0.18;
	};

	class AK74_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.22;
		s_recoilControlStabilityY = 0.20;
		s_recoilControlMisalignmentX = 0.14;
		s_recoilControlMisalignmentY = 0.12;
		s_recoilControlKick = 0.12;
	};

	class AKS74U: AK74_Base
	{
		s_recoilControlStabilityX = 0.34;
		s_recoilControlStabilityY = 0.30;
		s_recoilControlMisalignmentX = 0.22;
		s_recoilControlMisalignmentY = 0.18;
		s_recoilControlKick = 0.20;
	};

	class AK101_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.24;
		s_recoilControlStabilityY = 0.22;
		s_recoilControlMisalignmentX = 0.16;
		s_recoilControlMisalignmentY = 0.14;
		s_recoilControlKick = 0.14;
	};

	class AKM_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.20;
		s_recoilControlStabilityY = 0.18;
		s_recoilControlMisalignmentX = 0.12;
		s_recoilControlMisalignmentY = 0.10;
		s_recoilControlKick = 0.10;
	};

	class B95_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.28;
		s_recoilControlStabilityY = 0.24;
		s_recoilControlMisalignmentX = 0.18;
		s_recoilControlMisalignmentY = 0.14;
		s_recoilControlKick = 0.16;
	};

	class SawedoffB95: B95_Base
	{
		s_recoilControlStabilityX = 0.12;
		s_recoilControlStabilityY = 0.10;
		s_recoilControlMisalignmentX = 0.08;
		s_recoilControlMisalignmentY = 0.06;
		s_recoilControlKick = 0.06;
	};

	class Ruger1022_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.48;
		s_recoilControlStabilityY = 0.46;
		s_recoilControlMisalignmentX = 0.40;
		s_recoilControlMisalignmentY = 0.38;
		s_recoilControlKick = 0.46;
	};

	class Repeater_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.34;
		s_recoilControlStabilityY = 0.30;
		s_recoilControlMisalignmentX = 0.24;
		s_recoilControlMisalignmentY = 0.20;
		s_recoilControlKick = 0.22;
	};

	class SSG82_Base: BoltActionRifle_ExternalMagazine_Base
	{
		s_recoilControlStabilityX = 0.26;
		s_recoilControlStabilityY = 0.22;
		s_recoilControlMisalignmentX = 0.16;
		s_recoilControlMisalignmentY = 0.12;
		s_recoilControlKick = 0.14;
	};

	class Scout_Base: BoltActionRifle_ExternalMagazine_Base
	{
		s_recoilControlStabilityX = 0.28;
		s_recoilControlStabilityY = 0.24;
		s_recoilControlMisalignmentX = 0.18;
		s_recoilControlMisalignmentY = 0.14;
		s_recoilControlKick = 0.16;
	};

	class CZ527_Base: BoltActionRifle_ExternalMagazine_Base
	{
		s_recoilControlStabilityX = 0.26;
		s_recoilControlStabilityY = 0.22;
		s_recoilControlMisalignmentX = 0.16;
		s_recoilControlMisalignmentY = 0.12;
		s_recoilControlKick = 0.14;
	};

	class Mosin9130_Base: BoltActionRifle_InnerMagazine_Base
	{
		s_recoilControlStabilityX = 0.22;
		s_recoilControlStabilityY = 0.18;
		s_recoilControlMisalignmentX = 0.12;
		s_recoilControlMisalignmentY = 0.08;
		s_recoilControlKick = 0.12;
	};

	class SawedoffMosin9130_Base: Mosin9130_Base
	{
		s_recoilControlStabilityX = 0.14;
		s_recoilControlStabilityY = 0.12;
		s_recoilControlMisalignmentX = 0.06;
		s_recoilControlMisalignmentY = 0.04;
		s_recoilControlKick = 0.06;
	};

	class CZ550_Base: BoltActionRifle_ExternalMagazine_Base
	{
		s_recoilControlStabilityX = 0.28;
		s_recoilControlStabilityY = 0.24;
		s_recoilControlMisalignmentX = 0.18;
		s_recoilControlMisalignmentY = 0.14;
		s_recoilControlKick = 0.16;
	};

	class SV98_Base: BoltActionRifle_ExternalMagazine_Base
	{
		s_recoilControlStabilityX = 0.32;
		s_recoilControlStabilityY = 0.28;
		s_recoilControlMisalignmentX = 0.22;
		s_recoilControlMisalignmentY = 0.18;
		s_recoilControlKick = 0.18;
	};

	class Winchester70_Base: BoltActionRifle_InnerMagazine_Base
	{
		s_recoilControlStabilityX = 0.26;
		s_recoilControlStabilityY = 0.22;
		s_recoilControlMisalignmentX = 0.16;
		s_recoilControlMisalignmentY = 0.12;
		s_recoilControlKick = 0.14;
	};

	class Izh18_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.24;
		s_recoilControlStabilityY = 0.20;
		s_recoilControlMisalignmentX = 0.14;
		s_recoilControlMisalignmentY = 0.10;
		s_recoilControlKick = 0.12;
	};

	class Izh18;
	class SawedoffIzh18: Izh18
	{
		s_recoilControlStabilityX = 0.10;
		s_recoilControlStabilityY = 0.08;
		s_recoilControlMisalignmentX = 0.04;
		s_recoilControlMisalignmentY = 0.02;
		s_recoilControlKick = 0.04;
	};

	class SKS_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.28;
		s_recoilControlStabilityY = 0.24;
		s_recoilControlMisalignmentX = 0.18;
		s_recoilControlMisalignmentY = 0.14;
		s_recoilControlKick = 0.16;
	};

	class SVD_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.26;
		s_recoilControlStabilityY = 0.22;
		s_recoilControlMisalignmentX = 0.18;
		s_recoilControlMisalignmentY = 0.14;
		s_recoilControlKick = 0.14;
	};

	class M14_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.30;
		s_recoilControlStabilityY = 0.26;
		s_recoilControlMisalignmentX = 0.22;
		s_recoilControlMisalignmentY = 0.18;
		s_recoilControlKick = 0.18;
	};

	class Mp133Shotgun_Base: Shotgun_Base
	{
		s_recoilControlStabilityX = 0.16;
		s_recoilControlStabilityY = 0.14;
		s_recoilControlMisalignmentX = -0.12;
		s_recoilControlMisalignmentY = -0.06;
		s_recoilControlKick = 0.04;
	};

	class Saiga_Base: Rifle_Base
	{
		s_recoilControlStabilityX = 0.18;
		s_recoilControlStabilityY = 0.16;
		s_recoilControlMisalignmentX = -0.10;
		s_recoilControlMisalignmentY = -0.06;
		s_recoilControlKick = 0.04;
	};

	class R12_Base: Shotgun_Base
	{
		s_recoilControlStabilityX = 0.22;
		s_recoilControlStabilityY = 0.18;
		s_recoilControlMisalignmentX = -0.06;
		s_recoilControlMisalignmentY = -0.04;
		s_recoilControlKick = 0.08;
	};

	class Izh18Shotgun_Base: Shotgun_Base
	{
		s_recoilControlStabilityX = 0.14;
		s_recoilControlStabilityY = 0.12;
		s_recoilControlMisalignmentX = -0.14;
		s_recoilControlMisalignmentY = -0.08;
		s_recoilControlKick = 0.02;
	};

	class SawedoffIzh18Shotgun: Izh18Shotgun_Base
	{
		s_recoilControlStabilityX = 0.04;
		s_recoilControlStabilityY = 0.03;
		s_recoilControlMisalignmentX = -0.30;
		s_recoilControlMisalignmentY = -0.20;
		s_recoilControlKick = -0.16;
	};

	class Izh43Shotgun_Base: Shotgun_Base
	{
		s_recoilControlStabilityX = 0.15;
		s_recoilControlStabilityY = 0.13;
		s_recoilControlMisalignmentX = -0.10;
		s_recoilControlMisalignmentY = -0.06;
		s_recoilControlKick = 0.03;
	};

	class SawedoffIzh43Shotgun: Izh43Shotgun_Base
	{
		s_recoilControlStabilityX = 0.02;
		s_recoilControlStabilityY = 0.02;
		s_recoilControlMisalignmentX = -0.38;
		s_recoilControlMisalignmentY = -0.28;
		s_recoilControlKick = -0.18;
	};
};
