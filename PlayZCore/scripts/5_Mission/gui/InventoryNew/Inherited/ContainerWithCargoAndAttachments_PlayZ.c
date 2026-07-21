modded class ContainerWithCargoAndAttachments
{
	override void AttachmentAddedEx(EntityAI item, string slot, EntityAI parent, bool immedUpdate = true)
	{
		if (PlayZ_NBCGearStorage.ShouldHideAttachmentCargo(item))
		{
			return;
		}

		super.AttachmentAddedEx(item, slot, parent, immedUpdate);
	}
}
