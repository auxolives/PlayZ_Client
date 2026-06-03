modded class PPERequester_TerjeMedSleeping
{
    private bool m_SoundReduced = false;
    const float SLEEP_EPSILON    = 0.90;
    const float SLEEP_VOLUME     = 0.05;

    override void OnUpdate(float delta)
    {
        super.OnUpdate(delta);

        if (m_SleepingCurrent > SLEEP_EPSILON && !m_SoundReduced)
        {
            GetGame().GetSoundScene().SetSoundVolume(SLEEP_VOLUME, 20);
            m_SoundReduced = true;
            PlayZEarPlugsGate.SetSleepingDeafnessActive(true);
        }
        else if (m_SleepingCurrent <= SLEEP_EPSILON && m_SoundReduced)
        {
            GetGame().GetSoundScene().SetSoundVolume(1.0, 10);
            m_SoundReduced = false;
            PlayZEarPlugsGate.SetSleepingDeafnessActive(false);
        }

    }

    override protected void OnStop(Param par = null)
    {
        super.OnStop(par);

        if (m_SoundReduced)
            GetGame().GetSoundScene().SetSoundVolume(1.0, 5);

        m_SoundReduced = false;
        PlayZEarPlugsGate.SetSleepingDeafnessActive(false);
    }
}
