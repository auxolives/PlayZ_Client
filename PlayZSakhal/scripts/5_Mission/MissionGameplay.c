//! Sakhal hypoxia: chrom + vignette + Gauss blur (1s fade) on dedicated requester; sprint breath audio.

modded class MissionGameplay
{
	protected float m_PlayZ_HypoxiaSoundCooldownUntil;
	protected ref PPERequester_Hypoxia m_PlayZHypoxiaPPE;
	protected float m_PlayZHypoxiaChromSmoothed;
	protected float m_PlayZHypoxiaBlurSmoothed;
	protected float m_PlayZHypoxiaVignetteSmoothed;
	protected float m_PlayZHypoxiaTargetChrom;
	protected float m_PlayZHypoxiaTargetBlur;
	protected float m_PlayZHypoxiaTargetVignette;
	protected bool m_PlayZHypoxiaPPEWarned;
	protected ref PlayZPPEUpdateGate m_PlayZHypoxiaPPESampleGate;

	protected bool PlayZ_ShouldSampleHypoxiaPPE(float timeslice)
	{
		if (!m_PlayZHypoxiaPPESampleGate)
		{
			m_PlayZHypoxiaPPESampleGate = new PlayZPPEUpdateGate();
		}

		return m_PlayZHypoxiaPPESampleGate.ConsumeSampleTick(timeslice);
	}

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
			m_PlayZHypoxiaTargetChrom = 0;
			m_PlayZHypoxiaTargetBlur = 0;
			m_PlayZHypoxiaTargetVignette = 0;
			PlayZ_StopHypoxiaPPE();
			return;
		}

		if (!PlayZSakhalManager.GetSakhal().m_EnableHypoxiaPPE)
		{
			m_PlayZHypoxiaChromSmoothed = 0;
			m_PlayZHypoxiaBlurSmoothed = 0;
			m_PlayZHypoxiaVignetteSmoothed = 0;
			m_PlayZHypoxiaTargetChrom = 0;
			m_PlayZHypoxiaTargetBlur = 0;
			m_PlayZHypoxiaTargetVignette = 0;
			PlayZ_StopHypoxiaPPE();
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player)
			return;

		if (PlayZ_ShouldSampleHypoxiaPPE(timeslice))
		{
			float alt = player.GetPosition()[1];
			m_PlayZHypoxiaTargetChrom = 0;
			m_PlayZHypoxiaTargetBlur = 0;
			m_PlayZHypoxiaTargetVignette = 0;
			if (Hypoxia.IsHypoxicAltitude(alt))
			{
				m_PlayZHypoxiaTargetChrom = Hypoxia.GetHypoxiaChromForPPE(player, alt);
				m_PlayZHypoxiaTargetBlur = Hypoxia.GetHypoxiaBlurForPPE(player, alt);
				m_PlayZHypoxiaTargetVignette = Hypoxia.GetHypoxiaVignetteForPPE(player, alt);
			}
		}

		float k = timeslice / GameConstants.PLAYZ_SAKHAL_HYPOXIA_PPE_FADE_SEC;
		if (k > 1.0)
			k = 1.0;

		m_PlayZHypoxiaChromSmoothed = Math.Lerp(m_PlayZHypoxiaChromSmoothed, m_PlayZHypoxiaTargetChrom, k);
		m_PlayZHypoxiaBlurSmoothed = Math.Lerp(m_PlayZHypoxiaBlurSmoothed, m_PlayZHypoxiaTargetBlur, k);
		m_PlayZHypoxiaVignetteSmoothed = Math.Lerp(m_PlayZHypoxiaVignetteSmoothed, m_PlayZHypoxiaTargetVignette, k);

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
				if (m_PlayZHypoxiaTargetBlur > 0.0001 || m_PlayZHypoxiaTargetChrom > 0.0001 || m_PlayZHypoxiaTargetVignette > 0.0001)
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
