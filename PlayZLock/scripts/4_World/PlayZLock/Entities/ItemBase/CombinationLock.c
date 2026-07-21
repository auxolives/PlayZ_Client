modded class CombinationLock
{
	ref PlayZLockGUI m_PlayZLockGUI;
	protected bool m_RequestedPerms;
	protected bool m_ReceivedPerms;
	protected bool m_HasClientPermission;
	protected bool m_IsManagingLockClient;
	protected int m_LastSimulatedDialChanges;

	void CombinationLock()
	{
		m_RequestedPerms = false;
		m_ReceivedPerms = false;
		m_HasClientPermission = false;
		m_IsManagingLockClient = false;
		m_LastSimulatedDialChanges = -1;
	}

	void ~CombinationLock()
	{
		if (m_PlayZLockGUI)
			delete m_PlayZLockGUI;
	}

	override void EOnInit(IEntity other, int extra)
	{
		super.EOnInit(other, extra);

		if (g_Game.IsDedicatedServer())
			g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckLockRestart, 5000, false);
	}

	bool IsManagingLockClient()
	{
		if (g_Game.IsDedicatedServer())
			return false;

		return m_IsManagingLockClient;
	}

	void SetManagingLockClient(bool b)
	{
		m_IsManagingLockClient = b;
	}

	void RequestCombolockPerms()
	{
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());

		if (!player || player.GetSimulationTimeStamp() < 300)
		{
			g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(RequestCombolockPerms);
			g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(RequestCombolockPerms, 300, false);
			return;
		}

		if (!m_ReceivedPerms)
		{
			Print("[PlayZLock] Sending request for combination lock permissions @ " + player.GetSimulationTimeStamp() + " timestamp.");

			Param1<bool> params = new Param1<bool>(true);
			RPCSingleParam(PlayZLockRPCs.REQUEST_COMBO_DATA, params, true, NULL);
		}
	}

	void DisplayDigitText(string prefix = "")
	{
		if (!m_PlayZLockGUI)
			m_PlayZLockGUI = new PlayZLockGUI;

		PlayZLockClientConfig clientCfg = PlayZLockConfig.Get().ClientSyncConfig;
		if (!clientCfg)
			return;

		if (clientCfg.DisplayDigits == 1)
		{
			m_PlayZLockGUI.SetText(prefix + GetDialNumberText(false).Get(m_DialIndex));
		}
		else
		if (clientCfg.DisplayDigits == 2)
		{
			m_PlayZLockGUI.SetText(prefix + GetDialNumberText(true));
		}
	}

	string GetDialNumberText(bool formatDigits)
	{
		string dial_text = "";
		string combination_text = GetCombination().ToString();

		int length_diff = GetLockDigits() - combination_text.Length();
		for (int i = 0; i < length_diff; ++i)
		{
			combination_text = "0" + combination_text;
		}

		for (int j = 0; j < GetLockDigits(); ++j)
		{
			if (!formatDigits)
			{
				dial_text += string.Format("%1", combination_text.Get(j));
			}
			else
			{
				if (j == GetDialIndex())
				{
					dial_text += string.Format("[%1]", combination_text.Get(j));
				}
				else
				{
					dial_text += string.Format(" %1 ", combination_text.Get(j));
				}
			}
		}

		return dial_text;
	}

	protected ref ComboLockData m_ComboLockData = NULL;
	protected int m_SimulatedDialChanges = 0;

	void CheckLockRestart()
	{
		if (GetHierarchyParent() && GetHierarchyParent().IsInherited(BaseBuildingBase))
		{
			LockServer(GetHierarchyParent(), true);
		}
	}

	void LockTheLockToTheGate()
	{
		if (GetHierarchyParent() && (GetHierarchyParent().IsInherited(BaseBuildingBase) || GetHierarchyParent().IsKindOf("BBP_WALL_BASE")))
		{
			InventoryLocation inventory_location = new InventoryLocation;
			GetInventory().GetCurrentInventoryLocation(inventory_location);
			GetHierarchyParent().GetInventory().SetSlotLock(inventory_location.GetSlot(), true);
			m_LockActionPerformed = LockAction.LOCKED;
			SetTakeable(false);
			Synchronize();
		}
	}

	void UnlockTheLockFromTheGate()
	{
		if (GetHierarchyParent() && (GetHierarchyParent().IsInherited(BaseBuildingBase) || GetHierarchyParent().IsKindOf("BBP_WALL_BASE")))
		{
			InventoryLocation inventory_location = new InventoryLocation;
			GetInventory().GetCurrentInventoryLocation(inventory_location);
			GetHierarchyParent().GetInventory().SetSlotLock(inventory_location.GetSlot(), false);
			m_LockActionPerformed = LockAction.UNLOCKED;
			SetTakeable(true);
			Synchronize();
		}
	}

	void ResetSimulatedDialChanges()
	{
		m_SimulatedDialChanges = 0;
	}

	void IncreaseSimulatedDialChanges()
	{
		m_SimulatedDialChanges = m_SimulatedDialChanges + 1;

		int digitMult = 1;
		if (PlayZLockConfig.Get().ServerConfig)
			digitMult = PlayZLockConfig.Get().ServerConfig.DigitMultiplier;

		if (m_SimulatedDialChanges % ((GetLockDigits() * digitMult) / 2) == 0)
			m_LockActionPerformed = LockAction.DIAL_NUMBER_CHANED;
		else
			m_LockActionPerformed = LockAction.DIAL_INDEX_CHANGED;

		Synchronize();
	}

	int GetSimulatedDialChangeCount()
	{
		return m_SimulatedDialChanges;
	}

	ComboLockData GetComboLockData()
	{
		return m_ComboLockData;
	}

	void TriggerPlayZLockSync()
	{
		if (g_Game.IsDedicatedServer())
		{
			m_ServerSyncID++;
			SetSynchDirty();
		}
	}

	bool SetOwnerPermission(string id)
	{
		if (!m_ComboLockData)
		{
			m_ComboLockData = new ComboLockData();
		}

		PlayZLockLogger.Log("Assigned new OWNER to combination lock: " + id + " - " + GetType() + " / digits=" + GetLockDigits() + " / loc=" + GetPosition());
		m_ComboLockData.m_PlayerOwner = id;
		TriggerPlayZLockSync();

		return true;
	}

	bool AddGuestPermission(string id)
	{
		if (!m_ComboLockData)
		{
			m_ComboLockData = new ComboLockData();
		}

		if (m_ComboLockData.m_PlayerOwner != id)
		{
			foreach (string s : m_ComboLockData.m_PermittedPlayers)
			{
				if (s == id)
				{
					return false;
				}
			}
		}

		PlayZLockLogger.Log("Assigned new GUEST to combination lock: " + id + " - " + GetType() + " / digits=" + GetLockDigits() + " / loc=" + GetPosition());
		m_ComboLockData.m_PermittedPlayers.Insert(id);
		TriggerPlayZLockSync();

		return true;
	}

	void ResetPlayerPermissions()
	{
		if (!m_ComboLockData)
		{
			m_ComboLockData = new ComboLockData();
		}

		m_ComboLockData.m_PlayerOwner = "";
		m_ComboLockData.m_PermittedPlayers.Clear();
		TriggerPlayZLockSync();
	}

	int m_ClientSyncID = -1;
	int m_ServerSyncID = 0;

	override void InitItemVariables()
	{
		super.InitItemVariables();

		RegisterNetSyncVariableInt("m_ServerSyncID");
		RegisterNetSyncVariableInt("m_SimulatedDialChanges");
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if (m_ClientSyncID != m_ServerSyncID)
		{
			RequestCombolockPerms();
			m_ClientSyncID = m_ServerSyncID;
			m_RequestedPerms = false;
			m_ReceivedPerms = false;
		}

		if (!m_ReceivedPerms)
		{
			RequestCombolockPerms();
		}

		if (m_SimulatedDialChanges != m_LastSimulatedDialChanges)
		{
			m_LastSimulatedDialChanges = m_SimulatedDialChanges;
			UpdateSound();
		}
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == PlayZLockRPCs.RECEIVE_COMBO_DATA)
		{
			Param1<bool> client_params = new Param1<bool>(m_HasClientPermission);
			if (ctx.Read(client_params))
			{
				m_HasClientPermission = client_params.param1;
				m_ReceivedPerms = true;
			}

			return;
		}

		if (rpc_type == PlayZLockRPCs.REQUEST_COMBO_DATA)
		{
			if (!sender)
				return;

			Param1<bool> server_params = new Param1<bool>(false);
			if (ctx.Read(server_params))
			{
				if (server_params.param1)
				{
					if (!m_ComboLockData)
					{
						m_ComboLockData = new ComboLockData;
					}

					PlayerBase player = PlayerBase.Cast(sender.GetPlayer());

					if (!player)
					{
						Error("[PlayZLock] PLAYER NETWORK OBJECT NOT FOUND for combo lock permission sync");
						return;
					}

					Print("[PlayZLock] Sending requested combo lock permissions for lock @ " + GetPosition() + " to " + player.GetIdentity().GetId());

					SyncComboLockPermissions(player);
				}
			}

			return;
		}
	}

	bool HasReceivedClientsidePerms()
	{
		if (g_Game.IsDedicatedServer())
			return true;

		if (m_ReceivedPerms)
			return true;

		if (!m_RequestedPerms)
		{
			m_RequestedPerms = true;
			RequestCombolockPerms();
		}

		return false;
	}

	void SyncComboLockPermissions(notnull PlayerBase player)
	{
		if (!player.GetIdentity())
			return;

		bool hasPerms = IsPermittedToOpen(player);

		Param1<bool> data = new Param1<bool>(hasPerms);
		RPCSingleParam(PlayZLockRPCs.RECEIVE_COMBO_DATA, data, true, player.GetIdentity());
	}

	bool IsPermittedToOpen(PlayerBase player = NULL)
	{
		// Client UI only — never trust this on the server.
		if (g_Game.IsClient())
		{
			return m_HasClientPermission;
		}

		if (!player)
			return false;

		PlayerIdentity playerID = player.GetIdentity();

		if (!playerID)
			return false;

		string id = playerID.GetPlainId();

		PlayZLockConfig cfg = PlayZLockConfig.Get();
		if (cfg.ClientSyncConfig && cfg.ClientSyncConfig.AllowAdminOpen)
		{
			if (cfg.IsAdmin(playerID))
				return true;
		}

		if (!m_ComboLockData)
		{
			m_ComboLockData = new ComboLockData();
			return false;
		}

		if (m_ComboLockData.m_PlayerOwner == "")
			return false;

		if (m_ComboLockData.m_PlayerOwner == id)
			return true;

		foreach (string guestID : m_ComboLockData.m_PermittedPlayers)
		{
			if (guestID == id)
				return true;
		}

		return false;
	}

	// Combination digits match locked code (raw m_IsLocked, ignores IsTakeable).
	bool IsCombinationMatched()
	{
		return !m_IsLocked;
	}

	// Server-only: AdminIDs list, not the client NetSync flag.
	bool IsServerLockAdmin(PlayerBase player)
	{
		if (!player || !player.GetIdentity())
			return false;

		PlayZLockConfig cfg = PlayZLockConfig.Get();
		if (!cfg || !cfg.ClientSyncConfig || !cfg.ClientSyncConfig.AllowAdminOpen)
			return false;

		return cfg.IsAdmin(player.GetIdentity());
	}

	override void LockServer(EntityAI parent, bool ignore_combination = false)
	{
		super.LockServer(parent, ignore_combination);

		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(LockTheLockToTheGate);
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(LockTheLockToTheGate, 100, false);
	}

	override bool IsLocked()
	{
		if (IsTakeable())
			return false;

		return super.IsLocked();
	}

	override bool IsLockedOnGate()
	{
		if (IsTakeable())
			return false;

		return super.IsLockedOnGate();
	}

	override void UnlockServer(EntityAI player, EntityAI parent)
	{
		EntityAI hparent = GetHierarchyParent();
		if (hparent != NULL)
		{
			if (GetHierarchyParent().IsKindOf("BBP_WALL_BASE"))
			{
				UnlockServerPlayZ(player, parent);
				return;
			}
		}

		super.UnlockServer(player, parent);
	}

	void UnlockServerPlayZ(EntityAI player, EntityAI parent)
	{
		PlayerBase pb = PlayerBase.Cast(player);
		bool permitted = false;
		if (pb)
			permitted = IsPermittedToOpen(pb);

		// m_IsLocked is combination-matched state (not IsTakeable override).
		bool codeMatched = !m_IsLocked;

		// Stranger with no ownership and no correct code must never unlock.
		if (!permitted && !codeMatched)
		{
			if (pb && pb.GetIdentity())
				PlayZLockLogger.Log("Rejected unlock — no ownership/code match by " + pb.GetIdentity().GetPlainId() + " @ " + GetPosition());
			return;
		}

		if (IsLockAttached() && parent)
		{
			// Grant owner/guest only after a successful code dial (not from forced unlock RPCs).
			if (pb && pb.GetIdentity() && !permitted && codeMatched)
			{
				if (!m_ComboLockData)
				{
					m_ComboLockData = new ComboLockData;
				}

				if (m_ComboLockData.m_PlayerOwner == "")
				{
					SetOwnerPermission(pb.GetIdentity().GetPlainId());
				}
				else
				{
					AddGuestPermission(pb.GetIdentity().GetPlainId());
				}

				TriggerPlayZLockSync();
			}

			Synchronize();
		}

		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(UnlockTheLockFromTheGate);
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(UnlockTheLockFromTheGate, 100, false);
	}

	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
	{
		if (!old_owner || !old_owner.IsInherited(PlayerBase))
			return;

		if (g_Game.IsDedicatedServer())
		{
			if (IsInitialized() && new_owner && (new_owner.IsInherited(BaseBuildingBase) || new_owner.IsKindOf("BBP_WALL_BASE")))
			{
				LockServer(new_owner);

				PlayerBase player = PlayerBase.Cast(old_owner);
				if (player && player.GetIdentity())
				{
					SetOwnerPermission(player.GetIdentity().GetPlainId());

					m_ComboLockData.m_PermittedPlayers.Clear();
					TriggerPlayZLockSync();
					Synchronize();
				}
			}
		}
		else
		{
			m_IsManagingLockClient = false;
		}
	}

	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage["PlayZLock"];
		if (!ctx) return;

		if (!m_ComboLockData)
			m_ComboLockData = new ComboLockData();

		int playerCount = m_ComboLockData.m_PermittedPlayers.Count();

		ctx.Write(playerCount);
		for (int i = 0; i < playerCount; i++)
		{
			ctx.Write(m_ComboLockData.m_PermittedPlayers.Get(i));
		}

		ctx.Write(m_ComboLockData.m_PlayerOwner);
	}

	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage)) return false;

		auto ctx = storage["PlayZLock"];
		if (!ctx) return true;

		if (ctx.GetVersion() >= 1)
		{
			m_ComboLockData = new ComboLockData();

			int playerCount;

			if (!ctx.Read(playerCount)) return false;

			for (int i = 0; i < playerCount; i++)
			{
				string loadID;
				if (!ctx.Read(loadID))
					return false;

				m_ComboLockData.m_PermittedPlayers.Insert(loadID);
			}

			string ownerID;
			if (!ctx.Read(ownerID))
				return false;

			m_ComboLockData.m_PlayerOwner = ownerID;
		}

		return true;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(PlayZ_ActionNextCombinationLockDialOnTarget);
		AddAction(PlayZ_ActionDialCombinationLockOnTarget);

		AddAction(PlayZ_ActionOpenComboLock);
		AddAction(PlayZ_ActionOpenComboLockInstant);
		AddAction(PlayZ_ActionManageCombinationLockOnTarget);
		AddAction(PlayZ_ActionAdminCombinationLockOnTarget);
	}
}
