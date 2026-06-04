class CfgPatches
{
	class PlayZAsmond_attachments_optics
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Weapons_Optics",
			"DZ_Gear_Optics",
			"PlayZAsmond",
			"AsmondWeapons",
		};
	};
};

class cfgVehicles
{
	class FNP45_MRDSOptic;
	class MK4Optic_ColorBase;
	class PSO11Optic;
	class PSO1Optic;
	class PUScopeOptic;
	class ReflexOptic;

	class Asmond_Optic_MiniSight_Black;
	class FNP45_MRDSOptic_Black: Asmond_Optic_MiniSight_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 30;
							healthLevels[] = {{1,{"DZ\weapons\attachments\optics\data\lensglass_ca.paa","DZ\weapons\attachments\optics\data\lensglass_clearer.rvmat","DZ\weapons\attachments\data\mrds.rvmat"}},{0.7,{}},{0.5,{"DZ\weapons\attachments\optics\data\lensglass_damage_ca.paa","DZ\weapons\attachments\optics\data\lensglass_clearer_damage.rvmat","AsmondWeapons\Optics\MINI\Data\Asmond_MiniSight_Black_Damage.rvmat"}},{0.3,{}},{0,{"DZ\weapons\attachments\optics\data\lensglass_destruct_ca.paa","DZ\weapons\attachments\optics\data\lensglass_clearer_destruct.rvmat","AsmondWeapons\Optics\MINI\Data\Asmond_MiniSight_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Optic_MiniSight_Tan;
	class FNP45_MRDSOptic_Tan: Asmond_Optic_MiniSight_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 30;
							healthLevels[] = {{1,{"DZ\weapons\attachments\optics\data\lensglass_ca.paa","DZ\weapons\attachments\optics\data\lensglass_clearer.rvmat","DZ\weapons\attachments\data\mrds.rvmat"}},{0.7,{}},{0.5,{"DZ\weapons\attachments\optics\data\lensglass_damage_ca.paa","DZ\weapons\attachments\optics\data\lensglass_clearer_damage.rvmat","AsmondWeapons\Optics\MINI\Data\Asmond_MiniSight_Black_Damage.rvmat"}},{0.3,{}},{0,{"DZ\weapons\attachments\optics\data\lensglass_destruct_ca.paa","DZ\weapons\attachments\optics\data\lensglass_clearer_destruct.rvmat","AsmondWeapons\Optics\MINI\Data\Asmond_MiniSight_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Optic_MK4_Winter;
	class MK4Optic_Winter: Asmond_Optic_MK4_Winter { scope=2; };

	class Asmond_Optic_PSO1_Black;
	class PSO1Optic_Black: Asmond_Optic_PSO1_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 50;
							healthLevels[] = {{1,{"DZ\weapons\attachments\optics\data\lensglass_ca.paa","DZ\weapons\attachments\data\svd_scope.rvmat"}},{0.7,{}},{0.5,{"DZ\weapons\attachments\optics\data\lensglass_damage_ca.paa","AsmondWeapons\Optics\PSO1\Data\Asmond_PSO1_Black_Damage.rvmat"}},{0.3,{}},{0,{"DZ\weapons\attachments\optics\data\lensglass_destruct_ca.paa","AsmondWeapons\Optics\PSO1\Data\Asmond_PSO1_Black_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Optic_PSO11_Black;
	class PSO11Optic_Black: Asmond_Optic_PSO11_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 50;
							healthLevels[] = {{1,{"DZ\weapons\attachments\optics\data\lensglass_ca.paa","DZ\weapons\attachments\data\svd_scope.rvmat"}},{0.7,{}},{0.5,{"DZ\weapons\attachments\optics\data\lensglass_damage_ca.paa","AsmondWeapons\Optics\PSO11\Data\Asmond_PSO11_Black_Damage.rvmat"}},{0.3,{}},{0,{"DZ\weapons\attachments\optics\data\lensglass_destruct_ca.paa","AsmondWeapons\Optics\PSO11\Data\Asmond_PSO11_Black_destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Optic_PUScope_White;
	class PUScopeOptic_White: Asmond_Optic_PUScope_White
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 50;
							healthLevels[] = {{1,{"DZ\weapons\attachments\data\scope_alpha_clear_ca.paa","AsmondWeapons\Optics\PUScope\Data\Asmond_PUScopeOptic.rvmat"}},{0.7,{}},{0.5,{"DZ\weapons\attachments\data\scope_alpha_damaged_ca.paa","AsmondWeapons\Optics\PUScope\Data\Asmond_PUScopeOptic_Damage.rvmat"}},{0.3,{}},{0,{"DZ\weapons\attachments\data\scope_alpha_destroyed_ca.paa","AsmondWeapons\Optics\PUScope\Data\Asmond_PUScopeOptic_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Optic_Reflex_Black;
	class ReflexOptic_Black: Asmond_Optic_Reflex_Black
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 30;
							healthLevels[] = {{1,{"DZ\weapons\attachments\optics\data\lensglass_ca.paa","DZ\weapons\attachments\optics\data\Red_Dot.rvmat"}},{0.7,{}},{0.5,{"DZ\weapons\attachments\optics\data\lensglass_damage_ca.paa","AsmondWeapons\Optics\REFLEX\Data\Asmond_Reflex_Black_Damage.rvmat"}},{0.3,{}},{0,{"DZ\weapons\attachments\optics\data\lensglass_destruct_ca.paa","AsmondWeapons\Optics\REFLEX\Data\Asmond_Reflex_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

	class Asmond_Optic_Reflex_Tan;
	class ReflexOptic_Tan: Asmond_Optic_Reflex_Tan
	{
		scope=2;
		class DamageSystem
				{
					class GlobalHealth
					{
						class Health
						{
							hitpoints = 30;
							healthLevels[] = {{1,{"DZ\weapons\attachments\optics\data\lensglass_ca.paa","DZ\weapons\attachments\optics\data\Red_Dot.rvmat"}},{0.7,{}},{0.5,{"DZ\weapons\attachments\optics\data\lensglass_damage_ca.paa","AsmondWeapons\Optics\REFLEX\Data\Asmond_Reflex_Black_Damage.rvmat"}},{0.3,{}},{0,{"DZ\weapons\attachments\optics\data\lensglass_destruct_ca.paa","AsmondWeapons\Optics\REFLEX\Data\Asmond_Reflex_Black_Destruct.rvmat"}}};
						};
					};
				};
	};

};
