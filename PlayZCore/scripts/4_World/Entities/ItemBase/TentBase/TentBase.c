modded class TentBase
{
	override bool CanDisplayCargo()
	{
		if (PlayZ_SmershVestTentCargo.IsAttachedToSmershVest(this))
		{
			return false;
		}

		return super.CanDisplayCargo();
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		if (PlayZ_SmershVestTentCargo.IsAttachedToSmershVest(this))
		{
			return false;
		}

		return super.CanReceiveItemIntoCargo(item);
	}

	override bool CanLoadItemIntoCargo(EntityAI item)
	{
		if (PlayZ_SmershVestTentCargo.IsAttachedToSmershVest(this))
		{
			return false;
		}

		return super.CanLoadItemIntoCargo(item);
	}
}
