class PlayZ_SmershVestTentCargo
{
	static const string VEST_BACKPACK_SLOT = "VestBackpack";

	static bool HasAttachedTent(EntityAI item)
	{
		SmershVest vest = SmershVest.Cast(item);
		if (!vest)
		{
			return false;
		}

		EntityAI attachment = vest.FindAttachmentBySlotName(VEST_BACKPACK_SLOT);
		if (!attachment)
		{
			return false;
		}

		return attachment.IsInherited(TentBase);
	}

	static bool IsAttachedToSmershVest(EntityAI item)
	{
		if (!item)
		{
			return false;
		}

		if (!item.IsInherited(TentBase))
		{
			return false;
		}

		GameInventory inventory = item.GetInventory();
		if (!inventory || !inventory.IsAttachment())
		{
			return false;
		}

		EntityAI parent = item.GetHierarchyParent();
		if (!parent || !parent.IsInherited(SmershVest))
		{
			return false;
		}

		InventoryLocation il = new InventoryLocation();
		if (!inventory.GetCurrentInventoryLocation(il))
		{
			return false;
		}

		return IsVestBackpackTentSlot(il.GetSlot());
	}

	static bool CanAttachTentToVest(SmershVest vest)
	{
		if (!vest)
		{
			return false;
		}

		EntityAI parent = vest.GetHierarchyParent();
		if (!parent)
		{
			return true;
		}

		if (parent.IsMan())
		{
			return true;
		}

		return false;
	}

	static bool IsVestBackpackTentSlot(int slotId)
	{
		return slotId == InventorySlots.GetSlotIdFromString(VEST_BACKPACK_SLOT);
	}
}
