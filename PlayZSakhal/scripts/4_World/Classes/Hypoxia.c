class Hypoxia
{
	static bool IsSakhalWorld()
	{
		string wn = "";
		GetGame().GetWorldName(wn);
		wn.ToLower();
		if (wn == "sakhal")
			return true;
		return false;
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

	static float ComputeCapPenalty(PlayerBase player)
	{
		if (!player)
			return 0;

		float alt = player.GetPosition()[1];
		if (alt < GameConstants.PLAYZ_SAKHAL_HYPOXIA_ALT_START_M)
			return 0;

		float span = GameConstants.PLAYZ_SAKHAL_HYPOXIA_ALT_FULL_M - GameConstants.PLAYZ_SAKHAL_HYPOXIA_ALT_START_M;
		if (span <= 0)
			return 0;

		float t = (alt - GameConstants.PLAYZ_SAKHAL_HYPOXIA_ALT_START_M) / span;
		if (t < 0)
			t = 0;
		if (t > 1)
			t = 1;

		return t * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CAP_PENALTY_MAX;
	}

	static bool IsHypoxicAltitude(float altitudeM)
	{
		if (altitudeM >= GameConstants.PLAYZ_SAKHAL_HYPOXIA_ALT_START_M)
			return true;
		return false;
	}

	static float GetAltitudeNorm(float altitudeM)
	{
		float span = GameConstants.PLAYZ_SAKHAL_HYPOXIA_ALT_FULL_M - GameConstants.PLAYZ_SAKHAL_HYPOXIA_ALT_START_M;
		if (span <= 0)
			return 0;

		float t = (altitudeM - GameConstants.PLAYZ_SAKHAL_HYPOXIA_ALT_START_M) / span;
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

	static float GetHypoxiaChromForPPE(PlayerBase player, float altitudeM)
	{
		if (!player)
			return 0;

		if (!IsHypoxicAltitude(altitudeM))
			return 0;

		int ppeLevel = GetPpeMitigationLevel(player);
		if (ppeLevel == 2)
			return 0;

		float t = GetAltitudeNorm(altitudeM);
		float chrom = t * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CLIENT_CHROM_MAX;

		if (ppeLevel == 1)
			chrom = chrom * GameConstants.PLAYZ_SAKHAL_HYPOXIA_SOFT_PPE_PARTIAL_MUL;

		if (IsSprintingErect(player))
			chrom = chrom * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CLIENT_SPRINT_PPE_MUL;
		else
			chrom = chrom * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CLIENT_REST_PPE_MUL;

		return chrom;
	}

	static float GetHypoxiaBlurForPPE(PlayerBase player, float altitudeM)
	{
		if (!player)
			return 0;

		if (!IsHypoxicAltitude(altitudeM))
			return 0;

		int ppeLevel = GetPpeMitigationLevel(player);
		if (ppeLevel == 2)
			return 0;

		float t = GetAltitudeNorm(altitudeM);
		float blur = t * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CLIENT_BLUR_MAX;

		if (ppeLevel == 1)
			blur = blur * GameConstants.PLAYZ_SAKHAL_HYPOXIA_SOFT_PPE_PARTIAL_MUL;

		if (IsSprintingErect(player))
			blur = blur * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CLIENT_SPRINT_PPE_MUL;
		else
			blur = blur * GameConstants.PLAYZ_SAKHAL_HYPOXIA_CLIENT_REST_PPE_MUL;

		return blur;
	}
}
