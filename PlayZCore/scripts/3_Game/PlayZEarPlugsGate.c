//! Optional integration point: other PlayZ modules (e.g. PlayZTerjeMedicine) can call
//! SetSleepingDeafnessActive(true) while client-side sleeping audio reduction owns volume.
//! PlayZCore earplugs stay standalone: default is inactive; no Terje symbols here.

class PlayZEarPlugsGate
{
	private static bool s_SleepingDeafnessActive;

	static void SetSleepingDeafnessActive(bool active)
	{
		s_SleepingDeafnessActive = active;
	}

	static bool IsSleepingDeafnessActive()
	{
		return s_SleepingDeafnessActive;
	}
}
