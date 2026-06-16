//! Sakhal hypoxia: chrom + vignette + Gauss blur (1s fade) on dedicated requester; sprint breath audio.

modded class MissionGameplay
{
	protected float m_PlayZ_HypoxiaSoundCooldownUntil;
	protected ref PPERequester_Hypoxia m_PlayZHypoxiaPPE;
	protected float m_PlayZHypoxiaChromSmoothed;
	protected float m_PlayZHypoxiaBlurSmoothed;
	protected float m_PlayZHypoxiaVignetteSmoothed;
	protected bool m_PlayZHypoxiaPPEWarned;

	override void OnInit()
	{
		super.OnInit();
		DayZGame.Event_OnRPC.Insert(OnPlayZSakhalRPC);
	}

	void ~MissionGameplay()
	{
		if (DayZGame.Event_OnRPC)
			DayZGame.Event_OnRPC.Remove(OnPlayZSakhalRPC);
	}

	void OnPlayZSakhalRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if (rpc_type == PlayZSakhalRPCs.SYNC_SAKHAL)
			PlayZSakhalManager.OnSakhalRPC(ctx);
	}

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		if (GetGame().IsDedicatedServer())
			return;

		if (!Hypoxia.IsSakhalWorld())
		{
			m_PlayZHypoxiaChromSmoothed = 0;
			m_PlayZHypoxiaBlurSmoothed = 0;
			m_PlayZHypoxiaVignetteSmoothed = 0;
			PlayZ_StopHypoxiaPPE();
			return;
		}

		if (!PlayZSakhalManager.GetSakhal().m_EnableHypoxiaPPE)
		{
			m_PlayZHypoxiaChromSmoothed = 0;
			m_PlayZHypoxiaBlurSmoothed = 0;
			m_PlayZHypoxiaVignetteSmoothed = 0;
			PlayZ_StopHypoxiaPPE();
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player)
			return;

		float alt = player.GetPosition()[1];
		float targetChrom = 0;
		float targetBlur = 0;
		float targetVignette = 0;
		if (Hypoxia.IsHypoxicAltitude(alt))
		{
			targetChrom = Hypoxia.GetHypoxiaChromForPPE(player, alt);
			targetBlur = Hypoxia.GetHypoxiaBlurForPPE(player, alt);
			targetVignette = Hypoxia.GetHypoxiaVignetteForPPE(player, alt);
		}

		float k = timeslice / GameConstants.PLAYZ_SAKHAL_HYPOXIA_PPE_FADE_SEC;
		if (k > 1.0)
			k = 1.0;

		m_PlayZHypoxiaChromSmoothed = Math.Lerp(m_PlayZHypoxiaChromSmoothed, targetChrom, k);
		m_PlayZHypoxiaBlurSmoothed = Math.Lerp(m_PlayZHypoxiaBlurSmoothed, targetBlur, k);
		m_PlayZHypoxiaVignetteSmoothed = Math.Lerp(m_PlayZHypoxiaVignetteSmoothed, targetVignette, k);

		if (m_PlayZHypoxiaChromSmoothed < 0.0001 && m_PlayZHypoxiaBlurSmoothed < 0.0001 && m_PlayZHypoxiaVignetteSmoothed < 0.0001)
		{
			PlayZ_StopHypoxiaPPE();
			return;
		}

		if (!m_PlayZHypoxiaPPE)
			m_PlayZHypoxiaPPE = PPERequester_Hypoxia.Cast(PPERequesterBank.GetRequester(PPERequesterBank.REQ_PLAYZ_HYPOXIA));

		if (!m_PlayZHypoxiaPPE)
		{
			if (!m_PlayZHypoxiaPPEWarned)
			{
				m_PlayZHypoxiaPPEWarned = true;
				Error("PlayZSakhal: PPERequester_Hypoxia not in bank — rebuild and deploy @PlayZSakhal on the client.");
			}
			return;
		}

		if (!m_PlayZHypoxiaPPE.IsRequesterRunning())
			m_PlayZHypoxiaPPE.Start();

		m_PlayZHypoxiaPPE.SetChromAber(m_PlayZHypoxiaChromSmoothed);
		m_PlayZHypoxiaPPE.SetGaussBlur(m_PlayZHypoxiaBlurSmoothed);
		m_PlayZHypoxiaPPE.SetVignette(m_PlayZHypoxiaVignetteSmoothed);
		m_PlayZHypoxiaPPE.SetRequesterUpdating(true);

		int now = GetGame().GetTime();
		if (now >= m_PlayZ_HypoxiaSoundCooldownUntil)
		{
			HumanMovementState move = new HumanMovementState();
			player.GetMovementState(move);
			if (move.m_iMovement == DayZPlayerConstants.MOVEMENTIDX_SPRINT && move.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_ERECT)
			{
				if (targetBlur > 0.0001 || targetChrom > 0.0001 || targetVignette > 0.0001)
				{
					player.RequestSoundEvent(EPlayerSoundEventID.STAMINA_DOWN_HEAVY, false);
					m_PlayZ_HypoxiaSoundCooldownUntil = now + GameConstants.PLAYZ_SAKHAL_HYPOXIA_SOUND_COOLDOWN_MS;
				}
			}
		}
	}

	protected void PlayZ_StopHypoxiaPPE()
	{
		if (m_PlayZHypoxiaPPE && m_PlayZHypoxiaPPE.IsRequesterRunning())
			m_PlayZHypoxiaPPE.Stop();
	}
}
