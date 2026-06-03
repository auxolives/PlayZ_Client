modded class InediaInfectedAI_Restrictions
{
	override static float SmellsSystem_ModifyPlayerSmellRadius(PlayerBase player, int woundStatus, float defaultRadiusMeters)
	{
		float result = super.SmellsSystem_ModifyPlayerSmellRadius(player, woundStatus, defaultRadiusMeters);
		result = InediaInvismanCompat.ApplySmellRadius(player, result);
		
		return Math.Clamp(result, 0, 100);
	}
}
