// 1.29 T195618: ADS cameras on RightHand_Dummy with m_iDirectBoneMode = 3 roll/jitter when
// leaning (sGunplay/sVisual use 3 for head lean; vanilla ironsights use 4). Restore 4 and
// ignore parent roll so Q/E lean does not affect the sight picture on Sakhal.
modded class DayZPlayerCameraIronsights
{
	override bool isHeadLeanEnabled()
	{
		return false;
	}

	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult)
	{
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_iDirectBoneMode = 4;
		pOutResult.m_fIgnoreParentRoll = 1.0;
	}
}
