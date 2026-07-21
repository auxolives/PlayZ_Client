class PlayZ_ActionNextCombinationLockDialOnFence : PlayZ_ActionNextCombinationLockDialOnTarget
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{

		// If there is no object, stop here
		if (!target.GetObject())
			return false;

		// If interact anywhere is disabled, stop here
		if (!PlayZLockConfig.Get().ClientSyncConfig || !PlayZLockConfig.Get().ClientSyncConfig.InteractAnywhere)
			return false;
		
		// Check if player is looking at fence and interact anywhere is enabled
		CombinationLock lock = PlayZLockHelper.GetCombinationLock(target.GetObject());

		// If we've found a lock, check conditions
		if (lock && lock.IsLocked())
		{
			// If client has not received lock perms, don't display action
			if (!lock.HasReceivedClientsidePerms())
				return false;

			// Set combo lock in action data
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			construction_action_data.SetCombinationLock(lock);

			// If player owns this lock or is a guest, hide the dial action unless they've selected Manage Lock
			if (lock.IsPermittedToOpen(player))
				return g_Game.IsDedicatedServer() || (lock.IsManagingLockClient() && !PlayZLockConfig.Get().ClientSyncConfig.OwnerCanRemoveLockWithoutCode);

			// Player is not an owner of this combo lock - let them dial the lock as normal
			return true;
		}

		return false;
	}
}