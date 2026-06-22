#ifndef SERVER
modded class NotificationSystem
{
	override void AddNotif(NotificationRuntimeData data)
	{
		if (!data)
		{
			return;
		}

		if (GetGame().IsDedicatedServer())
		{
			return;
		}

		if (PlayZNotificationQueue.IsKillfeedNotification(data))
		{
			return;
		}

		if (!PlayZNotificationClientState.HasConfig())
		{
			PlayZNotificationQueue.Get().EnqueuePending(data);
			return;
		}

		if (!PlayZNotificationConfig.IsEnabled())
		{
			return;
		}

		PlayZNotificationEntry entry = PlayZNotificationQueue.Normalize(data);
		if (!entry)
		{
			return;
		}

		PlayZNotificationQueue.Get().Enqueue(entry);
	}
}
#endif
