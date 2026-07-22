//! Base clearance for pitched tents (Medium/Large/Party/Car + colour variants via IsKindOf).
modded class TentBase
{
	override void EEInit()
	{
		super.EEInit();

		if (g_Game.IsServer() && GetState() == TentBase.PITCHED)
			PlayZBaseClearanceManager.Get().OnBaseInit(this);
	}

	override void EEDelete(EntityAI parent)
	{
		if (g_Game.IsServer())
			PlayZBaseClearanceManager.Get().OnBaseDeleted(this);

		super.EEDelete(parent);
	}

	override void Pitch(bool update_navmesh, bool init = false)
	{
		super.Pitch(update_navmesh, init);

		//! Live pitch only — restart load uses EEInit when already pitched.
		if (g_Game.IsServer() && !init)
			PlayZBaseClearanceManager.Get().OnBaseInit(this);
	}

	override void Pack(bool update_navmesh, bool init = false)
	{
		if (g_Game.IsServer() && !init)
			PlayZBaseClearanceManager.Get().OnBaseDeleted(this);

		super.Pack(update_navmesh, init);
	}
}