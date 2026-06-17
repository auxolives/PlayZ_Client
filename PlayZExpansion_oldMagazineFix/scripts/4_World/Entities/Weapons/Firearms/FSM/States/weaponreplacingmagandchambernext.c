modded class DetachOldMagazine
{
	override void OnExit(WeaponEventBase e)
	{
		if (!e || !e.m_player)
		{
			m_weapon.HideMagazine();
			m_oldMagazine = NULL;
			m_newDst = NULL;
			super.OnExit(e);
			return;
		}

		if (m_oldMagazine)
		{
			InventoryLocation oldSrc = new InventoryLocation();
			bool hasCurrentLocation = m_oldMagazine.GetInventory().GetCurrentInventoryLocation(oldSrc);

			if (!hasCurrentLocation || !oldSrc.IsValid())
			{
				e.m_player.GetInventory().ClearInventoryReservationEx(m_oldMagazine, null);
				ErrorEx("[PlayZExpansion_oldMagazineFix] DetachOldMagazine::OnExit - skipping invalid old magazine location for " + Object.GetDebugName(m_oldMagazine), ErrorExSeverity.WARNING);
			}
			else
			{
				bool shouldDrop = !m_newDst || !m_newDst.IsValid() || m_newDst.GetType() == InventoryLocationType.GROUND;
				if (shouldDrop)
				{
					if (DayZPlayerUtils.HandleDropMagazine(e.m_player, m_oldMagazine))
					{
						if (LogManager.IsWeaponLogEnable()) { wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " DetachOldMagazine, guarded path - dropped old magazine to ground"); }
					}
					else
					{
						ErrorEx("[PlayZExpansion_oldMagazineFix] DetachOldMagazine::OnExit - drop failed for " + Object.GetDebugName(m_oldMagazine), ErrorExSeverity.WARNING);
					}
				}
				else
				{
					if (GameInventory.LocationSyncMoveEntity(oldSrc, m_newDst))
					{
						if (LogManager.IsWeaponLogEnable()) { wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " DetachOldMagazine, guarded path - moved old magazine"); }
					}
					else
					{
						ErrorEx("[PlayZExpansion_oldMagazineFix] DetachOldMagazine::OnExit - move failed from " + ExpansionStatic.DumpToString(oldSrc) + " to " + ExpansionStatic.DumpToString(m_newDst), ErrorExSeverity.WARNING);
					}
				}
			}
		}

		m_weapon.HideMagazine();
		m_oldMagazine = NULL;
		m_newDst = NULL;
		super.OnExit(e);
	}
}
