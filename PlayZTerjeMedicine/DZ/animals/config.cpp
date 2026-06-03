class CfgPatches
{
	class PlayZCore_Animals_Terje
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Animals",
            "TerjeCore",
            "TerjeMedicine"
		};
	};
};

class CfgVehicles
{
	class AnimalBase;
	class Animal_CanisLupus: AnimalBase
	{
		class Skinning
		{
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
				class Rabies
				{
					chance = 0.1;
				};
			};
		};
	};
};
