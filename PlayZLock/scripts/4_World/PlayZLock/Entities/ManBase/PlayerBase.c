modded class PlayerBase
{
	protected bool m_PlayZLockAdmin;

	void SetPlayZLockAdmin(bool state)
	{
		m_PlayZLockAdmin = state;
		SetSynchDirty();
	}

	bool IsPlayZLockAdmin()
	{
		return m_PlayZLockAdmin;
	}

	override void Init()
	{
		super.Init();
		RegisterNetSyncVariableBool("m_PlayZLockAdmin");
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type != PlayZLockRPCs.SYNC_CONFIG)
		{
			return;
		}

		Param1<PlayZLockClientConfig> data;
		if (!ctx.Read(data) || !data || !data.param1)
		{
			return;
		}

		PlayZLockConfig.Get().ApplyClientSync(data.param1);
	}
}
