modded class DrysackBag_ColorBase
{
	override bool IsTerjeRadiationAccumulated()
	{
		return false;
	}

	override float GetTerjeRadiationInventoryIsolation()
	{
		return 0.95;
	}
}
