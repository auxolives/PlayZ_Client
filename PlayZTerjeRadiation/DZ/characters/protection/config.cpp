class CfgPatches
{
	class PlayZTerjeRadiation_VanillaProtection
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"TerjeRadiation_Protection",
			"DZ_Characters_Tops",
			"DZ_Characters_Pants",
			"DZ_Characters_Shoes",
			"DZ_Characters_Gloves",
			"DZ_Characters_Masks",
			"DZ_Characters_Headgear",
			"DZ_Characters_Vests"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	class Inventory_Base;

	// --- PlayZ anchors ---
	class Raincoat_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.62;
		};
	};
	class Wellies_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.47;
		};
	};
	class SurgicalGloves_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.47;
		};
	};
	class SkiGloves_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.41;
		};
	};
	class SurgicalMask: Clothing
	{
		class Protection
		{
			radiation = 0.41;
		};
	};

	// --- Tops: minimal ---
	class TShirt_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class Shirt_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class Sweater_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class Blouse_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class TrackSuitJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class MiniDress_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};

	// --- Tops: low ---
	class Hoodie_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.26;
		};
	};
	class HikingJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class DownJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.26;
		};
	};
	class WoolCoat_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class QuiltedJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.26;
		};
	};
	class BomberJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class TacticalShirt_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class HuntingJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};
	class LeatherJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class M65Jacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.36;
		};
	};
	class GorkaEJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.36;
		};
	};
	class USMCJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.36;
		};
	};
	class TTsKOJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class OMKJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class FirefighterJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class ParamedicJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};
	class MedicalScrubsShirt_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};

	// --- Pants: minimal ---
	class Jeans_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.16;
		};
	};
	class CanvasPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class CanvasPantsMidi_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class SlacksPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.16;
		};
	};
	class TrackSuitPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class LegsCover_Improvised: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};

	// --- Pants: low ---
	class CargoPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.26;
		};
	};
	class HunterPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class JumpsuitPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class GorkaPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class FirefightersPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};
	class ParamedicPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class MedicalScrubsPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class USMCPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};

	// --- Shoes: minimal ---
	class Sneakers_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class JoggingShoes_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class AthleticShoes_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class DressShoes_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};

	// --- Shoes: low ---
	class HikingBoots_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class HikingBootsLow_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class WorkingBoots_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class JungleBoots_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class CombatBoots_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class MilitaryBoots_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class ColdOperationBoots_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.36;
		};
	};

	// --- Gloves: minimal ---
	class WoolGloves_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class WoolGlovesFingerless_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};

	// --- Gloves: low ---
	class LeatherGloves_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class WorkingGloves_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class PaddedGloves_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class TacticalGloves_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class OMNOGloves_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.36;
		};
	};
	class HandsCover_Improvised: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};

	// --- Tops: gap-fill (_ColorBase) ---
	class BushlatPoliceJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.36;
		};
	};
	class JumpsuitJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};
	class WinterMilitaryCoat_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.38;
		};
	};
	class MilitarySweater_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class GulagJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.36;
		};
	};
	class PilotJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};
	class LeatherShirt_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.26;
		};
	};
	class RidersJacket_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class NurseDress_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};

	// --- Tops: gap-fill (standalone) ---
	class BDUJacket: Clothing
	{
		
		class Protection
		{
			radiation = 0.34;
		};
	};
	class PoliceJacket: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class PoliceJacketOrel: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class PrisonUniformJacket: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class LabCoat: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class DenimJacket: Clothing
	{
		class Protection
		{
			radiation = 0.26;
		};
	};
	class TelnyashkaShirt: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class ChernarusSportShirt: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class TorsoCover_Improvised: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};

	// --- Pants: gap-fill ---
	class OMKPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class LeatherPants_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.26;
		};
	};
	class TTSKOPants: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class BDUPants: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class PolicePants: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class PolicePantsOrel: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class PrisonUniformPants: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};

	// --- Shoes: gap-fill ---
	class TraditionalBoots_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};
	class LeatherShoes_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.26;
		};
	};
	class Ballerinas_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class TTSKOBoots: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class FeetCover_Improvised: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};

	// --- Masks: low (bandana/shemagh via script) ---
	class BalaclavaMask_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class Balaclava3Holes_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.26;
		};
	};
	class NioshFaceMask: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class FaceCover_Improvised: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class MouthRag: Clothing
	{
		class Protection
		{
			radiation = 0.26;
		};
	};

	// --- GP5 / Airborne: config 0.95; script fallback 0.95 when filtered. Filter item 0.90. ---
	class GP5GasMask: Clothing
	{
		class Protection
		{
			radiation = 0.95;
		};
	};
	class AirborneMask: Clothing
	{
		class Protection
		{
			radiation = 0.95;
		};
	};
	class GP5GasMask_Filter: Inventory_Base
	{
		class Protection
		{
			radiation = 0.90;
		};
	};

	// --- Vests: low (Body slot) ---
	class LeatherStorageVest_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class HuntingVest: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class PressVest_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class UKAssVest_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};
	class PoliceVest: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class SmershVest: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class HighCapacityVest_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};
	class PlateCarrierVest: Clothing
	{
		class Protection
		{
			radiation = 0.36;
		};
	};
	class ReflexVest: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class Chestplate: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};

	// --- Headgear: minimal ---
	class BeanieHat_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class BaseballCap_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};

	// --- Headgear: low ---
	class ConstructionHelmet_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
	class MotoHelmet_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class BallisticHelmet_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};

	// --- Headgear: gap-fill (_ColorBase) ---
	class BoonieHat_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.20;
		};
	};
	class GhillieHood_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class OKZKCap_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.41;
		};
	};
	class RadarCap_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class MilitaryBeret_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.16;
		};
	};
	class Ushanka_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.16;
		};
	};
	class SnowstormUshanka_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.41;
		};
	};
	class WinterCoif_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.16;
		};
	};
	class BudenovkaHat_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.16;
		};
	};
	class FlatCap_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class ZmijovkaCap_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class SherpaHat_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class LeatherHat_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.26;
		};
	};
	class FirefightersHelmet_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.34;
		};
	};
	class DarkMotoHelmet_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class DirtBikeHelmet_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class MedicalScrubsHat_ColorBase: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};

	// --- Headgear: gap-fill (standalone) ---
	class Mich2001Helmet: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class HeadCover_Improvised: Clothing
	{
		class Protection
		{
			radiation = 0.12;
		};
	};
	class GorkaHelmet: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};
	class Ssh68Helmet: Clothing
	{
		class Protection
		{
			radiation = 0.32;
		};
	};
	class TankerHelmet: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class ZSh3PilotHelmet: Clothing
	{
		class Protection
		{
			radiation = 0.30;
		};
	};
	class WeldingMask: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class OfficerHat: Clothing
	{
		class Protection
		{
			radiation = 0.16;
		};
	};
	class PoliceCap: Clothing
	{
		class Protection
		{
			radiation = 0.16;
		};
	};
	class PilotkaCap: Clothing
	{
		class Protection
		{
			radiation = 0.16;
		};
	};
	class PrisonerCap: Clothing
	{
		class Protection
		{
			radiation = 0.14;
		};
	};
	class BurlapSackCover: Clothing
	{
		class Protection
		{
			radiation = 0.28;
		};
	};
};
