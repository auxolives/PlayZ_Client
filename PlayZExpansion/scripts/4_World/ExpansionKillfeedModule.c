// Killfeed player names: Terje identity with Expansion party-tag prefix preserved.
// Source Found: DayZExpansion/Scripts/.../ExpansionKillFeedModule.c:987-1030

modded class ExpansionKillFeedModule
{
	override string GetIdentityName(Man player)
	{
		PlayerBase pb;
		if (!Class.CastTo(pb, player) || !pb.GetIdentity())
		{
			return super.GetIdentityName(player);
		}

		string name = PlayZExpansionTerjeName.Resolve(pb);
		if (name == string.Empty)
		{
			name = pb.GetIdentity().GetName();
		}

	#ifdef EXPANSIONMODGROUPS
		if (GetExpansionSettings().GetParty().DisplayPartyTag)
		{
			ExpansionPartyData partyData = pb.Expansion_GetParty();
			if (partyData && partyData.GetPartyTag() != string.Empty)
			{
				return string.Format("%1%2", partyData.GetPartyTagFormatted(), name);
			}
		}
	#endif

		return name;
	}
}
