modded class ActionTurnOffTerjeRadTentStatic
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target)
		{
			return false;
		}

		Object targetObject = target.GetObject();
		if (!player || !targetObject)
		{
			return false;
		}

		TerjeRadTentStatic tent = TerjeRadTentStatic.Cast(targetObject);
		if (!tent)
		{
			return false;
		}

		if (!tent.HasEnergyManager())
		{
			return false;
		}

		return tent.GetCompEM().IsSwitchedOn();
	}

	override void OnExecuteServer(ActionData action_data)
	{
		TerjeRadTentStatic tent = TerjeRadTentStatic.Cast(action_data.m_Target.GetObject());
		if (!tent)
		{
			return;
		}

		if (tent.GetCompEM().CanSwitchOff())
		{
			tent.GetCompEM().SwitchOff();
		}
	}
}
