# PlayZ sibling modules — UI inventory

Every `CreateWidgets`, `modded class *Menu`, and `modded class IngameHud` under `PlayZ_Client/` **except PlayZUI itself**. Verified via workspace grep.

Mod load order within `@PlayZ_Client`:

```text
… PlayZCore · PlayZGunPlay · PlayZTerje* · PlayZUI · PlayZExpansion
```

**Source Found:** `PlayZ_Client/PlayZUI/README.md:9-19`

---

## Summary counts

| Pattern | Count | Notes |
|---------|-------|-------|
| `CreateWidgets` | 2 | PlayZCore earplugs, PlayZTerjeSkills tooltip helper |
| `modded class *Menu` | 3 | LogoutMenu, OptionsMenu, InspectMenuNew |
| `modded class IngameHud` | 2 | PlayZExpansion, PlayZTerjeMedicine |
| PlayZ-owned `.layout` | 1 | `PlayZCore/gui/earplugs.layout` |

PlayZUI has no mission scripts yet — only `PlayZUIPaths.c`.

**Source Found:** `PlayZ_Client/PlayZUI/scripts/3_Game/PlayZUIPaths.c:1-4`

---

## PlayZCore

| File | Class | Override | PlayZUI impact |
|------|-------|----------|----------------|
| `PlayZCore/scripts/5_Mission/EarPlugsWidget.c` | `EarPlugsWidget` | — | Workspace overlay — independent of menus |
| `PlayZCore/scripts/5_Mission/gui/LogoutMenu_AntiCombatLog.c` | `LogoutMenu` | `UpdateInfo`, `Update` | Preserve logout widget names |
| `PlayZCore/scripts/5_Mission/MissionGameplay.c` | `MissionGameplay` | `OnInit`, `OnUpdate` | Do not block; `GetMenu()` gates |

**Source Found:** see [01-playzcore-ui.md](01-playzcore-ui.md)

---

## PlayZExpansion (loads after PlayZUI)

### IngameHud.c

| Field | Value |
|-------|-------|
| Path | `PlayZ_Client/PlayZExpansion/scripts/5_Mission/IngameHud.c` |
| Overrides | `Expansion_ShouldShowPlayerTag`, `Expansion_SetPlayerTag`, `Expansion_ShowAggressionCooldown`, `Expansion_IsAggressionCooldownVisible` |

**Source Found:** `PlayZ_Client/PlayZExpansion/scripts/5_Mission/IngameHud.c:5-73`

- Terje character names on floating nametags via `PlayZExpansionTerjeNameUI`
- Suppresses Expansion AI aggression cooldown HUD

### ActionTargetsCursor.c

| Field | Value |
|-------|-------|
| Path | `PlayZ_Client/PlayZExpansion/scripts/5_Mission/ActionTargetsCursor.c` |
| Override | `GetItemDesc(ActionBase action)` |

**Source Found:** `PlayZ_Client/PlayZExpansion/scripts/5_Mission/ActionTargetsCursor.c:6-61`

Dead-player corpse cursor text — Terje name or empty per face-cover rules.

### PlayZExpansionTerjeNameUI.c

Static client helper — RPC `tss.name.req`, gating via `STARTSCREEN_DISPLAY_PLAYER_NAMES_MODE`.

**Source Found:** `PlayZ_Client/PlayZExpansion/scripts/5_Mission/PlayZExpansionTerjeNameUI.c:4-90`

### Server-side text surfaces (no widgets)

| File | Override |
|------|----------|
| `ExpansionGlobalChatModule.c` | `AddChatMessage_Server` |
| `ExpansionKillfeedModule.c` | `GetIdentityName` |
| `ExpansionP2PMarketListing.c` | `SetFromItem` |

**Source Found:** respective files under `PlayZ_Client/PlayZExpansion/scripts/4_World/`

---

## PlayZGunPlay

### OptionsMenu.c

| Field | Value |
|-------|-------|
| Path | `PlayZ_Client/PlayZGunPlay/scripts/5_Mission/sUDE/gui/optionsMenu/OptionsMenu.c` |
| Override | `Init()` |
| Action | Hides last tab (sUDE) — `Tab_Control_N`, `Tab_N` |

**Source Found:** `PlayZ_Client/PlayZGunPlay/scripts/5_Mission/sUDE/gui/optionsMenu/OptionsMenu.c:3-37`

PlayZUI options must chain `super.Init()`.

### sCrosshair.c

**Source Found:** `PlayZ_Client/PlayZGunPlay/scripts/5_Mission/sUDE/gui/sCrosshair.c:1-13`

`modded class SCrosshair` — respects `GetWorld().IsCrosshairDisabled()` before sGunplay logic.

### scoanimationlogo.c

**Source Found:** `PlayZ_Client/PlayZGunPlay/scripts/3_Game/scoanimationlogo.c:3-6`

Disables sFramework logo animation — no PlayZUI interaction.

---

## PlayZTerjeSkills

### TerjeSkillWidget.c

| Field | Value |
|-------|-------|
| Path | `PlayZ_Client/PlayZTerjeSkills/scripts/5_mission/TerjeSkillWidget.c` |
| Overrides | `OnResetSkillModalDialogResult`, `OnPerkMouseUp`, `OnPerkMouseDown`, `Refresh` |
| Widgets | `terje_perk_highlight`, `terje_skill_header_points` |

**Source Found:** `PlayZ_Client/PlayZTerjeSkills/scripts/5_mission/TerjeSkillWidget.c:1-78`

Hides per-skill points label; aggregates into container header with `#STR_PLAYZ_GLOBAL_PTS_LABEL`.

### PlayZTerjeSkillTooltip.c

**Source Found:** `PlayZ_Client/PlayZTerjeSkills/scripts/5_mission/PlayZTerjeSkillTooltip.c:1-68`

`CreateWidgets` on `TerjeSkills/Layouts/TerjeSkillTooltip.layout` — **not yet hooked** to vanilla Terje tooltip factory (no `modded class TerjeSkillTooltip`).

---

## PlayZTerjeMedicine

### IngameHud.c

**Source Found:** `PlayZ_Client/PlayZTerjeMedicine/scripts/5_mission/IngameHud.c:1-16`

Suppresses `"TerjeMind"` notifier and `"TerjeVacinaC"` badge registration.

### MissionGameplay.c

**Source Found:** `PlayZ_Client/PlayZTerjeMedicine/scripts/5_mission/MissionGameplay.c:1-7`

`OnUpdateTerjeCustomBadges` pass-through to super.

### pperequester_terjemedsleeping.c

**Source Found:** `PlayZ_Client/PlayZTerjeMedicine/scripts/3_game/pperequester_terjemedsleeping.c:1-36`

Drives `PlayZEarPlugsGate` during Terje sleep — audio bridge, not widget.

---

## PlayZTerjeRadiation

### InspectMenuNew.c

**Source Found:** `PlayZ_Client/PlayZTerjeRadiation/scripts/5_Mission/InspectMenuNew.c:5-174`

`modded class InspectMenuNew` — rad protection/contamination on `ItemFoodStageWidget`, `ItemCleannessWidget`.

### ItemManager.c

**Source Found:** `PlayZ_Client/PlayZTerjeRadiation/scripts/5_Mission/ItemManager.c:1-21`

`PrepareTooltip` override for hover tooltip refresh.

### MissionGameplay.c

**Source Found:** `PlayZ_Client/PlayZTerjeRadiation/scripts/5_Mission/MissionGameplay.c:1-94`

Dosimeter tooltip refresh + radioactive rain PPE (fullscreen, not widget).

---

## Ambient overlays (PPE only — no PlayZUI conflict)

| Module | File | UI relevance |
|--------|------|--------------|
| PlayZWeather | `PlayZWeather/scripts/5_Mission/MissionGameplay.c` | Weather PPE only |
| PlayZSakhal | `PlayZSakhal/scripts/5_Mission/MissionGameplay.c` | Hypoxia PPE only |

---

## CreateWidgets inventory

| # | File | Line | Layout | Parent |
|---|------|------|--------|--------|
| 1 | `PlayZCore/.../EarPlugsWidget.c` | 9 | `PlayZCore/gui/earplugs.layout` | workspace root |
| 2 | `PlayZTerjeSkills/.../PlayZTerjeSkillTooltip.c` | 22 | `TerjeSkills/Layouts/TerjeSkillTooltip.layout` | `ItemManager.GetTerjeSkillsRoot()` |

---

## modded class *Menu inventory

| File | Class | Overrides |
|------|-------|-----------|
| `PlayZCore/.../LogoutMenu_AntiCombatLog.c` | `LogoutMenu` | `UpdateInfo`, `Update` |
| `PlayZGunPlay/.../OptionsMenu.c` | `OptionsMenu` | `Init` |
| `PlayZTerjeRadiation/.../InspectMenuNew.c` | `InspectMenuNew` | `SetItem` |

## Related docs

- [01-playzcore-ui.md](01-playzcore-ui.md)
- [03-load-order-conflicts.md](03-load-order-conflicts.md)
- [../expansion/07-bridge-patterns-conflicts.md](../expansion/07-bridge-patterns-conflicts.md)
