class TLRLight_IR extends TLRLight
{
	static string LIGHT_ON_GLASS_RED = "dz\\characters\\headgear\\data\\HeadTorchGlass_on_red.rvmat";
	static string LIGHT_ON_REFLECTOR_RED = "dz\\characters\\headgear\\data\\HeadTorch_ON_red.rvmat";

	override void OnWorkStart()
	{
		super.OnWorkStart();

		if (!g_Game.IsServer() || !g_Game.IsMultiplayer())
		{
			if (m_Light)
			{
				m_Light.SetColorToRed();
			}
		}

		SetObjectMaterial(GLASS_ID, LIGHT_ON_GLASS_RED);
		SetObjectMaterial(REFLECTOR_ID, LIGHT_ON_REFLECTOR_RED);
	}
}
