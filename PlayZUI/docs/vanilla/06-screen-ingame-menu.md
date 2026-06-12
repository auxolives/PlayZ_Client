# In-game menu (pause screen)

ESC pause menu opened during gameplay. PlayZUI reskins this shell; HUD and nametag behavior is governed separately by Expansion and PlayZExpansion.

## Class and factory

| Field | Value |
|-------|-------|
| Class | `InGameMenu extends UIScriptedMenu` |
| Menu id | `MENU_INGAME` (9) |
| Layout | `gui/layouts/day_z_ingamemenu.layout` |

**Source Found:** `scripts/5_Mission/GUI/InGameMenu.c:1`
**Source Found:** `scripts/5_Mission/GUI/InGameMenu.c:36-78` (`Init`)
**Source Found:** `scripts/3_Game/constants.c:178` (`MENU_INGAME`)

Console variant: `InGameMenuXbox` — `missionBase.c:198-203`.

## Init() widget bindings

**Source Found:** `scripts/5_Mission/GUI/InGameMenu.c:38-57`

| Widget | Purpose |
|--------|---------|
| `continuebtn` | Resume game |
| `exitbtn` | Open logout flow |
| `restartbtn` | Restart (when allowed) |
| `respawn_button` | Custom respawn dialogue |
| `optionsbtn` | Open options |
| `ModdedWarning` | Modded warning |
| `server_info` | Server info panel |
| `server_ip`, `server_port`, `server_name` | Server details |
| `feedbackbtn` | Feedback link |
| `dayz_logo`, `Licensing`, `version`, `copyright` | Expansion branding |

### Side effects on open

`Init()` pauses the mission (lines 73–75). Destructor resumes mission and shows HUD (lines 28–34).

## Navigation

| Button | Action | Line |
|--------|--------|------|
| Options | `EnterScriptedMenu(MENU_OPTIONS)` | 251–253 |
| Exit | `CreateLogoutMenu(this)` via call queue | 256–259 |
| Respawn | `EnterScriptedMenu(MENU_RESPAWN_DIALOGUE)` | 240–242 |

**Source Found:** `scripts/5_Mission/GUI/InGameMenu.c:240-259`

Logout path creates `MENU_LOGOUT` as child of this menu — see [07-screen-logout-menu.md](07-screen-logout-menu.md).

## HUD interaction while pause is open

When any menu is open, `GetUIManager().GetMenu()` is non-null. Expansion uses this in `Expansion_CanShowHUDElements`:

**Source Found:** `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/ingamehud.c:39-40`

Effects while pause is open:
- Nametags hidden
- NV / earplugs HUD panels hidden (Expansion Scripts layer)
- PlayZCore earplugs toggle blocked (`GetMenu() == NULL` gate)

**Source Found:** `PlayZ_Client/PlayZCore/scripts/5_Mission/MissionGameplay.c:42`

PlayZUI does **not** own nametag or HUD overlay behavior — see `docs/expansion/03-ingame-hud.md` and `docs/playz/02-sibling-modules.md`.

## Expansion override stack

### Core layer

**Source Found:** `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/InGameMenu.c:27-37`

- `super.Init()` first
- Hides `server_info` when `StreamerMode` enabled
- Overrides `SetGameVersion()` for Expansion version text (49–58)

### Scripts bundle (death screen)

**Source Found:** `DayZExpansion/DayZExpansion/Scripts/5_Mission/DayZExpansion/GUI/InGameMenu/InGameMenu.c:74-147`

- Creates `DayZExpansion/GUI/layouts/ui/expansion_dead_screen.layout` overlay (92–118)
- News feed widget via `ExpansionNewsFeed` (124–129)
- Death fade in `Update()` (314–327)
- Gated by `UseDeathScreen`, `UseNewsFeedInGameMenu` in GeneralSettings

**Critical:** Replacing `Init()` without `super.Init()` silently breaks death screen, news feed, and licensing panel.

## Terje interaction

When player is dead, Terje Start Screen mission logic may open `InGameMenu` + respawn instead of the wizard:

**Source Found:** `TerjeStartScreen/Scripts/5_Mission/MissionGameplay.c:50-58`

PlayZUI pause reskin must not block Terje respawn button wiring on `respawn_button`.

## PlayZUI bridge rules

1. `layoutRoot = super.Init()` first — mandatory for Expansion death UI.
2. Preserve all widget names above.
3. Do **not** add `modded class IngameHud` in PlayZUI — HUD is PlayZExpansion / Terje scope.
4. Test: open pause → nametags disappear → close → nametags return.

## Related docs

- [07-screen-logout-menu.md](07-screen-logout-menu.md)
- [docs/playz/01-playzcore-ui.md](../playz/01-playzcore-ui.md) (earplugs gate)
- [docs/expansion/02-menu-overrides.md](../expansion/02-menu-overrides.md)
- [docs/expansion/03-ingame-hud.md](../expansion/03-ingame-hud.md)
