class CfgPatches
{
	class PlayZAsmond_masks
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters_Masks",
			"PlayZAsmond",
			"AsmondClothing",
		};
	};
};

class CfgVehicles
{
	class AirborneMask;
	class Balaclava3Holes_ColorBase;
	class BalaclavaMask_ColorBase;
	class GP5GasMask;
	class GasMask;
	class MimeMask_Male;
	class NioshFaceMask;

	class Asmond_AirborneMask_Grey;
	class AirborneMask_Grey: Asmond_AirborneMask_Grey { scope=2; };

	class Asmond_AirborneMask_Black;
	class AirborneMask_Black: Asmond_AirborneMask_Black { scope=2; };

	class Asmond_AirborneMask_Camo;
	class AirborneMask_Camo: Asmond_AirborneMask_Camo { scope=2; };

	class Asmond_Balaclava3Holes_Brown;
	class Balaclava3Holes_Brown: Asmond_Balaclava3Holes_Brown { scope=2; };

	class Asmond_Balaclava3Holes_Snow;
	class Balaclava3Holes_Snow: Asmond_Balaclava3Holes_Snow { scope=2; };

	class Asmond_Balaclava3Holes_BDU;
	class Balaclava3Holes_BDU: Asmond_Balaclava3Holes_BDU { scope=2; };

	class Asmond_Balaclava3Holes_Partizan;
	class Balaclava3Holes_Partizan: Asmond_Balaclava3Holes_Partizan { scope=2; };

	class Asmond_Balaclava3Holes_OMK;
	class Balaclava3Holes_OMK: Asmond_Balaclava3Holes_OMK { scope=2; };

	class Asmond_Balaclava3Holes_EMR;
	class Balaclava3Holes_EMR: Asmond_Balaclava3Holes_EMR { scope=2; };

	class Asmond_Balaclava3Holes_Grey;
	class Balaclava3Holes_Grey: Asmond_Balaclava3Holes_Grey { scope=2; };

	class Asmond_Balaclava3Holes_Pink;
	class Balaclava3Holes_Pink: Asmond_Balaclava3Holes_Pink { scope=2; };

	class Asmond_Balaclava3Holes_Red;
	class Balaclava3Holes_Red: Asmond_Balaclava3Holes_Red { scope=2; };

	class Asmond_Balaclava3Holes_Turquoise;
	class Balaclava3Holes_Turquoise: Asmond_Balaclava3Holes_Turquoise { scope=2; };

	class Asmond_Balaclava3Holes_Bunker;
	class Balaclava3Holes_Bunker: Asmond_Balaclava3Holes_Bunker { scope=2; };

	class Asmond_Balaclava3Holes_TTSKO;
	class Balaclava3Holes_TTSKO: Asmond_Balaclava3Holes_TTSKO { scope=2; };

	class Asmond_Balaclava3Holes_Hunter;
	class Balaclava3Holes_Hunter: Asmond_Balaclava3Holes_Hunter { scope=2; };

	class Asmond_Balaclava3Holes_Winter;
	class Balaclava3Holes_Winter: Asmond_Balaclava3Holes_Winter { scope=2; };

	class Asmond_Balaclava3Holes_Reindeer;
	class Balaclava3Holes_Reindeer: Asmond_Balaclava3Holes_Reindeer { scope=2; };

	class Asmond_BalaclavaMask_Brown;
	class BalaclavaMask_Brown: Asmond_BalaclavaMask_Brown { scope=2; };

	class Asmond_BalaclavaMask_Snow;
	class BalaclavaMask_Snow: Asmond_BalaclavaMask_Snow { scope=2; };

	class Asmond_BalaclavaMask_BDU;
	class BalaclavaMask_BDU_2: Asmond_BalaclavaMask_BDU { scope=2; };

	class Asmond_BalaclavaMask_Partizan;
	class BalaclavaMask_Partizan: Asmond_BalaclavaMask_Partizan { scope=2; };

	class Asmond_BalaclavaMask_OMK;
	class BalaclavaMask_OMK: Asmond_BalaclavaMask_OMK { scope=2; };

	class Asmond_BalaclavaMask_EMR;
	class BalaclavaMask_EMR: Asmond_BalaclavaMask_EMR { scope=2; };

	class Asmond_BalaclavaMask_Red;
	class BalaclavaMask_Red: Asmond_BalaclavaMask_Red { scope=2; };

	class Asmond_BalaclavaMask_Blue;
	class BalaclavaMask_Blue_2: Asmond_BalaclavaMask_Blue { scope=2; };

	class Asmond_BalaclavaMask_Grey;
	class BalaclavaMask_Grey: Asmond_BalaclavaMask_Grey { scope=2; };

	class Asmond_BalaclavaMask_TTSKO;
	class BalaclavaMask_TTSKO: Asmond_BalaclavaMask_TTSKO { scope=2; };

	class Asmond_BalaclavaMask_Hunter;
	class BalaclavaMask_Hunter: Asmond_BalaclavaMask_Hunter { scope=2; };

	class Asmond_BalaclavaMask_Winter;
	class BalaclavaMask_Winter: Asmond_BalaclavaMask_Winter { scope=2; };

	class Asmond_CombatGasmask_Moss;
	class CombatGasmask_Moss: Asmond_CombatGasmask_Moss { scope=2; };

	class Asmond_CombatGasmask_Camo;
	class CombatGasmask_Camo: Asmond_CombatGasmask_Camo
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\masks\data\GasMask.rvmat","DZ\characters\masks\data\GasMask_Glass.rvmat"}},{0.7,{"AsmondClothing\Data\Masks\CombatGasmask\Data\Asmond_CombatGasmask_Black.rvmat","DZ\characters\masks\data\GasMask_Glass.rvmat"}},{0.5,{"AsmondClothing\Data\Masks\CombatGasmask\Data\Asmond_CombatGasmask_Black_Damage.rvmat","DZ\characters\masks\data\GasMask_Glass_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Masks\CombatGasmask\Data\Asmond_CombatGasmask_Black_Damage.rvmat","DZ\characters\masks\data\GasMask_Glass_damage.rvmat"}},{0,{"AsmondClothing\Data\Masks\CombatGasmask\Data\Asmond_CombatGasmask_Black_Destruct.rvmat","DZ\characters\masks\data\GasMask_Glass_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_CombatGasmask_Black;
	class CombatGasmask_Black: Asmond_CombatGasmask_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 120;
							healthLevels[] = {{1,{"DZ\characters\masks\data\GasMask.rvmat","DZ\characters\masks\data\GasMask_Glass.rvmat"}},{0.7,{"AsmondClothing\Data\Masks\CombatGasmask\Data\Asmond_CombatGasmask_Black.rvmat","DZ\characters\masks\data\GasMask_Glass.rvmat"}},{0.5,{"AsmondClothing\Data\Masks\CombatGasmask\Data\Asmond_CombatGasmask_Black_Damage.rvmat","DZ\characters\masks\data\GasMask_Glass_damage.rvmat"}},{0.3,{"AsmondClothing\Data\Masks\CombatGasmask\Data\Asmond_CombatGasmask_Black_Damage.rvmat","DZ\characters\masks\data\GasMask_Glass_damage.rvmat"}},{0,{"AsmondClothing\Data\Masks\CombatGasmask\Data\Asmond_CombatGasmask_Black_Destruct.rvmat","DZ\characters\masks\data\GasMask_Glass_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_GP5GasMask_Camo;
	class GP5GasMask_Camo: Asmond_GP5GasMask_Camo { scope=2; };

	class Asmond_GP5GasMask_Black;
	class GP5GasMask_Black: Asmond_GP5GasMask_Black { scope=2; };

	class Asmond_GP5GasMask_Brown;
	class GP5GasMask_Brown: Asmond_GP5GasMask_Brown { scope=2; };

	class Asmond_MimeMask_PaperHouse;
	class MimeMask_PaperHouse: Asmond_MimeMask_PaperHouse { scope=2; };

	class Asmond_MimeMask_Nosferatu;
	class MimeMask_Nosferatu: Asmond_MimeMask_Nosferatu { scope=2; };

	class Asmond_MimeMask_Black;
	class MimeMask_Black: Asmond_MimeMask_Black { scope=2; };

	class Asmond_MimeMask_FullWhite;
	class MimeMask_FullWhite: Asmond_MimeMask_FullWhite { scope=2; };

	class Asmond_Mimemask_Fawkes;
	class MimeMask_Fawkes: Asmond_Mimemask_Fawkes { scope=2; };

	class Asmond_Mimemask_Killer;
	class MimeMask_Killer: Asmond_Mimemask_Killer { scope=2; };

	class Asmond_Mimemask_King;
	class MimeMask_King: Asmond_Mimemask_King
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 60;
							healthLevels[] = {{1,{"DZ\characters\masks\data\MimeMask.rvmat"}},{0.7,{"AsmondClothing\Data\Masks\MimeMask\Data\Asmond_Mimemask_King.rvmat"}},{0.5,{"AsmondClothing\Data\Masks\MimeMask\Data\Asmond_Mimemask_King_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Masks\MimeMask\Data\Asmond_Mimemask_King_Damage.rvmat"}},{0,{"AsmondClothing\Data\Masks\MimeMask\Data\Asmond_Mimemask_King_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Mimemask_BaldwinIV;
	class MimeMask_BaldwinIV: Asmond_Mimemask_BaldwinIV
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 60;
							healthLevels[] = {{1,{"DZ\characters\masks\data\MimeMask.rvmat"}},{0.7,{"AsmondClothing\Data\Masks\MimeMask\Data\Asmond_Mimemask_BaldwinIV.rvmat"}},{0.5,{"AsmondClothing\Data\Masks\MimeMask\Data\Asmond_Mimemask_BaldwinIV_Damage.rvmat"}},{0.3,{"AsmondClothing\Data\Masks\MimeMask\Data\Asmond_Mimemask_BaldwinIV_Damage.rvmat"}},{0,{"AsmondClothing\Data\Masks\MimeMask\Data\Asmond_Mimemask_BaldwinIV_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_NioshMask_Grey;
	class NioshMask_Grey: Asmond_NioshMask_Grey { scope=2; };

	class Asmond_NioshMask_Dusted;
	class NioshMask_Dusted: Asmond_NioshMask_Dusted { scope=2; };

	class Asmond_NioshMask_Hazmat;
	class NioshMask_Hazmat: Asmond_NioshMask_Hazmat { scope=2; };

};
