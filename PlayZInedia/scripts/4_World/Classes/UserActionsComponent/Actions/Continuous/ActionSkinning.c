modded class ActionSkinning
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
#ifndef SERVER
		if (target)
		{
			Object targetObject = target.GetObject();
			if (targetObject && targetObject.IsInherited(ZombieBase))
			{
				ZombieBase zmb = ZombieBase.Cast(targetObject);
				if (zmb && !zmb.IsAlive() && zmb.InediaInfectedAI_GetNetSyncBoolVariable("SearchBodyToViewCargo"))
				{
					if (!zmb.InediaInfectedAI_CanPlayerViewCargo(player))
					{
						return false;
					}
				}
			}
		}
#endif

		return super.ActionCondition(player, target, item);
	}
}
