//! Rad protection only when oxygen supply is available (filter attached or integrated).

modded class GP5GasMask
{
	static const float PLAYZ_RAD_PROTECT_FILTERED = 0.95;

	override protected float PlayZ_GetRadiationProtectionBase()
	{
		if (!HasValidFilter())
		{
			return 0;
		}

		float level = super.PlayZ_GetRadiationProtectionBase();
		if (level > 0)
		{
			return level;
		}

		return PLAYZ_RAD_PROTECT_FILTERED;
	}
}
