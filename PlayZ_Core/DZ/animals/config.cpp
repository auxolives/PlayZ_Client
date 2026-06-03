class CfgPatches
{
	class PlayZCore_Animals
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Animals",
			"DZ_Animals_bos_taurus",
			"DZ_Animals_capra_hircus",
			"DZ_Animals_capreolus_capreolus",
			"DZ_Animals_cervus_elaphus",
			"DZ_Animals_gallus_gallus_domesticus",
			"DZ_Animals_lepus_europaeus",
			"DZ_Animals_ovis_aries",
			"DZ_Animals_rangifer_tarandus",
			"DZ_Animals_sus_domesticus",
			"DZ_Animals_sus_scrofa",
			"DZ_Animals_vulpes_vulpes",
			"DZ_Animals_canis_lupus",
			"DZ_Animals_ursus_arctos"
		};
	};
};

class CfgVehicles
{
	class AnimalBase;

	// --- CATTLE (Cow/Bull) ---
	class Animal_BosTaurus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "CowSteakMeat";
				count = 15;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {3,3,3};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "CowPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 5;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 3;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 4;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};
	class Animal_BosTaurusF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "CowSteakMeat";
				count = 12;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {3,3,3};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "CowPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 5;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 3;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 4;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- GOATS ---
	class Animal_CapraHircus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "GoatSteakMeat";
				count = 6;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {2,1,2};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "GoatPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.3,6};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};
	class Animal_CapraHircusF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "GoatSteakMeat";
				count = 5;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {1,1,1};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "GoatPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.3,6};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- DEER (Roe Deer) ---
	class Animal_CapreolusCapreolus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "DeerSteakMeat";
				count = 8;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {2,2,2};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "DeerPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 0.5;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.2,0.5};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};
	class Animal_CapreolusCapreolusF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "DeerSteakMeat";
				count = 7;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {2,2,2};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "DeerPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 0.5;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.2,0.5};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- DEER (Red Deer) ---
	class Animal_CervusElaphus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "DeerSteakMeat";
				count = 14;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {4,4,4};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 3;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedPelt
			{
				item = "DeerPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 3;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 3;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};
	class Animal_CervusElaphusF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "DeerSteakMeat";
				count = 12;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {3,3,3};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 3;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedPelt
			{
				item = "DeerPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 3;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 3;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- CHICKENS ---
	class Animal_GallusGallusDomesticus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "ChickenBreastMeat";
				count = 2;
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedFeathers
			{
				item = "ChickenFeather";
				count = 10;
				quantityMinMaxCoef[] = {0.5,1};
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "SmallGuts";
				count = 0;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.2,0.3};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};
	class Animal_GallusGallusDomesticusF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "ChickenBreastMeat";
				count = 2;
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedFeathers
			{
				item = "ChickenFeather";
				count = 10;
				quantityMinMaxCoef[] = {0.5,1};
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "SmallGuts";
				count = 0;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.2,0.3};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- HARE (Rabbit) ---
	class Animal_LepusEuropaeus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "RabbitLegMeat";
				count = 2;
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "RabbitPelt";
				count = 1;
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.1,0.2};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.2,0.3};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- SHEEP (Ram/Ewe) ---
	class Animal_OvisAries: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "SheepSteakMeat";
				count = 9;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {2,2,2};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "SheepPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.4,8};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 2;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};
	class Animal_OvisAriesF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "SheepSteakMeat";
				count = 7;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {2,2,2};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "SheepPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.4,8};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 2;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- REINDEER ---
	class Animal_RangiferTarandus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "DeerSteakMeat";
				count = 14;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {4,4,4};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 3;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedPelt
			{
				item = "DeerPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 3;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 3;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};
	class Animal_RangiferTarandusF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "DeerSteakMeat";
				count = 12;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {3,3,3};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 3;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedPelt
			{
				item = "DeerPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 3;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 3;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- DOMESTIC PIG ---
	class Animal_SusDomesticus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "PigSteakMeat";
				count = 12;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {4,2,4};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "PigPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 2;
				quantityMinMaxCoef[] = {0.2,1};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 2;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- WILD BOAR ---
	class Animal_SusScrofa: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "PigSteakMeat";
				count = 12;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {3,3,3};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "WildBoarPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 2;
				quantityMinMaxCoef[] = {0.2,1};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 3;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- FOX ---
	class Animal_VulpesVulpes: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "WolfSteakMeat";
				count = 2;
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "FoxPelt";
				count = 1;
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 1;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.1,0.3};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.2,0.5};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- WOLF ---
	class Animal_CanisLupus: AnimalBase
	{
		class Skinning
		{
			class ObtainedHead
			{
				item = "Headdress_Wolf";
				count = 1;
				itemZones[] = {"Zone_Head"};
				countByZone[] = {1};
				quantityMinMaxCoef[] = {0,0.55};
			};
			class ObtainedSteaks
			{
				item = "WolfSteakMeat";
				count = 6;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {1,1,1};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedPelt
			{
				item = "WolfPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.7,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
	};

	// --- BEAR (Bliss) ---
	class Animal_UrsusArctos: AnimalBase
	{
		class Skinning
		{
			class ObtainedPelt
			{
				item = "BearPelt";
				count = 1;
				itemZones[] = {"Zone_Pelvis","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedSteaks
			{
				item = "BearSteakMeat";
				count = 15;
				itemZones[] = {"Zone_Belly","Zone_Pelvis"};
				countByZone[] = {6,6};
				quantityMinMaxCoef[] = {0.2,0.9};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 2;
				quantityMinMaxCoef[] = {0.2,1};
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 4;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 5;
				quantityMinMaxCoef[] = {0.3,1};
				transferToolDamageCoef = 1;
			};
			class BloodInfectionSettings
			{
				class Salmonella
				{
					chance = 0.4;
				};
			};
		};
		class AIBehaviourHL {};
	};
};

class CfgAIBehaviours
{
	class Predator_UrsusArctos
	{
		class BehaviourHLBear
		{
			class AlertSystem
			{
				visionToAlertMultiplier = 7.5;
				noiseToAlertMultiplier = 1.5;
			};
			instantAlertRangeMin = 30.0;
			instantAlertRangeMax = 150.0;
		};
		class TargetSystemDZBase
		{
			visionRangeMax = 150;
		};
	};
	class Herbivores
	{
		class BehaviourHLDeer
		{
			class AlertSystem
			{
				visionToAlertMultiplier = 9.0;
				noiseToAlertMultiplier = 1.3;
			};
		};
		class TargetSystemDZBase
		{
			visionRangeMax = 125;
		};
	};
	class Herbivores_BosTaurus
	{
		class BehaviourHLDomestic
		{
			class AlertSystem
			{
				visionToAlertMultiplier = 50.0;
				noiseToAlertMultiplier = 4.0;
			};
		};
		class TargetSystemDZBase
		{
			visionRangeMax = 40;
		};
	};
	class Herbivores_CapreolusCapreolus
	{
		class BehaviourHLDeer
		{
			class AlertSystem
			{
				visionToAlertMultiplier = 9.0;
			};
		};
		class TargetSystemDZBase
		{
			visionRangeMax = 65;
		};
	};
	class Herbivores_CapraHircus
	{
		class BehaviourHLDomestic
		{
			class AlertSystem
			{
				visionToAlertMultiplier = 50.0;
			};
		};
		class TargetSystemDZBase
		{
			visionRangeMax = 15;
		};
	};
	class Herbivores_SusDomesticus
	{
		class BehaviourHLDomestic
		{
			class AlertSystem
			{
				visionToAlertMultiplier = 45.0;
			};
		};
		class TargetSystemDZBase
		{
			visionRangeMax = 30;
		};
	};
	class Herbivores_SusScrofa
	{
		class BehaviourHLDeer
		{
			class AlertSystem
			{
				visionToAlertMultiplier = 9.0;
			};
		};
		class TargetSystemDZBase
		{
			visionRangeMax = 85;
		};
	};
	class Herbivores_CervusElaphus
	{
		class BehaviourHLDeer
		{
			class AlertSystem
			{
				visionToAlertMultiplier = 9.0;
			};
		};
		class TargetSystemDZBase
		{
			visionRangeMax = 125;
		};
	};
	class Herbivores_CervusElaphusFem
	{
		class BehaviourHLDeer
		{
			class AlertSystem
			{
				visionToAlertMultiplier = 25.0;
			};
		};
		class TargetSystemDZBase
		{
			visionRangeMax = 100;
		};
	};
	class Herbivores_OvisAries
	{
		class BehaviourHLDomestic
		{
			class AlertSystem
			{
				visionToAlertMultiplier = 50.0;
			};
		};
		class TargetSystemDZBase
		{
			visionRangeMax = 12;
		};
	};
};
