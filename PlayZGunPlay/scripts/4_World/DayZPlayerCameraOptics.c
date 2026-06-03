// Same custom lean fix for optics/scopes
modded class DayZPlayerCameraOptics
{
	protected float m_plzLeanRoll;
	protected float m_plzLeanVel[1];

	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult)
	{
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_fIgnoreParentRoll = 1.0;
	}

	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		super.OnUpdate(pDt, pOutResult);

		DayZPlayerImplement impl = DayZPlayerImplement.Cast(m_pPlayer);
		if (!impl) return;

		float leanValue = 0;
		if (!m_pPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDPRONE | DayZPlayerConstants.STANCEMASK_PRONE))
			leanValue = impl.m_MovementState.m_fLeaning;

		float headLeanAngle = 0;
		SUserConfigVisual cfg = SUserConfig.visual();
		if (cfg)
			headLeanAngle = cfg.getHeadLeanAngle();

		float targetRoll = leanValue * headLeanAngle;
		m_plzLeanRoll = Math.SmoothCD(m_plzLeanRoll, targetRoll, m_plzLeanVel, 0.25, 1000, pDt);

		vector camAngles = Math3D.MatrixToAngles(pOutResult.m_CameraTM);
		camAngles[2] = camAngles[2] + m_plzLeanRoll;
		Math3D.YawPitchRollMatrix(camAngles, pOutResult.m_CameraTM);
	}
}
