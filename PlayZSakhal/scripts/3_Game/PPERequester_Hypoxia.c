//! Dedicated post-process layer for altitude hypoxia (independent of PlayZ weather PPE).

class PPERequester_Hypoxia extends PPERequester_GameplayBase
{
	static const int L_LAYER_CHROM = 11;
	static const int L_LAYER_GAUSS_HYPOXIA = 920;

	void SetChromAber(float intensity)
	{
		SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERX, false, intensity, L_LAYER_CHROM, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERY, false, intensity, L_LAYER_CHROM, PPOperators.SET);
	}

	void SetGaussBlur(float intensity)
	{
		SetTargetValueFloat(PostProcessEffectType.GaussFilter, PPEGaussFilter.PARAM_INTENSITY, false, intensity, L_LAYER_GAUSS_HYPOXIA, PPOperators.SET);
	}
}
