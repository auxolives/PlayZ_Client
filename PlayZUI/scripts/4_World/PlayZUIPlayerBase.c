modded class PlayerBase
{
	override void SetDeathDarknessLevel(float duration, float tick_time)
	{
		if (PlayZDeathScreen_ShouldUseCustomFlow() && IsControlledPlayer())
		{
			StopDeathDarkeningEffect();
			return;
		}

		super.SetDeathDarknessLevel(duration, tick_time);
	}

	override void SimulateDeath(bool state)
	{
		if (state && g_Game && g_Game.IsClient() && PlayZDeathScreen_ShouldUseCustomFlow())
		{
			if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT)
			{
				SCameraOverlaysManager.getInstance().deactivateAll();
			}
		}

		super.SimulateDeath(state);
	}
}
