class PlayZLockHelper
{
	static bool IsOpen(Object doorGateThingy)
	{
		if (!doorGateThingy)
			return false;

		Fence fence = Fence.Cast(doorGateThingy);
		if (fence)
		{
			return fence.IsOpened();
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
