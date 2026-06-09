modded class TerjeDosimetrPripyat
{
	override void TerjeEnableDisplayClient()
	{
		TerjeUpdateDisplaySelectionsClient(-1, 0, 0, 0);
	}

	override void TerjeUpdateDisplayValueClient(int value)
	{
		string strValue = TerjeMathHelper.ClampInt(value, 0, TerjeGeigerMaxLimit()).ToString();
		while (strValue.Length() < 3)
		{
			strValue = "0" + strValue;
		}

		TerjeUpdateDisplaySelectionsClient(-1, strValue.Get(0).ToInt(), strValue.Get(1).ToInt(), strValue.Get(2).ToInt());
	}

	override int TerjeGeigerMaxLimit()
	{
		return 499;
	}

	override float TerjeGeigerRadiationModifier()
	{
		return 1000;
	}
}
