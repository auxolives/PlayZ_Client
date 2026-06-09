// Suppress vanilla corpse identity when Terje name rules block display.
// Source Found: TerjeStartScreen/Scripts/5_Mission/ActionTargetsCursor.c:3-49
// Source Found: scripts/5_Mission/GUI/ActionTargetsCursor.c:794-801 (dead entity -> GetDisplayName)
// Source Found: TerjeCore/Scripts/4_World/Entities/PlayerBase.c:153-165 (GetTerjeCharacterName client fallback = identity name)

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

		if (!PlayZExpansionTerjeNameUI.ShouldShowName(tgPlayer, true))
		{
			return string.Empty;
		}

		bool needsRequest;
		string characterName = PlayZExpansionTerjeNameUI.ResolveClientName(tgPlayer, needsRequest);
		if (characterName != string.Empty)
		{
			return characterName;
		}

		if (needsRequest)
		{
			if (tgPlayer != m_PlayZLastCorpseNameRequest)
			{
				m_PlayZLastCorpseNameRequest = tgPlayer;
				PlayZExpansionTerjeNameUI.RequestName(tgPlayer);
			}
		}

		return string.Empty;
	}
}
