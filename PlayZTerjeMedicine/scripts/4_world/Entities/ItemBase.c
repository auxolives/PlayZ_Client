modded class ItemBase
{
	override void SetActions()
	{
		super.SetActions();

		// Add surgery actions natively to knives without them needing `ActionSewSelf` defined like `SewingKit`
		if (IsKnifeForSurgery())
		{
			AddAction(ActionSurgeryBulletSelf);
			AddAction(ActionSurgeryBulletTarget);
		}
	}
	
	bool IsKnifeForSurgery()
	{
		string type = GetType();
		type.ToLower();
		
		if (type.Contains("knife") || type.Contains("bayonet"))
		{
			return true;
		}
		
		return false;
	}
	
	override float GetTerjeSurgeryBulletEffectivity(PlayerBase player)
	{
		if (IsKnifeForSurgery())
		{
			// Give knives a base 30% success rate instead of vanilla defaults
			float result = GetTerjeGameConfig().ConfigGetFloat("CfgVehicles " + GetType() + " terjeSurgeryBulletEffectivity");
			if (result <= 0)
			{
				result = 0.30; // Set base knife success to 30%
			}
			
			float perkValue;
			if (player && player.GetTerjeSkills() && player.GetTerjeSkills().GetPerkValue("med", "surgbw", perkValue))
			{
				float perkAffectRange = Math.Clamp(1.0 - result, 0, 1);
				result = result + (perkAffectRange * perkValue);
			}
			
			float settingMod;
			if (!GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_BULLET_SURGERY_EFF_MOD, settingMod))
			{
				settingMod = 1.0;
			}
			
			return result * settingMod;
		}
		
		return super.GetTerjeSurgeryBulletEffectivity(player);
	}
}
