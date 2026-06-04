class CfgPatches
{
	class PlayZAsmond_gloves
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters_Gloves",
			"PlayZAsmond",
			"AsmondClothing",
		};
	};
};

class CfgVehicles
{
	class NBCGloves_ColorBase;
	class OMNOGloves_ColorBase;
	class PaddedGloves_ColorBase;
	class SkiGloves_ColorBase;
	class TacticalGloves_ColorBase;
	class WoolGlovesFingerless_ColorBase;
	class WoolGloves_ColorBase;
	class WorkingGloves_ColorBase;

	class Asmond_NBCGloves_Blue;
	class NBCGlovesBlue: Asmond_NBCGloves_Blue { scope=2; };

	class Asmond_NBCGloves_Orange;
	class NBCGlovesOrange: Asmond_NBCGloves_Orange { scope=2; };

	class Asmond_NBCGloves_EMR;
	class NBCGlovesEMR: Asmond_NBCGloves_EMR { scope=2; };

	class Asmond_NBCGloves_Camo;
	class NBCGlovesCamo: Asmond_NBCGloves_Camo { scope=2; };

	class Asmond_NBCGloves_OZK;
	class NBCGlovesOZK: Asmond_NBCGloves_OZK { scope=2; };

	class Asmond_NBCGloves_Grey;
	class NBCGlovesGray_2: Asmond_NBCGloves_Grey { scope=2; };

	class Asmond_OMNOGloves_Snow;
	class OMNOGloves_Snow: Asmond_OMNOGloves_Snow { scope=2; };

	class Asmond_OMNOGloves_MulticamDark;
	class OMNOGloves_MulticamDark: Asmond_OMNOGloves_MulticamDark { scope=2; };

	class Asmond_OMNOGloves_Green;
	class OMNOGloves_Green: Asmond_OMNOGloves_Green { scope=2; };

	class Asmond_OMNOGloves_Tan;
	class OMNOGloves_Tan: Asmond_OMNOGloves_Tan { scope=2; };

	class Asmond_PaddedGloves_Dark;
	class PaddedGloves_Dark: Asmond_PaddedGloves_Dark { scope=2; };

	class Asmond_PaddedGloves_Black;
	class PaddedGloves_Black: Asmond_PaddedGloves_Black { scope=2; };

	class Asmond_PaddedGloves_Green;
	class PaddedGloves_Green: Asmond_PaddedGloves_Green { scope=2; };

	class Asmond_PaddedGloves_Grey;
	class PaddedGloves_Grey: Asmond_PaddedGloves_Grey { scope=2; };

	class Asmond_SkiGloves_White;
	class SkiGloves_White: Asmond_SkiGloves_White
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\Characters\gloves\data\SkiGloves.rvmat"}},{0.7,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque.rvmat"}},{0.5,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Damage.rvmat"}},{0,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SkiGloves_Orange;
	class SkiGloves_Orange: Asmond_SkiGloves_Orange
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\Characters\gloves\data\SkiGloves.rvmat"}},{0.7,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque.rvmat"}},{0.5,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Damage.rvmat"}},{0,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SkiGloves_Brown;
	class SkiGloves_Brown: Asmond_SkiGloves_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\Characters\gloves\data\SkiGloves.rvmat"}},{0.7,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque.rvmat"}},{0.5,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Damage.rvmat"}},{0,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SkiGloves_90s;
	class SkiGloves_90s_2: Asmond_SkiGloves_90s
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\Characters\gloves\data\SkiGloves.rvmat"}},{0.7,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque.rvmat"}},{0.5,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Damage.rvmat"}},{0,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SkiGloves_Green;
	class SkiGloves_Green: Asmond_SkiGloves_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\Characters\gloves\data\SkiGloves.rvmat"}},{0.7,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque.rvmat"}},{0.5,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Damage.rvmat"}},{0,{"AsmondClothing\Data\Gloves\SkiGloves\Data\Asmond_SkiGloves_Opaque_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TacticalGloves_MulticamDark;
	class TacticalGloves_MulticamDark: Asmond_TacticalGloves_MulticamDark { scope=2; };

	class Asmond_TacticalGloves_White;
	class TacticalGloves_White: Asmond_TacticalGloves_White { scope=2; };

	class Asmond_WoolGloves_90s;
	class WoolGloves_90s: Asmond_WoolGloves_90s { scope=2; };

	class Asmond_WoolGlovesFingerless_90s;
	class WoolGlovesFingerless_90s: Asmond_WoolGlovesFingerless_90s { scope=2; };

	class Asmond_WoolGloves_Arctic;
	class WoolGloves_Arctic: Asmond_WoolGloves_Arctic { scope=2; };

	class Asmond_WoolGlovesFingerless_Arctic;
	class WoolGlovesFingerless_Arctic: Asmond_WoolGlovesFingerless_Arctic { scope=2; };

	class Asmond_WoolGloves_Stalker;
	class WoolGloves_Stalker: Asmond_WoolGloves_Stalker { scope=2; };

	class Asmond_WoolGlovesFingerless_Stalker;
	class WoolGlovesFingerless_Stalker: Asmond_WoolGlovesFingerless_Stalker { scope=2; };

	class Asmond_WoolGloves_Brown;
	class WoolGloves_Brown: Asmond_WoolGloves_Brown { scope=2; };

	class Asmond_WoolGlovesFingerless_Brown;
	class WoolGlovesFingerless_Brown: Asmond_WoolGlovesFingerless_Brown { scope=2; };

	class Asmond_WoolGloves_Blue;
	class WoolGloves_Blue: Asmond_WoolGloves_Blue { scope=2; };

	class Asmond_WoolGlovesFingerless_Blue;
	class WoolGlovesFingerless_Blue: Asmond_WoolGlovesFingerless_Blue { scope=2; };

	class Asmond_WoolGloves_Red;
	class WoolGloves_Red: Asmond_WoolGloves_Red { scope=2; };

	class Asmond_WoolGlovesFingerless_Red;
	class WoolGlovesFingerless_Red: Asmond_WoolGlovesFingerless_Red { scope=2; };

	class Asmond_WoolGloves_Orange;
	class WoolGloves_Orange: Asmond_WoolGloves_Orange { scope=2; };

	class Asmond_WoolGlovesFingerless_Orange;
	class WoolGlovesFingerless_Orange: Asmond_WoolGlovesFingerless_Orange { scope=2; };

	class Asmond_WoolGloves_LightBlue;
	class WoolGloves_LightBlue: Asmond_WoolGloves_LightBlue { scope=2; };

	class Asmond_WoolGlovesFingerless_LightBlue;
	class WoolGlovesFingerless_LightBlue: Asmond_WoolGlovesFingerless_LightBlue { scope=2; };

	class Asmond_WoolGloves_Pink;
	class WoolGloves_Pink: Asmond_WoolGloves_Pink { scope=2; };

	class Asmond_WoolGlovesFingerless_Pink;
	class WoolGlovesFingerless_Pink: Asmond_WoolGlovesFingerless_Pink { scope=2; };

	class Asmond_WoolGloves_Multi;
	class WoolGloves_Multi: Asmond_WoolGloves_Multi { scope=2; };

	class Asmond_WoolGlovesFingerless_Multi;
	class WoolGlovesFingerless_Multi: Asmond_WoolGlovesFingerless_Multi { scope=2; };

	class Asmond_WoolGloves_Beige;
	class WoolGloves_Beige: Asmond_WoolGloves_Beige { scope=2; };

	class Asmond_WoolGlovesFingerless_Beige;
	class WoolGlovesFingerless_Beige: Asmond_WoolGlovesFingerless_Beige { scope=2; };

	class Asmond_WoolGloves_Military;
	class WoolGloves_Military: Asmond_WoolGloves_Military { scope=2; };

	class Asmond_WoolGlovesFingerless_Military;
	class WoolGlovesFingerless_Military: Asmond_WoolGlovesFingerless_Military { scope=2; };

	class Asmond_WorkingGloves_Brown;
	class WorkingGloves_Brown_2: Asmond_WorkingGloves_Brown { scope=2; };

	class Asmond_WorkingGloves_Light;
	class WorkingGloves_Light: Asmond_WorkingGloves_Light { scope=2; };

	class Asmond_WorkingGloves_Green;
	class WorkingGloves_Green: Asmond_WorkingGloves_Green { scope=2; };

	class Asmond_WorkingGloves_Grey;
	class WorkingGloves_Grey: Asmond_WorkingGloves_Grey { scope=2; };

	class Asmond_WorkingGloves_Orange;
	class WorkingGloves_Orange: Asmond_WorkingGloves_Orange { scope=2; };

};
