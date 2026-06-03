//! Invisible scanner spawned at bullet/explosive impacts to flag nearby players for combat logout.
class PlayZ_CombatLogTrigger extends Inventory_Base
{
	void PlayZ_CombatLogTrigger()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DeleteSafe, 1, false);
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		if (!g_Game.IsServer())
		{
			return;
		}

		int radius = 0;
		if (GetType().Contains("Explosive"))
		{
			radius = PlayZAntiCombatLogConfig.Get().TriggerOnExplosiveRadius;
		}
		else
		{
			radius = PlayZAntiCombatLogConfig.Get().TriggerOnBulletImpactRadius;
		}

		if (radius <= 0)
		{
			return;
		}

		vector ourRealPos = GetPosition();
		ourRealPos[1] = g_Game.SurfaceY(ourRealPos[0], ourRealPos[2]);

		array<Man> players = new array<Man>;
		g_Game.GetWorld().GetPlayerList(players);
		PlayerBase pb;
		int i;
		int count = players.Count();
		for (i = 0; i < count; i++)
		{
			if (vector.Distance(players.Get(i).GetPosition(), ourRealPos) < radius)
			{
				pb = PlayerBase.Cast(players.Get(i));
				if (pb)
				{
					pb.SetCombatLogTimer();
				}
			}
		}
	}
}

class PlayZ_CombatLogExplosiveTrigger extends PlayZ_CombatLogTrigger {}
