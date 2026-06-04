//! Glow colorization layer for radioactive rain/snow (same mechanism as PlayZ weather events).

class PPERequester_PlayZRadioactiveRain extends PPERequester_GameplayBase
{
	static const int L_LAYER_RAD_RAIN = 921;

	void SetColorization(float r, float g, float b, float a)
	{
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, {r, g, b, a}, L_LAYER_RAD_RAIN, PPOperators.SET);
	}
}
