class CfgPatches
{
	class PlayZAsmond_headgear
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters_Headgear",
			"PlayZAsmond",
			"AsmondClothing",
		};
	};
};

class CfgVehicles
{
	class BallisticHelmet_ColorBase;
	class Bandana_ColorBase;
	class BaseballCap_ColorBase;
	class BeanieHat_ColorBase;
	class BoonieHat_ColorBase;
	class BudenovkaHat_ColorBase;
	class Chainmail_Coif;
	class CowboyHat_ColorBase;
	class GorkaHelmet;
	class GreatHelm;
	class MedicalScrubsHat_ColorBase;
	class Mich2001Helmet;
	class MilitaryBeret_ColorBase;
	class NBCHoodBase;
	class NorseHelm;
	class OKZKCap_ColorBase;
	class OfficerHat;
	class PetushokHat_ColorBase;
	class PrisonerCap;
	class RadarCap_ColorBase;
	class Shemag_ColorBase;
	class SherpaHat_ColorBase;
	class SnowstormUshanka_ColorBase;
	class Ssh68Helmet;
	class TankerHelmet;
	class Ushanka_ColorBase;
	class WinterCoif_ColorBase;

	class Asmond_BaseballCap_GreyWhite;
	class BaseballCap_GreyWhite: Asmond_BaseballCap_GreyWhite { scope=2; };

	class Asmond_BaseballCap_Woodland;
	class BaseballCap_Woodland: Asmond_BaseballCap_Woodland { scope=2; };

	class Asmond_BaseballCap_ACUCamoPatch;
	class BaseballCap_ACUCamoPatch: Asmond_BaseballCap_ACUCamoPatch
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\BaseballCapII.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_ACUCamoPatch.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_ACUCamoPatch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_ACUCamoPatch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_ACUCamoPatch_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BaseballCap_BlackBeige;
	class BaseballCap_BlackBeige: Asmond_BaseballCap_BlackBeige { scope=2; };

	class Asmond_BaseballCap_BlackWhitePatch;
	class BaseballCap_BlackWhitePatch: Asmond_BaseballCap_BlackWhitePatch
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\BaseballCapII.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_BlackWhitePatch.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_BlackWhitePatch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_BlackWhitePatch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_BlackWhitePatch_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BaseballCap_BlueWhite;
	class BaseballCap_BlueWhite: Asmond_BaseballCap_BlueWhite { scope=2; };

	class Asmond_BaseballCap_BrownOAT;
	class BaseballCap_BrownOAT: Asmond_BaseballCap_BrownOAT { scope=2; };

	class Asmond_BaseballCap_WZ93;
	class BaseballCap_WZ93: Asmond_BaseballCap_WZ93
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\BaseballCapII.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_SmallFlag.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_SmallFlag_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_SmallFlag_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_SmallFlag_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BaseballCap_DesertCamo;
	class BaseballCap_DesertCamo: Asmond_BaseballCap_DesertCamo { scope=2; };

	class Asmond_BaseballCap_EMRCamoPatch;
	class BaseballCap_EMRCamoPatch: Asmond_BaseballCap_EMRCamoPatch
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\BaseballCapII.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_EMRCamoPatch.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_EMRCamoPatch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_EMRCamoPatch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_EMRCamoPatch_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BaseballCap_GreenWhitePatch;
	class BaseballCap_GreenWhitePatch: Asmond_BaseballCap_GreenWhitePatch
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\BaseballCapII.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_GreenWhitePatch.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_GreenWhitePatch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_GreenWhitePatch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_GreenWhitePatch_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BaseballCap_MulticamPatch;
	class BaseballCap_MulticamPatch: Asmond_BaseballCap_MulticamPatch
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\BaseballCapII.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_EMRCamoPatch.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_EMRCamoPatch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_EMRCamoPatch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_EMRCamoPatch_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BaseballCap_MulticamDarkPatch;
	class BaseballCap_MulticamDarkPatch: Asmond_BaseballCap_MulticamDarkPatch
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\BaseballCapII.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_MulticamDarkPatch.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_MulticamDarkPatch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_MulticamDarkPatch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_MulticamDarkPatch_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BaseballCap_RedWhite;
	class BaseballCap_RedWhite: Asmond_BaseballCap_RedWhite { scope=2; };

	class Asmond_BaseballCap_TTSKO;
	class BaseballCap_TTSKO: Asmond_BaseballCap_TTSKO
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\BaseballCapII.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_SmallFlag.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_SmallFlag_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_SmallFlag_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\BaseballCap\Data\Asmond_BaseballCap_SmallFlag_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BeanieHat_White;
	class BeanieHat_White: Asmond_BeanieHat_White { scope=2; };

	class Asmond_BeanieHat_M05;
	class BeanieHat_M05: Asmond_BeanieHat_M05 { scope=2; };

	class Asmond_BeanieHat_Stalker;
	class BeanieHat_Stalker: Asmond_BeanieHat_Stalker { scope=2; };

	class Asmond_BeanieHat_Orange;
	class BeanieHat_Orange: Asmond_BeanieHat_Orange { scope=2; };

	class Asmond_BeanieHat_EMR;
	class BeanieHat_EMR: Asmond_BeanieHat_EMR { scope=2; };

	class Asmond_BeanieHat_Brown;
	class BeanieHat_Brown_2: Asmond_BeanieHat_Brown { scope=2; };

	class Asmond_BeanieHat_Olive;
	class BeanieHat_Olive: Asmond_BeanieHat_Olive { scope=2; };

	class Asmond_BeanieHat_BDU;
	class BeanieHat_BDU: Asmond_BeanieHat_BDU { scope=2; };

	class Asmond_BeanieHat_Hunter;
	class BeanieHat_Hunter: Asmond_BeanieHat_Hunter { scope=2; };

	class Asmond_BeanieHat_Winter;
	class BeanieHat_Winter: Asmond_BeanieHat_Winter { scope=2; };

	class Asmond_BoonieHat_M05;
	class BoonieHat_M05: Asmond_BoonieHat_M05 { scope=2; };

	class Asmond_BoonieHat_FullAutumn;
	class BoonieHat_FullAutumn: Asmond_BoonieHat_FullAutumn { scope=2; };

	class Asmond_BoonieHat_TropenTarn;
	class BoonieHat_TropenTarn: Asmond_BoonieHat_TropenTarn { scope=2; };

	class Asmond_BoonieHat_BDU;
	class BoonieHat_BDU: Asmond_BoonieHat_BDU { scope=2; };

	class Asmond_BoonieHat_Woodland;
	class BoonieHat_Woodland: Asmond_BoonieHat_Woodland { scope=2; };

	class Asmond_BoonieHat_WZ93;
	class BoonieHat_WZ93: Asmond_BoonieHat_WZ93 { scope=2; };

	class Asmond_BoonieHat_Partizan;
	class BoonieHat_Partizan: Asmond_BoonieHat_Partizan { scope=2; };

	class Asmond_BoonieHat_FleckTarn;
	class BoonieHat_FleckTarn: Asmond_BoonieHat_FleckTarn { scope=2; };

	class Asmond_BoonieHat_Berezka;
	class BoonieHat_Berezka: Asmond_BoonieHat_Berezka { scope=2; };

	class Asmond_BoonieHat_Hunter;
	class BoonieHat_Hunter: Asmond_BoonieHat_Hunter { scope=2; };

	class Asmond_BoonieHat_Winter;
	class BoonieHat_Winter_2: Asmond_BoonieHat_Winter { scope=2; };

	class Asmond_BoonieHat_Desert;
	class BoonieHat_Desert: Asmond_BoonieHat_Desert { scope=2; };

	class Asmond_BudenovkaHat_Brown;
	class BudenovkaHat_Brown: Asmond_BudenovkaHat_Brown { scope=2; };

	class Asmond_BudenovkaHat_Green;
	class BudenovkaHat_Green: Asmond_BudenovkaHat_Green { scope=2; };

	class Asmond_BudenovkaHat_Grey;
	class BudenovkaHat_Grey: Asmond_BudenovkaHat_Grey { scope=2; };

	class Asmond_CowboyHat_Livonia;
	class CowboyHat_Livonia: Asmond_CowboyHat_Livonia { scope=2; };

	class Asmond_CowboyHat_Blue;
	class CowboyHat_Blue: Asmond_CowboyHat_Blue { scope=2; };

	class Asmond_CowboyHat_White;
	class CowboyHat_White: Asmond_CowboyHat_White { scope=2; };

	class Asmond_CowboyHat_Grey;
	class CowboyHat_Grey: Asmond_CowboyHat_Grey { scope=2; };

	class Asmond_MedicalScrubsHat_Black;
	class MedicalScrubsHat_Black: Asmond_MedicalScrubsHat_Black { scope=2; };

	class Asmond_MedicalScrubsHat_Blue;
	class MedicalScrubsHat_Blue_2: Asmond_MedicalScrubsHat_Blue { scope=2; };

	class Asmond_MedicalScrubsHat_Red;
	class MedicalScrubsHat_Red: Asmond_MedicalScrubsHat_Red { scope=2; };

	class Asmond_MilitaryCap_Base;
	class MilitaryCap_Base: Asmond_MilitaryCap_Base
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 50;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\prison_cap.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Plane.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Plane_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Plane_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Plane_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitaryCap_VSRFlora;
	class MilitaryCap_VSRFlora: Asmond_MilitaryCap_VSRFlora
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 50;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\prison_cap.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitaryCap_Tiger;
	class MilitaryCap_Tiger: Asmond_MilitaryCap_Tiger
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 50;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\prison_cap.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitaryCap_Orel;
	class MilitaryCap_Orel: Asmond_MilitaryCap_Orel
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 50;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\prison_cap.rvmat"}},{0.7,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon.rvmat"}},{0.5,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon_Damage.rvmat"}},{0,{"AsmondClothing\Data\Hats\MilitaryCap\Data\Asmond_MilitaryCap_Ribbon_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitaryCap_Flecktarn;
	class MilitaryCap_Flecktarn: Asmond_MilitaryCap_Flecktarn { scope=2; };

	class Asmond_MilitaryCap_BDU;
	class MilitaryCap_BDU: Asmond_MilitaryCap_BDU { scope=2; };

	class Asmond_MilitaryCap_TTSKO;
	class MilitaryCap_TTSKO: Asmond_MilitaryCap_TTSKO { scope=2; };

	class Asmond_MilitaryCap_Tan;
	class MilitaryCap_Tan: Asmond_MilitaryCap_Tan { scope=2; };

	class Asmond_MilitaryCap_Grey;
	class MilitaryCap_Grey: Asmond_MilitaryCap_Grey { scope=2; };

	class Asmond_MilitaryCap_TropenTarn;
	class MilitaryCap_TropenTarn: Asmond_MilitaryCap_TropenTarn { scope=2; };

	class Asmond_OfficerHat_Gulag;
	class OfficerHat_Gulag: Asmond_OfficerHat_Gulag { scope=2; };

	class Asmond_OfficerHat_Livonia;
	class OfficerHat_Livonia: Asmond_OfficerHat_Livonia { scope=2; };

	class Asmond_OKZKCap_Snow;
	class OKZKCap_Snow: Asmond_OKZKCap_Snow { scope=2; };

	class Asmond_OKZKCap_Hunter;
	class OKZKCap_Hunter: Asmond_OKZKCap_Hunter { scope=2; };

	class Asmond_OKZKCap_Brown;
	class OKZKCap_Brown: Asmond_OKZKCap_Brown { scope=2; };

	class Asmond_OKZKCap_Grey;
	class OKZKCap_Grey: Asmond_OKZKCap_Grey { scope=2; };

	class Asmond_OKZKCap_TTSKO;
	class OKZKCap_TTSKO: Asmond_OKZKCap_TTSKO { scope=2; };

	class Asmond_OKZKCap_Winter;
	class OKZKCap_Winter: Asmond_OKZKCap_Winter { scope=2; };

	class Asmond_PetushokHat_Chernarus;
	class PetushokHat_Chernarus: Asmond_PetushokHat_Chernarus { scope=2; };

	class Asmond_PetushokHat_Argentina;
	class PetushokHat_Argentina: Asmond_PetushokHat_Argentina { scope=2; };

	class Asmond_PetushokHat_Red;
	class PetushokHat_Red: Asmond_PetushokHat_Red { scope=2; };

	class Asmond_PetushokHat_Brown;
	class PetushokHat_Brown: Asmond_PetushokHat_Brown { scope=2; };

	class Asmond_PetushokHat_Blue;
	class PetushokHat_Blue: Asmond_PetushokHat_Blue { scope=2; };

	class Asmond_PetushokHat_CCCP;
	class PetushokHat_CCCP: Asmond_PetushokHat_CCCP { scope=2; };

	class Asmond_PetushokHat_Sport;
	class PetushokHat_Sport: Asmond_PetushokHat_Sport { scope=2; };

	class Asmond_PetushokHat_URSS;
	class PetushokHat_URSS: Asmond_PetushokHat_URSS { scope=2; };

	class Asmond_PrisonerCap_Livonia;
	class PrisonerCap_Livonia: Asmond_PrisonerCap_Livonia { scope=2; };

	class Asmond_RadarCap_Beige;
	class RadarCap_Beige: Asmond_RadarCap_Beige { scope=2; };

	class Asmond_RadarCap_BrownGreen;
	class RadarCap_BrownGreen: Asmond_RadarCap_BrownGreen { scope=2; };

	class Asmond_RadarCap_CCCP;
	class RadarCap_CCCP: Asmond_RadarCap_CCCP { scope=2; };

	class Asmond_RadarCap_Grey;
	class RadarCap_Grey: Asmond_RadarCap_Grey { scope=2; };

	class Asmond_RadarCap_Hunter;
	class RadarCap_Hunter: Asmond_RadarCap_Hunter { scope=2; };

	class Asmond_RadarCap_Orange;
	class RadarCap_Orange: Asmond_RadarCap_Orange { scope=2; };

	class Asmond_RadarCap_Red;
	class RadarCap_Red_2: Asmond_RadarCap_Red { scope=2; };

	class Asmond_RadarCap_TTSKO;
	class RadarCap_TTSKO: Asmond_RadarCap_TTSKO { scope=2; };

	class Asmond_RadarCap_White;
	class RadarCap_White: Asmond_RadarCap_White { scope=2; };

	class Asmond_RadarCap_Winter;
	class RadarCap_Winter: Asmond_RadarCap_Winter { scope=2; };

	class Asmond_SherpaHat_Aymara;
	class SherpaHat_Aymara: Asmond_SherpaHat_Aymara { scope=2; };

	class Asmond_SherpaHat_Coya;
	class SherpaHat_Coya: Asmond_SherpaHat_Coya { scope=2; };

	class Asmond_SherpaHat_Orange;
	class SherpaHat_Orange: Asmond_SherpaHat_Orange { scope=2; };

	class Asmond_SnowstormUshanka_Dumpgrah;
	class SnowstormUshanka_Dumpgrah: Asmond_SnowstormUshanka_Dumpgrah { scope=2; };

	class Asmond_SnowstormUshanka_Orange;
	class SnowstormUshanka_Orange: Asmond_SnowstormUshanka_Orange { scope=2; };

	class Asmond_SnowstormUshanka_Black;
	class SnowstormUshanka_Black: Asmond_SnowstormUshanka_Black { scope=2; };

	class Asmond_SnowstormUshanka_Red;
	class SnowstormUshanka_Red: Asmond_SnowstormUshanka_Red { scope=2; };

	class Asmond_SnowstormUshanka_Winter;
	class SnowstormUshanka_Winter: Asmond_SnowstormUshanka_Winter { scope=2; };

	class Asmond_TankerHelmet_Snow;
	class TankerHelmet_Snow: Asmond_TankerHelmet_Snow { scope=2; };

	class Asmond_TankerHelmet_Green;
	class TankerHelmet_Green: Asmond_TankerHelmet_Green { scope=2; };

	class Asmond_TankerHelmet_Brown;
	class TankerHelmet_Brown: Asmond_TankerHelmet_Brown { scope=2; };

	class Asmond_TankerHelmet_Winter;
	class TankerHelmet_Winter: Asmond_TankerHelmet_Winter { scope=2; };

	class Asmond_Ushanka_Beige;
	class Ushanka_Beige: Asmond_Ushanka_Beige { scope=2; };

	class Asmond_Ushanka_Blue;
	class Ushanka_Blue_2: Asmond_Ushanka_Blue { scope=2; };

	class Asmond_Ushanka_Brown;
	class Ushanka_Brown: Asmond_Ushanka_Brown { scope=2; };

	class Asmond_Ushanka_Hunter;
	class Ushanka_Hunter: Asmond_Ushanka_Hunter { scope=2; };

	class Asmond_Ushanka_Red;
	class Ushanka_Red: Asmond_Ushanka_Red { scope=2; };

	class Asmond_Ushanka_Winter;
	class Ushanka_Winter: Asmond_Ushanka_Winter { scope=2; };

	class Asmond_Ushanka_TTSKO;
	class Ushanka_TTSKO: Asmond_Ushanka_TTSKO { scope=2; };

	class Asmond_Ushanka_Partizan;
	class Ushanka_Partizan: Asmond_Ushanka_Partizan { scope=2; };

	class Asmond_WinterCoif_Orange;
	class WinterCoif_Orange: Asmond_WinterCoif_Orange { scope=2; };

	class Asmond_WinterCoif_Dark;
	class WinterCoif_Dark: Asmond_WinterCoif_Dark { scope=2; };

	class Asmond_BallisticHelmet_ACU;
	class BallisticHelmet_ACU: Asmond_BallisticHelmet_ACU { scope=2; };

	class Asmond_BallisticHelmet_EMR;
	class BallisticHelmet_EMR: Asmond_BallisticHelmet_EMR { scope=2; };

	class Asmond_BallisticHelmet_AAN;
	class BallisticHelmet_AAN: Asmond_BallisticHelmet_AAN { scope=2; };

	class Asmond_BallisticHelmet_Tan;
	class BallisticHelmet_Tan: Asmond_BallisticHelmet_Tan { scope=2; };

	class Asmond_BallisticHelmet_Woodland;
	class BallisticHelmet_Woodland_2: Asmond_BallisticHelmet_Woodland { scope=2; };

	class Asmond_BallisticHelmet_Desert;
	class BallisticHelmet_Desert_2: Asmond_BallisticHelmet_Desert { scope=2; };

	class Asmond_BallisticHelmet_Police;
	class BallisticHelmet_Police: Asmond_BallisticHelmet_Police { scope=2; };

	class Asmond_BallisticHelmet_Grey;
	class BallisticHelmet_Grey: Asmond_BallisticHelmet_Grey { scope=2; };

	class Asmond_BallisticHelmet_Press;
	class BallisticHelmet_Press: Asmond_BallisticHelmet_Press { scope=2; };

	class Asmond_BallisticHelmet_White;
	class BallisticHelmet_White: Asmond_BallisticHelmet_White { scope=2; };

	class Asmond_BallisticHelmet_UN;
	class BallisticHelmet_UN_2: Asmond_BallisticHelmet_UN { scope=2; };

	class Asmond_BallisticHelmet_UNA;
	class BallisticHelmet_UNA: Asmond_BallisticHelmet_UNA { scope=2; };

	class Asmond_Bandana_Snow;
	class Bandana_Snow: Asmond_Bandana_Snow { scope=2; };

	class Asmond_Bandana_ACU;
	class Bandana_ACU: Asmond_Bandana_ACU { scope=2; };

	class Asmond_Bandana_OMK;
	class Bandana_OMK: Asmond_Bandana_OMK { scope=2; };

	class Asmond_Bandana_Woodland;
	class Bandana_Woodland: Asmond_Bandana_Woodland { scope=2; };

	class Asmond_Bandana_BDU;
	class Bandana_BDU: Asmond_Bandana_BDU { scope=2; };

	class Asmond_Bandana_Hunter;
	class Bandana_Hunter: Asmond_Bandana_Hunter { scope=2; };

	class Asmond_Bandana_PlaneBlack;
	class Bandana_PlaneBlack: Asmond_Bandana_PlaneBlack { scope=2; };

	class Asmond_Bandana_PlaneBlue;
	class Bandana_PlaneBlue: Asmond_Bandana_PlaneBlue { scope=2; };

	class Asmond_Bandana_PlaneBrown;
	class Bandana_PlaneBrown: Asmond_Bandana_PlaneBrown { scope=2; };

	class Asmond_Bandana_PlaneGrey;
	class Bandana_PlaneGrey: Asmond_Bandana_PlaneGrey { scope=2; };

	class Asmond_Bandana_PlaneRed;
	class Bandana_PlaneRed: Asmond_Bandana_PlaneRed { scope=2; };

	class Asmond_Bandana_EMR;
	class Bandana_EMR: Asmond_Bandana_EMR { scope=2; };

	class Asmond_Bandana_SquareGreen;
	class Bandana_SquareGreen: Asmond_Bandana_SquareGreen { scope=2; };

	class Asmond_Bandana_SquareRed;
	class Bandana_SquareRed: Asmond_Bandana_SquareRed { scope=2; };

	class Asmond_Bandana_SquareBlue;
	class Bandana_SquareBlue: Asmond_Bandana_SquareBlue { scope=2; };

	class Asmond_Bandana_SquareWhite;
	class Bandana_SquareWhite: Asmond_Bandana_SquareWhite { scope=2; };

	class Asmond_Bandana_Winter;
	class Bandana_Winter: Asmond_Bandana_Winter { scope=2; };

	class Asmond_Bandana_Desert;
	class Bandana_Desert: Asmond_Bandana_Desert { scope=2; };

	class Asmond_CamoHelmet_Base;
	class CamoHelmet_Base: Asmond_CamoHelmet_Base { scope=2; };

	class Asmond_CamoHelmet_Black;
	class CamoHelmet_Black: Asmond_CamoHelmet_Black { scope=2; };

	class Asmond_CamoHelmet_Arctic;
	class CamoHelmet_Arctic: Asmond_CamoHelmet_Arctic { scope=2; };

	class Asmond_CamoHelmet_VSR93;
	class CamoHelmet_VSR93: Asmond_CamoHelmet_VSR93 { scope=2; };

	class Asmond_CamoHelmet_TropenTarn;
	class CamoHelmet_TropenTarn: Asmond_CamoHelmet_TropenTarn { scope=2; };

	class Asmond_CamoHelmet_MountainFlora;
	class CamoHelmet_MountainFlora: Asmond_CamoHelmet_MountainFlora { scope=2; };

	class Asmond_CamoHelmet_VSRFlora;
	class CamoHelmet_VSRFlora: Asmond_CamoHelmet_VSRFlora { scope=2; };

	class Asmond_CamoHelmet_ACU;
	class CamoHelmet_ACU: Asmond_CamoHelmet_ACU { scope=2; };

	class Asmond_CamoHelmet_Snow;
	class CamoHelmet_Snow: Asmond_CamoHelmet_Snow { scope=2; };

	class Asmond_CamoHelmet_WZ93;
	class CamoHelmet_WZ93: Asmond_CamoHelmet_WZ93 { scope=2; };

	class Asmond_CamoHelmet_BDU;
	class CamoHelmet_BDU: Asmond_CamoHelmet_BDU { scope=2; };

	class Asmond_CamoHelmet_OMK;
	class CamoHelmet_OMK: Asmond_CamoHelmet_OMK { scope=2; };

	class Asmond_CamoHelmet_EMR;
	class CamoHelmet_EMR: Asmond_CamoHelmet_EMR { scope=2; };

	class Asmond_CamoHelmet_Police;
	class CamoHelmet_Police: Asmond_CamoHelmet_Police { scope=2; };

	class Asmond_CamoHelmet_Berezka;
	class CamoHelmet_Berezka: Asmond_CamoHelmet_Berezka { scope=2; };

	class Asmond_CamoHelmet_FullGrey;
	class CamoHelmet_FullGrey: Asmond_CamoHelmet_FullGrey { scope=2; };

	class Asmond_CamoHelmet_TTSKO;
	class CamoHelmet_TTSKO: Asmond_CamoHelmet_TTSKO { scope=2; };

	class Asmond_CamoHelmet_UN;
	class CamoHelmet_UN: Asmond_CamoHelmet_UN { scope=2; };

	class Asmond_CamoHelmet_UNA;
	class CamoHelmet_UNA: Asmond_CamoHelmet_UNA { scope=2; };

	class Asmond_Chainmail_Coif_Rebels;
	class Chainmail_Coif_Rebels: Asmond_Chainmail_Coif_Rebels { scope=2; };

	class Asmond_Chainmail_Coif_King;
	class Chainmail_Coif_King: Asmond_Chainmail_Coif_King { scope=2; };

	class Asmond_GorkaHelmet_EMR;
	class GorkaHelmet_EMR: Asmond_GorkaHelmet_EMR { scope=2; };

	class Asmond_GorkaHelmet_Tan;
	class GorkaHelmet_Tan: Asmond_GorkaHelmet_Tan { scope=2; };

	class Asmond_GorkaHelmet_Police;
	class GorkaHelmet_Police: Asmond_GorkaHelmet_Police { scope=2; };

	class Asmond_GorkaHelmet_Grey;
	class GorkaHelmet_Grey: Asmond_GorkaHelmet_Grey { scope=2; };

	class Asmond_GorkaHelmet_White;
	class GorkaHelmet_White: Asmond_GorkaHelmet_White { scope=2; };

	class Asmond_GorkaHelmet_Winter;
	class GorkaHelmet_Winter: Asmond_GorkaHelmet_Winter { scope=2; };

	class Asmond_GreatHelm_Rebels;
	class GreatHelm_Rebels: Asmond_GreatHelm_Rebels { scope=2; };

	class Asmond_GreatHelm_King;
	class GreatHelm_King: Asmond_GreatHelm_King { scope=2; };

	class Asmond_GreatHelm_RebelsRed;
	class GreatHelm_RebelsRed: Asmond_GreatHelm_RebelsRed { scope=2; };

	class Asmond_MilitaryBeret_Grey;
	class MilitaryBeret_Grey: Asmond_MilitaryBeret_Grey { scope=2; };

	class Asmond_MilitaryBeret_Brown;
	class MilitaryBeret_Brown: Asmond_MilitaryBeret_Brown { scope=2; };

	class Asmond_MilitaryBeret_Blue;
	class MilitaryBeret_Blue: Asmond_MilitaryBeret_Blue { scope=2; };

	class Asmond_MilitaryBeret_Comandos;
	class MilitaryBeret_Comandos: Asmond_MilitaryBeret_Comandos { scope=2; };

	class Asmond_MilitaryBeret_Purple;
	class MilitaryBeret_Purple: Asmond_MilitaryBeret_Purple { scope=2; };

	class Asmond_MilitaryBeret_Desert;
	class MilitaryBeret_Desert: Asmond_MilitaryBeret_Desert { scope=2; };

	class Asmond_Mich2001Helmet_Woodland;
	class Mich2001Helmet_Woodland: Asmond_Mich2001Helmet_Woodland { scope=2; };

	class Asmond_Mich2001Helmet_Tan;
	class Mich2001Helmet_Tan: Asmond_Mich2001Helmet_Tan { scope=2; };

	class Asmond_Mich2001Helmet_Grey;
	class Mich2001Helmet_Grey: Asmond_Mich2001Helmet_Grey { scope=2; };

	class Asmond_Mich2001Helmet_Black;
	class Mich2001Helmet_Black: Asmond_Mich2001Helmet_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 80;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\mich2001.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.7,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Black.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.5,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Black_Damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Black_Damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Black_Destruct.rvmat","DZ\characters\headgear\data\mich2001_rail_destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.25;
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
						class Melee
						{
							class Health
							{
								damage = 0.55;
							};
							class Blood
							{
								damage = 0.2;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.55;
							};
							class Blood
							{
								damage = 0.2;
							};
							class Shock
							{
								damage = 0.5;
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

	class Asmond_Mich2001Helmet_Blue;
	class Mich2001Helmet_Blue: Asmond_Mich2001Helmet_Blue { scope=2; };

	class Asmond_Mich2001Helmet_TTSKO;
	class Mich2001Helmet_TTSKO: Asmond_Mich2001Helmet_TTSKO
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 80;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\mich2001.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.7,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Desert.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.5,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Desert_Damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Desert_Damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Desert_Destruct.rvmat","DZ\characters\headgear\data\mich2001_rail_destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.25;
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
						class Melee
						{
							class Health
							{
								damage = 0.55;
							};
							class Blood
							{
								damage = 0.2;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.55;
							};
							class Blood
							{
								damage = 0.2;
							};
							class Shock
							{
								damage = 0.5;
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

	class Asmond_Mich2001Helmet_Winter;
	class Mich2001Helmet_Winter: Asmond_Mich2001Helmet_Winter { scope=2; };

	class Asmond_Mich2001Helmet_White;
	class Mich2001Helmet_White: Asmond_Mich2001Helmet_White { scope=2; };

	class Asmond_Mich2001Helmet_Desert;
	class Mich2001Helmet_Desert: Asmond_Mich2001Helmet_Desert
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 80;
							healthLevels[] = {{1,{"DZ\characters\headgear\data\mich2001.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.7,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Desert.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.5,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Desert_Damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Desert_Damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0,{"AsmondClothing\Data\Headgear\MitchHelmet\Data\Asmond_Mich2001Helmet_Desert_Destruct.rvmat","DZ\characters\headgear\data\mich2001_rail_destruct.rvmat"}}};
						};
					};
					class GlobalArmor
					{
						class Projectile
						{
							class Health
							{
								damage = 0.25;
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
						class Melee
						{
							class Health
							{
								damage = 0.55;
							};
							class Blood
							{
								damage = 0.2;
							};
							class Shock
							{
								damage = 0.5;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.55;
							};
							class Blood
							{
								damage = 0.2;
							};
							class Shock
							{
								damage = 0.5;
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

	class Asmond_NBCHood_Blue;
	class NBCHood_Blue: Asmond_NBCHood_Blue { scope=2; };

	class Asmond_NBCHood_Orange;
	class NBCHood_Orange: Asmond_NBCHood_Orange { scope=2; };

	class Asmond_NBCHood_EMR;
	class NBCHood_EMR: Asmond_NBCHood_EMR { scope=2; };

	class Asmond_NBCHood_Camo;
	class NBCHood_Camo: Asmond_NBCHood_Camo { scope=2; };

	class Asmond_NBCHood_OZK;
	class NBCHood_OZK: Asmond_NBCHood_OZK { scope=2; };

	class Asmond_NBCHood_Grey;
	class NBCHood_Grey: Asmond_NBCHood_Grey { scope=2; };

	class Asmond_NorseHelm_Rebels;
	class NorseHelm_Rebels: Asmond_NorseHelm_Rebels { scope=2; };

	class Asmond_NorseHelm_RebelsRed;
	class NorseHelm_RebelsRed: Asmond_NorseHelm_RebelsRed { scope=2; };

	class Asmond_NorseHelm_King;
	class NorseHelm_King: Asmond_NorseHelm_King { scope=2; };

	class Asmond_Shemag_Snow;
	class Shemag_Snow: Asmond_Shemag_Snow { scope=2; };

	class Asmond_Shemag_Black;
	class Shemag_Black: Asmond_Shemag_Black { scope=2; };

	class Asmond_Shemag_Camo;
	class Shemag_Camo: Asmond_Shemag_Camo { scope=2; };

	class Asmond_Shemag_TacticalBlue;
	class Shemag_TacticalBlue: Asmond_Shemag_TacticalBlue { scope=2; };

	class Asmond_Shemag_Tan;
	class Shemag_Tan: Asmond_Shemag_Tan { scope=2; };

	class Asmond_Shemag_Desert;
	class Shemag_Desert: Asmond_Shemag_Desert { scope=2; };

	class Asmond_Shemag_EMR;
	class Shemag_EMR: Asmond_Shemag_EMR { scope=2; };

	class Asmond_Shemag_Winter;
	class Shemag_Winter: Asmond_Shemag_Winter { scope=2; };

	class Asmond_Shemag_TTSKO;
	class Shemag_TTSKO: Asmond_Shemag_TTSKO { scope=2; };

	class Asmond_Ssh68Helmet_White;
	class Ssh68Helmet_White: Asmond_Ssh68Helmet_White { scope=2; };

	class Asmond_Ssh68Helmet_Soviet;
	class Ssh68Helmet_Soviet: Asmond_Ssh68Helmet_Soviet { scope=2; };

	class Asmond_Ssh68Helmet_Tan;
	class Ssh68Helmet_Tan: Asmond_Ssh68Helmet_Tan { scope=2; };

	class Asmond_Ssh68Helmet_Grey;
	class Ssh68Helmet_Grey: Asmond_Ssh68Helmet_Grey { scope=2; };

};
