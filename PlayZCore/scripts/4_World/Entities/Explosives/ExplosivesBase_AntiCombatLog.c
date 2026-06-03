modded class ExplosivesBase
{
	private bool m_PlayZTriggeredPlayersCombat = false;

	override void OnExplode()
	{
		super.OnExplode();

		if (!g_Game.IsServer())
		{
			return;
		}

		if (!PlayZ_TriggerCombatLogTimer())
		{
			return;
		}

		PlayZ_TriggerCombatPlayersInRadius(PlayZAntiCombatLogConfig.Get().TriggerOnExplosiveRadius);
	}

	void PlayZ_TriggerCombatPlayersInRadius(int radius)
	{
		if (m_PlayZTriggeredPlayersCombat)
		{
			return;
		}

		m_PlayZTriggeredPlayersCombat = true;

		if (radius <= 0)
		{
			return;
		}

		array<Man> players = new array<Man>;
		GetGame().GetWorld().GetPlayerList(players);
		int x;
		int count = players.Count();
		for (x = 0; x < count; x++)
		{
			if (vector.Distance(players.Get(x).GetPosition(), GetPosition()) <= radius)
			{
				PlayerBase pb = PlayerBase.Cast(players.Get(x));
				if (pb)
				{
					pb.SetCombatLogTimer();
				}
			}
		}
	}

	bool PlayZ_TriggerCombatLogTimer()
	{
		return true;
	}
}
