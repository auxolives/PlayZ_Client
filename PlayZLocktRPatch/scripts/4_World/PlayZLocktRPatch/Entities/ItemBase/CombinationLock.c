modded class CombinationLock
{
	override bool IsLockAttached()
	{
		if (super.IsLockAttached())
			return true;

		EntityAI parent = GetHierarchyParent();
		if (parent && PlayZLockHelper.IsPlayZLockTRBuilding(parent))
			return true;

		return false;
	}

	override bool IsLockedOnGate()
	{
		if (IsTakeable())
			return false;

		if (super.IsLockedOnGate())
			return true;

		EntityAI parent = GetHierarchyParent();
		if (parent && PlayZLockHelper.IsPlayZLockTRBuilding(parent) && IsLocked())
			return true;

		return false;
	}

	override void UnlockServer(EntityAI player, EntityAI parent)
	{
		EntityAI unlockParent = parent;
		if (!unlockParent)
			unlockParent = GetHierarchyParent();

		if (unlockParent && PlayZLockHelper.IsPlayZLockTRBuilding(unlockParent))
		{
			UnlockServerPlayZ(player, unlockParent);
			return;
		}

		super.UnlockServer(player, parent);
	}

	void ForceDestroyFromTRBuilding(BaseBuildingBase building)
	{
		#ifdef SERVER
		if (!building || !IsLockAttached())
			return;

		InventoryLocation inventory_location = new InventoryLocation;
		if (GetInventory().GetCurrentInventoryLocation(inventory_location))
			building.GetInventory().SetSlotLock(inventory_location.GetSlot(), false);

		DeleteSafe();
		#endif
	}
}
