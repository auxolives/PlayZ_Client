//! tR kits: keep convert/switch-kit actions; replace only deploy/place with PlayZ_ActionDeployTRKit.
//! Website: "Take a kit in hands, then click and hold to switch the kit type"
//! Source Found: scripts/4_World/Entities/ItemBase.c:306 (GetActions)
modded class ItemBase
{
	void PlayZ_RemoveRegisteredAction(typename actionName)
	{
		ActionBase action = ActionManagerBase.GetAction(actionName);
		if (!action || !m_InputActionMap)
			return;

		typename ai = action.GetInputType();
		array<ActionBase_Basic> action_array = m_InputActionMap.Get(ai);
		if (action_array)
			action_array.RemoveItem(action);
	}

	bool PlayZ_IsStrippedDeployAction(ActionBase action, ActionBase ourDeploy)
	{
		if (!action || action == ourDeploy)
			return false;

		// Only strip real place/deploy classes — not tR "switch kit type" continuous actions.
		if (action.IsInherited(ActionDeployObject) || action.IsInherited(ActionPlaceObject))
			return true;

		return false;
	}

	void PlayZ_ReplaceTRKitDeployActions()
	{
		ActionBase ourDeploy = ActionManagerBase.GetAction(PlayZ_ActionDeployTRKit);
		if (!ourDeploy)
			return;

		PlayZ_RemoveRegisteredAction(ActionDeployObject);
		PlayZ_RemoveRegisteredAction(ActionPlaceObject);
		AddAction(PlayZ_ActionDeployTRKit);
	}

	override void GetActions(typename action_input_type, out array<ActionBase_Basic> actions)
	{
		super.GetActions(action_input_type, actions);

		if (!PlayZTRPlacement.IsTRKitItem(this))
			return;

		ActionBase ourDeploy = ActionManagerBase.GetAction(PlayZ_ActionDeployTRKit);
		if (!ourDeploy || !actions)
			return;

		for (int i = actions.Count() - 1; i >= 0; i--)
		{
			ActionBase action = ActionBase.Cast(actions.Get(i));
			if (PlayZ_IsStrippedDeployAction(action, ourDeploy))
				actions.Remove(i);
		}

		if (action_input_type == ourDeploy.GetInputType() && actions.Find(ourDeploy) == -1)
			actions.Insert(ourDeploy);
	}

	override void SetActions()
	{
		super.SetActions();

		if (PlayZTRPlacement.IsTRKitItem(this))
			PlayZ_ReplaceTRKitDeployActions();
	}
}
