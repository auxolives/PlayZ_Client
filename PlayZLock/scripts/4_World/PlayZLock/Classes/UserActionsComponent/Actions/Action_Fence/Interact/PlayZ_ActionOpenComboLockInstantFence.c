class PlayZ_ActionOpenComboLockInstantFence : ActionInteractBase
{
	void PlayZ_ActionOpenComboLockInstantFence()
	{
		m_Text = "#open";
	}

	// Create action item & target conditions
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = PlayZLockActionConditions.CreateTargetCondition();
	}

	// Action is an instant action
	override bool IsInstant()
	{
		return true;
	}

	// Check the various conditions required to allow this action
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{

		// If there is no target, stop here
		if (!target.GetObject() || !PlayZLockConfig.Get().ClientSyncConfig)
			return false;

		// Check if player is looking at fence and interact anywhere is enabled
		if (!PlayZLockConfig.Get().ClientSyncConfig.InteractAnywhere)
			return false;

		// Get combo lock from fence target
		CombinationLock lock = PlayZLockHelper.GetCombinationLock(target.GetObject());

		// If we haven't found a combo lock, stop here.
		if (!lock)
			return false;

		// If client has not received lock perms, don't display action
		if (!lock.HasReceivedClientsidePerms())
			return false;

		// If fence doesn't exist or gate is opened, stop here.
		if (PlayZLockHelper.IsOpen(target.GetObject()))
			return false;

		// Set construction action data for the player (referenced in other actions related to combo lock)
		ConstructionActionData construction_action_data = player.GetConstructionActionData();
		construction_action_data.SetCombinationLock(lock);

		bool permittedInstant = PlayZLockConfig.Get().ClientSyncConfig.InstantOpen && lock.IsPermittedToOpen(player) && !lock.IsManagingLockClient();
		bool adminInstant = PlayZLockConfig.Get().ClientSyncConfig.AllowAdminOpen && player.IsPlayZLockAdmin();
		return lock.IsLocked() && (permittedInstant || adminInstant);
	}

	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);

		if (!action_data.m_Player || !action_data.m_Player.GetIdentity())
			return;

		PlayZLockConfig cfg = PlayZLockConfig.Get();
		if (!cfg || !cfg.ClientSyncConfig)
			return;

		CombinationLock lock = PlayZLockHelper.GetCombinationLock(action_data.m_Target.GetObject());
		if (!lock)
			return;

		bool allowInstant = cfg.ClientSyncConfig.InstantOpen;
		bool allowAdmin = lock.IsServerLockAdmin(action_data.m_Player);
		if (!allowInstant && !allowAdmin)
			return;

		if (!lock.IsLockedOnGate())
			return;

		if (!lock.IsPermittedToOpen(action_data.m_Player))
			return;

		PlayZLockHelper.Open(lock.GetHierarchyParent());

		if (cfg.ServerConfig && cfg.ServerConfig.UnlockOnOpen)
			lock.UnlockServerPlayZ(action_data.m_Player, lock.GetHierarchyParent());

		PlayZLockLogger.Log("Player " + action_data.m_Player.GetIdentity().GetPlainId() + " opened lock @ " + action_data.m_Player.GetPosition());
	}
}