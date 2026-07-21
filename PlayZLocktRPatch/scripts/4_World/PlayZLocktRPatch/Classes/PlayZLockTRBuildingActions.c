class PlayZLockTRBuildingActions
{
	static void AddLockActions(ItemBase building)
	{
		if (!building)
			return;

		building.AddAction(PlayZ_ActionNextCombinationLockDialOnFence);
		building.AddAction(PlayZ_ActionRemoveComboLock);
		building.AddAction(PlayZ_ActionOpenComboLockFence);
		building.AddAction(PlayZ_ActionOpenComboLockInstantFence);
		building.AddAction(PlayZ_ActionDialCombinationLockOnFence);
		building.AddAction(PlayZ_ActionManageCombinationLockOnFence);
		building.AddAction(PlayZ_ActionRemoveCombinationLockOnFence);
		building.AddAction(PlayZ_ActionAdminCombinationLockOnFence);
	}

	static void RelockOnClose(EntityAI building)
	{
		#ifdef SERVER
		CombinationLock lock = PlayZLockHelper.GetCombinationLock(building);
		if (lock && lock.IsTakeable())
		{
			lock.LockServer(building, true);
		}
		#endif
	}
}
