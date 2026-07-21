modded class tR_StockadeCorner
{
	override void SetActions()
	{
		super.SetActions();
		PlayZLockTRBuildingActions.AddLockActions(this);
	}

	override void CloseFence()
	{
		super.CloseFence();
		PlayZLockTRBuildingActions.RelockOnClose(this);
	}
}
