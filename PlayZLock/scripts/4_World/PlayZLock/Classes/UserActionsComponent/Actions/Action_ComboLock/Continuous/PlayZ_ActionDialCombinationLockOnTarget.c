modded class ActionDialCombinationLockOnTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{

		m_ActionData.m_ActionComponent = new CAContinuousRepeat(PlayZLockConfig.Get().ClientSyncConfig.DialTime);
	}
}

class PlayZ_ActionDialCombinationLockOnTarget : ActionContinuousBase
{
	void PlayZ_ActionDialCombinationLockOnTarget()
	{
		m_CallbackClass = ActionDialCombinationLockOnTargetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		m_Text = "#dial_combination_lock";
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

	override void OnActionInfoUpdate(PlayerBase player, ActionTarget target, ItemBase item)
	{
		ConstructionActionData construction_action_data = player.GetConstructionActionData();
		m_Text = "#dial_combination_lock " + construction_action_data.GetDialNumberText();
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
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

		// Set player construction data for other functions & actions to reference
		ConstructionActionData construction_action_data = player.GetConstructionActionData();
		construction_action_data.SetCombinationLock(lock);

		// Don't display combo dial if client has open perms and is not managing the lock
		return !lock.IsPermittedToOpen(player) || GetGame().IsDedicatedServer() || (lock.IsManagingLockClient() && !PlayZLockConfig.Get().ClientSyncConfig.OwnerCanRemoveLockWithoutCode);
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (!action_data.m_Player || !action_data.m_Player.GetIdentity())
			return;

		CombinationLock combination_lock = CombinationLock.Cast(action_data.m_Target.GetObject());
		if (!combination_lock)
			return;

		combination_lock.DialNextNumber();

		// Only unlock after digits match the locked combination.
		if (!combination_lock.IsCombinationMatched())
			return;

		EntityAI lockParent = combination_lock.GetHierarchyParent();
		if (!lockParent)
			return;

		combination_lock.UnlockServerPlayZ(action_data.m_Player, lockParent);
		PlayZLockLogger.Log("Player " + action_data.m_Player.GetIdentity().GetPlainId() + " entered pin @ " + action_data.m_Player.GetPosition());
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
}