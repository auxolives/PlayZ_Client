class PlayZ_NBCGearStorage
{
	static bool IsNBCStorageSlot(string slotName)
	{
		return slotName.IndexOf("HazmatBag_") == 0;
	}

	static bool CanReceiveNBCAttachment(EntityAI attachment, string slotName)
	{
		if (!attachment)
		{
			return false;
		}

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
		if (slotName == "HazmatBag_Filter1" || slotName == "HazmatBag_Filter2" || slotName == "HazmatBag_Filter3" || slotName == "HazmatBag_Filter4")
		{
			if (attachment.IsInherited(GasMask_Filter))
			{
				return true;
			}
			return attachment.IsKindOf("GP5GasMask_Filter");
		}

		return false;
	}
}
