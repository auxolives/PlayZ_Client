//! Default no-op bridge — PlayZNamalsk modds this class to gate/sofen weather PPE on Namalsk.
//! In 5_Mission so PlayZNamalsk Mission can modd the same class (Mission cannot see 3_Game types from other mods).
class PlayZWeatherNamalskPPEBridge
{
	static void OnTick(float timeslice)
	{
	}

	static float GetOverallWeight()
	{
		return 1.0;
	}

	static float GetGlowColorWeight()
	{
		return 1.0;
	}
}
