modded class ActionDrinkThroughContinuous
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (super.ActionCondition(player, target, item))
		{
			m_PlayZMouthBlockedHint = false;
			return true;
		}
		if (!PlayZCoreConfig.GetInstance().BlockEatingWithMouthCover)
		{
			return false;
		}
		PlayZMouthBlocker.SetBypassMouthCheck(true);
		bool wouldPass = super.ActionCondition(player, target, item);
		PlayZMouthBlocker.SetBypassMouthCheck(false);
		if (wouldPass)
		{
			m_PlayZMouthBlockedHint = true;
			return true;
		}
		return false;
	}
}
