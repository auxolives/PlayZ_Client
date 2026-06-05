//! Rad protection tier tag on inventory inspect / hover tooltip.
//! Reuses ItemFoodStageWidget (empty for clothing). PlayZ green palette: #5ECF6E family.
//! Rad contamination tier tag (dosimeter-gated) reuses ItemCleannessWidget. Yellow-orange palette.

modded class InspectMenuNew
{
	static const float PLAYZ_RAD_PROTECT_T1 = 0.2;
	static const float PLAYZ_RAD_PROTECT_T2 = 0.4;
	static const float PLAYZ_RAD_PROTECT_T3 = 0.6;
	static const float PLAYZ_RAD_PROTECT_T4 = 0.8;

	static const int PLAYZ_RAD_COLOR_MINIMAL = 0x002E5A35;
	static const int PLAYZ_RAD_COLOR_LOW = 0x003E7A48;
	static const int PLAYZ_RAD_COLOR_MEDIUM = 0x004E9F58;
	static const int PLAYZ_RAD_COLOR_HIGH = 0x005ECF6E;
	static const int PLAYZ_RAD_COLOR_MAXIMUM = 0x006FE882;

	static const float PLAYZ_RAD_CONTAM_T1 = 100;
	static const float PLAYZ_RAD_CONTAM_T2 = 500;
	static const float PLAYZ_RAD_CONTAM_T3 = 1000;
	static const float PLAYZ_RAD_CONTAM_T4 = 2000;

	static const int PLAYZ_RAD_CONTAM_COLOR_TRACE = 0x00C9C44E;
	static const int PLAYZ_RAD_CONTAM_COLOR_LOW = 0x00D4A832;
	static const int PLAYZ_RAD_CONTAM_COLOR_MODERATE = 0x00E08C1A;
	static const int PLAYZ_RAD_CONTAM_COLOR_HIGH = 0x00E8720A;
	static const int PLAYZ_RAD_CONTAM_COLOR_SEVERE = 0x00F05800;

	static bool IsLocalPlayerDosimeterActive()
	{
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!player)
		{
			return false;
		}

		return player.PlayZHasActiveDosimeterInHands();
	}

	static float GetEntityTerjeRadiation(EntityAI entity)
	{
		if (!entity)
		{
			return 0;
		}

		PluginTerjeScriptableAreas plugin = GetTerjeScriptableAreas();
		if (!plugin)
		{
			return 0;
		}

		return plugin.GetTerjeRadiationFromEntity(entity);
	}

	static void UpdateItemInfoRadProtection(Widget root_widget, EntityAI item)
	{
		if (!root_widget || !item)
		{
			return;
		}

		ItemBase itemBase = ItemBase.Cast(item);
		if (!itemBase)
		{
			return;
		}

		Edible_Base foodItem = Edible_Base.Cast(item);
		if (foodItem && foodItem.GetFoodStage())
		{
			return;
		}

		float protection = itemBase.GetTerjeProtectionLevel("radiation");
		float isolation = itemBase.GetTerjeRadiationInventoryIsolation();
		float value = Math.Max(protection, isolation);
		if (value <= 0)
		{
			return;
		}

		string label;
		int color;
		if (value <= PLAYZ_RAD_PROTECT_T1)
		{
			label = "#STR_PLAYZ_RAD_PROTECT_MINIMAL";
			color = PLAYZ_RAD_COLOR_MINIMAL;
		}
		else if (value <= PLAYZ_RAD_PROTECT_T2)
		{
			label = "#STR_PLAYZ_RAD_PROTECT_LOW";
			color = PLAYZ_RAD_COLOR_LOW;
		}
		else if (value <= PLAYZ_RAD_PROTECT_T3)
		{
			label = "#STR_PLAYZ_RAD_PROTECT_MEDIUM";
			color = PLAYZ_RAD_COLOR_MEDIUM;
		}
		else if (value <= PLAYZ_RAD_PROTECT_T4)
		{
			label = "#STR_PLAYZ_RAD_PROTECT_HIGH";
			color = PLAYZ_RAD_COLOR_HIGH;
		}
		else
		{
			label = "#STR_PLAYZ_RAD_PROTECT_MAXIMUM";
			color = PLAYZ_RAD_COLOR_MAXIMUM;
		}

		WidgetTrySetText(root_widget, "ItemFoodStageWidget", label, color);
	}

	static void UpdateItemInfoRadContamination(Widget root_widget, EntityAI item)
	{
		if (!root_widget || !item)
		{
			return;
		}

		if (!IsLocalPlayerDosimeterActive())
		{
			return;
		}

		float radiation = GetEntityTerjeRadiation(item);
		if (radiation <= 0)
		{
			UpdateItemInfoCleanness(root_widget, item);
			return;
		}

		string label;
		int color;
		if (radiation <= PLAYZ_RAD_CONTAM_T1)
		{
			label = "#STR_PLAYZ_RAD_CONTAM_TRACE";
			color = PLAYZ_RAD_CONTAM_COLOR_TRACE;
		}
		else if (radiation <= PLAYZ_RAD_CONTAM_T2)
		{
			label = "#STR_PLAYZ_RAD_CONTAM_LOW";
			color = PLAYZ_RAD_CONTAM_COLOR_LOW;
		}
		else if (radiation <= PLAYZ_RAD_CONTAM_T3)
		{
			label = "#STR_PLAYZ_RAD_CONTAM_MODERATE";
			color = PLAYZ_RAD_CONTAM_COLOR_MODERATE;
		}
		else if (radiation <= PLAYZ_RAD_CONTAM_T4)
		{
			label = "#STR_PLAYZ_RAD_CONTAM_HIGH";
			color = PLAYZ_RAD_CONTAM_COLOR_HIGH;
		}
		else
		{
			label = "#STR_PLAYZ_RAD_CONTAM_SEVERE";
			color = PLAYZ_RAD_CONTAM_COLOR_SEVERE;
		}

		WidgetTrySetText(root_widget, "ItemCleannessWidget", label, color);
	}

	override void SetItem(EntityAI item)
	{
		super.SetItem(item);

		if (item && layoutRoot)
		{
			UpdateItemInfoRadProtection(layoutRoot, item);
			UpdateItemInfoRadContamination(layoutRoot, item);
		}
	}
}
