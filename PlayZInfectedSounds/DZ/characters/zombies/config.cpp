class CfgPatches
{
	class PlayZInfectedSounds_Zombies
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Sounds_PlayZInfectedSounds",
			"DZ_Characters_Zombies"
		};
	};
};

class CfgVehicles
{
	class ZombieMaleBase;
	class ZombieFemaleBase;
	class ZmbM_priestPopSkinny_Base;
	class ZmbM_usSoldier_normal_Base;

	class ZmbM_SkaterYoung_Base: ZombieMaleBase
	{
		class AnimEvents
		{
			class SoundVoice
			{
				class LightHit
				{
					soundSet = "PlayZ_ZmbM_SkaterYoung_LightHit_Soundset";
					id = 1;
				};
				class HeavyHit
				{
					soundSet = "PlayZ_ZmbM_SkaterYoung_HeavyHit_Soundset";
					id = 2;
				};
				class Attack
				{
					soundSet = "PlayZ_ZmbM_SkaterYoung_Attack_Soundset";
					id = 5;
				};
				class Jump
				{
					soundSet = "PlayZ_ZmbM_SkaterYoung_Jump_Soundset";
					id = 10;
				};
				class Land
				{
					soundSet = "PlayZ_ZmbM_SkaterYoung_Land_Soundset";
					id = 11;
				};
				class CallToArmsShort
				{
					soundSet = "PlayZ_ZmbM_SkaterYoung_CallToArmsShort_Soundset";
					id = 20;
				};
			};
		};
	};

	class ZmbF_SkaterYoung_Base: ZombieFemaleBase
	{
		class AnimEvents
		{
			class SoundVoice
			{
				class LightHit
				{
					soundSet = "PlayZ_ZmbF_SkaterYoung_LightHit_Soundset";
					id = 1;
				};
				class HeavyHit
				{
					soundSet = "PlayZ_ZmbF_SkaterYoung_HeavyHit_Soundset";
					id = 2;
				};
				class Attack
				{
					soundSet = "PlayZ_ZmbF_SkaterYoung_Attack_Soundset";
					id = 5;
				};
				class Jump
				{
					soundSet = "PlayZ_ZmbF_SkaterYoung_Jump_Soundset";
					id = 10;
				};
				class Land
				{
					soundSet = "PlayZ_ZmbF_SkaterYoung_Land_Soundset";
					id = 11;
				};
				class CallToArmsShort
				{
					soundSet = "PlayZ_ZmbF_SkaterYoung_CallToArmsShort_Soundset";
					id = 20;
				};
			};
		};
	};

	class ZmbM_priestPopSkinny: ZmbM_priestPopSkinny_Base
	{
		class AnimEvents
		{
			class SoundVoice
			{
				class LightHit
				{
					soundSet = "PlayZ_ZmbM_Priest_LightHit_Soundset";
					id = 1;
				};
				class HeavyHit
				{
					soundSet = "PlayZ_ZmbM_Priest_HeavyHit_Soundset";
					id = 2;
				};
				class Attack
				{
					soundSet = "PlayZ_ZmbM_Priest_Attack_Soundset";
					id = 5;
				};
				class Jump
				{
					soundSet = "PlayZ_ZmbM_Priest_Jump_Soundset";
					id = 10;
				};
				class Land
				{
					soundSet = "PlayZ_ZmbM_Priest_Land_Soundset";
					id = 11;
				};
				class CallToArmsShort
				{
					soundSet = "PlayZ_ZmbM_Priest_CallToArmsShort_Soundset";
					id = 20;
				};
			};
		};
	};

	class ZmbM_usSoldier_Officer_Desert: ZmbM_usSoldier_normal_Base
	{
		class AnimEvents
		{
			class SoundVoice
			{
				class LightHit
				{
					soundSet = "PlayZ_ZmbM_Officer_LightHit_Soundset";
					id = 1;
				};
				class HeavyHit
				{
					soundSet = "PlayZ_ZmbM_Officer_HeavyHit_Soundset";
					id = 2;
				};
				class Attack
				{
					soundSet = "PlayZ_ZmbM_Officer_Attack_Soundset";
					id = 5;
				};
				class Jump
				{
					soundSet = "PlayZ_ZmbM_Officer_Jump_Soundset";
					id = 10;
				};
				class Land
				{
					soundSet = "PlayZ_ZmbM_Officer_Land_Soundset";
					id = 11;
				};
				class CallToArmsShort
				{
					soundSet = "PlayZ_ZmbM_Officer_CallToArmsShort_Soundset";
					id = 20;
				};
			};
		};
	};
};
