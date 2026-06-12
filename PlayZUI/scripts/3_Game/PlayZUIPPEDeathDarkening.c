modded class PPERequester_DeathDarkening
{
	override protected void OnStart(Param par = null)
	{
		if (PlayZDeathScreen_IsCustomDeathActive())
		{
			return;
		}

		super.OnStart(par);
	}
}
