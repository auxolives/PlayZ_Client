class PlayZWeatherScenarioNames
{
	static ref array<string> GetDefaultNames()
	{
		array<string> names = new array<string>;
		names.Insert("Heatwave");
		names.Insert("Clear");
		names.Insert("Coldwave");
		names.Insert("Partly Cloudy");
		names.Insert("Very Cloudy");
		names.Insert("Light Falls");
		names.Insert("Heavy Falls");
		names.Insert("Heavy Fog");
		names.Insert("Gale");
		names.Insert("Squall");
		return names;
	}
}
