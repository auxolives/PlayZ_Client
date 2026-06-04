class CfgPatches
{
	class PlayZAsmond_tops
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters_Tops",
			"PlayZAsmond",
			"AsmondClothing",
		};
	};
};

class CfgVehicles
{
	class Blouse_ColorBase;
	class BomberJacket_ColorBase;
	class BushlatPoliceJacket_ColorBase;
	class Chainmail;
	class ChernarusSportShirt;
	class DenimJacket;
	class DownJacket_ColorBase;
	class FirefighterJacket_ColorBase;
	class GorkaEJacket_ColorBase;
	class GulagJacket_ColorBase;
	class HikingJacket_ColorBase;
	class Hoodie_ColorBase;
	class HuntingJacket_ColorBase;
	class JumpsuitJacket_ColorBase;
	class M65Jacket_ColorBase;
	class MedicalScrubsShirt_ColorBase;
	class MilitarySweater_ColorBase;
	class NBCJacketBase;
	class NavyUniformJacket;
	class ParamedicJacket_ColorBase;
	class PilotJacket_ColorBase;
	class PoliceJacket;
	class PoliceJacketOrel;
	class PrisonUniformJacket;
	class QuiltedJacket_ColorBase;
	class RidersJacket_ColorBase;
	class Shirt_ColorBase;
	class Sweater_ColorBase;
	class TShirt_ColorBase;
	class TTsKOJacket_ColorBase;
	class TacticalShirt_ColorBase;
	class TelnyashkaShirt;
	class TrackSuitJacket_ColorBase;
	class USMCJacket_ColorBase;
	class WinterMilitaryCoat_ColorBase;
	class WoolCoat_ColorBase;

	class Asmond_Blouse_King;
	class Blouse_King: Asmond_Blouse_King { scope=2; };

	class Asmond_Blouse_Green;
	class Blouse_Green_2: Asmond_Blouse_Green { scope=2; };

	class Asmond_Blouse_Grey;
	class Blouse_Grey: Asmond_Blouse_Grey { scope=2; };

	class Asmond_Blouse_Cyan;
	class Blouse_Cyan: Asmond_Blouse_Cyan { scope=2; };

	class Asmond_Blouse_Blue;
	class Blouse_Blue_2: Asmond_Blouse_Blue { scope=2; };

	class Asmond_Blouse_Brown;
	class Blouse_Brown: Asmond_Blouse_Brown { scope=2; };

	class Asmond_BomberJacket_Maroon;
	class BomberJacket_Maroon_2: Asmond_BomberJacket_Maroon
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\BomberJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BomberJacket_Pink;
	class BomberJacket_Pink: Asmond_BomberJacket_Pink
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\BomberJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BomberJacket_Green;
	class BomberJacket_Green: Asmond_BomberJacket_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\BomberJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BomberJacket_Brown;
	class BomberJacket_Brown_2: Asmond_BomberJacket_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\BomberJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BomberJacket_Winter;
	class BomberJacket_Winter: Asmond_BomberJacket_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\BomberJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Opaque_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BomberJacket_Camo;
	class BomberJacket_Camo: Asmond_BomberJacket_Camo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\BomberJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BomberJacket_Yellow;
	class BomberJacket_Yellow: Asmond_BomberJacket_Yellow
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\BomberJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BomberJacket_White;
	class BomberJacket_White: Asmond_BomberJacket_White
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\BomberJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BomberJacket\Data\Asmond_BomberJacket_Patch_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BushlatJacket_Arctic;
	class BushlatPoliceJacket_Arctic: Asmond_BushlatJacket_Arctic
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\bushlatPoliceJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Snow.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Snow_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Snow_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Snow_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BushlatJacket_Green;
	class BushlatPoliceJacket_Green: Asmond_BushlatJacket_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\bushlatPoliceJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Green.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Green_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Green_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Green_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BushlatJacket_VSRFlora;
	class BushlatPoliceJacket_VSRFlora: Asmond_BushlatJacket_VSRFlora
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\bushlatPoliceJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_VSR.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_VSR_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_VSR_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_VSR_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BushlatJacket_Brown;
	class BushlatPoliceJacket_Brown: Asmond_BushlatJacket_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\bushlatPoliceJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Brown.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Brown_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Brown_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Brown_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BushlatJacket_Grey;
	class BushlatPoliceJacket_Grey: Asmond_BushlatJacket_Grey
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\bushlatPoliceJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_VSR.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_VSR_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_VSR_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_VSR_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_BushlatJacket_Orel;
	class BushlatPoliceJacket_Orel: Asmond_BushlatJacket_Orel { scope=2; };

	class Asmond_BushlatJacket_Winter;
	class BushlatPoliceJacket_Winter: Asmond_BushlatJacket_Winter { scope=2; };

	class Asmond_BushlatJacket_Orange;
	class BushlatPoliceJacket_Orange: Asmond_BushlatJacket_Orange
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\bushlatPoliceJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Orange.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Orange_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Orange_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\BushlatJacket\Data\Asmond_BushlatJacket_Orange_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CasualShirt_Base;
	class PrisonUniformJacket_Base: Asmond_CasualShirt_Base
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\prison_top.rvmat","DZ\characters\tops\Data\prison_top_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\CasualShirt\Data\Asmond_CasualShirt.rvmat","AsmondClothing\Data\Tops\CasualShirt\Data\Asmond_CasualShirt_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\CasualShirt\Data\Asmond_CasualShirt_Damage.rvmat","AsmondClothing\Data\Tops\CasualShirt\Data\Asmond_CasualShirt_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\CasualShirt\Data\Asmond_CasualShirt_Damage.rvmat","AsmondClothing\Data\Tops\CasualShirt\Data\Asmond_CasualShirt_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\CasualShirt\Data\Asmond_CasualShirt_Destruct.rvmat","AsmondClothing\Data\Tops\CasualShirt\Data\Asmond_CasualShirt_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CasualShirt_Beige;
	class PrisonUniformJacket_Beige: Asmond_CasualShirt_Beige { scope=2; };

	class Asmond_CasualShirt_Grey;
	class PrisonUniformJacket_Grey: Asmond_CasualShirt_Grey { scope=2; };

	class Asmond_CasualShirt_Cyan;
	class PrisonUniformJacket_Cyan: Asmond_CasualShirt_Cyan { scope=2; };

	class Asmond_CasualShirt_Blue;
	class PrisonUniformJacket_Blue: Asmond_CasualShirt_Blue { scope=2; };

	class Asmond_Chainmail_King;
	class Chainmail_King: Asmond_Chainmail_King { scope=2; };

	class Asmond_Chainmail_Rebels;
	class Chainmail_Rebels: Asmond_Chainmail_Rebels { scope=2; };

	class Asmond_DenimJacket_Snake;
	class DenimJacket_Snake: Asmond_DenimJacket_Snake
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\denim_jacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Snake.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Snake_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Snake_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Snake_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_DenimJacket_Light;
	class DenimJacket_Light: Asmond_DenimJacket_Light
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\denim_jacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_DenimJacket_BrownGrey;
	class DenimJacket_BrownGrey: Asmond_DenimJacket_BrownGrey
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\denim_jacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_DenimJacket_Wolf;
	class DenimJacket_Wolf: Asmond_DenimJacket_Wolf
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\denim_jacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Wolf.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Wolf_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Wolf_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Wolf_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_DenimJacket_Black;
	class DenimJacket_Black: Asmond_DenimJacket_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\denim_jacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_DenimJacket_Green;
	class DenimJacket_Green: Asmond_DenimJacket_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\denim_jacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\DenimJacket\Data\Asmond_DenimJacket_Light_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_DownJacket_Base;
	class DownJacket_Base: Asmond_DownJacket_Base
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\DownJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\DownJacket\Data\Asmond_DownJacket_Plane.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\DownJacket\Data\Asmond_DownJacket_Plane_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\DownJacket\Data\Asmond_DownJacket_Plane_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\DownJacket\Data\Asmond_DownJacket_Plane_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_DownJacket_Grey;
	class DownJacket_Grey: Asmond_DownJacket_Grey { scope=2; };

	class Asmond_DownJacket_Orange;
	class DownJacket_Orange_2: Asmond_DownJacket_Orange { scope=2; };

	class Asmond_DownJacket_Winter;
	class DownJacket_Winter: Asmond_DownJacket_Winter { scope=2; };

	class Asmond_DownJacket_GreenBrown;
	class DownJacket_GreenBrown: Asmond_DownJacket_GreenBrown { scope=2; };

	class Asmond_DownJacket_Black;
	class DownJacket_Black: Asmond_DownJacket_Black { scope=2; };

	class Asmond_DownJacket_White;
	class DownJacket_White: Asmond_DownJacket_White { scope=2; };

	class Asmond_FirefighterJacket_Blue;
	class FirefighterJacket_Blue: Asmond_FirefighterJacket_Blue
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 180;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\Firefighter_jacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\FirefighterJacket\Data\Asmond_FirefighterJacket.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\FirefighterJacket\Data\Asmond_FirefighterJacket_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\FirefighterJacket\Data\Asmond_FirefighterJacket_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\FirefighterJacket\Data\Asmond_FirefighterJacket_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_FirefighterJacket_Green;
	class FirefighterJacket_Green: Asmond_FirefighterJacket_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 180;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\Firefighter_jacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\FirefighterJacket\Data\Asmond_FirefighterJacket.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\FirefighterJacket\Data\Asmond_FirefighterJacket_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\FirefighterJacket\Data\Asmond_FirefighterJacket_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\FirefighterJacket\Data\Asmond_FirefighterJacket_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_FirefighterJacket_Orange;
	class FirefighterJacket_Orange: Asmond_FirefighterJacket_Orange { scope=2; };

	class Asmond_GasStationJacket_Base;
	class ParamedicJacket_GasStation_Base: Asmond_GasStationJacket_Base
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
						};
					};
				};
	};

	class Asmond_GasStationJacket_YPF;
	class ParamedicJacket_GasStation_YPF: Asmond_GasStationJacket_YPF { scope=2; };

	class Asmond_GasStationJacket_Chernarus;
	class ParamedicJacket_GasStation_Chernarus: Asmond_GasStationJacket_Chernarus { scope=2; };

	class Asmond_GasStationJacket_Livonia;
	class ParamedicJacket_GasStation_Livonia: Asmond_GasStationJacket_Livonia { scope=2; };

	class Asmond_GorkaJacket_M05;
	class GorkaEJacket_M05: Asmond_GorkaJacket_M05
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_FullAutumn;
	class GorkaEJacket_FullAutumn: Asmond_GorkaJacket_FullAutumn
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_Combat;
	class GorkaEJacket_Combat: Asmond_GorkaJacket_Combat
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_Snow;
	class GorkaEJacket_Snow: Asmond_GorkaJacket_Snow
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_Flecktarn;
	class GorkaEJacket_Flecktarn: Asmond_GorkaJacket_Flecktarn
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_RedDawn;
	class GorkaEJacket_RedDawn: Asmond_GorkaJacket_RedDawn
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Patch.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Patch_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Patch_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Patch_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_Partizan;
	class GorkaEJacket_Partizan: Asmond_GorkaJacket_Partizan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_Berezka;
	class GorkaEJacket_Berezka: Asmond_GorkaJacket_Berezka
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_BDU;
	class GorkaEJacket_BDU: Asmond_GorkaJacket_BDU
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_Spetsnaz;
	class GorkaEJacket_Spetsnaz: Asmond_GorkaJacket_Spetsnaz
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_TTSKO;
	class GorkaEJacket_TTSKO: Asmond_GorkaJacket_TTSKO
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_WinterBerezka;
	class GorkaEJacket_WinterBerezka: Asmond_GorkaJacket_WinterBerezka
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GorkaJacket_EMR;
	class GorkaEJacket_EMR: Asmond_GorkaJacket_EMR
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 130;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\GorkaUpper.rvmat","DZ\characters\tops\Data\GorkaUpper_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Damage.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_Destruct.rvmat","AsmondClothing\Data\Tops\GorkaJacket\Data\Asmond_GorkaEJacket_Opaque_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GulagJacket_Green;
	class GulagJacket_Green: Asmond_GulagJacket_Green { scope=2; };

	class Asmond_GulagJacket_White;
	class GulagJacket_White: Asmond_GulagJacket_White { scope=2; };

	class Asmond_GulagJacket_Black;
	class GulagJacket_Black: Asmond_GulagJacket_Black { scope=2; };

	class Asmond_GulagJacket_Brown;
	class GulagJacket_Brown: Asmond_GulagJacket_Brown { scope=2; };

	class Asmond_GulagJacket_Blue;
	class GulagJacket_Blue: Asmond_GulagJacket_Blue { scope=2; };

	class Asmond_HeavyMilitaryJacket_Base;
	class USMCJacket_Base: Asmond_HeavyMilitaryJacket_Base { scope=2; };

	class Asmond_HeavyMilitaryJacket_BlackMulticam;
	class USMCJacket_BlackMulticam: Asmond_HeavyMilitaryJacket_BlackMulticam { scope=2; };

	class Asmond_HeavyMilitaryJacket_ACU;
	class USMCJacket_ACU: Asmond_HeavyMilitaryJacket_ACU { scope=2; };

	class Asmond_HeavyMilitaryJacket_Strichtarn;
	class USMCJacket_Strichtarn: Asmond_HeavyMilitaryJacket_Strichtarn { scope=2; };

	class Asmond_HeavyMilitaryJacket_VSR93;
	class USMCJacket_VSR93: Asmond_HeavyMilitaryJacket_VSR93 { scope=2; };

	class Asmond_HeavyMilitaryJacket_FleckTarn;
	class USMCJacket_FleckTarn: Asmond_HeavyMilitaryJacket_FleckTarn { scope=2; };

	class Asmond_HeavyMilitaryJacket_TropenTarn;
	class USMCJacket_TropenTarn: Asmond_HeavyMilitaryJacket_TropenTarn { scope=2; };

	class Asmond_HeavyMilitaryJacket_WZ93;
	class USMCJacket_WZ93: Asmond_HeavyMilitaryJacket_WZ93 { scope=2; };

	class Asmond_HikingJacket_Yellow;
	class HikingJacket_Yellow: Asmond_HikingJacket_Yellow
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\PCU5Jacket_nopatches.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_NoBackLines.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_NoBackLines_Damage.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_NoBackLines_Damage.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_NoBackLines_Destruct.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_HikingJacket_WhiteCamo;
	class HikingJacket_WhiteCamo: Asmond_HikingJacket_WhiteCamo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\PCU5Jacket_nopatches.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_FrontOnly.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_FrontOnly_Damage.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_FrontOnly_Damage.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_FrontOnly_Destruct.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_HikingJacket_Brown;
	class HikingJacket_Brown: Asmond_HikingJacket_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 150;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\PCU5Jacket_nopatches.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_NoBackLines.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_NoBackLines_Damage.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_NoBackLines_Damage.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\HikingJacket\Data\Asmond_HikingJacket_NoBackLines_Destruct.rvmat","DZ\characters\tops\Data\PCU5Jacket_ground_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_HikingJacket_GreyBlue;
	class HikingJacket_GreyBlue: Asmond_HikingJacket_GreyBlue { scope=2; };

	class Asmond_Hoodie_ACU;
	class Hoodie_ACU: Asmond_Hoodie_ACU { scope=2; };

	class Asmond_Hoodie_BlackWhite;
	class Hoodie_BlackWhite: Asmond_Hoodie_BlackWhite { scope=2; };

	class Asmond_Hoodie_Red;
	class Hoodie_Red_2: Asmond_Hoodie_Red { scope=2; };

	class Asmond_Hoodie_Mustard;
	class Hoodie_Mustard: Asmond_Hoodie_Mustard { scope=2; };

	class Asmond_Hoodie_BDU;
	class Hoodie_BDU: Asmond_Hoodie_BDU { scope=2; };

	class Asmond_Hoodie_Blue;
	class Hoodie_Blue_2: Asmond_Hoodie_Blue { scope=2; };

	class Asmond_Hoodie_Brown;
	class Hoodie_Brown_2: Asmond_Hoodie_Brown { scope=2; };

	class Asmond_Hoodie_Black;
	class Hoodie_Black_2: Asmond_Hoodie_Black { scope=2; };

	class Asmond_Hoodie_Green;
	class Hoodie_Green_2: Asmond_Hoodie_Green { scope=2; };

	class Asmond_Hoodie_Beige;
	class Hoodie_Beige: Asmond_Hoodie_Beige { scope=2; };

	class Asmond_HuntingJacket_Camo;
	class HuntingJacket_Camo: Asmond_HuntingJacket_Camo { scope=2; };

	class Asmond_HuntingJacket_Beige;
	class HuntingJacket_Beige: Asmond_HuntingJacket_Beige { scope=2; };

	class Asmond_HuntingJacket_Grey;
	class HuntingJacket_Grey: Asmond_HuntingJacket_Grey { scope=2; };

	class Asmond_HuntingJacket_Winter;
	class HuntingJacket_Winter_2: Asmond_HuntingJacket_Winter { scope=2; };

	class Asmond_HuntingJacket_Hunter;
	class HuntingJacket_Hunter: Asmond_HuntingJacket_Hunter { scope=2; };

	class Asmond_HuntingJacket_White;
	class HuntingJacket_White: Asmond_HuntingJacket_White { scope=2; };

	class Asmond_JumpsuitJacket_Black;
	class JumpsuitJacket_Black: Asmond_JumpsuitJacket_Black { scope=2; };

	class Asmond_JumpsuitJacket_Light;
	class JumpsuitJacket_Light: Asmond_JumpsuitJacket_Light { scope=2; };

	class Asmond_JumpsuitJacket_Brown;
	class JumpsuitJacket_Brown: Asmond_JumpsuitJacket_Brown { scope=2; };

	class Asmond_LightMilitaryJacket_Base;
	class ParamedicJacket_LightMilitary_Base: Asmond_LightMilitaryJacket_Base
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\Paramedic_Jacket.rvmat","DZ\characters\tops\Data\Paramedic_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\LightMilitaryJacket\Data\Asmond_LightMilitaryJacket.rvmat","AsmondClothing\Data\Tops\LightMilitaryJacket\Data\Asmond_LightMilitaryJacket_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\LightMilitaryJacket\Data\Asmond_LightMilitaryJacket_Damage.rvmat","AsmondClothing\Data\Tops\LightMilitaryJacket\Data\Asmond_LightMilitaryJacket_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\LightMilitaryJacket\Data\Asmond_LightMilitaryJacket_Damage.rvmat","AsmondClothing\Data\Tops\LightMilitaryJacket\Data\Asmond_LightMilitaryJacket_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\LightMilitaryJacket\Data\Asmond_LightMilitaryJacket_Destruct.rvmat","AsmondClothing\Data\Tops\LightMilitaryJacket\Data\Asmond_LightMilitaryJacket_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_LightMilitaryJacket_TropenTarn;
	class ParamedicJacket_LightMilitary_TropenTarn: Asmond_LightMilitaryJacket_TropenTarn { scope=2; };

	class Asmond_LightMilitaryJacket_BDU;
	class ParamedicJacket_LightMilitary_BDU: Asmond_LightMilitaryJacket_BDU { scope=2; };

	class Asmond_LightMilitaryJacket_WZ93;
	class ParamedicJacket_LightMilitary_WZ93: Asmond_LightMilitaryJacket_WZ93 { scope=2; };

	class Asmond_LightMilitaryJacket_TTSKO;
	class ParamedicJacket_LightMilitary_TTSKO: Asmond_LightMilitaryJacket_TTSKO { scope=2; };

	class Asmond_LightMilitaryJacket_Snow;
	class ParamedicJacket_LightMilitary_Snow: Asmond_LightMilitaryJacket_Snow { scope=2; };

	class Asmond_LightMilitaryJacket_Partizan;
	class ParamedicJacket_LightMilitary_Partizan: Asmond_LightMilitaryJacket_Partizan { scope=2; };

	class Asmond_LightMilitaryJacket_Arctic;
	class ParamedicJacket_LightMilitary_Arctic: Asmond_LightMilitaryJacket_Arctic { scope=2; };

	class Asmond_LightMilitaryJacket_M05;
	class ParamedicJacket_LightMilitary_M05: Asmond_LightMilitaryJacket_M05 { scope=2; };

	class Asmond_LightMilitaryJacket_Desert;
	class ParamedicJacket_LightMilitary_Desert: Asmond_LightMilitaryJacket_Desert { scope=2; };

	class Asmond_LongSleevesShirt_Base;
	class ChernarusSportShirt_LongSleeves_Base: Asmond_LongSleevesShirt_Base
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\Chernarus_sport_shirt.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\LongSleeves\Data\Asmond_LongSleevesShirt_Color.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\LongSleeves\Data\Asmond_LongSleevesShirt_Color_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\LongSleeves\Data\Asmond_LongSleevesShirt_Color_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\LongSleeves\Data\Asmond_LongSleevesShirt_Color_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_LongSleevesShirt_Black;
	class ChernarusSportShirt_LongSleeves_Black: Asmond_LongSleevesShirt_Black { scope=2; };

	class Asmond_LongSleevesShirt_Blue;
	class ChernarusSportShirt_LongSleeves_Blue: Asmond_LongSleevesShirt_Blue { scope=2; };

	class Asmond_LongSleevesShirt_Green;
	class ChernarusSportShirt_LongSleeves_Green: Asmond_LongSleevesShirt_Green { scope=2; };

	class Asmond_LongSleevesShirt_Pink;
	class ChernarusSportShirt_LongSleeves_Pink: Asmond_LongSleevesShirt_Pink { scope=2; };

	class Asmond_LongSleevesShirt_Brown;
	class ChernarusSportShirt_LongSleeves_Brown: Asmond_LongSleevesShirt_Brown { scope=2; };

	class Asmond_LongSleevesShirt_Red;
	class ChernarusSportShirt_LongSleeves_Red: Asmond_LongSleevesShirt_Red { scope=2; };

	class Asmond_M65Jacket_MulticamDark;
	class M65Jacket_MulticamDark: Asmond_M65Jacket_MulticamDark { scope=2; };

	class Asmond_M65Jacket_Multicam;
	class M65Jacket_Multicam: Asmond_M65Jacket_Multicam { scope=2; };

	class Asmond_M65Jacket_ACU;
	class M65Jacket_ACU: Asmond_M65Jacket_ACU
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 180;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\M65_Jacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\M65Jacket\Data\Asmond_M65Jacket_ACU.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\M65Jacket\Data\Asmond_M65Jacket_ACU_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\M65Jacket\Data\Asmond_M65Jacket_ACU_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\M65Jacket\Data\Asmond_M65Jacket_ACU_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_M65Jacket_Winter;
	class M65Jacket_Winter: Asmond_M65Jacket_Winter { scope=2; };

	class Asmond_M65Jacket_BDU;
	class M65Jacket_BDU: Asmond_M65Jacket_BDU { scope=2; };

	class Asmond_M65Jacket_Brown;
	class M65Jacket_Brown: Asmond_M65Jacket_Brown { scope=2; };

	class Asmond_M65Jacket_Grey;
	class M65Jacket_Grey: Asmond_M65Jacket_Grey { scope=2; };

	class Asmond_M65Jacket_TTSKO;
	class M65Jacket_TTSKO: Asmond_M65Jacket_TTSKO { scope=2; };

	class Asmond_MedicalScrubsShirt_Black;
	class MedicalScrubsShirt_Black: Asmond_MedicalScrubsShirt_Black { scope=2; };

	class Asmond_MedicalScrubsShirt_Blue;
	class MedicalScrubsShirt_Blue_2: Asmond_MedicalScrubsShirt_Blue { scope=2; };

	class Asmond_MedicalScrubsShirt_Red;
	class MedicalScrubsShirt_Red: Asmond_MedicalScrubsShirt_Red { scope=2; };

	class Asmond_MilitarySweater_Stalker;
	class MilitarySweater_Stalker: Asmond_MilitarySweater_Stalker
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\MilitarySweater_nopatch.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitarySweater_ACU;
	class MilitarySweater_ACU: Asmond_MilitarySweater_ACU
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\MilitarySweater_nopatch.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitarySweater_VSRFlora;
	class MilitarySweater_VSRFlora: Asmond_MilitarySweater_VSRFlora
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\MilitarySweater_nopatch.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitarySweater_White;
	class MilitarySweater_White: Asmond_MilitarySweater_White
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\MilitarySweater_nopatch.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitarySweater_Tiger;
	class MilitarySweater_Tiger: Asmond_MilitarySweater_Tiger { scope=2; };

	class Asmond_MilitarySweater_Partizan;
	class MilitarySweater_Partizan: Asmond_MilitarySweater_Partizan { scope=2; };

	class Asmond_MilitarySweater_Woodland;
	class MilitarySweater_Woodland: Asmond_MilitarySweater_Woodland { scope=2; };

	class Asmond_MilitarySweater_Winter;
	class MilitarySweater_Winter: Asmond_MilitarySweater_Winter { scope=2; };

	class Asmond_MilitarySweater_Orel;
	class MilitarySweater_Orel: Asmond_MilitarySweater_Orel
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\MilitarySweater_nopatch.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitarySweater_Black;
	class MilitarySweater_Black: Asmond_MilitarySweater_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\MilitarySweater_nopatch.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitarySweater_Green;
	class MilitarySweater_Green: Asmond_MilitarySweater_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\MilitarySweater_nopatch.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitarySweater_Blue;
	class MilitarySweater_Blue: Asmond_MilitarySweater_Blue
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\MilitarySweater_nopatch.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitarySweater_Red;
	class MilitarySweater_Red: Asmond_MilitarySweater_Red
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\MilitarySweater_nopatch.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitarySweater_BDU;
	class MilitarySweater_BDU: Asmond_MilitarySweater_BDU
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\MilitarySweater_nopatch.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\MilitarySweater\Data\Asmond_MilitarySweater_Civil_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_MilitarySweater_TTSKO;
	class MilitarySweater_TTSKO: Asmond_MilitarySweater_TTSKO { scope=2; };

	class Asmond_MilitarySweater_Desert;
	class MilitarySweater_Desert: Asmond_MilitarySweater_Desert { scope=2; };

	class Asmond_MilitarySweater_VSR93;
	class MilitarySweater_VSR93: Asmond_MilitarySweater_VSR93 { scope=2; };

	class Asmond_NavyUniformJacket_Military;
	class NavyUniformJacket_Military: Asmond_NavyUniformJacket_Military
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\WoolCoat.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\NavyUniform\Data\Asmond_NavyUniformJacket_Military.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\NavyUniform\Data\Asmond_NavyUniformJacket_Military_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\NavyUniform\Data\Asmond_NavyUniformJacket_Military_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\NavyUniform\Data\Asmond_NavyUniformJacket_Military_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_NavyUniformJacket_Soviet;
	class NavyUniformJacket_Soviet: Asmond_NavyUniformJacket_Soviet { scope=2; };

	class Asmond_NBCJacket_Blue;
	class NBCJacketBlue: Asmond_NBCJacket_Blue { scope=2; };

	class Asmond_NBCJacket_Orange;
	class NBCJacketOrange: Asmond_NBCJacket_Orange { scope=2; };

	class Asmond_NBCJacket_EMR;
	class NBCJacketEMR: Asmond_NBCJacket_EMR { scope=2; };

	class Asmond_NBCJacket_Camo;
	class NBCJacketCamo: Asmond_NBCJacket_Camo { scope=2; };

	class Asmond_NBCJacket_OZK;
	class NBCJacketOZK: Asmond_NBCJacket_OZK { scope=2; };

	class Asmond_NBCJacket_Grey;
	class NBCJacketGray_2: Asmond_NBCJacket_Grey { scope=2; };

	class Asmond_PoliceJacketCamo_Base;
	class PoliceJacketOrel_Base: Asmond_PoliceJacketCamo_Base
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\PoliceJacket.rvmat","DZ\characters\tops\Data\PoliceJacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\OrelJacket\Data\Asmond_TigerJacket.rvmat","AsmondClothing\Data\Tops\OrelJacket\Data\Asmond_TigerJacket_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\OrelJacket\Data\Asmond_TigerJacket_Damage.rvmat","AsmondClothing\Data\Tops\OrelJacket\Data\Asmond_TigerJacket_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\OrelJacket\Data\Asmond_TigerJacket_Damage.rvmat","AsmondClothing\Data\Tops\OrelJacket\Data\Asmond_TigerJacket_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\OrelJacket\Data\Asmond_TigerJacket_Destruct.rvmat","AsmondClothing\Data\Tops\OrelJacket\Data\Asmond_TigerJacket_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_PoliceJacketCamo_Tiger;
	class PoliceJacketOrel_Tiger: Asmond_PoliceJacketCamo_Tiger { scope=2; };

	class Asmond_PoliceJacketCamo_Orel;
	class PoliceJacketOrel_Camo: Asmond_PoliceJacketCamo_Orel { scope=2; };

	class Asmond_PoliceJacketCamo_VSRFlora;
	class PoliceJacketOrel_VSRFlora: Asmond_PoliceJacketCamo_VSRFlora { scope=2; };

	class Asmond_ParamedicJacket_Black;
	class ParamedicJacket_Black: Asmond_ParamedicJacket_Black { scope=2; };

	class Asmond_PilotJacket_Dark;
	class PilotJacket_Dark: Asmond_PilotJacket_Dark { scope=2; };

	class Asmond_PilotJacket_Green;
	class PilotJacket_Green: Asmond_PilotJacket_Green { scope=2; };

	class Asmond_PilotJacket_Blue;
	class PilotJacket_Blue: Asmond_PilotJacket_Blue { scope=2; };

	class Asmond_PilotJacket_Winter;
	class PilotJacket_Winter: Asmond_PilotJacket_Winter { scope=2; };

	class Asmond_PoliceJacket_Gulag;
	class PoliceJacket_Gulag: Asmond_PoliceJacket_Gulag { scope=2; };

	class Asmond_PoliceJacket_Livonia;
	class PoliceJacket_Livonia: Asmond_PoliceJacket_Livonia { scope=2; };

	class Asmond_PrisonUniformJacket_Livonia;
	class PrisonUniformJacket_Livonia: Asmond_PrisonUniformJacket_Livonia { scope=2; };

	class Asmond_QuiltedJacket_Aquamarine;
	class QuiltedJacket_Aquamarine: Asmond_QuiltedJacket_Aquamarine
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_BlackCamo;
	class QuiltedJacket_BlackCamo: Asmond_QuiltedJacket_BlackCamo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_FullCamo;
	class QuiltedJacket_FullCamo: Asmond_QuiltedJacket_FullCamo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_BlackOrange;
	class QuiltedJacket_BlackOrange: Asmond_QuiltedJacket_BlackOrange
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_BlackWhite;
	class QuiltedJacket_BlackWhite: Asmond_QuiltedJacket_BlackWhite
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_BlueBlue;
	class QuiltedJacket_BlueBlue: Asmond_QuiltedJacket_BlueBlue
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_Maroon;
	class QuiltedJacket_Maroon: Asmond_QuiltedJacket_Maroon
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_BrownBrown;
	class QuiltedJacket_BrownBrown: Asmond_QuiltedJacket_BrownBrown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_BrownCamo;
	class QuiltedJacket_BrownCamo: Asmond_QuiltedJacket_BrownCamo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_GreenWhiteOrange;
	class QuiltedJacket_GreenWhiteOrange: Asmond_QuiltedJacket_GreenWhiteOrange
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_Lime;
	class QuiltedJacket_Lime: Asmond_QuiltedJacket_Lime
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_RedWhiteBlue;
	class QuiltedJacket_RedWhiteBlue: Asmond_QuiltedJacket_RedWhiteBlue
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Catedral_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_Winter;
	class QuiltedJacket_Winter: Asmond_QuiltedJacket_Winter
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_QuiltedJacket_WhiteCamo;
	class QuiltedJacket_WhiteCamo: Asmond_QuiltedJacket_WhiteCamo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\QuiltedJacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\QuiltedJacket\Data\Asmond_QuiltedJacket_Patagonia_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_RidersJacket_Blue;
	class RidersJacket_Blue: Asmond_RidersJacket_Blue { scope=2; };

	class Asmond_RidersJacket_Brown;
	class RidersJacket_Brown: Asmond_RidersJacket_Brown { scope=2; };

	class Asmond_RidersJacket_Grey;
	class RidersJacket_Grey: Asmond_RidersJacket_Grey { scope=2; };

	class Asmond_RidersJacket_LoneWolf;
	class RidersJacket_LoneWolf: Asmond_RidersJacket_LoneWolf
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 170;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\Riders_Jacket.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\RidersJacket\Data\Asmond_RidersJacket_LoneWolf.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\RidersJacket\Data\Asmond_RidersJacket_LoneWolf_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\RidersJacket\Data\Asmond_RidersJacket_LoneWolf_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\RidersJacket\Data\Asmond_RidersJacket_LoneWolf_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Shirt_CheckGreen;
	class Shirt_CheckGreen: Asmond_Shirt_CheckGreen { scope=2; };

	class Asmond_Shirt_CheckRed;
	class Shirt_CheckRed: Asmond_Shirt_CheckRed { scope=2; };

	class Asmond_Shirt_CheckBlue;
	class Shirt_CheckBlue: Asmond_Shirt_CheckBlue { scope=2; };

	class Asmond_Shirt_PlaneYellow;
	class Shirt_PlaneYellow: Asmond_Shirt_PlaneYellow { scope=2; };

	class Asmond_Shirt_PlaneGreen;
	class Shirt_PlaneGreen: Asmond_Shirt_PlaneGreen { scope=2; };

	class Asmond_Shirt_PlaneRed;
	class Shirt_PlaneRed: Asmond_Shirt_PlaneRed { scope=2; };

	class Asmond_Shirt_PlaneBlue;
	class Shirt_PlaneBlue: Asmond_Shirt_PlaneBlue { scope=2; };

	class Asmond_Shirt_PlaneBrown;
	class Shirt_PlaneBrown: Asmond_Shirt_PlaneBrown { scope=2; };

	class Asmond_Shirt_PlaneGrey;
	class Shirt_PlaneGrey: Asmond_Shirt_PlaneGrey { scope=2; };

	class Asmond_Shirt_PlaneWhite;
	class Shirt_PlaneWhite: Asmond_Shirt_PlaneWhite { scope=2; };

	class Asmond_Shirt_PlaneHunter;
	class Shirt_PlaneHunter: Asmond_Shirt_PlaneHunter { scope=2; };

	class Asmond_Shirt_MovieAnotonio;
	class Shirt_MovieAnotonio: Asmond_Shirt_MovieAnotonio { scope=2; };

	class Asmond_Shirt_MovieVice;
	class Shirt_MovieVice: Asmond_Shirt_MovieVice { scope=2; };

	class Asmond_Shirt_MovieYakuza;
	class Shirt_MovieYakuza: Asmond_Shirt_MovieYakuza { scope=2; };

	class Asmond_Shirt_LumberRed;
	class Shirt_LumberRed: Asmond_Shirt_LumberRed { scope=2; };

	class Asmond_Shirt_LumberGrey;
	class Shirt_LumberGrey: Asmond_Shirt_LumberGrey { scope=2; };

	class Asmond_Shirt_LumberWhite;
	class Shirt_LumberWhite: Asmond_Shirt_LumberWhite { scope=2; };

	class Asmond_Shirt_LumberBlue;
	class Shirt_LumberBlue: Asmond_Shirt_LumberBlue { scope=2; };

	class Asmond_Shirt_LumberGreen;
	class Shirt_LumberGreen: Asmond_Shirt_LumberGreen { scope=2; };

	class Asmond_Shirt_LumberYellow;
	class Shirt_LumberYellow: Asmond_Shirt_LumberYellow { scope=2; };

	class Asmond_Sweater_RedBlue;
	class Sweater_RedBlue: Asmond_Sweater_RedBlue { scope=2; };

	class Asmond_Sweater_BlueReal;
	class Sweater_BlueReal: Asmond_Sweater_BlueReal { scope=2; };

	class Asmond_Sweater_Green;
	class Sweater_Green_2: Asmond_Sweater_Green { scope=2; };

	class Asmond_Sweater_Grey;
	class Sweater_Gray: Asmond_Sweater_Grey { scope=2; };

	class Asmond_Sweater_Blue;
	class Sweater_Blue_2: Asmond_Sweater_Blue { scope=2; };

	class Asmond_Sweater_TTSKO;
	class Sweater_TTSKO: Asmond_Sweater_TTSKO { scope=2; };

	class Asmond_Sweater_Yellow;
	class Sweater_Yellow: Asmond_Sweater_Yellow { scope=2; };

	class Asmond_Sweater_TRMZ;
	class Sweater_TRMZ: Asmond_Sweater_TRMZ { scope=2; };

	class Asmond_Sweater_Black;
	class Sweater_Black: Asmond_Sweater_Black { scope=2; };

	class Asmond_TacticalShirt_M05;
	class TacticalShirt_M05: Asmond_TacticalShirt_M05 { scope=2; };

	class Asmond_TacticalShirt_Snow;
	class TacticalShirt_Snow: Asmond_TacticalShirt_Snow { scope=2; };

	class Asmond_TacticalShirt_EMR;
	class TacticalShirt_EMR: Asmond_TacticalShirt_EMR { scope=2; };

	class Asmond_TacticalShirt_Woodland;
	class TacticalShirt_Woodland: Asmond_TacticalShirt_Woodland { scope=2; };

	class Asmond_TacticalShirt_BDU;
	class TacticalShirt_BDU: Asmond_TacticalShirt_BDU { scope=2; };

	class Asmond_TacticalShirt_Grey;
	class TacticalShirt_Grey_2: Asmond_TacticalShirt_Grey { scope=2; };

	class Asmond_TacticalShirt_Multicam;
	class TacticalShirt_Multicam: Asmond_TacticalShirt_Multicam { scope=2; };

	class Asmond_TacticalShirt_MulticamDark;
	class TacticalShirt_MulticamDark: Asmond_TacticalShirt_MulticamDark { scope=2; };

	class Asmond_TacticalShirt_Winter;
	class TacticalShirt_Winter: Asmond_TacticalShirt_Winter { scope=2; };

	class Asmond_TacticalShirt_Desert;
	class TacticalShirt_Desert: Asmond_TacticalShirt_Desert { scope=2; };

	class Asmond_Telnyashka_White;
	class TelnyashkaShirt_White: Asmond_Telnyashka_White { scope=2; };

	class Asmond_Telnyashka_Red;
	class TelnyashkaShirt_Red: Asmond_Telnyashka_Red { scope=2; };

	class Asmond_Telnyashka_Green;
	class TelnyashkaShirt_Green: Asmond_Telnyashka_Green { scope=2; };

	class Asmond_Telnyashka_Beige;
	class TelnyashkaShirt_Beige: Asmond_Telnyashka_Beige { scope=2; };

	class Asmond_ThermalShirt_Base;
	class ChernarusSportShirt_Thermal_Base: Asmond_ThermalShirt_Base
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\Chernarus_sport_shirt.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\ThermalShirt\Data\Asmond_ThermalShirt_Color.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\ThermalShirt\Data\Asmond_ThermalShirt_Color_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\ThermalShirt\Data\Asmond_ThermalShirt_Color_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\ThermalShirt\Data\Asmond_ThermalShirt_Color_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_ThermalShirt_Purple;
	class ChernarusSportShirt_Thermal_Purple: Asmond_ThermalShirt_Purple { scope=2; };

	class Asmond_ThermalShirt_Grey;
	class ChernarusSportShirt_Thermal_Grey: Asmond_ThermalShirt_Grey { scope=2; };

	class Asmond_ThermalShirt_Brown;
	class ChernarusSportShirt_Thermal_Brown: Asmond_ThermalShirt_Brown { scope=2; };

	class Asmond_ThermalShirt_Green;
	class ChernarusSportShirt_Thermal_Green: Asmond_ThermalShirt_Green { scope=2; };

	class Asmond_ThermalShirt_Blue;
	class ChernarusSportShirt_Thermal_Blue: Asmond_ThermalShirt_Blue { scope=2; };

	class Asmond_ThermalShirt_Red;
	class ChernarusSportShirt_Thermal_Red: Asmond_ThermalShirt_Red { scope=2; };

	class Asmond_TrackSuitJacket_Sasha;
	class TrackSuitJacket_Sasha: Asmond_TrackSuitJacket_Sasha
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TrackSuit_Jacket.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Sasha.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Sasha_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Sasha_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Sasha_Destruct.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TrackSuitJacket_Grey;
	class TrackSuitJacket_Grey: Asmond_TrackSuitJacket_Grey
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TrackSuit_Jacket.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Loner.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Loner_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Loner_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Loner_Destruct.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TrackSuitJacket_Loner;
	class TrackSuitJacket_Loner: Asmond_TrackSuitJacket_Loner
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TrackSuit_Jacket.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Loner.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Loner_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Loner_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_Loner_Destruct.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TrackSuitJacket_Brown;
	class TrackSuitJacket_Brown: Asmond_TrackSuitJacket_Brown
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TrackSuit_Jacket.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP_Destruct.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TrackSuitJacket_LightBlue;
	class TrackSuitJacket_LightBlue_2: Asmond_TrackSuitJacket_LightBlue
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TrackSuit_Jacket.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP_Destruct.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TrackSuitJacket_Maroon;
	class TrackSuitJacket_Maroon: Asmond_TrackSuitJacket_Maroon
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 100;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TrackSuit_Jacket.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP_Damage.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TrackSuitJacket\Data\Asmond_TrackSuitJacket_CCCP_Destruct.rvmat","DZ\characters\tops\Data\TrackSuit_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TShirt_BlackWhite;
	class TShirt_BlackWhite: Asmond_TShirt_BlackWhite { scope=2; };

	class Asmond_TShirt_StripesBlue;
	class TShirt_StripesBlue: Asmond_TShirt_StripesBlue { scope=2; };

	class Asmond_TShirt_BrownBrown;
	class TShirt_BrownBrown: Asmond_TShirt_BrownBrown { scope=2; };

	class Asmond_TShirt_LightBlue;
	class TShirt_LightBlue: Asmond_TShirt_LightBlue { scope=2; };

	class Asmond_TShirt_MilitaryBlue;
	class TShirt_MilitaryBlue: Asmond_TShirt_MilitaryBlue { scope=2; };

	class Asmond_TShirt_MilitaryBrown;
	class TShirt_MilitaryBrown: Asmond_TShirt_MilitaryBrown { scope=2; };

	class Asmond_TShirt_MilitaryGreen;
	class TShirt_MilitaryGreen: Asmond_TShirt_MilitaryGreen { scope=2; };

	class Asmond_TShirt_MilitaryGrey;
	class TShirt_MilitaryGrey: Asmond_TShirt_MilitaryGrey { scope=2; };

	class Asmond_TShirt_WhiteBlue;
	class TShirt_WhiteBlue: Asmond_TShirt_WhiteBlue { scope=2; };

	class Asmond_TShirt_WhiteGreen;
	class TShirt_WhiteGreen: Asmond_TShirt_WhiteGreen { scope=2; };

	class Asmond_TShirt_WhitePink;
	class TShirt_WhitePink: Asmond_TShirt_WhitePink { scope=2; };

	class Asmond_TShirt_StripesWhite;
	class TShirt_StripesWhite: Asmond_TShirt_StripesWhite { scope=2; };

	class Asmond_TShirt_StripesGreen;
	class TShirt_StripesGreen: Asmond_TShirt_StripesGreen { scope=2; };

	class Asmond_TTSKOJacket_MountainFlora;
	class TTsKOJacket_MountainFlora: Asmond_TTSKOJacket_MountainFlora
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 180;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TTsKO_Jacket.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Destruct.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TTSKOJacket_VSRFlora;
	class TTsKOJacket_VSRFlora: Asmond_TTSKOJacket_VSRFlora { scope=2; };

	class Asmond_TTSKOJacket_VSR93;
	class TTsKOJacket_VSR93: Asmond_TTSKOJacket_VSR93 { scope=2; };

	class Asmond_TTSKOJacket_Grey;
	class TTsKOJacket_Grey: Asmond_TTSKOJacket_Grey
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 180;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TTsKO_Jacket.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Destruct.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TTSKOJacket_Jigsaw;
	class TTsKOJacket_Jigsaw: Asmond_TTSKOJacket_Jigsaw
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 180;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TTsKO_Jacket.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Destruct.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TTSKOJacket_Green;
	class TTsKOJacket_Green: Asmond_TTSKOJacket_Green { scope=2; };

	class Asmond_TTSKOJacket_Tan;
	class TTsKOJacket_Tan: Asmond_TTSKOJacket_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 180;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TTsKO_Jacket.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Destruct.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TTSKOJacket_BDU;
	class TTsKOJacket_BDU: Asmond_TTSKOJacket_BDU
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 180;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TTsKO_Jacket.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Patch_Destruct.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TTSKOJacket_Flecktarn;
	class TTsKOJacket_Flecktarn: Asmond_TTSKOJacket_Flecktarn { scope=2; };

	class Asmond_TTSKOJacket_WZ93;
	class TTsKOJacket_WZ93: Asmond_TTSKOJacket_WZ93
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 180;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\TTsKO_Jacket.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Flag.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Flag_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Flag_Damage.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TTSKOJacket\Data\Asmond_TTSKOJacket_Flag_Destruct.rvmat","DZ\characters\tops\Data\TTsKO_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TurnoutJacket_Base;
	class ParamedicJacket_Turnout_Base: Asmond_TurnoutJacket_Base
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\Paramedic_Jacket.rvmat","DZ\characters\tops\Data\Paramedic_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\TurnoutJacket\Data\Asmond_TurnoutJacket.rvmat","DZ\characters\tops\Data\Paramedic_Jacket_g.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\TurnoutJacket\Data\Asmond_TurnoutJacket_Damage.rvmat","DZ\characters\tops\Data\Paramedic_Jacket_g_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\TurnoutJacket\Data\Asmond_TurnoutJacket_Damage.rvmat","DZ\characters\tops\Data\Paramedic_Jacket_g_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\TurnoutJacket\Data\Asmond_TurnoutJacket_Destruct.rvmat","DZ\characters\tops\Data\Paramedic_Jacket_g_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_TurnoutJacket_Beige;
	class ParamedicJacket_Turnout_Beige: Asmond_TurnoutJacket_Beige { scope=2; };

	class Asmond_TurnoutJacket_Black;
	class ParamedicJacket_Turnout_Black: Asmond_TurnoutJacket_Black { scope=2; };

	class Asmond_WinterMilitaryCoat_Beige;
	class WinterMilitaryCoat_Beige: Asmond_WinterMilitaryCoat_Beige
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 170;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\WinterMilitaryCoat.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\WinterMilitaryCoat\Data\Asmond_WinterMilitaryCoat.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\WinterMilitaryCoat\Data\Asmond_WinterMilitaryCoat_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\WinterMilitaryCoat\Data\Asmond_WinterMilitaryCoat_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\WinterMilitaryCoat\Data\Asmond_WinterMilitaryCoat_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_WinterMilitaryCoat_NavyBlue;
	class WinterMilitaryCoat_NavyBlue: Asmond_WinterMilitaryCoat_NavyBlue { scope=2; };

	class Asmond_WinterMilitaryCoat_Green;
	class WinterMilitaryCoat_Green: Asmond_WinterMilitaryCoat_Green
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 170;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\WinterMilitaryCoat.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\WinterMilitaryCoat\Data\Asmond_WinterMilitaryCoat.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\WinterMilitaryCoat\Data\Asmond_WinterMilitaryCoat_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\WinterMilitaryCoat\Data\Asmond_WinterMilitaryCoat_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\WinterMilitaryCoat\Data\Asmond_WinterMilitaryCoat_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_WinterMilitaryCoat_URSS;
	class WinterMilitaryCoat_URSS: Asmond_WinterMilitaryCoat_URSS { scope=2; };

	class Asmond_WoolCoat_BlueLine;
	class WoolCoat_BlueLine: Asmond_WoolCoat_BlueLine { scope=2; };

	class Asmond_WoolCoat_BrownWool;
	class WoolCoat_BrownWool: Asmond_WoolCoat_BrownWool { scope=2; };

	class Asmond_WoolCoat_BlueWool;
	class WoolCoat_BlueWool: Asmond_WoolCoat_BlueWool
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 140;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\WoolCoat.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\WoolCoat\Data\Asmond_WoolCoat_Wool.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\WoolCoat\Data\Asmond_WoolCoat_Wool_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\WoolCoat\Data\Asmond_WoolCoat_Wool_damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\WoolCoat\Data\Asmond_WoolCoat_Wool_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_WoolCoat_GreyLine;
	class WoolCoat_GreyLine: Asmond_WoolCoat_GreyLine { scope=2; };

	class Asmond_WorkingJacket_Base;
	class ParamedicJacket_Working_Base: Asmond_WorkingJacket_Base
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 160;
							healthLevels[] = {{1,{"DZ\characters\tops\Data\Paramedic_Jacket.rvmat","DZ\characters\tops\Data\Paramedic_Jacket_g.rvmat"}},{0.7,{"AsmondClothing\Data\Tops\WorkingJacket\Data\Asmond_WorkingJacket.rvmat","AsmondClothing\Data\Tops\WorkingJacket\Data\Asmond_WorkingJacket_G.rvmat"}},{0.5,{"AsmondClothing\Data\Tops\WorkingJacket\Data\Asmond_WorkingJacket_Damage.rvmat","AsmondClothing\Data\Tops\WorkingJacket\Data\Asmond_WorkingJacket_G_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Tops\WorkingJacket\Data\Asmond_WorkingJacket_Damage.rvmat","AsmondClothing\Data\Tops\WorkingJacket\Data\Asmond_WorkingJacket_G_Damage.rvmat"}},{0,{"AsmondClothing\Data\Tops\WorkingJacket\Data\Asmond_WorkingJacket_Destruct.rvmat","AsmondClothing\Data\Tops\WorkingJacket\Data\Asmond_WorkingJacket_G_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_WorkingJacket_Steel;
	class ParamedicJacket_Working_Steel: Asmond_WorkingJacket_Steel { scope=2; };

	class Asmond_WorkingJacket_Beige;
	class ParamedicJacket_Working_Beige: Asmond_WorkingJacket_Beige { scope=2; };

	class Asmond_WorkingJacket_Grey;
	class ParamedicJacket_Working_Grey: Asmond_WorkingJacket_Grey { scope=2; };

	class Asmond_WorkingJacket_Orange;
	class ParamedicJacket_Working_Orange: Asmond_WorkingJacket_Orange { scope=2; };

	class Asmond_WorkingJacket_Green;
	class ParamedicJacket_Working_Green: Asmond_WorkingJacket_Green { scope=2; };

	class Asmond_WorkingJacket_Yellow;
	class ParamedicJacket_Working_Yellow: Asmond_WorkingJacket_Yellow { scope=2; };

};
