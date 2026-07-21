modded class HandsContainer
{
	override void AttachmentAdded(EntityAI item, string slot, EntityAI parent)
	{
		if (PlayZ_NBCGearStorage.ShouldHideAttachmentCargo(item))
		{
			return;
		}

		super.AttachmentAdded(item, slot, parent);
	}
}
