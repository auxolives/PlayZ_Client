modded class ActionDigOutStash
{
	protected const float PLAYZ_HIDDEN_STASH_SEARCH_RADIUS = 1.0;

	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTCursorNoObject(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined();
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		UndergroundStash stash = PlayZResolveStashTarget(target);
		if (!stash)
		{
			return false;
		}

		if (!stash.CanBeDigged())
		{
			return false;
		}

		if (stash.GetTerjeStashInvisible())
		{
			if (!player || !player.GetTerjeSkills())
			{
				return false;
			}

			return player.GetTerjeSkills().GetPerkLevel("surv", "stashes") > 0;
		}

		return true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		UndergroundStash stash = PlayZResolveStashTarget(action_data.m_Target);
		if (!stash)
		{
			return;
		}

		ItemBase stashedItem = stash.GetStashedItem();
		if (stashedItem)
		{
			DigOutStashLambda lambda(stash, "", action_data.m_Player);
			action_data.m_Player.ServerReplaceItemWithNew(lambda);
		}
		else
		{
			g_Game.ObjectDelete(stash);
		}

		MiscGameplayFunctions.DealEvinronmentAdjustedDmg(action_data.m_MainItem, action_data.m_Player, 10);
	}

	protected UndergroundStash PlayZResolveStashTarget(ActionTarget target)
	{
		if (!target)
		{
			return null;
		}

		UndergroundStash directStash;
		if (Class.CastTo(directStash, target.GetObject()))
		{
			return directStash;
		}

		vector cursorPosition = target.GetCursorHitPos();
		array<Object> nearbyObjects = new array<Object>();
		array<CargoBase> proxyCargos = new array<CargoBase>();
		g_Game.GetObjectsAtPosition3D(cursorPosition, PLAYZ_HIDDEN_STASH_SEARCH_RADIUS, nearbyObjects, proxyCargos);

		int nearbyCount = nearbyObjects.Count();
		for (int i = 0; i < nearbyCount; i++)
		{
			UndergroundStash nearbyStash;
			if (Class.CastTo(nearbyStash, nearbyObjects[i]))
			{
				return nearbyStash;
			}
		}

		return null;
	}
}
