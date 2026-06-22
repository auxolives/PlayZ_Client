class PlayZNotificationEntry
{
	string Title;
	string Message;
	float HoldSeconds;
	float EnqueuedAtMs;

	void PlayZNotificationEntry(string title, string message, float holdSeconds, float enqueuedAtMs)
	{
		Title = title;
		Message = message;
		HoldSeconds = holdSeconds;
		EnqueuedAtMs = enqueuedAtMs;
	}

	bool HasVisibleContent(bool showTitle, bool showMessage)
	{
		if (showTitle && Title != "")
		{
			return true;
		}

		if (showMessage && Message != "")
		{
			return true;
		}

		return false;
	}
}
