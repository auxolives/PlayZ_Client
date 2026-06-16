//! Body radiation buffer: vignette, fever gauss blur, radial blur.

class PPERequester_PlayZRadBody extends PPERequester_GameplayBase
{
	static const int L_LAYER_VIGNETTE = 925;
	static const int L_LAYER_VIGNETTE_COLOR = 925;
	static const int L_LAYER_GAUSS = 926;
	static const int L_LAYER_RADIAL = 927;

	void SetVignette(float intensity)
	{
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_VIGNETTE, false, intensity, L_LAYER_VIGNETTE, PPOperators.SET);
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_VIGNETTECOLOR, {0.06, 0.09, 0.02, 0.0}, L_LAYER_VIGNETTE_COLOR, PPOperators.SET);
	}

	void SetGaussBlur(float intensity)
	{
		SetTargetValueFloat(PostProcessEffectType.GaussFilter, PPEGaussFilter.PARAM_INTENSITY, false, intensity, L_LAYER_GAUSS, PPOperators.SET);
	}

	void SetRadialBlur(float power)
	{
		SetTargetValueFloat(PostProcessEffectType.RadialBlur, PPERadialBlur.PARAM_POWERX, false, power, L_LAYER_RADIAL, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RadialBlur, PPERadialBlur.PARAM_POWERY, false, power, L_LAYER_RADIAL, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RadialBlur, PPERadialBlur.PARAM_OFFSETX, false, 0.1, L_LAYER_RADIAL, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RadialBlur, PPERadialBlur.PARAM_OFFSETY, false, 0.1, L_LAYER_RADIAL, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RadialBlur, PPERadialBlur.PARAM_PIXELSCALE, false, 0.5, L_LAYER_RADIAL, PPOperators.SET);
	}
}
