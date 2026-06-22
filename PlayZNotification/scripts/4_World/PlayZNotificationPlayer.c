modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type != PlayZNotificationRPCs.SYNC_CONFIG)
		{
			return;
		}

		Param1<PlayZNotificationConfig> data;
		if (!ctx.Read(data) || !data || !data.param1)
		{
			return;
		}

		data.param1.Normalize();
		PlayZNotificationClientState.SetConfig(data.param1);
	}
}
