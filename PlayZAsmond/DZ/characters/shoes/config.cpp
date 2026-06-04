class CfgPatches
{
	class PlayZAsmond_shoes
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters_Shoes",
			"PlayZAsmond",
			"AsmondClothing",
		};
	};
};

class CfgVehicles
{
	class ColdOperationBoots_ColorBase;
	class CombatBoots_ColorBase;
	class JungleBoots_ColorBase;
	class MilitaryBoots_ColorBase;
	class NBCBootsBase;
	class TraditionalBoots_ColorBase;
	class WorkingBoots_ColorBase;

	class Asmond_ColdOperationBoots_Black;
	class ColdOperationBoots_Black: Asmond_ColdOperationBoots_Black { scope=2; };

	class Asmond_ColdOperationBoots_Brown;
	class ColdOperationBoots_Brown: Asmond_ColdOperationBoots_Brown { scope=2; };

	class Asmond_ColdOperationBoots_M05;
	class ColdOperationBoots_M05: Asmond_ColdOperationBoots_M05 { scope=2; };

	class Asmond_CombatBoots_Black;
	class CombatBoots_Black_2: Asmond_CombatBoots_Black { scope=2; };

	class Asmond_CombatBoots_Beige;
	class CombatBoots_Beige_2: Asmond_CombatBoots_Beige { scope=2; };

	class Asmond_CombatBoots_Arctic;
	class CombatBoots_Arctic: Asmond_CombatBoots_Arctic { scope=2; };

	class Asmond_JungleBoots_White;
	class JungleBoots_White: Asmond_JungleBoots_White { scope=2; };

	class Asmond_JungleBoots_Arctic;
	class JungleBoots_Arctic: Asmond_JungleBoots_Arctic { scope=2; };

	class Asmond_JungleBoots_Grey;
	class JungleBoots_Grey: Asmond_JungleBoots_Grey { scope=2; };

	class Asmond_MilitaryBoots_Arctic;
	class MilitaryBoots_Arctic: Asmond_MilitaryBoots_Arctic { scope=2; };

	class Asmond_MilitaryBoots_Green;
	class MilitaryBoots_Green: Asmond_MilitaryBoots_Green { scope=2; };

	class Asmond_MilitaryBoots_Desert;
	class MilitaryBoots_Desert: Asmond_MilitaryBoots_Desert { scope=2; };

	class Asmond_NBCBoots_Blue;
	class NBCBoots_Blue: Asmond_NBCBoots_Blue { scope=2; };

	class Asmond_NBCBoots_Orange;
	class NBCBoots_Orange: Asmond_NBCBoots_Orange { scope=2; };

	class Asmond_NBCBoots_EMR;
	class NBCBoots_EMR: Asmond_NBCBoots_EMR { scope=2; };

	class Asmond_NBCBoots_Camo;
	class NBCBoots_Camo: Asmond_NBCBoots_Camo { scope=2; };

	class Asmond_NBCBoots_OZK;
	class NBCBoots_OZK: Asmond_NBCBoots_OZK { scope=2; };

	class Asmond_NBCBoots_Grey;
	class NBCBootsGray_2: Asmond_NBCBoots_Grey { scope=2; };

	class Asmond_TraditionalBoots_Black;
	class TraditionalBoots_Black: Asmond_TraditionalBoots_Black { scope=2; };

	class Asmond_TraditionalBoots_Green;
	class TraditionalBoots_Green: Asmond_TraditionalBoots_Green { scope=2; };

	class Asmond_TraditionalBoots_White;
	class TraditionalBoots_White: Asmond_TraditionalBoots_White
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							healthLevels[] = {{1,{"DZ\characters\shoes\Data\TraditionalBoots.rvmat"}},{0.7,{"AsmondClothing\Data\Boots\TraditionalBoots\Data\Asmond_TraditionalBoots.rvmat"}},{0.5,{"AsmondClothing\Data\Boots\TraditionalBoots\Data\Asmond_TraditionalBoots_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Boots\TraditionalBoots\Data\Asmond_TraditionalBoots_Damage.rvmat"}},{0,{"AsmondClothing\Data\Boots\TraditionalBoots\Data\Asmond_TraditionalBoots_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_WorkingBoots_White;
	class WorkingBoots_White: Asmond_WorkingBoots_White { scope=2; };

	class Asmond_WorkingBoots_Black;
	class WorkingBoots_Black: Asmond_WorkingBoots_Black { scope=2; };

	class Asmond_WorkingBoots_LightBrown;
	class WorkingBoots_LightBrown: Asmond_WorkingBoots_LightBrown { scope=2; };

};
