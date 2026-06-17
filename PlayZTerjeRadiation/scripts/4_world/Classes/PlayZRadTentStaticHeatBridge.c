//! Static rad tents (House) are omitted from fireplace UTS spatial queries (DYNAMIC only).
//! Bridge fireplace heat to tent attachment slots — mirrors UniversalTemperatureSourceLambdaBaseImpl.
class PlayZRadTentStaticHeatBridge
{
	protected static const float FIRE_RANGE_MAX = 10.0;
	protected static const float FIRE_RANGE_FULL = 5.0;
	protected static const float UPDATE_INTERVAL_SEC = 1.0;

	static void ProcessAttachments(TerjeRadTentStatic tent)
	{
		if (!g_Game || !g_Game.IsDedicatedServer() || !tent)
			return;

		GameInventory inv = tent.GetInventory();
		if (!inv || inv.AttachmentCount() == 0)
			return;

		vector tentPos = tent.GetPosition();
		float halfRange = FIRE_RANGE_MAX;
		vector minPos = tentPos - Vector(halfRange, halfRange / 2, halfRange);
		vector maxPos = tentPos + Vector(halfRange, halfRange / 2, halfRange);

		array<EntityAI> nearbyObjects = {};
		DayZPlayerUtils.SceneGetEntitiesInBox(minPos, maxPos, nearbyObjects, QueryFlags.DYNAMIC);

		float tempTarget = GameConstants.ITEM_TEMPERATURE_NEUTRAL_ZONE_MIDDLE;
		float tempCoef = GameConstants.TEMP_COEF_UTS;

		foreach (EntityAI entity : nearbyObjects)
		{
			FireplaceBase fireplace = FireplaceBase.Cast(entity);
			if (!fireplace || !fireplace.IsBurning())
				continue;

			vector firePos = fireplace.GetPosition();
			float distance = vector.Distance(tentPos, firePos);
			if (distance > FIRE_RANGE_MAX)
				continue;

			float distFactor = 1;
			if (distance > FIRE_RANGE_FULL)
			{
				distFactor = Math.InverseLerp(FIRE_RANGE_MAX, FIRE_RANGE_FULL, distance);
				distFactor = Math.Max(distFactor, 0.0);
			}

			TemperatureDataInterpolated dta = new TemperatureDataInterpolated(tempTarget, ETemperatureAccessTypes.ACCESS_UTS, UPDATE_INTERVAL_SEC, tempCoef * distFactor);
			ApplyHeatRecursive(tent, dta);
		}
	}

	protected static void ApplyHeatRecursive(EntityAI ent, TemperatureData dta, float heatPermeabilityCoef = 1.0)
	{
		float heatPermCoef = heatPermeabilityCoef;
		heatPermCoef *= ent.GetHeatPermeabilityCoef();
		dta.m_HeatPermeabilityCoef = heatPermCoef;

		if (ent.CanHaveTemperature() && !ent.IsSelfAdjustingTemperature())
		{
			float temperatureDifference = dta.m_AdjustedTarget - ent.GetTemperature();
			if (Math.AbsFloat(temperatureDifference) >= GameConstants.TEMPERATURE_SENSITIVITY_THRESHOLD || !ent.IsFreezeThawProgressFinished())
				ent.SetTemperatureEx(dta);
			else
				ent.RefreshTemperatureAccess(dta);
		}

		GameInventory inv = ent.GetInventory();
		if (!inv)
			return;

		int inventoryAttCount = inv.AttachmentCount();
		for (int inAttIdx = 0; inAttIdx < inventoryAttCount; ++inAttIdx)
		{
			EntityAI attachmentEnt;
			if (Class.CastTo(attachmentEnt, inv.GetAttachmentFromIndex(inAttIdx)))
				ApplyHeatRecursive(attachmentEnt, dta, heatPermCoef);
		}
	}
}
