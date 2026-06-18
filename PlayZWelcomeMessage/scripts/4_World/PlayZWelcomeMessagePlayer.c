modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type != PlayZWelcomeMessageRPCs.SYNC_CONFIG)
		{
			return;
		}

		Param1<PlayZWelcomeMessageConfig> data;
		if (!ctx.Read(data) || !data || !data.param1)
		{
			return;
		}

		if (!data.param1.Enabled)
		{
			return;
		}

		data.param1.Normalize();
		PlayZWelcomeMessageClientState.SetPendingConfig(data.param1);
	}
}
