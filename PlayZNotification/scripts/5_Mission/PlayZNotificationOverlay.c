class PlayZNotificationOverlay
{
	protected static const float MAX_CONTENT_WIDTH = 900.0;
	protected static const float CONTENT_LINE_GAP = 8.0;
	protected static const float BODY_MEASURE_MAX_HEIGHT = 600.0;
	protected static const float SHADOW_OPACITY_SCALE = 0.6;

	protected ref PlayZNotificationConfig m_Config;
	protected ref PlayZNotificationEntry m_Entry;

	protected Widget m_Root;
	protected RichTextWidget m_TitleText;
	protected RichTextWidget m_BodyText;

	protected float m_ElapsedMs;
	protected float m_TotalMs;
	protected float m_FadeInMs;
	protected float m_HoldMs;
	protected float m_FadeOutMs;
	protected float m_ScreenScale;
	protected bool m_Finished;

	protected bool m_ShowTitle;
	protected bool m_ShowMessage;

	void PlayZNotificationOverlay(PlayZNotificationEntry entry, PlayZNotificationConfig config)
	{
		m_Entry = entry;
		m_Config = config;
		m_ScreenScale = GetScreenScale();
		m_FadeInMs = m_Config.FadeInMs;
		m_HoldMs = m_Entry.HoldSeconds * 1000.0;
		m_FadeOutMs = m_Config.FadeOutMs;
		m_TotalMs = m_FadeInMs + m_HoldMs + m_FadeOutMs;

		m_ShowTitle = m_Config.UsesShowTitle() && m_Entry.Title != "";
		m_ShowMessage = m_Config.UsesShowMessage() && m_Entry.Message != "";

		CreateWidgets();
		FitContentLayout();
		ApplyScreenCenterPosition();
	}

	void ~PlayZNotificationOverlay()
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
		UpdateAlpha();

		if (m_ElapsedMs >= m_TotalMs)
		{
			m_Finished = true;
		}
	}

	protected void CreateWidgets()
	{
		m_Root = GetGame().GetWorkspace().CreateWidgets(PlayZNotificationPaths.LAYOUT_NOTIFICATION);
		if (!m_Root)
		{
			return;
		}

		m_TitleText = RichTextWidget.Cast(m_Root.FindAnyWidget("NotificationTitle"));
		m_BodyText = RichTextWidget.Cast(m_Root.FindAnyWidget("NotificationBody"));

		int titleColor = ParseConfiguredColor(m_Config.TitleTextColor, ARGB(255, 255, 255, 255));
		int bodyColor = ParseConfiguredColor(m_Config.BodyTextColor, ARGB(255, 232, 232, 232));

		int shadowSize = Math.Max(1, Math.Round(2.0 * m_ScreenScale));
		float shadowOffsetX = Math.Max(1.0, 1.0 * m_ScreenScale);
		float shadowOffsetY = Math.Max(1.0, 2.0 * m_ScreenScale);

		if (m_ShowTitle && m_TitleText)
		{
			int titleSize = Math.Max(1, Math.Round(m_Config.TitleTextSize * m_ScreenScale));
			m_TitleText.SetText(FormatNotificationText(m_Entry.Title));
			m_TitleText.SetTextExactSize(titleSize);
			m_TitleText.SetColor(titleColor);
			m_TitleText.SetShadow(shadowSize, ARGB(255, 0, 0, 0), 0.0, shadowOffsetX, shadowOffsetY);
			m_TitleText.Show(true);
		}
		else
		{
			if (m_TitleText)
			{
				m_TitleText.Show(false);
			}
		}

		if (m_ShowMessage && m_BodyText)
		{
			int bodySize = Math.Max(1, Math.Round(m_Config.BodyTextSize * m_ScreenScale));
			m_BodyText.SetText(FormatNotificationText(m_Entry.Message));
			m_BodyText.SetTextExactSize(bodySize);
			m_BodyText.SetColor(bodyColor);
			m_BodyText.SetShadow(shadowSize, ARGB(255, 0, 0, 0), 0.0, shadowOffsetX, shadowOffsetY);
			m_BodyText.Show(true);
		}
		else
		{
			if (m_BodyText)
			{
				m_BodyText.Show(false);
			}
		}

		m_Root.SetAlpha(0);
		if (m_TitleText && m_ShowTitle)
		{
			m_TitleText.SetAlpha(0);
		}

		if (m_BodyText && m_ShowMessage)
		{
			m_BodyText.SetAlpha(0);
		}
	}

	protected string FormatNotificationText(string text)
	{
		if (text == "")
		{
			return "";
		}

		string formatted = text;
		formatted.Replace("<br>", "<br/>");
		formatted.Replace("<BR>", "<br/>");
		formatted.Replace("<br />", "<br/>");
		formatted.Replace("<BR />", "<br/>");
		return formatted;
	}

	protected void FitContentLayout()
	{
		if (!m_Root)
		{
			return;
		}

		float maxWidth = MAX_CONTENT_WIDTH * m_ScreenScale;
		float lineGap = CONTENT_LINE_GAP * m_ScreenScale;
		float measureMaxHeight = BODY_MEASURE_MAX_HEIGHT * m_ScreenScale;

		if (m_ShowTitle && m_TitleText)
		{
			m_TitleText.Update();
		}

		if (m_ShowMessage && m_BodyText)
		{
			m_BodyText.Update();
		}

		float titleWidth;
		float titleHeight;
		float bodyWidth;
		float bodyHeight;
		titleWidth = 0;
		titleHeight = 0;
		bodyWidth = 0;
		bodyHeight = 0;

		if (m_ShowTitle && m_TitleText)
		{
			m_TitleText.GetScreenSize(titleWidth, titleHeight);
		}

		if (m_ShowMessage && m_BodyText)
		{
			m_BodyText.GetScreenSize(bodyWidth, bodyHeight);
		}

		float contentWidth = Math.Max(titleWidth, bodyWidth);
		if (contentWidth > maxWidth)
		{
			contentWidth = maxWidth;
		}

		if (contentWidth < 1.0)
		{
			contentWidth = 1.0;
		}

		if (m_ShowTitle && m_TitleText)
		{
			m_TitleText.SetSize(contentWidth, titleHeight);
			m_TitleText.Update();
			m_TitleText.GetScreenSize(titleWidth, titleHeight);
		}

		if (m_ShowMessage && m_BodyText)
		{
			m_BodyText.SetSize(contentWidth, measureMaxHeight);
			m_BodyText.Update();
			m_BodyText.GetScreenSize(bodyWidth, bodyHeight);

			if (bodyHeight < 1.0)
			{
				bodyHeight = EstimateBodyHeight();
			}
		}

		float contentHeight = 0;
		if (m_ShowTitle)
		{
			contentHeight += titleHeight;
		}

		if (m_ShowTitle && m_ShowMessage)
		{
			contentHeight += lineGap;
		}

		if (m_ShowMessage)
		{
			contentHeight += bodyHeight;
		}

		if (contentHeight < 1.0)
		{
			contentHeight = 32.0 * m_ScreenScale;
		}

		if (m_ShowMessage && m_BodyText)
		{
			float bodyY = 0;
			if (m_ShowTitle)
			{
				bodyY = titleHeight + lineGap;
			}

			m_BodyText.SetPos(0, bodyY);
			m_BodyText.SetSize(contentWidth, bodyHeight);
			m_BodyText.Update();
		}

		m_Root.SetSize(contentWidth, contentHeight);
		m_Root.Update();
	}

	protected float EstimateBodyHeight()
	{
		if (!m_ShowMessage || m_Entry.Message == "")
		{
			return 0;
		}

		int bodySize = Math.Max(1, Math.Round(m_Config.BodyTextSize * m_ScreenScale));
		int lineCount = CountLineBreaks(m_Entry.Message) + 1;
		return lineCount * (bodySize + 6) * m_ScreenScale;
	}

	protected int CountLineBreaks(string text)
	{
		int count = 0;
		string probe = text;
		string token = "<br/>";

		while (probe.IndexOf(token) > -1)
		{
			count++;
			int index = probe.IndexOf(token);
			probe = probe.Substring(index + token.Length(), probe.Length() - index - token.Length());
		}

		probe = text;
		token = "<br>";
		while (probe.IndexOf(token) > -1)
		{
			count++;
			int index2 = probe.IndexOf(token);
			probe = probe.Substring(index2 + token.Length(), probe.Length() - index2 - token.Length());
		}

		return count;
	}

	protected void ApplyScreenCenterPosition()
	{
		if (!m_Root)
		{
			return;
		}

		float screenWidth;
		float screenHeight;
		GetGame().GetWorkspace().GetScreenSize(screenWidth, screenHeight);

		float marginX = m_Config.MarginX * m_ScreenScale;
		float marginY = m_Config.MarginY * m_ScreenScale;

		float rootWidth;
		float rootHeight;
		m_Root.GetScreenSize(rootWidth, rootHeight);

		float posX = ((screenWidth - rootWidth) * 0.5) + marginX;
		float posY = ((screenHeight - rootHeight) * 0.5) + marginY;
		m_Root.SetPos(posX, posY);
	}

	protected void UpdateAlpha()
	{
		float alpha = 1.0;

		if (m_ElapsedMs < m_FadeInMs)
		{
			if (m_FadeInMs > 0)
			{
				alpha = SmoothStep(m_ElapsedMs / m_FadeInMs);
			}
		}
		else
		{
			float fadeOutStart = m_FadeInMs + m_HoldMs;
			if (m_ElapsedMs >= fadeOutStart)
			{
				float fadeOutT = 0.0;
				if (m_FadeOutMs > 0)
				{
					fadeOutT = (m_ElapsedMs - fadeOutStart) / m_FadeOutMs;
				}

				alpha = 1.0 - SmoothStep(Math.Clamp(fadeOutT, 0.0, 1.0));
			}
		}

		int shadowSize = Math.Max(1, Math.Round(2.0 * m_ScreenScale));
		float shadowOffsetX = Math.Max(1.0, 1.0 * m_ScreenScale);
		float shadowOffsetY = Math.Max(1.0, 2.0 * m_ScreenScale);
		float shadowAlpha = alpha * SHADOW_OPACITY_SCALE;

		m_Root.SetAlpha(alpha);

		if (m_TitleText && m_ShowTitle)
		{
			m_TitleText.SetAlpha(alpha);
			m_TitleText.SetShadow(shadowSize, ARGB(255, 0, 0, 0), shadowAlpha, shadowOffsetX, shadowOffsetY);
		}

		if (m_BodyText && m_ShowMessage)
		{
			m_BodyText.SetAlpha(alpha);
			m_BodyText.SetShadow(shadowSize, ARGB(255, 0, 0, 0), shadowAlpha, shadowOffsetX, shadowOffsetY);
		}
	}

	protected float GetScreenScale()
	{
		if (!m_Config.UsesScaleToScreen())
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

	protected float SmoothStep(float t)
	{
		t = Math.Clamp(t, 0.0, 1.0);
		return t * t * (3.0 - 2.0 * t);
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
			if (!TryParseHexByte(normalized.Substring(0, 2), r))
			{
				return fallbackColor;
			}

			if (!TryParseHexByte(normalized.Substring(2, 2), g))
			{
				return fallbackColor;
			}

			if (!TryParseHexByte(normalized.Substring(4, 2), b))
			{
				return fallbackColor;
			}

			return ARGB(255, r, g, b);
		}

		if (normalized.Length() == 8)
		{
			int a;
			int r2;
			int g2;
			int b2;
			if (!TryParseHexByte(normalized.Substring(0, 2), a))
			{
				return fallbackColor;
			}

			if (!TryParseHexByte(normalized.Substring(2, 2), r2))
			{
				return fallbackColor;
			}

			if (!TryParseHexByte(normalized.Substring(4, 2), g2))
			{
				return fallbackColor;
			}

			if (!TryParseHexByte(normalized.Substring(6, 2), b2))
			{
				return fallbackColor;
			}

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
		if (digit == "0")
		{
			return 0;
		}

		if (digit == "1")
		{
			return 1;
		}

		if (digit == "2")
		{
			return 2;
		}

		if (digit == "3")
		{
			return 3;
		}

		if (digit == "4")
		{
			return 4;
		}

		if (digit == "5")
		{
			return 5;
		}

		if (digit == "6")
		{
			return 6;
		}

		if (digit == "7")
		{
			return 7;
		}

		if (digit == "8")
		{
			return 8;
		}

		if (digit == "9")
		{
			return 9;
		}

		if (digit == "A" || digit == "a")
		{
			return 10;
		}

		if (digit == "B" || digit == "b")
		{
			return 11;
		}

		if (digit == "C" || digit == "c")
		{
			return 12;
		}

		if (digit == "D" || digit == "d")
		{
			return 13;
		}

		if (digit == "E" || digit == "e")
		{
			return 14;
		}

		if (digit == "F" || digit == "f")
		{
			return 15;
		}

		return -1;
	}
}
