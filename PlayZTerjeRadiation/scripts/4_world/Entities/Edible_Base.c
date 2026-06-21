// Scales Terje ingest dose after super.Consume (TerjeRadiation/EdibleBase.c).
// Tunable: $profile:PlayZ/Radiation.json (m_FoodIngestRadMultiplier, server-only).
modded class Edible_Base
{
	override bool Consume(float amount, PlayerBase consumer)
	{
		float accumBefore = 0;
		if (GetGame().IsDedicatedServer() && consumer && consumer.GetTerjeStats())
		{
			accumBefore = consumer.GetTerjeStats().GetRadiationAccumulated();
		}

		if (!super.Consume(amount, consumer))
		{
			return false;
		}

		if (GetGame().IsDedicatedServer() && consumer && consumer.GetTerjeStats())
		{
			float mult = PlayZRadiationManager.GetRadiation().m_FoodIngestRadMultiplier;
			if (mult < 1.0)
			{
				float accumAfter = consumer.GetTerjeStats().GetRadiationAccumulated();
				float added = accumAfter - accumBefore;
				if (added > 0)
				{
					consumer.GetTerjeStats().SetRadiationAccumulated(accumBefore + (added * mult));
					consumer.UpdateTerjeRadiationAccumulated();
				}
			}
		}

		return true;
	}
}
