//! Vanilla-aligned deploy for tR kits. Self-contained Can/ActionCondition (no ActionDeployObject super for conditions).
//! Source Found: scripts/4_World/Classes/UserActionsComponent/Actions/Continuous/DeployActions/ActionDeployObject.c:35
class PlayZ_ActionDeployTRKit: ActionDeployObject
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		// Mirror vanilla ActionDeployObject, but use PlayZ hologram collide flag.
		if (!g_Game.IsDedicatedServer())
		{
			if (player && player.IsPlacingLocal() && item)
			{
				if (!PlayZTRPlacement.CanDeployFromHologram(player, player.GetHologramLocal(), item))
					return false;

				Hologram hologram = player.GetHologramLocal();
				if (hologram && item.CanBePlaced(player, hologram.GetProjectionEntity().GetPosition()))
				{
					// Expansion territory / zones (static helper on ActionDeployObject).
					return ActionDeployObject.Expansion_CheckDeploy(player, target, item, false);
				}
			}
			return false;
		}

		return true;
	}

	override bool ActionConditionContinue(ActionData action_data)
	{
		ItemBase item = action_data.m_MainItem;
		PlayerBase player = action_data.m_Player;

		if (g_Game.IsDedicatedServer())
		{
			if (player && player.IsPlacingServer() && item)
			{
				Hologram hologram = player.GetHologramServer();
				if (!PlayZTRPlacement.CanDeployFromHologram(player, hologram, item))
					return false;

				if (hologram && item.CanBePlaced(player, hologram.GetProjectionEntity().GetPosition()))
					return true;

				return false;
			}
			return false;
		}

		return true;
	}

	override bool Can(PlayerBase player, ActionTarget target, ItemBase item, int condition_mask)
	{
		if (((condition_mask & m_ConditionMask) != condition_mask) || (!IsFullBodyEx(player, target, item) && !player.IsPlayerInStance(GetStanceMaskEx(player, target, item))) || player.IsRolling())
			return false;

		if (m_ConditionItem && !m_ConditionItem.Can(player, item))
			return false;

		if (!ActionCondition(player, target, item))
			return false;

		if (IsFullBodyEx(player, target, item))
		{
			int nextStance = GetClosestPossibleStance(player, target, item);
			int stanceIdx = DayZPlayerUtils.ConvertStanceMaskToStanceIdx(nextStance);
			if (stanceIdx != -1 && !DayZPlayerUtils.PlayerCanChangeStance(player, stanceIdx))
				return false;
		}

		return true;
	}

	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if (!g_Game.IsDedicatedServer() && !ActionCondition(player, target, item))
			return false;

		return super.SetupAction(player, target, item, action_data, extra_data);
	}
}
