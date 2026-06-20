modded class InediaInfectedAI_IrritantsManager
{
	override static float GetInfectedDamageToIrritantingItem(ZombieBase zmb, ItemBase item)
	{
		if (item && (item.IsInherited(Flashlight_IR) || item.IsInherited(UniversalLight_IR) || item.IsInherited(TLRLight_IR)))
		{
			return GetInfectedDamageToIrritant(zmb, InediaInfectedAI_Irritants.HEADTORCHRED_VISUAL);
		}

		return super.GetInfectedDamageToIrritantingItem(zmb, item);
	}
}
