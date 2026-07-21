class PlayZ_ActionAdminCombinationLockOnFenceCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(3);
	}
}

class PlayZ_ActionAdminCombinationLockOnFence : ActionContinuousBase
{
	void PlayZ_ActionAdminCombinationLockOnFence()
	{
		m_CallbackClass = PlayZ_ActionAdminCombinationLockOnFenceCB;
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
		if (!target.GetObject() || !PlayZLockConfig.Get().ClientSyncConfig)
			return false;

		// If player does not have admin authority, stop here
		if (!player.IsPlayZLockAdmin() || !PlayZLockConfig.Get().ClientSyncConfig.AllowAdminOpen)
			return false;

		// Check if player is looking at fence
		CombinationLock lock = PlayZLockHelper.GetCombinationLock(target.GetObject());

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

		CombinationLock lock = PlayZLockHelper.GetCombinationLock(action_data.m_Target.GetObject());
		if (!lock)
			return;

		if (!lock.IsServerLockAdmin(action_data.m_Player))
			return;

		if (!lock.IsLockedOnGate())
			return;

		EntityAI lockParent = lock.GetHierarchyParent();
		lock.UnlockServer(action_data.m_Player, lockParent);
		lock.GetInventory().DropEntity(InventoryMode.SERVER, action_data.m_Player, lock);
		PlayZLockLogger.Log("Admin " + action_data.m_Player.GetIdentity().GetPlainId() + " removed lock @ " + action_data.m_Player.GetPosition());
	}
}