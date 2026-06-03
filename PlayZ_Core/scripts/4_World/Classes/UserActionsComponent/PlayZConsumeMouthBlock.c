class PlayZConsumeMouthBlock
{
	static bool ShouldRefuseConsume(PlayerBase mouthOwner)
	{
		if (!PlayZCoreConfig.GetInstance().BlockEatingWithMouthCover)
		{
			return false;
		}
		if (!mouthOwner)
		{
			return false;
		}
		return PlayZMouthBlocker.IsMouthCovered(mouthOwner);
	}
}
