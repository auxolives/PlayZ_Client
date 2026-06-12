modded class MissionGameplay
{
	override void OnUpdate(float timeslice)
	{
		if (PlayZDeathScreen_IsMenuMode())
		{
			PlayZDeathScreen_MaintainDeathMenuView();
		}

		if (PlayZDeathScreen_IsIntroActive())
		{
			PlayZDeathScreen_SilenceWorldAudio();
		}

		super.OnUpdate(timeslice);
	}

	override void Pause()
	{
		if (!PlayZDeathScreen_IsTerjeMaintenanceDeath() && PlayZDeathScreen_ShouldBlockPause())
		{
			return;
		}

		super.Pause();
	}

	override void Continue()
	{
		if (!PlayZDeathScreen_IsTerjeMaintenanceDeath() && PlayZDeathScreen_ShouldBlockContinue())
		{
			return;
		}

		super.Continue();
	}

	override void OnPlayerRespawned(Man player)
	{
		PlayZDeathScreen_Reset();
		super.OnPlayerRespawned(player);
	}
}
