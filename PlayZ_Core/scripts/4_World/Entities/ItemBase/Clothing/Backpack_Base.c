modded class Backpack_Base
{
	override bool CanDisplayCargo()
	{
		if (PlayZCoreConfig.GetInstance().HideAttachedBackpackCargo && !PlayZ_IsWaistAccessibleBag())
		{
			InventoryLocation il = new InventoryLocation();
			if (GetInventory() && GetInventory().GetCurrentInventoryLocation(il))
			{
				if (il.GetType() == InventoryLocationType.ATTACHMENT && il.GetSlot() == InventorySlots.BACK)
				{
					EntityAI parent = il.GetParent();
					if (parent && parent.IsMan())
					{
						return false;
					}
				}
			}
		}
		return super.CanDisplayCargo();
	}

	protected bool PlayZ_IsWaistAccessibleBag()
	{
		if (IsInherited(DuffelBagSmall_ColorBase)) { return true; }
		if (IsInherited(CanvasBag_ColorBase)) { return true; }
		if (IsInherited(DrysackBag_ColorBase)) { return true; }
		if (IsInherited(ArmyPouch_ColorBase)) { return true; }
		return false;
	}
}
