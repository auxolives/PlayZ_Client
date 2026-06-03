// Custom head lean for ADS — cancels all vanilla/mod lean sources and implements our own.
// Root cause of pushback: bone constraint (mode 3) applies bone lean as parent,
// but sGunplay's weapon aiming matrix in camera TM has no lean — they fight.
// Fix: kill bone roll, kill sVisual lean, apply our own smoothed roll directly.
modded class DayZPlayerCameraIronsights
{
	protected float m_plzLeanRoll;
	protected float m_plzLeanVel[1];

	override bool isHeadLeanEnabled()
	{
		return false;
	}

	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult)
	{
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_fIgnoreParentRoll = 1.0;
	}

	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		super.OnUpdate(pDt, pOutResult);

		// Apply our own smoothed lean roll as the last step before engine processes
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
