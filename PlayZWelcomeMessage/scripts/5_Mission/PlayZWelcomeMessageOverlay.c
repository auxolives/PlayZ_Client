class PlayZWelcomeMessageLineWidget
{
	Widget Root;
	TextWidget Text;
	float AlphaMultiplier;
	int LineIndex;
	int ShadowSize;
	float ShadowOffsetX;
	float ShadowOffsetY;

	void PlayZWelcomeMessageLineWidget(Widget root, TextWidget text, float alphaMultiplier, int lineIndex, int shadowSize, float shadowOffsetX, float shadowOffsetY)
	{
		Root = root;
		Text = text;
		AlphaMultiplier = alphaMultiplier;
		LineIndex = lineIndex;
		ShadowSize = shadowSize;
		ShadowOffsetX = shadowOffsetX;
		ShadowOffsetY = shadowOffsetY;
	}
}

class PlayZWelcomeMessageOverlay
{
	protected static const int TITLE_TEXT_SIZE = 48;
	protected static const int BODY_TEXT_SIZE = 30;
	protected static const int MAX_INFORMATION_LINES = 16;
	protected static const float SHADOW_OPACITY_SCALE = 0.6;

	protected ref PlayZWelcomeMessageConfig m_Config;
	protected ref array<ref PlayZWelcomeMessageLineWidget> m_LineWidgets;

	protected Widget m_Root;
	protected float m_ElapsedMs;
	protected float m_AnimationElapsedMs;
	protected float m_StartDelayMs;
	protected float m_TotalMs;
	protected float m_ScreenScale;
	protected bool m_Finished;

	void PlayZWelcomeMessageOverlay(PlayZWelcomeMessageConfig config)
	{
		m_Config = config;
		m_LineWidgets = new array<ref PlayZWelcomeMessageLineWidget>();
		m_StartDelayMs = m_Config.StartDelaySeconds * 1000.0;
		m_ScreenScale = GetScreenScale();
		CreateWidgets();
		CalculateTotalDuration();
	}

	void ~PlayZWelcomeMessageOverlay()
	{
		if (m_Root)
		{
			m_Root.Unlink();
		}
	}

	bool IsFinished()
	{
		return m_Finished;
	}

	void Update(float timeslice)
	{
		if (m_Finished)
		{
			return;
		}

		m_ElapsedMs += timeslice * 1000.0;
		m_AnimationElapsedMs = m_ElapsedMs - m_StartDelayMs;
		UpdateAlpha();

		if (m_ElapsedMs >= m_TotalMs)
		{
			m_Finished = true;
		}
	}

	protected void CreateWidgets()
	{
		m_Root = GetGame().GetWorkspace().CreateWidgets(PlayZWelcomeMessagePaths.LAYOUT_ROOT);

		int firstLineColor = ParseConfiguredColor(m_Config.FirstLineTextColor, ARGB(255, 255, 255, 255));
		int informationTextColor = ParseConfiguredColor(m_Config.InformationTextColor, ARGB(255, 255, 255, 255));

		float startX = m_Config.StartX * m_ScreenScale;
		float lineY = m_Config.StartY * m_ScreenScale;
		int shadowSize = Math.Max(1, Math.Round(2.0 * m_ScreenScale));
		float shadowOffsetX = Math.Max(1.0, 1.0 * m_ScreenScale);
		float shadowOffsetY = Math.Max(1.0, 2.0 * m_ScreenScale);

		CreateLineWidget(PlayZWelcomeMessagePaths.LAYOUT_LINE_TITLE, ResolveTextKey(m_Config.FirstLineTextKey), startX, lineY, TITLE_TEXT_SIZE, firstLineColor, shadowSize, shadowOffsetX, shadowOffsetY, 0);

		lineY += (TITLE_TEXT_SIZE + 14) * m_ScreenScale;

		for (int i = 0; i < m_Config.InformationTextLineKeys.Count() && i < MAX_INFORMATION_LINES; i++)
		{
			string lineKey = m_Config.InformationTextLineKeys.Get(i);
			if (lineKey != "")
			{
				CreateLineWidget(PlayZWelcomeMessagePaths.LAYOUT_LINE_BODY, ResolveTextKey(lineKey), startX, lineY, BODY_TEXT_SIZE, informationTextColor, shadowSize, shadowOffsetX, shadowOffsetY, i + 1);
			}

			if (lineKey == "")
			{
				lineY += (BODY_TEXT_SIZE + 8) * m_ScreenScale;
			}
			else
			{
				lineY += (BODY_TEXT_SIZE + 4) * m_ScreenScale;
			}
		}
	}

	protected void CreateLineWidget(string layoutPath, string text, float startX, float startY, int baseTextSize, int color, int shadowSize, float shadowOffsetX, float shadowOffsetY, int lineIndex)
	{
		Widget lineRoot = GetGame().GetWorkspace().CreateWidgets(layoutPath, m_Root);
		TextWidget lineText = TextWidget.Cast(lineRoot.FindAnyWidget("WelcomeLineText"));
		if (!lineRoot || !lineText)
		{
			return;
		}

		int textSize = Math.Max(1, Math.Round(baseTextSize * m_ScreenScale));
		lineRoot.SetPos(startX, startY);
		lineText.SetText(text);
		lineText.SetTextExactSize(textSize);
		lineText.SetColor(color);
		lineText.SetShadow(shadowSize, ARGB(255, 0, 0, 0), 0.0, shadowOffsetX, shadowOffsetY);
		lineRoot.SetAlpha(0);
		lineText.SetAlpha(0);
		lineRoot.Show(true);

		m_LineWidgets.Insert(new PlayZWelcomeMessageLineWidget(lineRoot, lineText, 1.0, lineIndex, shadowSize, shadowOffsetX, shadowOffsetY));
	}

	protected string ResolveTextKey(string key)
	{
		if (key == "")
		{
			return "";
		}

		if (key.Substring(0, 1) == "#")
		{
			return key;
		}

		return "#" + key;
	}

	protected int ParseConfiguredColor(string colorValue, int fallbackColor)
	{
		if (colorValue == "")
		{
			return fallbackColor;
		}

		string normalized = colorValue;
		if (normalized.Length() > 0 && normalized.Substring(0, 1) == "#")
		{
			normalized = normalized.Substring(1, normalized.Length() - 1);
		}

		if (normalized.Length() == 6)
		{
			int r;
			int g;
			int b;
			if (!TryParseHexByte(normalized.Substring(0, 2), r)) return fallbackColor;
			if (!TryParseHexByte(normalized.Substring(2, 2), g)) return fallbackColor;
			if (!TryParseHexByte(normalized.Substring(4, 2), b)) return fallbackColor;
			return ARGB(255, r, g, b);
		}

		if (normalized.Length() == 8)
		{
			int a;
			int r2;
			int g2;
			int b2;
			if (!TryParseHexByte(normalized.Substring(0, 2), a)) return fallbackColor;
			if (!TryParseHexByte(normalized.Substring(2, 2), r2)) return fallbackColor;
			if (!TryParseHexByte(normalized.Substring(4, 2), g2)) return fallbackColor;
			if (!TryParseHexByte(normalized.Substring(6, 2), b2)) return fallbackColor;
			return ARGB(a, r2, g2, b2);
		}

		return fallbackColor;
	}

	protected bool TryParseHexByte(string hexPair, out int value)
	{
		value = 0;
		if (hexPair.Length() != 2)
		{
			return false;
		}

		int high = HexDigitToInt(hexPair.Substring(0, 1));
		int low = HexDigitToInt(hexPair.Substring(1, 1));
		if (high < 0 || low < 0)
		{
			return false;
		}

		value = (high * 16) + low;
		return true;
	}

	protected int HexDigitToInt(string digit)
	{
		if (digit == "0") return 0;
		if (digit == "1") return 1;
		if (digit == "2") return 2;
		if (digit == "3") return 3;
		if (digit == "4") return 4;
		if (digit == "5") return 5;
		if (digit == "6") return 6;
		if (digit == "7") return 7;
		if (digit == "8") return 8;
		if (digit == "9") return 9;
		if (digit == "A" || digit == "a") return 10;
		if (digit == "B" || digit == "b") return 11;
		if (digit == "C" || digit == "c") return 12;
		if (digit == "D" || digit == "d") return 13;
		if (digit == "E" || digit == "e") return 14;
		if (digit == "F" || digit == "f") return 15;
		return -1;
	}

	protected float GetScreenScale()
	{
		if (!m_Config.ScaleToScreen)
		{
			return 1.0;
		}

		float screenWidth;
		float screenHeight;
		GetGame().GetWorkspace().GetScreenSize(screenWidth, screenHeight);

		float widthScale = screenWidth / m_Config.ReferenceScreenWidth;
		float heightScale = screenHeight / m_Config.ReferenceScreenHeight;
		return Math.Min(widthScale, heightScale);
	}

	protected void CalculateTotalDuration()
	{
		int infoLineCount = m_Config.InformationTextLineKeys.Count();
		if (infoLineCount > MAX_INFORMATION_LINES)
		{
			infoLineCount = MAX_INFORMATION_LINES;
		}

		m_TotalMs = m_StartDelayMs;
		m_TotalMs += m_Config.FirstLineFadeInMs;
		m_TotalMs += m_Config.PauseBetweenFirstLineAndInformationTextMs;
		m_TotalMs += infoLineCount * m_Config.InformationLineFadeInDelayMs;
		m_TotalMs += m_Config.FullyVisiblePauseSeconds * 1000;
		m_TotalMs += m_Config.FadeOutMs;
	}

	protected void UpdateAlpha()
	{
		float fadeOutStart = m_TotalMs - m_Config.FadeOutMs;
		float globalAlpha = 1.0;

		if (m_ElapsedMs >= fadeOutStart)
		{
			float fadeOutT = Math.Clamp((m_ElapsedMs - fadeOutStart) / m_Config.FadeOutMs, 0.0, 1.0);
			globalAlpha = 1.0 - SmoothStep(fadeOutT);
		}

		for (int i = 0; i < m_LineWidgets.Count(); i++)
		{
			PlayZWelcomeMessageLineWidget line = m_LineWidgets.Get(i);
			float lineAlpha = SmoothStep(GetLineAlpha(line.LineIndex));
			float alpha = lineAlpha * globalAlpha * line.AlphaMultiplier;
			line.Root.SetAlpha(alpha);
			if (line.Text)
			{
				line.Text.SetAlpha(alpha);
				float shadowAlpha = alpha * SHADOW_OPACITY_SCALE;
				line.Text.SetShadow(line.ShadowSize, ARGB(255, 0, 0, 0), shadowAlpha, line.ShadowOffsetX, line.ShadowOffsetY);
			}
		}
	}

	protected float SmoothStep(float t)
	{
		t = Math.Clamp(t, 0.0, 1.0);
		return t * t * (3.0 - 2.0 * t);
	}

	protected float GetLineAlpha(int index)
	{
		if (index == 0)
		{
			if (m_Config.FirstLineFadeInMs == 0)
			{
				if (m_AnimationElapsedMs >= 0)
				{
					return 1.0;
				}

				return 0.0;
			}

			return Math.Clamp(m_AnimationElapsedMs / m_Config.FirstLineFadeInMs, 0.0, 1.0);
		}

		float startMs = m_Config.FirstLineFadeInMs + m_Config.PauseBetweenFirstLineAndInformationTextMs + ((index - 1) * m_Config.InformationLineFadeInDelayMs);
		if (m_Config.InformationLineFadeInDelayMs == 0)
		{
			if (m_AnimationElapsedMs >= startMs)
			{
				return 1.0;
			}

			return 0.0;
		}

		return Math.Clamp((m_AnimationElapsedMs - startMs) / m_Config.InformationLineFadeInDelayMs, 0.0, 1.0);
	}
}
