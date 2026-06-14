class PlayZACDeferredKickMessage
{
	protected static string s_Reason;

	static void Queue(string reason)
	{
		if (reason == "")
			return;

		s_Reason = reason;
	}

	static bool HasMessage()
	{
		return s_Reason != "";
	}

	static string GetAndClear()
	{
		string reason = s_Reason;
		s_Reason = "";
		return reason;
	}
}
