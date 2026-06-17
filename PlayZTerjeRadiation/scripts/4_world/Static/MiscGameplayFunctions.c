modded class MiscGameplayFunctions
{
	override static bool CanIgnoreDistanceCheck(Object obj)
	{
		if (TerjeRadTentStatic.Cast(obj))
		{
			return true;
		}

		return super.CanIgnoreDistanceCheck(obj);
	}
}
