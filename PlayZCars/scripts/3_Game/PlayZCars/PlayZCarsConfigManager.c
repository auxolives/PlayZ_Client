class PlayZCarsConfigManager
{
	protected static ref PlayZCarsConfig s_Config;

	static PlayZCarsConfig Get()
	{
		if (!s_Config)
		{
			if (GetGame() && !GetGame().IsServer())
			{
				s_Config = new PlayZCarsConfig();
				s_Config.SetDefaults();
			}
			else
			{
				s_Config = PlayZCarsConfig.LoadFromProfile();
			}
		}

		return s_Config;
	}
}
