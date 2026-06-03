modded class CatchingContextFishingRodAction
{
	//! Source Found: scripts/4_World/Systems/AnimalCatchingSystem/CatchingContexts/CatchingContextFishingRodAction.c:352 (OnAfterSpawnSignalHit)
	override void OnAfterSpawnSignalHit()
	{
		super.OnAfterSpawnSignalHit();

		// Catch path mutates hook/bait/rod; push replication so clients and observers stay aligned.
		if (GetGame().IsServer() && m_Rod)
			m_Rod.SetSynchDirty();

		if (GetGame().IsServer() && m_Player)
			m_Player.SetSynchDirty();
	}

	override protected void RemoveItemSafe(EntityAI item)
	{
		super.RemoveItemSafe(item);

		// PlayZ Fix: Sync rod state after hook/bait deletion to prevent hand desync
		// Without this, client and server disagree on attachment state, causing stuck hands
		if (GetGame().IsServer() && m_Rod)
		{
			m_Rod.SetSynchDirty();
		}
	}

	override float GetHookLossChanceModifierClamped()
	{
		float result = super.GetHookLossChanceModifierClamped();
		
		// PlayZ Override: Use reliabgearmod_plz level-based modifier
		if (m_Player && m_Player.GetTerjeSkills())
		{
			float reliabMod = 0;
			if (m_Player.GetTerjeSkills().GetSkillModifierValue("fish", "reliabgearmod_plz", reliabMod))
			{
				result *= Math.Clamp(1.0 + reliabMod, 0, 1);
			}
		}
		
		return result;
	}
	
	override float GetBaitLossChanceModifierClamped()
	{
		float result = super.GetBaitLossChanceModifierClamped();
		
		// PlayZ Override: Use reliabgearmod_plz level-based modifier
		if (m_Player && m_Player.GetTerjeSkills())
		{
			float reliabMod = 0;
			if (m_Player.GetTerjeSkills().GetSkillModifierValue("fish", "reliabgearmod_plz", reliabMod))
			{
				result *= Math.Clamp(1.0 + reliabMod, 0, 1);
			}
		}
		
		return result;
	}
}
