modded class ActionFishingNew
{
	override protected EntityAI TrySpawnCatch(FishingActionData action_data)
	{
		// PlayZ Override: Use catchmod_plz modifier instead of catchmod
		if (action_data.m_Player && action_data.m_Player.GetTerjeSkills())
		{
			float modifierValue = 0;
			float catchChance = Math.Clamp(GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_FISHING_OVERRIDE_BASE_CATCH_CHANCE), 0, 1);
			if (action_data.m_Player.GetTerjeSkills().GetSkillModifierValue("fish", "catchmod_plz", modifierValue))
			{
				modifierValue = Math.Clamp(modifierValue, 0, 1);
				catchChance = catchChance + ((1.0 - catchChance) * modifierValue);
			}

			if (catchChance < Math.RandomFloat01())
			{
				return null;
			}
		}

		// Note: We don't call super.TrySpawnCatch because it would re-run the base mod's logic
		// which might fail if 'catchmod' is disabled. We've effectively re-implemented the
		// success check with our own modifier here.

		EntityAI result = super.TrySpawnCatch(action_data);
		if (action_data.m_Player)
		{
			TerjeProcessingSpawnCatch(action_data.m_Player, result);
		}

		return result;
	}

	override void OnEnd(ActionData action_data)
	{
		super.OnEnd(action_data);

		// PlayZ Fix: Force sync rod and player hand state when fishing ends
		// Prevents hands getting stuck in fishing animation after desync
		if (GetGame().IsServer() && action_data.m_MainItem)
		{
			action_data.m_MainItem.SetSynchDirty();

			if (action_data.m_Player)
			{
				action_data.m_Player.SetSynchDirty();
			}
		}
	}

	//! Source Found: scripts/4_World/Classes/UserActionsComponent/ActionBase.c:764 (End), 1290 (OnEndClient)
	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient(action_data);

		// Local client: force rod visual closed + sync request. MP can skip part of the chain so super.OnEnd
		// alone leaves fishing pose / action widget state wrong for the acting player; observers may then see
		// "fishing with nothing" while the fisher's client is stuck until drop/pickup.
		FishingActionData fad;
		if (!Class.CastTo(fad, action_data))
			return;

		if (!action_data.m_Player)
			return;

		PlayerBase localP;
		if (!Class.CastTo(localP, GetGame().GetPlayer()))
			return;

		if (action_data.m_Player != localP)
			return;

		if (!fad.m_MainItem)
			return;

		FishingRod_Base_New rod;
		if (Class.CastTo(rod, fad.m_MainItem))
			rod.AnimateFishingRodEx(0, true);
	}
}
