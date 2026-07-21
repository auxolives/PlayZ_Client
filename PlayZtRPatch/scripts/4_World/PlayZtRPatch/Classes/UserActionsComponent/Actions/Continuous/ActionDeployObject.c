//! Gate deploy/place prompt on a fresh hologram check (4-arg Can is what ActionInput uses).
//! SetupAction also refuses so a stale prompt cannot start the anim.
//! Source Found: scripts/4_World/Classes/UserActionsComponent/Actions/Continuous/DeployActions/ActionDeployObject.c:35
//! Source Found: scripts/4_World/Classes/UserActionsComponent/ActionInput.c:331 (Can with condition_mask)
modded class ActionDeployObject
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!g_Game.IsDedicatedServer())
		{
			if (player.IsPlacingLocal() && item && !PlayZTRPlacement.IgnoresPlacementCollision(item))
			{
				if (!PlayZTRPlacement.CanDeployFromHologram(player, player.GetHologramLocal(), item))
					return false;
			}
		}

		return super.ActionCondition(player, target, item);
	}

	override bool ActionConditionContinue(ActionData action_data)
	{
		ItemBase item = action_data.m_MainItem;

		if (g_Game.IsDedicatedServer())
		{
			if (action_data.m_Player.IsPlacingServer() && item && !PlayZTRPlacement.IgnoresPlacementCollision(item))
			{
				Hologram hologram = action_data.m_Player.GetHologramServer();
				if (!PlayZTRPlacement.CanDeployFromHologram(action_data.m_Player, hologram, item))
					return false;
			}

			return super.ActionConditionContinue(action_data);
		}

		// Client: refuse continue while still in place mode with an invalid hologram.
		if (action_data.m_Player.IsPlacingLocal() && item && !PlayZTRPlacement.IgnoresPlacementCollision(item))
		{
			if (!PlayZTRPlacement.CanDeployFromHologram(action_data.m_Player, action_data.m_Player.GetHologramLocal(), item))
				return false;
		}

		return super.ActionConditionContinue(action_data);
	}

	//! ActionInput calls this overload — not the 3-arg Can().
	override bool Can(PlayerBase player, ActionTarget target, ItemBase item, int condition_mask)
	{
		if (!g_Game.IsDedicatedServer() && player && player.IsPlacingLocal() && item && !PlayZTRPlacement.IgnoresPlacementCollision(item))
		{
			if (!PlayZTRPlacement.CanDeployFromHologram(player, player.GetHologramLocal(), item))
				return false;
		}

		return super.Can(player, target, item, condition_mask);
	}

	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if (!g_Game.IsDedicatedServer() && player && player.IsPlacingLocal() && item && !PlayZTRPlacement.IgnoresPlacementCollision(item))
		{
			if (!PlayZTRPlacement.CanDeployFromHologram(player, player.GetHologramLocal(), item))
				return false;
		}

		return super.SetupAction(player, target, item, action_data, extra_data);
	}
}
