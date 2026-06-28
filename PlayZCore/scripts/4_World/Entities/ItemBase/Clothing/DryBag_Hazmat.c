class DryBag_Hazmat extends DryBag_ColorBase
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
		{
			return false;
		}

		string slotName = InventorySlots.GetSlotName(slotId);
		if (PlayZ_NBCGearStorage.IsNBCStorageSlot(slotName))
		{
			return PlayZ_NBCGearStorage.CanReceiveNBCAttachment(attachment, slotName);
		}

		return true;
	}
}
