# Widget API patterns

Low-level widget engine APIs used by all scripted menus. PlayZUI layouts and scripts must follow these patterns.

## Core proto layer

**Source Found:** `scripts/1_Core/proto/EnWidgets.c`

### Widget base class

| API | Purpose | Line region |
|-----|---------|-------------|
| `Show(bool)` | Visibility | ~107 |
| `Enable(bool)` | Input enabled | ~107 |
| `SetColor(int)` | Tint | ~107 |
| `FindWidget(string path)` | Path-based lookup | ~107 |
| `FindAnyWidget(string name)` | Name-based lookup | ~107 |
| `FindAnyWidgetById(int id)` | ID lookup | ~107 |
| `SetHandler(ScriptedWidgetEventHandler)` | Event routing | ~107 |
| `GetScript(out Class)` | Retrieve script object | ~107 |
| `Unlink()` | Remove from tree | ~107 |

### WorkspaceWidget — layout loader

**Source Found:** `scripts/1_Core/proto/EnWidgets.c:176-182`

```c
CreateWidgets(string layout, Widget parent, bool immedUpdate)
```

Primary entry: `g_Game.GetWorkspace().CreateWidgets("gui/layouts/....layout")`.

Loading workspace variant: `g_Game.GetLoadingWorkspace().CreateWidgets(...)` for `LoadingScreen`.

**Source Found:** `scripts/3_Game/DayZGame.c:713`

### WidgetFlags enum

**Source Found:** `scripts/1_Core/proto/EnWidgets.c:57-85`

Common flags: `VISIBLE`, `IGNOREPOINTER`, `DISABLED`, `NOFOCUS`, `STRETCH`.

### Typed widgets

| Class | Key methods |
|-------|-------------|
| `TextWidget` | `SetText`, `SetOutline`, `SetShadow`, `SetColor` |
| `ImageWidget` | `LoadImageFile`, `SetColor` |
| `ButtonWidget` | Click events via handler |
| `ProgressBarWidget` | Progress value |
| `MultilineTextWidget` | Multi-line text |

Cast pattern: `TextWidget.Cast(layoutRoot.FindAnyWidget("name"))`.

## ScriptedWidgetEventHandler

**Source Found:** `scripts/1_Core/proto/EnWidgets.c:656-686`

Override hooks for widget events:

- `OnClick`, `OnChange`, `OnModalResult`
- `OnFocus`, `OnFocusLost`
- `OnMouseEnter`, `OnMouseLeave`
- `OnKeyDown`, `OnKeyUp`
- Drag/drop: `OnDrag`, `OnDrop`, `OnDraggingOver`
- `OnController` (gamepad)

Menus (`UIScriptedMenu`) inherit event dispatch. Tab panels use `ScriptedWidgetEventHandler` directly:

```c
m_Root.SetHandler(this);
```

**Source Found:** `scripts/5_Mission/GUI/NewUI/Options/OptionsMenuGame.c:46-52`

## UIScriptedMenu patterns

**Source Found:** `scripts/3_Game/tools/UIScriptedMenu.c:66-166`

| Pattern | Usage |
|---------|--------|
| `override Widget Init()` | Create `layoutRoot`, bind widgets, return root |
| `layoutRoot` member | Root widget (C++ destroys on close) |
| `LockControls()` / `UnlockControls()` | Pause game input while menu open |
| `OnShow()` / `OnHide()` | Visibility lifecycle |
| `EnterScriptedMenu(int id)` | Open child menu (from `UIMenuPanel`) |
| `SetID()` / `GetID()` | Menu identity (`m_id`) |
| `Update(float timeslice)` | Per-frame logic |

### Standard Init template

```c
override Widget Init()
{
    layoutRoot = g_Game.GetWorkspace().CreateWidgets("gui/layouts/my_menu.layout");
    m_Button = ButtonWidget.Cast(layoutRoot.FindAnyWidget("my_button"));
    layoutRoot.FindAnyWidget("Tabber").GetScript(m_Tabber);
    return layoutRoot;
}
```

### Keyboard capture

Menus that capture key input:

```c
g_Game.SetKeyboardHandle(this);  // constructor or Init
// destructor:
g_Game.SetKeyboardHandle(null);
```

**Source Found:** `scripts/5_Mission/GUI/LogoutMenu.c:15-25`
**Source Found:** `scripts/5_Mission/GUI/NewUI/Keybindings/KeybindingsMenu.c:73`

## TabberUI integration

**Source Found:** `scripts/5_Mission/GUI/NewUI/TabberPrefab/TabberUI.c:1-16`

```c
layoutRoot.FindAnyWidget("Tabber").GetScript(m_Tabber);
m_Tabber.m_OnTabSwitch.Insert(OnTabSwitch);
```

Tab content panels named `Tab_0`, `Tab_Control_0`, etc.

## Terje widget layer

Terje wraps vanilla widgets in `TerjeWidgetBase` with deferred command queue — see `docs/terje/01-terje-core-widgets.md`.

PlayZUI Start Screen skins use `GetNativeLayout()` overrides on Terje page classes, not raw `CreateWidgets` in PlayZUI scripts.

## PlayZUI rules

1. Always `Cast()` widget lookups to typed widgets.
2. Bind by **name string** — document names in layout comments for milestone 2.
3. One `modded class` per file; override `Init()` with `super.Init()` when patching existing menus.
4. Do not leak widgets — parent to workspace root or menu root; unlink in destructor when creating dynamic widgets.

## Related docs

- [01-core-framework.md](01-core-framework.md)
- [12-extension-points-mod-overrides.md](12-extension-points-mod-overrides.md)
- [docs/terje/01-terje-core-widgets.md](../terje/01-terje-core-widgets.md)
