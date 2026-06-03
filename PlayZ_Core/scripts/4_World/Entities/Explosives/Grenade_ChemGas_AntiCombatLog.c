modded class Grenade_ChemGas
{
	override void EOnContact(IEntity other, Contact extra)
	{
		super.EOnContact(other, extra);

		if (!g_Game.IsServer())
		{
			return;
		}

		PlayZ_TriggerCombatPlayersInRadius(PlayZAntiCombatLogConfig.Get().TriggerOnExplosiveRadius);
	}
}
