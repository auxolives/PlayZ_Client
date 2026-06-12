# Load order and conflict matrix

Merged conflict rules for PlayZUI milestone 2. Combines vanilla extension points, PlayZ sibling patches, Terje, and Expansion layers.

## Load order (authoritative)

### Within `@PlayZ_Client`

```text
PlayZCore → PlayZGunPlay → PlayZTerje* → PlayZUI → PlayZExpansion
```

**Source Found:** `PlayZ_Client/PlayZUI/README.md:9-19`

### Third-party stack (abbreviated)

```text
… TerjeStartScreen · DayZ-Expansion-* · … · PlayZUI · PlayZExpansion
```

PlayZUI `requiredAddons[]`:

**Source Found:** `PlayZ_Client/PlayZUI/config.cpp:8-15`

- `TerjeCore`, `TerjeStartScreen`
- `DayZExpansion_Core_Scripts`, `DayZExpansion_Scripts`

---

## Conflict matrix

| # | Surface | Mods involved | Resolution |
|---|---------|---------------|------------|
| 1 | `MainMenu.Init` | Expansion Core + Scripts → PlayZUI | `super.Init()` first; preserve `dayz_logo`, `*_button_image`, `version` |
| 2 | `InGameMenu.Init` | Expansion Core + Scripts → PlayZUI | `super.Init()`; preserve death-screen widgets, `server_info`, `ModdedWarning` |
| 3 | `OptionsMenu.Init` / tabs | Expansion → PlayZGunPlay → PlayZUI | EXPANSION tab added before sUDE hide; do not reorder tabs blindly |
| 4 | `LoadingScreen` ctor | Expansion → PlayZUI | Keep `ImageLogoMid/Corner`, `LoadingBar` widget names |
| 5 | `LogoutMenu` layout | PlayZCore → PlayZUI | Keep `txtLogoutTime`, `txtDescription`, `bLogoutNow`, `bCancel` |
| 6 | `IngameHud` | Expansion stack → Terje* → PlayZExpansion | **PlayZUI must not** touch nametags |
| 7 | `Expansion_CanShowHUDElements` | Expansion Core | Pause menu hides HUD elements via `GetMenu()!=null` |
| 8 | Terje names vs Expansion identity | NameTags, chat, killfeed, P2P, cursor | PlayZExpansion bridges — see expansion doc |
| 9 | AI aggression cooldown HUD | Expansion AI → PlayZExpansion | PlayZExpansion forces hidden |
| 10 | Earplugs overlay | PlayZCore vs any menu | Blocked when `GetMenu() != null` |
| 11 | `ExpansionGlobalChatModule` | PlayZ full override vs Expansion updates | Diff upstream on Expansion upgrade |
| 12 | ScriptView vs pause | Expansion MissionGameplay | ScriptView open blocks `Pause()` |
| 13 | Terje Start Screen | Terje → PlayZUI | Layout-only `GetNativeLayout()` — preserve RPC flow |
| 14 | Symbol winner | Reference mod vs PlayZ | **PlayZ wins** on conflicts |

---

## Per-class resolution detail

### LogoutMenu

```
Vanilla Init() binds widgets
  → PlayZCore UpdateInfo/Update (ACL)
    → PlayZUI custom layout (widget names must match)
```

PlayZUI must **not** override `UpdateInfo`/`Update` without coordinating with PlayZCore.

**Source Found:** `PlayZ_Client/PlayZCore/scripts/5_Mission/gui/LogoutMenu_AntiCombatLog.c:5-72`
**Source Found:** `scripts/5_Mission/GUI/LogoutMenu.c:45-52`

### OptionsMenu

```
Vanilla Init() + tabs
  → Expansion AddTab("EXPANSION")
    → PlayZGunPlay hide last tab (sUDE)
      → PlayZUI custom shell (super.Init() required)
```

**Source Found:** `DayZExpansion/.../OptionsMenu.c:23-30`
**Source Found:** `PlayZ_Client/PlayZGunPlay/.../OptionsMenu.c:12-32`

### IngameHud

PlayZUI scope: **none**. Chain:

```
Vanilla → Expansion Core gate → Expansion Scripts (NV/earplugs)
  → NameTags → … → TerjeMedicine → PlayZExpansion (nametags)
```

**Source Found:** `PlayZ_Client/PlayZExpansion/scripts/5_Mission/IngameHud.c:5-73`

### MissionGameplay

PlayZCore `OnUpdate` runs earplugs + input gates. PlayZUI must not add heavy `MissionGameplay.OnUpdate` logic that blocks the chain.

**Source Found:** `PlayZ_Client/PlayZCore/scripts/5_Mission/MissionGameplay.c:42`

---

## Testing checklist (post milestone 2)

1. Main menu: Expansion logo + PlayZ layout + version string
2. Pause: death screen + news feed toggles from GeneralSettings
3. Options: EXPANSION tab visible; sUDE tab hidden; Apply works
4. Loading: progress bar + logos on both LoadingScreen paths
5. Logout: ACL text + button lock in all penalty states
6. Earplugs: toggle works in-world; blocked on pause
7. Nametags: Terje names per mode; hidden on ESC
8. Terje Start Screen: pages advance; RPC flow intact after layout reskin

---

## Related docs

- [01-playzcore-ui.md](01-playzcore-ui.md)
- [02-sibling-modules.md](02-sibling-modules.md)
- [../BRIDGES.md](../BRIDGES.md)
- [../expansion/07-bridge-patterns-conflicts.md](../expansion/07-bridge-patterns-conflicts.md)
