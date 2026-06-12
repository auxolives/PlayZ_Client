# Expansion UI manager and ScriptView

EXPANSIONUI framework for MVC-style menus (Market, Quests, Garage, etc.). Relevant on Sakhal for loaded modules (P2P/Market if on mod line); affects HUD gates when open.

## EXPANSIONUI compile flag

Wraps ScriptView / UIManager code. When undefined, `ExpansionScriptViewMenuBase` degrades to dummy typedef:

**Source Found:** `DayZExpansion/Core/Scripts/3_Game/DayZExpansion_Core/ExpansionScriptViewMenuBase.c:34-36`

## Class hierarchy

| Class | File | Role |
|-------|------|------|
| Engine `ScriptView` | vanilla | Base MVC view |
| `ExpansionScriptViewBase` | `Core/Scripts/3_Game/.../ExpansionScriptView.c:22-120` | Show/hide/destroy, registry |
| `ExpansionScriptViewMenuBase` | `ExpansionScriptViewMenuBase.c:14-32` | Input lock, cursor, `CloseMenu()` |
| `ExpansionScriptViewMenu` | `Core/Scripts/5_Mission/.../ExpansionScriptViewMenu.c` | Full menu implementation |
| Feature menus | e.g. `ExpansionP2PMarketMenu` | Extend `ExpansionScriptViewMenu` |

Menus spawn via `className.ToType().Spawn()`:

**Source Found:** `DayZExpansion/Core/Scripts/3_Game/DayZExpansion_Core/ExpansionUIManager.c:139-141`

## ExpansionUIManager

**Source Found:** `DayZExpansion/Core/Scripts/3_Game/DayZExpansion_Core/ExpansionUIManager.c:14-121`

| API | Purpose |
|-----|---------|
| `GetMenu()` | Current ScriptView menu |
| `CloseMenu()` | Close active menu |
| `CloseAll(bool includeVanilla)` | Close all — **caution:** `includeVanilla` closes pause too |
| `CreateSVMenu(string viewName)` | Spawn menu by class name |

Hosted on `ExpansionGame`:

**Source Found:** `DayZExpansion/Core/Scripts/3_Game/DayZExpansion_Core/ExpansionGame.c:15-34`

Access patterns:
- `GetDayZExpansion().GetExpansionUIManager()`
- `GetDayZGame().GetExpansionGame().GetExpansionUIManager()`

Menu id filter: `[MENU_EXPANSION_MENU_START, MENU_EXPANSION_MENU_END)` at line 93.

## Mission integration

**Source Found:** `DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/MissionGameplay.c:78-170`

| Hook | Behavior | Lines |
|------|----------|-------|
| `OnUpdate` | Passes vanilla menu + ScriptView to `Expansion_OnUpdate` | 78-85 |
| ESC | Closes ScriptView menu | 90-103 |
| `Pause()` | Blocked while ScriptView open | 111-117 |
| `CloseAllMenus()` | Also closes Expansion UI | 122-128 |
| Mission finish | Destroys all ScriptViews | 167-170 |

## HUD interaction

When ScriptView menu open, `Expansion_CanShowHUDElements` returns false:

**Source Found:** `DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/ingamehud.c:41-44`

Same effect as vanilla pause menu for nametags/NV/earplugs HUD.

## Sakhal relevance

Limited Sakhal design — Market/Quest/Garage not pillars. P2P/Market may still load if on mod line; PlayZExpansion patches P2P listings.

**Source Found:** `.cursor/docs/DAYZ_EXPANSION_SAKHAL.md:35`

ScriptView menus still block HUD elements when open regardless of server pillar status.

## PlayZUI scope

PlayZUI does not implement ScriptView menus. Document for debugging HUD hide/show and pause blocking.

## Related docs

- [03-ingame-hud.md](03-ingame-hud.md)
- [06-sakhal-limited-scope.md](06-sakhal-limited-scope.md)
- [07-bridge-patterns-conflicts.md](07-bridge-patterns-conflicts.md)
