modded class ShelterSite
{
	float m_PlayZ_CalculatedHealth01 = 1.0;

	override void OnPartBuiltServer(notnull Man player, string part_name, int action_id)
	{
		string shelter_type = "";
		switch (part_name)
		{
			case "leather": 
				shelter_type = "ShelterLeather";
			break;
			
			case "fabric": 
				shelter_type = "ShelterFabric";
			break;
			
			case "stick": 
				shelter_type = "ShelterStick";
			break;
		}
		
		if (shelter_type != "")
		{
			GetConstruction().DropNonUsableMaterialsServer(player, part_name);
			
			ShelterTurnItemLambda lambda = new ShelterTurnItemLambda(this, shelter_type, PlayerBase.Cast(player), m_PlayZ_CalculatedHealth01);
			MiscGameplayFunctions.TurnItemIntoItemEx(PlayerBase.Cast(player), lambda);
			
			PluginAdminLog admin_log = PluginAdminLog.Cast(GetPlugin(PluginAdminLog));
			if (admin_log)
			{
				string playerPrefix = admin_log.GetPlayerPrefix(PlayerBase.Cast(player), player.GetIdentity());
				admin_log.DirectAdminLogPrint(playerPrefix +" built " + shelter_type + " with Hands (Weighted Health: " + (m_PlayZ_CalculatedHealth01 * 100) + "%)");
			}
			
			// Return to prevent vanilla from spawning another pristine shelter and spamming logs
			return;
		}
		else
		{
			super.OnPartBuiltServer(player, part_name, action_id);
		}
	}
}

class ShelterTurnItemLambda : TurnItemIntoItemLambda
{
	float m_Health01;
	
	void ShelterTurnItemLambda(EntityAI old_item, string new_item_type, PlayerBase player, float health01)
	{
		m_Health01 = health01;
	}

	override void OnSuccess(EntityAI new_item)
	{
		super.OnSuccess(new_item);
		if (new_item)
		{
			new_item.SetHealth01("", "Health", m_Health01);
		}
	}
}
