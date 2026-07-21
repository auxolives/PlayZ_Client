class DryBag_Hazmat extends DryBag_ColorBase
{
	override set<int> GetAttachmentExclusionMaskAll(int slotId)
	{
		return PlayZ_NBCGearStorage.GetHostAttachmentExclusionMaskAll(this, slotId);
	}

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
