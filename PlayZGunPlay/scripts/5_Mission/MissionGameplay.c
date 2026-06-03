modded class MissionGameplay
{
	override void OnInit()
	{
		super.OnInit();
		DayZGame.Event_OnRPC.Insert(OnPlayZGunPlayRPC);
	}

	void ~MissionGameplay()
	{
		if (DayZGame.Event_OnRPC)
			DayZGame.Event_OnRPC.Remove(OnPlayZGunPlayRPC);
	}

	void OnPlayZGunPlayRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if (rpc_type == PlayZGunPlayRPCs.SYNC_GUNPLAY)
		{
			PlayZGunPlayManager.OnGunPlayRPC(ctx);
		}
	}
}
