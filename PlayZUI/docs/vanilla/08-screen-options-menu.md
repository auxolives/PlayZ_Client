# Options menu screen

Multi-tab settings shell opened from main menu or pause menu. PlayZUI reskins the shell and tab layouts; Expansion and PlayZGunPlay inject or hide tabs after `super.Init()`.

## Class and factory

| Field | Value |
|-------|-------|
| Class | `OptionsMenu extends UIScriptedMenu` |
| Menu id | `MENU_OPTIONS` (14) |
| Tab classes | `OptionsMenuGame`, `OptionsMenuSounds`, `OptionsMenuVideo`, `OptionsMenuControls` |

**Source Found:** `scripts/5_Mission/GUI/NewUI/Options/OptionsMenu.c:1-17`
**Source Found:** `scripts/3_Game/constants.c:183` (`MENU_OPTIONS`)

## Platform layout paths

**Source Found:** `scripts/5_Mission/GUI/NewUI/Options/OptionsMenu.c:41-55`

| Platform | Shell layout |
|----------|--------------|
| MS Store | `gui/layouts/new_ui/options/msstore/options_menu.layout` |
| Xbox | `gui/layouts/new_ui/options/xbox/options_menu.layout` |
| PS4 | `gui/layouts/new_ui/options/ps/options_menu.layout` |
| PC (Sakhal) | `gui/layouts/new_ui/options/pc/options_menu.layout` |

## Tab wiring

**Source Found:** `scripts/5_Mission/GUI/NewUI/Options/OptionsMenu.c:57-77`

| Tab index | PC/PS content | Xbox content |
|-----------|---------------|--------------|
| `Tab_0` | Game (`OptionsMenuGame`) | Game |
| `Tab_1` | Sounds (`OptionsMenuSounds`) | Sounds |
| `Tab_2` | Video (`OptionsMenuVideo`) | Controls only |
| `Tab_3` | Controls (`OptionsMenuControls`) | — |

Tabber retrieved via `layoutRoot.FindAnyWidget("Tabber").GetScript(m_Tabber)` (line 103).

### Tab sub-layouts (PC)

| Tab class | Layout path | GetLayoutName |
|-----------|-------------|---------------|
| `OptionsMenuGame` | `gui/layouts/new_ui/options/pc/game_tab.layout` | `OptionsMenuGame.c:157-163` |
| `OptionsMenuSounds` | `.../pc/sound_tab.layout` | `OptionsMenuSounds.c:135-143` |
| `OptionsMenuVideo` | `.../pc/video_tab.layout` | `OptionsMenuVideo.c:231-243` |
| `OptionsMenuControls` | `.../pc/controls_tab.layout` | `OptionsMenuControls.c:238-248` |

Each tab creates widgets with `g_Game.GetWorkspace().CreateWidgets(GetLayoutName(), parent)`.

Shared details panel widgets: `settings_details`, `details_label`, `details_content`.

## Shell action buttons

**Source Found:** `scripts/5_Mission/GUI/NewUI/Options/OptionsMenu.c:14-17`

- `apply`, `back`, `reset`, `defaults` — bound in `Init()`

Apply pipeline (232–274): each tab `.Apply()` + `m_Options.Apply()` + `GetUApi().Export()`.

## Child menu navigation

Controls tab opens keybindings:

**Source Found:** `scripts/5_Mission/GUI/NewUI/Options/OptionsMenuControls.c:252-254`

`EnterScriptedMenu(MENU_KEYBINDINGS)` — see [09-options-keybindings-architecture.md](09-options-keybindings-architecture.md).

## Expansion EXPANSION tab

Expansion adds a tab **after** vanilla tabs via `m_Tabber.AddTab("EXPANSION")`:

**Source Found:** `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/Options/OptionsMenu.c:23-30`

Tab content: `OptionsMenuExpansion` loading `DayZExpansion/Core/GUI/layouts/ui/options/expansion_tab.layout`.

**Source Found:** `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/Options/OptionsMenuExpansion.c:33`

Overrides `OnChanged()`, `Apply()`, `Refresh()` forward to expansion tab (33–57).

## PlayZGunPlay tab hide

PlayZGunPlay hides the last tab (sUDE) by index after `super.Init()`:

**Source Found:** `PlayZ_Client/PlayZGunPlay/scripts/5_Mission/sUDE/gui/optionsMenu/OptionsMenu.c:5-36`

Widgets hidden: `Tab_Control_{lastIndex}`, `Tab_{lastIndex}`.

**Load order:** Expansion adds EXPANSION tab → PlayZGunPlay hides sUDE tab → PlayZUI loads after both. PlayZUI options rewrite must call `super.Init()` and preserve tab indices or re-run sibling hide logic.

## PlayZUI bridge rules

1. `layoutRoot = super.Init()` — required for EXPANSION tab and sUDE hide.
2. Preserve `Tabber`, `Tab_*`, `Tab_Control_*` naming convention.
3. Do not reorder tabs without updating PlayZGunPlay hide indices.
4. EXPANSION tab content stays in PlayZExpansion / Expansion — not PlayZUI scope.

## Related docs

- [09-options-keybindings-architecture.md](09-options-keybindings-architecture.md)
- [docs/expansion/02-menu-overrides.md](../expansion/02-menu-overrides.md)
- [docs/playz/02-sibling-modules.md](../playz/02-sibling-modules.md)
- [docs/BRIDGES.md](../BRIDGES.md)
