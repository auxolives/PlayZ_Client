//! Desaturation layer for radioactive rain/snow (same mechanism as PlayZ weather events).

class PPERequester_PlayZRadioactiveRain extends PPERequester_GameplayBase
{
	static const int L_LAYER_RAD_RAIN = 921;

	void SetSaturation(float value)
	{
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_SATURATION, false, value, L_LAYER_RAD_RAIN, PPOperators.SET);
	}
}
