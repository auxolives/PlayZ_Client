// Client-side suspicious keybind reporter (cheat-menu hotkeys).
// Compacts presses into one RPC at most once per second to limit flood abuse.

class PlayZACKeybindInput
{
	string InputName;
	ref array<int> KeyCodes;
	protected bool m_HoldingPrimary;
	protected bool m_HoldingSecondary;

	void PlayZACKeybindInput(string inputName, array<int> keyCodes)
	{
		InputName = inputName;
		KeyCodes = keyCodes;
	}

	int GetHoldButton()
	{
		return KeyCodes[0];
	}

	bool OnPress(int key)
	{
		if (KeyCodes.Count() >= 3)
		{
			if (key == KeyCodes[0])
			{
				HoldPrimaryStart();
				return false;
			}

			if (key == KeyCodes[1])
			{
				HoldSecondaryStart();
				return false;
			}

			return IsPrimaryHeld() && IsSecondaryHeld() && key == KeyCodes[2];
		}

		if (NeedHold())
		{
			if (key == GetHoldButton())
			{
				HoldPrimaryStart();
				return false;
			}

			return IsPrimaryHeld() && key == KeyCodes[1];
		}

		return key == KeyCodes[0];
	}

	void OnRelease(int key)
	{
		if (KeyCodes.Count() >= 3)
		{
			if (key == KeyCodes[0])
				HoldPrimaryEnd();
			if (key == KeyCodes[1])
				HoldSecondaryEnd();
			return;
		}

		if (NeedHold() && key == GetHoldButton())
			HoldPrimaryEnd();
	}

	void HoldPrimaryStart()
	{
		m_HoldingPrimary = true;
	}

	void HoldPrimaryEnd()
	{
		m_HoldingPrimary = false;
	}

	void HoldSecondaryStart()
	{
		m_HoldingSecondary = true;
	}

	void HoldSecondaryEnd()
	{
		m_HoldingSecondary = false;
	}

	bool IsPrimaryHeld()
	{
		return m_HoldingPrimary;
	}

	bool IsSecondaryHeld()
	{
		return m_HoldingSecondary;
	}

	bool NeedHold()
	{
		return KeyCodes.Count() == 2;
	}
}

class PlayZACKeybindHandler
{
	protected ref array<ref PlayZACKeybindInput> m_Inputs;
	protected ref map<int, int> m_PendingInputs;
	protected ref Timer m_FlushTimer;
	protected float m_LastRpcSendTime;

	void PlayZACKeybindHandler()
	{
		m_Inputs = new array<ref PlayZACKeybindInput>();
		m_PendingInputs = new map<int, int>();
		m_FlushTimer = new Timer();
		m_LastRpcSendTime = 0;
		RegisterDefaults();
	}

	protected void RegisterInput(PlayZACKeybindInput input)
	{
		m_Inputs.Insert(input);
	}

	protected void RegisterCombo(string label, int modifierKey, int key)
	{
		RegisterInput(new PlayZACKeybindInput(label, {modifierKey, key}));
	}

	protected void RegisterTripleCombo(string label, int modifierKey1, int modifierKey2, int key)
	{
		RegisterInput(new PlayZACKeybindInput(label, {modifierKey1, modifierKey2, key}));
	}

	protected void RegisterFunctionKeyWithCombos(string label, int key)
	{
		RegisterInput(new PlayZACKeybindInput(label, {key}));
		RegisterCombo("Shift + " + label, KeyCode.KC_LSHIFT, key);
		RegisterCombo("Alt + " + label, KeyCode.KC_LMENU, key);
		RegisterCombo("Ctrl + " + label, KeyCode.KC_LCONTROL, key);
		RegisterCombo("Right Ctrl + " + label, KeyCode.KC_RCONTROL, key);
		RegisterCombo("Right Alt + " + label, KeyCode.KC_RMENU, key);
		RegisterTripleCombo("Ctrl + Shift + " + label, KeyCode.KC_LCONTROL, KeyCode.KC_LSHIFT, key);
	}

	protected void RegisterDefaults()
	{
		RegisterInput(new PlayZACKeybindInput("INSERT", {KeyCode.KC_INSERT}));
		RegisterInput(new PlayZACKeybindInput("HOME", {KeyCode.KC_HOME}));
		RegisterInput(new PlayZACKeybindInput("END", {KeyCode.KC_END}));
		RegisterInput(new PlayZACKeybindInput("DELETE", {KeyCode.KC_DELETE}));
		RegisterCombo("Ctrl + INSERT", KeyCode.KC_LCONTROL, KeyCode.KC_INSERT);
		RegisterCombo("Ctrl + HOME", KeyCode.KC_LCONTROL, KeyCode.KC_HOME);

		RegisterInput(new PlayZACKeybindInput("PAGE UP", {KeyCode.KC_PRIOR}));
		RegisterInput(new PlayZACKeybindInput("PAGE DOWN", {KeyCode.KC_NEXT}));
		RegisterInput(new PlayZACKeybindInput("PAUSE", {KeyCode.KC_PAUSE}));
		RegisterInput(new PlayZACKeybindInput("SCROLL LOCK", {KeyCode.KC_SCROLL}));
		RegisterInput(new PlayZACKeybindInput("PRINT SCREEN", {KeyCode.KC_SYSRQ}));

		RegisterInput(new PlayZACKeybindInput("BACKSLASH", {KeyCode.KC_BACKSLASH}));
		RegisterInput(new PlayZACKeybindInput("LBRACKET", {KeyCode.KC_LBRACKET}));
		RegisterInput(new PlayZACKeybindInput("RBRACKET", {KeyCode.KC_RBRACKET}));

		RegisterInput(new PlayZACKeybindInput("NUMPAD 0", {KeyCode.KC_NUMPAD0}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD 1", {KeyCode.KC_NUMPAD1}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD 2", {KeyCode.KC_NUMPAD2}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD 3", {KeyCode.KC_NUMPAD3}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD 4", {KeyCode.KC_NUMPAD4}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD 5", {KeyCode.KC_NUMPAD5}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD 6", {KeyCode.KC_NUMPAD6}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD 7", {KeyCode.KC_NUMPAD7}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD 8", {KeyCode.KC_NUMPAD8}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD 9", {KeyCode.KC_NUMPAD9}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD ENTER", {KeyCode.KC_NUMPADENTER}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD +", {KeyCode.KC_ADD}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD -", {KeyCode.KC_SUBTRACT}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD *", {KeyCode.KC_MULTIPLY}));
		RegisterInput(new PlayZACKeybindInput("NUMPAD /", {KeyCode.KC_DIVIDE}));

		RegisterFunctionKeyWithCombos("F2", KeyCode.KC_F2);
		RegisterFunctionKeyWithCombos("F3", KeyCode.KC_F3);
		RegisterFunctionKeyWithCombos("F4", KeyCode.KC_F4);
		RegisterFunctionKeyWithCombos("F5", KeyCode.KC_F5);
		RegisterFunctionKeyWithCombos("F6", KeyCode.KC_F6);
		RegisterFunctionKeyWithCombos("F7", KeyCode.KC_F7);
		RegisterFunctionKeyWithCombos("F8", KeyCode.KC_F8);
		RegisterFunctionKeyWithCombos("F9", KeyCode.KC_F9);
		RegisterFunctionKeyWithCombos("F10", KeyCode.KC_F10);
		RegisterFunctionKeyWithCombos("F11", KeyCode.KC_F11);
		RegisterFunctionKeyWithCombos("F12", KeyCode.KC_F12);

		RegisterCombo("Right Shift + F12", KeyCode.KC_RSHIFT, KeyCode.KC_F12);
	}

	void OnKeyPress(int key)
	{
		for (int i = 0; i < m_Inputs.Count(); i++)
		{
			PlayZACKeybindInput input = m_Inputs[i];
			if (input.OnPress(key))
			{
				int count = 0;
				if (m_PendingInputs.Contains(i))
					count = m_PendingInputs.Get(i);

				count++;
				if (count > PLAYZ_AC_KEYBIND_MAX_COUNT_DISPLAY)
					count = PLAYZ_AC_KEYBIND_MAX_COUNT_DISPLAY;

				m_PendingInputs.Set(i, count);
				EnsureFlushTimer();
			}
		}
	}

	void OnKeyRelease(int key)
	{
		for (int i = 0; i < m_Inputs.Count(); i++)
			m_Inputs[i].OnRelease(key);
	}

	protected void EnsureFlushTimer()
	{
		if (m_FlushTimer.IsRunning())
			return;

		m_FlushTimer.Run(PLAYZ_AC_KEYBIND_FLUSH_SECONDS, this, "OnFlushTick", null, true);
	}

	protected void OnFlushTick()
	{
		if (m_PendingInputs.Count() == 0)
		{
			m_FlushTimer.Stop();
			return;
		}

		float now = GetGame().GetTime();
		int minIntervalMs = PLAYZ_AC_KEYBIND_FLUSH_SECONDS * 1000;
		if (m_LastRpcSendTime > 0 && now - m_LastRpcSendTime < minIntervalMs)
			return;

		string message = BuildCompactMessage();
		if (message == "")
			return;

		m_PendingInputs.Clear();
		SendRpc(message);
		m_LastRpcSendTime = now;
	}

	protected string BuildCompactMessage()
	{
		string message;

		foreach (int inputIndex, int count : m_PendingInputs)
		{
			string countLabel = count.ToString();
			if (count >= PLAYZ_AC_KEYBIND_MAX_COUNT_DISPLAY)
				countLabel = countLabel + "+";

			message += string.Format("%1_(%2) ", m_Inputs[inputIndex].InputName, countLabel);

			if (message.Length() >= PLAYZ_AC_KEYBIND_MAX_PAYLOAD_CHARS)
				break;
		}

		message.Trim();
		return message;
	}

	protected void SendRpc(string message)
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player)
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(message);
		rpc.Send(player, RPC_PLAYZ_AC_KEYBIND_REPORT, true, null);
	}
}

modded class MissionGameplay
{
	protected ref PlayZACKeybindHandler m_PlayZACKeybindHandler;

	override void OnInit()
	{
		super.OnInit();
		m_PlayZACKeybindHandler = new PlayZACKeybindHandler();
	}

	override void OnKeyPress(int key)
	{
		super.OnKeyPress(key);

		if (m_PlayZACKeybindHandler)
			m_PlayZACKeybindHandler.OnKeyPress(key);
	}

	override void OnKeyRelease(int key)
	{
		super.OnKeyRelease(key);

		if (m_PlayZACKeybindHandler)
			m_PlayZACKeybindHandler.OnKeyRelease(key);
	}
}
