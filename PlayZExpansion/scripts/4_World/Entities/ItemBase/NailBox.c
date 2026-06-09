// Expansion Exchange treats NailBox as a 70-unit denomination but vanilla Box_Base has no quantity stack.
// Source Found: DayZExpansion/DayZExpansion/Market/Scripts/4_World/DayZExpansion_Market/Entities/Items/ExpansionMoneyBase.c:59-68

modded class NailBox
{
	override bool HasQuantity()
	{
		return true;
	}

	override float GetQuantity()
	{
		return 1;
	}
}
