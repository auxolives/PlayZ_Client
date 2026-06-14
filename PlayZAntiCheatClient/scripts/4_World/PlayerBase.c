modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == RPC_PLAYZ_AC_CAMERA_REQUEST)
		{
			HandlePlayZACCameraRequest(ctx);
		}
		else if (rpc_type == RPC_PLAYZ_AC_KICK_MESSAGE)
		{
			HandlePlayZACKickMessage(ctx);
		}
	}

	protected void HandlePlayZACCameraRequest(ParamsReadContext ctx)
	{
		if (!GetGame() || GetGame().IsServer())
			return;

		float serverTime;
		if (!ctx.Read(serverTime))
			return;

		vector cameraPos = GetGame().GetCurrentCameraPosition();
		vector localPlayerPos = GetPosition();
		float clientTime = GetGame().GetTime();

		int flags = 0;
		Camera detachedCamera = Camera.GetCurrentCamera();
		if (detachedCamera)
			flags = flags | PLAYZ_AC_CAMERA_FLAG_DETACHED;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(cameraPos);
		rpc.Write(localPlayerPos);
		rpc.Write(clientTime);
		rpc.Write(flags);
		rpc.Send(this, RPC_PLAYZ_AC_CAMERA_RESPONSE, true, NULL);
	}

	protected void HandlePlayZACKickMessage(ParamsReadContext ctx)
	{
		if (!GetGame() || GetGame().IsServer())
			return;

		string reason;
		if (!ctx.Read(reason))
			return;

		PlayZACDeferredKickMessage.Queue(reason);
	}
};
