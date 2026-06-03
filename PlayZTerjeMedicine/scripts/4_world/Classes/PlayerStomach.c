modded class PlayerStomach
{
	override void ProcessNutrients(float delta_time)
	{
		float rabies = 0;
		if (m_Player)
			rabies = m_Player.PlayZ_GetRabiesValue();

		if (rabies <= 0)
		{
			super.ProcessNutrients(delta_time);
			return;
		}

		int rabiesStage = Math.Floor(rabies);
		float waterModifier = 1.0;
		if      (rabiesStage == 1) waterModifier = 0.30;
		else if (rabiesStage == 2) waterModifier = 0.15;
		else if (rabiesStage >= 3) waterModifier = 0.0;

		m_DigestingType = 0;

		int stomachItemsCount = m_StomachContents.Count();
		if (stomachItemsCount == 0)
			return;

		float digestionPointsPerItem = (DIGESTION_POINTS / stomachItemsCount) * delta_time;
		m_StomachVolume = 0;

		float totalEnergyToAdd = 0;
		float totalWaterToAdd = 0;

		for (int i = stomachItemsCount - 1; i >= 0; i--)
		{
			StomachItem item = m_StomachContents[i];

			float water, energy, toxicity, volume, consumedAmount;
			int   agents;

			if (item.ProcessDigestion(digestionPointsPerItem, water, energy, toxicity, volume, agents, consumedAmount))
			{
				m_StomachContents.Remove(i);
				UpdateStomachTemperature();
			}

			m_StomachVolume += volume;
			totalEnergyToAdd += energy;
			totalWaterToAdd += (water * waterModifier);

			if (energy > 0)
				m_DigestingType |= DIGESTING_ENERGY;
			if (water > 0 && waterModifier > 0)
				m_DigestingType |= DIGESTING_WATER;

			float amtAgents = item.m_Profile.m_AgentsPerDigest;
			if (amtAgents == 0)
				amtAgents = consumedAmount;

			if ((item.m_Agents & eAgents.FOOD_POISON) == eAgents.FOOD_POISON && m_Player.HasBloodyHands())
				amtAgents = Math.Max(amtAgents, PlayerConstants.BLOODY_HANDS_FOOD_POISON_AGENT_INCREMENT);

			DigestAgents(agents, amtAgents);
		}

		if (totalEnergyToAdd != 0) m_Player.GetStatEnergy().Add(totalEnergyToAdd);
		if (totalWaterToAdd != 0)  m_Player.GetStatWater().Add(totalWaterToAdd);
	}
}
