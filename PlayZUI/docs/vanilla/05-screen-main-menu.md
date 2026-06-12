# Main menu screen

Vanilla PC main menu shell. PlayZUI milestone 2 replaces layout and styling here while preserving widget names consumed by Expansion and mission navigation.

## Class and factory

| Field | Value |
|-------|-------|
| Class | `MainMenu extends UIScriptedMenu` |
| Menu id | `MENU_MAIN` (13) |
| Factory | `MissionBase.CreateScriptedMenu` → `new MainMenu` (PC) |

**Source Found:** `scripts/5_Mission/GUI/NewUI/MainMenu/MainMenu.c:1`
**Source Found:** `scripts/3_Game/constants.c:182` (`MENU_MAIN`)
**Source Found:** `scripts/5_Mission/mission/missionBase.c:191-196` (factory switch)

Console variant: `MainMenuConsole` under `#ifdef PLATFORM_CONSOLE`.

## Init() and layout

**Source Found:** `scripts/5_Mission/GUI/NewUI/MainMenu/MainMenu.c:53-131`

```c
layoutRoot = g_Game.GetWorkspace().CreateWidgets("gui/layouts/new_ui/main_menu.layout");
```

### Required widget names (do not rename)

| Widget name | Member / use | Line |
|-------------|--------------|------|
| `play` | Play button | 57 |
| `choose_server` | Server browser | 58 |
| `customize_character` | Character menu | 59 |
| `settings_button` | Options | 60 |
| `exit_button` | Quit | 61 |
| `version` | Version text | 62 |
| `ModdedWarning` | Modded warning | 63 |
| `character_rotation_frame` | Character preview | 64 |
| `dayz_logo` | Logo (Expansion swaps) | — |
| `tutorial_button_image` | Expansion icon swap | — |
| `message_button_image` | Expansion icon swap | — |
| `settings_button_image` | Expansion icon swap | — |
| `exit_button_image` | Expansion icon swap | — |

Expansion-specific names are consumed by `DayZExpansion/Scripts/.../MainMenu.c` after `super.Init()`.

## Navigation (child menus)

| Action | Target id | Method | Line |
|--------|-----------|--------|------|
| Settings | `MENU_OPTIONS` | `EnterScriptedMenu` | 519–521 |
| Server browser | `MENU_SERVER_BROWSER` | `EnterScriptedMenu` | 434–436 |
| Character | `MENU_CHARACTER` | `EnterScriptedMenu` | 439–441 |
| Tutorials | `MENU_TUTORIAL` | `EnterScriptedMenu` | 534–536 |
| Credits | `MENU_CREDITS` | `EnterScriptedMenu` | 539–542 |
| Video | `MENU_VIDEO` | `EnterScriptedMenu` | 524–526 |

**Source Found:** `scripts/5_Mission/GUI/NewUI/MainMenu/MainMenu.c:434-542`

PlayZUI custom layouts must wire the same button names or re-bind in `modded class MainMenu` after `super.Init()`.

## Mission integration

`MissionMainMenu` owns intro scene and main-menu mission lifecycle.

**Source Found:** `scripts/5_Mission/mission/missionMainMenu.c` (main-menu mission)

`DayZIntroScenePC` drives character preview rotation. Expansion can replace intro scenes when `UseExpansionMainMenuIntroScene` is enabled.

**Source Found:** `DayZExpansion/DayZExpansion/Scripts/5_Mission/DayZExpansion/GUI/Intro/DayZIntroScenePC.c:19-23`

## Expansion override stack

Two Expansion layers patch `MainMenu` after vanilla:

1. **Core** — version text only, `super.Init()` first:

**Source Found:** `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/MainMenu/MainMenu.c:15-19`

2. **Scripts bundle** — logo and button icon swaps gated by `GeneralSettings`:

**Source Found:** `DayZExpansion/DayZExpansion/Scripts/5_Mission/DayZExpansion/GUI/MainMenu/MainMenu.c:15-46`

Settings keys: `UseExpansionMainMenuLogo`, `UseExpansionMainMenuIcons` — see `docs/expansion/05-general-settings-gates.md`.

## PlayZUI bridge rules

1. Always call `layoutRoot = super.Init()` first (or equivalent: load custom layout **then** run sibling logic — prefer `super.Init()` + widget mutation).
2. Preserve widget names in the table above.
3. Do not replace `MissionBase.CreateScriptedMenu` for `MENU_MAIN`.
4. PlayZGunPlay and Expansion load before PlayZUI — their `modded class MainMenu` patches merge into the chain.

## Platform layouts

| Platform | Layout |
|----------|--------|
| PC | `gui/layouts/new_ui/main_menu.layout` |
| Console | `gui/layouts/new_ui/main_menu_console.layout` |
| MS Store | `gui/layouts/new_ui/main_menu_msstore.layout` |

**Source Found:** `scripts/5_Mission/GUI/NewUI/MainMenu/MainMenu.c:55` (PC path)

Sakhal targets PC layout first.

## Related docs

- [02-menu-ids-and-factory.md](02-menu-ids-and-factory.md)
- [docs/expansion/02-menu-overrides.md](../expansion/02-menu-overrides.md)
- [docs/BRIDGES.md](../BRIDGES.md)
