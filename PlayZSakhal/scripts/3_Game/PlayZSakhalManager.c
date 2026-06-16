class PlayZSakhalManager
{
	private static ref PlayZSakhalConfig m_Sakhal;

	static PlayZSakhalConfig GetSakhal()
	{
		if (!m_Sakhal)
		{
			m_Sakhal = new PlayZSakhalConfig();
			if (GetGame().IsServer())
				m_Sakhal.Load();
		}
		return m_Sakhal;
	}

	static void SyncSakhal(PlayerIdentity identity = null)
	{
		if (!GetGame().IsServer())
			return;

		PlayZSakhalConfig cfg = GetSakhal();
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(cfg.m_EnableHypoxiaPPE);
		rpc.Write(cfg.m_EnableHypoxiaStamina);
		rpc.Write(cfg.m_AltStartM);
		rpc.Write(cfg.m_AltFullM);
		rpc.Write(cfg.m_ClientChromMax);
		rpc.Write(cfg.m_ClientBlurMax);
		rpc.Write(cfg.m_ClientVignetteMax);
		rpc.Send(null, PlayZSakhalRPCs.SYNC_SAKHAL, true, identity);
	}

	static void OnSakhalRPC(ParamsReadContext ctx)
	{
		PlayZSakhalConfig cfg = GetSakhal();
		if (!ctx.Read(cfg.m_EnableHypoxiaPPE))
			return;
		if (!ctx.Read(cfg.m_EnableHypoxiaStamina))
			return;
		if (!ctx.Read(cfg.m_AltStartM))
			return;
		if (!ctx.Read(cfg.m_AltFullM))
			return;
		if (!ctx.Read(cfg.m_ClientChromMax))
			return;
		if (!ctx.Read(cfg.m_ClientBlurMax))
			return;
		if (!ctx.Read(cfg.m_ClientVignetteMax))
			return;
	}
}
