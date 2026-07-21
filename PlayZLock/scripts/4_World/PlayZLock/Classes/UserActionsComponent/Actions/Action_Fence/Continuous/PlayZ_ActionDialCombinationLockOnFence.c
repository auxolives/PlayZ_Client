// Modified vanilla combination dial action to work with fence
class PlayZ_ActionDialCombinationLockOnFence : PlayZ_ActionDialCombinationLockOnTarget
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{

		// If there is no object, stop here
		if (!target.GetObject() || !PlayZLockConfig.Get().ClientSyncConfig)
			return false;

		// Check if interact anywhere is enabled or the owner can use the RemoveLockWithoutCode action
		if (!PlayZLockConfig.Get().ClientSyncConfig.InteractAnywhere)
			return false;

		// Check if lock exists and is not already unlocked
		CombinationLock lock = PlayZLockHelper.GetCombinationLock(target.GetObject());
		if (!lock || (lock && !lock.IsLocked()))
			return false;

		// If client has not received lock perms, don't display action
		if (!lock.HasReceivedClientsidePerms())
			return false;

		// Set player construction data for other functions & actions to reference
		ConstructionActionData construction_action_data = player.GetConstructionActionData();
		construction_action_data.SetCombinationLock(lock);

		// Don't display combo dial if client has open perms and is not managing the lock
		return !lock.IsPermittedToOpen(player) || GetGame().IsDedicatedServer() || (lock.IsManagingLockClient() && !PlayZLockConfig.Get().ClientSyncConfig.OwnerCanRemoveLockWithoutCode);
	}

	// CLIENT-SIDE: Display code digit if enabled in config
	override void Do(ActionData action_data, int state)
	{
		super.Do(action_data, state);

		// If digit display is disabled or we're calling Do() on server, stop here
		if (!GetGame().IsClient() || PlayZLockConfig.Get().ClientSyncConfig.DisplayDigits == 0)
			return;

		// Get combo lock
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		CombinationLock lock = construction_action_data.GetCombinationLock();

		// If lock exists, display current digit
		if (lock)
			lock.DisplayDigitText();
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (!action_data.m_Player || !action_data.m_Player.GetIdentity())
			return;

		CombinationLock lock = PlayZLockHelper.GetCombinationLock(action_data.m_Target.GetObject());
		if (!lock)
			return;

		lock.DialNextNumber();

		if (!lock.IsCombinationMatched())
			return;

		EntityAI lockParent = lock.GetHierarchyParent();
		if (!lockParent)
			return;

		lock.UnlockServerPlayZ(action_data.m_Player, lockParent);
		PlayZLockLogger.Log("Player " + action_data.m_Player.GetIdentity().GetPlainId() + " entered pin @ " + action_data.m_Player.GetPosition());
	}
}