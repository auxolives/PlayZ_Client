// Source Found: TerjeMedicine/Scripts/4_World/Classes/UserActionsComponent/Actions/ActionInjectSyringeTarget.c
// Block Terje syringe injection on Expansion AI bots; self and human players remain valid.

modded class ActionInjectSyringeTarget
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!super.ActionCondition(player, target, item))
		{
			return false;
		}

		PlayerBase targetPlayer = PlayerBase.Cast(target.GetObject());
		if (targetPlayer && !targetPlayer.PlayZ_CanReceivePlayerSyringeInjection())
		{
			return false;
		}

		return true;
	}

	override void OnExecuteServer(ActionData action_data)
	{
		PlayerBase targetPlayer = PlayerBase.Cast(action_data.m_Target.GetObject());
		if (targetPlayer && !targetPlayer.PlayZ_CanReceivePlayerSyringeInjection())
		{
			return;
		}

		super.OnExecuteServer(action_data);
	}
}
