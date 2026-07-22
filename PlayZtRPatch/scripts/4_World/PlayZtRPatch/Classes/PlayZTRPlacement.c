//! Helpers for tR kit / projection detection (Tierro base building).
class PlayZTRPlacement
{
	//! Penetration allowed per side before BBox/proxy counts as colliding (metres).
	static const float BBOX_CLIP_MARGIN_BARREL_M = 0.05;
	static const float BBOX_CLIP_MARGIN_TENT_M = 0.10;
	static const float BBOX_CLIP_MARGIN_TR_M = 0.75;
	static const float BBOX_CLIP_MARGIN_DEFAULT_M = 0.05;
	static const float BBOX_EDGE_MIN_M = 0.05;

	//! Half-extent / separation radius per tR family (metres). Min centre distance = r_self + r_other.
	static const float TR_SEP_STOCKADE_M = 1.5;
	static const float TR_SEP_STOCKADE_CORNER_M = 1.5;
	static const float TR_SEP_NARROW_DOOR_M = 0.6;
	static const float TR_SEP_MEDIUM_DOOR_M = 0.7;
	static const float TR_SEP_SHED_M = 1.2;
	static const float TR_SEP_BARRICADE_M = 0.5;
	static const float TR_SEP_SEARCH_M = 10.0; //! >= 2 * max radius
	static const float TR_SEP_EPSILON_M = 0.05; //! float tolerance on centre distance

	static bool IsTRTypeName(string typeName)
	{
		if (typeName == string.Empty)
			return false;

		return typeName.IndexOf("tR_") == 0;
	}

	static bool IsTREntity(Object obj)
	{
		if (!obj)
			return false;

		EntityAI entity;
		if (!Class.CastTo(entity, obj))
			return false;

		return IsTRTypeName(entity.GetType());
	}

	//! True when the hologram parent kit and/or projection is a tR deployable.
	static bool IsTRPlacement(EntityAI parent, EntityAI projection)
	{
		if (parent && IsTRTypeName(parent.GetType()))
			return true;

		if (projection && IsTRTypeName(projection.GetType()))
			return true;

		return false;
	}

	//! Trees, bushes, rocks, loot stones, power poles/lines, road signs, static walls — skip BBox/proxy.
	static bool IgnoresBBoxCollision(Object obj)
	{
		if (!obj)
			return true;

		if (obj.IsTree() || obj.IsBush() || obj.IsRock())
			return true;

		if (IsIgnoredStaticWorldProp(obj))
			return true;

		ItemBase item;
		if (Class.CastTo(item, obj))
		{
			if (item.IsInherited(SmallStone) || item.IsInherited(Stone))
				return true;
		}

		return false;
	}

	//! Match GetType() and GetShapeName() (.p3d) — cursor/collision often has empty type.
	static bool IsIgnoredStaticWorldProp(Object obj)
	{
		if (!obj)
			return false;

		if (MatchesIgnoredStaticToken(obj.GetType()))
			return true;

		return MatchesIgnoredStaticToken(obj.GetShapeName());
	}

	static bool MatchesIgnoredStaticToken(string token)
	{
		if (token == string.Empty)
			return false;

		token.ToLower();

		//! power poles / lines (power_pole_wood6_h, power_wiretel_50_main, …)
		if (token.IndexOf("power_pole") != -1)
			return true;

		if (token.IndexOf("power_wire") != -1)
			return true;

		if (token.IndexOf("power_hv_line") != -1)
			return true;

		if (token.IndexOf("power_hv2_line") != -1)
			return true;

		if (token.IndexOf("power_hv2_wire") != -1)
			return true;

		//! road signs (sign_priority_new.p3d, StaticObj_Sign_*, …)
		if (token.IndexOf("sign_") != -1)
			return true;

		//! map fence/wall props (wall_woodf_5_2.p3d, StaticObj_Wall_*, …)
		if (token.IndexOf("wall_") != -1)
			return true;

		return false;
	}

	//! True when a BBox/proxy hit should block placement (skips vegetation/rocks + tR↔tR).
	static bool HasBlockingBBoxHit(Object obj, bool isTRPlacement)
	{
		if (IgnoresBBoxCollision(obj))
			return false;

		if (isTRPlacement && IsTREntity(obj))
			return false;

		return true;
	}

	//! Separation radius for kits and placed/winter variants (StockadeCorner before Stockade).
	static float GetTRSeparationRadius(string typeName)
	{
		if (!IsTRTypeName(typeName))
			return 0;

		if (typeName.IndexOf("StockadeCorner") != -1)
			return TR_SEP_STOCKADE_CORNER_M;

		if (typeName.IndexOf("Stockade") != -1)
			return TR_SEP_STOCKADE_M;

		if (typeName.IndexOf("NarrowDoor") != -1)
			return TR_SEP_NARROW_DOOR_M;

		if (typeName.IndexOf("MediumDoor") != -1)
			return TR_SEP_MEDIUM_DOOR_M;

		if (typeName.IndexOf("Shed") != -1)
			return TR_SEP_SHED_M;

		if (typeName.IndexOf("ShieldSmall") != -1)
			return TR_SEP_BARRICADE_M;

		return 0;
	}

	static float GetTRSeparationRadiusEntity(EntityAI entity)
	{
		if (!entity)
			return 0;

		return GetTRSeparationRadius(entity.GetType());
	}

	//! Horizontal distance only (ignore height).
	static float DistanceHorizontal(vector a, vector b)
	{
		a[1] = 0;
		b[1] = 0;
		return vector.Distance(a, b);
	}

	//! True when projection is closer than (own radius + other radius) to another placed tR base
	//! (not a casually dropped / held Kit item).
	static bool IsTooCloseToOtherTR(EntityAI parent, EntityAI projection, vector projectionPos)
	{
		if (!projection)
			return false;

		float selfRadius = GetTRSeparationRadiusEntity(projection);
		if (selfRadius <= 0 && parent)
			selfRadius = GetTRSeparationRadiusEntity(parent);

		if (selfRadius <= 0)
			return false;

		array<Object> nearest = new array<Object>;
		array<CargoBase> proxy = new array<CargoBase>;
		g_Game.GetObjectsAtPosition(projectionPos, TR_SEP_SEARCH_M, nearest, proxy);

		foreach (Object obj : nearest)
		{
			if (!obj || obj == projection || obj == parent)
				continue;

			EntityAI other;
			if (!Class.CastTo(other, obj))
				continue;

			if (!IsTRTypeName(other.GetType()))
				continue;

			float otherRadius = GetTRSeparationRadiusEntity(other);
			if (otherRadius <= 0)
				continue;

			float required = selfRadius + otherRadius;
			float distance = DistanceHorizontal(projectionPos, other.GetPosition());
			if (distance + TR_SEP_EPSILON_M < required)
				return true;
		}

		return false;
	}

	static bool EntityIsTent(EntityAI entity)
	{
		return entity && entity.IsInherited(TentBase);
	}

	static bool EntityIsBarrel(EntityAI entity)
	{
		return entity && (entity.IsInherited(Barrel_ColorBase) || entity.IsInherited(BarrelHoles_ColorBase));
	}

	//! Per-type clip margin: tR kits 0.75 m, tents 0.15 m, barrels 0.05 m, else default.
	static float GetBBoxClipMargin(EntityAI parent, EntityAI projection)
	{
		if (IsTRPlacement(parent, projection))
			return BBOX_CLIP_MARGIN_TR_M;

		if (EntityIsTent(parent) || EntityIsTent(projection))
			return BBOX_CLIP_MARGIN_TENT_M;

		if (EntityIsBarrel(parent) || EntityIsBarrel(projection))
			return BBOX_CLIP_MARGIN_BARREL_M;

		return BBOX_CLIP_MARGIN_DEFAULT_M;
	}

	//! Shrink hologram collision extents so up to the type margin can clip on each side.
	static vector ApplyBBoxClipMargin(vector edgeLength, EntityAI parent, EntityAI projection)
	{
		float shrink = GetBBoxClipMargin(parent, projection) * 2.0;
		edgeLength[0] = Math.Max(BBOX_EDGE_MIN_M, edgeLength[0] - shrink);
		edgeLength[1] = Math.Max(BBOX_EDGE_MIN_M, edgeLength[1] - shrink);
		edgeLength[2] = Math.Max(BBOX_EDGE_MIN_M, edgeLength[2] - shrink);
		return edgeLength;
	}

	//! True for tR placement kits only (not placed stockade/door entities).
	static bool IsTRKitItem(ItemBase item)
	{
		if (!item)
			return false;

		string typeName = item.GetType();
		if (!IsTRTypeName(typeName))
			return false;

		if (typeName.IndexOf("Kit") != -1)
			return true;

		return item.IsBasebuildingKit() || item.IsDeployable();
	}

	//! Base-building deployables blocked by no-build zones (not barrels/crates/etc.).
	static bool IsBaseBuildingDeployable(ItemBase item)
	{
		if (!item)
			return false;

		if (item.IsBasebuildingKit())
			return true;

		if (IsTRKitItem(item))
			return true;

		if (item.IsInherited(TentBase))
			return true;

		return false;
	}

	static bool IsInNoBuildZone(vector pos)
	{
		return PlayZNoBuildZonesState.IsPositionRestricted(pos);
	}

	//! Items that intentionally skip hologram collision (Notes).
	static bool IgnoresPlacementCollision(ItemBase action_item)
	{
		if (!action_item)
			return false;

		if (action_item.IsKindOf("PlayZNote"))
			return true;

		return false;
	}

	//! Client/server gate for deploy prompt + SetupAction. Refresh collision first; also treat float/hidden as invalid
	//! (RefreshVisual uses IsColliding || IsFloating for the red material — floating alone must hide deploy).
	static bool CanDeployFromHologram(PlayerBase player, Hologram hologram, ItemBase item)
	{
		if (!player || !item)
			return false;

		if (!hologram)
			return false;

		hologram.EvaluateCollision(item);

		// IsColliding() for tR returns PlayZ-owned flag (see Hologram.IsColliding override).
		if (hologram.IsColliding() || hologram.IsFloating() || hologram.IsHidden())
			return false;

		EntityAI projection = hologram.GetProjectionEntity();
		if (!projection)
			return false;

		if (IsBaseBuildingDeployable(item) && IsInNoBuildZone(projection.GetPosition()))
			return false;

		if (!item.CanBePlaced(player, projection.GetPosition()))
			return false;

		return true;
	}
}
