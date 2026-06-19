class PlayZTerjeStartScreenNameRules
{
	static void SanitizeOutputs(inout string first, inout string last)
	{
		if (first == string.Empty)
		{
			last = string.Empty;
		}
	}

	static bool IsFirstNamePresent(string first)
	{
		return first != string.Empty;
	}
}
