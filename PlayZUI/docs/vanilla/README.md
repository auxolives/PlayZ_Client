# Vanilla UI reference index

Authoritative vanilla DayZ UI documentation for PlayZUI milestone 2. Sources: workspace `scripts/`, `gui/`, `DZ/` (UI input via `GetUApi()`, not `DZ/` configs).

## Document map

| # | File | Topic |
|---|------|-------|
| 01 | [01-core-framework.md](01-core-framework.md) | `UIScriptedMenu`, `UIManager`, `EnWidgets`, `TabberUI` |
| 02 | [02-menu-ids-and-factory.md](02-menu-ids-and-factory.md) | `MENU_*` constants, `CreateScriptedMenu` factory |
| 03 | [03-uimanager-flow.md](03-uimanager-flow.md) | Menu open/close flow, pause, logout, `GetMenu()` gates |
| 04 | [04-loading-screen-lifecycle.md](04-loading-screen-lifecycle.md) | `LoadingScreen` vs `LoadingMenu`, `loading.layout` |
| 05 | [05-screen-main-menu.md](05-screen-main-menu.md) | `MainMenu`, intro scene, navigation |
| 06 | [06-screen-ingame-menu.md](06-screen-ingame-menu.md) | `InGameMenu`, pause, HUD side effects |
| 07 | [07-screen-logout-menu.md](07-screen-logout-menu.md) | `LogoutMenu`, widget contract, PlayZCore ACL |
| 08 | [08-screen-options-menu.md](08-screen-options-menu.md) | `OptionsMenu`, tabs, Expansion EXPANSION tab |
| 09 | [09-options-keybindings-architecture.md](09-options-keybindings-architecture.md) | `KeybindingsMenu`, `GetUApi()`, presets |
| 10 | [10-gui-layouts-and-naming.md](10-gui-layouts-and-naming.md) | Layout folders, platform splits, naming |
| 11 | [11-widget-api-patterns.md](11-widget-api-patterns.md) | Widget API, handlers, menu patterns |
| 12 | [12-extension-points-mod-overrides.md](12-extension-points-mod-overrides.md) | Mod override patterns, anti-patterns |
| 13 | [13-dz-and-config-notes.md](13-dz-and-config-notes.md) | Profile paths, inputs, no DZ UI presets |
| 14 | [14-cross-reference-index.md](14-cross-reference-index.md) | Master screen → class → layout table |
| 15 | [15-linked-screen-flows.md](15-linked-screen-flows.md) | Connect/boot shell: loading, queue, login, hints |

## Reading order for milestone 2

1. **01–03** — framework before touching any menu
2. **12 + [BRIDGES.md](../BRIDGES.md)** — override rules and sibling compat
3. **Target screen doc** (04–09) — per-screen implementation
4. **14** — lookup table while coding

## Suggested screen implementation order

| Order | Screen | Primary docs |
|-------|--------|--------------|
| 1 | Loading + connect shell | 04, **15**, [expansion/02](../expansion/02-menu-overrides.md) |
| 2 | Main menu | 05 |
| 3 | Pause + logout | 06, 07, [playz/01](../playz/01-playzcore-ui.md) |
| 4 | Options + keybindings | 08, 09 |
| 5 | Terje Start Screen | [terje/02](../terje/02-terje-start-screen.md), [terje/05](../terje/05-playz-bridge-patterns.md) |

## Related trees

- [docs/playz/](../playz/) — PlayZ_Client sibling UI patches
- [docs/terje/](../terje/) — Terje widget stack
- [docs/expansion/](../expansion/) — DayZ Expansion UI
- [docs/BRIDGES.md](../BRIDGES.md) — cross-cutting integration rules

## Citation rule

Every non-obvious claim cites: `Source Found: path/to/file.c:Line`
