// Expansion floating nametags: Terje identity + DisplayPlayerNamesMode face-cover gate.
// Source Found: DayZExpansion/NameTags/.../IngameHud.c:109-128, 209, 348, 488-512
// Source Found: DayZExpansion/AI/Scripts/5_Mission/DayZExpansion_AI/IngameHud.c:26-48

modded class IngameHud
{
	protected PlayerBase m_PlayZLastNametagNameRequest;

	override protected bool Expansion_ShouldShowPlayerTag(EntityAI entity)
	{
		if (!super.Expansion_ShouldShowPlayerTag(entity))
		{
			return false;
		}

		PlayerBase player = PlayerBase.Cast(entity);
		if (!player || !player.IsMan())
		{
			return true;
		}

		if (!PlayZExpansionTerjeNameUI.ShouldShowName(player, false))
		{
			return false;
		}

		bool needsRequest;
		PlayZExpansionTerjeNameUI.ResolveClientName(player, needsRequest);
		if (needsRequest && player != m_PlayZLastNametagNameRequest)
		{
			m_PlayZLastNametagNameRequest = player;
			PlayZExpansionTerjeNameUI.RequestName(player);
		}

		return true;
	}

	override protected void Expansion_SetPlayerTag(string icon, int iconColor, string nameText, int textColor, float timeslice)
	{
		if (m_CurrentTaggedPlayer)
		{
			bool needsRequest;
			string terjeName = PlayZExpansionTerjeNameUI.ResolveClientName(m_CurrentTaggedPlayer, needsRequest);

			if (terjeName != string.Empty)
			{
				nameText = terjeName;
			}
			else
			{
				if (needsRequest && m_CurrentTaggedPlayer != m_PlayZLastNametagNameRequest)
				{
					m_PlayZLastNametagNameRequest = m_CurrentTaggedPlayer;
					PlayZExpansionTerjeNameUI.RequestName(m_CurrentTaggedPlayer);
				}

				nameText = string.Empty;
			}
		}

		super.Expansion_SetPlayerTag(icon, iconColor, nameText, textColor, timeslice);
	}

	override void Expansion_ShowAggressionCooldown(bool state)
	{
		super.Expansion_ShowAggressionCooldown(false);
	}

	override bool Expansion_IsAggressionCooldownVisible()
	{
		return false;
	}
}
