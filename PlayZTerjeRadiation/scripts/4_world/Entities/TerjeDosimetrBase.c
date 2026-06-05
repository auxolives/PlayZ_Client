modded class TerjeDosimetrBase
{
	override void OnWorkStart()
	{
		super.OnWorkStart();
		PlayZMarkDosimeterTooltipDirty();
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
		PlayZMarkDosimeterTooltipDirty();
	}

	protected void PlayZMarkDosimeterTooltipDirty()
	{
		if (!g_Game.IsClient())
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (player)
		{
			player.PlayZSetDosimeterTooltipDirty(true);
		}
	}
}
