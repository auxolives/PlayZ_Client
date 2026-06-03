modded class StaminaHandler
{
	protected int m_PlayZ_HypoxiaAltBand = -2147483648;

	override void RecalculateStaminaCap()
	{
		super.RecalculateStaminaCap();

		if (!GetGame().IsServer())
			return;

		PlayerBase pb = PlayerBase.Cast(m_Player);
		if (!pb)
			return;

		if (!Hypoxia.IsSakhalWorld())
			return;

		float pen = Hypoxia.ComputeCapPenalty(pb);
		if (pen <= 0)
			return;

		m_StaminaCap = Math.Max(CfgGameplayHandler.GetStaminaMinCap(), m_StaminaCap - pen);
		m_StaminaCapSynced = m_StaminaCap;

		if (m_Stamina > m_StaminaCap)
			m_Stamina = m_StaminaCap;
	}

	override void Update(float deltaT, int pCurrentCommandID)
	{
		super.Update(deltaT, pCurrentCommandID);

		if (!GetGame().IsServer())
			return;

		PlayerBase pb = PlayerBase.Cast(m_Player);
		if (!pb)
			return;

		if (!Hypoxia.IsSakhalWorld())
			return;

		float alt = pb.GetPosition()[1];
		int altBand = (int)(alt * 0.2);

		if (altBand == m_PlayZ_HypoxiaAltBand)
			return;

		m_PlayZ_HypoxiaAltBand = altBand;

		RecalculateStaminaCap();

		if (m_Stamina > m_StaminaCap)
			m_Stamina = m_StaminaCap;

		m_StaminaSynced = m_Stamina;
		m_StaminaCapSynced = m_StaminaCap;

		pb.GetStatStamina().Set(m_Stamina);
		SyncStaminaEx();
	}
}
