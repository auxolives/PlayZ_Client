modded class AttachmentCategoriesRow
{
	override void RefreshSlot(int row, int column, int slot_id, string slot_name)
	{
		super.RefreshSlot(row, column, slot_id, slot_name);

		SlotsIcon icon = m_AttachmentsContainer.GetSlotsIcon(row, column);
		if (!icon)
		{
			return;
		}

		int slot_id_ = icon.GetSlotID();
		EntityAI item = m_Entity.GetInventory().FindAttachment(slot_id_);
		if (!item || !PlayZ_NBCGearStorage.ShouldHideAttachmentCargo(item))
		{
			return;
		}

		ContainerWithCargo cont = m_AttachmentCargos.Get(slot_id_);
		if (!cont)
		{
			return;
		}

		m_AttachmentCargos.Remove(slot_id_);
		Remove(cont);
		Container.Cast(cont.m_Parent).Remove(cont);
		icon.SetContainer(null);
		icon.GetRadialIconPanel().Show(false);
	}
}
