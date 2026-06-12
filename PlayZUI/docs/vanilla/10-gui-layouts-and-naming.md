# GUI layouts and naming conventions

Survey of vanilla `gui/layouts/` organization. PlayZUI custom layouts should follow the same path and naming patterns.

## Root structure

**Path:** `gui/layouts/` (~216 `.layout` files in workspace)

### Top-level categories

| Folder / pattern | Contents |
|------------------|----------|
| Root `day_z_*.layout` | Legacy shared dialogs (ingame menu, logout, inspect) |
| `loading.layout`, `startup.layout` | Engine-level screens |
| `new_ui/` | Modern UI refactor (main menu, options, server browser) |
| `xbox/` | Console-specific standalone layouts |
| `inventory_new/` | Responsive inventory (`narrow/`, `medium/`, `wide/`, `xbox/`) |
| `radial_menu/` | Radial quickbar |
| `debug/`, `repro/` | Debug tooling |

## Platform subfolders

Modern options and tutorials split by platform at **compile time** via `#ifdef`:

| Define | Folder |
|--------|--------|
| `PLATFORM_WINDOWS` | `new_ui/options/pc/` |
| `PLATFORM_XBOX` | `new_ui/options/xbox/` |
| `PLATFORM_PS4` | `new_ui/options/ps/` |
| `PLATFORM_MSSTORE` | `new_ui/options/msstore/` |
| `PLATFORM_CONSOLE` | Shared console behavior |

**Source Found:** `scripts/5_Mission/GUI/NewUI/Options/OptionsMenu.c:41-55`

### Path pattern

```text
gui/layouts/<feature>/<platform>/<name>.layout
```

Examples:
- `gui/layouts/new_ui/main_menu.layout` (PC main menu)
- `gui/layouts/new_ui/options/pc/options_menu.layout`
- `gui/layouts/new_ui/options/pc/keybinding_menu.layout`

## Main menu platform variants

| Platform | Layout file |
|----------|---------------|
| PC | `new_ui/main_menu.layout` |
| Console | `new_ui/main_menu_console.layout` |
| MS Store | `new_ui/main_menu_msstore.layout` |

**Source Found:** `scripts/5_Mission/GUI/NewUI/MainMenu/MainMenu.c:55`

## Widget naming rules

1. **Stable across platforms** — same widget names in PC and console layouts; platform folders differ in chrome/hints only.
2. **Script binding by name** — menus use `FindAnyWidget("name")`; renames break all `modded class` consumers.
3. **Tab convention** — `Tab_0`, `Tab_1`, … paired with `Tab_Control_0`, `Tab_Control_1`, …
4. **Imageset references** — layouts reference `set:name image:id` pairs; imagesets live beside layouts in mod GUI PBOs.

## PlayZUI layout root

Milestone 2 layouts load from:

```c
PlayZUIPaths.PLAYZ_UI_ROOT + "layouts/..."
```

**Source Found:** `PlayZ_Client/PlayZUI/scripts/3_Game/PlayZUIPaths.c:1-4`

Suggested mirror structure:

```text
PlayZ_Client/PlayZUI/gui/layouts/
  main_menu.layout
  day_z_ingamemenu.layout
  day_z_logout_dialog.layout
  loading.layout
  options/pc/options_menu.layout
  ...
```

Script references use full mod path: `"PlayZ_Client/PlayZUI/gui/layouts/..."` or constant from `PlayZUIPaths`.

## Imagesets and styles

Vanilla imagesets are under `gui/` (not always in `layouts/`). Third-party mods register imagesets in `CfgMods` defs:

**Source Found:** `DayZExpansion/DayZExpansion/Core/Scripts/config.cpp:43-62`

PlayZUI milestone 2 should register PlayZ imagesets in `PlayZUI/config.cpp` when adding custom textures.

## Inventory responsive layouts

**Source Found:** `gui/layouts/inventory_new/` tree

Inventory uses width-based layout selection — out of PlayZUI milestone 2 scope unless explicitly requested.

## Related docs

- [11-widget-api-patterns.md](11-widget-api-patterns.md)
- [14-cross-reference-index.md](14-cross-reference-index.md)
- [docs/terje/06-layouts-imagesets-config.md](../terje/06-layouts-imagesets-config.md)
