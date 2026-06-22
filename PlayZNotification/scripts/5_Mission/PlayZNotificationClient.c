modded class MissionGameplay
{
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		PlayZNotificationManager.Get().Update(timeslice);
	}
}
