// Client-side Terje name gating and display for world UI (nametags, corpse cursor).
// Source Found: TerjeStartScreen/Scripts/5_Mission/ActionTargetsCursor.c:20-44 (DisplayPlayerNamesMode)

class PlayZExpansionTerjeNameUI
{
	static bool ShouldShowName(PlayerBase player, bool isDeadTarget)
	{
		if (!player)
		{
			return false;
		}

		int nameDisplayMode = -1;
		if (!GetTerjeSettingInt(TerjeSettingsCollection.STARTSCREEN_DISPLAY_PLAYER_NAMES_MODE, nameDisplayMode))
		{
			return true;
		}

		if (nameDisplayMode < 0)
		{
			return false;
		}

		if (nameDisplayMode == 0)
		{
			return true;
		}

		if (isDeadTarget)
		{
			if (nameDisplayMode == 1)
			{
				return true;
			}

			if (nameDisplayMode == 2 || nameDisplayMode == 3)
			{
				return player.GetTerjeFaceVisible();
			}
		}
		else
		{
			if (nameDisplayMode == 2)
			{
				return player.GetTerjeFaceVisible();
			}
		}

		return false;
	}

	static string ResolveClientName(PlayerBase player, out bool needsRequest)
	{
		needsRequest = false;

		if (!player)
		{
			return string.Empty;
		}

		string charName = player.GetTerjeCharacterName();
		if (charName == string.Empty)
		{
			needsRequest = true;
			return string.Empty;
		}

		if (player.GetIdentity())
		{
			string identityName = player.GetIdentity().GetName();
			if (charName == identityName)
			{
				needsRequest = true;
				return string.Empty;
			}
		}

		return charName;
	}

	static void RequestName(PlayerBase player)
	{
		if (!player)
		{
			return;
		}

		player.TerjeRPCSingleParam("tss.name.req", null, true);
	}
}
