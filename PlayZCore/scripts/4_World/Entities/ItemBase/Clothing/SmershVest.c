modded class SmershVest
{
	override bool CanPutInCargo(EntityAI parent)
	{
		if (PlayZ_SmershVestTentCargo.HasAttachedTent(this))
		{
			return false;
		}

		return super.CanPutInCargo(parent);
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (attachment && attachment.IsInherited(TentBase))
		{
			if (PlayZ_SmershVestTentCargo.IsVestBackpackTentSlot(slotId))
			{
				if (!PlayZ_SmershVestTentCargo.CanAttachTentToVest(this))
				{
					return false;
				}
			}
		}

		return super.CanReceiveAttachment(attachment, slotId);
	}

	override bool CanLoadAttachment(EntityAI attachment)
	{
		if (attachment && attachment.IsInherited(TentBase))
		{
			if (!PlayZ_SmershVestTentCargo.CanAttachTentToVest(this))
			{
				return false;
			}
		}

		return super.CanLoadAttachment(attachment);
	}
}
