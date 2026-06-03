class CfgPatches
{
	class PlayZAsmond_belts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters_Belts",
			"PlayZAsmond",
			"AsmondClothing",
		};
	};
};

class CfgVehicles
{
	class CivilianBelt;
	class HipPack_ColorBase;
	class MilitaryBelt;

	class Asmond_CivilianBelt_Brown;
	class CivilianBelt_Brown: Asmond_CivilianBelt_Brown { scope=2; };

	class Asmond_CivilianBelt_Green;
	class CivilianBelt_Green: Asmond_CivilianBelt_Green { scope=2; };

	class Asmond_HipPack_Brown;
	class HipPack_Brown: Asmond_HipPack_Brown { scope=2; };

	class Asmond_HipPack_White;
	class HipPack_White: Asmond_HipPack_White { scope=2; };

	class Asmond_HipPack_Blue;
	class HipPack_Blue: Asmond_HipPack_Blue { scope=2; };

	class Asmond_HipPack_90s;
	class HipPack_90s: Asmond_HipPack_90s { scope=2; };

	class Asmond_HipPack_Soviet;
	class HipPack_Soviet: Asmond_HipPack_Soviet { scope=2; };

	class Asmond_MilitaryBelt_White;
	class MilitaryBelt_White: Asmond_MilitaryBelt_White { scope=2; };

	class Asmond_MilitaryBelt_Tan;
	class MilitaryBelt_Tan: Asmond_MilitaryBelt_Tan { scope=2; };

	class Asmond_MilitaryBelt_Black;
	class MilitaryBelt_Black: Asmond_MilitaryBelt_Black { scope=2; };

};
