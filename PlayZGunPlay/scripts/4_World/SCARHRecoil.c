// sGunplay never patched SCARHRecoil — without this it used soft RecoilBase defaults.
// Peers FAL .308 profile; a touch cleaner (shorter platform).
modded class SCARHRecoil
{
	override void initRecoilParameters()
	{
		handsRanges        = {-2.200,  2.220,  7.550,  8.450};
		handsAccumSpeed    = 0.970;
		handsResetSpeed    = 0.780;

		misalignIntensity  = {1.450,  0.250};
		misalignAccumSpeed = 0.945;
		misalignResetSpeed = 0.910;

		mouseRanges        = {-0.180,  0.180,  1.450,  2.150};
		mouseTime          = 0.200;

		kick               = 0.055;
		kickResetTime      = 2.850;
	}
}
