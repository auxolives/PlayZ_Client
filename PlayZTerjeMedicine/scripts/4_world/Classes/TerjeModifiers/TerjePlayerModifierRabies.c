modded class TerjePlayerModifierRabies
{
	override void OnServerFixedTick(PlayerBase player, float deltaTime)
	{
		// Force zero rabies if vaccinated or immune via perk BEFORE base logic runs to ensure total immunity
		float rabresValue = 0;
		if (player.GetTerjeStats() && (player.GetTerjeStats().GetRabiesVacineValue() > 0 || (player.GetTerjeSkills() && player.GetTerjeSkills().GetPerkValue("immunity", "rabres", rabresValue) && rabresValue >= 1.0)))
		{
			player.GetTerjeStats().SetRabiesValue(0);
		}
		
		super.OnServerFixedTick(player, deltaTime);
	}
}
