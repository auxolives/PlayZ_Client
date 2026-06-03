class PlayZWeatherScenario
{
	string m_Name;
	float m_Probability;
	
	float m_OvercastMin, m_OvercastMax;
	float m_RainMin, m_RainMax;
	float m_WindMin, m_WindMax;
	
	float m_VolFogDistanceMin, m_VolFogDistanceMax;
	float m_VolFogHeightMin, m_VolFogHeightMax;
	float m_VolFogBiasMin, m_VolFogBiasMax;
	
	int m_DurationMin, m_DurationMax;
	
	void PlayZWeatherScenario(string name, float prob, float oMin, float oMax, float rMin, float rMax, float wMin, float wMax, float vfdMin, float vfdMax, float vfhMin, float vfhMax, float vfbMin, float vfbMax, int dMin, int dMax)
	{
		m_Name = name;
		m_Probability = prob;
		m_OvercastMin = oMin;
		m_OvercastMax = oMax;
		m_RainMin = rMin;
		m_RainMax = rMax;
		m_WindMin = wMin;
		m_WindMax = wMax;
		m_VolFogDistanceMin = vfdMin;
		m_VolFogDistanceMax = vfdMax;
		m_VolFogHeightMin = vfhMin;
		m_VolFogHeightMax = vfhMax;
		m_VolFogBiasMin = vfbMin;
		m_VolFogBiasMax = vfbMax;
		m_DurationMin = dMin;
		m_DurationMax = dMax;
	}
}
