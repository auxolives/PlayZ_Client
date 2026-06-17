//! Pre-death health PPE — dedicated SET layers (930–933) stack with rad/hypoxia/weather.

class PPERequester_PlayZDying extends PPERequester_GameplayBase
{
	static const int L_LAYER_VIGNETTE = 930;
	static const int L_LAYER_OVERLAY = 931;
	static const int L_LAYER_OVERLAY_COLOR = 931;
	static const int L_LAYER_GAUSS = 932;
	static const int L_LAYER_EXPOSURE = 933;

	void SetVignette(float intensity)
	{
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_VIGNETTE, false, intensity, L_LAYER_VIGNETTE, PPOperators.SET);
	}

	void SetOverlay(float factor)
	{
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_OVERLAYFACTOR, false, factor, L_LAYER_OVERLAY, PPOperators.SET);
		if (factor > 0)
		{
			SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_OVERLAYCOLOR, {0.0, 0.0, 0.0, 1.0}, L_LAYER_OVERLAY_COLOR, PPOperators.SET);
		}
	}

	void SetGaussBlur(float intensity)
	{
		SetTargetValueFloat(PostProcessEffectType.GaussFilter, PPEGaussFilter.PARAM_INTENSITY, false, intensity, L_LAYER_GAUSS, PPOperators.SET);
	}

	void SetExposureDarken(float intensity)
	{
		SetTargetValueFloat(PPEExceptions.EXPOSURE, PPEExposureNative.PARAM_INTENSITY, false, intensity, L_LAYER_EXPOSURE, PPOperators.SET);
	}

	void ClearAll()
	{
		SetVignette(0);
		SetOverlay(0);
		SetGaussBlur(0);
		SetExposureDarken(0);
	}
}
