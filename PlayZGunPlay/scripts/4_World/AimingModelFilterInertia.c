// Changes sGunplay's inertia direction from "weapon lags behind aim movement"
// to "weapon overshoots in the direction of movement" (pendulum swing feel).
// The only difference from the base implementation is + m_vel instead of - m_vel
// in the SmoothCD target, reversing the inertia vector direction.
modded class AimingModelFilterInertia
{
    override void onUpdate(float pDt, SDayZPlayerAimingModel pModel, int stanceIndex)
    {
        //////////////////////////
        // ACCELERATION
        m_accel = getAimingModel().getAimDeltaDegree(pDt) * computeInertiaMultiplier();
        m_vel += m_accel;
        m_vel[0] = Math.Clamp(m_vel[0], GunplayConstants.INERTIA_VELOCITY_LIMIT[1], GunplayConstants.INERTIA_VELOCITY_LIMIT[2]);
        m_vel[1] = Math.Clamp(m_vel[1], GunplayConstants.INERTIA_VELOCITY_LIMIT[3], GunplayConstants.INERTIA_VELOCITY_LIMIT[0]);

        pModel.m_fAimXHandsOffset = Math.SmoothCD(pModel.m_fAimXHandsOffset, pModel.m_fAimXHandsOffset + m_vel[0], m_currInertiaVelX, GunplayConstants.INERTIA_SPEED_ACCELERATION[0], 1000, pDt);

        pModel.m_fAimYHandsOffset = Math.SmoothCD(pModel.m_fAimYHandsOffset, pModel.m_fAimYHandsOffset + m_vel[1], m_currInertiaVelY, GunplayConstants.INERTIA_SPEED_ACCELERATION[1], 1000, pDt);

        //////////////////////////
        // DECELERATION
        m_vel[0] = Math.SmoothCD(m_vel[0],0,m_currResetVelX,GunplayConstants.INERTIA_SPEED_RESET[0], 1000, pDt);
        m_vel[1] = Math.SmoothCD(m_vel[1],0,m_currResetVelY,GunplayConstants.INERTIA_SPEED_RESET[1], 1000, pDt);

        if (GetGame().IsClient())
        {
            pModel.m_fAimXCamOffset += m_vel[0] * GunplayConstants.INERTIA_MISALIGNMENT_INTENSITY[0];
            pModel.m_fAimYCamOffset += m_vel[1] * GunplayConstants.INERTIA_MISALIGNMENT_INTENSITY[1];
        }
    }
}
