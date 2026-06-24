class CfgPatches
{
	class sGunplay_AWS
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"sGunplay","AD_ACOG","AD_B13Mount","AD_DHF5","AD_LeupoldMk4","AD_NFATACR","AD_NFATACR_1_8","AD_Pilad","AD_PVS4","AD_RMR","AD_SpecterDR","AD_XPS34"};
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
		dependencies[] = {};
	};
};
class cfgVehicles
{
	class ItemOptics_Base;
	class AD_ACOG_Base: ItemOptics_Base
	{
		s_pipRadius = 0.35;
		s_pipMagnification = 0.5;
		s_pipBlur = 0.01;
		s_pipChromAber = 0.2;
	};
	class AD_ACOG_RMR_Base: ItemOptics_Base
	{
		s_pipRadius = 0.35;
		s_pipMagnification = 0.5;
		s_pipBlur = 0.01;
		s_pipChromAber = 0.2;
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
		class OpticsInfo
		{
			opticsZoomMin = "0.3926/6";
			opticsZoomMax = "0.3926/6";
			opticsZoomInit = "0.3926/6";
			discretefov[] = {};
		};
	};
	class AD_XPS34_HHS_Base: ItemOptics_Base
	{
		s_pipOffset[] = {0,0.03};
		s_pipLensOffset[] = {0,-0.03};
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
