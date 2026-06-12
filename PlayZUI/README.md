# PlayZUI

Sakhal UI rework home: main menu, loading, pause/options shells, logout, and Terje Start Screen page skins. HUD, nametags, and Expansion overlays stay in sibling modules.

## Mod-line order

Within `@PlayZ_Client`:

```text
… PlayZCore · PlayZGunPlay · PlayZTerje* · PlayZUI · PlayZExpansion
```

Third-party stack (abbreviated):

```text
… TerjeStartScreen · DayZ-Expansion-* · … · PlayZUI · PlayZExpansion
```

`PlayZCore` loads before `PlayZUI`. `PlayZExpansion` loads after `PlayZUI`.

## Ownership

| Surface | Owner | Notes |
|---------|-------|-------|
| Main menu, loading, pause, options shell, logout, death screen | **PlayZUI** | `modded class` + custom layouts |
| Terje Start Screen page skins | **PlayZUI** | `GetNativeLayout()` overrides only |
| Expansion nametags, chat names, killfeed, life stats, options EXPANSION tab | **PlayZExpansion** | Narrow hooks after PlayZUI |
| Terje HUD badges, skills panel, medicine/rad notifiers | **Terje mods** | PlayZUI documents; PlayZTerje* may extend |
| Earplugs HUD flash overlay | **PlayZCore** | `EarPlugsWidget` — gate on `GetMenu() == null` |
| Anti-combat logout text/button lock | **PlayZCore** | `LogoutMenu_AntiCombatLog` — preserve vanilla widget names in PlayZUI logout layout |

## Documentation index

### Cross-cutting

| Doc | Purpose |
|-----|---------|
| [docs/BRIDGES.md](docs/BRIDGES.md) | Integration rules, per-screen checklists, conflict summary |

### Vanilla (`docs/vanilla/`)

| Doc | Topic |
|-----|-------|
| [README.md](docs/vanilla/README.md) | Index + reading order |
| [01-core-framework.md](docs/vanilla/01-core-framework.md) | UIScriptedMenu, UIManager, EnWidgets |
| [02-menu-ids-and-factory.md](docs/vanilla/02-menu-ids-and-factory.md) | MENU_* constants, CreateScriptedMenu |
| [03-uimanager-flow.md](docs/vanilla/03-uimanager-flow.md) | Menu open/close, pause, logout |
| [04-loading-screen-lifecycle.md](docs/vanilla/04-loading-screen-lifecycle.md) | LoadingScreen vs LoadingMenu |
| [15-linked-screen-flows.md](docs/vanilla/15-linked-screen-flows.md) | Connect shell: loading + queue + login + hints |
| [05-screen-main-menu.md](docs/vanilla/05-screen-main-menu.md) | MainMenu |
| [06-screen-ingame-menu.md](docs/vanilla/06-screen-ingame-menu.md) | InGameMenu pause |
| [07-screen-logout-menu.md](docs/vanilla/07-screen-logout-menu.md) | LogoutMenu widget contract |
| [08-screen-options-menu.md](docs/vanilla/08-screen-options-menu.md) | OptionsMenu tabs |
| [09-options-keybindings-architecture.md](docs/vanilla/09-options-keybindings-architecture.md) | KeybindingsMenu, GetUApi |
| [10-gui-layouts-and-naming.md](docs/vanilla/10-gui-layouts-and-naming.md) | Layout folders, platform splits |
| [11-widget-api-patterns.md](docs/vanilla/11-widget-api-patterns.md) | Widget API, handlers |
| [12-extension-points-mod-overrides.md](docs/vanilla/12-extension-points-mod-overrides.md) | Mod override patterns |
| [13-dz-and-config-notes.md](docs/vanilla/13-dz-and-config-notes.md) | Profile paths, inputs |
| [14-cross-reference-index.md](docs/vanilla/14-cross-reference-index.md) | Master lookup table |

### PlayZ siblings (`docs/playz/`)

| Doc | Topic |
|-----|-------|
| [README.md](docs/playz/README.md) | Index + PlayZCore checklist |
| [01-playzcore-ui.md](docs/playz/01-playzcore-ui.md) | Earplugs, ACL logout, inputs |
| [02-sibling-modules.md](docs/playz/02-sibling-modules.md) | Full UI grep inventory |
| [03-load-order-conflicts.md](docs/playz/03-load-order-conflicts.md) | Conflict matrix |
| [04-death-screen.md](docs/playz/04-death-screen.md) | Custom death flow, cover reveal, vanilla PPE/fade fixes |

### Terje (`docs/terje/`)

| Doc | Topic |
|-----|-------|
| [README.md](docs/terje/README.md) | Stack index, load order |
| [01-terje-core-widgets.md](docs/terje/01-terje-core-widgets.md) | TerjeWidgetBase, TerjeUiManager |
| [02-terje-start-screen.md](docs/terje/02-terje-start-screen.md) | Wizard flow, RPC |
| [03-terje-hud-skills-medicine-radiation.md](docs/terje/03-terje-hud-skills-medicine-radiation.md) | HUD badges, skills panel |
| [04-terje-cot-compatibility.md](docs/terje/04-terje-cot-compatibility.md) | COT admin UI |
| [05-playz-bridge-patterns.md](docs/terje/05-playz-bridge-patterns.md) | PlayZUI + PlayZTerje bridges |
| [06-layouts-imagesets-config.md](docs/terje/06-layouts-imagesets-config.md) | Layout paths, deps |

### Expansion (`docs/expansion/`)

| Doc | Topic |
|-----|-------|
| [README.md](docs/expansion/README.md) | Sakhal scope, index |
| [01-module-structure.md](docs/expansion/01-module-structure.md) | GUI vs Scripts PBOs |
| [02-menu-overrides.md](docs/expansion/02-menu-overrides.md) | Menu override stack |
| [03-ingame-hud.md](docs/expansion/03-ingame-hud.md) | Nametags, HUD gates |
| [04-expansion-ui-manager-scriptview.md](docs/expansion/04-expansion-ui-manager-scriptview.md) | ScriptView framework |
| [05-general-settings-gates.md](docs/expansion/05-general-settings-gates.md) | GeneralSettings.json |
| [06-sakhal-limited-scope.md](docs/expansion/06-sakhal-limited-scope.md) | Sakhal pillars |
| [07-bridge-patterns-conflicts.md](docs/expansion/07-bridge-patterns-conflicts.md) | PlayZExpansion bridges |

## Milestone 2 backlog

Screen rewrites (layouts + `modded class` scripts) follow the doc trees. Suggested order:

1. Loading + connect shell — [vanilla/04](docs/vanilla/04-loading-screen-lifecycle.md), [vanilla/15](docs/vanilla/15-linked-screen-flows.md), [expansion/02](docs/expansion/02-menu-overrides.md)
2. Main menu — [vanilla/05](docs/vanilla/05-screen-main-menu.md)
3. In-game / logout — [vanilla/06](docs/vanilla/06-screen-ingame-menu.md), [vanilla/07](docs/vanilla/07-screen-logout-menu.md), [playz/01](docs/playz/01-playzcore-ui.md)
4. Options / keybindings — [vanilla/08](docs/vanilla/08-screen-options-menu.md), [vanilla/09](docs/vanilla/09-options-keybindings-architecture.md)
5. Terje Start Screen pages — [terje/02](docs/terje/02-terje-start-screen.md), [terje/05](docs/terje/05-playz-bridge-patterns.md)

Track progress in [docs/BRIDGES.md](docs/BRIDGES.md) implementation log.

## Packing

```text
.vscode/scripts/Build-PlayZ_Client.bat PlayZUI
```

Mikero source mirror: `P:\PlayZ_Client\PlayZUI\`.

Path constant: `PlayZUIPaths.PLAYZ_UI_ROOT` = `"PlayZ_Client/PlayZUI/gui/"`

**Source Found:** `PlayZ_Client/PlayZUI/scripts/3_Game/PlayZUIPaths.c:1-4`
