modded class TerjeRadTent
{
	override bool IsValidTerjeRadTentToWork()
	{
		if (!super.IsValidTerjeRadTentToWork())
		{
			return false;
		}

		ItemBase canister = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("CanisterGasoline")));
		if (!canister || canister.GetIsFrozen())
		{
			return false;
		}

		if (ActionWashRadioactiveItems.GetTerjeRadiationCleanupForce(canister) <= 0)
		{
			return false;
		}

		return true;
	}

	override void OnWorkTerjeServerLogic()
	{
		ItemBase canister = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("CanisterGasoline")));
		if (canister && canister.GetIsFrozen())
		{
			if (HasEnergyManager() && GetCompEM().CanSwitchOff())
			{
				GetCompEM().SwitchOff();
			}
			return;
		}

		super.OnWorkTerjeServerLogic();
	}
}
