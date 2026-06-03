modded class ActionBandageBase
{
	override void ApplySurgeryBullet(ItemBase item, PlayerBase target, PlayerBase operator)
	{
		if (item && item.IsKnifeForSurgery())
		{
			if (Math.RandomFloat01() < item.GetTerjeSurgeryBulletEffectivity(operator))
			{
				if (target.GetTerjeStats() != null)
				{
					int bulletWounds = target.GetTerjeStats().GetBulletWounds();
					if (bulletWounds > (target.GetTerjeStats().GetStubWounds() + target.GetTerjeStats().GetBandagesClean() + target.GetTerjeStats().GetBandagesDirty()))
					{
						int suturesMin = 1;
						int suturesMax = 1;
						GetTerjeSettingInt(TerjeSettingsCollection.MEDICINE_BULLETS_SUTURES_MIN, suturesMin);
						GetTerjeSettingInt(TerjeSettingsCollection.MEDICINE_BULLETS_SUTURES_MAX, suturesMax);
						
						if (suturesMin > 0 && suturesMax > 0 && suturesMin < suturesMax)
						{
							target.GetTerjeStats().SetSuturesClean(target.GetTerjeStats().GetSuturesClean() + Math.RandomIntInclusive(suturesMin, suturesMax));
						}
						else if (suturesMin > 0)
						{
							target.GetTerjeStats().SetSuturesClean(target.GetTerjeStats().GetSuturesClean() + suturesMin);
						}
					}
					
					target.GetTerjeStats().SetBulletWounds(bulletWounds - 1);
				}
				
				if (operator.GetIdentity())
				{
					NotificationSystem.SendNotificationToPlayerIdentityExtended(operator.GetIdentity(), 8, "#STR_TERJEMED_SURGERY_SUCCESS", "#STR_TERJEMED_SURGERY_BULLET_SUCCESS", "set:TerjePerk_icon image:tp_surgerybullet");
				}
				
				if (operator.GetTerjeSkills())
				{
					int bandageExpGain = 0;
					if (GetTerjeSettingInt(TerjeSettingsCollection.MEDICINE_MEDICINE_BULLET_SURGERY_EXP_GAIN, bandageExpGain) && bandageExpGain > 0)
					{
						operator.GetTerjeSkills().AddSkillExperience("med", bandageExpGain);
					}
				}
			}
			else
			{
				target.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_HEAVY);
				target.GetTerjeHealth().DecreaseHealth(GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_BULLETS_FAILED_HEALTH_LOSE), TerjeDamageSource.SURGERY_BULLETS);
				target.GetTerjeHealth().DecreaseBlood(GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_BULLETS_FAILED_BLOOD_LOSE), TerjeDamageSource.SURGERY_BULLETS);
				target.GetTerjeHealth().DecreaseShock(GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_BULLETS_FAILED_SHOCK_LOSE), TerjeDamageSource.SURGERY_BULLETS);
				
				if (operator.GetIdentity())
				{
					NotificationSystem.SendNotificationToPlayerIdentityExtended(operator.GetIdentity(), 10, "#STR_TERJEMED_SURGERY_FAILED", "#STR_TERJEMED_SURGERY_BULLET_FAILED", "set:TerjePerkBlack_icon image:tp_surgerybullet");
				}
			}
			
			CheckInfectionSurgery(item, target, operator);
			
			// Prevent knife deletion by intercepting the final execution and dealing 10 condition damage instead
			item.AddHealth("","",-10);
			return;
		}
		
		super.ApplySurgeryBullet(item, target, operator);
	}
}
