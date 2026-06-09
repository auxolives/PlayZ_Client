// Expansion chat sender name: Terje identity instead of vanilla identity name.
// Source Found: DayZExpansion/Chat/.../ExpansionGlobalChatModule.c:81-159
// Full-method override required: no smaller seam than AddChatMessage_Server.

modded class ExpansionGlobalChatModule
{
	override void AddChatMessage_Server(PlayerIdentity sender, Object target, ParamsReadContext ctx, ExpansionChatMessageEventParams data)
	{
		PlayerBase player = PlayerBase.Cast(sender.GetPlayer());

		string terjeName = PlayZExpansionTerjeName.Resolve(player);
		if (terjeName != string.Empty)
		{
			data.param2 = terjeName;
		}
		else
		{
			data.param2 = sender.GetName();
		}

		string originalText = data.param3;
		RemoveSensitiveInfo(data.param3);
		FilterBlacklistedWords(data.param3);
		data.param5 = sender.GetId();

	#ifdef EXPANSIONMODGROUPS
		ExpansionPartyData party = player.Expansion_GetParty();

		if (party && GetExpansionSettings().GetParty().DisplayPartyTag)
		{
			data.param6 = party.GetPartyTagFormatted();
		}
	#endif

		auto rpc = Expansion_CreateRPC("RPC_AddChatMessage");
		rpc.Write(data);

		switch (data.param1)
		{
			case ExpansionChatChannels.CCTransport:
				auto vehicle = ExpansionVehicle.Get(player, false, true);
				if (vehicle)
				{
					set<Human> crew = vehicle.GetCrew(true, true);
					foreach (Human crewMember: crew)
					{
						rpc.Expansion_Send(vehicle.GetEntity(), true, crewMember.GetIdentity());
					}
				}

				break;

		#ifdef EXPANSIONMODGROUPS
			case ExpansionChatChannels.CCTeam:
				if (party)
				{
					rpc.Write(party.GetPartyID());

					array<ref ExpansionPartyPlayerData> players = party.GetPlayers();
					foreach (ExpansionPartyPlayerData partyMember: players)
					{
						PlayerBase partyPlayer = partyMember.Player;
						if (partyPlayer && partyPlayer.GetIdentity())
						{
							rpc.Expansion_Send(true, partyPlayer.GetIdentity());
						}
					}
				}

				break;
		#endif

			case ExpansionChatChannels.CCDirect:
				float range = GetVoiceRange(player);
				player.Expansion_SendNear(rpc, player.GetPosition(), range, null, true);
				break;

			default:
				rpc.Expansion_Send(true);
				break;
		}

		g_Game.GetMission().OnEvent(ChatMessageEventTypeID, data);

		if (GetExpansionSettings().GetLog().Chat)
		{
			string channelName = GetChannelName(data.param1);

			GetExpansionSettings().GetLog().PrintLog("[Chat - " + channelName + "](\"" + data.param2 + "\"(id=" + data.param5 + ")): " + originalText);
			g_Game.AdminLog("[Chat - " + channelName + "](\"" + data.param2 + "\"(id=" + data.param5 + ")): " + originalText);
		}
	}
}
