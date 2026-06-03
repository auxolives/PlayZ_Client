modded class AimingModelFilterBreathing
{
	override float calculateWeight(int stanceIndex)
	{
		float w = super.calculateWeight(stanceIndex);
		if (getWeapon().IsBipodDeployed() && getWeapon().Bipod().IsBipodInUse())
		{
			return 0.05;
		}
		return w;
	}
}
