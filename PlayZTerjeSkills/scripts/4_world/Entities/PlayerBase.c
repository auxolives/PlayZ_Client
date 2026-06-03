modded class PlayerBase
{
	override void TerjeSendSoundEvent(string soundSet, string soundType, float volume)
	{
		float perkValue;
		float modVal;

		// Stealth perks (QuietStep/ColdBlooded/QuietShooter) are off in PlayZ config; modifiers use the same ids.
		// Terje bitmask/perk paths ignore modifiers — apply modifier fallbacks here before base Terje runs.
		if (GetGame() && GetGame().IsDedicatedServer() && GetTerjeSkills() != null)
		{
			if (soundType == TERJE_SOUND_EVENT_TYPE_VOICE)
			{
				if (!GetTerjeSkillsStealthPerkValueFromBitmask(TerjeSkillsStealthMask.TERJE_SKILLS_STEALTH_VOICE, "coldbldd", perkValue))
				{
					if (GetTerjeSkills().GetSkillModifierValue("stlth", "coldbldd", modVal))
					{
						volume = volume * Math.Clamp(1.0 + modVal, 0, 1);
					}
				}
			}
			else if (soundType == TERJE_SOUND_EVENT_TYPE_WEAPON)
			{
				if (!GetTerjeSkillsStealthPerkValueFromBitmask(TerjeSkillsStealthMask.TERJE_SKILLS_STEALTH_WEAPON, "qshooter", perkValue))
				{
					if (GetTerjeSkills().GetSkillModifierValue("stlth", "qshooter", modVal))
					{
						volume = volume * Math.Clamp(1.0 + modVal, 0, 1);
					}
				}
			}
		}

		super.TerjeSendSoundEvent(soundSet, soundType, volume);
		
		// In PlayZ, we want the Ninja perk to be more powerful (70% reduction instead of 50%)
		if (GetGame() && GetGame().IsDedicatedServer() && GetTerjeSkills() != null)
		{
			// We check if Ninja is active using the same bitmask check as the base mod
			if (GetTerjeSkillsStealthPerkValueFromBitmask(TerjeSkillsStealthMask.TERJE_SKILLS_STEALTH_NINJA, "ninja", perkValue))
			{
				// Get our custom PlayZ value from the config (which is -0.7)
				float customNinjaValue = 0;
				if (GetTerjeSkills().GetPerkValue("stlth", "ninja", customNinjaValue))
				{
					// The base mod already reduced volume by 50% (volume *= 0.5)
					// We want it to be 70% reduction (volume *= 0.3)
					// We apply the difference: 0.3 / 0.5 = 0.6
					// 0.3 is calculated as (1.0 + -0.7)
					float targetMultiplier = Math.Clamp(1.0 + customNinjaValue, 0, 1);
					float currentMultiplier = 0.5; // What TerjeSkills already applied
					
					if (targetMultiplier < currentMultiplier)
					{
						float correction = targetMultiplier / currentMultiplier;
						volume *= correction;
					}
				}
			}
		}
	}
}
