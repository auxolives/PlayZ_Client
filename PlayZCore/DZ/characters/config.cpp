class CfgPatches
{
	class DZ_Characters_PlayZCore
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Tops",
			"DZ_Characters_Pants",
			"DZ_Characters_Gloves",
			"DZ_Characters_Backpacks",
			"DZ_Characters_Headgear",
			"DZ_Characters_Shoes",
			"DZ_Characters_Vests"
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Clothing_Base;
	class Clothing;

	class LeatherSack_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {15.0};
	};
	class LeatherSack_Natural: LeatherSack_ColorBase {};
	class LeatherSack_Black: LeatherSack_ColorBase {};
	class LeatherSack_Beige: LeatherSack_ColorBase {};
	class LeatherSack_Brown: LeatherSack_ColorBase {};

	class LeatherJacket_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		itemsCargoSize[] = {6,4};
	};
	class LeatherJacket_Natural: LeatherJacket_ColorBase {};
	class LeatherJacket_Beige: LeatherJacket_ColorBase {};
	class LeatherJacket_Brown: LeatherJacket_ColorBase {};
	class LeatherJacket_Black: LeatherJacket_ColorBase {};

	class LeatherPants_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {20.0};
		itemsCargoSize[] = {5,4};
	};
	class LeatherPants_Natural: LeatherPants_ColorBase {};
	class LeatherPants_Beige: LeatherPants_ColorBase {};
	class LeatherPants_Brown: LeatherPants_ColorBase {};
	class LeatherPants_Black: LeatherPants_ColorBase {};

	class LeatherHat_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {15.0};
	};
	class LeatherHat_Natural: LeatherHat_ColorBase {};
	class LeatherHat_Beige: LeatherHat_ColorBase {};
	class LeatherHat_Brown: LeatherHat_ColorBase {};
	class LeatherHat_Black: LeatherHat_ColorBase {};

	class LeatherShoes_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {15.0};
	};
	class LeatherShoes_Natural: LeatherShoes_ColorBase {};
	class LeatherShoes_Beige: LeatherShoes_ColorBase {};
	class LeatherShoes_Brown: LeatherShoes_ColorBase {};
	class LeatherShoes_Black: LeatherShoes_ColorBase {};

	class LeatherGloves_ColorBase: Clothing
	{
		repairableWithKits[] = {3};
		repairCosts[] = {15.0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
				};
			};
		};
	};
	class LeatherGloves_Brown: LeatherGloves_ColorBase {};
	class LeatherGloves_Natural: LeatherGloves_ColorBase {};
	class LeatherGloves_Beige: LeatherGloves_ColorBase {};
	class LeatherGloves_Black: LeatherGloves_ColorBase {};

	// Pants cargo (vanilla baseline - tune here)
	class BDUPants: Clothing
	{
		itemsCargoSize[] = {4,4};
	};
	class Breeches_ColorBase: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class CanvasPantsMidi_ColorBase: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class CanvasPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class CargoPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,4};
	};
	class Chainmail_Leggings: Clothing
	{
		itemsCargoSize[] = {4,2};
	};
	class FirefightersPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,4};
	};
	class GorkaPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,4};
	};
	class HunterPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,4};
	};
	class Jeans_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,3};
	};
	class JumpsuitPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,4};
	};
	class LegsCover_Improvised: Clothing
	{
		itemsCargoSize[] = {3,2};
	};
	class MedicalScrubsPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,3};
	};
	class NBCPantsBase: Clothing
	{
		itemsCargoSize[] = {4,4};
	};
	class OMKPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,4};
	};
	class ParamedicPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,3};
	};
	class PolicePants: Clothing
	{
		itemsCargoSize[] = {4,3};
	};
	class PolicePantsOrel: Clothing
	{
		itemsCargoSize[] = {5,3};
	};
	class PrisonUniformPants: Clothing
	{
		itemsCargoSize[] = {4,2};
	};
	class ShortJeans_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,3};
	};
	class Skirt_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,2};
	};
	class SlacksPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,3};
	};
	class TTSKOPants: Clothing
	{
		itemsCargoSize[] = {5,3};
	};
	class TrackSuitPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,3};
	};
	class USMCPants_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,4};
	};

	// Tops cargo (vanilla baseline - tune here)
	class BDUJacket: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class Blouse_ColorBase: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class BomberJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class BushlatPoliceJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,5};
	};
	class Chainmail: Clothing
	{
		itemsCargoSize[] = {4,3};
	};
	class ChernarusSportShirt: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class DenimJacket: Clothing
	{
		itemsCargoSize[] = {5,4};
	};
	class DownJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,4};
	};
	class FirefighterJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class GorkaEJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class GulagJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class HikingJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class Hoodie_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,4};
	};
	class HuntingJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class JumpsuitJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class LabCoat: Clothing
	{
		itemsCargoSize[] = {5,4};
	};
	class LeatherShirt_ColorBase: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class M65Jacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class ManSuit_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,4};
	};
	class MedicalScrubsShirt_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,3};
	};
	class MilitarySweater_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class MiniDress_ColorBase: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class NBCJacketBase: Clothing
	{
		itemsCargoSize[] = {4,4};
	};
	class NurseDress_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,4};
	};
	class OMKJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,5};
	};
	class ParamedicJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,4};
	};
	class PilotJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,4};
	};
	class PoliceJacket: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class PoliceJacketOrel: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class PrisonUniformJacket: Clothing
	{
		itemsCargoSize[] = {5,3};
	};
	class QuiltedJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class Raincoat_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,3};
	};
	class RidersJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class Shirt_ColorBase: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class Sweater_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,4};
	};
	class TShirt_ColorBase: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class TTsKOJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class TacticalShirt_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class TelnyashkaShirt: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class TorsoCover_Improvised: Clothing
	{
		itemsCargoSize[] = {3,3};
	};
	class TrackSuitJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,3};
	};
	class USMCJacket_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,5};
	};
	class WinterMilitaryCoat_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class WomanSuit_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,4};
	};
	class WoolCoat_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,4};
	};

	// Backpacks cargo (vanilla baseline - tune here)
	class AliceBag_ColorBase: Clothing
	{
		itemsCargoSize[] = {8,8};
	};
	class ArmyPouch_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,5};
	};
	class AssaultBag_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,6};
	};
	class Attack2Bag_ColorBase: Clothing
	{
		itemsCargoSize[] = {8,8};
	};
	class CanvasBag_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,5};
	};
	class ChildBag_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class CourierBag: Clothing
	{
		itemsCargoSize[] = {5,6};
	};
	class CoyoteBag_ColorBase: Clothing
	{
		itemsCargoSize[] = {8,7};
	};
	class DryBag_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,7};
	};
	class DrysackBag_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,5};
	};
	class DuffelBagSmall_ColorBase: Clothing
	{
		itemsCargoSize[] = {5,5};
	};
	class FurCourierBag: Clothing
	{
		itemsCargoSize[] = {5,6};
	};
	class FurImprovisedBag: Clothing
	{
		itemsCargoSize[] = {7,5};
	};
	class HuntingBag: Clothing
	{
		itemsCargoSize[] = {7,6};
	};
	class ImprovisedBag: Clothing
	{
		itemsCargoSize[] = {7,5};
	};
	class MountainBag_ColorBase: Clothing
	{
		itemsCargoSize[] = {7,8};
	};
	class SlingBag_ColorBase: Clothing
	{
		itemsCargoSize[] = {4,5};
	};
	class SmershVest: Clothing
	{
		descriptionShort = "#STR_PlayZ_SmershVest_Desc";
	};
	class SmershBag: Clothing
	{
		itemsCargoSize[] = {6,4};
	};
	class TaloonBag_ColorBase: Clothing
	{
		itemsCargoSize[] = {6,5};
	};
	class TortillaBag: Clothing
	{
		itemsCargoSize[] = {7,8};
	};

	class Headtorch_ColorBase;
	class Headtorch_Black: Headtorch_ColorBase
	{
		descriptionShort = "#STR_PlayZ_Headtorch_Black1";
	};
};
