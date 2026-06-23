class DryBag_Hazmat extends DryBag_ColorBase
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
		{
			return false;
		}

		if (!attachment)
		{
			return false;
		}

		string slotName = InventorySlots.GetSlotName(slotId);
		if (slotName == "HazmatBag_Jacket")
		{
			return attachment.IsInherited(NBCJacketBase);
		}
		if (slotName == "HazmatBag_Pants")
		{
			return attachment.IsInherited(NBCPantsBase);
		}
		if (slotName == "HazmatBag_Hood")
		{
			return attachment.IsInherited(NBCHoodBase);
		}
		if (slotName == "HazmatBag_Gloves")
		{
			return attachment.IsInherited(NBCGloves_ColorBase);
		}
		if (slotName == "HazmatBag_Boots")
		{
			return attachment.IsInherited(NBCBootsBase);
		}
		if (slotName == "HazmatBag_GasMask")
		{
			return attachment.IsInherited(MaskBase);
		}

		return true;
	}
}
