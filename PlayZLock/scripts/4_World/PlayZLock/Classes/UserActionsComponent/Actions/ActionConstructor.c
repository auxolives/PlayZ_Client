modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);

        // Custom combo lock actions
        actions.Insert(PlayZ_ActionOpenComboLock);
        actions.Insert(PlayZ_ActionRemoveComboLock);
        actions.Insert(PlayZ_ActionOpenComboLockInstant);
        actions.Insert(PlayZ_ActionManageCombinationLockOnTarget);
        actions.Insert(PlayZ_ActionRemoveCombinationLockOnFence);

        // Vanilla combo lock action overrides
        actions.Insert(PlayZ_ActionDialCombinationLockOnTarget);
        actions.Insert(PlayZ_ActionNextCombinationLockDialOnTarget);

        // Fence interact anywhere actions
        actions.Insert(PlayZ_ActionOpenComboLockFence);
        actions.Insert(PlayZ_ActionOpenComboLockInstantFence);
        actions.Insert(PlayZ_ActionManageCombinationLockOnFence);
        actions.Insert(PlayZ_ActionNextCombinationLockDialOnFence);
        actions.Insert(PlayZ_ActionDialCombinationLockOnFence);

        // Admin actions
        actions.Insert(PlayZ_ActionAdminCombinationLockOnTarget);
        actions.Insert(PlayZ_ActionAdminCombinationLockOnFence);
    }
}