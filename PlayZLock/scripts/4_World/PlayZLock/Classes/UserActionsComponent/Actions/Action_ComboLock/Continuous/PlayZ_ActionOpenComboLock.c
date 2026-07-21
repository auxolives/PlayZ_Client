class PlayZ_ActionOpenComboLockCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(PlayZLockConfig.Get().ClientSyncConfig.DialTime);
	}
};

class PlayZ_ActionOpenComboLock : ActionContinuousBase
{
	void PlayZ_ActionOpenComboLock()
	{
		m_CallbackClass = PlayZ_ActionOpenComboLockCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "#open";
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

		// If there is no object, stop here
		if (!target.GetObject() || !PlayZLockConfig.Get().ClientSyncConfig)
			return false;

		// If server has enabled instant open or player is an admin, stop here (as Instant action is used instead)
		if (PlayZLockConfig.Get().ClientSyncConfig.InstantOpen || player.IsPlayZLockAdmin())
			return false;

		// Check if player is looking directly at combo lock
		CombinationLock lock = CombinationLock.Cast(target.GetObject());

		// If we haven't found a combo lock or it's not locked onto the gate, stop here.
		if (!lock || !lock.IsLockedOnGate())
			return false;

		// If client has not received lock perms, don't display action
		if (!lock.HasReceivedClientsidePerms())
			return false;

		// Set construction action data for the player (referenced in other actions related to combo lock on both client & server)
		ConstructionActionData construction_action_data = player.GetConstructionActionData();
		construction_action_data.SetCombinationLock(lock);

		// Check action condition client (player has client permission & is not managing the lock)
		return lock.IsPermittedToOpen(player) && !lock.IsManagingLockClient() && !PlayZLockHelper.IsOpen(lock.GetHierarchyParent());
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (PlayZLockConfig.Get().ClientSyncConfig.InstantOpen)
			return;

		if (!action_data.m_Player || !action_data.m_Player.GetIdentity())
			return;

		CombinationLock lock = CombinationLock.Cast(action_data.m_Target.GetObject());
		if (!lock)
			return;

		if (!lock.IsLockedOnGate() || !lock.IsPermittedToOpen(action_data.m_Player))
			return;

		lock.IncreaseSimulatedDialChanges();

		if (lock.GetSimulatedDialChangeCount() >= (lock.GetLockDigits() * PlayZLockConfig.Get().ServerConfig.DigitMultiplier))
		{
			EntityAI lockParent = lock.GetHierarchyParent();
			PlayZLockHelper.Open(lockParent);

			if (PlayZLockConfig.Get().ServerConfig.UnlockOnOpen)
				lock.UnlockServerPlayZ(action_data.m_Player, lockParent);

			PlayZLockLogger.Log("Player " + action_data.m_Player.GetIdentity().GetPlainId() + " opened lock @ " + action_data.m_Player.GetPosition());
		}
	}

	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);

		if (!action_data.m_Player || !action_data.m_Player.GetIdentity())
			return;

		CombinationLock lock = CombinationLock.Cast(action_data.m_Target.GetObject());
		if (lock)
			lock.ResetSimulatedDialChanges();
	}
}