modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		PlayZLockConfig.Get();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		if (!player || !identity)
		{
			return;
		}

		PlayZLockConfig cfg = PlayZLockConfig.Get();
		if (!cfg)
		{
			return;
		}

		if (cfg.IsAdmin(identity))
		{
			player.SetPlayZLockAdmin(true);
		}

		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayZLock_SendConfig, 500, false, player, identity);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayZLock_SendConfig, 2500, false, player, identity);
	}

	protected void PlayZLock_SendConfig(PlayerBase player, PlayerIdentity identity)
	{
		if (!player || !identity)
		{
			return;
		}

		PlayZLockConfig cfg = PlayZLockConfig.Get();
		if (!cfg || !cfg.ClientSyncConfig)
		{
			return;
		}

		GetGame().RPCSingleParam(player, PlayZLockRPCs.SYNC_CONFIG, new Param1<PlayZLockClientConfig>(cfg.ClientSyncConfig), true, identity);
	}
}
