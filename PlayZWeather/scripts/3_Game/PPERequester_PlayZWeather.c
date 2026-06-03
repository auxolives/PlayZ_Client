class PPERequester_PlayZWeather extends PPERequester_GameplayBase
{
	// Layer IDs to avoid conflicts with vanilla effects
	static const int L_LAYER_WEATHER = 10;

	void SetSaturation(float value)
	{
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_SATURATION, false, value, L_LAYER_WEATHER, PPOperators.SET);
	}

	void SetContrast(float value)
	{
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_CONTRAST, false, value, L_LAYER_WEATHER, PPOperators.SET);
	}

	void SetColorization(float r, float g, float b, float a)
	{
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, {r, g, b, a}, L_LAYER_WEATHER, PPOperators.SET);
	}

	void SetFilmGrain(float intensity)
	{
		SetTargetValueFloat(PPEExceptions.NVLIGHTPARAMS, PPELightIntensityParamsNative.PARAM_NOISE_MULT, false, intensity, L_LAYER_WEATHER, PPOperators.SET);
	}

	void SetChromAber(float intensity)
	{
		SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERX, false, intensity, L_LAYER_WEATHER, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERY, false, intensity, L_LAYER_WEATHER, PPOperators.SET);
	}

	void SetGodRays(float intensity, float sunVisible)
	{
		SetTargetValueFloat(PostProcessEffectType.GodRays, PPEGodRays.PARAM_INTENSITY, false, intensity, L_LAYER_WEATHER, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.GodRays, PPEGodRays.PARAM_SUNVISIBLE, false, sunVisible, L_LAYER_WEATHER, PPOperators.SET);
	}
}
