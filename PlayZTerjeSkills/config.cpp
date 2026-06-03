class CfgPatches
{
	class PlayZTerjeSkills
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"PlayZCore",
			"TerjeCore",
			"TerjeSkills",
			"PlayZTerjeCore"
		};
	};
};
class CfgMods
{
	class PlayZTerjeSkills
	{
		dir = "PlayZTerjeSkills";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Terje Skills";
		credits = "";
		author = "Olivier";
		type = "mod";
		dependencies[] = {
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeSkills/scripts/3_game",
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeSkills/scripts/4_world",
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeSkills/scripts/5_mission"
				};
			};
		};
	};
};
class CfgTerjeSkills
{
	class Athletic
	{
		id = "athlc";
		enabled = 1;
		displayName = "#STR_TERJESKILL_ATHLETIC_NAME";
		description = "#STR_TERJESKILL_ATHLETIC_DESC";
		icon = "set:TerjeSkills_icon image:ts_athletic";
		perkPointsPerLevel = 1;
		levels[] = { 80, 170, 270, 380, 500, 630, 770, 920, 1080, 1250, 1430, 1620, 1820, 2030, 2250, 2480, 2720, 2970, 3230, 3500, 3780, 4070, 4370, 4680, 5000, 5350, 5750, 6150, 6550, 7000 };
		class Modifiers
		{
			class MaxStaminaModifier
			{
				id = "maxstaminamod";
				enabled = 1;
				text = "#STR_TERJESKILL_ATHLETIC_MOD0maxstaminamod";
				value = 0.02;
			};
			class QuickFeet
			{
				id = "quickf";
				enabled = 1;
				text = "#STR_TERJESKILL_ATHLETIC_MOD0quickf";
				value = -0.025;
			};
			class Swimmer
			{
				id = "swimmer";
				enabled = 1;
				text = "#STR_TERJESKILL_ATHLETIC_MOD0swimmer";
				value = 0.02;
			};
			class StairMaster
			{
				id = "ladder";
				enabled = 1;
				text = "#STR_TERJESKILL_ATHLETIC_MOD0ladder";
				value = 0.02;
			};
			class StrongBones
			{
				id = "strbones";
				enabled = 1;
				text = "#STR_TERJESKILL_ATHLETIC_MOD0strbones";
				value = -0.015;
			};
		};
		class Perks
		{
			class QuickFeet { enabled = 0; };
			class Marathoner { enabled = 0; };
			class ProperBreathing
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
				displayName = "#STR_PLAYZ_PERK_ATH_PROPER_BREATHING_NAME";
				description = "#STR_PLAYZ_PERK_ATH_PROPER_BREATHING_DESC";
			};
			class Swimmer { enabled = 0; };
			class StairMaster { enabled = 0; };
			class NoPanting
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = {-0.1, -0.2, -0.4, -0.6, -0.8 };
				displayName = "#STR_PLAYZ_PERK_ATH_NO_PANTING_NAME";
				description = "#STR_PLAYZ_PERK_ATH_NO_PANTING_DESC";
			};
			class Enduring { enabled = 0; };
			class Stuntman
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = {-0.05, -0.1, -0.2, -0.3, -0.5 };
				displayName = "#STR_PLAYZ_PERK_ATH_STUNTMAN_NAME";
				description = "#STR_PLAYZ_PERK_ATH_STUNTMAN_DESC";
			};
			class StrongBones { enabled = 0; };
		};
	};
	class Strength
	{
		id = "strng";
		enabled = 1;
		displayName = "#STR_TERJESKILL_STRENGTH_NAME";
		description = "#STR_TERJESKILL_STRENGTH_DESC";
		icon = "set:TerjeSkills_icon image:ts_strength";
		perkPointsPerLevel = 1;
		levels[] = { 80, 170, 270, 380, 500, 630, 770, 920, 1080, 1250, 1430, 1620, 1820, 2030, 2250, 2480, 2720, 2970, 3230, 3500, 3780, 4070, 4370, 4680, 5000, 5350, 5750, 6150, 6550, 7000 };
		class Modifiers
		{
			class MaxWeightModifier
			{
				id = "maxweightmod";
				enabled = 1;
				text = "#STR_TERJESKILL_STRENGTH_MOD0maxweightmod";
				value = 0.02;
			};
			class MasterOfDefence
			{
				id = "mrdefence";
				enabled = 1;
				text = "#STR_TERJESKILL_STRENGTH_MOD0mrdefence";
				value = -0.02;
			};
			class LightAttacksForce
			{
				id = "lattkforce";
				enabled = 1;
				text = "#STR_TERJESKILL_STRENGTH_MOD0lattkforce";
				value = 0.015;
			};
			class HeavyAttacksForce
			{
				id = "hattkforce";
				enabled = 1;
				text = "#STR_TERJESKILL_STRENGTH_MOD0hattkforce";
				value = 0.01;
			};
		};
		class Perks
		{
			class HeavyWeight
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = { 0.05, 0.1, 0.15, 0.2, 0.25 };
				displayName = "#STR_PLAYZ_PERK_STRNG_HEAVYWEIGHT_NAME";
				description = "#STR_PLAYZ_PERK_STRNG_HEAVYWEIGHT_DESC";
			};
			class Jumper
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = {-0.1, -0.2, -0.3, -0.4, -0.5 };
				displayName = "#STR_PLAYZ_PERK_STRNG_JUMPER_NAME";
				description = "#STR_PLAYZ_PERK_STRNG_JUMPER_DESC";
			};
			class MasterOfDefence { enabled = 0; };
			class MasterOfEvasion { enabled = 0; };
			class LightAttacksSpeed { enabled = 0; };
			class LightAttacksForce { enabled = 0; };
			class HeavyAttacksSpeed { enabled = 0; };
			class HeavyAttacksForce { enabled = 0; };
			class LightweightArmor
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = {-0.05, -0.1, -0.15, -0.2, -0.25 };
				displayName = "#STR_PLAYZ_PERK_STRNG_LTARMOR_NAME";
				description = "#STR_PLAYZ_PERK_STRNG_LTARMOR_DESC";
			};
			class StrongHands { enabled = 0; };
			class MasterStroke { enabled = 0; };
		};
	};
	class Metabolism
	{
		id = "mtblsm";
		enabled = 1;
		displayName = "#STR_TERJESKILL_METABLSM_NAME";
		description = "#STR_TERJESKILL_METABLSM_DESC";
		icon = "set:TerjeSkills_icon image:ts_metablsm";
		perkPointsPerLevel = 1;
		levels[] = { 80, 170, 270, 380, 500, 630, 770, 920, 1080, 1250, 1430, 1620, 1820, 2030, 2250, 2480, 2720, 2970, 3230, 3500, 3780, 4070, 4370, 4680, 5000, 5350, 5750, 6150, 6550, 7000 };
		class Modifiers
		{
			class EnergyConsumptionModifier
			{
				id = "energconsmod";
				enabled = 1;
				text = "#STR_TERJESKILL_METABLSM_MOD0energconsmod";
				value = -0.01;
			};
		};
		class Perks
		{
			class IncreasedCalorie
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
				displayName = "#STR_PLAYZ_PERK_MET_INCREASED_CALORIE_NAME";
				description = "#STR_PLAYZ_PERK_MET_INCREASED_CALORIE_DESC";
			};
			class IncreasedHydration
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
				displayName = "#STR_PLAYZ_PERK_MET_INCREASED_HYDRATION_NAME";
				description = "#STR_PLAYZ_PERK_MET_INCREASED_HYDRATION_DESC";
			};
			class EnergySaving { enabled = 0; };
			class WaterSaving { enabled = 0; };
			class EnergyControl { enabled = 0; };
			class HydrationControl { enabled = 0; };
			class EnregyContainment { enabled = 0; };
			class WaterContainment { enabled = 0; };
			class ResistWater { enabled = 0; };
			class ResistHunger { enabled = 0; };
			class WildMeatLover
			{
				enabled = 1;
				stagesCount = 1;
				requiredSkillLevels[] = { 20 };
				requiredPerkPoints[] = { 15 };
				values[] = { 0.0 };
				displayName = "#STR_PLAYZ_PERK_MET_WILD_MEAT_LOVER_NAME";
				description = "#STR_PLAYZ_PERK_MET_WILD_MEAT_LOVER_DESC";
			};
		};
	};
	class Stealth
	{
		id = "stlth";
		enabled = 1;
		displayName = "#STR_TERJESKILL_STEALCH_NAME";
		description = "#STR_TERJESKILL_STEALCH_DESC";
		icon = "set:TerjeSkills_icon image:ts_stealth";
		perkPointsPerLevel = 1;
		levels[] = { 80, 170, 270, 380, 500, 630, 770, 920, 1080, 1250, 1430, 1620, 1820, 2030, 2250, 2480, 2720, 2970, 3230, 3500, 3780, 4070, 4370, 4680, 5000, 5350, 5750, 6150, 6550, 7000 };
		class Modifiers
		{
			class QuietStep
			{
				id = "qtstep";
				enabled = 1;
				text = "#STR_TERJESKILL_STEALTH_MOD0qtstep";
				value = -0.02;
			};
			class ColdBlooded
			{
				id = "coldbldd";
				enabled = 1;
				text = "#STR_TERJESKILL_STEALTH_MOD0coldbldd";
				value = -0.03;
			};
			class QuietShooter
			{
				id = "qshooter";
				enabled = 1;
				text = "#STR_TERJESKILL_STEALTH_MOD0qshooter";
				value = -0.02;
			};
			class WolfInstinct
			{
				enabled = 0;
			};
			class BearsFriend
			{
				enabled = 0;
			};
		};
		class Perks
		{
			class QuietStep { enabled = 0; };
			class ColdBlooded { enabled = 0; };
			class QuietShooter { enabled = 0; };
			class FittingEquipment { enabled = 0; };
			class InvisibleMan
			{
				enabled = 1;
				stagesCount = 7;
				requiredPerkPoints[] = { 5, 5, 10, 10, 15, 15, 25 };
				requiredSkillLevels[] = { 0, 5, 10, 15, 20, 25, 30 };
				values[] = {-0.1, -0.2, -0.3, -0.4, -0.5, -0.6, -0.7 };
				displayName = "#STR_PLAYZ_PERK_STLTH_INVISIBLEMAN";
				description = "#STR_PLAYZ_PERK_STLTH_INVISIBLEMAN_DES";
			};
			class CatVision { enabled = 0; };
			class WolfInstinct
			{
				enabled = 1;
				stagesCount = 5;
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				values[] = {-0.3, -0.4, -0.5, -0.6, -0.7 };
				displayName = "#STR_PLAYZ_PERK_STLTH_WOLF_INSTINCT_NAME";
				description = "#STR_PLAYZ_PERK_STLTH_WOLF_INSTINCT_DESC";
			};
			class BearsFriend
			{
				enabled = 1;
				stagesCount = 5;
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				values[] = {-0.3, -0.4, -0.5, -0.6, -0.7 };
				displayName = "#STR_PLAYZ_PERK_STLTH_BEARS_FRIEND_NAME";
				description = "#STR_PLAYZ_PERK_STLTH_BEARS_FRIEND_DESC";
			};
			class SilentKiller { enabled = 0; };
			class Ninja { enabled = 0; };
			class ShadowTracker { enabled = 0; };
		};
	};
	class Survival
	{
		id = "surv";
		enabled = 1;
		displayName = "#STR_TERJESKILL_SURVIVAL_NAME";
		description = "#STR_TERJESKILL_SURVIVAL_DESC";
		icon = "set:TerjeSkills_icon image:ts_survival";
		perkPointsPerLevel = 1;
		levels[] = { 80, 170, 270, 380, 500, 630, 770, 920, 1080, 1250, 1430, 1620, 1820, 2030, 2250, 2480, 2720, 2970, 3230, 3500, 3780, 4070, 4370, 4680, 5000, 5350, 5750, 6150, 6550, 7000 };
		class Modifiers
		{
			class ReducedTempModifier
			{
				enabled = 0;
			};
			class ReducedZombDmgModifier
			{
				id = "survzmbmod";
				enabled = 1;
				text = "#STR_TERJESKILL_SURVIVAL_survzmbmod";
				value = -0.01;
			};
			class ReducedFireStartModifier
			{
				id = "survfiremod";
				enabled = 1;
				text = "#STR_TERJESKILL_SURVIVAL_startfire2";
				value = -0.01;
			};
			class StartingFire
			{
				id = "startfire";
				enabled = 1;
				text = "#STR_TERJESKILL_SURVIVAL_startfire";
				value = 0.03;
			};
			class ColdResistance
			{
				id = "coldres";
				enabled = 0;
				text = "#STR_TERJESKILL_SURVIVAL_coldres";
				value = 0.02;
			};
			class MaintainingFire
			{
				id = "maintngfire";
				enabled = 1;
				text = "#STR_TERJESKILL_SURVIVAL_maintngfire";
				value = 0.10;
			};
		};
		class Perks
		{
			class StartingFire { enabled = 0; };
			class ColdResistance { enabled = 0; };
			class RoughFeet
			{
				enabled = 1;
				stagesCount = 5;
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				values[] = {-0.2, -0.4, -0.6, -0.8, -1.0 };
				displayName = "#STR_PLAYZ_PERK_SURV_ROUGH_FEET_NAME";
				description = "#STR_PLAYZ_PERK_SURV_ROUGH_FEET_DESC";
			};
			class RoughHands { enabled = 0; };
			class AncestralTechnologies { enabled = 0; };
			class MaintainingFire { enabled = 0; };
			class DurableEquipment
			{
				enabled = 1;
				stagesCount = 5;
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				values[] = {-0.1, -0.2, -0.4, -0.6, -0.7 };
				displayName = "#STR_PLAYZ_PERK_SURV_DURABLE_EQUIPMENT_NAME";
				description = "#STR_PLAYZ_PERK_SURV_DURABLE_EQUIPMENT_DESC";
			};
			class Bushcraft { enabled = 0; };
			class Expert { enabled = 0; };
			class Stashes
			{
				enabled = 1;
				stagesCount = 1;
				requiredSkillLevels[] = { 20 };
				requiredPerkPoints[] = { 15 };
				values[] = { 0.0 };
				displayName = "#STR_PLAYZ_PERK_SURV_STASHES_NAME";
				description = "#STR_PLAYZ_PERK_SURV_STASHES_DESC";
			};
			class SurvivalInstinct { enabled = 0; };
			class MushroomPremonition { enabled = 0; };
		};
	};
	class Hunting
	{
		id = "hunt";
		enabled = 1;
		displayName = "#STR_TERJESKILL_HUNTING_NAME";
		description = "#STR_TERJESKILL_HUNTING_DESC";
		icon = "set:TerjeSkills_icon image:ts_hunting";
		perkPointsPerLevel = 1;
		levels[] = { 80, 170, 270, 380, 500, 630, 770, 920, 1080, 1250, 1430, 1620, 1820, 2030, 2250, 2480, 2720, 2970, 3230, 3500, 3780, 4070, 4370, 4680, 5000, 5350, 5750, 6150, 6550, 7000 };
		class Modifiers
		{
			class MeatCountModifier
			{
				id = "meatcountmod";
				enabled = 0;
				text = "#STR_TERJESKILL_HUNTING_MOD0MeatCountModifier";
				value = 0.02;
			};
			class MeatHunterModifier
			{
				id = "meathuntmod_plz";
				enabled = 1;
				text = "#STR_PLAYZ_HUNTING_MOD_MEATHUNT_DESC";
				value = 0.035;
			};
			class QuickSkinningModifier
			{
				id = "quickcutmod_plz";
				enabled = 1;
				text = "#STR_PLAYZ_HUNTING_MOD_QUICKCUT_DESC";
				value = -0.025;
			};
			class PeltMasterModifier
			{
				id = "plmastermod_plz";
				enabled = 1;
				text = "#STR_PLAYZ_HUNTING_MOD_PLMASTER_DESC";
				value = 0.033;
			};
		};
		class Perks
		{
			class MeatHunter { enabled = 0; };
			class QuickSkinning { enabled = 0; };
			class MasterKnife { enabled = 0; };
			class TrapExpert { enabled = 0; };
			class PeltMaster { enabled = 0; };
			class ExperiencedHunter { enabled = 0; };
			class KnowledgeAnatomy { enabled = 0; };
			class RemovingRot { enabled = 0; };
			class Pathfinder { enabled = 0; };
		};
	};
	class Fishing
	{
		id = "fish";
		enabled = 1;
		displayName = "#STR_TERJESKILL_FISHING_NAME";
		description = "#STR_TERJESKILL_FISHING_DESC";
		icon = "set:TerjeSkills_icon image:ts_fushing";
		perkPointsPerLevel = 1;
		levels[] = { 80, 170, 270, 380, 500, 630, 770, 920, 1080, 1250, 1430, 1620, 1820, 2030, 2250, 2480, 2720, 2970, 3230, 3500, 3780, 4070, 4370, 4680, 5000, 5350, 5750, 6150, 6550, 7000 };
		class Modifiers
		{
			class CatchFishModifier
			{
				id = "catchmod_plz";
				enabled = 1;
				text = "#STR_PLAYZ_FISHING_MOD_CATCH_DESC";
				value = 0.033;
			};
			class ReliableGearModifier
			{
				id = "reliabgearmod_plz";
				enabled = 1;
				text = "#STR_PLAYZ_FISHING_MOD_RELIABGEAR_DESC";
				value = -0.035;
			};
			class MasterFilletModifier
			{
				id = "masterfmod_plz";
				enabled = 1;
				text = "#STR_PLAYZ_FISHING_MOD_MASTERF_DESC";
				value = 0.035;
			};
		};
		class Perks
		{
			class MasterFillet { enabled = 0; };
			class QuickClean { enabled = 0; };
			class StraightArms { enabled = 0; };
			class MasterTrap { enabled = 0; };
			class SkilledFisherman { enabled = 0; };
			class FishermanLuck { enabled = 0; };
			class ReliableGear { enabled = 0; };
			class WormHunter { enabled = 0; };
			class CraftsMan { enabled = 0; };
			class RemoveRottenFish { enabled = 0; };
		};
	};
};