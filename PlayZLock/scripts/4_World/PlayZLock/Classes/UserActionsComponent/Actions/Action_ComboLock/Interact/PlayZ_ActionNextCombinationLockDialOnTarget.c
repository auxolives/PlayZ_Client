class PlayZ_ActionNextCombinationLockDialOnTarget : ActionInteractBase
{
	void PlayZ_ActionNextCombinationLockDialOnTarget()
	{
		m_Text = "#next_combination_lock_dial";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = PlayZLockActionConditions.CreateTargetCondition();
	}

	override bool IsInstant()
	{
		return true;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{

		// If there is no object, stop here
		if (!target.GetObject() || !PlayZLockConfig.Get().ClientSyncConfig)
			return false;

		// Check if player is looking directly at combo lock
		CombinationLock lock = CombinationLock.Cast(target.GetObject());

		// If lock doesn't exist or is unlocked, stop here
		if (!lock || !lock.IsLockedOnGate())
			return false;

		// If client has not received lock perms, don't display action
		if (!lock.HasReceivedClientsidePerms())
			return false;

		ConstructionActionData construction_action_data = player.GetConstructionActionData();
		construction_action_data.SetCombinationLock(lock);

		// If player owns this lock is a guest, hide the dial action unless they've selected Manage Lock
		if (lock.IsPermittedToOpen(player))
			return GetGame().IsDedicatedServer() || (lock.IsManagingLockClient() && !PlayZLockConfig.Get().ClientSyncConfig.OwnerCanRemoveLockWithoutCode);

		// Player is not an owner of this combo lock - let them dial the lock as normal
		return true;
	}

	// From vanilla action
	override void Start(ActionData action_data)
	{
		super.Start(action_data);

		//set next dial
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		CombinationLock combination_lock = construction_action_data.GetCombinationLock();
		if (combination_lock)
			combination_lock.SetNextDial();
	}
}