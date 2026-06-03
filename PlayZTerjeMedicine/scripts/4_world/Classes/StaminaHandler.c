modded class StaminaHandler
{
	override void Update(float deltaT, int pCurrentCommandID)
	{
		float staminaBefore;
		float staminaAfter;
		float lost;
		float sleepCur;
		PlayerBase player;

		staminaBefore = GetStamina();
		super.Update(deltaT, pCurrentCommandID);

		if (!GetGame().IsServer())
			return;

		staminaAfter = GetStamina();
		lost = staminaBefore - staminaAfter;
		if (lost <= 0)
			return;

		if (!m_Player)
			return;

		player = PlayerBase.Cast(m_Player);
		if (!player)
			return;

		if (!player.GetTerjeStats())
			return;

		//! 0.25 Terje sleep point per stamina point lost.
		sleepCur = player.GetTerjeStats().GetSleepingValue();
		player.GetTerjeStats().SetSleepingValue(sleepCur - (lost * 0.25));
	}
}
