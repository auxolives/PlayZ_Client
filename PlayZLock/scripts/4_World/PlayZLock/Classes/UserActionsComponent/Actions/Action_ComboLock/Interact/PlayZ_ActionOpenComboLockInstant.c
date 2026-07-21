class PlayZ_ActionOpenComboLockInstant : ActionInteractBase
{
	void PlayZ_ActionOpenComboLockInstant()
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

		// Check if player is looking directly at combo lock
		CombinationLock lock = CombinationLock.Cast(target.GetObject());

		// If we haven't found a combo lock, stop here.
		if (!lock || !lock.IsLockedOnGate())
			return false;

		// Ensure the door is not already open
		if (PlayZLockHelper.IsOpen(lock.GetHierarchyParent()))
			return false;

		// Set construction action data for the player (referenced in other actions related to combo lock)
		ConstructionActionData construction_action_data = player.GetConstructionActionData();
		construction_action_data.SetCombinationLock(lock);

		// Check if player is admin - if so then permit instant open
		if (PlayZLockConfig.Get().ClientSyncConfig.AllowAdminOpen && player.IsPlayZLockAdmin())
			return true;

		// If we've made it this far, check if player has permission to open
		return PlayZLockConfig.Get().ClientSyncConfig.InstantOpen && lock.IsPermittedToOpen(player) && !lock.IsManagingLockClient();
	}

	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);

		if (!action_data.m_Player || !action_data.m_Player.GetIdentity())
			return;

		PlayZLockConfig cfg = PlayZLockConfig.Get();
		if (!cfg || !cfg.ClientSyncConfig)
			return;

		CombinationLock lock = CombinationLock.Cast(action_data.m_Target.GetObject());
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

		EntityAI lockParent = lock.GetHierarchyParent();
		PlayZLockHelper.Open(lockParent);

		if (cfg.ServerConfig && cfg.ServerConfig.UnlockOnOpen)
			lock.UnlockServerPlayZ(action_data.m_Player, lockParent);

		PlayZLockLogger.Log("Player " + action_data.m_Player.GetIdentity().GetPlainId() + " opened lock @ " + action_data.m_Player.GetPosition());
	}
}