//! Sakhal hypoxia: chrom + Gauss blur (1s fade) on dedicated requester; sprint breath audio.

modded class MissionGameplay
{
	protected float m_PlayZ_HypoxiaSoundCooldownUntil;
	protected ref PPERequester_Hypoxia m_PlayZHypoxiaPPE;
	protected float m_PlayZHypoxiaChromSmoothed;
	protected float m_PlayZHypoxiaBlurSmoothed;

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		if (GetGame().IsDedicatedServer())
			return;

		if (!PlayZSakhalHypoxia.IsSakhalWorld())
		{
			m_PlayZHypoxiaChromSmoothed = 0;
			m_PlayZHypoxiaBlurSmoothed = 0;
			PlayZ_StopHypoxiaPPE();
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player || !player.IsControlledPlayer())
			return;

		float alt = player.GetPosition()[1];
		float targetChrom = 0;
		float targetBlur = 0;
		if (PlayZSakhalHypoxia.IsHypoxicAltitude(alt))
		{
			targetChrom = PlayZSakhalHypoxia.GetHypoxiaChromForPPE(player, alt);
			targetBlur = PlayZSakhalHypoxia.GetHypoxiaBlurForPPE(player, alt);
		}

		float k = timeslice / GameConstants.PLAYZ_SAKHAL_HYPOXIA_PPE_FADE_SEC;
		if (k > 1.0)
			k = 1.0;

		m_PlayZHypoxiaChromSmoothed = Math.Lerp(m_PlayZHypoxiaChromSmoothed, targetChrom, k);
		m_PlayZHypoxiaBlurSmoothed = Math.Lerp(m_PlayZHypoxiaBlurSmoothed, targetBlur, k);

		if (m_PlayZHypoxiaChromSmoothed < 0.0001 && m_PlayZHypoxiaBlurSmoothed < 0.0001)
		{
			PlayZ_StopHypoxiaPPE();
			return;
		}

		if (!m_PlayZHypoxiaPPE)
			m_PlayZHypoxiaPPE = PPERequester_Hypoxia.Cast(PPERequesterBank.GetRequester(PPERequester_Hypoxia));

		if (!m_PlayZHypoxiaPPE)
			return;

		if (!m_PlayZHypoxiaPPE.IsRequesterRunning())
			m_PlayZHypoxiaPPE.Start();

		m_PlayZHypoxiaPPE.SetChromAber(m_PlayZHypoxiaChromSmoothed);
		m_PlayZHypoxiaPPE.SetGaussBlur(m_PlayZHypoxiaBlurSmoothed);

		int now = GetGame().GetTime();
		if (now >= m_PlayZ_HypoxiaSoundCooldownUntil)
		{
			HumanMovementState move = new HumanMovementState();
			player.GetMovementState(move);
			if (move.m_iMovement == DayZPlayerConstants.MOVEMENTIDX_SPRINT && move.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_ERECT)
			{
				if (targetBlur > 0.0001 || targetChrom > 0.0001)
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
