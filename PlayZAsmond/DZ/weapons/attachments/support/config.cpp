class CfgPatches
{
	class PlayZAsmond_attachments_support
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Weapons_Supports",
			"PlayZAsmond",
			"AsmondWeapons",
		};
	};
};

class cfgVehicles
{
	class AKS74U_Bttstck;
	class AK_FoldingBttstck;
	class AK_PlasticBttstck;
	class AK_PlasticHndgrd;
	class AK_RailHndgrd;
	class AK_WoodBttstck;
	class AK_WoodHndgrd;
	class Fal_OeBttstck;
	class M4_CQBBttstck;
	class M4_MPBttstck;
	class M4_MPHndgrd;
	class M4_OEBttstck;
	class M4_PlasticHndgrd;
	class M4_RISHndgrd;
	class MP5_PlasticHndgrd;
	class MP5_RailHndgrd;
	class MP5k_StockBttstck;
	class PP19_Bttstck;
	class Saiga_Bttstck;

	class Asmond_AK_PlasticHndgrd_Black;
	class AK_PlasticHndgrd_Black: Asmond_AK_PlasticHndgrd_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_PlasticBttstck_Black;
	class AK_PlasticBttstck_Black_2: Asmond_AK_PlasticBttstck_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_PlasticHndgrd_Winter;
	class AK_PlasticHndgrd_Winter: Asmond_AK_PlasticHndgrd_Winter { scope=2; };

	class Asmond_AK_PlasticBttstck_Winter;
	class AK_PlasticBttstck_Winter: Asmond_AK_PlasticBttstck_Winter { scope=2; };

	class Asmond_AK_PlasticHndgrd_Tan;
	class AK_PlasticHndgrd_Tan: Asmond_AK_PlasticHndgrd_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_PlasticBttstck_Tan;
	class AK_PlasticBttstck_Tan: Asmond_AK_PlasticBttstck_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_PlasticHndgrd_Grey;
	class AK_PlasticHndgrd_Grey: Asmond_AK_PlasticHndgrd_Grey { scope=2; };

	class Asmond_AK_PlasticBttstck_Grey;
	class AK_PlasticBttstck_Grey: Asmond_AK_PlasticBttstck_Grey { scope=2; };

	class Asmond_AK_PlasticHndgrd_Wine;
	class AK_PlasticHndgrd_Wine: Asmond_AK_PlasticHndgrd_Wine
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_PlasticBttstck_Wine;
	class AK_PlasticBttstck_Wine: Asmond_AK_PlasticBttstck_Wine
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_PlasticHndgrd_Green;
	class AK_PlasticHndgrd_Green: Asmond_AK_PlasticHndgrd_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_PlasticBttstck_Green;
	class AK_PlasticBttstck_Green_2: Asmond_AK_PlasticBttstck_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Asmond_AK101_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_AKS74UBttstck_Black;
	class AK_AKS74UBttstck_Black: Asmond_AK_AKS74UBttstck_Black { scope=2; };

	class Asmond_AK_AKS74UBttstck_Winter;
	class AK_AKS74UBttstck_Winter: Asmond_AK_AKS74UBttstck_Winter { scope=2; };

	class Asmond_AK_WoodHndgrd_Natural;
	class AK_WoodHndgrd_Natural: Asmond_AK_WoodHndgrd_Natural
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_WoodBttstck_Natural;
	class AK_WoodBttstck_Natural: Asmond_AK_WoodBttstck_Natural
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_WoodHndgrd_LightWood;
	class AK_WoodHndgrd_LightWood: Asmond_AK_WoodHndgrd_LightWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_WoodBttstck_LightWood;
	class AK_WoodBttstck_LightWood: Asmond_AK_WoodBttstck_LightWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_WoodHndgrd_LightBrown;
	class AK_WoodHndgrd_LightBrown: Asmond_AK_WoodHndgrd_LightBrown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_WoodBttstck_LightBrown;
	class AK_WoodBttstck_LightBrown: Asmond_AK_WoodBttstck_LightBrown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Att\Asmond_AKAtt_LightBrown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_PlasticHndgrd_Desert;
	class AK_PlasticHndgrd_Desert: Asmond_AK_PlasticHndgrd_Desert
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_PlasticBttstck_Desert;
	class AK_PlasticBttstck_Desert: Asmond_AK_PlasticBttstck_Desert
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_PlasticHndgrd_Camo;
	class AK_PlasticHndgrd_Camo: Asmond_AK_PlasticHndgrd_Camo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_PlasticBttstck_Camo;
	class AK_PlasticBttstck_Camo: Asmond_AK_PlasticBttstck_Camo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Asmond_AK74_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_WoodHndgrd_Camo;
	class AK_WoodHndgrd_Camo_2: Asmond_AK_WoodHndgrd_Camo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_WoodBttstck_Camo;
	class AK_WoodBttstck_Camo_2: Asmond_AK_WoodBttstck_Camo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_WoodHndgrd_Yellow;
	class AK_WoodHndgrd_Yellow: Asmond_AK_WoodHndgrd_Yellow
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_WoodBttstck_Yellow;
	class AK_WoodBttstck_Yellow: Asmond_AK_WoodBttstck_Yellow
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_WoodHndgrd_DarkWood;
	class AK_WoodHndgrd_DarkWood: Asmond_AK_WoodHndgrd_DarkWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_WoodBttstck_DarkWood;
	class AK_WoodBttstck_DarkWood: Asmond_AK_WoodBttstck_DarkWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_wood.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMYellow_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_RailHndgrd_Winter;
	class AK_RailHndgrd_Winter: Asmond_AK_RailHndgrd_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_accessories.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_RailHndgrd_Green;
	class AK_RailHndgrd_Green_2: Asmond_AK_RailHndgrd_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_accessories.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_FoldingBttstck_Winter;
	class AK_FoldingBttstck_Winter: Asmond_AK_FoldingBttstck_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_accessories.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_AK_FoldingBttstck_Green;
	class AK_FoldingBttstck_Green_2: Asmond_AK_FoldingBttstck_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 300;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_accessories.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_PP19_Buttstock_Red;
	class PP19_Buttstock_Red: Asmond_PP19_Buttstock_Red { scope=2; };

	class Asmond_PP19_Buttstock_Black;
	class PP19_Buttstock_Black: Asmond_PP19_Buttstock_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\attachments\support\data\buttstock_PP_19.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Bizon_Black_Buttstock.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Bizon_Black_Buttstock_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Bizon_Black_Buttstock_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Bizon_Black_Buttstock_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_FAL_Buttstock_DarkWood;
	class FAL_Buttstock_DarkWood: Asmond_FAL_Buttstock_DarkWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\attachments\support\data\FAL_stock_oe.rvmat"}},{0.7,{"AsmondWeapons\Weapons\FAL\Data\Att\Asmond_FAL_Buttstock_DarkWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\FAL\Data\Att\Asmond_FAL_Buttstock_DarkWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\FAL\Data\Att\Asmond_FAL_Buttstock_DarkWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\FAL\Data\Att\Asmond_FAL_Buttstock_DarkWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_FAL_Buttstock_Moss;
	class FAL_Buttstock_Moss: Asmond_FAL_Buttstock_Moss { scope=2; };

	class Asmond_FAL_Buttstock_Winter;
	class FAL_Buttstock_Winter: Asmond_FAL_Buttstock_Winter { scope=2; };

	class Asmond_FAL_Buttstock_LightWood;
	class FAL_Buttstock_LightWood: Asmond_FAL_Buttstock_LightWood
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\attachments\support\data\FAL_stock_oe.rvmat"}},{0.7,{"AsmondWeapons\Weapons\FAL\Data\Att\Asmond_FAL_Buttstock_DarkWood.rvmat"}},{0.5,{"AsmondWeapons\Weapons\FAL\Data\Att\Asmond_FAL_Buttstock_DarkWood_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\FAL\Data\Att\Asmond_FAL_Buttstock_DarkWood_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\FAL\Data\Att\Asmond_FAL_Buttstock_DarkWood_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M4_PlasticHndgrd_Tan;
	class M4_PlasticHndgrd_Tan: Asmond_M4_PlasticHndgrd_Tan { scope=2; };

	class Asmond_M4_PlasticHndgrd_Green;
	class M4_PlasticHndgrd_Green_2: Asmond_M4_PlasticHndgrd_Green { scope=2; };

	class Asmond_M4_PlasticHndgrd_Grey;
	class M4_PlasticHndgrd_Grey: Asmond_M4_PlasticHndgrd_Grey { scope=2; };

	class Asmond_M4_PlasticHndgrd_Black;
	class M4_PlasticHndgrd_Black_2: Asmond_M4_PlasticHndgrd_Black { scope=2; };

	class Asmond_M4_RISHndgrd_Tan;
	class M4_RISHndgrd_Tan: Asmond_M4_RISHndgrd_Tan { scope=2; };

	class Asmond_M4_RISHndgrd_Green;
	class M4_RISHndgrd_Green_2: Asmond_M4_RISHndgrd_Green { scope=2; };

	class Asmond_M4_RISHndgrd_Grey;
	class M4_RISHndgrd_Grey: Asmond_M4_RISHndgrd_Grey { scope=2; };

	class Asmond_M4_RISHndgrd_Black;
	class M4_RISHndgrd_Black_2: Asmond_M4_RISHndgrd_Black { scope=2; };

	class Asmond_M4_MPHndgrd_Tan;
	class M4_MPHndgrd_Tan: Asmond_M4_MPHndgrd_Tan { scope=2; };

	class Asmond_M4_MPHndgrd_Green;
	class M4_MPHndgrd_Green_2: Asmond_M4_MPHndgrd_Green { scope=2; };

	class Asmond_M4_MPHndgrd_Grey;
	class M4_MPHndgrd_Grey: Asmond_M4_MPHndgrd_Grey { scope=2; };

	class Asmond_M4_MPHndgrd_Black;
	class M4_MPHndgrd_Black_2: Asmond_M4_MPHndgrd_Black { scope=2; };

	class Asmond_M4_OEBttstck_Tan;
	class M4_OEBttstck_Tan: Asmond_M4_OEBttstck_Tan { scope=2; };

	class Asmond_M4_OEBttstck_Green;
	class M4_OEBttstck_Green_2: Asmond_M4_OEBttstck_Green { scope=2; };

	class Asmond_M4_OEBttstck_Grey;
	class M4_OEBttstck_Grey: Asmond_M4_OEBttstck_Grey { scope=2; };

	class Asmond_M4_OEBttstck_Black;
	class M4_OEBttstck_Black_2: Asmond_M4_OEBttstck_Black { scope=2; };

	class Asmond_M4_MPBttstck_Tan;
	class M4_MPBttstck_Tan: Asmond_M4_MPBttstck_Tan { scope=2; };

	class Asmond_M4_MPBttstck_Green;
	class M4_MPBttstck_Green_2: Asmond_M4_MPBttstck_Green { scope=2; };

	class Asmond_M4_MPBttstck_Grey;
	class M4_MPBttstck_Grey: Asmond_M4_MPBttstck_Grey { scope=2; };

	class Asmond_M4_MPBttstck_Black;
	class M4_MPBttstck_Black_2: Asmond_M4_MPBttstck_Black { scope=2; };

	class Asmond_M4_CQBBttstck_Tan;
	class M4_CQBBttstck_Tan: Asmond_M4_CQBBttstck_Tan { scope=2; };

	class Asmond_M4_CQBBttstck_Green;
	class M4_CQBBttstck_Green_2: Asmond_M4_CQBBttstck_Green { scope=2; };

	class Asmond_M4_CQBBttstck_Grey;
	class M4_CQBBttstck_Grey: Asmond_M4_CQBBttstck_Grey { scope=2; };

	class Asmond_M4_CQBBttstck_Black;
	class M4_CQBBttstck_Black_2: Asmond_M4_CQBBttstck_Black { scope=2; };

	class Asmond_MP5K_Bttstck_Sand;
	class MP5K_Bttstck_Sand: Asmond_MP5K_Bttstck_Sand
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\MP5k_stock.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Bttstck_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Bttstck_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Bttstck_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Bttstck_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MP5K_PlasticHndgrd_Sand;
	class MP5K_PlasticHndgrd_Sand: Asmond_MP5K_PlasticHndgrd_Sand
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\MP5k_grip01.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_PlasticHndgrd_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_PlasticHndgrd_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_PlasticHndgrd_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_PlasticHndgrd_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MP5K_Bttstck_Black;
	class MP5K_Bttstck_Black: Asmond_MP5K_Bttstck_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 200;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\MP5k_stock.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Bttstck_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Bttstck_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Bttstck_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_Bttstck_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MP5K_PlasticHndgrd_Black;
	class MP5K_PlasticHndgrd_Black: Asmond_MP5K_PlasticHndgrd_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\MP5k_grip01.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_PlasticHndgrd_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_PlasticHndgrd_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_PlasticHndgrd_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_PlasticHndgrd_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MP5K_RailHndgrd_Black;
	class MP5K_RailHndgrd_Black: Asmond_MP5K_RailHndgrd_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\MP5k_grip01.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_RailHndgrd_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_RailHndgrd_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_RailHndgrd_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_RailHndgrd_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MP5K_RailHndgrd_Sand;
	class MP5K_RailHndgrd_Sand: Asmond_MP5K_RailHndgrd_Sand
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\MP5k_grip01.rvmat"}},{0.7,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_RailHndgrd_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_RailHndgrd_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_RailHndgrd_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\MP5K\Data\Asmond_MP5K_RailHndgrd_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Saiga_Red_Bttstck;
	class Saiga_Red_Bttstck: Asmond_Saiga_Red_Bttstck
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 250;
							healthLevels[] = {{1,{"DZ\weapons\attachments\support\data\saiga_folding.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Saiga\Data\Asmond_Saiga_Red_Buttstock.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Saiga\Data\Asmond_Saiga_Red_Buttstock_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Saiga\Data\Asmond_Saiga_Red_Buttstock_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Saiga\Data\Asmond_Saiga_Red_Buttstock_Destruct.rvmat"}}};
						};
					};
				};
	};

};
