//! Environmental radiation: full desaturation + film grain (zone + rain/snow).

class PPERequester_PlayZRadEnvironment extends PPERequester_GameplayBase
{
	static const int L_LAYER_SAT = 921;
	static const int L_LAYER_GRAIN_SHARP = 924;
	static const int L_LAYER_GRAIN_SIZE = 928;
	static const int L_LAYER_NOISE = 924;

	void SetSaturation(float value)
	{
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_SATURATION, false, value, L_LAYER_SAT, PPOperators.SET);
	}

	void SetFilmGrain(float sharpness, float grainSize)
	{
		SetTargetValueFloat(PostProcessEffectType.FilmGrain, PPEFilmGrain.PARAM_SHARPNESS, false, sharpness, L_LAYER_GRAIN_SHARP, PPOperators.HIGHEST);
		SetTargetValueFloat(PostProcessEffectType.FilmGrain, PPEFilmGrain.PARAM_GRAINSIZE, false, grainSize, L_LAYER_GRAIN_SIZE, PPOperators.LOWEST);
	}

	void SetNoiseMult(float value)
	{
		SetTargetValueFloat(PPEExceptions.NVLIGHTPARAMS, PPELightIntensityParamsNative.PARAM_NOISE_MULT, false, value, L_LAYER_NOISE, PPOperators.SET);
	}
}
