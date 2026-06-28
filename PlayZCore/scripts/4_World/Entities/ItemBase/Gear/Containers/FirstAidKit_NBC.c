class FirstAidKit_NBC extends FirstAidKit
{
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		return false;
	}

	override bool CanLoadItemIntoCargo(EntityAI item)
	{
		return false;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
		{
			return false;
		}

		string slotName = InventorySlots.GetSlotName(slotId);
		if (!PlayZ_NBCGearStorage.IsNBCStorageSlot(slotName))
		{
			return false;
		}

		return PlayZ_NBCGearStorage.CanReceiveNBCAttachment(attachment, slotName);
	}
}
