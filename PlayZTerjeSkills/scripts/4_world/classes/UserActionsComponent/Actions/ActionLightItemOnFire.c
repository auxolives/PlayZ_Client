modded class ActionLightItemOnFire
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        // Must clear juncture for vanilla sync
        ClearActionJuncture(action_data);
        
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        if (!player) return;
        
        auto accessor = player.GetTerjeSkills();
        if (!accessor) return;

        ItemBase target_item = ItemBase.Cast(action_data.m_Target.GetObject());
        ItemBase main_item = action_data.m_MainItem;
        if (!target_item || !main_item) return;

        float baseChance;
        if (!GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_SURV_IGNITE_FIRE_BASE_CHANCE, baseChance))
        {
            baseChance = 0.5; // Fallback to 50%
        }
        float successModifier;
        float durationModifier;
        
        // Success Chance Math
        if (accessor.GetSkillModifierValue("surv", "startfire", successModifier))
        {
            baseChance += successModifier;
        }
        
        float roll = Math.RandomFloat01();
        bool success = (roll <= baseChance);

        if (success)
        {
            // Execute vanilla-style ignition
            main_item.OnIgnitedTarget(target_item);
            target_item.OnIgnitedThis(main_item);
            
            // Soft Skills XP & Survival Skill EXP (Config-driven)
            action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
            
            int expGain;
            if (GetTerjeSettingInt(TerjeSettingsCollection.SKILLS_SURV_MAKE_FIRE_SUCCESS_GAIN_EXP, expGain))
                accessor.AddSkillExperience("surv", expGain); 

            // Maintaining Fire Duration (Burn rate modifier)
            FireplaceBase targetFireplace = FireplaceBase.Cast(target_item);
            if (targetFireplace && accessor.GetSkillModifierValue("surv", "maintngfire", durationModifier))
            {
                // durationModifier is positive (e.g. 0.10 per level)
                targetFireplace.SetTerjeSkillSurvFuelModifier(1.0 + durationModifier);
            }
        }
        else
        {
            // Vanilla failure logic
            main_item.OnIgnitedTargetFailed(target_item);
            target_item.OnIgnitedThisFailed(main_item);
            
            // Consume quantity on fail
            if (main_item.HasQuantity())
                main_item.AddQuantity(-1);
            else
                main_item.Delete();
                
            // Survival Skill EXP on fail (Config-driven)
            int expGainFail;
            if (GetTerjeSettingInt(TerjeSettingsCollection.SKILLS_SURV_MAKE_FIRE_FAIL_GAIN_EXP, expGainFail))
                accessor.AddSkillExperience("surv", expGainFail);
        }
    }
}
