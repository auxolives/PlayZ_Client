//! Non-interactive road flare marking a combat-log position.
class PlayZ_CombatLogFlare extends Roadflare
{
	override void EEInit()
	{
		super.EEInit();
		SetLifetime(PlayZAntiCombatLogConfig.Get().CombatLogoutSecs);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(IgniteCombatFlare, 1000, false);
	}

	private void IgniteCombatFlare()
	{
		if (GetCompEM())
		{
			GetCompEM().SwitchOn();
		}

		SetModelState(RoadflareModelStates.UNCAPPED_UNIGNITED);
		HideSelection(STANDS_FOLDED);
		ShowSelection(STANDS_UNFOLDED);

		vector ori_rotate = GetOrientation();
		ori_rotate = ori_rotate + Vector(180, 32, 0);
		SetOrientation(ori_rotate);
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
}
