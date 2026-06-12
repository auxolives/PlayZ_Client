# DZ configs and input profile notes

What `DZ/` does and does **not** contain for UI work. PlayZUI authors use scripts + gui + profile paths instead.

## DZ/ has no UI layout presets

The `DZ/` tree holds world data, entity configs, and CE definitions — not scripted menu layouts or widget presets.

UI layouts live in:
- Vanilla: `gui/layouts/`
- Mods: `<ModName>/GUI/` or `<ModName>/Layouts/` (Terje pattern)

Input bindings are **not** in `DZ/` — they use the user action API and profile export.

## GetUApi() — user action API

**Source Found:** `scripts/3_Game/` (search `GetUApi` proto)

| API | Purpose |
|-----|---------|
| `GetUApi()` | Singleton user action manager |
| `GetInputByName(string)` | Lookup `UAInput` by action name |
| `Export()` | Save bindings to profile |
| `Sync()` | Sync after apply |

Options apply pipeline calls `GetUApi().Export()` after tab changes:

**Source Found:** `scripts/5_Mission/GUI/NewUI/Options/OptionsMenu.c:232-274`

Keybindings menu reads sorting via `InputUtils.GetInputActionSortingMap()`:

**Source Found:** `scripts/5_Mission/GUI/NewUI/Keybindings/KeybindingsMenu.c:86-104`

## Custom input actions (PlayZ)

PlayZ registers inputs via `inputs.xml` in sub-mod roots:

**Source Found:** `PlayZ_Client/PlayZCore/inputs.xml:1-25`
**Source Found:** `PlayZ_Client/PlayZCore/config.cpp:26` (inputs registration)

| Action | Key | Appears in keybindings UI |
|--------|-----|---------------------------|
| `UAEarPlugsToggle` | N | Yes |
| `UAEmoteLyingDown` | V | Yes |
| `UATakeBackpackToHands` | B | Yes |
| `UATakeMouthBlockerToHands` | M | Yes |

PlayZUI does not own these inputs — document for keybindings screen awareness.

## Profile paths

Player settings persist under `$profile:` (client profile directory):

| Data | Typical path |
|------|--------------|
| Keybindings export | User profile (via `GetUApi().Export()`) |
| Expansion GeneralSettings | `$profile:ExpansionMod/Settings/GeneralSettings.json` |
| Expansion NameTags | `$profile:ExpansionMod/Settings/NameTagsSettings.json` |

**Source Found:** `DayZExpansion/DayZExpansion/Scripts/3_Game/DayZExpansion/Settings/General/ExpansionGeneralSettings.c:25`

Expansion settings are **ops levers** — toggle UI features without script changes. See `docs/expansion/05-general-settings-gates.md`.

## GameOptions vs profile

`OptionsMenu` uses `GameOptions m_Options` for in-session game/video/sound settings:

**Source Found:** `scripts/5_Mission/GUI/NewUI/Options/OptionsMenu.c:14`

Tab classes call `m_Options` getters/setters and `Apply()` on confirm.

## Engine vs scripted loading

| System | Config source |
|--------|---------------|
| `LoadingScreen` | Hardcoded in `DayZGame.c` — not menu factory |
| `LoadingMenu` | `MENU_LOADING` factory |
| Workspaces | `GetWorkspace()` vs `GetLoadingWorkspace()` |

**Source Found:** `scripts/3_Game/DayZGame.c:688-713`

No `DZ/` config selects loading layout — script-only.

## PlayZUI config.cpp deps

PlayZUI declares script module paths and third-party deps — no GUI CfgPatches yet (milestone 2):

**Source Found:** `PlayZ_Client/PlayZUI/config.cpp:8-50`

Milestone 2 will add GUI patch for layouts/imagesets when assets ship.

## Related docs

- [09-options-keybindings-architecture.md](09-options-keybindings-architecture.md)
- [docs/expansion/05-general-settings-gates.md](../expansion/05-general-settings-gates.md)
- [04-loading-screen-lifecycle.md](04-loading-screen-lifecycle.md)
