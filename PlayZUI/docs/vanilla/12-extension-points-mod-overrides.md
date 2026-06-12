# Extension points and mod overrides

Catalog of `modded class` targets PlayZUI will touch, with canonical override patterns from Expansion and Terje.

## Golden rules

1. **One `modded class` per file** — name file after the class.
2. **`super.Init()` first** when patching existing menu `Init()`.
3. **Preserve widget names** — downstream mods bind by string.
4. **Load order** — PlayZUI loads after Terje/Expansion script packs within `@PlayZ_Client`.

**Source Found:** `PlayZ_Client/PlayZUI/README.md:9-19` (mod-line order)

## PlayZUI target classes (milestone 2)

| Class | PlayZUI action | Sibling consumers |
|-------|----------------|-------------------|
| `MainMenu` | Custom layout | Expansion Core + Scripts, intro scene |
| `InGameMenu` | Custom layout | Expansion death screen, news feed |
| `LogoutMenu` | Custom layout only (no Init override) | PlayZCore ACL patch |
| `OptionsMenu` | Custom shell layout | Expansion tab, PlayZGunPlay tab hide |
| `KeybindingsMenu` | Optional reskin | Expansion version text |
| `LoadingScreen` | Logo/background reskin | Expansion logo swap |
| `LoadingMenu` | Optional reskin | Same layout file |
| `TerjeStartScreenPage*` | `GetNativeLayout()` only | Terje RPC flow |

PlayZUI does **not** target: `IngameHud`, `MissionBase.CreateScriptedMenu`, `InventoryMenu`.

## Pattern A — post-process after super.Init()

Minimal, safest pattern. Used by Expansion Core:

**Source Found:** `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/MainMenu/MainMenu.c:15-19`

```c
modded class MainMenu
{
    override Widget Init()
    {
        layoutRoot = super.Init();
        // mutate widgets on layoutRoot
        return layoutRoot;
    }
}
```

## Pattern B — full layout swap with super.Init()

PlayZUI milestone 2 option when replacing layout path in `modded class`:

```c
modded class MainMenu
{
    override Widget Init()
    {
        layoutRoot = g_Game.GetWorkspace().CreateWidgets(
            PlayZUIPaths.PLAYZ_UI_ROOT + "layouts/main_menu.layout");
        // re-bind all vanilla widget names, then call sibling hooks manually — RISKY
        return layoutRoot;
    }
}
```

**Prefer Pattern A** when possible. Full swap requires replicating all vanilla `Init()` bindings and breaks if vanilla adds widgets.

## Pattern C — add options tab

**Source Found:** `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/Options/OptionsMenu.c:23-30`

```c
layoutRoot = super.Init();
int idx = m_Tabber.AddTab("EXPANSION");
m_ExpansionTab = new OptionsMenuExpansion(layoutRoot.FindAnyWidget("Tab_" + idx), ...);
```

PlayZUI must not add tabs here — EXPANSION tab is PlayZExpansion/Expansion scope.

## Pattern D — hide tab by index

**Source Found:** `PlayZ_Client/PlayZGunPlay/scripts/5_Mission/sUDE/gui/optionsMenu/OptionsMenu.c:12-32`

After `super.Init()`, hide `Tab_Control_N` and `Tab_N` for last index.

## Pattern E — MissionBase factory extension

For **new menu ids** only (Expansion range 1000+):

**Source Found:** `DayZExpansion/DayZExpansion/Navigation/Scripts/5_Mission/DayZExpansion_Navigation/MissionBase.c:15-49`

```c
override UIScriptedMenu CreateScriptedMenu(int id)
{
    if (id == MENU_EXPANSION_MAP)
        return new ExpansionMapMenu;
    return super.CreateScriptedMenu(id);
}
```

PlayZUI does **not** add vanilla `MENU_*` ids — use existing ids with `modded class` on menu classes.

## Pattern F — Terje layout-only override

**Source Found:** `TerjeStartScreen/Scripts/5_Mission/TerjeStartScreenPageName.c:29-32`

```c
modded class TerjeStartScreenPageName
{
    override string GetNativeLayout()
    {
        return PlayZUIPaths.PLAYZ_UI_ROOT + "layouts/terje/page_name.layout";
    }
}
```

Preserve all widget names expected by Terje page `OnInit`.

## Pattern G — LogoutMenu cosmetic (PlayZCore-safe)

PlayZCore overrides `UpdateInfo`/`Update` only — PlayZUI replaces layout in `Init()` **only if** widget names match vanilla.

**Source Found:** `PlayZ_Client/PlayZCore/scripts/5_Mission/gui/LogoutMenu_AntiCombatLog.c:5-72`

Alternative: layout reskin without script override — ship layout with same names, override path in `modded class LogoutMenu.Init()` calling `super.Init()` after layout swap is **not** supported (vanilla hardcodes layout path). PlayZUI must override `Init()` to load custom layout **and** re-bind widgets identically to vanilla lines 49–52.

## Anti-patterns (do not)

| Anti-pattern | Breaks |
|--------------|--------|
| `Init()` without `super.Init()` on MainMenu/InGameMenu/OptionsMenu | Expansion branding, death screen, EXPANSION tab |
| Rename logout widgets | PlayZCore ACL |
| `modded class IngameHud` in PlayZUI | Conflicts with PlayZExpansion nametag bridges |
| Replace `MissionBase.CreateScriptedMenu` for vanilla ids | Load-order wars with Expansion |
| Multiple `modded class MainMenu` in one file | Engine rule violation |

## Reference mod override inventory

Full PlayZ_Client sibling list: `docs/playz/02-sibling-modules.md`.

Expansion menu stack: `docs/expansion/02-menu-overrides.md`.

Terje Start Screen hooks: `docs/terje/05-playz-bridge-patterns.md`.

## Related docs

- [docs/BRIDGES.md](../BRIDGES.md)
- [docs/playz/03-load-order-conflicts.md](../playz/03-load-order-conflicts.md)
- [14-cross-reference-index.md](14-cross-reference-index.md)
