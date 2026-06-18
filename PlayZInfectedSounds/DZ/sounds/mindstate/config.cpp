class CfgPatches
{
	class DZ_Sounds_PlayZInfectedSounds_MindState
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

	class ZmbM_HermitSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_HermitSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_HermitSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_HermitSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.82;
	};

	class ZmbM_CitizenASkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_CitizenASkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_CitizenASkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_CitizenASkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_CitizenASkinny_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_CitizenASkinny_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_CitizenASkinny_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_CitizenASkinny_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_PrisonerSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_PrisonerSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_PrisonerSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_PrisonerSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_JournalistSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_JournalistSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_JournalistSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_JournalistSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_HikerSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_HikerSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_HikerSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_HikerSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_JoggerSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_JoggerSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_JoggerSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_JoggerSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM__Runner_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM__Runner_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM__Runner_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM__Runner_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_MechanicSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_MechanicSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_MechanicSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_MechanicSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_PatientSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_PatientSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_PatientSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_PatientSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.05;
		volumeFactor = 0.8;
	};

	class ZmbM_FirefighterNormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_FirefighterNormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_FirefighterNormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_FirefighterNormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_ParamedicNormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_ParamedicNormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_ParamedicNormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_ParamedicNormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_NBC_Yellow_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_Yellow_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_Yellow_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_Yellow_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_SurvivorDean_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_SurvivorDean_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_SurvivorDean_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_SurvivorDean_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_PolicemanSpecForce_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_PolicemanSpecForce_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_PolicemanSpecForce_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_PolicemanSpecForce_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_SoldierNormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_SoldierNormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_SoldierNormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_SoldierNormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_usSoldier_normal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_usSoldier_normal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_usSoldier_normal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_usSoldier_normal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_PatrolNormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_PatrolNormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_PatrolNormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_PatrolNormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_NBC_Grey_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_Grey_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_Grey_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_Grey_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_White_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_White_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_White_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_NBC_White_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_NBC_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.95;
		volumeFactor = 0.7;
	};

	class ZmbM_SkaterYoung_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_ConstrWorkerNormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_ConstrWorkerNormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_ConstrWorkerNormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_ConstrWorkerNormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_HeavyIndustryWorker_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_HeavyIndustryWorker_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_HeavyIndustryWorker_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_HeavyIndustryWorker_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_OffshoreWorker_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_OffshoreWorker_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_OffshoreWorker_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_OffshoreWorker_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_HandymanNormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_HandymanNormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_HandymanNormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_HandymanNormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Jacket_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Jacket_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Jacket_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Jacket_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Jacket_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Jacket_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Jacket_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Jacket_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Soldier_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Soldier_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Soldier_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Soldier_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_FarmerFat_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_FarmerFat_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_FarmerFat_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_FarmerFat_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_FarmerFat_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_FarmerFat_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_FarmerFat_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_FarmerFat_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_CitizenBFat_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_CitizenBFat_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_CitizenBFat_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_CitizenBFat_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_PolicemanFat_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_PolicemanFat_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_PolicemanFat_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_PolicemanFat_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_MotobikerFat_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_MotobikerFat_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_MotobikerFat_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_MotobikerFat_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_DoctorFat_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_DoctorFat_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_DoctorFat_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_DoctorFat_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_ClerkFat_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_ClerkFat_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_ClerkFat_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_ClerkFat_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_ClerkFat_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_ClerkFat_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_ClerkFat_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_ClerkFat_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.9;
		volumeFactor = 0.95;
	};

	class ZmbM_VillagerOld_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_VillagerOld_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_VillagerOld_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_VillagerOld_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_VillagerOld_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_VillagerOld_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_VillagerOld_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_VillagerOld_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_FishermanOld_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_FishermanOld_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_FishermanOld_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_FishermanOld_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_HunterOld_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_HunterOld_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_HunterOld_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_HunterOld_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_CommercialPilotOld_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_CommercialPilotOld_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_CommercialPilotOld_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_CommercialPilotOld_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_CommercialPilotOld_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_CommercialPilotOld_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_CommercialPilotOld_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_CommercialPilotOld_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_Gamedev_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_Gamedev_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_Gamedev_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_Gamedev_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.85;
		volumeFactor = 0.85;
	};

	class ZmbM_Mummy_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Mummy_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Mummy_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbM_Mummy_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1;
		volumeFactor = 0.85;
	};

	class ZmbF_CitizenANormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_CitizenANormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_CitizenANormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_CitizenANormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_CitizenANormal_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_CitizenANormal_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_CitizenANormal_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_CitizenANormal_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_JournalistNormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_JournalistNormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_JournalistNormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_JournalistNormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_JournalistNormal_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_JournalistNormal_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_JournalistNormal_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_JournalistNormal_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ParamedicNormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ParamedicNormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ParamedicNormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ParamedicNormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_SurvivorNormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_SurvivorNormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_SurvivorNormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_SurvivorNormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_SurvivorNormal_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_SurvivorNormal_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_SurvivorNormal_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_SurvivorNormal_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_PoliceWomanNormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_PoliceWomanNormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_PoliceWomanNormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_PoliceWomanNormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_MechanicNormal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_MechanicNormal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_MechanicNormal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_MechanicNormal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Clerk_Normal_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Clerk_Normal_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Clerk_Normal_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Clerk_Normal_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ClerkFat_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_ClerkFat_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_ClerkFat_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_ClerkFat_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_Clerk_Normal_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Clerk_Normal_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Clerk_Normal_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_Clerk_Normal_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ShortSkirt_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ShortSkirt_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ShortSkirt_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ShortSkirt_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ShortSkirt_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ShortSkirt_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ShortSkirt_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_ShortSkirt_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.08;
		volumeFactor = 0.8;
	};

	class ZmbF_CitizenBSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_CitizenBSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_CitizenBSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_CitizenBSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_HikerSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_HikerSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_HikerSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_HikerSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_JoggerSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_JoggerSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_JoggerSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_JoggerSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_Runner_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_Runner_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_Runner_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_Runner_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_SkaterYoung_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_DoctorSkinny_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_DoctorSkinny_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_DoctorSkinny_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_DoctorSkinny_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.12;
		volumeFactor = 0.78;
	};

	class ZmbF_BlueCollarFat_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_BlueCollarFat_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_BlueCollarFat_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_BlueCollarFat_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_NurseFat_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_NurseFat_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_NurseFat_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_NurseFat_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.02;
		volumeFactor = 0.88;
	};

	class ZmbF_PatientOld_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_PatientOld_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_PatientOld_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_PatientOld_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_VillagerOld_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_VillagerOld_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_VillagerOld_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_VillagerOld_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_VillagerOld_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_VillagerOld_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_VillagerOld_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_VillagerOld_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_MilkMaidOld_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_MilkMaidOld_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_MilkMaidOld_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_MilkMaidOld_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_MilkMaidOld_LT_Base_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_MilkMaidOld_LT_Base_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_MilkMaidOld_LT_Base_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

	class ZmbF_MilkMaidOld_LT_Base_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 0.88;
		volumeFactor = 0.82;
	};

// SkaterYoung leaf spawn classes (runtime ClassName, not _Base).
	class ZmbF_SkaterYoung_Brown_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Brown_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Brown_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Brown_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Striped_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Striped_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Striped_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Striped_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Violet_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Violet_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Violet_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbF_SkaterYoung_Violet_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Brown_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Brown_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Brown_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Brown_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Green_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Green_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Green_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Green_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Grey_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Grey_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Grey_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Grey_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Blue_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
		delay = 3;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Blue_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Blue_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};

	class ZmbM_SkaterYoung_Blue_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
		delay = 2;
		delayRandomizer = 1;
		startDelay = 3;
		startDelayRandomizer = 1;
		frequencyFactor = 1.35;
		volumeFactor = 0.65;
	};
};
