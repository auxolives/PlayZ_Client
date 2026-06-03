modded class DayZPlayerImplement
{
	override void OnStepEvent(string pEventType, string pUserString, int pUserInt)
	{
		if (GetGame().IsClient())
		{
			float perkValue;
			PlayerBase player = PlayerBase.Cast(this);
			if (player)
			{
				AnimBootsType bootsType = GetBootsType();
				if (bootsType == AnimBootsType.None)
				{
					if (player.GetTerjeSkillsStealthPerkValueFromBitmask(TerjeSkillsStealthMask.TERJE_SKILLS_STEALTH_FEETS, "shadowtrc", perkValue))
					{
						HumanMovementState state = new HumanMovementState();
						GetMovementState(state);
						if (state.m_iMovement != DayZPlayerConstants.MOVEMENTIDX_SPRINT)
						{
							ModifyTerjeWaveMasterVolume(0);
						}
					}
				}

				if (player.GetTerjeSkillsStealthPerkValueFromBitmask(TerjeSkillsStealthMask.TERJE_SKILLS_STEALTH_SHOES, "qtstep", perkValue))
				{
					ModifyTerjeWaveMasterVolume(Math.Clamp(1.0 + perkValue, 0, 1));
				}
				else
				{
					float qtMod;
					if (player.GetTerjeSkills() && player.GetTerjeSkills().GetSkillModifierValue("stlth", "qtstep", qtMod))
					{
						ModifyTerjeWaveMasterVolume(Math.Clamp(1.0 + qtMod, 0, 1));
					}
				}

				if (player.GetTerjeSkillsStealthPerkValueFromBitmask(TerjeSkillsStealthMask.TERJE_SKILLS_STEALTH_NINJA, "ninja", perkValue))
				{
					ModifyTerjeWaveMasterVolume(0.5);
				}
			}
		}

		super.OnStepEvent(pEventType, pUserString, pUserInt);
		ResetTerjeWaveMasterVolume();
	}

	override void OnSoundEvent(string pEventType, string pUserString, int pUserInt)
	{
		if (GetGame().IsClient())
		{
			float perkValue;
			PlayerBase player = PlayerBase.Cast(this);
			if (player)
			{
				if (pEventType == "SoundVoice")
				{
					if (player.GetTerjeSkillsStealthPerkValueFromBitmask(TerjeSkillsStealthMask.TERJE_SKILLS_STEALTH_VOICE, "coldbldd", perkValue))
					{
						ModifyTerjeWaveMasterVolume(Math.Clamp(1.0 + perkValue, 0, 1));
					}
					else
					{
						float coldMod;
						if (player.GetTerjeSkills() && player.GetTerjeSkills().GetSkillModifierValue("stlth", "coldbldd", coldMod))
						{
							ModifyTerjeWaveMasterVolume(Math.Clamp(1.0 + coldMod, 0, 1));
						}
					}
				}
				else if (pEventType == "SoundAttachment")
				{
					if (player.GetTerjeSkillsStealthPerkValueFromBitmask(TerjeSkillsStealthMask.TERJE_SKILLS_STEALTH_CLOTHES, "fitequip", perkValue))
					{
						ModifyTerjeWaveMasterVolume(Math.Clamp(1.0 + perkValue, 0, 1));
					}
				}
				else if (pEventType == "SoundWeapon" || pEventType == "Sound")
				{
					if (player.GetTerjeSkillsStealthPerkValueFromBitmask(TerjeSkillsStealthMask.TERJE_SKILLS_STEALTH_WEAPON, "qshooter", perkValue))
					{
						ModifyTerjeWaveMasterVolume(Math.Clamp(1.0 + perkValue, 0, 1));
					}
					else
					{
						float qsMod;
						if (player.GetTerjeSkills() && player.GetTerjeSkills().GetSkillModifierValue("stlth", "qshooter", qsMod))
						{
							ModifyTerjeWaveMasterVolume(Math.Clamp(1.0 + qsMod, 0, 1));
						}
					}
				}

				if (player.GetTerjeSkillsStealthPerkValueFromBitmask(TerjeSkillsStealthMask.TERJE_SKILLS_STEALTH_NINJA, "ninja", perkValue))
				{
					ModifyTerjeWaveMasterVolume(0.5);
				}
			}
		}

		super.OnSoundEvent(pEventType, pUserString, pUserInt);
		ResetTerjeWaveMasterVolume();
	}
}
