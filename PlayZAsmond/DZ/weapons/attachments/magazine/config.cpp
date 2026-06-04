class CfgPatches
{
	class PlayZAsmond_attachments_magazine
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Weapons_Magazines",
			"PlayZAsmond",
			"AsmondWeapons",
		};
	};
};

class CfgMagazines
{
	class Mag_1911_7Rnd;
	class Mag_AK101_30Rnd;
	class Mag_AK74_30Rnd;
	class Mag_AK74_45Rnd;
	class Mag_AKM_30Rnd;
	class Mag_AKM_Drum75Rnd;
	class Mag_AKM_Palm30Rnd;
	class Mag_CMAG_10Rnd;
	class Mag_CMAG_20Rnd;
	class Mag_CMAG_30Rnd;
	class Mag_CMAG_40Rnd;
	class Mag_FAMAS_25Rnd;
	class Mag_PP19_64Rnd;
	class Mag_UMP_25Rnd;
	class Mag_VAL_20Rnd;
	class Mag_VSS_10Rnd;
	class Mag_Vikhr_30Rnd;

	class Asmond_Mag_1911_7Rnd_Black;
	class Mag_1911_7Rnd_Black: Asmond_Mag_1911_7Rnd_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\1911.rvmat"}},{0.7,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Mags\Asmond_Mag_1911_7Rnd_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Mags\Asmond_Mag_1911_7Rnd_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Mags\Asmond_Mag_1911_7Rnd_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Mags\Asmond_Mag_1911_7Rnd_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_1911_7Rnd_Gold;
	class Mag_1911_7Rnd_Gold: Asmond_Mag_1911_7Rnd_Gold
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\1911.rvmat"}},{0.7,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Mags\Asmond_Mag_1911_7Rnd_Gold.rvmat"}},{0.5,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Mags\Asmond_Mag_1911_7Rnd_Gold_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Mags\Asmond_Mag_1911_7Rnd_Gold_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\1911ENGRAVED\Data\Mags\Asmond_Mag_1911_7Rnd_Gold_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK101_30Rnd_Black;
	class Mag_AK101_30Rnd_Black_2: Asmond_Mag_AK101_30Rnd_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK101_30Rnd_Winter;
	class Mag_AK101_30Rnd_Winter: Asmond_Mag_AK101_30Rnd_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK101_30Rnd_Tan;
	class Mag_AK101_30Rnd_Tan: Asmond_Mag_AK101_30Rnd_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK101\Data\Mags\Asmond_AK101_Mag_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK74_45Rnd_Black;
	class Mag_AK74_45Rnd_Black: Asmond_Mag_AK74_45Rnd_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\magazine_ak74_45rnd.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK74_45Rnd_Green;
	class Mag_AK74_45Rnd_Green: Asmond_Mag_AK74_45Rnd_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\magazine_ak74_45rnd.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK74_45Rnd_Tan;
	class Mag_AK74_45Rnd_Tan: Asmond_Mag_AK74_45Rnd_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\magazine_ak74_45rnd.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK74_45Rnd_Black_Taped;
	class Mag_AK74_45Rnd_Black_Taped: Asmond_Mag_AK74_45Rnd_Black_Taped
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\magazine_ak74_45rnd.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Taped.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Taped_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Taped_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_45Rnd_Black_Taped_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK74_30Rnd_Black;
	class Mag_AK74_30Rnd_Black_2: Asmond_Mag_AK74_30Rnd_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\magazine_ak74.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK74_30Rnd_Camo;
	class Mag_AK74_30Rnd_Camo: Asmond_Mag_AK74_30Rnd_Camo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\magazine_ak74.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK74_30Rnd_Tan;
	class Mag_AK74_30Rnd_Tan: Asmond_Mag_AK74_30Rnd_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\magazine_ak74.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Tan.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Tan_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Tan_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Tan_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK74_30Rnd_Winter;
	class Mag_AK74_30Rnd_Winter: Asmond_Mag_AK74_30Rnd_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\magazine_ak74.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AK74_30Rnd_Green;
	class Mag_AK74_30Rnd_Green_2: Asmond_Mag_AK74_30Rnd_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\magazine_ak74.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Tan.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Tan_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Tan_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AK74\Data\Mags\Asmond_Mag_AK74_30Rnd_Tan_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AKM_30Rnd_Winter;
	class Mag_AKM_30Rnd_Winter: Asmond_Mag_AKM_30Rnd_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_steel_mag.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Mags\Asmond_Mag_AKM_30Rnd_Color.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Mags\Asmond_Mag_AKM_30Rnd_Color_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Mags\Asmond_Mag_AKM_30Rnd_Color_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Mags\Asmond_Mag_AKM_30Rnd_Color_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AKM_Palm30Rnd_Winter;
	class Mag_AKM_Palm30Rnd_Winter: Asmond_Mag_AKM_Palm30Rnd_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_accessories.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMWinter_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AKM_Drum75Rnd_Winter;
	class Mag_AKM_Drum75Rnd_Winter: Asmond_Mag_AKM_Drum75Rnd_Winter { scope=2; };

	class Asmond_Mag_AKM_30Rnd_Green;
	class Mag_AKM_30Rnd_Green: Asmond_Mag_AKM_30Rnd_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_steel_mag.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Mags\Asmond_Mag_AKM_30Rnd_Color.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Mags\Asmond_Mag_AKM_30Rnd_Color_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Mags\Asmond_Mag_AKM_30Rnd_Color_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Mags\Asmond_Mag_AKM_30Rnd_Color_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AKM_Palm30Rnd_Green;
	class Mag_AKM_Palm30Rnd_Green_2: Asmond_Mag_AKM_Palm30Rnd_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\akm_accessories.rvmat"}},{0.7,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen.rvmat"}},{0.5,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\AKM\Data\Att\Asmond_AKAtt_AKMGreen_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_AKM_Drum75Rnd_Green;
	class Mag_AKM_Drum75Rnd_Green_2: Asmond_Mag_AKM_Drum75Rnd_Green { scope=2; };

	class Asmond_Mag_VAL_20Rnd_Red;
	class Mag_VAL_20Rnd_Red: Asmond_Mag_VAL_20Rnd_Red
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\val_mag.rvmat"}},{0.7,{"AsmondWeapons\Weapons\ASVAL\Data\Mags\Asmond_Mag_VAL_20Rnd_Red.rvmat"}},{0.5,{"AsmondWeapons\Weapons\ASVAL\Data\Mags\Asmond_Mag_VAL_20Rnd_Red_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\ASVAL\Data\Mags\Asmond_Mag_VAL_20Rnd_Red_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\ASVAL\Data\Mags\Asmond_Mag_VAL_20Rnd_Red_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_PP19_Black;
	class Mag_PP19_64Rnd_Black: Asmond_Mag_PP19_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\magazine_PP_19.rvmat"}},{0.7,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Mag_PP19_Black.rvmat"}},{0.5,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Mag_PP19_Black_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Mag_PP19_Black_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\Bizon\Data\Asmond_Mag_PP19_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_FAMAS_25Rnd_Black;
	class Mag_FAMAS_25Rnd_Black: Asmond_Mag_FAMAS_25Rnd_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\firearms\famas\data\famas_rifle1.rvmat"}},{0.7,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1.rvmat"}},{0.5,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\FAMAS\Data\Asmond_Famas_Black_R1_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_M4A1_10Rnd_Tan;
	class Mag_CMAG_10Rnd_Tan: Asmond_Mag_M4A1_10Rnd_Tan { scope=2; };

	class Asmond_Mag_M4A1_10Rnd_Green;
	class Mag_CMAG_10Rnd_Green_2: Asmond_Mag_M4A1_10Rnd_Green { scope=2; };

	class Asmond_Mag_M4A1_20Rnd_Tan;
	class Mag_CMAG_20Rnd_Tan: Asmond_Mag_M4A1_20Rnd_Tan { scope=2; };

	class Asmond_Mag_M4A1_20Rnd_Green;
	class Mag_CMAG_20Rnd_Green_2: Asmond_Mag_M4A1_20Rnd_Green { scope=2; };

	class Asmond_Mag_M4A1_30Rnd_Tan;
	class Mag_CMAG_30Rnd_Tan: Asmond_Mag_M4A1_30Rnd_Tan { scope=2; };

	class Asmond_Mag_M4A1_30Rnd_Green;
	class Mag_CMAG_30Rnd_Green_2: Asmond_Mag_M4A1_30Rnd_Green { scope=2; };

	class Asmond_Mag_M4A1_40Rnd_Tan;
	class Mag_CMAG_40Rnd_Tan: Asmond_Mag_M4A1_40Rnd_Tan { scope=2; };

	class Asmond_Mag_M4A1_40Rnd_Green;
	class Mag_CMAG_40Rnd_Green_2: Asmond_Mag_M4A1_40Rnd_Green { scope=2; };

	class Asmond_Mag_UMP_25Rnd_Winter;
	class Mag_UMP_25Rnd_Winter: Asmond_Mag_UMP_25Rnd_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\ump45_magazine.rvmat"}},{0.7,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color.rvmat"}},{0.5,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_UMP_25Rnd_Sand;
	class Mag_UMP_25Rnd_Sand: Asmond_Mag_UMP_25Rnd_Sand
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\ump45_magazine.rvmat"}},{0.7,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color.rvmat"}},{0.5,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_UMP_25Rnd_Green;
	class Mag_UMP_25Rnd_Green: Asmond_Mag_UMP_25Rnd_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\ump45_magazine.rvmat"}},{0.7,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color.rvmat"}},{0.5,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\UMP45\Data\Mags\Asmond_Mag_UMP_25Rnd_Color_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_Vikhr_30Rnd_Red;
	class Mag_Vikhr_30Rnd_Red: Asmond_Mag_Vikhr_30Rnd_Red
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\magazine_vikhr_30rnd.rvmat"}},{0.7,{"AsmondWeapons\Weapons\VIKHR\Data\Mags\Asmond_Mag_Vikhr_30Rnd_Red.rvmat"}},{0.5,{"AsmondWeapons\Weapons\VIKHR\Data\Mags\Asmond_Mag_Vikhr_30Rnd_Red_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\VIKHR\Data\Mags\Asmond_Mag_Vikhr_30Rnd_Red_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\VIKHR\Data\Mags\Asmond_Mag_Vikhr_30Rnd_Red_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mag_VSS_10Rnd_Red;
	class Mag_VSS_10Rnd_Red: Asmond_Mag_VSS_10Rnd_Red
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\weapons\attachments\magazine\data\vss_mag.rvmat"}},{0.7,{"AsmondWeapons\Weapons\VSS\Data\Mags\Asmond_Mag_VSS_10Rnd_Red.rvmat"}},{0.5,{"AsmondWeapons\Weapons\VSS\Data\Mags\Asmond_Mag_VSS_10Rnd_Red_Damage.rvmat"}},{0.3,{"AsmondWeapons\Weapons\VSS\Data\Mags\Asmond_Mag_VSS_10Rnd_Red_Damage.rvmat"}},{0,{"AsmondWeapons\Weapons\VSS\Data\Mags\Asmond_Mag_VSS_10Rnd_Red_Destruct.rvmat"}}};
						};
					};
				};
	};

};
