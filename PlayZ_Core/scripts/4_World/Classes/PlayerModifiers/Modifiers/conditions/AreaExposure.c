modded class AreaExposureMdfr
{
	override void BleedingSourceCreateCheck(PlayerBase player)
	{
		// [PlayZ] If the player has 1.0 chemical protection on the MASK slot (gas mask + filter), skip bleeding logic.
		// This makes the gas mask sufficient for toxic zones without full NBC gear.
		if (PluginTransmissionAgents.GetProtectionLevelEx(DEF_CHEMICAL, InventorySlots.MASK, player, true) >= 1.0)
		{
			return;
		}

		super.BleedingSourceCreateCheck(player);
	}
}
