modded class GameConstants
{
	//! Vanilla 0.01 — Sakhal: 3× slower heat buffer drain (per enviro tick).
	const float ENVIRO_PLAYER_HEATBUFFER_DECREASE = 0.006;

	//! Thin-air hypoxia (Sakhal): altitude/chrom/blur tunables in $profile:PlayZ/Sakhal.json.
	const float PLAYZ_SAKHAL_HYPOXIA_CAP_PENALTY_MAX = 100.0;
	const float PLAYZ_SAKHAL_HYPOXIA_SOFT_PPE_PARTIAL_MUL = 0.40;

	const float PLAYZ_SAKHAL_HYPOXIA_PPE_FADE_SEC = 1.0;
	const float PLAYZ_SAKHAL_HYPOXIA_CLIENT_REST_PPE_MUL = 0.52;
	const float PLAYZ_SAKHAL_HYPOXIA_CLIENT_SPRINT_PPE_MUL = 1.85;

	const float PLAYZ_SAKHAL_HYPOXIA_SOUND_COOLDOWN_MS = 4200;
}
