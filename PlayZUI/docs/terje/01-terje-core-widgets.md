# Terje core widgets

Foundation widget framework used by all Terje UI. PlayZUI does not replace these classes — only overrides layout paths on page subclasses.

## TerjeWidgetBase

**Source Found:** `TerjeCore/Scripts/3_Game/Widgets/TerjeWidgetBase.c:1-467`

Base class for all Terje UI composition. Extends `ScriptedWidgetEventHandler`.

| Concern | Lines | Behavior |
|---------|-------|----------|
| Lifecycle | 11-18 | `OnCreate(parent)` → `CreateWidgets(GetNativeLayout(), parent)` + `SetHandler(this)` |
| Default layout | 25-28 | `"TerjeCore/Layouts/TerjeWidgetEmpty.layout"` |
| Child tree | 258-316 | `CreateTerjeWidget`, `DestroyTerjeWidget`, `DestroyAllChildren` |
| Deferred commands | 248-393 | `PushCommand` flushed in `OnUpdate(timeslice)` |
| User params | 45-61 | `SetUserParam` / `GetUserParam` map |

**Command types:** `Show`, `Color`, `SetSize`, `SetWidth`, `SetHeight`, `SetPos` (397-467).

**Subclass pattern:** override `GetNativeLayout()` to point at mod-specific `.layout`.

## TerjeScriptedMenu

**Source Found:** `TerjeCore/Scripts/3_Game/Widgets/TerjeScriptedMenu.c:8-316`

Extends vanilla `UIScriptedMenu` with Terje widget/command model.

| Concern | Lines | Behavior |
|---------|-------|----------|
| `Init()` | 8-19 | Lazy `OnCreate` → `OnInit` → `OnUpdate(0)` once |
| Root layout | 26-29, 86-99 | `"TerjeCore/Layouts/TerjeScriptedMenu.layout"` |
| Show/Hide | 181-257 | Toggles HUD, cursor, input, sound, blur via overridable guards |
| Update loop | 259-316 | `UAUIBack` closes if `CanBeClosed()`; propagates `OnUpdate` to children |
| Widget factory | 121-149 | `CreateTerjeWidget` / `CreateTerjeWidgetEx` |

Guards overridable per menu: `IsHudVisible`, `IsCursorVisible`, `IsInputEnabled`, `IsSoundMuted`, `IsBlurEnabled`, `CanBeClosed`.

## TerjeUiManager

**Source Found:** `TerjeCore/Scripts/3_Game/Widgets/TerjeUiManager.c:8-123`

Client-only singleton menu factory + global tooltip host.

| API | Lines | Purpose |
|-----|-------|---------|
| `GetInstance()` | 8-24 | Singleton; errors on server |
| `GetScriptedMenu(typename)` | 31-44 | Cached spawn via `name.Spawn()` |
| `ShowScriptedMenu(typename)` | 46-55 | `UIManager.ShowScriptedMenu(menu, null)` |
| `ShowGlobalTooltip` | 72-123 | Tooltip under active menu root; screen clamp |
| `HideGlobalTooltip` | 57-70 | Unlink + stop timer |

Used by inventory entity icons:

**Source Found:** `TerjeCore/Scripts/5_Mission/Widgets/TerjeWidgetEntityIcon.c:162-186`

## TerjeScriptedWidget

**Source Found:** `TerjeCore/Scripts/3_Game/Widgets/TerjeScriptedWidget.c:6-37`

Non-menu embedded widget root. Same default layout as menu. Constructed with parent widget in ctor.

## TerjeStartScreenPageBase

**Source Found:** `TerjeCore/Scripts/5_Mission/TerjeStartScreenPageBase.c:5-22`

| Method | Role |
|--------|------|
| `InitInputContext` | Populate page from server context |
| `InitOutputContext` | Serialize page state before RPC |
| `ExecuteNextPage` | Invokes `m_NextPageCallback` once |

## Widget catalog

**Path:** `TerjeCore/Scripts/3_Game/Widgets/`

Layout primitives: `TerjeWidgetText` (+ Label/Centered/Small/Error), `TerjeWidgetImage`, `TerjeWidgetButton`, `TerjeWidgetButtonHold`, `TerjeWidgetRow`, `TerjeWidgetCol`, `TerjeWidgetStackArea`, `TerjeWidgetStackList`, `TerjeWidgetScrollArea`, `TerjeWidgetScrollList`, `TerjeWidgetListItem`, `TerjeWidgetMultitab`, `TerjeWidgetTab`, `TerjeWidgetHeaderPanel`, `TerjeWidgetPadding`, `TerjeWidgetSpacer`, `TerjeWidgetEmpty`, `TerjeWidgetMarkdown`.

Mission widgets (`TerjeCore/Scripts/5_Mission/Widgets/`): `TerjeWidgetPlayerPreview`, `TerjeWidgetEntityInventory`, `TerjeWidgetEntityIcon`, `TerjeWidgetCargoRow`.

## HUD templates

Badge and notifier templates cloned at runtime:

**Source Found:** `TerjeCore/Scripts/5_Mission/IngameHud.c:18-142`

- `TerjeCore/Layouts/BadgeTemplate.layout` — badge widgets
- `TerjeCore/Layouts/TendencyTemplate.layout` — notifier widgets

## Vanilla relationship

`TerjeScriptedMenu` extends `UIScriptedMenu`:

**Source Found:** `scripts/3_Game/tools/UIScriptedMenu.c:66`

See [vanilla/01-core-framework.md](../vanilla/01-core-framework.md).

## Related docs

- [02-terje-start-screen.md](02-terje-start-screen.md)
- [06-layouts-imagesets-config.md](06-layouts-imagesets-config.md)
