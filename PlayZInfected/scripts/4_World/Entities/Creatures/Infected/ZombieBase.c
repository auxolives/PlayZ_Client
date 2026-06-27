modded class ZombieBase
{
	protected bool m_PlayZSpawnDead;

	override void EEOnCECreate()
	{
		super.EEOnCECreate();
		if (GetGame().IsServer())
		{
			m_PlayZSpawnDead = PlayZInfectedConfig.GetInstance().RollSpawnDead();
		}
	}

	override void EOnInit(IEntity other, int extra)
	{
		super.EOnInit(other, extra);
		if (GetGame().IsServer() && m_PlayZSpawnDead)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(InediaInfectedAI_InitOnceServer, 0, false);
		}
	}

	override void InediaInfectedAI_InitOnceServer()
	{
		super.InediaInfectedAI_InitOnceServer();
		if (GetGame().IsServer() && m_PlayZSpawnDead)
		{
			PlayZ_ApplySpawnDead();
		}
	}

	protected void PlayZ_ApplySpawnDead()
	{
		m_DeathType = DayZInfectedDeathAnims.ANIM_DEATH_DEFAULT;
		m_DamageHitDirection = Math.RandomFloatInclusive(0, 360);
		InediaInfectedAI_Kill();
		if (GetAIAgent())
		{
			GetAIAgent().SetKeepInIdle(true);
		}
	}
}
