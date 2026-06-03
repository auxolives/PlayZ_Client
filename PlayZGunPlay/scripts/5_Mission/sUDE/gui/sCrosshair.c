modded class SCrosshair {

	protected override bool canShowStaticCrosshair() {
		if (GetGame().GetWorld().IsCrosshairDisabled()) return false;
		return super.canShowStaticCrosshair();
	}

	protected override bool canShowDynamicCrosshair() {
		if (GetGame().GetWorld().IsCrosshairDisabled()) return false;
		return super.canShowDynamicCrosshair();
	}

}
