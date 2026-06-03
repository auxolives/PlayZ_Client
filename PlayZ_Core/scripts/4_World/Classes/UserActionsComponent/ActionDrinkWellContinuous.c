modded class ActionDrinkWellContinuous
{
	protected bool m_PlayZMouthBlockedHint = false;

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

	override string GetText()
	{
		if (m_PlayZMouthBlockedHint)
		{
			return "#STR_PlayZ_MouthBlocked";
		}
		return super.GetText();
	}

	override bool Post_SetupAction(ActionData action_data)
	{
		if (PlayZConsumeMouthBlock.ShouldRefuseConsume(action_data.m_Player))
		{
			return false;
		}
		return super.Post_SetupAction(action_data);
	}
}
