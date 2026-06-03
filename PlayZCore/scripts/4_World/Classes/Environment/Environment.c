modded class Environment
{
	override void GatherTemperatureSources()
	{
		super.GatherTemperatureSources();

		for (int i = m_UTemperatureSources.Count() - 1; i >= 0; i--)
		{
			UTemperatureSource uts = m_UTemperatureSources.Get(i);
			if (uts && uts.GetParent() && uts.GetParent().IsInherited(Torch))
			{
				m_UTemperatureSources.Remove(i);
			}
		}
	}
}
