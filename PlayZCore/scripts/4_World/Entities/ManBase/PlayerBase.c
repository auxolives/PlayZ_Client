modded class PlayerBase
{
	protected int m_PlayZDyingHealthSynch = 1000;
	protected float m_PlayZDyingHealthSyncAccum;

	override void Init()
	{
		super.Init();
		RegisterNetSyncVariableInt("m_PlayZDyingHealthSynch", 0, 1000);
	}

	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);
		PlayZUpdateDyingHealthSynchServer(deltaTime);
	}

	void PlayZUpdateDyingHealthSynchServer(float deltaTime)
	{
		if (!GetGame().IsServer() || !IsAlive())
		{
			return;
		}

		if (!PlayZCoreConfig.GetInstance().m_EnableDyingPPE)
		{
			return;
		}

		m_PlayZDyingHealthSyncAccum = m_PlayZDyingHealthSyncAccum + deltaTime;
		if (m_PlayZDyingHealthSyncAccum < PlayZPPEUpdateGate.SAMPLE_INTERVAL_SEC)
		{
			return;
		}

		m_PlayZDyingHealthSyncAccum = 0;

		float health = GetHealth("GlobalHealth", "Health");
		float start = PlayZCoreConfig.GetInstance().m_DyingHealthStart;
		int newSynch;

		if (health > start + 5.0)
		{
			newSynch = 1000;
		}
		else
		{
			newSynch = Math.Clamp(Math.Round(health * 10), 0, 1000);
		}

		if (m_PlayZDyingHealthSynch != newSynch)
		{
			m_PlayZDyingHealthSynch = newSynch;
			SetSynchDirty();
		}
	}

	float PlayZGetDyingPPEHealthForPPE()
	{
		if (GetGame().IsClient())
		{
			return m_PlayZDyingHealthSynch * 0.1;
		}

		return GetHealth("GlobalHealth", "Health");
	}

	override bool CanEatAndDrink()
	{
		if (!super.CanEatAndDrink())
		{
			return false;
		}

		if (PlayZCoreConfig.GetInstance().BlockEatingWithMouthCover && !PlayZMouthBlocker.IsBypassMouthCheck())
		{
			if (PlayZMouthBlocker.IsMouthCovered(this))
			{
				return false;
			}
		}

		return true;
	}
	
	private float m_PlayZCombatLogTimer = 0;
	private bool m_PlayZKillPlayerForCombatLogging = false;
	private int m_PlayZWillBePunishedForCombatLogging = 0;
	private int m_PlayZDisableExitButtonSecs = 5;

	ref map<string, bool> m_PlayZShotAtUsFirst = new map<string, bool>;

	PlayerBase PlayZ_GetPlayerById(int id)
	{
		array<Man> players = new array<Man>;
		GetGame().GetPlayers(players);

		foreach (Man playerMan : players)
		{
			PlayerBase player = PlayerBase.Cast(playerMan);
			if (player && player.GetID() == id)
			{
				return player;
			}
		}

		return null;
	}

	int GetDisableExitButtonSecs()
	{
		return m_PlayZDisableExitButtonSecs;
	}

	void InformPlayerOfCombatLogout(int willBeKilled)
	{
		Param2<int, int> params = new Param2<int, int>(willBeKilled, PlayZAntiCombatLogConfig.Get().DisableExitButtonSecs);
		GetGame().RPCSingleParam(this, PlayZAntiCombatLogRPCs.ANTI_COMBAT_LOG_MSG_RPC, params, true, GetIdentity());
		m_PlayZWillBePunishedForCombatLogging = willBeKilled;
	}

	int WillBePunishedForCombatLogging()
	{
		return m_PlayZWillBePunishedForCombatLogging;
	}

	void SetCombatLogTimer(PlayerBase attacker = null, PlayerBase victim = null)
	{
		if (attacker != victim && victim && attacker)
		{
			if (!victim.m_PlayZShotAtUsFirst.Contains(attacker.GetCachedID()))
			{
				attacker.m_PlayZShotAtUsFirst.Set(victim.GetCachedID(), false);
				victim.m_PlayZShotAtUsFirst.Set(attacker.GetCachedID(), true);
			}
		}

		m_PlayZCombatLogTimer = GetGame().GetTime() + (PlayZAntiCombatLogConfig.Get().CombatLogoutSecs * 1000);
	}

	bool DidWeStartCombatWith(notnull PlayerBase enemy)
	{
		bool weShotFirst = false;
		enemy.m_PlayZShotAtUsFirst.Find(GetCachedID(), weShotFirst);
		return weShotFirst;
	}

	void ResetCombatLogTimer()
	{
		m_PlayZCombatLogTimer = 0;
	}

	float GetCombatLogTimer()
	{
		return m_PlayZCombatLogTimer;
	}

	void InformServerThatWeShotAt(notnull PlayerBase player)
	{
		Param1<int> params = new Param1<int>(player.GetID());
		GetGame().RPCSingleParam(this, PlayZAntiCombatLogRPCs.ANTI_COMBAT_LOG_RPC, params, true);
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == PlayZAntiCombatLogRPCs.ANTI_COMBAT_LOG_MSG_RPC)
		{
			Param2<int, int> antiCombatLog_ClientParams;
			if (!ctx.Read(antiCombatLog_ClientParams))
			{
				return;
			}

			m_PlayZWillBePunishedForCombatLogging = antiCombatLog_ClientParams.param1;
			m_PlayZDisableExitButtonSecs = antiCombatLog_ClientParams.param2;
			return;
		}

		if (rpc_type == PlayZAntiCombatLogRPCs.ANTI_COMBAT_LOG_RPC)
		{
			Param1<int> antiCombatLog_ServerParams;
			if (!ctx.Read(antiCombatLog_ServerParams))
			{
				return;
			}

			int highBits;
			int lowBits;
			GetGame().GetPlayerNetworkIDByIdentityID(sender.GetPlayerId(), lowBits, highBits);
			PlayerBase shooter = PlayerBase.Cast(GetGame().GetObjectByNetworkId(lowBits, highBits));
			PlayerBase victim = PlayZ_GetPlayerById(antiCombatLog_ServerParams.param1);

			if (!victim || !shooter)
			{
				return;
			}

			if (victim == shooter)
			{
				return;
			}

			#ifdef EXPANSIONMODAI
			if (victim.IsAI())
			{
				if (!PlayZAntiCombatLogConfig.Get().TriggerForExpansionAI)
				{
					return;
				}
			}
			#endif

			if (shooter && shooter.IsAlive())
			{
				shooter.SetCombatLogTimer(shooter, victim);
			}

			if (victim && victim.GetIdentity() && victim.IsAlive())
			{
				#ifdef EXPANSIONMODAI
				if (victim.IsAI())
				{
					return;
				}
				#endif

				victim.SetCombatLogTimer(shooter, victim);
			}
		}
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		PlayZ_HandleAntiCombatLog(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
	}

	void PlayZ_HandleAntiCombatLog(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		#ifdef EXPANSIONMODAI
		if (IsAI())
		{
			if (!PlayZAntiCombatLogConfig.Get().TriggerForExpansionAI)
			{
				return;
			}
		}
		#endif

		PlayerBase attacker;
		CarScript vehicle = CarScript.Cast(source);
		if (vehicle)
		{
			attacker = PlayerBase.Cast(vehicle.CrewMember(0));
			if (attacker)
			{
				float speed = 0.0;
				Car car;
				if (Class.CastTo(car, vehicle))
				{
					speed = car.GetSpeedometer();
				}
				else
				{
					speed = GetVelocity(vehicle).Length() * 3.6;
				}

				if (speed > 1 && damageResult && damageResult.GetDamage(dmgZone, "Health") > 1)
				{
					attacker.SetCombatLogTimer(attacker, this);
					return;
				}
			}
		}

		if (!IsAlive() || !source)
		{
			return;
		}

		attacker = PlayerBase.Cast(source.GetHierarchyRootPlayer());
		if (!attacker || attacker == this)
		{
			return;
		}

		attacker.SetCombatLogTimer(attacker, this);
		SetCombatLogTimer(attacker, this);
	}
}
