# Vanilla UI core framework

PlayZUI milestone 2 rewrites shell menus on top of this stack. Read this before touching any `modded class` menu.

## Class hierarchy

| Class | Role |
|-------|------|
| `UIMenuPanel` | Base panel: parent/submenu, visibility, `EnterScriptedMenu`, `Close` |
| `UIScriptedMenu` | Script menus: `layoutRoot`, `Init()`, input handlers, `GetID()` |
| `TerjeScriptedMenu` | Terje extension of `UIScriptedMenu` (see `docs/terje/`) |

`UIScriptedMenu` extends `UIMenuPanel` and owns the widget tree loaded in `Init()`.

**Source Found:** `scripts/3_Game/tools/UIScriptedMenu.c:2-67`

## UIScriptedMenu lifecycle

1. Factory (`MissionBase.CreateScriptedMenu` or `UIManager.CreateScriptedMenu`) constructs the menu class.
2. `UIManager` calls `Init()` — must return the root `Widget` (usually `layoutRoot`).
3. Menu receives `OnShow` / `OnHide`, per-frame `Update(float timeslice)`, and widget events (`OnClick`, `OnChange`, …).
4. `Close()` tears down via `UIMenuPanel` native path; destructor runs cleanup (keyboard handle, RPC cancel, etc.).

Key members on `UIScriptedMenu`:

- `layoutRoot` — root widget from `CreateWidgets`
- `m_id` — set by UIManager to the `MENU_*` constant
- `LockControls()` / `UnlockControls()` — pause game input while menu open

**Source Found:** `scripts/3_Game/tools/UIScriptedMenu.c:66-78` (layout root)
**Source Found:** `scripts/3_Game/tools/UIScriptedMenu.c:53-56` (`GetID` default)

## UIManager

Native singleton accessed via `GetGame().GetUIManager()`.

| API | Purpose |
|-----|---------|
| `CreateScriptedMenu(int id, UIMenuPanel parent)` | Factory entry — resolves `MENU_*` to class |
| `GetMenu()` | Currently open top-level menu (null when none) |
| `ShowScriptedMenu(UIScriptedMenu menu, …)` | Display after `Init()` |
| `EnterScriptedMenu(int id)` | Open submenu from parent panel |

**Source Found:** `scripts/3_Game/tools/UIManager.c:5` (`CreateScriptedMenu` proto)
**Source Found:** `scripts/3_Game/tools/UIMenuPanel.c:12` (`EnterScriptedMenu`)

## Widget engine (EnWidgets)

Low-level widget types and handlers live in the core proto layer:

- `Widget` — base: `FindAnyWidget`, `Show`, `GetParent`, flags
- `TextWidget`, `ImageWidget`, `ButtonWidget`, `ProgressBarWidget`, …
- `ScriptedWidgetEventHandler` — mixin for `OnClick` / `OnChange` on menus

**Source Found:** `scripts/1_Core/proto/EnWidgets.c` (widget proto definitions)

PlayZUI layouts bind widgets by **name string** in `Init()` via `FindAnyWidget("widgetName")`. Renaming widgets in a custom layout without updating every `modded class` consumer breaks sibling patches (see `docs/playz/01-playzcore-ui.md` logout contract).

## TabberUI

Options and multi-tab shells use `TabberUI` to register tab buttons and content panes (`Tab_0`, `Tab_Control_0`, …). PlayZGunPlay hides the sUDE tab by index after `super.Init()` — PlayZUI options rewrites must preserve tab indices or re-run sibling hide logic.

**Source Found:** `scripts/3_Game/tools/TabberUI.c` (tab registration)
**Source Found:** `PlayZ_Client/PlayZGunPlay/scripts/5_Mission/sUDE/gui/optionsMenu/OptionsMenu.c:14-32`

## Workspace vs loading workspace

| Workspace | Used by |
|-----------|---------|
| `GetGame().GetWorkspace()` | In-game HUD overlays, menus, inventory |
| `GetGame().GetLoadingWorkspace()` | `LoadingScreen` class (not `LoadingMenu`) |

**Source Found:** `scripts/3_Game/DayZGame.c:713` (`LoadingScreen` uses `GetLoadingWorkspace()`)

## PlayZUI scaffold

Milestone 1 exposes path constants only:

**Source Found:** `PlayZ_Client/PlayZUI/scripts/3_Game/PlayZUIPaths.c:1-4`

Custom layouts in milestone 2 load from `PlayZUIPaths.PLAYZ_UI_ROOT` + relative path.

## Related docs

- [02-menu-ids-and-factory.md](02-menu-ids-and-factory.md)
- [03-uimanager-flow.md](03-uimanager-flow.md)
- [11-widget-api-patterns.md](11-widget-api-patterns.md)
