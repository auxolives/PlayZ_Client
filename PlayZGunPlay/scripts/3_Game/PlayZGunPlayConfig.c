class PlayZGunPlayConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/GunPlay.json";

	// -------------------------------------------------------------------------
	// Vegetation Sway Penalty
	// -------------------------------------------------------------------------
	// Simulates weapon catching on branches, causing aim tremors.
	// Amplifies sway heavily when standing inside bushes or trees, and fires
	// random directional "branch snag" jolts modulated by wind speed.
	bool  m_EnableVegetationSwayPenalty  = true;

	// Extra sway scale at maximum vegetation collision.
	// e.g. 2.5 means a fully entangled player has 3.5x base sway.
	float m_VegetationSwayPenaltyScale   = 2.50;

	// Snag parameters — controls the random "branch hit" frequency and force
	float m_VegSnagMinInterval           = 0.8;
	float m_VegSnagMaxInterval           = 6.0;
	float m_VegSnagIntensityScale        = 1.5;
	float m_VegSnagWindScale             = 2.0;

	// -------------------------------------------------------------------------
	// ADS Entry Offset
	// -------------------------------------------------------------------------
	// Each time the player enters ADS (ironsights or optics), a small random
	// X/Y offset is applied to the hands model and smoothly decays to zero.
	// This prevents reliable quick-scoping with a fixed fake crosshair.
	bool  m_EnableADSEntryOffset         = true;
	float m_ADSEntryOffsetMaxX           = 1.6;   // Max random X degrees at ADS entry
	float m_ADSEntryOffsetMaxY           = 0.9;   // Max random Y degrees at ADS entry
	float m_ADSEntryOffsetDecayTime      = 1.6;   // Seconds to decay fully to zero

	// -------------------------------------------------------------------------

	void Load()
	{
		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZGunPlayConfig>.JsonLoadFile(CONFIG_PATH, this);
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
			MakeDirectory(CONFIG_ROOT);
		JsonFileLoader<PlayZGunPlayConfig>.JsonSaveFile(CONFIG_PATH, this);
	}

	void SetDefaults()
	{
		m_EnableVegetationSwayPenalty = true;
		m_VegetationSwayPenaltyScale  = 2.50;
		m_VegSnagMinInterval          = 0.8;
		m_VegSnagMaxInterval          = 6.0;
		m_VegSnagIntensityScale       = 1.5;
		m_VegSnagWindScale            = 2.0;

		m_EnableADSEntryOffset        = true;
		m_ADSEntryOffsetMaxX          = 1.6;
		m_ADSEntryOffsetMaxY          = 0.9;
		m_ADSEntryOffsetDecayTime     = 1.6;
	}
}
