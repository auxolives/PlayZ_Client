modded class ActionCloseFence
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{

		Object targetObject = target.GetObject();
		if (targetObject && targetObject.CanUseConstruction())
		{
			Fence fence = Fence.Cast(targetObject);

			if (fence && fence.CanCloseFence())
			{
				// Check if interact anywhere is enabled
				if (PlayZLockConfig.Get().ClientSyncConfig && PlayZLockConfig.Get().ClientSyncConfig.InteractAnywhere)
					return true;
			}
		}

		return super.ActionCondition(player, target, item);
	}

	// Do action (client-side only)
	override void OnStartClient(ActionData action_data)
	{
		super.OnStartClient(action_data);

		// Get combo lock
		CombinationLock combination_lock = PlayZLockHelper.GetCombinationLock(action_data.m_Target.GetObject());

		// If combo lock exists, handle management
		if (combination_lock)
		{
			// Set managing lock to false after door has been closed
			combination_lock.SetManagingLockClient(false);
		}
	}

	// For BBP compatibility:
	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		if (action_data.m_Target.GetObject() && action_data.m_Target.GetObject().IsKindOf("BBP_WALL_BASE"))
		{
			CombinationLock lock = PlayZLockHelper.GetCombinationLock(action_data.m_Target.GetObject());
			if (lock)
			{
				if (!lock.IsLocked())
				{
					lock.LockServer(EntityAI.Cast(action_data.m_Target.GetObject()), true);
				}
			}
		}
	}
}