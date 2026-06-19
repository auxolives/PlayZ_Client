modded class TerjeStartScreenContextName
{
	override void Apply(PlayerBase player)
	{
		PlayZTerjeStartScreenNameRules.SanitizeOutputs(m_outputFirstName, m_outputLastName);
		if (!PlayZTerjeStartScreenNameRules.IsFirstNamePresent(m_outputFirstName))
		{
			return;
		}

		super.Apply(player);
	}
}
