modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type != PlayZNoBuildZonesRPCs.SYNC_CONFIG)
			return;

		Param1<PlayZNoBuildZonesConfig> data;
		if (!ctx.Read(data) || !data || !data.param1)
			return;

		data.param1.Normalize();
		PlayZNoBuildZonesState.SetConfig(data.param1);
	}
}
