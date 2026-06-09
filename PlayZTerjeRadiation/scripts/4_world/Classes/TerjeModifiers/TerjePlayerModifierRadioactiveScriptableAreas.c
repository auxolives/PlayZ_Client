modded class TerjePlayerModifierRadioactiveScriptableAreas
{
	override void OnServerFixedTick(PlayerBase player, float deltaTime)
	{
		if (!player.GetAllowDamage())
		{
			return;
		}

		PluginTerjeScriptableAreas plugin = GetTerjeScriptableAreas();
		if (!plugin)
		{
			return;
		}

		float playerRadiation = player.GetTerjeRadiation();
		float environmentRadiation = plugin.PlayZGetEnvironmentRadiationWithRain(player);

		float nearestRadiationRadius = GetTerjeSettingFloat(TerjeSettingsCollection.RADIATION_NEAREST_TRANSFER_RADIUS);
		if (nearestRadiationRadius > 0)
		{
			float nearestRadiationThreshold = GetTerjeSettingFloat(TerjeSettingsCollection.RADIATION_NEAREST_TRANSFER_THRESHOLD);
			float nearestRadiationValue = plugin.CalculateTerjeRadiationFromNearestEntities(player, nearestRadiationRadius, true);
			if (nearestRadiationValue * nearestRadiationThreshold > environmentRadiation)
			{
				environmentRadiation = nearestRadiationValue * nearestRadiationThreshold;
			}
		}

		if (environmentRadiation > 0)
		{
			float radioactiveGlobalModifier = GetTerjeSettingFloat(TerjeSettingsCollection.RADIATION_AREAS_POWER_MOD);
			float rAmount = environmentRadiation * radioactiveGlobalModifier;
			float maxAccumulatedRadLimit = rAmount * GetTerjeSettingFloat(TerjeSettingsCollection.RADIATION_ZONE_POWER_TO_RAD_LIMIT);
			if (playerRadiation < maxAccumulatedRadLimit)
			{
				float rIncrement = Math.Clamp(rAmount * deltaTime, 0, maxAccumulatedRadLimit - playerRadiation);
				player.AddTerjeRadiationAdvanced(rIncrement, environmentRadiation, false);
			}

			ConsumeGasMaskFilterQuantity(player, environmentRadiation, deltaTime);
		}

		if (GetTerjeSettingBool(TerjeSettingsCollection.RADIATION_TRANSFER_WITH_PARENT))
		{
			float transferThreshold = GetTerjeSettingFloat(TerjeSettingsCollection.RADIATION_TRANSFER_THRESHOLD);
			float transferAmount = GetTerjeSettingFloat(TerjeSettingsCollection.RADIATION_TRANSFER_PER_SECOND) * deltaTime;

			ItemBase attachment;
			playerRadiation = player.GetTerjeRadiation();
			int attCount = player.GetInventory().AttachmentCount();
			for (int attIdx = 0; attIdx < attCount; attIdx++)
			{
				if (ItemBase.CastTo(attachment, player.GetInventory().GetAttachmentFromIndex(attIdx)) && attachment)
				{
					TransferRadiationWithEntity(player, attachment, playerRadiation, transferThreshold, transferAmount);
				}
			}

			ItemBase inHands = player.GetItemInHands();
			if (inHands != null)
			{
				TransferRadiationWithEntity(player, inHands, playerRadiation, transferThreshold, transferAmount);
			}

			EntityAI parent = EntityAI.Cast(player.GetParent());
			if (parent != null)
			{
				TransferRadiationWithEntity(player, parent, playerRadiation, transferThreshold, transferAmount);
			}
		}
	}
}
