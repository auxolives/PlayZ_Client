class PlayZRadiationConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/Radiation.json";

	bool m_EnableEnvSaturation = true;
	bool m_EnableEnvGrain = true;
	bool m_EnableBodyVignette = true;
	bool m_EnableBodyFever = true;
	bool m_EnableBodyRadial = true;
	bool m_EnableBodyGhost = true;

	float m_EnvSatDoseMin = 0.3;
	float m_EnvSatDoseMax = 2.0;
	float m_EnvGrainDoseMin = 0.8;
	float m_EnvGrainDoseMax = 3.0;

	float m_BodyVignetteMin = 300.0;
	float m_BodyVignetteMax = 2000.0;
	float m_BodyFeverMin = 800.0;
	float m_BodyFeverMax = 3000.0;
	float m_BodyRadialMin = 1500.0;
	float m_BodyRadialMax = 3000.0;
	float m_BodyGhostMin = 1500.0;
	float m_BodyGhostMax = 3000.0;

	float m_SickVignetteMin = 1.0;
	float m_SickVignetteMax = 2.0;
	float m_SickFeverMin = 1.5;
	float m_SickFeverMax = 2.5;
	float m_SickRadialMin = 2.2;
	float m_SickRadialMax = 3.5;
	float m_SickGhostMin = 2.2;
	float m_SickGhostMax = 3.5;
	float m_SickSatMin = 2.5;
	float m_SickSatMax = 4.0;
	float m_SickGrainMin = 3.5;
	float m_SickGrainMax = 5.0;

	float m_BodyVignetteIntensityMax = 1.0;
	float m_BodyFeverIntensityMax = 0.4;
	float m_BodyRadialPowerMax = 0.25;

	float m_EnvGrainSharpnessMax = 10.0;
	float m_EnvGrainSizeMin = 1.0;
	float m_EnvGrainSizeDefault = 2.75;
	float m_EnvNoiseMultMax = 0.15;

	bool m_ProtectHealthEnabled = true;
	float m_ProtectHealthFloor = 0.8;
	float m_ProtectMaxPenalty = 0.5;

	//! Server-only: scales Terje food rad buffer gain on eat (1 = vanilla Terje).
	float m_FoodIngestRadMultiplier = 0.25;

	//! Server-only: VehicleBattery zone exposure charge drain (drainEnergy/s = effectiveZone / divisor).
	bool m_BatteryZoneDrainEnabled = true;
	float m_BatteryZoneDrainThreshold = 0.5;
	float m_BatteryZoneDrainDivisor = 15.0;
	float m_BatteryZoneDrainMaxZone = 5.0;
	float m_BatteryZoneDrainTickSeconds = 1.0;

	void Load()
	{
		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZRadiationConfig>.JsonLoadFile(CONFIG_PATH, this);
		}
		else
		{
			SetDefaults();
			Save();
		}
	}

	void Save()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}

		JsonFileLoader<PlayZRadiationConfig>.JsonSaveFile(CONFIG_PATH, this);
	}

	void SetDefaults()
	{
		m_EnableEnvSaturation = true;
		m_EnableEnvGrain = true;
		m_EnableBodyVignette = true;
		m_EnableBodyFever = true;
		m_EnableBodyRadial = true;
		m_EnableBodyGhost = true;

		m_EnvSatDoseMin = 0.3;
		m_EnvSatDoseMax = 2.0;
		m_EnvGrainDoseMin = 0.8;
		m_EnvGrainDoseMax = 3.0;

		m_BodyVignetteMin = 300.0;
		m_BodyVignetteMax = 2000.0;
		m_BodyFeverMin = 800.0;
		m_BodyFeverMax = 3000.0;
		m_BodyRadialMin = 1500.0;
		m_BodyRadialMax = 3000.0;
		m_BodyGhostMin = 1500.0;
		m_BodyGhostMax = 3000.0;

		m_SickVignetteMin = 1.0;
		m_SickVignetteMax = 2.0;
		m_SickFeverMin = 1.5;
		m_SickFeverMax = 2.5;
		m_SickRadialMin = 2.2;
		m_SickRadialMax = 3.5;
		m_SickGhostMin = 2.2;
		m_SickGhostMax = 3.5;
		m_SickSatMin = 2.5;
		m_SickSatMax = 4.0;
		m_SickGrainMin = 3.5;
		m_SickGrainMax = 5.0;

		m_BodyVignetteIntensityMax = 1.0;
		m_BodyFeverIntensityMax = 0.4;
		m_BodyRadialPowerMax = 0.25;

		m_EnvGrainSharpnessMax = 10.0;
		m_EnvGrainSizeMin = 1.0;
		m_EnvGrainSizeDefault = 2.75;
		m_EnvNoiseMultMax = 0.15;

		m_ProtectHealthEnabled = true;
		m_ProtectHealthFloor = 0.8;
		m_ProtectMaxPenalty = 0.5;

		m_FoodIngestRadMultiplier = 0.25;

		m_BatteryZoneDrainEnabled = true;
		m_BatteryZoneDrainThreshold = 0.5;
		m_BatteryZoneDrainDivisor = 15.0;
		m_BatteryZoneDrainMaxZone = 5.0;
		m_BatteryZoneDrainTickSeconds = 1.0;
	}
}
