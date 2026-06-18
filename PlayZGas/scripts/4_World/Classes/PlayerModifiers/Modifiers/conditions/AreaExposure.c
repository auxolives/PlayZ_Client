modded class AreaExposureMdfr
{
	override void BleedingSourceCreateCheck(PlayerBase player)
	{
		// Gas mask + filter on MASK slot is enough; skip NBC body-slot bleeding.
		if (PluginTransmissionAgents.GetProtectionLevelEx(DEF_CHEMICAL, InventorySlots.MASK, player, true) >= 1.0)
		{
			return;
		}

		super.BleedingSourceCreateCheck(player);
	}
}
