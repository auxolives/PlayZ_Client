class Hypoxia
{
	static bool IsSakhalWorld()
	{
		string wn = "";
		GetGame().GetWorldName(wn);
		wn.ToLower();
		return wn == "sakhal";
	}

	//! PPE chrom/blur: up to two soft slots (headgear + eyewear), capped at 2.
	static int GetPpeMitigationLevel(PlayerBase player)
	{
		if (!player)
			return 0;

		return GetSoftPpeMitigationSlotCount(player);
	}

	//! 0–2: headgear slot + eyewear slot each contribute at most one if they match soft PPE list.
	static int GetSoftPpeMitigationSlotCount(PlayerBase player)
	{
		int n = 0;

		ItemBase head = ItemBase.Cast(player.GetItemOnSlot("Headgear"));
		if (IsSoftHypoxiaPpeHeadgear(head))
			n++;

		ItemBase eye = ItemBase.Cast(player.GetItemOnSlot("Eyewear"));
		if (IsSoftHypoxiaPpeEyewear(eye))
			n++;

		if (n > 2)
			n = 2;

		return n;
	}

	static bool IsSoftHypoxiaPpeHeadgear(EntityAI item)
	{
		if (!item)
			return false;

		if (item.IsInherited(OKZKCap_ColorBase))
			return true;

		if (item.IsInherited(SnowstormUshanka_ColorBase))
			return true;

		if (item.IsInherited(MotoHelmet_ColorBase))
			return true;

		if (item.IsInherited(DirtBikeHelmet_ColorBase))
			return true;

		if (item.IsInherited(Ushanka_ColorBase))
			return true;

		if (item.IsInherited(WinterCoif_ColorBase))
			return true;

		if (item.IsInherited(SherpaHat_ColorBase))
			return true;

		if (item.IsInherited(PetushokHat_ColorBase))
			return true;

		if (item.IsInherited(Headdress_Colorbase))
			return true;

		if (item.IsInherited(Headdress_Fox))
			return true;

		if (item.IsInherited(Shemag_ColorBase))
			return true;

		return false;
	}

	static bool IsSoftHypoxiaPpeEyewear(EntityAI item)
	{
		if (!item)
			return false;

		if (item.IsInherited(NVGHeadstrap))
			return false;

		if (item.IsInherited(Glasses_Base))
			return true;

		return false;
	}

	static float GetAltStartM()
	{
		return PlayZSakhalManager.GetSakhal().m_AltStartM;
	}

	static float GetAltFullM()
	{
		return PlayZSakhalManager.GetSakhal().m_AltFullM;
	}

	static float ComputeCapPenalty(PlayerBase player)
	{
		if (!player)
			return 0;

		if (!PlayZSakhalManager.GetSakhal().m_EnableHypoxiaStamina)
			return 0;

		float alt = player.GetPosition()[1];
		float altStart = GetAltStartM();
		if (alt < altStart)
			return 0;

		float span = GetAltFullM() - altStart;
		if (span <= 0)
			return 0;

		float t = (alt - altStart) / span;
		if (t < 0)
			t = 0;
		if (t > 1)
			t = 1;

		return t * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CAP_PENALTY_MAX;
	}

	static bool IsHypoxicAltitude(float altitudeM)
	{
		if (altitudeM >= GetAltStartM())
			return true;
		return false;
	}

	static float GetAltitudeNorm(float altitudeM)
	{
		float altStart = GetAltStartM();
		float span = GetAltFullM() - altStart;
		if (span <= 0)
			return 0;

		float t = (altitudeM - altStart) / span;
		if (t < 0)
			t = 0;
		if (t > 1)
			t = 1;

		return t;
	}

	static bool IsSprintingErect(PlayerBase player)
	{
		HumanMovementState move = new HumanMovementState();
		player.GetMovementState(move);
		if (move.m_iMovement != DayZPlayerConstants.MOVEMENTIDX_SPRINT)
			return false;

		if (move.m_iStanceIdx != DayZPlayerConstants.STANCEIDX_ERECT)
			return false;

		return true;
	}

	static float ApplySoftPpeMitigation(float value, int ppeLevel)
	{
		if (ppeLevel <= 0)
			return value;

		float mul = GameConstants.PLAYZ_SAKHAL_HYPOXIA_SOFT_PPE_PARTIAL_MUL;
		if (ppeLevel == 1)
			return value * mul;

		return value * mul * mul;
	}

	static float GetHypoxiaChromForPPE(PlayerBase player, float altitudeM)
	{
		if (!player)
			return 0;

		if (player.IsInVehicle())
			return 0;

		if (!IsHypoxicAltitude(altitudeM))
			return 0;

		int ppeLevel = GetPpeMitigationLevel(player);
		float t = GetAltitudeNorm(altitudeM);
		float chrom = t * PlayZSakhalManager.GetSakhal().m_ClientChromMax;
		chrom = ApplySoftPpeMitigation(chrom, ppeLevel);

		if (IsSprintingErect(player))
			chrom = chrom * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CLIENT_SPRINT_PPE_MUL;

		return chrom;
	}

	static float GetHypoxiaBlurForPPE(PlayerBase player, float altitudeM)
	{
		if (!player)
			return 0;

		if (player.IsInVehicle())
			return 0;

		if (!IsHypoxicAltitude(altitudeM))
			return 0;

		int ppeLevel = GetPpeMitigationLevel(player);
		float t = GetAltitudeNorm(altitudeM);
		float blur = t * PlayZSakhalManager.GetSakhal().m_ClientBlurMax;
		blur = ApplySoftPpeMitigation(blur, ppeLevel);

		if (IsSprintingErect(player))
			blur = blur * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CLIENT_SPRINT_PPE_MUL;
		else
			blur = blur * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CLIENT_REST_PPE_MUL;

		return blur;
	}

	static float GetHypoxiaVignetteForPPE(PlayerBase player, float altitudeM)
	{
		if (!player)
			return 0;

		if (!IsHypoxicAltitude(altitudeM))
			return 0;

		int ppeLevel = GetPpeMitigationLevel(player);
		float t = GetAltitudeNorm(altitudeM);
		float vignette = t * PlayZSakhalManager.GetSakhal().m_ClientVignetteMax;
		vignette = ApplySoftPpeMitigation(vignette, ppeLevel);

		if (IsSprintingErect(player))
			vignette = vignette * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CLIENT_SPRINT_PPE_MUL;
		else
			vignette = vignette * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CLIENT_REST_PPE_MUL;

		return vignette;
	}
}
