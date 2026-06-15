modded class Weapon_Base
{
	override bool JamCheck(int muzzleIndex)
	{
		return false;
	}

	override float GetChanceToJam()
	{
		return 0.0;
	}

	override void SetJammed(bool value)
	{
		if (value)
		{
			return;
		}

		super.SetJammed(value);
	}

	override void AfterStoreLoad()
	{
		super.AfterStoreLoad();

		if (m_isJammed)
		{
			super.SetJammed(false);
		}

		if (GetGame().IsServer())
		{
			ValidateAndRepair();
		}
	}
}
