//! Restore vanilla hologram collision + visuals for deployables.
//! For tR kits: own IsColliding flag (tR may force false), vanilla RefreshVisual (no tR style).
//! Source Found: scripts/4_World/Classes/Hologram.c:432, :540, :589, :1373, :1546, :1570
modded class Hologram
{
	//! PlayZ-owned collide flag — used for tR so ActionCondition cannot be lied to by upstream IsColliding().
	protected bool m_PlayZIsColliding;

	void PlayZ_SetIsColliding(bool isColliding)
	{
		m_PlayZIsColliding = isColliding;
		SetIsColliding(isColliding);
	}

	bool PlayZ_IsColliding()
	{
		return m_PlayZIsColliding;
	}

	override void EvaluateCollision(ItemBase action_item = null)
	{
		// Do not call super — tR / Expansion clear or bypass collision.
		if (PlayZTRPlacement.IgnoresPlacementCollision(action_item))
		{
			PlayZ_SetIsColliding(false);
			return;
		}

		if (!m_Player.CanPlaceItem(m_Projection))
		{
			PlayZ_SetIsColliding(true);
		}
		else if (IsFloating() || IsHidden() || IsCollidingBBox(action_item) || IsCollidingGeometryProxy(action_item) || IsCollidingPlayer() || IsClippingRoof() || !IsBaseViable() || IsCollidingGPlot() || IsCollidingZeroPos() || IsCollidingAngle() || !IsPlacementPermitted() || !HeightPlacementCheck() || IsUnderwater() || IsInTerrain())
		{
			PlayZ_SetIsColliding(true);
		}
		else if (PlayZTRPlacement.IsTRPlacement(GetParentEntity(), GetProjectionEntity()) && PlayZTRPlacement.IsTooCloseToOtherTR(GetParentEntity(), GetProjectionEntity(), m_Projection.GetPosition()))
		{
			PlayZ_SetIsColliding(true);
		}
		else if (m_Projection.IsInherited(TrapSpawnBase))
		{
			TrapSpawnBase trapSpawnBase;
			Class.CastTo(trapSpawnBase, m_Projection);
			PlayZ_SetIsColliding(!trapSpawnBase.IsPlaceableAtPosition(m_Projection.GetPosition()));
		}
		else if (m_Projection.IsInherited(TrapBase))
		{
			TrapBase trapBase;
			Class.CastTo(trapBase, m_Projection);
			PlayZ_SetIsColliding(!trapBase.IsPlaceableAtPosition(m_Projection.GetPosition()));
		}
		else
		{
			PlayZ_SetIsColliding(false);
		}
	}

	//! tR: never trust upstream IsColliding(); everyone else uses normal chain.
	override bool IsColliding()
	{
		if (PlayZTRPlacement.IsTRPlacement(GetParentEntity(), GetProjectionEntity()))
			return m_PlayZIsColliding;

		return super.IsColliding();
	}

	//! tR: vanilla hologram materials only (skip tR custom RefreshVisual).
	override void RefreshVisual()
	{
		if (!PlayZTRPlacement.IsTRPlacement(GetParentEntity(), GetProjectionEntity()))
		{
			super.RefreshVisual();
			return;
		}

		if (!m_Projection)
			return;

		static const string textureName = "#(argb,8,8,3)color(0.5,0.5,0.5,0.75,ca)";

		int hidden_selection = 0;
		string selection_to_refresh;
		string config_material = string.Format("CfgVehicles %1 hologramMaterial", m_Projection.GetType());
		string hologram_material = g_Game.ConfigGetTextOut(config_material);
		string config_model = string.Format("CfgVehicles %1 hologramMaterialPath", m_Projection.GetType());
		string hologram_material_path = string.Format("%1\\%2%3", g_Game.ConfigGetTextOut(config_model), hologram_material, PlayZ_CorrectMaterialPathNameVanilla());

		for (int i = 0; i < m_SelectionsToRefresh.Count(); ++i)
		{
			selection_to_refresh = m_SelectionsToRefresh.Get(i);
			hidden_selection = GetHiddenSelection(selection_to_refresh);
			m_Projection.SetObjectTexture(hidden_selection, textureName);
			m_Projection.SetObjectMaterial(hidden_selection, hologram_material_path);
		}
	}

	//! Same rules as vanilla CorrectMaterialPathName, using PlayZ collide flag for tR.
	string PlayZ_CorrectMaterialPathNameVanilla()
	{
		if (IsColliding() || IsFloating())
			return SUFFIX_MATERIAL_UNDEPLOYABLE;

		if (m_Parent && m_Parent.HasEnergyManager())
		{
			ComponentEnergyManager comp_em = m_Parent.GetCompEM();
			string SEL_CORD_PLUGGED = m_Parent.GetCompEM().SEL_CORD_PLUGGED;
			string SEL_CORD_FOLDED = m_Parent.GetCompEM().SEL_CORD_FOLDED;

			if (comp_em.IsPlugged() && comp_em.IsEnergySourceAtReach(GetProjectionPosition()))
			{
				m_Projection.SetAnimationPhase(SEL_CORD_PLUGGED, 0);
				m_Projection.SetAnimationPhase(SEL_CORD_FOLDED, 1);
				return SUFFIX_MATERIAL_POWERED;
			}

			m_Projection.SetAnimationPhase(SEL_CORD_PLUGGED, 1);
			m_Projection.SetAnimationPhase(SEL_CORD_FOLDED, 0);
		}

		return SUFFIX_MATERIAL_DEPLOYABLE;
	}

	override bool IsCollidingBBox(ItemBase action_item = null)
	{
		if (CfgGameplayHandler.GetDisableIsCollidingBBoxCheck())
			return false;

		vector center;
		vector relativeOffset;
		vector absoluteOffset = "0 0.05 0";
		vector orientation = GetProjectionOrientation();
		vector edgeLength;
		vector minMax[2];
		array<Object> excludedObjects = new array<Object>();
		array<Object> collidedObjects = new array<Object>();

		GetProjectionCollisionBox(minMax);
		relativeOffset[1] = (minMax[1][1] - minMax[0][1]) * 0.5;
		center = m_Projection.GetPosition() + relativeOffset + absoluteOffset;
		edgeLength = PlayZTRPlacement.ApplyBBoxClipMargin(GetCollisionBoxSize(minMax), GetParentEntity(), GetProjectionEntity());
		excludedObjects.Insert(m_Projection);
		excludedObjects.Insert(m_Player);

		if (action_item)
			excludedObjects.Insert(action_item);

		bool hit = g_Game.IsBoxCollidingGeometry(center, orientation, edgeLength, ObjIntersectFire, ObjIntersectGeom, excludedObjects, collidedObjects);
		if (!hit)
			return false;

		bool isTR = PlayZTRPlacement.IsTRPlacement(GetParentEntity(), GetProjectionEntity());
		foreach (Object obj : collidedObjects)
		{
			if (PlayZTRPlacement.HasBlockingBBoxHit(obj, isTR))
				return true;
		}

		return false;
	}

	override bool IsCollidingGeometryProxy(ItemBase action_item = null)
	{
		if (CfgGameplayHandler.GetDisableIsCollidingBBoxCheck())
			return false;

		vector center;
		vector relativeOffset;
		vector absoluteOffset = "0 0.05 0";
		vector orientation = GetProjectionOrientation();
		vector edgeLength;
		vector minMax[2];
		array<Object> excludedObjects = new array<Object>();
		array<ref BoxCollidingResult> collidedObjects = new array<ref BoxCollidingResult>();

		GetProjectionCollisionBox(minMax);
		relativeOffset[1] = (minMax[1][1] - minMax[0][1]) * 0.5;
		center = m_Projection.GetPosition() + relativeOffset + absoluteOffset;
		edgeLength = PlayZTRPlacement.ApplyBBoxClipMargin(GetCollisionBoxSize(minMax), GetParentEntity(), GetProjectionEntity());
		excludedObjects.Insert(m_Projection);
		excludedObjects.Insert(m_Player);

		if (action_item)
			excludedObjects.Insert(action_item);

		BoxCollidingParams params = new BoxCollidingParams();
		params.SetParams(center, orientation, edgeLength, ObjIntersect.View, ObjIntersect.Geom, false);
		bool hit = g_Game.IsBoxCollidingGeometryProxy(params, excludedObjects, collidedObjects);
		if (!hit)
			return false;

		bool isTR = PlayZTRPlacement.IsTRPlacement(GetParentEntity(), GetProjectionEntity());
		foreach (BoxCollidingResult result : collidedObjects)
		{
			if (!result || !result.obj)
				continue;

			if (PlayZTRPlacement.HasBlockingBBoxHit(result.obj, isTR))
				return true;
		}

		return false;
	}
}
