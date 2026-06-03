modded class IngameHud
{
	override int RegisterTerjeNotifierWidget(string iconPath, string name)
	{
		if (name == "TerjeMind")
			return -1;
		return super.RegisterTerjeNotifierWidget(iconPath, name);
	}

	override int RegisterTerjeBadgetWidget(string iconPath, string name, TerjeBadgeType type)
	{
		if (name == "TerjeVacinaC")
			return -1;
		return super.RegisterTerjeBadgetWidget(iconPath, name, type);
	}
}
