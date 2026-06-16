// Defer Expansion grave cross spawn while a living player is within block radius.
// Source Found: DayZExpansion/Scripts/4_World/DayZExpansion/Entities/ManBase/PlayerBase.c:137-225
// Config: $profile:PlayZ/Expansion.json

modded class PlayerBase
{
	protected bool PlayZExpansionGravecross_HasLivingPlayerNearby(vector origin, float radiusMeters)
	{
		array<Man> players = new array<Man>;
		g_Game.GetPlayers(players);

		float radiusSq = radiusMeters * radiusMeters;

		foreach (Man man : players)
		{
			PlayerBase pb = PlayerBase.Cast(man);
			if (!pb)
				continue;

			if (pb == this)
				continue;

			if (!pb.IsAlive())
				continue;

			if (pb.Expansion_IsAI())
				continue;

			if (vector.DistanceSq(origin, pb.GetPosition()) <= radiusSq)
				return true;
		}

		return false;
	}

	override void CreateGraveCross(EntityAI handEntity)
	{
		if (!g_Game.IsServer())
			return;

		if (ToDelete())
			return;

		PlayZExpansionConfig config = PlayZExpansionConfig.Get();

		if (PlayZExpansionGravecross_HasLivingPlayerNearby(GetPosition(), config.GraveCrossBlockRadiusMeters))
		{
			int retryMs = config.GraveCrossRetryIntervalSeconds * 1000;
			g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CreateGraveCross, retryMs, false, handEntity);
			return;
		}

		super.CreateGraveCross(handEntity);
	}
}
