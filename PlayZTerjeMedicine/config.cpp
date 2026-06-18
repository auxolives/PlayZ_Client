class CfgPatches
{
	class PlayZTerjeMedicine
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"PlayZCore",
			"TerjeMedicine",
			"PlayZTerjeCore"
		};
	};
};
class CfgMods
{
	class PlayZTerjeMedicine
	{
		dir = "PlayZTerjeMedicine";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Terje Medicine";
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
					"PlayZ_Client/PlayZTerjeMedicine/scripts/3_game",
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeMedicine/scripts/4_world",
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeMedicine/scripts/5_mission"
				};
			};
		};
	};
};
class CfgTerjeSkills
{
	class Immunity
	{
		id = "immunity";
		enabled = 1;
		displayName = "#STR_TERJESKILL_IMMUNITY_NAME";
		description = "#STR_TERJESKILL_IMMUNITY_DESC";
		icon = "set:TerjeSkills_icon image:ts_immun";
		perkPointsPerLevel = 1;
		levels[] = { 80, 170, 270, 380, 500, 630, 770, 920, 1080, 1250, 1430, 1620, 1820, 2030, 2250, 2480, 2720, 2970, 3230, 3500, 3780, 4070, 4370, 4680, 5000, 5350, 5750, 6150, 6550, 7000 };
		class Modifiers
		{
			class ResistDiseasesModifier
			{
				id = "resdiseasesmod";
				enabled = 1;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0resdiseasesmod";
				value = 0.01;
			};
			class ColdResist
			{
				id = "coldres";
				enabled = 1;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0coldres";
				value = 0.02;
			};
			class PoisonResist
			{
				id = "poisonres";
				enabled = 1;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0poisonres";
				value = 0.02;
			};
			class BiohazardResist
			{
				id = "biohzres";
				enabled = 1;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0biohzres";
				value = 0.025;
			};
			class ResistSepsis
			{
				id = "sepsisres";
				enabled = 1;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0sepsisres";
				value = 0.015;
			};
			class RabiesResist
			{
				id = "rabres";
				enabled = 0;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0rabres";
				value = 1.0;
			};
			class RecoveryShock
			{
				id = "recshock";
				enabled = 0;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0recshock";
				value = 0.045;
			};
			class IronMind
			{
				id = "irnmind";
				enabled = 1;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0irnmind";
				value = 0.025;
			};
		};
		class Perks
		{
			class ColdResist { enabled = 0; };
			class PoisonResist { enabled = 0; };
			class BiohazardResist { enabled = 0; };
			class HematomaRecovery { enabled = 0; };
			class WoundHealing { enabled = 0; };
			class IntoxicResist { enabled = 0; };
			class FastSleep { enabled = 0; };
			class IronMind { enabled = 0; };
			class RecoveryShock
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = { 0.10, 0.25, 0.45, 0.70, 1.0 };
				displayName = "#STR_PLAYZ_PERK_IMMUNITY_RECOVERY_SHOCK_NAME";
				description = "#STR_PLAYZ_PERK_IMMUNITY_RECOVERY_SHOCK_DESC";
			};
			class ImpactResist { enabled = 0; };
			class DurableLeather { enabled = 0; };
			class ResistZmbVirus { enabled = 0; };
			class ResistSepsis { enabled = 0; };
			class FeetWarm { enabled = 0; };
			class SafeDinner { enabled = 0; };
			class QuickHealing { enabled = 0; };
			class BloodRegen { enabled = 0; };
			class ThickBlood { enabled = 0; };
			class RabiesResist
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = { 0.05, 0.1, 0.2, 0.5, 1.0 };
				displayName = "#STR_PLAYZ_PERK_IMMUNITY_RABIES_RESIST_NAME";
				description = "#STR_PLAYZ_PERK_IMMUNITY_RABIES_RESIST_DESC";
			};
			class LowPainTresh
			{
				enabled = 1;
				stagesCount = 1;
				requiredSkillLevels[] = { 20 };
				requiredPerkPoints[] = { 15 };
				values[] = { 0.0 };
				displayName = "#STR_PLAYZ_PERK_IMMUNITY_PAIN_SUPPRESSION_NAME";
				description = "#STR_PLAYZ_PERK_IMMUNITY_PAIN_SUPPRESSION_DESC";
			};
		};
	};
	class Medicine
	{
		id = "med";
		enabled = 1;
		displayName = "#STR_TERJESKILL_MED_NAME";
		description = "#STR_TERJESKILL_MED_DESC";
		icon = "set:TerjeSkills_icon image:ts_med";
		perkPointsPerLevel = 1;
		levels[] = { 80, 170, 270, 380, 500, 630, 770, 920, 1080, 1250, 1430, 1620, 1820, 2030, 2250, 2480, 2720, 2970, 3230, 3500, 3780, 4070, 4370, 4680, 5000, 5350, 5750, 6150, 6550, 7000 };
		class Modifiers
		{
			class CleanlinessSterility
			{
				id = "cleanstr";
				enabled = 0;
				text = "#STR_TERJESKILL_MEDICINE_MOD0cleanstr";
				value = -0.025;
			};
			class MasterDressing
			{
				id = "mastdress";
				enabled = 1;
				text = "#STR_TERJESKILL_MEDICINE_MOD0mastdress";
				value = -0.015;
			};
			class Surgeon
			{
				id = "surgeon";
				enabled = 1;
				text = "#STR_TERJESKILL_MEDICINE_MOD0surgeon";
				value = -0.02;
			};
			class SurgeryStabWound
			{
				id = "surgsw";
				enabled = 1;
				text = "#STR_TERJESKILL_MEDICINE_MOD0surgsw";
				value = 0.03;
			};
			class SurgeryBulletWound
			{
				id = "surgbw";
				enabled = 1;
				text = "#STR_TERJESKILL_MEDICINE_MOD0surgbw";
				value = 0.025;
			};
			class SurgeryInternalWound
			{
				id = "surgint";
				enabled = 1;
				text = "#STR_TERJESKILL_MEDICINE_MOD0surgint";
				value = 0.02;
			};
			class Pharmacologist
			{
				id = "pharmac";
				enabled = 0;
				text = "#STR_TERJESKILL_MEDICINE_MOD0pharmac";
				value = 0.03;
			};
		};
		class Perks
		{
			class SurgeryStabWound { enabled = 0; };
			class SurgeryBulletWound { enabled = 0; };
			class SurgeryInternalWound { enabled = 0; };
			class CleanlinessSterility
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = { -0.05, -0.10, -0.15, -0.35, -0.75 };
				displayName = "#STR_PLAYZ_PERK_MED_CLEANLINESS_NAME";
				description = "#STR_PLAYZ_PERK_MED_CLEANLINESS_DESC";
			};
			class Pharmacologist
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = { 0.10, 0.25, 0.45, 0.70, 1.00 };
				displayName = "#STR_PLAYZ_PERK_MED_PHARMACOLOGIST_NAME";
				description = "#STR_PLAYZ_PERK_MED_PHARMACOLOGIST_DESC";
			};
			class MasterDressing { enabled = 0; };
			class Surgeon { enabled = 0; };
			class BringingLife { enabled = 0; };
			class PillRecognition
			{
				enabled = 1;
				stagesCount = 1;
				requiredSkillLevels[] = { 5 };
				requiredPerkPoints[] = { 10 };
				values[] = { 0.0 };
				displayName = "#STR_PLAYZ_PERK_MED_PILL_RECOGNITION_NAME";
				description = "#STR_PLAYZ_PERK_MED_PILL_RECOGNITION_DESC";
			};
			class AmpouleRecognition
			{
				enabled = 1;
				stagesCount = 1;
				requiredSkillLevels[] = { 10 };
				requiredPerkPoints[] = { 10 };
				values[] = { 0.0 };
				displayName = "#STR_PLAYZ_PERK_MED_AMPOULE_RECOGNITION_NAME";
				description = "#STR_PLAYZ_PERK_MED_AMPOULE_RECOGNITION_DESC";
			};
			class InjectorRecognition
			{
				enabled = 1;
				stagesCount = 1;
				requiredSkillLevels[] = { 20 };
				requiredPerkPoints[] = { 10 };
				values[] = { 0.0 };
				displayName = "#STR_PLAYZ_PERK_MED_INJECTOR_RECOGNITION_NAME";
				description = "#STR_PLAYZ_PERK_MED_INJECTOR_RECOGNITION_DESC";
			};
			class Stethoscope { enabled = 0; };
			class ExpertAntibiotics { enabled = 0; };
			class Anesthesiolog { enabled = 0; };
		};
	};
};