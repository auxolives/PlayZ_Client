modded class Construction
{
	override void BuildPartServer(notnull Man player, string part_name, int action_id)
	{
		ShelterSite site = ShelterSite.Cast(GetParent());
		if (site)
		{
			float total_health = 0;
			float total_max = 0;
			
			for (int i = 0; i < site.GetInventory().GetAttachmentSlotsCount(); i++)
			{
				int slot = site.GetInventory().GetAttachmentSlotId(i);
				ItemBase item = ItemBase.Cast(site.GetInventory().FindAttachment(slot));
				if (item)
				{
					float qty = item.GetQuantity();
					if (qty <= 0) qty = 1;

					// Weighted average according to material health ratio and total max health
					total_max += item.GetMaxHealth("","Health") * qty;
					total_health += item.GetHealth("","Health") * qty;
				}
			}

			if (total_max > 0)
			{
				// Cache the percentage ratio on the site so OnPartBuiltServer can access it
				// after the new base object is spawned and materials are dropped
				site.m_PlayZ_CalculatedHealth01 = total_health / total_max;
			}
		}

		super.BuildPartServer(player, part_name, action_id);
	}
}
