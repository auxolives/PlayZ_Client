modded class DayZPlayerMeleeFightLogic_LightHeavy
{
	protected ref HumanMovementState m_MovementState;

	override protected bool DummyHitSelector(EMeleeHitType hitType, out string ammoType)
	{
		if (hitType == EMeleeHitType.KICK)
		{
			if (!m_MovementState)
				m_MovementState = new HumanMovementState();
			
			m_Player.GetMovementState(m_MovementState);
			if (m_MovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_PRONE || m_MovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDPRONE)
			{
				ammoType = "MeleeFistHeavy";
				return false;
			}
		}
		
		return super.DummyHitSelector(hitType, ammoType);
	}
}
