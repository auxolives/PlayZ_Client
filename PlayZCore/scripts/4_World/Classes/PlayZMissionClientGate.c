//! Shared client-side gate for PlayZ MissionGameplay PPE and player-scoped ticks.
//! Lives in 4_World — PlayerBase is not visible from 3_Game.
class PlayZMissionClientGate
{
	static bool IsPPEReady(PlayerBase player)
	{
		if (GetGame().IsDedicatedServer())
		{
			return false;
		}

		if (!player || !player.IsAlive() || !player.IsControlledPlayer())
		{
			return false;
		}

		if (player.HasActiveTerjeStartScreen())
		{
			return false;
		}

		return true;
	}

	static bool IsToastReady(PlayerBase player)
	{
		if (GetGame().IsDedicatedServer())
		{
			return false;
		}

		if (!player || !player.IsAlive() || !player.IsControlledPlayer())
		{
			return false;
		}

		if (player.HasActiveTerjeStartScreen())
		{
			return false;
		}

		if (GetGame().GetUIManager().GetMenu())
		{
			return false;
		}

		return true;
	}
}
