// Server-side Terje character name for Expansion meta surfaces (P2P, killfeed, chat).
// Source Found: TerjeStartScreen/Scripts/4_World/Entities/PlayerBase.c:102-124 (server GetTerjeCharacterName)

class PlayZExpansionTerjeName
{
	static string Resolve(PlayerBase player)
	{
		if (!player)
		{
			return string.Empty;
		}

		string charName = player.GetTerjeCharacterName();
		if (charName != string.Empty)
		{
			return charName;
		}

		if (player.GetIdentity())
		{
			return player.GetIdentity().GetName();
		}

		return string.Empty;
	}
}
