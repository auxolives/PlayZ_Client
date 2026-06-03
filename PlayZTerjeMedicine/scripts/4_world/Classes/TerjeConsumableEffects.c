modded class TerjeConsumableEffects
{
	override void Apply(EntityAI entity, string classname, PlayerBase player, float amount)
	{
		super.Apply(entity, classname, player, amount);
		
		if (player && player.GetTerjeStats() && entity)
		{
			float medRabiesInfectionChance = GetTerjeGameConfig().ConfigGetFloat( classname + " medRabiesInfectionChance" );
			if (medRabiesInfectionChance > 0)
			{
				Edible_Base food = Edible_Base.Cast(entity);
				if (food && !food.m_PlayZ_RabiesRolled)
				{
					food.m_PlayZ_RabiesRolled = true;
					
					// Only raw or rotten meat can infect the player with Rabies
					FoodStage foodStage = food.GetFoodStage();
					if (foodStage && (foodStage.IsFoodRaw() || foodStage.IsFoodRotten()))
					{
						float rabResist = 0;
						bool isWildMeatLover = false;

						if (player.GetTerjeSkills())
						{
							player.GetTerjeSkills().GetPerkValue("immunity", "rabres", rabResist);
							isWildMeatLover = player.GetTerjeSkills().GetPerkLevel("mtblsm", "wmlover") > 0;
						}

						if (rabResist < 1.0 && !isWildMeatLover && Math.RandomFloat01() < medRabiesInfectionChance)
						{
							// Infect with Rabies (0.75 is the standard bite value)
							player.GetTerjeStats().SetRabiesValue(player.GetTerjeStats().GetRabiesValue() + 0.75);
						}
					}
				}
			}
		}
	}
}
