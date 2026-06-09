// P2P Market owner column: Terje First Last name instead of vanilla identity name.
// Source Found: DayZExpansion/P2PMarket/.../ExpansionP2PMarketListing.c:54-58

modded class ExpansionP2PMarketListing
{
	override void SetFromItem(EntityAI object, PlayerBase owner = null)
	{
		super.SetFromItem(object, owner);

		if (!owner)
		{
			owner = PlayerBase.Cast(object.GetHierarchyRootPlayer());
		}

		if (!owner)
		{
			return;
		}

		string terjeName = PlayZExpansionTerjeName.Resolve(owner);
		if (terjeName != string.Empty)
		{
			m_OwnerName = terjeName;
		}
	}
}
