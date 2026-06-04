class PlayZMenuStyle
{
	// DayZ color format is ARGB(alpha, red, green, blue), each channel 0-255.

	static int AccentColor()
	{
		// Signature PlayZ accent red (#FF3000), fully opaque.
		return ARGB(255, 255, 48, 0);
	}

	static int AccentColorSoft()
	{
		// Softer accent orange-red used for secondary highlights/icons.
		return ARGB(255, 220, 42, 0);
	}

	static int TextNormal()
	{
		// Default text color: white.
		return ARGB(255, 255, 255, 255);
	}

	static int HoverBlack()
	{
		// Hover state color for text/icons: black.
		return ARGB(255, 0, 0, 0);
	}

	static int IconNormal()
	{
		// Default icon tint: white.
		return ARGB(255, 255, 255, 255);
	}

	static int PanelTransparent()
	{
		// Fully transparent panel/background (alpha = 0).
		return ARGB(0, 0, 0, 0);
	}
}
