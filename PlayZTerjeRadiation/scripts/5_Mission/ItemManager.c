modded class ItemManager
{
	override void PrepareTooltip(EntityAI item, int x = 0, int y = 0)
	{
		super.PrepareTooltip(item, x, y);

		if (item && m_TooltipWidget && !IsDragging())
		{
			InspectMenuNew.UpdateItemInfoRadProtection(m_TooltipWidget, item);
			InspectMenuNew.UpdateItemInfoRadContamination(m_TooltipWidget, item);
		}
	}

	void PlayZRefreshHoveredItemTooltip()
	{
		if (m_HoveredItem)
		{
			PrepareTooltip(m_HoveredItem);
		}
	}
}
