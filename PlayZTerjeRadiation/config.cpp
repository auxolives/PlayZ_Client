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
				id="radres";
				enabled=1;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0radresmod";
				value = 0.01;
			};
			class RadiationRegen
			{
				id="radregen";
				enabled=1;
				text = "#STR_TERJESKILL_IMMUNITY_MOD0radregenmod";
				value = 0.025;
			};
		}
		class Perks
		{
			class RadiationResist { enabled = 0; };
			class RadiationRegen { enabled = 0; };
		};
	};
};
