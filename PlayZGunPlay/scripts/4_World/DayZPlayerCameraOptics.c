// Same 1.29 ADS lean/jitter workaround as ironsights (T195618).
modded class DayZPlayerCameraOptics
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
