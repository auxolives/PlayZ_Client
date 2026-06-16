//! Push rad-buffer NetSync immediately after admin/COT sets accumulated dose (client PPE reads synch, not server-only stats).

modded class TerjeAdmintoolSupport_PlayerStat_RadiationAccum
{
	override void SetValue(PlayerBase player, float value)
	{
		super.SetValue(player, value);

		if (player && GetGame().IsServer())
		{
			player.UpdateTerjeRadiationAccumulated();
		}
	}
}
