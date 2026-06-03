modded class BoltActionBipodRecoil
{
	override void initRecoilParameters()
	{
		handsRanges        = {-1.000,  1.000,  1.000,  1.000};
		handsAccumSpeed    = 0.955;
		handsResetSpeed    = 0.750;

		misalignIntensity  = { 0.500,  0.250};
		misalignAccumSpeed = 0.975;
		misalignResetSpeed = 0.650;

		mouseRanges        = { 0.000,  0.000,  0.000,  0.000};
		mouseTime          = 0.050;

		kick               = 0.050;
		kickResetTime      = 1.250;
	}
}
