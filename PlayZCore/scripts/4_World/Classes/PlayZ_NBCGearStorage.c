class PlayZ_NBCGearStorage
{
	static bool IsNBCStorageSlot(string slotName)
	{
		return slotName.IndexOf("NBC_") == 0;
	}

	static bool IsNBCGearStorageHost(EntityAI entity)
	{
		if (!entity)
		{
			return false;
		}
		if (entity.IsKindOf("DryBag_Hazmat"))
		{
			return true;
		}
		return entity.IsKindOf("FirstAidKit_NBC");
	}

	// Stored NBC kit pieces are not worn; their mask/headgear exclusions must not block equipping the host.
	static set<int> GetHostAttachmentExclusionMaskAll(EntityAI host, int slotId)
	{
		set<int> values = new set<int>();
		set<int> slotValues = host.GetAttachmentExclusionMaskSlot(slotId);
		if (slotValues)
		{
			values.InsertSet(slotValues);
		}
		values.InsertSet(host.GetAttachmentExclusionMaskGlobal());
		return values;
	}

	static bool IsAttachedToNBCGearStorage(EntityAI item)
	{
		if (!item)
		{
			return false;
		}
		if (!item.GetInventory().IsAttachment())
		{
			return false;
		}
		return IsNBCGearStorageHost(item.GetHierarchyParent());
	}

	static bool ShouldHideAttachmentCargo(EntityAI item)
	{
		if (!item)
		{
			return false;
		}
		if (!item.GetInventory().GetCargo())
		{
			return false;
		}
		if (PlayZ_SmershVestTentCargo.IsAttachedToSmershVest(item))
		{
			return true;
		}
		return !item.CanDisplayCargo();
	}

	static bool HasCargoContents(EntityAI item)
	{
		GameInventory inventory = item.GetInventory();
		if (!inventory)
		{
			return false;
		}
		CargoBase cargo = inventory.GetCargo();
		if (!cargo)
		{
			return false;
		}
		return cargo.GetItemCount() > 0;
	}

	static bool IsNBCClothingStorageSlot(string slotName)
	{
		if (slotName == "NBC_Jacket")
		{
			return true;
		}
		if (slotName == "NBC_Pants")
		{
			return true;
		}
		if (slotName == "NBC_Hood")
		{
			return true;
		}
		if (slotName == "NBC_Gloves")
		{
			return true;
		}
		return slotName == "NBC_Boots";
	}

	static bool CanReceiveNBCAttachment(EntityAI attachment, string slotName)
	{
		if (!attachment)
		{
			return false;
		}

		if (slotName == "NBC_Jacket")
		{
			if (!attachment.IsInherited(NBCJacketBase))
			{
				return false;
			}
		}
		else if (slotName == "NBC_Pants")
		{
			if (!attachment.IsInherited(NBCPantsBase))
			{
				return false;
			}
		}
		else if (slotName == "NBC_Hood")
		{
			if (!attachment.IsInherited(NBCHoodBase))
			{
				return false;
			}
		}
		else if (slotName == "NBC_Gloves")
		{
			if (!attachment.IsInherited(NBCGloves_ColorBase))
			{
				return false;
			}
		}
		else if (slotName == "NBC_Boots")
		{
			if (!attachment.IsInherited(NBCBootsBase))
			{
				return false;
			}
		}
		else if (slotName == "NBC_GasMask")
		{
			if (!attachment.IsInherited(MaskBase))
			{
				return false;
			}
		}
		else if (slotName == "NBC_Filter1" || slotName == "NBC_Filter2" || slotName == "NBC_Filter3" || slotName == "NBC_Filter4")
		{
			if (attachment.IsInherited(GasMask_Filter))
			{
				return true;
			}
			return attachment.IsKindOf("GP5GasMask_Filter");
		}
		else
		{
			return false;
		}

		if (IsNBCClothingStorageSlot(slotName) && HasCargoContents(attachment))
		{
			return false;
		}

		return true;
	}
}
