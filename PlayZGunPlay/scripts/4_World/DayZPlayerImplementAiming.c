// Appends PlayZ filters to sGunplay's aiming pipeline:
//   - AimingModelFilterVegetation    : aim disruption when inside bushes/trees
//   - AimingModelFilterADSEntryOffset: random offset on ADS entry, decays to zero
// All other aiming logic (inertia, sway, recoil, ADS FOV, deadzone) is handled by sGunplay.
modded class DayZPlayerImplementAiming
{
    override protected void registerFilters()
    {
        super.registerFilters();
        registerFilter(new AimingModelFilterVegetation(this));
        registerFilter(new AimingModelFilterADSEntryOffset(this));
    }
}
