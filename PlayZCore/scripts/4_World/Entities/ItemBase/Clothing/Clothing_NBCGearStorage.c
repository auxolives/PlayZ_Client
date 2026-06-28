modded class Clothing
{
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		if (PlayZ_NBCGearStorage.IsAttachedToNBCGearStorage(this))
		{
			return false;
		}
		return super.CanReceiveItemIntoCargo(item);
	}

	override bool CanLoadItemIntoCargo(EntityAI item)
	{
		if (PlayZ_NBCGearStorage.IsAttachedToNBCGearStorage(this))
		{
			return false;
		}
		return super.CanLoadItemIntoCargo(item);
	}
}
