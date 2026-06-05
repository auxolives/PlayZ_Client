//! Rad protection only when oxygen supply is available (filter attached or integrated).

modded class AirborneMask
{
	static const float PLAYZ_RAD_PROTECT_FILTERED = 0.95;

	override float GetTerjeProtectionLevel(string protectionType)
	{
		if (protectionType != "radiation")
		{
			return super.GetTerjeProtectionLevel(protectionType);
		}

		if (!HasValidFilter())
		{
			return 0;
		}

		float level = super.GetTerjeProtectionLevel(protectionType);
		if (level > 0)
		{
			return level;
		}

		return PLAYZ_RAD_PROTECT_FILTERED;
	}
}
