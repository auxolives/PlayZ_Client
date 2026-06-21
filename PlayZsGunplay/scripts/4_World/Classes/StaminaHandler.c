//! sVisual getStaminaPercentage() divides by m_StaminaCap with no zero guard.
modded class StaminaHandler
{
	override void ReplayMove(PlayerBaseMove move)
	{
		if (move && move.m_bStaminaSynced && move.m_fStaminaSyncedCapacity <= 0)
		{
			float cap = CfgGameplayHandler.GetStaminaMinCap();
			if (cap <= 0)
				cap = CfgGameplayHandler.GetStaminaMax();

			move.m_fStaminaSyncedCapacity = cap;
		}

		super.ReplayMove(move);
	}

	override void CheckStaminaState()
	{
		if (m_StaminaCap <= 0)
		{
			float cap = CfgGameplayHandler.GetStaminaMinCap();
			if (cap <= 0)
				cap = CfgGameplayHandler.GetStaminaMax();

			m_StaminaCap = cap;
			m_StaminaCapSynced = cap;
		}

		super.CheckStaminaState();
	}
}
