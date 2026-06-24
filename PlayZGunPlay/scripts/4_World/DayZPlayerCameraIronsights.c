// T195618 / sGunplay exp: m_iDirectBoneMode 4 (d94487e), yaw m_CurrentCameraYaw (a8fc8ef). sVisual lean kept.
modded class DayZPlayerCameraIronsights
{
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		updateDOF();
		updateAimAngle(m_CurrentCameraYaw, m_CurrentCameraPitch, pDt);
		computeHandsOffset(m_handsOffsetX, m_handsOffsetY, pDt);
		updateCamera(pDt, pOutResult);
		updateCameraShake(pDt);
		AdjustCameraParameters(pDt, pOutResult);
		updateFOVFocus(pDt, pOutResult);
		updateFocusingOverlay(pDt, pOutResult);
		UpdateBatteryOptics(GetCurrentSightEntity());
		UpdateCameraNV(m_player);
		updateDDOF(pDt, pOutResult);
		updateCamAngles(pDt, pOutResult);
	}

	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult)
	{
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_iDirectBoneMode = 4;
	}
}
