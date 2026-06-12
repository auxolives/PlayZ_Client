# PlayZCore UI surface

PlayZCore ships client UI behavior that **must keep working** after PlayZUI layout rewrites. PlayZCore loads **before** PlayZUI in the `@PlayZ_Client` chain.

**Source Found:** `PlayZ_Client/PlayZUI/README.md:9-19`

## Overview

| Feature | Owner | PlayZUI rule |
|---------|-------|--------------|
| Earplugs HUD flash overlay | PlayZCore | Do not block `MissionGameplay.OnUpdate` or earplugs input |
| Anti-combat logout text/button lock | PlayZCore | Preserve logout layout widget names |
| Custom input actions | PlayZCore | Visible in keybindings — no PlayZUI change needed |
| Stringtable ACL keys | PlayZCore | Referenced by logout patch |

---

## Earplugs overlay

### EarPlugsWidget

Standalone helper — not a `modded class`. Creates a workspace-root overlay independent of menu layouts.

| Field | Value |
|-------|-------|
| Script | `PlayZ_Client/PlayZCore/scripts/5_Mission/EarPlugsWidget.c` |
| Layout | `PlayZ_Client/PlayZCore/gui/earplugs.layout` |
| Widget | `icon` (`ImageWidgetClass`) |

**Source Found:** `PlayZ_Client/PlayZCore/scripts/5_Mission/EarPlugsWidget.c:1-56`
**Source Found:** `PlayZ_Client/PlayZCore/gui/earplugs.layout:1-15`

Constructor calls `CreateWidgets` on workspace root (line 9). `SetIcon(imagePath)` loads `.edds` and fades alpha via GUI call queue.

### Icon assets (runtime)

| State | Volume | Icon path |
|-------|--------|-----------|
| 0→1 | 0.50 | `PlayZ_Client/PlayZCore/gui/volume_mid.edds` |
| 1→2 | 0.25 | `PlayZ_Client/PlayZCore/gui/volume_low.edds` |
| 2→3 | 0.05 | `PlayZ_Client/PlayZCore/gui/volume_off.edds` |
| 3→0 | 1.0 | `PlayZ_Client/PlayZCore/gui/volume_full.edds` |

**Source Found:** `PlayZ_Client/PlayZCore/scripts/5_Mission/MissionGameplay.c:44-67`

### MissionGameplay integration

**Source Found:** `PlayZ_Client/PlayZCore/scripts/5_Mission/MissionGameplay.c:1-334`

- `OnInit()` constructs `m_earplugswidget = new EarPlugsWidget()` (line 19)
- `OnUpdate()` handles `UAEarPlugsToggle` when `GetMenu() == NULL` (line 42)
- Gate also checks `PlayZEarPlugsGate.IsSleepingDeafnessActive()` (Terje sleep PPE bridge)

### GetMenu() gate

Earplugs toggle is blocked while any menu is open (pause, inventory, etc.):

```c
if (GetGame().GetUIManager().GetMenu() == NULL)
```

**Source Found:** `PlayZ_Client/PlayZCore/scripts/5_Mission/MissionGameplay.c:42`

PlayZUI custom menus must use standard `UIManager` open/close — do not leave stale menu references.

### PlayZEarPlugsGate (Terje bridge)

**Source Found:** `PlayZ_Client/PlayZCore/scripts/3_Game/PlayZEarPlugsGate.c:5-18`

Called from `PlayZTerjeMedicine/.../pperequester_terjemedsleeping.c` during Terje sleep PPE — suppresses earplugs toggle while sleeping deafness is active.

### Expansion earplugs (separate system)

Expansion adds its own earplugs HUD panel on `IngameHud` — different from PlayZCore flash overlay:

**Source Found:** `DayZExpansion/DayZExpansion/Scripts/5_Mission/DayZExpansion/GUI/Hud/IngameHud.c:78`

Both coexist; PlayZUI does not own either.

---

## Anti-combat logout

### LogoutMenu_AntiCombatLog

| Field | Value |
|-------|-------|
| Script | `PlayZ_Client/PlayZCore/scripts/5_Mission/gui/LogoutMenu_AntiCombatLog.c` |
| Class | `modded class LogoutMenu` |
| Overrides | `UpdateInfo()`, `Update(float timeslice)` only — **not** `Init()` |

**Source Found:** `PlayZ_Client/PlayZCore/scripts/5_Mission/gui/LogoutMenu_AntiCombatLog.c:1-73`

Uses protected members set in vanilla `Init()`:
- `m_DescriptionText` ← layout `txtDescription`
- `m_bLogoutNow` ← layout `bLogoutNow`

**Source Found:** `scripts/5_Mission/GUI/LogoutMenu.c:49-52`

### ACL behavior

When `WillBePunishedForCombatLogging()` returns non-zero:

| Value | String key | Line |
|-------|------------|------|
| 3 | `#STR_PlayZ_ACL_LogoutNote_Extended` | 30 |
| 1 | `#STR_PlayZ_ACL_LogoutNote_Killed` | 36 |
| else | `#STR_PlayZ_ACL_LogoutNote_Flare` | 40 |

- Description text red: `ARGB(255,255,0,0)` (line 44)
- `m_bLogoutNow` hidden until `GetDisableExitButtonSecs()` timer (lines 20-24, 46)

### PlayZUI layout contract

Custom `day_z_logout_dialog` layout **must keep** widget names:
- `txtLogoutTime`
- `txtDescription`
- `bLogoutNow`
- `bCancel`

See [vanilla/07-screen-logout-menu.md](../vanilla/07-screen-logout-menu.md).

---

## Inputs

**Source Found:** `PlayZ_Client/PlayZCore/inputs.xml:1-25`
**Source Found:** `PlayZ_Client/PlayZCore/config.cpp:26`

| Action | Default | String key |
|--------|---------|------------|
| `UAEarPlugsToggle` | N | `STR_PlayZ_EarPlugs_Keybind` |
| `UAEmoteLyingDown` | V | `STR_PlayZ_EmoteLyingDown_Keybind` |
| `UATakeBackpackToHands` | B | `STR_PlayZ_BackpackToHands_Keybind` |
| `UATakeMouthBlockerToHands` | M | `STR_PlayZ_MouthBlocker_Keybind` |

Unrelated to menu rework; documented for keybindings screen awareness.

---

## Stringtable

**Source Found:** `PlayZ_Client/PlayZCore/stringtable.csv:2-9`

| Key | Used by |
|-----|---------|
| `STR_PlayZ_EarPlugs_Keybind` | inputs.xml |
| `STR_PlayZ_EmoteLyingDown_Keybind` | inputs.xml |
| `STR_PlayZ_BackpackToHands_Keybind` | inputs.xml |
| `STR_PlayZ_MouthBlocker_Keybind` | inputs.xml |
| `STR_PlayZ_ACL_LogoutNote_Killed` | LogoutMenu_AntiCombatLog |
| `STR_PlayZ_ACL_LogoutNote_Flare` | LogoutMenu_AntiCombatLog |
| `STR_PlayZ_ACL_LogoutNote_Extended` | LogoutMenu_AntiCombatLog |

---

## PlayZUI compatibility checklist

- [ ] Do not override `LogoutMenu.Init()` without re-binding ACL widget names
- [ ] Do not block `MissionGameplay.OnUpdate` in PlayZUI scripts
- [ ] Earplugs overlay is workspace-level — independent of menu layout swaps
- [ ] Test earplugs toggle with pause menu open (should be blocked)
- [ ] Test ACL logout states after custom logout layout

## Related docs

- [02-sibling-modules.md](02-sibling-modules.md)
- [03-load-order-conflicts.md](03-load-order-conflicts.md)
- [../BRIDGES.md](../BRIDGES.md)
