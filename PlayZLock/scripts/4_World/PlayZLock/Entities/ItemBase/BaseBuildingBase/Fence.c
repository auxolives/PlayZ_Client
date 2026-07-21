modded class Fence
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(PlayZ_ActionNextCombinationLockDialOnFence);
		AddAction(PlayZ_ActionRemoveComboLock);
		AddAction(PlayZ_ActionOpenComboLockFence);
		AddAction(PlayZ_ActionOpenComboLockInstantFence);
		AddAction(PlayZ_ActionDialCombinationLockOnFence);
		AddAction(PlayZ_ActionManageCombinationLockOnFence);
		AddAction(PlayZ_ActionRemoveCombinationLockOnFence);
		AddAction(PlayZ_ActionAdminCombinationLockOnFence);
	}

	override void CloseFence()
	{
		super.CloseFence();

		#ifdef SERVER
		if (GetCombinationLock() && GetCombinationLock().IsTakeable())
		{
			GetCombinationLock().LockServer(this, true);
		}
		#endif
	}
};
