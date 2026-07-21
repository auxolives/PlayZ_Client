// Slightly softer than stock sGunplay FAL — still a heavy .308 battle rifle.
modded class FALRecoil
{
	override void initRecoilParameters()
	{
		handsRanges        = {-2.350,  2.370,  7.850,  8.750};
		handsAccumSpeed    = 0.975;
		handsResetSpeed    = 0.760;

		misalignIntensity  = {1.550,  0.250};
		misalignAccumSpeed = 0.950;
		misalignResetSpeed = 0.900;

		mouseRanges        = {-0.195,  0.195,  1.550,  2.300};
		mouseTime          = 0.200;

		kick               = 0.060;
		kickResetTime      = 3.000;
	}
}
