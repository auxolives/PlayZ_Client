modded class CarScript
{
	protected int m_PlayZ_HillStartAssistUntil;
	protected int m_PlayZ_HillStuckSince;

	int PlayZ_GetHillStartAssistUntil()
	{
		return m_PlayZ_HillStartAssistUntil;
	}

	void PlayZ_SetHillStartAssistUntil(int value)
	{
		m_PlayZ_HillStartAssistUntil = value;
	}

	int PlayZ_GetHillStuckSince()
	{
		return m_PlayZ_HillStuckSince;
	}

	void PlayZ_SetHillStuckSince(int value)
	{
		m_PlayZ_HillStuckSince = value;
	}

	override void DamageCrew(float dmg)
	{
		for (int c = 0; c < CrewSize(); c++)
		{
			Human crew = CrewMember(c);
			if (!crew)
			{
				continue;
			}

			PlayerBase player;
			if (!Class.CastTo(player, crew))
			{
				continue;
			}

			if (dmg > GameConstants.CARS_CONTACT_DMG_KILLCREW)
			{
				player.SetHealth(0.0);
				continue;
			}

			float shockTemp = Math.InverseLerp(GameConstants.CARS_CONTACT_DMG_THRESHOLD, GameConstants.CARS_CONTACT_DMG_KILLCREW, dmg);
			shockTemp = Math.Clamp(shockTemp, 0, 1);
			float shock = Math.Lerp(50, 150, shockTemp);
			float hp = Math.Lerp(2, 100, shockTemp);
			hp = hp * PlayZCarsConstants.CREW_CRASH_HEALTH_DAMAGE_SCALE;

			player.AddHealth("", "Shock", -shock);
			player.AddHealth("", "Health", -hp);
		}
	}

	override void EOnPostSimulate(IEntity other, float timeSlice)
	{
		super.EOnPostSimulate(other, timeSlice);

		if (!GetGame() || !GetGame().IsServer())
		{
			return;
		}

		if (!EngineIsOn())
		{
			return;
		}

		PlayZCarVehicleEntry entry = PlayZCarsConfigManager.Get().GetEntry(GetType());
		if (!entry)
		{
			return;
		}

		if (!entry.m_HillAssistEnabled)
		{
			return;
		}

		if (entry.m_HillAssistStrength <= 0.0)
		{
			return;
		}

		PlayZCarHillAssist.Apply(this, entry.m_HillAssistStrength, timeSlice);
	}
}
