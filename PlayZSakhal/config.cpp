class CfgPatches
{
	class PlayZSakhal
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Navigation",
			"DZ_Surfaces_Sakhal",
			"PlayZCore"
		};
	};
};

class CfgMods
{
	class PlayZSakhal
	{
		dir = "PlayZSakhal";
		hideName = 1;
		hidePicture = 1;
		name = "PlayZ Sakhal";
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
					"PlayZ_Client/PlayZSakhal/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZSakhal/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"PlayZ_Client/PlayZSakhal/scripts/5_Mission"
				};
			};
		};
	};
};

class CfgWorlds
{
	class DefaultWorld;
	class CAWorld: DefaultWorld
	{
		class Clutter
		{
			class BrownGrass_Tall
			{
				noSatColor = 1;
			};
			class BrownGrass_Tall2
			{
				noSatColor = 1;
			};
			class BrownGrass_Lump
			{
				noSatColor = 1;
			};
			class BrownGrass
			{
				noSatColor = 1;
			};
			class BrownGrass_Flat
			{
				noSatColor = 1;
			};
			class DryThistle
			{
				noSatColor = 1;
			};
			class GreenGrass_Tall
			{
				noSatColor = 1;
			};
			class GreenGrass_Tall2
			{
				noSatColor = 1;
			};
			class BirchLeaves
			{
				noSatColor = 1;
			};
			class BirchLeaves_Sparse
			{
				noSatColor = 1;
			};
			class Twigs1
			{
				noSatColor = 1;
			};
			class Twigs2
			{
				noSatColor = 1;
			};
			class PiceaCluster
			{
				noSatColor = 1;
			};
			class PiceaCones
			{
				noSatColor = 1;
			};
			class Stones
			{
				noSatColor = 1;
			};
			class Stones_small
			{
				noSatColor = 1;
			};
			class VolcanicStones_Red
			{
				noSatColor = 1;
			};
			class VolcanicStones_Yellow
			{
				noSatColor = 1;
			};
		};
	};
	class sakhal: CAWorld
	{
		mapTextureClosed = "dz/worlds/sakhal/data/map_folded_sakhal_co.paa";
		mapTextureOpened = "PlayZSakhal/DZ/worlds/sakhal/data/map_unfolded_sakhal_co.paa";
		mapTextureLegend = "dz/worlds/sakhal/data/map_legend_sakhal_co.paa";
	};
};
