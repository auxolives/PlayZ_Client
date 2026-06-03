class PlayZGunPlayManager
{
	private static ref PlayZGunPlayConfig m_GunPlay;

	static PlayZGunPlayConfig GetGunPlay()
	{
		if (!m_GunPlay)
		{
			m_GunPlay = new PlayZGunPlayConfig();
			if (GetGame().IsServer())
				m_GunPlay.Load();
		}
		return m_GunPlay;
	}

	static void SyncGunPlay(PlayerIdentity identity = null)
	{
		if (!GetGame().IsServer())
			return;

		PlayZGunPlayConfig cfg = GetGunPlay();
		ScriptRPC rpc = new ScriptRPC();

		// Vegetation sway penalty
		rpc.Write(cfg.m_EnableVegetationSwayPenalty);
		rpc.Write(cfg.m_VegetationSwayPenaltyScale);
		rpc.Write(cfg.m_VegSnagMinInterval);
		rpc.Write(cfg.m_VegSnagMaxInterval);
		rpc.Write(cfg.m_VegSnagIntensityScale);
		rpc.Write(cfg.m_VegSnagWindScale);

		// ADS entry offset
		rpc.Write(cfg.m_EnableADSEntryOffset);
		rpc.Write(cfg.m_ADSEntryOffsetMaxX);
		rpc.Write(cfg.m_ADSEntryOffsetMaxY);
		rpc.Write(cfg.m_ADSEntryOffsetDecayTime);

		rpc.Send(null, PlayZGunPlayRPCs.SYNC_GUNPLAY, true, identity);
	}

	static void OnGunPlayRPC(ParamsReadContext ctx)
	{
		PlayZGunPlayConfig cfg = GetGunPlay();

		// Vegetation sway penalty
		if (!ctx.Read(cfg.m_EnableVegetationSwayPenalty))   return;
		if (!ctx.Read(cfg.m_VegetationSwayPenaltyScale))    return;
		if (!ctx.Read(cfg.m_VegSnagMinInterval))            return;
		if (!ctx.Read(cfg.m_VegSnagMaxInterval))            return;
		if (!ctx.Read(cfg.m_VegSnagIntensityScale))         return;
		if (!ctx.Read(cfg.m_VegSnagWindScale))              return;

		// ADS entry offset
		if (!ctx.Read(cfg.m_EnableADSEntryOffset))          return;
		if (!ctx.Read(cfg.m_ADSEntryOffsetMaxX))            return;
		if (!ctx.Read(cfg.m_ADSEntryOffsetMaxY))            return;
		if (!ctx.Read(cfg.m_ADSEntryOffsetDecayTime))       return;
	}
}
