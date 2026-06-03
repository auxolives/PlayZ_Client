modded class TerjePlayerSkillsAccessor
{
    override bool GetPerkValue(string skillId, string perkId, out float result)
    {
        if (super.GetPerkValue(skillId, perkId, result))
        {
            return true;
        }

        return GetSkillModifierValue(skillId, perkId, result);
    }

    override bool IsPerkRegistered(string skillId, string perkId)
    {
        if (super.IsPerkRegistered(skillId, perkId))
        {
            return true;
        }

        ref TerjeSkillCfg skillCfg;
        if (GetTerjeSkillsRegistry().FindSkill(skillId, skillCfg))
        {
            ref TerjeSkillModifierCfg modifierCfg;
            if (skillCfg.FindModifier(perkId, modifierCfg))
            {
                return true;
            }
        }

        return false;
    }
}
