// Guards null/stale m_CommandWeapons before vanilla UpdateUDAngleUnlocked (crash at 0x74).
// Source Found: scripts/4_World/Entities/ManBase/DayZPlayer/DayZPlayerCamera_Base.c:132
modded class DayZPlayerCameraBase
{
	protected void PlayZmCommandWeaponsFix_RefreshCommandWeapons()
	{
		m_CommandWeapons = null;

		if (!m_pPlayer)
			return;

		m_CommandWeapons = m_pPlayer.GetCommandModifier_Weapons();
	}

	protected bool PlayZmCommandWeaponsFix_CanUseCommandWeapons()
	{
		PlayZmCommandWeaponsFix_RefreshCommandWeapons();
		if (!m_CommandWeapons)
			return false;

		if (!m_pPlayer.GetHumanInventory())
			return false;

		if (!m_pPlayer.GetHumanInventory().GetEntityInHands())
			return false;

		return true;
	}

	protected float PlayZmCommandWeaponsFix_UpdateUDAngleUnlockedCore(out float pAngle, out float pAngleAdd, float pMin, float pMax, float pDt, bool useWeaponAim)
	{
		float target = pAngle;
		if (useWeaponAim)
			target = m_CommandWeapons.GetBaseAimingAngleUD();

		if (m_pInput.CameraIsTracking())
		{
			pAngleAdd = m_pInput.GetTracking()[1] * Math.RAD2DEG;
			pAngle = target;
			m_fUDAngleVel[0] = 0;
		}
		else
		{
			if (Math.AbsFloat(pAngleAdd) > 0.001)
			{
				pAngleAdd = pAngle + pAngleAdd - target;
				pAngle = target;
			}

			if (m_pInput.CameraIsFreeLook())
			{
				pAngleAdd += m_pInput.GetAimDelta(pDt)[1] * Math.RAD2DEG;
				m_fUDAngleVel[0] = 0;
			}
			else
			{
				PlayerBase player = PlayerBase.Cast(m_pPlayer);
				if (player)
				{
					float pitch = pAngle + pAngleAdd;
					float downLimit, upLimit, leftLimit, rightLimit;
					player.GetLookLimits(downLimit, upLimit, leftLimit, rightLimit);

					if (pitch < (upLimit + 1) && pitch > (downLimit - 1))
					{
						pMin = downLimit;
						pMax = upLimit;
					}
					else
					{
						float vel[1] = m_fUDAngleVel;
						pMin = Math.SmoothCD(pitch, downLimit, vel, 0.2, 1000, pDt);
						pMax = Math.SmoothCD(pitch, upLimit, vel, 0.2, 1000, pDt);
					}
				}

				pAngleAdd = Math.SmoothCD(pAngleAdd, 0.0, m_fUDAngleVel, 0.14, 1000, pDt);
			}

			if (!m_pInput.CameraIsFreeLook())
			{
				pAngle += m_pInput.GetAimDelta(pDt)[1] * Math.RAD2DEG;
			}
		}

		pAngle = Limit(pAngle, pMin, pMax);
		pAngleAdd = Limit(pAngle + pAngleAdd, pMin, pMax) - pAngle;
		return pAngle + pAngleAdd;
	}

	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		PlayZmCommandWeaponsFix_RefreshCommandWeapons();
		super.OnUpdate(pDt, pOutResult);
	}

	override float UpdateUDAngleUnlocked(out float pAngle, out float pAngleAdd, float pMin, float pMax, float pDt)
	{
		if (!m_ExIsFreeLook)
			return m_CurrentCameraPitch;

		bool useWeaponAim = PlayZmCommandWeaponsFix_CanUseCommandWeapons();
		return PlayZmCommandWeaponsFix_UpdateUDAngleUnlockedCore(pAngle, pAngleAdd, pMin, pMax, pDt, useWeaponAim);
	}

	override float UpdateUDAngle(out float pAngle, out float pAngleAdd, float pMin, float pMax, float pDt)
	{
		if (!PlayZmCommandWeaponsFix_CanUseCommandWeapons())
		{
			if (Math.AbsFloat(pAngleAdd) > 0.001)
				pAngleAdd = 0;
		}

		return super.UpdateUDAngle(pAngle, pAngleAdd, pMin, pMax, pDt);
	}
}
