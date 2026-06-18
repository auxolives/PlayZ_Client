class CfgPatches
{
	class PlayZTerjeRadiation
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"PlayZCore",
			"TerjeCore",
			"TerjeMedicine",
			"TerjeRadiation",
			"TerjeRadiation_Protection",
			"PlayZTerjeCore",
			"PlayZTerjeMedicine"
		};
	};
};
class CfgMods
{
	class PlayZTerjeRadiation
	{
		dir = "PlayZTerjeRadiation";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Terje Radiation";
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
					"PlayZ_Client/PlayZTerjeRadiation/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeRadiation/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZTerjeRadiation/scripts/5_Mission"
				};
			};
		};
	};
};

class CfgTerjeSkills
{
	class SkillsBase;
	class Immunity: SkillsBase
	{
		class Modifiers
		{
			class RadiationResist
			{
				id = "radres";
				enabled = 0;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0radresmod";
				value = 0.01;
			};
			class RadiationRegen
			{
				id = "radregen";
				enabled = 0;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0radregenmod";
				value = 0.025;
			};
		};
		class Perks
		{
			class RadiationResist
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = { 0.10, 0.20, 0.30, 0.40, 0.50 };
				displayName = "#STR_PLAYZ_PERK_IMMUNITY_RADIATION_RESIST_NAME";
				description = "#STR_PLAYZ_PERK_IMMUNITY_RADIATION_RESIST_DESC";
			};
			class RadiationRegen
			{
				enabled = 1;
				stagesCount = 5;
				requiredSkillLevels[] = { 0, 5, 10, 15, 20 };
				requiredPerkPoints[] = { 1, 2, 3, 5, 10 };
				values[] = { 0.10, 0.25, 0.45, 0.70, 1.00 };
				displayName = "#STR_PLAYZ_PERK_IMMUNITY_RADIATION_REGEN_NAME";
				description = "#STR_PLAYZ_PERK_IMMUNITY_RADIATION_REGEN_DESC";
			};
		};
	};
};
