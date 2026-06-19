class PlayZRadiationManager
{
	private static ref PlayZRadiationConfig m_Radiation;

	static PlayZRadiationConfig GetRadiation()
	{
		if (!m_Radiation)
		{
			m_Radiation = new PlayZRadiationConfig();
			if (GetGame().IsServer())
			{
				m_Radiation.Load();
			}
		}
		return m_Radiation;
	}

	static void SyncRadiation(PlayerIdentity identity = null)
	{
		if (!GetGame().IsServer())
		{
			return;
		}

		PlayZRadiationConfig cfg = GetRadiation();
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(cfg.m_EnableEnvSaturation);
		rpc.Write(cfg.m_EnableEnvGrain);
		rpc.Write(cfg.m_EnableBodyVignette);
		rpc.Write(cfg.m_EnableBodyFever);
		rpc.Write(cfg.m_EnableBodyRadial);
		rpc.Write(cfg.m_EnableBodyGhost);
		rpc.Write(cfg.m_EnvSatDoseMin);
		rpc.Write(cfg.m_EnvSatDoseMax);
		rpc.Write(cfg.m_EnvGrainDoseMin);
		rpc.Write(cfg.m_EnvGrainDoseMax);
		rpc.Write(cfg.m_BodyVignetteMin);
		rpc.Write(cfg.m_BodyVignetteMax);
		rpc.Write(cfg.m_BodyFeverMin);
		rpc.Write(cfg.m_BodyFeverMax);
		rpc.Write(cfg.m_BodyRadialMin);
		rpc.Write(cfg.m_BodyRadialMax);
		rpc.Write(cfg.m_BodyGhostMin);
		rpc.Write(cfg.m_BodyGhostMax);
		rpc.Write(cfg.m_BodyVignetteIntensityMax);
		rpc.Write(cfg.m_BodyFeverIntensityMax);
		rpc.Write(cfg.m_BodyRadialPowerMax);
		rpc.Write(cfg.m_EnvGrainSharpnessMax);
		rpc.Write(cfg.m_EnvGrainSizeMin);
		rpc.Write(cfg.m_EnvGrainSizeDefault);
		rpc.Write(cfg.m_EnvNoiseMultMax);
		rpc.Write(cfg.m_SickVignetteMin);
		rpc.Write(cfg.m_SickVignetteMax);
		rpc.Write(cfg.m_SickFeverMin);
		rpc.Write(cfg.m_SickFeverMax);
		rpc.Write(cfg.m_SickRadialMin);
		rpc.Write(cfg.m_SickRadialMax);
		rpc.Write(cfg.m_SickGhostMin);
		rpc.Write(cfg.m_SickGhostMax);
		rpc.Write(cfg.m_SickSatMin);
		rpc.Write(cfg.m_SickSatMax);
		rpc.Write(cfg.m_SickGrainMin);
		rpc.Write(cfg.m_SickGrainMax);
		rpc.Write(cfg.m_ProtectHealthEnabled);
		rpc.Write(cfg.m_ProtectHealthFloor);
		rpc.Write(cfg.m_ProtectMaxPenalty);
		rpc.Send(null, PlayZRadiationRPCs.SYNC_RADIATION, true, identity);
	}

	static void OnRadiationRPC(ParamsReadContext ctx)
	{
		PlayZRadiationConfig cfg = GetRadiation();
		if (!ctx.Read(cfg.m_EnableEnvSaturation))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnableEnvGrain))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnableBodyVignette))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnableBodyFever))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnableBodyRadial))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnableBodyGhost))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnvSatDoseMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnvSatDoseMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnvGrainDoseMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnvGrainDoseMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_BodyVignetteMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_BodyVignetteMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_BodyFeverMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_BodyFeverMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_BodyRadialMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_BodyRadialMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_BodyGhostMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_BodyGhostMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_BodyVignetteIntensityMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_BodyFeverIntensityMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_BodyRadialPowerMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnvGrainSharpnessMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnvGrainSizeMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnvGrainSizeDefault))
		{
			return;
		}
		if (!ctx.Read(cfg.m_EnvNoiseMultMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickVignetteMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickVignetteMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickFeverMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickFeverMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickRadialMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickRadialMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickGhostMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickGhostMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickSatMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickSatMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickGrainMin))
		{
			return;
		}
		if (!ctx.Read(cfg.m_SickGrainMax))
		{
			return;
		}
		if (!ctx.Read(cfg.m_ProtectHealthEnabled))
		{
			return;
		}
		if (!ctx.Read(cfg.m_ProtectHealthFloor))
		{
			return;
		}
		if (!ctx.Read(cfg.m_ProtectMaxPenalty))
		{
			return;
		}
	}
}
