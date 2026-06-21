// modded class Mich2001Helmet
// {
// 	override bool CanDisplayAttachmentSlot(int slot_id)
// 	{
// 		int slotNvg = InventorySlots.GetSlotIdFromString("NVG");
// 		if (slot_id == slotNvg)
// 			return false;
// 		return super.CanDisplayAttachmentSlot(slot_id);
// 	}

// 	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
// 	{
// 		if (!super.CanReceiveAttachment(attachment, slotId))
// 			return false;

// 		int slotNvg = InventorySlots.GetSlotIdFromString("NVG");
// 		if (slotId == slotNvg)
// 			return false;

// 		NVGoggles nvg;
// 		if (Class.CastTo(nvg, attachment))
// 			return false;

// 		return true;
// 	}

// 	override void SetActions()
// 	{
// 		super.SetActions();
// 		RemoveAction(ActionToggleNVG);
// 	}
// }
