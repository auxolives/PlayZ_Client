modded class PlayerSoundManagerClient
{
    ref TerjeMindHallucinationClient m_TerjeMind;

    override void Init()
    {
        super.Init();

        m_TerjeMind = new TerjeMindHallucinationClient(m_Player);
    }

    override void Update()
    {
        super.Update();

        if (m_TerjeMind)
            m_TerjeMind.Update();
    }
}