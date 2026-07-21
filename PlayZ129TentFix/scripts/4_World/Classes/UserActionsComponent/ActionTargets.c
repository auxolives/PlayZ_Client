// DayZ 1.29 ActionTargets drops tent proxies:
//  - hierLevel>0 hits with GetID()<1 are skipped
//  - TransformToVicinityObjects requires non-empty GetType()
// Entrance / window / pack proxies are NOID + empty type, so open/close/pack never appear.
// TentBase-scoped: keep those proxies and StoreVicinityObject with parent (no second raycast).
// Remove when Bohemia restores tent proxy targeting.

modded class ActionTargets
{
	override void Update()
	{
		m_VicinityObjects.ClearVicinityObjects();
		Clear();

		Object firstValidRaycastedObject = null;
		array<Object> vicinityObjects = new array<Object>;

		vector playerPos = m_Player.GetPosition();
		vector headingDirection = MiscGameplayFunctions.GetHeadingVector(m_Player);

		m_RayStart = g_Game.GetCurrentCameraPosition();
		m_RayEnd = m_RayStart + g_Game.GetCurrentCameraDirection() * c_RayDistance;

		RaycastRVParams rayInput = new RaycastRVParams(m_RayStart, m_RayEnd, m_Player);
		rayInput.flags = CollisionFlags.ALLOBJECTS;
		array<ref RaycastRVResult> results = new array<ref RaycastRVResult>();
		array<RaycastRVResult> sortedValidRaycastResults = new array<RaycastRVResult>();
		map<Object, RaycastRVResult> resultMap = new map<Object, RaycastRVResult>();

		if (DayZPhysics.RaycastRVProxy(rayInput, results))
		{
			array<int> sortedDistanceHelper = SortResultsDistance(results);
			int sortedResultsCount = m_SortedResults.Count();
			if (sortedResultsCount > 0)
			{
				foreach (int sortedDist : sortedDistanceHelper)
				{
					array<RaycastRVResult> sameDistResults = m_SortedResults.Get(sortedDist);

					foreach (RaycastRVResult res : sameDistResults)
					{
						if (res.obj && !res.obj.CanBeActionTarget())
							continue;

						if (res.hierLevel > 0)
						{
							bool isTentProxy = res.parent && res.parent.IsInherited(TentBase);
							if (res.parent.IsMan() || (res.obj.GetID() < 1 && !isTentProxy))
								continue;

							if (isTentProxy)
								m_VicinityObjects.StoreVicinityObject(res.obj, res.parent);
						}

						sortedValidRaycastResults.Insert(res);
						resultMap.Insert(res.obj, res);
						if (!firstValidRaycastedObject)
							firstValidRaycastedObject = res.obj;

						if (m_HitPos == vector.Zero)
							m_HitPos = res.pos;

						break;
					}
				}
			}
		}
		else
		{
			firstValidRaycastedObject = null;
			m_HitPos = vector.Zero;
		}

		DayZPlayerCamera camera = m_Player.GetCurrentCamera();
		if (camera && camera.GetCurrentPitch() <= -45)
			DayZPlayerUtils.GetEntitiesInCone(playerPos, headingDirection, c_ConeAngle, c_MaxTargetDistance, c_ConeHeightMin, c_ConeHeightMax, vicinityObjects);

		vicinityObjects.RemoveItem(m_Player);

		FilterDuplicateVicinityObjects(vicinityObjects, sortedValidRaycastResults);

		m_VicinityObjects.TransformToVicinityObjects(vicinityObjects);

		FilterObstructedObjectsEx(firstValidRaycastedObject, vicinityObjects);

		int vicinityObjCount = m_VicinityObjects.Count();
		for (int i = 0; i < vicinityObjCount; ++i)
		{
			Object object = m_VicinityObjects.GetObject(i);
			Object parent;
			RaycastRVResult result;
			int targetComponent;
			vector hitpos;
			if (resultMap.Find(object, result))
			{
				parent = result.parent;
				hitpos = result.pos;
				targetComponent = result.component;
			}
			else
			{
				parent = m_VicinityObjects.GetParent(i);
				hitpos = m_HitPos;
				targetComponent = -1;
			}

			float utility = ComputeUtility(object, m_RayStart, m_RayEnd, firstValidRaycastedObject, hitpos);
			if (utility > 0)
			{
				ActionTarget at = new ActionTarget(object, parent, targetComponent, m_HitPos, utility);
				StoreTarget(at);
			}
		}

		if (m_HitPos == vector.Zero)
		{
			vector contact_pos;
			vector hitNormal;
			float hitFraction;
			Object hitObject;

			m_RayEnd = m_RayStart + g_Game.GetCurrentCameraDirection() * c_RayDistance * 3;

			PhxInteractionLayers collisionLayerMask = PhxInteractionLayers.ROADWAY | PhxInteractionLayers.TERRAIN | PhxInteractionLayers.WATERLAYER;
			DayZPhysics.RayCastBullet(m_RayStart, m_RayEnd, collisionLayerMask, null, hitObject, contact_pos, hitNormal, hitFraction);
			m_HitPos = contact_pos;
		}

		m_Targets.Insert(new ActionTarget(null, null, -1, m_HitPos, 0));

#ifdef DIAG_DEVELOPER
		if (DiagMenu.GetBool(DiagMenuIDs.MISC_ACTION_TARGETS_DEBUG))
		{
			ShowDebugActionTargets(true);
			DrawDebugActionTargets(true);
			DrawDebugCone(true);
			DrawDebugRay(true);
			DrawSelectionPos(DiagMenu.GetBool(DiagMenuIDs.MISC_ACTION_TARGETS_SELPOS_DEBUG));
		}
		else
		{
			ShowDebugActionTargets(false);
			DrawDebugActionTargets(false);
			DrawDebugCone(false);
			DrawDebugRay(false);
			DrawSelectionPos(false);
		}
#endif
	}
};
