// T195618 / sGunplay exp d94487e: sVisual sets mode 3 after super — restore 4. sVisual lean unchanged.
modded class DayZPlayerCameraOptics
{
	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult)
	{
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_iDirectBoneMode = 4;
	}
}
