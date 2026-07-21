class PlayZ_ActionAdminCombinationLockOnTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(3);
	}
}

class PlayZ_ActionAdminCombinationLockOnTarget : ActionContinuousBase
{
	void PlayZ_ActionAdminCombinationLockOnTarget()
	{
		m_CallbackClass = PlayZ_ActionAdminCombinationLockOnTargetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = PlayZLockActionConditions.CreateTargetCondition();
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool HasProgress()
	{
		return true;
	}

	override string GetText()
	{
		return "#STR_PLAYZ_LOCK_ADMIN_REMOVE";
	}

	// Check client-side conditions
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{

		// If there is no target object, stop here
		if (!target.GetObject())
			return false;

		if (!player.IsPlayZLockAdmin())
			return false;

		if (!PlayZLockConfig.Get().ClientSyncConfig || !PlayZLockConfig.Get().ClientSyncConfig.AllowAdminOpen)
			return false;

		// Check if player is looking directly at combo lock
		CombinationLock lock = CombinationLock.Cast(target.GetObject());

		// If we haven't found a combo lock, stop here
		if (!lock || !lock.IsLockedOnGate())
			return false;

		ConstructionActionData construction_action_data = player.GetConstructionActionData();
		construction_action_data.SetCombinationLock(lock);
		return true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Player.GetIdentity())
			return;

		CombinationLock combination_lock = CombinationLock.Cast(action_data.m_Target.GetObject());
		if (!combination_lock)
			return;

		if (!combination_lock.IsServerLockAdmin(action_data.m_Player))
			return;

		if (!combination_lock.IsLockedOnGate())
			return;

		EntityAI lockParent = combination_lock.GetHierarchyParent();
		combination_lock.UnlockServer(action_data.m_Player, lockParent);
		combination_lock.GetInventory().DropEntity(InventoryMode.SERVER, action_data.m_Player, combination_lock);
		PlayZLockLogger.Log("Admin " + action_data.m_Player.GetIdentity().GetPlainId() + " unlocked lock @ " + action_data.m_Player.GetPosition());
	}
}