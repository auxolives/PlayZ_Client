class FirstAidKit_NBC extends Container_Base
{
	override set<int> GetAttachmentExclusionMaskAll(int slotId)
	{
		return PlayZ_NBCGearStorage.GetHostAttachmentExclusionMaskAll(this, slotId);
	}

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

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
