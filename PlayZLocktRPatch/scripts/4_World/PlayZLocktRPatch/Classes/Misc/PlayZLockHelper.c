modded class PlayZLockHelper
{
	static bool IsPlayZLockTRBuilding(Object obj)
	{
		if (!obj)
			return false;

		if (obj.IsKindOf("tR_Stockade"))
			return true;
		if (obj.IsKindOf("tR_StockadeCorner"))
			return true;
		if (obj.IsKindOf("tR_NarrowDoor"))
			return true;
		if (obj.IsKindOf("tR_MediumDoor"))
			return true;
		if (obj.IsKindOf("tR_Shed"))
			return true;

		return false;
	}

	static bool IsOpen(Object doorGateThingy)
	{
		if (!doorGateThingy)
			return false;

		Fence fence = Fence.Cast(doorGateThingy);
		if (fence)
		{
			return fence.IsOpened();
		}

		if (IsPlayZLockTRBuilding(doorGateThingy))
		{
			BaseBuildingBase building = BaseBuildingBase.Cast(doorGateThingy);
			if (building)
				return building.IsOpened();
		}

		return false;
	}

	static void Open(Object doorGateThingy)
	{
		if (!doorGateThingy)
			return;

		Fence fence = Fence.Cast(doorGateThingy);
		if (fence)
		{
			fence.OpenFence();
			return;
		}

		tR_Stockade stockade = tR_Stockade.Cast(doorGateThingy);
		if (stockade)
		{
			stockade.OpenFence();
			return;
		}

		tR_StockadeCorner corner = tR_StockadeCorner.Cast(doorGateThingy);
		if (corner)
		{
			corner.OpenFence();
			return;
		}

		tR_NarrowDoor narrow = tR_NarrowDoor.Cast(doorGateThingy);
		if (narrow)
		{
			narrow.OpenFence();
			return;
		}

		tR_MediumDoor medium = tR_MediumDoor.Cast(doorGateThingy);
		if (medium)
		{
			medium.OpenFence();
			return;
		}

		tR_Shed shed = tR_Shed.Cast(doorGateThingy);
		if (shed)
		{
			shed.OpenFence();
			return;
		}
	}

	static CombinationLock GetCombinationLock(Object doorGateThingy)
	{
		if (!doorGateThingy)
			return NULL;

		Fence fence = Fence.Cast(doorGateThingy);
		if (fence)
		{
			return fence.GetCombinationLock();
		}

		EntityAI entityObject = EntityAI.Cast(doorGateThingy);
		if (!entityObject)
			return NULL;

		return CombinationLock.Cast(entityObject.FindAttachmentBySlotName("Att_CombinationLock"));
	}
}
