modded class BaseBuildingBase
{
	override void OnPartDismantledServer(notnull Man player, string part_name, int action_id)
	{
		super.OnPartDismantledServer(player, part_name, action_id);
		PlayZLockTRPartHooks.HandleAnchorPartRemoved(this, player, part_name);
	}

	override void OnPartDestroyedServer(Man player, string part_name, int action_id, bool destroyed_by_connected_part = false)
	{
		super.OnPartDestroyedServer(player, part_name, action_id, destroyed_by_connected_part);
		PlayZLockTRPartHooks.HandleAnchorPartRemoved(this, player, part_name);
	}
}
