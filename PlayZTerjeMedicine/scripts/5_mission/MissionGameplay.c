modded class MissionGameplay
{
	override void OnInit()
	{
		super.OnInit();
		DayZGame.Event_OnRPC.Insert(OnPlayZOverdoseRPC);
	}

	void ~MissionGameplay()
	{
		if (DayZGame.Event_OnRPC)
		{
			DayZGame.Event_OnRPC.Remove(OnPlayZOverdoseRPC);
		}
	}

	void OnPlayZOverdoseRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if (rpc_type == PlayZOverdoseRPCs.SYNC_OVERDOSE_CONFIG)
		{
			PlayZOverdoseConfig.OnRPC(ctx);
		}
	}

	override void OnUpdateTerjeCustomBadges(PlayerBase player, bool detailedDiseaseHudBadges, bool detailedHealingHudBadges)
	{
		super.OnUpdateTerjeCustomBadges(player, detailedDiseaseHudBadges, detailedHealingHudBadges);
	}

	override void OnUpdateTerjeCustomGUI(PlayerBase player, float deltaTime)
	{
		super.OnUpdateTerjeCustomGUI(player, deltaTime);

		float mod = GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_OVERDOSE_VISUAL_EFFECTS);
		float raw = 0;
		if (PlayZOverdoseConfig.GetInstance().m_EnableOverdosePPE)
		{
			if (PlayZMissionClientGate.IsPPEReady(player))
			{
				raw = player.PlayZGetOverdoseValueForPPE();
			}
		}

		PPERequester_TerjeMedOverdose req = PPERequester_TerjeMedOverdose.Cast(PPERequesterBank.GetRequester(PPERequesterBank.REQ_TERJEMED_OVERDOSE));
		if (req)
		{
			req.SetPlayZOverdoseValue(raw, mod);
		}
	}
}
