class PlayZLockActionConditions
{
	// Cursor hit distance (like ActionOpenFence), not object-center distance (CCTNonRuined).
	// BASEBUILDING reach so InteractAnywhere works on large tR gates/stockades.
	static CCTBase CreateTargetCondition()
	{
		return new CCTCursor(UAMaxDistances.BASEBUILDING);
	}
}
