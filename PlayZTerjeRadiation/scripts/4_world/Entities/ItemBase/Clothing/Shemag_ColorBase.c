//! Dual-slot headgear: rad protection depends on worn slot (Mask vs Headgear).

modded class Shemag_ColorBase
{
	static const float PLAYZ_RAD_PROTECT_MASK = 0.45;
	static const float PLAYZ_RAD_PROTECT_HEADGEAR = 0.28;

	override float GetTerjeProtectionLevel(string protectionType)
	{
		if (protectionType != "radiation")
		{
			return super.GetTerjeProtectionLevel(protectionType);
		}

		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (!player)
		{
			return 0;
		}

		if (player.GetInventory().FindAttachment(InventorySlots.MASK) == this)
		{
			return PLAYZ_RAD_PROTECT_MASK;
		}

		if (player.GetInventory().FindAttachment(InventorySlots.HEADGEAR) == this)
		{
			return PLAYZ_RAD_PROTECT_HEADGEAR;
		}

		return 0;
	}
}
