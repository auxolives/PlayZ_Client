# Expansion in-game HUD

Nametag stack, HUD visibility gates, and overlay layers. **PlayZUI does not own this surface** — PlayZExpansion loads after PlayZUI.

## Expansion_CanShowHUDElements

Authoritative gate on `IngameHud`:

**Source Found:** `DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/ingamehud.c:26-56`

Returns false when:
- Player not alive or unconscious (42-43)
- `g_Game.GetUIManager().GetMenu()` non-null — **any menu open** (39-40)
- `#ifdef EXPANSIONUI`: Expansion ScriptView menu open (41-44)
- HUD visibility flags: `HUD_DISABLE`, `MENU_OPEN`, `INVENTORY_OPEN` (48-52)

Base stub on `Hud` always returns true:

**Source Found:** `DayZExpansion/Core/Scripts/3_Game/DayZExpansion_Core/hud.c:15-17`

### Consumers

| Feature | File |
|---------|------|
| NV / earplugs HUD | `Scripts/.../GUI/Hud/IngameHud.c:311-321` |
| NameTags update | `NameTags/.../IngameHud.c:584-597` |
| Navigation 3D markers | `Navigation/.../Expansion3DMarker.c:156` |
| Groups party HUD | `Groups/.../IngameHud.c:112` |

---

## IngameHud modded-class stack

| Order | Module | File | Role |
|-------|--------|------|------|
| 1 | Vanilla | `scripts/5_Mission/GUI/IngameHud.c` | Base HUD |
| 2 | Core | `Core/.../ingamehud.c` | Visibility gate |
| 3 | Scripts | `Scripts/.../GUI/Hud/IngameHud.c` | NV, earplugs panel, HUD colors |
| 4 | NameTags | `NameTags/.../IngameHud.c` | Floating tags |
| 5 | Navigation | `Navigation/.../IngameHud.c` | Map/minimap HUD |
| 6 | Groups | `Groups/.../IngameHud.c` | Party HUD |
| 7 | AI | `AI/.../IngameHud.c` | Aggression cooldown |
| 8 | Terje* | respective mods | Badges/notifiers |
| 9 | **PlayZExpansion** | `PlayZExpansion/scripts/5_Mission/IngameHud.c` | Terje names + hide AI cooldown |

Each layer calls `super.Init(hud_panel_widget)`.

---

## NameTags module

### Init

**Source Found:** `DayZExpansion/NameTags/Scripts/5_Mission/DayZExpansion_NameTags/GUI/Hud/IngameHud.c:54-66`

Loads `NameTagsSettings`, creates `DayZExpansion/NameTags/GUI/layouts/expansion_hud_player_tag.layout`.

### Show logic

- `Expansion_ShouldShowPlayerTag` — distance, LOS, alive (109+)
- `Expansion_SetPlayerTag` — icon + text alpha fade (488-513)
- Default name: `GetIdentityName()` (348)

### Update gate

**Source Found:** `DayZExpansion/NameTags/Scripts/5_Mission/DayZExpansion_NameTags/GUI/Hud/IngameHud.c:580-597`

Clears tags when `!Expansion_CanShowHUDElements()` — pause menu hides nametags.

### Profile settings

`$profile:ExpansionMod/Settings/NameTagsSettings.json` — `EnablePlayerTags` must be on for Sakhal nametags.

**Source Found:** `.cursor/docs/ENGINE_TRUTH.md:362`

---

## Expansion Scripts HUD layer

**Source Found:** `DayZExpansion/Scripts/5_Mission/DayZExpansion/GUI/Hud/IngameHud.c:60-99`

- NV overlay panel
- Earplugs panel (gated by `EnableEarPlugs` in GeneralSettings)
- Custom HUD colors when `UseHUDColors` enabled (280-308)

Distinct from PlayZCore earplugs flash overlay — both can coexist.

---

## PlayZExpansion bridges

**Source Found:** `PlayZ_Client/PlayZExpansion/scripts/5_Mission/IngameHud.c:5-73`

| Override | Behavior |
|----------|----------|
| `Expansion_ShouldShowPlayerTag` | `super` first; Terje face-cover gating |
| `Expansion_SetPlayerTag` | Terje character name via `PlayZExpansionTerjeNameUI` |
| `Expansion_ShowAggressionCooldown` | Always false — hide AI cooldown HUD |
| `Expansion_IsAggressionCooldownVisible` | Always false |

Helper: `PlayZExpansionTerjeNameUI.c` — RPC `tss.name.req`, mode gating.

**Source Found:** `PlayZ_Client/PlayZExpansion/scripts/5_Mission/PlayZExpansionTerjeNameUI.c:4-90`

Corpse cursor: `ActionTargetsCursor.c:6-61`.

---

## PlayZUI rule

Do **not** add `modded class IngameHud` in PlayZUI. HUD/nametag work belongs in PlayZExpansion.

**Source Found:** `PlayZ_Client/PlayZUI/README.md:27`

## Related docs

- [07-bridge-patterns-conflicts.md](07-bridge-patterns-conflicts.md)
- [../playz/02-sibling-modules.md](../playz/02-sibling-modules.md)
- [../vanilla/06-screen-ingame-menu.md](../vanilla/06-screen-ingame-menu.md)
