modded class Flashlight_IR
{
	override void InediaInfectedAI_IrritationAction()
	{
		InediaInfectedAI_IrritantsManager.MassSearchActivation(GetPosition(), GetPosition(), InediaInfectedAI_Irritants.HEADTORCHRED_VISUAL, this);
	}
}
