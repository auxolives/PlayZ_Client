modded class Environment
{
	protected float m_PlayZTempMod = 0;

	override void Update(float pDelta)
	{
		super.Update(pDelta);

		float targetMod = PlayZConfig.m_CurrentScenarioTempMod;
		
		// Smooth interpolation for temperature modifier
		// Using a relatively slow factor (0.05) to ensure a gradual fade over several minutes
		// 0.05 * pDelta (0.1s tick) means it takes about 200 ticks (~20-40 seconds) to reach 63% of target.
		// For a very gradual fade, we could use even smaller value or tie it to weather transition.
		// But this provides a decent starting point for "gradual".
		m_PlayZTempMod = Math.Lerp(m_PlayZTempMod, targetMod, pDelta * 0.05);
	}

	override float GetEnvironmentTemperature()
	{
		float temperature = super.GetEnvironmentTemperature();

		if (m_PlayZTempMod != 0)
		{
			float modifier = m_PlayZTempMod;

			// Shelter logic: reduce penalty by 30% if under roof, 60% if inside building
			if (IsInsideBuilding())
			{
				modifier *= 0.4; // 60% reduction
			}
			else if (IsUnderRoof())
			{
				modifier *= 0.7; // 30% reduction
			}

			temperature += modifier;
		}

		return temperature;
	}
}
