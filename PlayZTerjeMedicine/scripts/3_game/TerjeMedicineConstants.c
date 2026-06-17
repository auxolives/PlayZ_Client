// Source Found: TerjeMedicine/Scripts/3_Game/Constants.c:21-22 (SLEEPING_TENDENCY_MINUS_STAGE1/2)

modded class TerjeMedicineConstants
{
	const float SLEEPING_TENDENCY_MINUS_STAGE1 = -1.65;
	const float SLEEPING_TENDENCY_MINUS_STAGE2 = -5.55;

	// Low-health mind drain: 0 at PLAYZ_LOW_HEALTH_MIND_THRESHOLD HP, max per sec at 0 HP.
	const float PLAYZ_LOW_HEALTH_MIND_THRESHOLD = 40.0;
	const float PLAYZ_LOW_HEALTH_MIND_DRAIN_MAX_PER_SEC = 0.20;
}
