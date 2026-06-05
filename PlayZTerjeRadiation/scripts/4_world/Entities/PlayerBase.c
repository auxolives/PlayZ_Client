modded class PlayerBase
{
	protected bool m_PlayZDosimeterTooltipDirty;

	void PlayZSetDosimeterTooltipDirty(bool dirty)
	{
		m_PlayZDosimeterTooltipDirty = dirty;
	}

	bool PlayZConsumeDosimeterTooltipDirty()
	{
		if (!m_PlayZDosimeterTooltipDirty)
		{
			return false;
		}

		m_PlayZDosimeterTooltipDirty = false;
		return true;
	}

	bool PlayZHasActiveDosimeterInHands()
	{
		EntityAI inHands = GetHumanInventory().GetEntityInHands();
		TerjeDosimetrBase dosimeter = TerjeDosimetrBase.Cast(inHands);
		if (!dosimeter || !dosimeter.HasEnergyManager())
		{
			return false;
		}

		return dosimeter.GetCompEM().IsWorking();
	}
}
