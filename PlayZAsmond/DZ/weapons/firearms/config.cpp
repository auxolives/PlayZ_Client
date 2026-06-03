class CfgPatches
{
	class PlayZAsmond_firearms
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Weapons_Firearms",
			"PlayZAsmond",
			"AsmondWeapons",
		};
	};
};

class cfgWeapons
{
	class AK101;
	class AK74;
	class AKM;
	class AKS74U;
	class ASVAL;
	class Aug;
	class AugShort;
	class B95;
	class CZ527;
	class CZ550;
	class CZ61;
	class CZ75;
	class Colt1911;
	class Crossbow;
	class Deagle;
	class Derringer_Black;
	class Engraved1911;
	class FAL;
	class FAMAS;
	class FNX45;
	class Glock19;
	class Izh18;
	class Izh18Shotgun;
	class Izh43Shotgun;
	class LongHorn;
	class M14;
	class M16A2;
	class M4A1;
	class M79;
	class MKII;
	class MP5K;
	class Magnum;
	class MakarovIJ70;
	class Mosin9130;
	class Mp133Shotgun;
	class P1;
	class PM73Rak;
	class PP19;
	class R12;
	class Repeater;
	class Ruger1022;
	class SKS;
	class SSG82;
	class SV98;
	class SVD;
	class SVD_Wooden;
	class Saiga;
	class SawedoffB95;
	class SawedoffFAMAS;
	class SawedoffIzh18;
	class SawedoffIzh18Shotgun;
	class SawedoffIzh43Shotgun;
	class SawedoffMagnum;
	class SawedoffMosin9130;
	class Scout;
	class UMP45;
	class VSS;
	class Vikhr;
	class Winchester70;

	class Asmond_1911_Malvinas;
	class 1911_Malvinas: Asmond_1911_Malvinas
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\1911\data\1911.rvmat"}},{0.7,{"AsmondWeapons\Weapons\1911\Data\Asmond_1911_Malvinas.rvmat"}},{0.5,{"AsmondWeapons\Weapons\1911\Data\Asmond_1911_Malvinas_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\1911\Data\Asmond_1911_Malvinas_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\1911\Data\Asmond_1911_Malvinas_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_1911_Black;
	class 1911_Black: Asmond_1911_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\1911\data\1911.rvmat"}},{0.7,{"AsmondWeapons\Weapons\1911\Data\Asmond_1911_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\1911\Data\Asmond_1911_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\1911\Data\Asmond_1911_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\1911\Data\Asmond_1911_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_1911_YellowKing;
	class 1911_YellowKing: Asmond_1911_YellowKing
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\1911\data\1911.rvmat"}},{0.7,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Asmond_1911Engraved_Gold.rvmat"}},{0.5,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Asmond_1911Engraved_Gold_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Asmond_1911Engraved_Gold_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Asmond_1911Engraved_Gold_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK101_Black;
	class AK101_Black_2: Asmond_AK101_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\Data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK101_Wine;
	class AK101_Wine: Asmond_AK101_Wine
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\Data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Wine.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Wine_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Wine_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Wine_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK101_Winter;
	class AK101_Winter: Asmond_AK101_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\Data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Winter.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Winter_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Winter_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Winter_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK101_Grey;
	class AK101_Grey: Asmond_AK101_Grey
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\Data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Grey.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Grey_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Grey_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Grey_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK74_Desert;
	class AK74_Desert: Asmond_AK74_Desert
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\Data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK74_Black;
	class AK74_Black_2: Asmond_AK74_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\Data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK74_Combatant;
	class AK74_Combatant: Asmond_AK74_Combatant
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\Data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Combatant.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Combatant_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Combatant_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Combatant_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK74_Winter;
	class AK74_Winter: Asmond_AK74_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\Data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Winter.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Winter_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Winter_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Winter_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK74_Rusted;
	class AK74_Rusted: Asmond_AK74_Rusted
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\Data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AKM_Camo;
	class AKM_Camo: Asmond_AKM_Camo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AKM\data\AKM.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Camo.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Camo_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Camo_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Camo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AKM_Grey;
	class AKM_Grey: Asmond_AKM_Grey
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AKM\data\AKM.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Grey.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Grey_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Grey_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Grey_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AKM_Brown;
	class AKM_Brown: Asmond_AKM_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AKM\data\AKM.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Grey.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Grey_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Grey_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Grey_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AKM_Black;
	class AKM_Black: Asmond_AKM_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AKM\data\AKM.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AKM_Winter;
	class AKM_Winter: Asmond_AKM_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AKM\data\AKM.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Winter.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Winter_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Winter_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Asmond_AKM_Winter_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AKS74U_Black;
	class AKS74U_Black_2: Asmond_AKS74U_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\ak74\Data\aks74u.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKS74U\Data\Asmond_AKS74U_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKS74U\Data\Asmond_AKS74U_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKS74U\Data\Asmond_AKS74U_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKS74U\Data\Asmond_AKS74U_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AKS74U_Grey;
	class AKS74U_Grey: Asmond_AKS74U_Grey
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\ak74\Data\aks74u.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKS74U\Data\Asmond_AKS74U_Grey.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKS74U\Data\Asmond_AKS74U_Grey_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKS74U\Data\Asmond_AKS74U_Grey_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKS74U\Data\Asmond_AKS74U_Grey_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AKS74U_Winter;
	class AKS74U_Winter: Asmond_AKS74U_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\ak74\Data\aks74u.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKS74U\Data\Asmond_AKS74U_Winter.rvmat"}},{0.5,{"DZ\weapons\firearms\ak74\Data\aks74u_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\ak74\Data\aks74u_damage.rvmat"}},{0,{"DZ\weapons\firearms\ak74\Data\aks74u_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_ASVAL_Red;
	class ASVAL_Red: Asmond_ASVAL_Red
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"dz\weapons\firearms\VSS\data\val.rvmat","dz\weapons\firearms\VSS\data\val_rails.rvmat"}},{0.7,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Red.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Red_Rails.rvmat"}},{0.5,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Red_Damage.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Red_Rails_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Red_Damage.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Red_Rails_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Red_Destruct.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Red_Rails_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_ASVAL_Grey;
	class ASVAL_Grey: Asmond_ASVAL_Grey { scope=2; };

	class Asmond_ASVAL_Moss;
	class ASVAL_Moss: Asmond_ASVAL_Moss
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"dz\weapons\firearms\VSS\data\val.rvmat","dz\weapons\firearms\VSS\data\val_rails.rvmat"}},{0.7,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Moss.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Moss_Rails.rvmat"}},{0.5,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Moss_Damage.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Moss_Rails_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Moss_Damage.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Moss_Rails_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Moss_Destruct.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Moss_Rails_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_ASVAL_Stalker;
	class ASVAL_Stalker: Asmond_ASVAL_Stalker
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"dz\weapons\firearms\VSS\data\val.rvmat","dz\weapons\firearms\VSS\data\val_rails.rvmat"}},{0.7,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Stalker.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Stalker_Rails.rvmat"}},{0.5,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Stalker_Damage.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Stalker_Rails_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Stalker_Damage.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Stalker_Rails_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Stalker_Destruct.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Stalker_Rails_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_ASVAL_Loner;
	class ASVAL_Loner: Asmond_ASVAL_Loner
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"dz\weapons\firearms\VSS\data\val.rvmat","dz\weapons\firearms\VSS\data\val_rails.rvmat"}},{0.7,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Loner.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Loner_Rails.rvmat"}},{0.5,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Loner_Damage.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Loner_Rails_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Loner_Damage.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Loner_Rails_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Loner_Destruct.rvmat","AsmondWeapons\Weapons\ASVAL\Data\Asmond_ASVAL_Loner_Rails_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AUG_Green;
	class AUG_Green: Asmond_AUG_Green { scope=2; };

	class Asmond_AUG_Beige;
	class AUG_Beige: Asmond_AUG_Beige { scope=2; };

	class Asmond_AUG_Grey;
	class AUG_Grey: Asmond_AUG_Grey { scope=2; };

	class Asmond_AUG_Black;
	class AUG_Black: Asmond_AUG_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\aug\data\aug_barrel.rvmat","DZ\weapons\firearms\aug\data\aug_stock.rvmat","DZ\weapons\firearms\aug\data\rail.rvmat"}},{0.7,{"DZ\weapons\firearms\aug\data\aug_barrel.rvmat","AsmondWeapons\Weapons\AURAX\Data\Asmond_AURAX_Black_Stock.rvmat","DZ\weapons\firearms\aug\data\rail.rvmat"}},{0.5,{"DZ\weapons\firearms\aug\data\aug_barrel_damage.rvmat","AsmondWeapons\Weapons\AURAX\Data\Asmond_AURAX_Black_Stock_Damage.rvmat","DZ\weapons\firearms\aug\data\rail_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\aug\data\aug_barrel_damage.rvmat","AsmondWeapons\Weapons\AURAX\Data\Asmond_AURAX_Black_Stock_Damage.rvmat","DZ\weapons\firearms\aug\data\rail_damage.rvmat"}},{0,{"DZ\weapons\firearms\aug\data\aug_barrel_destruct.rvmat","AsmondWeapons\Weapons\AURAX\Data\Asmond_AURAX_Black_Stock_Destruct.rvmat","DZ\weapons\firearms\aug\data\rail_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AUGShort_Green;
	class AUGShort_Green: Asmond_AUGShort_Green { scope=2; };

	class Asmond_AUGShort_Grey;
	class AUGShort_Grey: Asmond_AUGShort_Grey { scope=2; };

	class Asmond_AUGShort_Beige;
	class AUGShort_Beige: Asmond_AUGShort_Beige { scope=2; };

	class Asmond_AUGShort_Black;
	class AUGShort_Black: Asmond_AUGShort_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\aug\data\aug_barrel.rvmat","DZ\weapons\firearms\aug\data\aug_stock.rvmat","DZ\weapons\firearms\aug\data\scope.rvmat"}},{0.7,{"DZ\weapons\firearms\aug\data\aug_barrel.rvmat","AsmondWeapons\Weapons\AURShort\Data\Asmond_AUR_Short_Black_Stock.rvmat","DZ\weapons\firearms\aug\data\scope.rvmat"}},{0.5,{"DZ\weapons\firearms\aug\data\aug_barrel_damage.rvmat","AsmondWeapons\Weapons\AURShort\Data\Asmond_AUR_Short_Black_Stock_Damage.rvmat","DZ\weapons\firearms\aug\data\scope_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\aug\data\aug_barrel_damage.rvmat","AsmondWeapons\Weapons\AURShort\Data\Asmond_AUR_Short_Black_Stock_Damage.rvmat","DZ\weapons\firearms\aug\data\scope_damage.rvmat"}},{0,{"DZ\weapons\firearms\aug\data\aug_barrel_destruct.rvmat","AsmondWeapons\Weapons\AURShort\Data\Asmond_AUR_Short_Black_Stock_Destruct.rvmat","DZ\weapons\firearms\aug\data\scope_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_B95_Wood;
	class B95_Wood: Asmond_B95_Wood { scope=2; };

	class Asmond_SawoffB95_Wood;
	class SawoffB95_Wood: Asmond_SawoffB95_Wood { scope=2; };

	class Asmond_B95_Dark;
	class B95_Dark: Asmond_B95_Dark { scope=2; };

	class Asmond_SawoffB95_Dark;
	class SawoffB95_Dark: Asmond_SawoffB95_Dark { scope=2; };

	class Asmond_B95_Winter;
	class B95_Winter: Asmond_B95_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\B95\Data\b95.rvmat"}},{0.7,{"AsmondWeapons\Weapons\B95\Data\Asmond_B95_Painted.rvmat"}},{0.5,{"AsmondWeapons\Weapons\B95\Data\Asmond_B95_Painted_damaged.rvmat"}},{0.3,{"AsmondWeapons\Weapons\B95\Data\Asmond_B95_Painted_damaged.rvmat"}},{0,{"AsmondWeapons\Weapons\B95\Data\Asmond_B95_Painted_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawoffB95_Winter;
	class SawoffB95_Winter: Asmond_SawoffB95_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\B95\Data\b95.rvmat"}},{0.7,{"DZ\weapons\firearms\B95\Data\b95.rvmat"}},{0.5,{"DZ\weapons\firearms\B95\Data\b95_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\B95\Data\b95_damage.rvmat"}},{0,{"DZ\weapons\firearms\B95\Data\b95_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_B95_Moss;
	class B95_Moss: Asmond_B95_Moss
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\B95\Data\b95.rvmat"}},{0.7,{"AsmondWeapons\Weapons\B95\Data\Asmond_B95_Painted.rvmat"}},{0.5,{"AsmondWeapons\Weapons\B95\Data\Asmond_B95_Painted_damaged.rvmat"}},{0.3,{"AsmondWeapons\Weapons\B95\Data\Asmond_B95_Painted_damaged.rvmat"}},{0,{"AsmondWeapons\Weapons\B95\Data\Asmond_B95_Painted_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawoffB95_Moss;
	class SawoffB95_Moss: Asmond_SawoffB95_Moss
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\B95\Data\b95.rvmat"}},{0.7,{"DZ\weapons\firearms\B95\Data\b95.rvmat"}},{0.5,{"DZ\weapons\firearms\B95\Data\b95_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\B95\Data\b95_damage.rvmat"}},{0,{"DZ\weapons\firearms\B95\Data\b95_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_PP19_Red;
	class PP19_Red: Asmond_PP19_Red { scope=2; };

	class Asmond_PP19_Black;
	class PP19_Black: Asmond_PP19_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\PP19\Data\PP_19.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Bizon_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Bizon_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Bizon_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Bizon_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Crossbow_Winter;
	class Crossbow_Winter: Asmond_Crossbow_Winter { scope=2; };

	class Asmond_Crossbow_Camo;
	class Crossbow_Camo: Asmond_Crossbow_Camo { scope=2; };

	class Asmond_CZ527_Camo;
	class CZ527_Camo_2: Asmond_CZ527_Camo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\cz527\Data\cz527.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Camo.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Camo_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Camo_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Camo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CZ527_Winter;
	class CZ527_Winter: Asmond_CZ527_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\cz527\Data\cz527.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Camo.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Camo_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Camo_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Camo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CZ527_Black;
	class CZ527_Black_2: Asmond_CZ527_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\cz527\Data\cz527.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CZ527_Brown;
	class CZ527_Brown: Asmond_CZ527_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\cz527\Data\cz527.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Brown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Brown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Brown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ527\Data\Asmond_CZ527_Brown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CZ550_Black;
	class CZ550_Black: Asmond_CZ550_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\cz550\Data\cz550.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CZ550_Brown;
	class CZ550_Brown: Asmond_CZ550_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\cz550\Data\cz550.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Brown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Brown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Brown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Brown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CZ550_Winter;
	class CZ550_Winter: Asmond_CZ550_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\cz550\Data\cz550.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Dark.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Dark_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Dark_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Dark_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CZ550_Green;
	class CZ550_Green: Asmond_CZ550_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\cz550\Data\cz550.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ550\Data\Asmond_CZ550_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CZ61_Sand;
	class CZ61_Sand: Asmond_CZ61_Sand
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\cz61\data\cz61.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ61\Data\Asmond_CZ61_Sand.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ61\Data\Asmond_CZ61_Sand_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ61\Data\Asmond_CZ61_Sand_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ61\Data\Asmond_CZ61_Sand_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CZ61_Black;
	class CZ61_Black: Asmond_CZ61_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\cz61\data\cz61.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ61\Data\Asmond_CZ61_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ61\Data\Asmond_CZ61_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ61\Data\Asmond_CZ61_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ61\Data\Asmond_CZ61_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CZ75_Wooden;
	class CZ75_Wooden: Asmond_CZ75_Wooden
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 170;
							healthLevels[] = {{1,{"DZ\weapons\pistols\cz75\data\cz75.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ75\Data\Asmond_CZ75_Wooden.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ75\Data\Asmond_CZ75_Wooden_damaged.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ75\Data\Asmond_CZ75_Wooden_damaged.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ75\Data\Asmond_CZ75_Wooden_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CZ75_Silver;
	class CZ75_Silver: Asmond_CZ75_Silver
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 170;
							healthLevels[] = {{1,{"DZ\weapons\pistols\cz75\data\cz75.rvmat"}},{0.7,{"AsmondWeapons\Weapons\CZ75\Data\Asmond_CZ75_Silver.rvmat"}},{0.5,{"AsmondWeapons\Weapons\CZ75\Data\Asmond_CZ75_Silver_damaged.rvmat"}},{0.3,{"AsmondWeapons\Weapons\CZ75\Data\Asmond_CZ75_Silver_damaged.rvmat"}},{0,{"AsmondWeapons\Weapons\CZ75\Data\Asmond_CZ75_Silver_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Deagle_Beige;
	class Deagle_Beige: Asmond_Deagle_Beige { scope=2; };

	class Asmond_Deagle_Black;
	class Deagle_Black: Asmond_Deagle_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 220;
							healthLevels[] = {{1,{"DZ\weapons\pistols\DE\data\deagle.rvmat","DZ\weapons\pistols\DE\data\deagle_plastic.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Deagle\Data\Asmond_Deagle_Black.rvmat","DZ\weapons\pistols\DE\data\deagle_plastic.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Deagle\Data\Asmond_Deagle_Black_damage.rvmat","DZ\weapons\pistols\DE\data\deagle_plastic_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Deagle\Data\Asmond_Deagle_Black_damage.rvmat","DZ\weapons\pistols\DE\data\deagle_plastic_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Deagle\Data\Asmond_Deagle_Black_destruct.rvmat","DZ\weapons\pistols\DE\data\deagle_plastic_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Derringer_White;
	class Derringer_White: Asmond_Derringer_White
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\derringer\data\derringer_1.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Derringer\Data\Asmond_Derringer_Model95.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Derringer\Data\Asmond_Derringer_Model95_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Derringer\Data\Asmond_Derringer_Model95_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Derringer\Data\Asmond_Derringer_Model95_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Derringer_RedWood;
	class Derringer_RedWood: Asmond_Derringer_RedWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\derringer\data\derringer_1.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Derringer\Data\Asmond_Derringer_Redwood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Derringer\Data\Asmond_Derringer_Redwood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Derringer\Data\Asmond_Derringer_Redwood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Derringer\Data\Asmond_Derringer_Redwood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_FAL_DarkWood;
	class FAL_DarkWood: Asmond_FAL_DarkWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\fal\Data\fal.rvmat"}},{0.7,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_DarkWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_DarkWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_DarkWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_DarkWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_FAL_Moss;
	class FAL_Moss: Asmond_FAL_Moss
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\fal\Data\fal.rvmat"}},{0.7,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Moss.rvmat"}},{0.5,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Moss_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Moss_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Moss_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_FAL_Winter;
	class FAL_Winter: Asmond_FAL_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\fal\Data\fal.rvmat"}},{0.7,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Winter.rvmat"}},{0.5,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Winter_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Winter_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Winter_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_FAL_LightWood;
	class FAL_LightWood: Asmond_FAL_LightWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\fal\Data\fal.rvmat"}},{0.7,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Moss.rvmat"}},{0.5,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Moss_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Moss_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\FAL\Data\Asmond_FAL_Moss_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_FAMAS_Black;
	class FAMAS_Black: Asmond_FAMAS_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 180;
							healthLevels[] = {{1,{"DZ\weapons\firearms\famas\data\famas_rifle1.rvmat","DZ\weapons\firearms\famas\data\famas_rifle2.rvmat"}},{0.7,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1.rvmat","AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R2.rvmat"}},{0.5,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1_Damage.rvmat","AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R2_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1_Damage.rvmat","AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R2_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1_Destruct.rvmat","AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R2_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawedoffFAMAS_Black;
	class SawedoffFAMAS_Black: Asmond_SawedoffFAMAS_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 180;
							healthLevels[] = {{1,{"DZ\weapons\firearms\famas\data\famas_rifle1.rvmat","DZ\weapons\firearms\famas\data\famas_rifle2.rvmat"}},{0.7,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1.rvmat","AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R2.rvmat"}},{0.5,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1_Damage.rvmat","AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R2_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1_Damage.rvmat","AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R2_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1_Destruct.rvmat","AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R2_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_FNX_Desert;
	class FNX_Desert: Asmond_FNX_Desert
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\weapons\pistols\fnx45\data\herstal45.rvmat","DZ\weapons\pistols\fnx45\data\herstal45_bolt.rvmat"}},{0.7,{"AsmondWeapons\Weapons\FNX45\Data\Asmond_FNX_Desert.rvmat","DZ\weapons\pistols\fnx45\data\herstal45_bolt.rvmat"}},{0.5,{"AsmondWeapons\Weapons\FNX45\Data\Asmond_FNX_Desert_Damage.rvmat","DZ\weapons\pistols\fnx45\data\herstal45_bolt_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\FNX45\Data\Asmond_FNX_Desert_Damage.rvmat","DZ\weapons\pistols\fnx45\data\herstal45_bolt_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\FNX45\Data\Asmond_FNX_Desert_Destruct.rvmat","DZ\weapons\pistols\fnx45\data\herstal45_bolt_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_FNX_Black;
	class FNX_Black: Asmond_FNX_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\weapons\pistols\fnx45\data\herstal45.rvmat","DZ\weapons\pistols\fnx45\data\herstal45_bolt.rvmat"}},{0.7,{"AsmondWeapons\Weapons\FNX45\Data\Asmond_FNX_Black.rvmat","DZ\weapons\pistols\fnx45\data\herstal45_bolt.rvmat"}},{0.5,{"AsmondWeapons\Weapons\FNX45\Data\Asmond_FNX_Black_Damage.rvmat","DZ\weapons\pistols\fnx45\data\herstal45_bolt_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\FNX45\Data\Asmond_FNX_Black_Damage.rvmat","DZ\weapons\pistols\fnx45\data\herstal45_bolt_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\FNX45\Data\Asmond_FNX_Black_Destruct.rvmat","DZ\weapons\pistols\fnx45\data\herstal45_bolt_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Glock_Desert;
	class Glock_Desert: Asmond_Glock_Desert
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\weapons\pistols\glock\data\glock19.rvmat"}},{0.7,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey.rvmat"}},{0.5,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Glock_Green;
	class Glock_Green: Asmond_Glock_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\weapons\pistols\glock\data\glock19.rvmat"}},{0.7,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey.rvmat"}},{0.5,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Glock_Grey;
	class Glock_Grey: Asmond_Glock_Grey
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\weapons\pistols\glock\data\glock19.rvmat"}},{0.7,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey.rvmat"}},{0.5,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\GLOCK\Data\Asmond_Glock_Grey_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_IZH18Rifle_Black;
	class IZH18Rifle_Black: Asmond_IZH18Rifle_Black { scope=2; };

	class Asmond_SawedoffIzh18_Black;
	class SawedoffIzh18_Black: Asmond_SawedoffIzh18_Black { scope=2; };

	class Asmond_IZH18Rifle_Brown;
	class IZH18Rifle_Brown: Asmond_IZH18Rifle_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\Izh18\data\Izh18.rvmat"}},{0.7,{"AsmondWeapons\Weapons\IZH18Rifle\Data\Asmond_IZH18Rifle_Brown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\IZH18Rifle\Data\Asmond_IZH18Rifle_Brown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\IZH18Rifle\Data\Asmond_IZH18Rifle_Brown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\IZH18Rifle\Data\Asmond_IZH18Rifle_Brown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawedoffIzh18_Brown;
	class SawedoffIzh18_Brown: Asmond_SawedoffIzh18_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\Izh18\data\Izh18.rvmat"}},{0.7,{"AsmondWeapons\Weapons\IZH18Rifle\Data\Asmond_IZH18Rifle_Brown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\IZH18Rifle\Data\Asmond_IZH18Rifle_Brown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\IZH18Rifle\Data\Asmond_IZH18Rifle_Brown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\IZH18Rifle\Data\Asmond_IZH18Rifle_Brown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_IZH18Shotgun_RedWood;
	class IZH18Shotgun_RedWood: Asmond_IZH18Shotgun_RedWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\shotguns\Izh18Shotgun\data\Izh18Shotgun.rvmat"}},{0.7,{"AsmondWeapons\Weapons\IZH18Shotgun\Data\Asmond_IZH18Shotgun_RedWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\IZH18Shotgun\Data\Asmond_IZH18Shotgun_RedWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\IZH18Shotgun\Data\Asmond_IZH18Shotgun_RedWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\IZH18Shotgun\Data\Asmond_IZH18Shotgun_RedWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawedoffIzh18Shotgun_RedWood;
	class SawedoffIzh18Shotgun_RedWood: Asmond_SawedoffIzh18Shotgun_RedWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\shotguns\Izh18Shotgun\data\Izh18Shotgun.rvmat"}},{0.7,{"AsmondWeapons\Weapons\IZH18Shotgun\Data\Asmond_IZH18Shotgun_RedWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\IZH18Shotgun\Data\Asmond_IZH18Shotgun_RedWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\IZH18Shotgun\Data\Asmond_IZH18Shotgun_RedWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\IZH18Shotgun\Data\Asmond_IZH18Shotgun_RedWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_IZH18Shotgun_Black;
	class IZH18Shotgun_Black: Asmond_IZH18Shotgun_Black { scope=2; };

	class Asmond_SawedoffIzh18Shotgun_Black;
	class SawedoffIzh18Shotgun_Black: Asmond_SawedoffIzh18Shotgun_Black { scope=2; };

	class Asmond_IZH43Shotgun_RedWood;
	class IZH43Shotgun_RedWood: Asmond_IZH43Shotgun_RedWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\shotguns\Izh43\data\izh43.rvmat"}},{0.7,{"AsmondWeapons\Weapons\IZH43Shotgun\Data\Asmond_IZH43Shotgun_RedWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\IZH43Shotgun\Data\Asmond_IZH43Shotgun_RedWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\IZH43Shotgun\Data\Asmond_IZH43Shotgun_RedWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\IZH43Shotgun\Data\Asmond_IZH43Shotgun_RedWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawedoffIzh43Shotgun_RedWood;
	class SawedoffIzh43Shotgun_RedWood: Asmond_SawedoffIzh43Shotgun_RedWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\shotguns\Izh43\data\izh43.rvmat"}},{0.7,{"AsmondWeapons\Weapons\IZH43Shotgun\Data\Asmond_IZH43Shotgun_RedWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\IZH43Shotgun\Data\Asmond_IZH43Shotgun_RedWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\IZH43Shotgun\Data\Asmond_IZH43Shotgun_RedWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\IZH43Shotgun\Data\Asmond_IZH43Shotgun_RedWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_IZH43Shotgun_Green;
	class IZH43Shotgun_Green: Asmond_IZH43Shotgun_Green { scope=2; };

	class Asmond_SawedoffIzh43Shotgun_Green;
	class SawedoffIzh43Shotgun_Green: Asmond_SawedoffIzh43Shotgun_Green { scope=2; };

	class Asmond_LongHorn_Black;
	class LongHorn_Black: Asmond_LongHorn_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\LongHorn\data\LongHorn.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Longhorn\Data\Asmond_Longhorn_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Longhorn\Data\Asmond_Longhorn_Black_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Longhorn\Data\Asmond_Longhorn_Black_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Longhorn\Data\Asmond_Longhorn_Black_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_LongHorn_LightBrown;
	class LongHorn_LightBrown: Asmond_LongHorn_LightBrown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\LongHorn\data\LongHorn.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Longhorn\Data\Asmond_Longhorn_LightWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Longhorn\Data\Asmond_Longhorn_LightWood_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Longhorn\Data\Asmond_Longhorn_LightWood_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Longhorn\Data\Asmond_Longhorn_LightWood_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M14_Black;
	class M14_Black: Asmond_M14_Black { scope=2; };

	class Asmond_M14_Tan;
	class M14_Tan: Asmond_M14_Tan { scope=2; };

	class Asmond_M14_Camo;
	class M14_Camo: Asmond_M14_Camo { scope=2; };

	class Asmond_M14_Winter;
	class M14_Winter: Asmond_M14_Winter { scope=2; };

	class Asmond_M14_Wooden;
	class M14_Wooden: Asmond_M14_Wooden
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\M14\Data\m14_metal.rvmat","DZ\weapons\firearms\M14\Data\m14_synth.rvmat"}},{0.7,{"DZ\weapons\firearms\M14\Data\m14_metal.rvmat","AsmondWeapons\Weapons\M14\Data\Asmond_M14_Wooden_Synth.rvmat"}},{0.5,{"DZ\weapons\firearms\M14\Data\m14_metal_damage.rvmat","AsmondWeapons\Weapons\M14\Data\Asmond_M14_Wooden_Synth_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\M14\Data\m14_metal_damage.rvmat","AsmondWeapons\Weapons\M14\Data\Asmond_M14_Wooden_Synth_Damage.rvmat"}},{0,{"DZ\weapons\firearms\M14\Data\m14_metal_destruct.rvmat","AsmondWeapons\Weapons\M14\Data\Asmond_M14_Wooden_Synth_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M16A2_Camo;
	class M16A2_Camo: Asmond_M16A2_Camo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\M16a2\Data\m16a2_a.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b.rvmat"}},{0.7,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b.rvmat"}},{0.5,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A_Damage.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A_Damage.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A_Destruct.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M16A2_Purple;
	class M16A2_Purple: Asmond_M16A2_Purple { scope=2; };

	class Asmond_M16A2_Wooden;
	class M16A2_Wooden: Asmond_M16A2_Wooden
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"dz\weapons\firearms\m16a2\data\m16a2_a.rvmat","dz\weapons\firearms\m16a2\data\m16a2_b.rvmat"}},{0.7,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Wooden_A.rvmat","AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Wooden_B.rvmat"}},{0.5,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Wooden_A_Damage.rvmat","AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Wooden_B_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Wooden_A_Damage.rvmat","AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Wooden_B_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Wooden_A_Destruct.rvmat","AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Wooden_B_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M16A2_Tan;
	class M16A2_Tan: Asmond_M16A2_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\M16a2\Data\m16a2_a.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b.rvmat"}},{0.7,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b.rvmat"}},{0.5,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A_Damage.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A_Damage.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A_Destruct.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M16A2_Green;
	class M16A2_Green: Asmond_M16A2_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\M16a2\Data\m16a2_a.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b.rvmat"}},{0.7,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b.rvmat"}},{0.5,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A_Damage.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A_Damage.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\M16\Data\Asmond_M16A2_Tan_A_Destruct.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M16A2_Winter;
	class M16A2_Winter: Asmond_M16A2_Winter { scope=2; };

	class Asmond_M4A1_Camo;
	class M4A1_Camo: Asmond_M4A1_Camo { scope=2; };

	class Asmond_M4A1_Tan;
	class M4A1_Tan: Asmond_M4A1_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\M4\Data\m4_body.rvmat"}},{0.7,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Tan.rvmat"}},{0.5,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Tan_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Tan_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Tan_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M4A1_Winter;
	class M4A1_Winter: Asmond_M4A1_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\M4\Data\m4_body.rvmat"}},{0.7,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Winter.rvmat"}},{0.5,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Winter_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Winter_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Winter_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M4A1_Dark;
	class M4A1_Dark: Asmond_M4A1_Dark
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\M4\Data\m4_body.rvmat"}},{0.7,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Dark.rvmat"}},{0.5,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Dark_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Dark_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Dark_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M4A1_Green;
	class M4A1_Green_2: Asmond_M4A1_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\M4\Data\m4_body.rvmat"}},{0.7,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Green.rvmat"}},{0.5,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Green_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Green_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Green_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M4A1_Desert;
	class M4A1_Desert: Asmond_M4A1_Desert
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\M4\Data\m4_body.rvmat"}},{0.7,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Desert.rvmat"}},{0.5,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Desert_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Desert_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\M4A1\Data\Asmond_M4A1_Desert_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M79_Polymer;
	class M79_Polymer: Asmond_M79_Polymer
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\launchers\m79\data\m79_a.rvmat","DZ\weapons\launchers\m79\data\m79_b.rvmat"}},{0.7,{"AsmondWeapons\Weapons\M79\Data\Asmond_M79_Polymer_A.rvmat","AsmondWeapons\Weapons\M79\Data\Asmond_M79_Polymer_B.rvmat"}},{0.5,{"AsmondWeapons\Weapons\M79\Data\Asmond_M79_Polymer_A_Damage.rvmat","AsmondWeapons\Weapons\M79\Data\Asmond_M79_Polymer_B_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\M79\Data\Asmond_M79_Polymer_A_Damage.rvmat","AsmondWeapons\Weapons\M79\Data\Asmond_M79_Polymer_B_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\M79\Data\Asmond_M79_Polymer_A_Destruct.rvmat","AsmondWeapons\Weapons\M79\Data\Asmond_M79_Polymer_B_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M79_Green;
	class M79_Green: Asmond_M79_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\launchers\m79\data\m79_a.rvmat","DZ\weapons\launchers\m79\data\m79_b.rvmat"}},{0.7,{"AsmondWeapons\Weapons\M79\Data\Asmond_M79_Green_A.rvmat","AsmondWeapons\Weapons\M79\Data\Asmond_M79_Green_B.rvmat"}},{0.5,{"AsmondWeapons\Weapons\M79\Data\Asmond_M79_Green_A_Damage.rvmat","AsmondWeapons\Weapons\M79\Data\Asmond_M79_Green_B_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\M79\Data\Asmond_M79_Green_A_Damage.rvmat","AsmondWeapons\Weapons\M79\Data\Asmond_M79_Green_B_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\M79\Data\Asmond_M79_Green_A_Destruct.rvmat","AsmondWeapons\Weapons\M79\Data\Asmond_M79_Green_B_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Magnum_Black;
	class Magnum_Black: Asmond_Magnum_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Black.rvmat"}},{0.5,{"DZ\weapons\pistols\magnum\data\magnum_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\magnum\data\magnum_damage.rvmat"}},{0,{"DZ\weapons\pistols\magnum\data\magnum_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawedoffMagnum_Black;
	class SawedoffMagnum_Black: Asmond_SawedoffMagnum_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Magnum_Ivory;
	class Magnum_Ivory: Asmond_Magnum_Ivory
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Ivory.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Ivory_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Ivory_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Ivory_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawedoffMagnum_Ivory;
	class SawedoffMagnum_Ivory: Asmond_SawedoffMagnum_Ivory
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Ivory.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Ivory_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Ivory_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Ivory_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Magnum_Brown;
	class Magnum_Brown: Asmond_Magnum_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Brown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Brown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Brown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Brown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawedoffMagnum_Brown;
	class SawedoffMagnum_Brown: Asmond_SawedoffMagnum_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Brown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Brown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Brown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Magnum\Data\Asmond_Magnum_Brown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_IJ70_Beige;
	class IJ70_Beige: Asmond_IJ70_Beige
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\pistols\pmm\data\pmm.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Makarov\Data\Asmond_IJ70_Beige.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Makarov\Data\Asmond_IJ70_Beige_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Makarov\Data\Asmond_IJ70_Beige_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Makarov\Data\Asmond_IJ70_Beige_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_IJ70_Red;
	class IJ70_Red: Asmond_IJ70_Red
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\pistols\pmm\data\pmm.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Makarov\Data\Asmond_IJ70_Red.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Makarov\Data\Asmond_IJ70_Red_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Makarov\Data\Asmond_IJ70_Red_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Makarov\Data\Asmond_IJ70_Red_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MKII_Wood;
	class MKII_Wood: Asmond_MKII_Wood { scope=2; };

	class Asmond_MKII_Black;
	class MKII_Black: Asmond_MKII_Black { scope=2; };

	class Asmond_Mosin9130_Dark;
	class Mosin9130_Dark: Asmond_Mosin9130_Dark
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_RedWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_RedWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_RedWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_RedWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawedoffMosin9130_Dark;
	class SawedoffMosin9130_Dark: Asmond_SawedoffMosin9130_Dark
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\mosin9130\Data\mosin_sawn.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_RedWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_RedWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_RedWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_RedWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mosin9130_Winter;
	class Mosin9130_Winter: Asmond_Mosin9130_Winter { scope=2; };

	class Asmond_SawedoffMosin9130_Winter;
	class SawedoffMosin9130_Winter: Asmond_SawedoffMosin9130_Winter { scope=2; };

	class Asmond_Mosin9130_BrownCamo;
	class Mosin9130_BrownCamo: Asmond_Mosin9130_BrownCamo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_BrownCamo.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_BrownCamo_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_BrownCamo_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_BrownCamo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawedoffMosin9130_BrownCamo;
	class SawedoffMosin9130_BrownCamo: Asmond_SawedoffMosin9130_BrownCamo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\mosin9130\Data\mosin_sawn.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_BrownCamo.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_BrownCamo_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_BrownCamo_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_BrownCamo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mosin9130_RedWood;
	class Mosin9130_RedWood: Asmond_Mosin9130_RedWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_RedWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_RedWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_RedWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_Mosin9130_RedWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SawedoffMosin9130_RedWood;
	class SawedoffMosin9130_RedWood: Asmond_SawedoffMosin9130_RedWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\mosin9130\Data\mosin_sawn.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_RedWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_RedWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_RedWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Mosin9130\Data\Asmond_SawedoffMosin9130_RedWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MP133_Black;
	class MP133_Black: Asmond_MP133_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\shotguns\Mp133\data\mp133.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MP133_Beige;
	class MP133_Beige: Asmond_MP133_Beige
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\shotguns\Mp133\data\mp133.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_Beige.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_Beige_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_Beige_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_Beige_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MP133_RedWood;
	class MP133_RedWood: Asmond_MP133_RedWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\shotguns\Mp133\data\mp133.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_RedWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_RedWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_RedWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP133\Data\Asmond_MP133_RedWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MP5K_Light;
	class MP5K_Light: Asmond_MP5K_Light
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\MP5\data\mp5k_body.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Light.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Light_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Light_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Light_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MP5K_Black;
	class MP5K_Black: Asmond_MP5K_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\MP5\data\mp5k_body.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MP5K_Sand;
	class MP5K_Sand: Asmond_MP5K_Sand
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\MP5\data\mp5k_body.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Sand.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Sand_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Sand_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Sand_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_P1_Wooden;
	class P1_Wooden: Asmond_P1_Wooden
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\p1\data\p38.rvmat"}},{0.7,{"AsmondWeapons\Weapons\P1\Data\Asmond_P1_Wooden.rvmat"}},{0.5,{"AsmondWeapons\Weapons\P1\Data\Asmond_P1_Wooden_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\P1\Data\Asmond_P1_Wooden_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\P1\Data\Asmond_P1_Wooden_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_P1_Black;
	class P1_Black: Asmond_P1_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\pistols\p1\data\p38.rvmat"}},{0.7,{"AsmondWeapons\Weapons\P1\Data\Asmond_P1_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\P1\Data\Asmond_P1_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\P1\Data\Asmond_P1_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\P1\Data\Asmond_P1_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_PM73Rak_Black;
	class PM73Rak_Black: Asmond_PM73Rak_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\pm73rak\data\pm73.rvmat"}},{0.7,{"AsmondWeapons\Weapons\PM73\Data\Asmond_PM73Rak_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\PM73\Data\Asmond_PM73Rak_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\PM73\Data\Asmond_PM73Rak_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\PM73\Data\Asmond_PM73Rak_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_R12_SledgeHammer;
	class R12_SledgeHammer: Asmond_R12_SledgeHammer
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 225;
							healthLevels[] = {{1,{"DZ\weapons\shotguns\Remington_r12\data\Remington_r12.rvmat"}},{0.7,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_SledgeHammer.rvmat"}},{0.5,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_SledgeHammer_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_SledgeHammer_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_SledgeHammer_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_R12_Wooden;
	class R12_Wooden: Asmond_R12_Wooden
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 225;
							healthLevels[] = {{1,{"DZ\weapons\shotguns\Remington_r12\data\Remington_r12.rvmat"}},{0.7,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_Wooden.rvmat"}},{0.5,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_Wooden_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_Wooden_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_Wooden_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_R12_RedWood;
	class R12_RedWood: Asmond_R12_RedWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 225;
							healthLevels[] = {{1,{"DZ\weapons\shotguns\Remington_r12\data\Remington_r12.rvmat"}},{0.7,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_RedWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_RedWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_RedWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\R12\Data\Asmond_R12_RedWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Repeater_Black;
	class Repeater_Black: Asmond_Repeater_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\repeater\Data\repeater.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Repeater\Data\Asmond_Repeater_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Repeater\Data\Asmond_Repeater_Black_damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Repeater\Data\Asmond_Repeater_Black_damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Repeater\Data\Asmond_Repeater_Black_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Repeater_Wooden;
	class Repeater_Wooden: Asmond_Repeater_Wooden { scope=2; };

	class Asmond_Ruger1022_Black;
	class Ruger1022_Black: Asmond_Ruger1022_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\Ruger1022\data\ruger1022.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Ruger1022\Data\Asmond_Ruger1022_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Ruger1022\Data\Asmond_Ruger1022_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Ruger1022\Data\Asmond_Ruger1022_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Ruger1022\Data\Asmond_Ruger1022_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Ruger1022_Beige;
	class Ruger1022_Beige: Asmond_Ruger1022_Beige
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\Ruger1022\data\ruger1022.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Ruger1022\Data\Asmond_Ruger1022_Beige.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Ruger1022\Data\Asmond_Ruger1022_Beige_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Ruger1022\Data\Asmond_Ruger1022_Beige_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Ruger1022\Data\Asmond_Ruger1022_Beige_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Saiga_Red;
	class Saiga_Red: Asmond_Saiga_Red
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\shotguns\saiga\data\saiga.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Saiga\Data\Asmond_Saiga_Red.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Saiga\Data\Asmond_Saiga_Red_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Saiga\Data\Asmond_Saiga_Red_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Saiga\Data\Asmond_Saiga_Red_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Scout_Grey;
	class Scout_Grey: Asmond_Scout_Grey { scope=2; };

	class Asmond_Scout_Beige;
	class Scout_Beige: Asmond_Scout_Beige { scope=2; };

	class Asmond_Scout_Green;
	class Scout_Green: Asmond_Scout_Green { scope=2; };

	class Asmond_Scout_Wooden;
	class Scout_Wooden: Asmond_Scout_Wooden
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\scout\data\scout.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Scout\Data\Asmond_Scout_Wooden.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Scout\Data\Asmond_Scout_Wooden_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Scout\Data\Asmond_Scout_Wooden_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Scout\Data\Asmond_Scout_Wooden_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SKS_Black;
	class SKS_Black_2: Asmond_SKS_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\SKS\data\sks.rvmat"}},{0.7,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SKS_Green;
	class SKS_Green_2: Asmond_SKS_Green { scope=2; };

	class Asmond_SKS_Lightwood;
	class SKS_Lightwood: Asmond_SKS_Lightwood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\SKS\data\sks.rvmat"}},{0.7,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Lightwood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Lightwood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Lightwood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Lightwood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SKS_Winter;
	class SKS_Winter: Asmond_SKS_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\SKS\data\sks.rvmat"}},{0.7,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Winter.rvmat"}},{0.5,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Winter_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Winter_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Winter_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SKS_RedWood;
	class SKS_RedWood: Asmond_SKS_RedWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\SKS\data\sks.rvmat"}},{0.7,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Lightwood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Lightwood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Lightwood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Lightwood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SKS_Old;
	class SKS_Old: Asmond_SKS_Old
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\firearms\SKS\data\sks.rvmat"}},{0.7,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\SKS\Data\Asmond_SKS_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SSG82_Black;
	class SSG82_Black: Asmond_SSG82_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\ssg82\data\ssg82_01.rvmat","DZ\weapons\firearms\ssg82\data\ssg82_02.rvmat"}},{0.7,{"DZ\weapons\firearms\ssg82\data\ssg82_01.rvmat","AsmondWeapons\Weapons\SSG82\Data\Asmond_SSG82_Black.rvmat"}},{0.5,{"DZ\weapons\firearms\ssg82\data\ssg82_01_damage.rvmat","AsmondWeapons\Weapons\SSG82\Data\Asmond_SSG82_Black_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\ssg82\data\ssg82_01_damage.rvmat","AsmondWeapons\Weapons\SSG82\Data\Asmond_SSG82_Black_damage.rvmat"}},{0,{"DZ\weapons\firearms\ssg82\data\ssg82_01_destruct.rvmat","AsmondWeapons\Weapons\SSG82\Data\Asmond_SSG82_Black_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SSG82_Redwood;
	class SSG82_Redwood: Asmond_SSG82_Redwood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\ssg82\data\ssg82_01.rvmat","DZ\weapons\firearms\ssg82\data\ssg82_02.rvmat"}},{0.7,{"DZ\weapons\firearms\ssg82\data\ssg82_01.rvmat","AsmondWeapons\Weapons\SSG82\Data\Asmond_SSG82_Black.rvmat"}},{0.5,{"DZ\weapons\firearms\ssg82\data\ssg82_01_damage.rvmat","AsmondWeapons\Weapons\SSG82\Data\Asmond_SSG82_Black_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\ssg82\data\ssg82_01_damage.rvmat","AsmondWeapons\Weapons\SSG82\Data\Asmond_SSG82_Black_damage.rvmat"}},{0,{"DZ\weapons\firearms\ssg82\data\ssg82_01_destruct.rvmat","AsmondWeapons\Weapons\SSG82\Data\Asmond_SSG82_Black_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SSG82_Winter;
	class SSG82_Winter: Asmond_SSG82_Winter { scope=2; };

	class Asmond_SV98_Wooden;
	class SV98_Wooden: Asmond_SV98_Wooden
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\sv98\data\sv98_wood.rvmat","DZ\weapons\firearms\sv98\data\sv98_metal.rvmat"}},{0.7,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Wooden.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_DarkMetal.rvmat"}},{0.5,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Wooden_Damage.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_DarkMetal_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Wooden_Damage.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_DarkMetal_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Wooden_Destruct.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_DarkMetal_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SV98_Winter;
	class SV98_Winter: Asmond_SV98_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\sv98\data\sv98_wood.rvmat","DZ\weapons\firearms\sv98\data\sv98_metal.rvmat"}},{0.7,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Winter.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_WinterMetal.rvmat"}},{0.5,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Winter_Damage.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_WinterMetal_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Winter_Damage.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_WinterMetal_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Winter_Destruct.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_WinterMetal_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SV98_Black;
	class SV98_Black: Asmond_SV98_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\sv98\data\sv98_wood.rvmat","DZ\weapons\firearms\sv98\data\sv98_metal.rvmat"}},{0.7,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Black.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_WinterMetal.rvmat"}},{0.5,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Black_Damage.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_WinterMetal_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Black_Damage.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_WinterMetal_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_Black_Destruct.rvmat","AsmondWeapons\Weapons\SV98\Data\Asmond_SV98_WinterMetal_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SVD_Winter;
	class SVD_Winter: Asmond_SVD_Winter { scope=2; };

	class Asmond_SVD_RedWood;
	class SVD_RedWood: Asmond_SVD_RedWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\svd\data\SVD.rvmat"}},{0.7,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_RedWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_RedWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_RedWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_RedWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SVD_Yellow;
	class SVD_Yellow: Asmond_SVD_Yellow
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\svd\data\SVD_old.rvmat"}},{0.7,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_Yellow.rvmat"}},{0.5,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_Yellow_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_Yellow_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_Yellow_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_SVD_Camo;
	class SVD_Camo: Asmond_SVD_Camo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\svd\data\SVD_old.rvmat"}},{0.7,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_Camo.rvmat"}},{0.5,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_Camo_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_Camo_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\SVD\Data\Asmond_SVD_Camo_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_UMP45_Sand;
	class UMP45_Sand: Asmond_UMP45_Sand { scope=2; };

	class Asmond_UMP45_Green;
	class UMP45_Green: Asmond_UMP45_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\UMP45\data\ump45.rvmat"}},{0.7,{"AsmondWeapons\Weapons\UMP45\Data\Asmond_UMP45_Green.rvmat"}},{0.5,{"AsmondWeapons\Weapons\UMP45\Data\Asmond_UMP45_Green_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\UMP45\Data\Asmond_UMP45_Green_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\UMP45\Data\Asmond_UMP45_Green_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_UMP45_Grey;
	class UMP45_Grey: Asmond_UMP45_Grey { scope=2; };

	class Asmond_UMP45_Winter;
	class UMP45_Winter: Asmond_UMP45_Winter { scope=2; };

	class Asmond_Vikhr_Red;
	class Vikhr_Red: Asmond_Vikhr_Red { scope=2; };

	class Asmond_Vikhr_Winter;
	class Vikhr_Winter: Asmond_Vikhr_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\VSS\data\vikhr.rvmat"}},{0.7,{"AsmondWeapons\Weapons\VIKHR\Data\Asmond_Vikhr_White.rvmat"}},{0.5,{"AsmondWeapons\Weapons\VIKHR\Data\Asmond_Vikhr_White_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\VIKHR\Data\Asmond_Vikhr_White_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\VIKHR\Data\Asmond_Vikhr_White_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_VSS_Black;
	class VSS_Black: Asmond_VSS_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\VSS\data\vss.rvmat"}},{0.7,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_VSS_Winter;
	class VSS_Winter: Asmond_VSS_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\VSS\data\vss.rvmat"}},{0.7,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Winter.rvmat"}},{0.5,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Winter_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Winter_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Winter_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_VSS_Stalker;
	class VSS_Stalker: Asmond_VSS_Stalker
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\VSS\data\vss.rvmat"}},{0.7,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Stalker.rvmat"}},{0.5,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Stalker_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Stalker_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Stalker_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_VSS_Yellow;
	class VSS_Yellow: Asmond_VSS_Yellow
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\firearms\VSS\data\vss.rvmat"}},{0.7,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Yellow.rvmat"}},{0.5,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Yellow_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Yellow_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\VSS\Data\Asmond_VSS_Yellow_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Winchester70_Beige;
	class Winchester70_Beige: Asmond_Winchester70_Beige { scope=2; };

	class Asmond_Winchester70_Green;
	class Winchester70_Green_2: Asmond_Winchester70_Green { scope=2; };

	class Asmond_Winchester70_RedWood;
	class Winchester70_RedWood: Asmond_Winchester70_RedWood { scope=2; };

	class Asmond_Winchester70_Winter;
	class Winchester70_Winter: Asmond_Winchester70_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\winchester70\data\winchester70.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Winchester\Data\Asmond_Winchester70_Winter.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Winchester\Data\Asmond_Winchester70_Winter_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Winchester\Data\Asmond_Winchester70_Winter_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Winchester\Data\Asmond_Winchester70_Winter_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Winchester70_Black;
	class Winchester70_Black_2: Asmond_Winchester70_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\winchester70\data\winchester70.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Winchester\Data\Asmond_Winchester70_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Winchester\Data\Asmond_Winchester70_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Winchester\Data\Asmond_Winchester70_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Winchester\Data\Asmond_Winchester70_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

};
