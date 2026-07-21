modded class Container_Base
{
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		if (PlayZ_SmershVestTentCargo.HasAttachedTent(item))
		{
			return false;
		}

		return super.CanReceiveItemIntoCargo(item);
	}

	override bool CanLoadItemIntoCargo(EntityAI item)
	{
		if (PlayZ_SmershVestTentCargo.HasAttachedTent(item))
		{
			return false;
		}

		return super.CanLoadItemIntoCargo(item);
	}
}
