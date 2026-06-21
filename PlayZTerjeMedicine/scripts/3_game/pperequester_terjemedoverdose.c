modded class PPERequester_TerjeMedOverdose
{
	static const int L_PLAYZ_ROT_POWER = 934;
	static const int L_PLAYZ_ROT_MINANGLE = 935;
	static const int L_PLAYZ_ROT_MAXANGLE = 936;
	static const int L_PLAYZ_ROT_MINDEPTH = 937;
	static const int L_PLAYZ_ROT_MAXDEPTH = 938;
	static const int L_PLAYZ_DISTORT = 939;
	static const int L_PLAYZ_DISTORT_CENTERX = 940;
	static const int L_PLAYZ_DISTORT_CENTERY = 941;

	protected float m_PlayZRawValue;
	protected float m_PlayZMod;

	void SetPlayZOverdoseValue(float rawValue, float mod)
	{
		m_PlayZRawValue = rawValue;
		m_PlayZMod = mod;
	}

	override void OnUpdate(float delta)
	{
		super.OnUpdate(delta);

		PlayZOverdoseConfig cfg = PlayZOverdoseConfig.GetInstance();
		if (!cfg.m_EnableOverdosePPE)
		{
			PlayZ_ClearExtras();
			return;
		}

		float weight = PlayZOverdosePPE.GetTierWeight(m_PlayZRawValue);
		if (!PlayZOverdosePPE.HasAnyEffect(weight) || m_PlayZMod <= PlayZOverdosePPE.EPSILON)
		{
			PlayZ_ClearExtras();
			return;
		}

		float pulse = PlayZOverdosePPE.PulseFromOffset(m_OverdosedOffset);

		float power;
		float minAngle;
		float maxAngle;
		float minDepth;
		float maxDepth;
		PlayZOverdosePPE.ComputeRotBlur(weight, pulse, m_PlayZMod, power, minAngle, maxAngle, minDepth, maxDepth);

		float distort;
		float centerX;
		float centerY;
		PlayZOverdosePPE.ComputeDistort(weight, pulse, m_PlayZMod, distort, centerX, centerY);

		SetTargetValueFloat(PostProcessEffectType.RotBlur, PPERotBlur.PARAM_POWER, false, power, L_PLAYZ_ROT_POWER, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RotBlur, PPERotBlur.PARAM_MINANGLEPERSEC, false, minAngle, L_PLAYZ_ROT_MINANGLE, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RotBlur, PPERotBlur.PARAM_MAXANGLEPERSEC, false, maxAngle, L_PLAYZ_ROT_MAXANGLE, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RotBlur, PPERotBlur.PARAM_MINDEPTH, false, minDepth, L_PLAYZ_ROT_MINDEPTH, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RotBlur, PPERotBlur.PARAM_MAXDEPTH, false, maxDepth, L_PLAYZ_ROT_MAXDEPTH, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.Distort, PPEDistort.PARAM_DISTORT, false, distort, L_PLAYZ_DISTORT, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.Distort, PPEDistort.PARAM_CENTERX, false, centerX, L_PLAYZ_DISTORT_CENTERX, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.Distort, PPEDistort.PARAM_CENTERY, false, centerY, L_PLAYZ_DISTORT_CENTERY, PPOperators.SET);
	}

	override protected void OnStop(Param par = null)
	{
		super.OnStop(par);
		PlayZ_ClearExtras();
		m_PlayZRawValue = 0;
		m_PlayZMod = 0;
	}

	protected void PlayZ_ClearExtras()
	{
		SetTargetValueFloat(PostProcessEffectType.RotBlur, PPERotBlur.PARAM_POWER, false, 0, L_PLAYZ_ROT_POWER, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RotBlur, PPERotBlur.PARAM_MINANGLEPERSEC, false, 0, L_PLAYZ_ROT_MINANGLE, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RotBlur, PPERotBlur.PARAM_MAXANGLEPERSEC, false, 0, L_PLAYZ_ROT_MAXANGLE, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RotBlur, PPERotBlur.PARAM_MINDEPTH, false, 0, L_PLAYZ_ROT_MINDEPTH, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RotBlur, PPERotBlur.PARAM_MAXDEPTH, false, 0, L_PLAYZ_ROT_MAXDEPTH, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.Distort, PPEDistort.PARAM_DISTORT, false, 0, L_PLAYZ_DISTORT, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.Distort, PPEDistort.PARAM_CENTERX, false, 0, L_PLAYZ_DISTORT_CENTERX, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.Distort, PPEDistort.PARAM_CENTERY, false, 0, L_PLAYZ_DISTORT_CENTERY, PPOperators.SET);
	}
}
