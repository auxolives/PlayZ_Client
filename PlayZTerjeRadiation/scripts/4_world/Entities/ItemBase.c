modded class ItemBase
{
	protected float PlayZ_GetTerjeHierarchyIsolation()
	{
		float isolation = 0;
		ItemBase parentItem;
		EntityAI parent = GetHierarchyParent();
		while (parent)
		{
			if (ItemBase.CastTo(parentItem, parent))
			{
				isolation += parentItem.GetTerjeRadiationInventoryIsolation();
			}
			else
			{
				break;
			}

			parent = parent.GetHierarchyParent();
		}

		return Math.Clamp(isolation, 0, 1);
	}

	override bool AddTerjeRadiation(float rAmount)
	{
		if (rAmount > 0)
		{
			float leakFactor = 1.0 - PlayZ_GetTerjeHierarchyIsolation();
			if (leakFactor <= 0)
			{
				return false;
			}

			rAmount *= leakFactor;
		}

		return super.AddTerjeRadiation(rAmount);
	}
}
