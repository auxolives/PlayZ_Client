// Suppress vanilla corpse identity when Terje name rules block display.
// Source Found: TerjeStartScreen/Scripts/5_Mission/ActionTargetsCursor.c:3-49
// Source Found: scripts/5_Mission/GUI/ActionTargetsCursor.c:794-801 (dead entity -> GetDisplayName)
// Source Found: TerjeCore/Scripts/4_World/Entities/PlayerBase.c:153-165 (GetTerjeCharacterName client fallback = identity name)
// Expansion NameTagsSettings.EnablePlayerTags=0 — not involved in action cursor label.
// COT only prefixes GetActionDesc; InediaInfectedAI only gates corpse cargo count.

modded class ActionTargetsCursor
{
	protected PlayerBase m_PlayZLastCorpseNameRequest;

	override protected string GetItemDesc(ActionBase action)
	{
		string desc = super.GetItemDesc(action);

		int nameDisplayMode = -1;
		if (!GetTerjeSettingInt(TerjeSettingsCollection.STARTSCREEN_DISPLAY_PLAYER_NAMES_MODE, nameDisplayMode))
		{
			return desc;
		}

		if (nameDisplayMode < 0)
		{
			return desc;
		}

		Object tgObject = m_DisplayInteractTarget;
		if (!tgObject && m_Target)
		{
			tgObject = m_Target.GetObject();
		}

		PlayerBase tgPlayer = PlayerBase.Cast(tgObject);
		if (!tgPlayer || tgPlayer.IsAlive())
		{
			m_PlayZLastCorpseNameRequest = null;
			return desc;
		}

		if (!PlayZShouldShowTerjeCorpseName(tgPlayer, nameDisplayMode))
		{
			return string.Empty;
		}

		string characterName = PlayZGetTerjeCorpseDisplayName(tgPlayer);
		if (characterName != string.Empty)
		{
			return characterName;
		}

		PlayZRequestCorpseTerjeName(tgPlayer);
		return string.Empty;
	}

	protected bool PlayZShouldShowTerjeCorpseName(PlayerBase tgPlayer, int nameDisplayMode)
	{
		if (nameDisplayMode == 0)
		{
			return true;
		}

		if (nameDisplayMode == 1)
		{
			return true;
		}

		if (nameDisplayMode == 2)
		{
			return tgPlayer.GetTerjeFaceVisible();
		}

		if (nameDisplayMode == 3)
		{
			return tgPlayer.GetTerjeFaceVisible();
		}

		return false;
	}

	protected string PlayZGetTerjeCorpseDisplayName(PlayerBase tgPlayer)
	{
		string characterName = tgPlayer.GetTerjeCharacterName();
		if (characterName == string.Empty)
		{
			return string.Empty;
		}

		if (tgPlayer.GetIdentity())
		{
			string identityName = tgPlayer.GetIdentity().GetName();
			if (characterName == identityName)
			{
				return string.Empty;
			}
		}

		return characterName;
	}

	protected void PlayZRequestCorpseTerjeName(PlayerBase tgPlayer)
	{
		if (!tgPlayer || tgPlayer == m_PlayZLastCorpseNameRequest)
		{
			return;
		}

		m_PlayZLastCorpseNameRequest = tgPlayer;
		tgPlayer.TerjeRPCSingleParam("tss.name.req", null, true);
	}
}
