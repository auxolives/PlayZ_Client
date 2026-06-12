# Options keybindings architecture

Key rebinding UI opened from the options controls tab. Separate from the options shell but shares platform layout folders.

## Class and factory

| Field | Value |
|-------|-------|
| Class | `KeybindingsMenu extends UIScriptedMenu` |
| Menu id | `MENU_KEYBINDINGS` (34) |
| Parent | `OptionsMenu` (controls tab) |

**Source Found:** `scripts/5_Mission/GUI/NewUI/Keybindings/KeybindingsMenu.c:1`
**Source Found:** `scripts/3_Game/constants.c:203` (`MENU_KEYBINDINGS`)

## Layout paths

**Source Found:** `scripts/5_Mission/GUI/NewUI/Keybindings/KeybindingsMenu.c:32-36`

| Platform | Layout |
|----------|--------|
| MS Store | `gui/layouts/new_ui/options/msstore/keybinding_menu.layout` |
| PC | `gui/layouts/new_ui/options/pc/keybinding_menu.layout` |

## Init() widget bindings

**Source Found:** `scripts/5_Mission/GUI/NewUI/Keybindings/KeybindingsMenu.c:38-73`

| Widget | Purpose |
|--------|---------|
| `version` | Version label |
| `apply` | Apply changes |
| `back` | Return to options |
| `undo` | Undo last change |
| `reset` | Reset category |
| `reset_all` | Reset all bindings |
| `Tabber` | Category tabs |
| `TabContentsHolder` | Dynamic tab content |
| `group_header` | Group header row |

Keyboard capture: `g_Game.SetKeyboardHandle(this)` (line 73).

## Dynamic tab generation

**Source Found:** `scripts/5_Mission/GUI/NewUI/Keybindings/KeybindingsMenu.c:86-109`

`CreateTabs()` iterates `InputUtils.GetInputActionSortingMap()` to build category tabs dynamically.

Container class: `KeybindingsContainer` parented to `TabContentsHolder`.

## Input API stack

| Component | Role |
|-----------|------|
| `GetUApi()` | User action API singleton |
| `UAInput` | Individual input binding |
| `InputUtils` | Sorting map, preset helpers |
| `PresetsMenu` | Control preset picker (`MENU_CONTROLS_PRESET`, id 20) |

**Source Found:** `scripts/3_Game/constants.c:189` (`MENU_CONTROLS_PRESET`)

Apply from options menu exports bindings: `GetUApi().Export()` in `OptionsMenu.Apply()`.

**Source Found:** `scripts/5_Mission/GUI/NewUI/Options/OptionsMenu.c:232-274`

Profile paths are under user profile — not in `DZ/` configs. See [13-dz-and-config-notes.md](13-dz-and-config-notes.md).

## PresetsMenu

**Source Found:** `scripts/5_Mission/GUI/NewUI/Keybindings/PresetsMenu.c`

Opened via `MENU_CONTROLS_PRESET` from MS Store options flow (`OptionsMenu.c:157-168`).

## Expansion layer

Expansion patches version text only:

**Source Found:** `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/KeybindingsMenu/KeybindingsMenu.c:13-28`

```c
layoutRoot = super.Init();
GetDayZGame().Expansion_SetGameVersionText(m_Version);
```

## TabberUI prefab

Shared tab controller used by options and keybindings:

**Source Found:** `scripts/5_Mission/GUI/NewUI/TabberPrefab/TabberUI.c:1-16`

- Invokers: `m_OnTabSwitch`, `m_OnAttemptTabSwitch`
- Retrieved via `FindAnyWidget("Tabber").GetScript(m_Tabber)`

## PlayZUI bridge rules

1. Keybindings are a **separate menu id** — reskin via `modded class KeybindingsMenu`, not options shell alone.
2. Preserve dynamic tab structure — do not hard-code tab count.
3. `SetKeyboardHandle` must remain in constructor/init path for rebinding capture.
4. PlayZCore custom inputs (`UAEarPlugsToggle`, etc.) appear in the binding list via `PlayZCore/inputs.xml` — unrelated to layout reskin but visible in UI.

**Source Found:** `PlayZ_Client/PlayZCore/inputs.xml:1-25`

## Related docs

- [08-screen-options-menu.md](08-screen-options-menu.md)
- [13-dz-and-config-notes.md](13-dz-and-config-notes.md)
- [docs/BRIDGES.md](../BRIDGES.md)
