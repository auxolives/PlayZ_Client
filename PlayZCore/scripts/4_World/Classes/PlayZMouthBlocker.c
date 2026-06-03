class PlayZMouthBlocker
{
	static const string DIRTBIKE_MOUTHGUARD_SLOT = "DBHelmetMouth";

	protected static bool s_BypassMouthCheck = false;

	static void SetBypassMouthCheck(bool val)
	{
		s_BypassMouthCheck = val;
	}

	static bool IsBypassMouthCheck()
	{
		return s_BypassMouthCheck;
	}

	static bool IsHeadBlocker(EntityAI item)
	{
		if (!item)
		{
			return false;
		}

		if (item.IsInherited(BurlapSackCover)) { return true; }
		if (item.IsInherited(OKZKCap_ColorBase)) { return true; }
		if (item.IsInherited(GreatHelm)) { return true; }
		if (item.IsInherited(MotoHelmet_ColorBase)) { return true; }
		if (item.IsInherited(WeldingMask)) { return true; }
		if (item.IsInherited(SnowstormUshanka_ColorBase)) { return true; }

		if (item.IsInherited(DirtBikeHelmet_ColorBase))
		{
			if (item.FindAttachmentBySlotName(DIRTBIKE_MOUTHGUARD_SLOT))
			{
				return true;
			}
		}

		return false;
	}

	static bool IsMaskBlocker(EntityAI item)
	{
		if (!item)
		{
			return false;
		}

		if (item.IsInherited(Bandana_ColorBase)) { return true; }
		if (item.IsInherited(Shemag_ColorBase)) { return true; }
		if (item.IsKindOf("BandanaMask_ColorBase")) { return true; }
		if (item.IsInherited(BalaclavaMask_ColorBase)) { return true; }
		if (item.IsInherited(GP5GasMask)) { return true; }
		if (item.IsInherited(AirborneMask)) { return true; }
		if (item.IsInherited(GasMask)) { return true; }
		if (item.IsInherited(NioshFaceMask)) { return true; }
		if (item.IsInherited(FaceCover_Improvised)) { return true; }
		if (item.IsInherited(MimeMask_Male)) { return true; }
		if (item.IsInherited(SurgicalMask)) { return true; }
		if (item.IsInherited(PaydayMask_ColorBase)) { return true; }

		return false;
	}

	static bool IsMouthCovered(Man player)
	{
		if (!player)
		{
			return false;
		}

		EntityAI head = player.FindAttachmentBySlotName("Headgear");
		if (IsHeadBlocker(head))
		{
			return true;
		}

		EntityAI mask = player.FindAttachmentBySlotName("Mask");
		if (IsMaskBlocker(mask))
		{
			return true;
		}

		return false;
	}
}
