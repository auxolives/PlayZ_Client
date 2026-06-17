//! Throttles expensive PPE input sampling (health, dose, weather targets) to 1 Hz.
//! Fade/lerp and requester apply still run every frame for smooth visuals.
class PlayZPPEUpdateGate
{
	static const float SAMPLE_INTERVAL_SEC = 1.0;

	protected float m_Accum;

	bool ConsumeSampleTick(float timeslice)
	{
		m_Accum = m_Accum + timeslice;
		if (m_Accum < SAMPLE_INTERVAL_SEC)
		{
			return false;
		}

		m_Accum = 0;
		return true;
	}

	void Reset()
	{
		m_Accum = 0;
	}
}
