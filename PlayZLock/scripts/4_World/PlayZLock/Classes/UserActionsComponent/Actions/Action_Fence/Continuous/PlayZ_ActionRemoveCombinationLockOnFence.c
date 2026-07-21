class PlayZ_ActionRemoveCombinationLockOnFence : ActionContinuousBase
{
	void PlayZ_ActionRemoveCombinationLockOnFence()
	{
		m_CallbackClass = PlayZ_ActionOpenComboLockCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "#STR_PLAYZ_LOCK_REMOVE";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = PlayZLockActionConditions.CreateTargetCondition();
	}

	override bool HasProneException()
	{
		return true;
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	// Check both client & server-side action requirements
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{

		// If there is no object or we're holding something, stop here
		if (!target.GetObject() || item || !PlayZLockConfig.Get().ClientSyncConfig)
			return false;

		// If interact anywhere is enabled, stop here as that action is used instead
		if (!PlayZLockConfig.Get().ClientSyncConfig.InteractAnywhere)
			return false;

		// Check if player is looking at a fence containing a combo lock
		CombinationLock lock = CombinationLock.Cast(PlayZLockHelper.GetCombinationLock(target.GetObject()));

		// If we haven't found a gate with a combo lock or gate is open, stop here.
		if (!lock || PlayZLockHelper.IsOpen(lock.GetHierarchyParent()))
			return false;

		// If client has not received lock perms, don't display action yet
		if (!lock.HasReceivedClientsidePerms() || !PlayZLockConfig.Get().ClientSyncConfig.OwnerCanRemoveLockWithoutCode)
			return false;

		// If we're not managing the lock, stop here
		if (GetGame().IsClient() && !lock.IsManagingLockClient())
			return false;

		// Set construction action data for the player (referenced in other actions related to combo lock)
		ConstructionActionData construction_action_data = player.GetConstructionActionData();
		construction_action_data.SetCombinationLock(lock);

		// Client-side check: If player is an admin, stop here (as Instant action is used instead)
		if (player.IsPlayZLockAdmin())
			return false;

		// Check action condition client (player has client permission & is managing the lock)
		return lock.IsPermittedToOpen(player) && !lock.IsTakeable();
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (!action_data.m_Player || !action_data.m_Player.GetIdentity())
			return;

		if (!PlayZLockConfig.Get().ClientSyncConfig || !PlayZLockConfig.Get().ClientSyncConfig.OwnerCanRemoveLockWithoutCode)
			return;

		CombinationLock lock = PlayZLockHelper.GetCombinationLock(action_data.m_Target.GetObject());
		if (!lock)
			return;

		if (!lock.IsLockedOnGate() || !lock.IsLocked() || !lock.IsPermittedToOpen(action_data.m_Player))
			return;

		lock.IncreaseSimulatedDialChanges();

		if (lock.GetSimulatedDialChangeCount() >= (lock.GetLockDigits() * PlayZLockConfig.Get().ServerConfig.DigitMultiplier))
		{
			lock.UnlockServerPlayZ(action_data.m_Player, lock.GetHierarchyParent());
			PlayZLockLogger.Log("Player " + action_data.m_Player.GetIdentity().GetPlainId() + " unlocked lock @ " + action_data.m_Player.GetPosition());
		}
	}

	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);

		if (!action_data.m_Player || !action_data.m_Player.GetIdentity())
			return;

		CombinationLock lock = PlayZLockHelper.GetCombinationLock(action_data.m_Target.GetObject());
		if (lock)
			lock.ResetSimulatedDialChanges();
	}

	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient(action_data);

		CombinationLock combination_lock = PlayZLockHelper.GetCombinationLock(action_data.m_Target.GetObject());
		if (combination_lock)
		{
			combination_lock.SetManagingLockClient(false);
		}
	}
}