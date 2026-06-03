modded class ShelterBase
{
	override void Deconstruct()
	{
		// PlayZ: Custom material spawning for 100% return with proportional health
		SpawnFullConstructionMaterialPiles(this, null, GetMaterialPath(), GetShelterVariant());
		SpawnKit();
		Delete();
	}

	// Custom implementation based on StaticConstructionMethods.SpawnConstructionMaterialPiles
	// Modified to return 100% quantity regardless of damage level
	void SpawnFullConstructionMaterialPiles(notnull EntityAI entity, Man player, string cfg_path, string main_part_name, string damagezone_name = "", bool is_base = false)
	{
		int	child_count = GetGame().ConfigGetChildrenCount(cfg_path);
		
		for (int i = 0; i < child_count; i++)
		{
			string child_name;
			GetGame().ConfigGetChildName(cfg_path, i, child_name);
			
			// Get type, quantity from material config
			string config_path;
			string type;
			string slot_name;
			config_path = cfg_path + " " + child_name + " " + "type";
			GetGame().ConfigGetText(config_path, type);
			config_path = cfg_path + " " + child_name + " " + "slot_name";
			GetGame().ConfigGetText(config_path, slot_name);
			config_path = cfg_path + " " + child_name + " " + "quantity";
			float quantity = GetGame().ConfigGetFloat(config_path);
			config_path = cfg_path + " " + child_name + " " + "lockable";
			bool lockable = GetGame().ConfigGetInt(config_path);
			
			// Handle lockable items (like attachments that might be locked)
			ItemBase attachment = ItemBase.Cast(entity.FindAttachmentBySlotName(slot_name));
			
			if (lockable)
			{
				if (attachment)
				{
					InventoryLocation src = new InventoryLocation;
					attachment.GetInventory().GetCurrentInventoryLocation(src);
					entity.GetInventory().SetSlotLock(src.GetSlot(), false);
					
					if (is_base)
					{
						if (GetGame().IsMultiplayer() && player)
						{
							InventoryLocation dst = new InventoryLocation;
							GameInventory.SetGroundPosByOwner(player, src.GetItem(), dst);
							if (dst && dst.IsValid())
							{
								if (!player.ServerTakeToDst(src, dst))
								{
									Print("[PlayZ][1.29] Shelter deconstruct transfer failed: item=" + src.GetItem() + " slot=" + src.GetSlot() + " parent=" + entity);
									entity.GetInventory().DropEntity(InventoryMode.SERVER, entity, attachment);
								}
							}
							else
							{
								Print("[PlayZ][1.29] Shelter deconstruct invalid destination: item=" + src.GetItem() + " slot=" + src.GetSlot() + " parent=" + entity);
								entity.GetInventory().DropEntity(InventoryMode.SERVER, entity, attachment);
							}
						}
						else
						{
							entity.GetInventory().DropEntity(InventoryMode.PREDICTIVE, entity, attachment);
						}
					}
				}
			}
			else
			{
				float pile_health;
				vector destination = entity.GetPosition();
				
				// Handle memory points for material spawning
				if (entity.MemoryPointExists("" + main_part_name + "_materials"))
				{
					destination = entity.GetMemoryPointPos("" + main_part_name + "_materials");
					destination = GetGame().ObjectModelToWorld(entity, destination);
				}
				else if (entity.MemoryPointExists(main_part_name))
				{
					destination = entity.GetMemoryPointPos(main_part_name);
					destination = GetGame().ObjectModelToWorld(entity, destination);
				}
				
				// Calculate material health: proportional to shelter's health
				pile_health = entity.GetHealth01(damagezone_name, "Health") * MiscGameplayFunctions.GetTypeMaxGlobalHealth(type);
				
				// Quantity modification: 100% of the config value is returned.
				// We intentionally ignore Construction.DECONSTURCT_MATERIAL_LOSS (vanilla 20% loss).
				quantity = Math.Max(Math.Floor(quantity), 1);
				
				if (player)
				{
					vector posHead;
					MiscGameplayFunctions.GetHeadBonePos(PlayerBase.Cast(player), posHead);
					MiscGameplayFunctions.CreateItemBasePilesDispersed(type, posHead, destination, UAItemsSpreadRadius.NARROW, quantity, pile_health, player);
				}
				else
				{
					MiscGameplayFunctions.CreateItemBasePiles(type, destination, quantity, pile_health, true);
				}
			}
		}
	}
}
