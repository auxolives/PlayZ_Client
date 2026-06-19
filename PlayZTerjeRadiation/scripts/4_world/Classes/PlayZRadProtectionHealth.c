//! Condition-based penalty on Terje radiation protection (worn gear + masks).
//! Tunables: $profile:PlayZ/Radiation.json (m_ProtectHealth*).

class PlayZRadProtectionHealth
{
	//! GetHealth01 throws on client; use discrete health levels for PPE / inspect.
	static float PlayZGetItemHealth01(ItemBase item)
	{
		if (GetGame().IsServer())
		{
			return item.GetHealth01("", "");
		}

		return item.GetHealthLevelValue(item.GetHealthLevel(), "");
	}

	static float GetEffectiveHealth01(ItemBase item)
	{
		if (!item || item.IsDamageDestroyed())
		{
			return 0;
		}

		float health01 = PlayZGetItemHealth01(item);

		MaskBase mask = MaskBase.Cast(item);
		if (mask)
		{
			ItemBase filter = ItemBase.Cast(mask.GetExternalFilter());
			if (filter && !filter.IsDamageDestroyed())
			{
				float filterHealth01 = PlayZGetItemHealth01(filter);
				if (filterHealth01 < health01)
				{
					health01 = filterHealth01;
				}
			}
		}

		return health01;
	}

	static float GetPenalty(float health01)
	{
		PlayZRadiationConfig cfg = PlayZRadiationManager.GetRadiation();
		if (!cfg || !cfg.m_ProtectHealthEnabled)
		{
			return 0;
		}

		if (health01 >= cfg.m_ProtectHealthFloor)
		{
			return 0;
		}

		return cfg.m_ProtectMaxPenalty * (1.0 - health01);
	}

	static float ApplyPenalty(ItemBase item, float baseProtection)
	{
		if (baseProtection <= 0)
		{
			return 0;
		}

		PlayZRadiationConfig cfg = PlayZRadiationManager.GetRadiation();
		if (!cfg || !cfg.m_ProtectHealthEnabled)
		{
			return baseProtection;
		}

		float health01 = GetEffectiveHealth01(item);
		if (health01 <= 0)
		{
			if (item.IsDamageDestroyed())
			{
				return 0;
			}

			return baseProtection;
		}

		return Math.Clamp(baseProtection - GetPenalty(health01), 0, 1);
	}
}
