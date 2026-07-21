class PlayZLockTRPartHooks
{
	protected static bool IsLockAnchorPart(string part_name)
	{
		return part_name == "tr_door_base" || part_name == "tr_door_base_left" || part_name == "tr_door_base_right" || part_name == "tr_gate" || part_name == "tr_level_1_gate_left" || part_name == "tr_level_1_gate_right";
	}

	static void HandleAnchorPartRemoved(BaseBuildingBase building, Man player, string part_name)
	{
		#ifdef SERVER
		if (!building || !PlayZLockHelper.IsPlayZLockTRBuilding(building))
			return;

		if (!IsLockAnchorPart(part_name))
			return;

		CombinationLock lock = PlayZLockHelper.GetCombinationLock(building);
		if (!lock)
			return;

		lock.ForceDestroyFromTRBuilding(building);

		PlayerBase pb = PlayerBase.Cast(player);
		if (pb && pb.GetIdentity())
			PlayZLockLogger.Log("Destroyed combo lock on " + building.GetType() + " — anchor part removed: " + part_name + " by " + pb.GetIdentity().GetPlainId());
		else
			PlayZLockLogger.Log("Destroyed combo lock on " + building.GetType() + " — anchor part removed: " + part_name);
		#endif
	}
}
