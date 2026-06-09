modded class PlayerBase
{
	void PlayZ_ApplySyncedWeatherTempMod(float mod)
	{
		if (m_Environment)
		{
			m_Environment.PlayZ_ApplySyncedTempMod(mod);
		}
	}
}
