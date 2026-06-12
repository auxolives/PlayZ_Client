# Menu IDs and Factory

DayZ identifies every scripted menu with an integer `MENU_*` constant defined in `constants.c`. The mission layer (`MissionBase.CreateScriptedMenu`) maps each id to a concrete class. Mods override this factory or individual menu classes to inject custom UI.

## MENU_* constants (shell-relevant subset)

| Constant | Value | Class instantiated |
|----------|-------|-------------------|
| `MENU_MAIN` | 13 | `MainMenu` (PC) / `MainMenuConsole` |
| `MENU_INGAME` | 9 | `InGameMenu` / `InGameMenuXbox` |
| `MENU_OPTIONS` | 14 | `OptionsMenu` |
| `MENU_LOADING` | 12 | `LoadingMenu` |
| `MENU_LOGOUT` | 26 | `LogoutMenu` |
| `MENU_KEYBINDINGS` | 34 | `KeybindingsMenu` |
| `MENU_CONTROLS_PRESET` | 20 | `PresetsMenu` |
| `MENU_STARTUP` | 15 | `StartupMenu` |
| `MENU_TITLE_SCREEN` | 27 | `TitleScreenMenu` |
| `MENU_INVENTORY` | 11 | `InventoryMenu` |
| `MENU_MAP` | 22 | `MapMenu` |
| `MENU_RESPAWN_DIALOGUE` | 40 | Respawn dialogue |
| `MENU_LOGIN_TIME` | 38 | `LoginTimeBase` |
| `MENU_LOGIN_QUEUE` | 30 | `LoginQueueBase` |

Full list: `MENU_ANY` (1) through `MENU_CONNECTION_DIALOGUE` (46).

Source Found: `scripts/3_Game/constants.c:170-215`

## Factory chain

```
UIManager.CreateScriptedMenu(id, parent)
  └── DayZGame.CreateScriptedMenu(id)          // delegates to mission
        └── MissionBase.CreateScriptedMenu(id) // switch(id) → new Class
```

`DayZGame.CreateScriptedMenu` returns `mission.CreateScriptedMenu(id)` when a mission exists, else `NULL`.

Source Found: `scripts/3_Game/DayZGame.c:1380-1389`
Source Found: `scripts/5_Mission/mission/missionBase.c:185-299`

### missionBase switch (PlayZUI targets)

```c
case MENU_MAIN:       menu = new MainMenu; break;
case MENU_INGAME:     menu = new InGameMenu; break;
case MENU_OPTIONS:    menu = new OptionsMenu; break;
case MENU_LOADING:    menu = new LoadingMenu; break;
case MENU_LOGOUT:     menu = new LogoutMenu; break;
case MENU_KEYBINDINGS: menu = new KeybindingsMenu; break;
```

Platform `#ifdef`s select console variants for `MENU_MAIN` and `MENU_INGAME`.

Source Found: `scripts/5_Mission/mission/missionBase.c:191-264`

## Parent/child relationships

| Flow | Parent | Child id | Notes |
|------|--------|----------|-------|
| Pause game | `null` or current | `MENU_INGAME` | `MissionGameplay` opens pause. |
| Logout countdown | `InGameMenu` | `MENU_LOGOUT` | `parent.EnterScriptedMenu(MENU_LOGOUT)`. |
| Options from main | `MainMenu` | `MENU_OPTIONS` | Submenu stack. |
| Options from pause | `InGameMenu` | `MENU_OPTIONS` | Same class, different parent. |
| Keybindings | `OptionsMenu` | `MENU_KEYBINDINGS` | Via controls tab button. |

`UIMenuPanel.EnterScriptedMenu(id)` on a parent creates the child and links parent/submenu pointers natively.

Source Found: `scripts/3_Game/tools/UIScriptedMenu.c:11-12`

## SetID and GetID

After factory creation, the engine sets menu id via `SetID(int id)`. `GetID()` returns `m_id` (default `MENU_UNKNOWN` until set).

Source Found: `scripts/3_Game/tools/UIScriptedMenu.c:145-153`

## Mod override strategies

PlayZUI will **not** replace `MissionBase.CreateScriptedMenu` in milestone 1. Milestone 2 uses:

1. **`modded class MainMenu`** (etc.) — swap layout in `Init()`, preserve widget names.
2. **Load order** — PlayZUI loads after Terje/Expansion script packs so `modded class` merges resolve correctly.

Expansion already uses strategy (1) for `MainMenu`, `InGameMenu`, `OptionsMenu` with `super.Init()` first.

Source Found: `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/MainMenu/MainMenu.c:15-19`

### Anti-pattern

Replacing `Init()` entirely without `super.Init()` skips Expansion branding, tab injection, and PlayZGunPlay sUDE tab hiding.

## Lookup helpers

```c
GetUIManager().IsMenuOpen(MENU_LOGOUT)
GetUIManager().FindMenu(MENU_INGAME)
GetUIManager().CloseMenu(MENU_OPTIONS)
```

Source Found: `scripts/3_Game/tools/UIManager.c:154-175`

## PlayZUI factory checklist (milestone 2)

- [ ] Confirm target `MENU_*` id matches vanilla class you mod.
- [ ] Do not add new `MENU_*` values without engine support.
- [ ] If adding Terje Start Screen pages, use Terje factory (`TerjeStartScreenPagesFactory`), not `MissionBase`.
- [ ] Document layout path change in `docs/vanilla/14-cross-reference-index.md`.
