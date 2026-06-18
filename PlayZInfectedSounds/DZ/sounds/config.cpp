class CfgPatches
{
	class DZ_Sounds_PlayZInfectedSounds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Sounds_Effects"
		};
	};
};
class CfgSoundSets
{
	class Zmb_VoiceFX_Base_SoundSet;

	class ZmbM_Normal_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Attack_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Normal_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_HeavyHit_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Normal_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_LightHit_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Normal_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Jump_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Normal_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Land_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Normal_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbM_Normal_CallToArmsShort_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 1;
	};

	class ZmbM_Normal_Old_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Attack_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_Normal_Old_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_HeavyHit_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_Normal_Old_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_LightHit_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_Normal_Old_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Jump_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_Normal_Old_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Land_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_Normal_Old_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbM_Normal_CallToArmsShort_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 1;
	};

	class ZmbM_Normal2_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_Attack_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Normal2_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_HeavyHit_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Normal2_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_LightHit_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Normal2_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_Jump_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Normal2_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_Land_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Normal2_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbM_Normal2_CallToArmsShort_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 1;
	};

	class ZmbF_Normal_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Attack_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Normal_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_HeavyHit_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Normal_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_LightHit_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Normal_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Jump_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Normal_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Land_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Normal_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbF_Normal_CallToArmsShort_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 1;
	};

	class ZmbM_Skinny_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Attack_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_Skinny_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_HeavyHit_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_Skinny_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_LightHit_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_Skinny_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Jump_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_Skinny_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Land_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_Skinny_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbM_Skinny_CallToArmsShort_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 1;
	};

	class ZmbM_Skinny_Old_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Attack_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_Skinny_Old_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_HeavyHit_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_Skinny_Old_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_LightHit_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_Skinny_Old_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Jump_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_Skinny_Old_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Land_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_Skinny_Old_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbM_Skinny_CallToArmsShort_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 1;
	};

	class ZmbF_Skinny_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Attack_SoundShader"};
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_Skinny_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_HeavyHit_SoundShader"};
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_Skinny_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_LightHit_SoundShader"};
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_Skinny_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Jump_SoundShader"};
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_Skinny_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Land_SoundShader"};
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_Skinny_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbF_Skinny_CallToArmsShort_SoundShader"};
		frequencyFactor = 1.12;
		volumeFactor = 1;
	};

	class ZmbM_Fat_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_Attack_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_Fat_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_HeavyHit_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_Fat_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_LightHit_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_Fat_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_Jump_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_Fat_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_Land_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_Fat_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbM_Fat_CallToArmsShort_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 1;
	};

	class ZmbF_Fat_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Attack_SoundShader"};
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_Fat_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_HeavyHit_SoundShader"};
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_Fat_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_LightHit_SoundShader"};
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_Fat_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Jump_SoundShader"};
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_Fat_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Land_SoundShader"};
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_Fat_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbF_Normal_CallToArmsShort_SoundShader"};
		frequencyFactor = 1.02;
		volumeFactor = 1;
	};

	class ZmbM_Old_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_Attack_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_Old_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_HeavyHit_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_Old_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_LightHit_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_Old_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_Jump_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_Old_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_Land_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_Old_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbM_Old_CallToArmsShort_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 1;
	};

	class ZmbF_Old_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Attack_SoundShader"};
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_Old_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_HeavyHit_SoundShader"};
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_Old_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_LightHit_SoundShader"};
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_Old_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Jump_SoundShader"};
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_Old_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Land_SoundShader"};
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_Old_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbF_Skinny_CallToArmsShort_SoundShader"};
		frequencyFactor = 0.88;
		volumeFactor = 1;
	};

	class ZmbM_NBC_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_Attack_SoundShader"};
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_HeavyHit_SoundShader"};
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_LightHit_SoundShader"};
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_Jump_SoundShader"};
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_Land_SoundShader"};
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		volumeCurve = "infectedShoutingAttenuationCurve";
		soundShaders[] = {"ZmbM_NBC_CallToArmsShort_SoundShader"};
		frequencyFactor = 0.95;
		volumeFactor = 1;
	};

	class PlayZ_ZmbM_SkaterYoung_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_Attack_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class PlayZ_ZmbM_SkaterYoung_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_HeavyHit_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class PlayZ_ZmbM_SkaterYoung_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_LightHit_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class PlayZ_ZmbM_SkaterYoung_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_Jump_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class PlayZ_ZmbM_SkaterYoung_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_Land_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class PlayZ_ZmbM_SkaterYoung_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CallToArmsShort_SoundShader"};
		volumeCurve = "infectedShoutingAttenuationCurve";
		frequencyFactor = 1.35;
		volumeFactor = 0.85;
	};

	class PlayZ_ZmbF_SkaterYoung_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Attack_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class PlayZ_ZmbF_SkaterYoung_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_HeavyHit_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class PlayZ_ZmbF_SkaterYoung_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_LightHit_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class PlayZ_ZmbF_SkaterYoung_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Jump_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class PlayZ_ZmbF_SkaterYoung_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Land_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class PlayZ_ZmbF_SkaterYoung_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CallToArmsShort_SoundShader"};
		volumeCurve = "infectedShoutingAttenuationCurve";
		frequencyFactor = 1.35;
		volumeFactor = 0.85;
	};

	class ZmbM_priestPopSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 1.4;
	};

	class ZmbM_priestPopSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 1.4;
	};

	class ZmbM_priestPopSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 1.4;
	};

	class ZmbM_priestPopSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 1.4;
	};

	class ZmbM_priestPopSkinny_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 1.4;
	};

	class ZmbM_priestPopSkinny_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 1.4;
	};

	class ZmbM_priestPopSkinny_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 1.4;
	};

	class ZmbM_priestPopSkinny_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 1.4;
	};

	class PlayZ_ZmbM_Priest_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Attack_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 1.40;
	};

	class PlayZ_ZmbM_Priest_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_HeavyHit_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 1.40;
	};

	class PlayZ_ZmbM_Priest_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_LightHit_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 1.40;
	};

	class PlayZ_ZmbM_Priest_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Jump_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 1.40;
	};

	class PlayZ_ZmbM_Priest_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Land_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 1.40;
	};

	class PlayZ_ZmbM_Priest_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CallToArmsShort_SoundShader"};
		volumeCurve = "infectedShoutingAttenuationCurve";
		frequencyFactor = 1.05;
		volumeFactor = 1.45;
	};

	class ZmbM_usSoldier_Officer_Desert_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		volumeCurve = "infectedShoutingAttenuationCurve";
		frequencyFactor = 1.00;
		volumeFactor = 1.40;
	};

	class ZmbM_usSoldier_Officer_Desert_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
		volumeCurve = "infectedShoutingAttenuationCurve";
		frequencyFactor = 1.00;
		volumeFactor = 1.40;
	};

	class ZmbM_usSoldier_Officer_Desert_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		volumeCurve = "infectedShoutingAttenuationCurve";
		frequencyFactor = 1.00;
		volumeFactor = 1.40;
	};

	class ZmbM_usSoldier_Officer_Desert_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		volumeCurve = "infectedShoutingAttenuationCurve";
		frequencyFactor = 1.00;
		volumeFactor = 1.40;
	};

	class PlayZ_ZmbM_Officer_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Attack_SoundShader"};
		frequencyFactor = 1.00;
		volumeFactor = 1.40;
	};

	class PlayZ_ZmbM_Officer_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_HeavyHit_SoundShader"};
		frequencyFactor = 1.00;
		volumeFactor = 1.40;
	};

	class PlayZ_ZmbM_Officer_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_LightHit_SoundShader"};
		frequencyFactor = 1.00;
		volumeFactor = 1.40;
	};

	class PlayZ_ZmbM_Officer_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Jump_SoundShader"};
		frequencyFactor = 1.00;
		volumeFactor = 1.40;
	};

	class PlayZ_ZmbM_Officer_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Land_SoundShader"};
		frequencyFactor = 1.00;
		volumeFactor = 1.40;
	};

	class PlayZ_ZmbM_Officer_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CallToArmsShort_SoundShader"};
		volumeCurve = "infectedShoutingAttenuationCurve";
		frequencyFactor = 1.00;
		volumeFactor = 1.45;
	};

};
