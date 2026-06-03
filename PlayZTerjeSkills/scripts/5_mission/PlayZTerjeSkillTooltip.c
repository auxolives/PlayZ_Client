class PlayZTerjeSkillTooltip
{
    // Widget is recreated only when Unlink()d by HideTooltip() (i.e. cursor left the skill).
    // When hovering quickly between skills, the parented widget is reused — no XML parse or FindAnyWidget calls.
    // Child refs are re-cached only after each CreateWidgets() call.
    private static ref Widget m_skillTooltipInstance = null;
    private static ImageWidget m_TooltipIcon = null;
    private static TextWidget  m_TooltipName = null;
    private static TextWidget  m_TooltipInfo = null;
    private static TextWidget  m_TooltipLevel = null;
    private static TextWidget  m_TooltipExp = null;
    private static TextWidget  m_TooltipPoints = null;
    private static Widget      m_TooltipContentSpacer = null;
    private static Widget      m_TooltipContent = null;

    static ref Widget GetSkillTooltipWidget(TerjeSkillCfg skillCfg, int exp, int points)
    {
        // Recreate when null OR when HideTooltip() has Unlink()d us from the parent layout.
        // GetParent() returns null on an unlinked widget — that's the signal to re-parent via CreateWidgets.
        if (!m_skillTooltipInstance || !m_skillTooltipInstance.GetParent())
        {
            m_skillTooltipInstance = GetGame().GetWorkspace().CreateWidgets("TerjeSkills/Layouts/TerjeSkillTooltip.layout", ItemManager.GetInstance().GetTerjeSkillsRoot());
            m_skillTooltipInstance.Show(false);

            // Cache all child widget refs — re-runs only when widget is recreated after Unlink
            m_TooltipIcon          = ImageWidget.Cast(m_skillTooltipInstance.FindAnyWidget("terje_skill_tooltip_icon"));
            m_TooltipName          = TextWidget.Cast(m_skillTooltipInstance.FindAnyWidget("terje_skill_tooltip_name"));
            m_TooltipInfo          = TextWidget.Cast(m_skillTooltipInstance.FindAnyWidget("terje_skill_tooltip_info"));
            m_TooltipLevel         = TextWidget.Cast(m_skillTooltipInstance.FindAnyWidget("terje_skill_tooltip_level"));
            m_TooltipExp           = TextWidget.Cast(m_skillTooltipInstance.FindAnyWidget("terje_skill_tooltip_exp"));
            m_TooltipPoints        = TextWidget.Cast(m_skillTooltipInstance.FindAnyWidget("terje_skill_tooltip_points"));
            m_TooltipContentSpacer = m_skillTooltipInstance.FindAnyWidget("terje_skill_tooltip_content_spacer");
            m_TooltipContent       = m_skillTooltipInstance.FindAnyWidget("terje_skill_tooltip_content");
        }

        int level = skillCfg.GetLevelFromExp(exp);
        string expStr = "MAX";
        if (level < skillCfg.GetMaxLevel())
        {
            expStr = exp.ToString() + "/" + skillCfg.GetExpForLevel(level + 1).ToString();
        }

        string info = skillCfg.GetDescription();
        ref array<ref TerjeSkillModifierCfg> modifiers = new array<ref TerjeSkillModifierCfg>;
        skillCfg.GetModifiers(modifiers);
        if (modifiers.Count() > 0)
        {
            info = info + "<br/>";
            foreach (ref TerjeSkillModifierCfg modifier : modifiers)
            {
                string totalPercent = TerjeMathHelper.ToDisplayPercent(modifier.GetValue() * level);
                info = info + "<br/>" + modifier.GetText() + " <color rgba='97,215,124,255'>" + totalPercent + "%</color>";
            }
        }

        m_TooltipIcon.LoadImageFile(0, skillCfg.GetIcon());
        m_TooltipName.SetText(skillCfg.GetDisplayName());
        m_TooltipInfo.SetText(info);
        m_TooltipLevel.SetText("#STR_TERJESKILL_MISC1: " + level.ToString() + "/" + skillCfg.GetMaxLevel().ToString());
        m_TooltipExp.SetText("#STR_TERJESKILL_MISC2: " + expStr);
        m_TooltipPoints.SetText("#STR_TERJESKILL_MISC3: " + points);

        m_TooltipContentSpacer.Update();
        m_TooltipContent.Update();

        return m_skillTooltipInstance;
    }
}
