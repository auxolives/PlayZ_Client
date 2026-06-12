# Terje PlayZ bridge patterns

How PlayZUI and PlayZTerje* integrate with the Terje UI stack without breaking RPC flows or HUD registration.

## PlayZTerje mod chain

| Sub-mod | requiredAddons | UI-relevant scripts |
|---------|----------------|---------------------|
| `PlayZTerjeCore` | `PlayZCore`, `TerjeCore` | `TerjePlayerSkillsAccessor.c` — perk/modifier bridge |
| `PlayZTerjeSkills` | `TerjeSkills`, `PlayZTerjeCore` | `TerjeSkillWidget.c` |
| `PlayZTerjeMedicine` | `TerjeMedicine`, `PlayZTerjeCore` | `IngameHud.c`, sleep PPE |
| `PlayZTerjeRadiation` | `TerjeRadiation`, `PlayZTerjeCore` | `InspectMenuNew.c`, `MissionGameplay.c` |

**Source Found:** respective `PlayZ_Client/PlayZTerje*/config.cpp`

Load order: `PlayZTerje*` before `PlayZUI` before `PlayZExpansion`.

---

## PlayZUI Start Screen skins (planned)

Per `PlayZUI/README.md`:

**Source Found:** `PlayZ_Client/PlayZUI/README.md:26`

Pattern — layout-only override on page subclasses:

```c
modded class TerjeStartScreenPageName
{
    override string GetNativeLayout()
    {
        return PlayZUIPaths.PLAYZ_UI_ROOT + "layouts/terje/page_name.layout";
    }
}
```

**Source Found:** `PlayZ_Client/PlayZUI/scripts/3_Game/PlayZUIPaths.c:1-4`

### Rules

1. Override **only** `GetNativeLayout()` — preserve all widget names from Terje vanilla layouts.
2. Do **not** fork `TerjeWidgetBase`, `TerjeScriptedMenu`, or `TerjeUiManager`.
3. Do **not** replace `TerjeStartScreenMenu` or RPC handlers.
4. One `modded class` per page file.

### Pages to skin (milestone 2 backlog item)

| Page class | Vanilla layout |
|------------|----------------|
| `TerjeStartScreenPageRules` | `TerjeStartScreen/Layouts/PageRules.layout` |
| `TerjeStartScreenPageName` | `TerjeStartScreen/Layouts/PageName.layout` |
| `TerjeStartScreenPageFace` | `TerjeStartScreen/Layouts/PageFace.layout` |
| `TerjeStartScreenPageSkills` | `TerjeStartScreen/Layouts/PageSkills.layout` |
| `TerjeStartScreenPageOverview` | `TerjeStartScreen/Layouts/PageOverview.layout` |
| `TerjeStartScreenPageLoadout` | `TerjeStartScreen/Layouts/PageLoadout.layout` |
| `TerjeStartScreenPageMap` | `TerjeStartScreen/Layouts/PageMap.layout` |

See [02-terje-start-screen.md](02-terje-start-screen.md) for RPC flow.

---

## PlayZTerjeSkills UI bridge

**Source Found:** `PlayZ_Client/PlayZTerjeSkills/scripts/5_mission/TerjeSkillWidget.c:1-78`

- Hides `terje_skill_header_points` per skill row
- Rewrites container header with aggregated points + `#STR_PLAYZ_GLOBAL_PTS_LABEL`
- `PlayZ_RefreshSkillsView()` after perk apply / reset

String key in `PlayZTerjeCore/stringtable.csv:58`.

### PlayZTerjeSkillTooltip (unhooked)

**Source Found:** `PlayZ_Client/PlayZTerjeSkills/scripts/5_mission/PlayZTerjeSkillTooltip.c:1-68`

Custom tooltip layout exists but vanilla still calls `TerjeSkillTooltip.GetSkillTooltipWidget` — no redirect yet.

---

## PlayZTerjeMedicine bridges

**Source Found:** `PlayZ_Client/PlayZTerjeMedicine/scripts/5_mission/IngameHud.c:1-16`

Suppresses TerjeMind notifier and TerjeVacinaC badge.

**Source Found:** `PlayZ_Client/PlayZTerjeMedicine/scripts/3_game/pperequester_terjemedsleeping.c:1-36`

Sleep PPE drives `PlayZEarPlugsGate` — coordinates with PlayZCore earplugs (not PlayZUI).

---

## PlayZTerjeRadiation bridges

**Source Found:** `PlayZ_Client/PlayZTerjeRadiation/scripts/5_Mission/InspectMenuNew.c:5-174`

Rad tier tags on inspect widgets — independent of PlayZUI shell menus.

---

## TerjeGameRespawn

When player dies during Start Screen gate, Terje opens pause + respawn:

**Source Found:** `TerjeStartScreen/Scripts/5_Mission/MissionGameplay.c:50-58`

PlayZUI pause reskin must preserve `respawn_button` wiring — see [vanilla/06-screen-ingame-menu.md](../vanilla/06-screen-ingame-menu.md).

---

## Factory extension (adding pages)

To add a **new** Start Screen page type (not milestone 2 default):

1. Extend `TerjeStartScreenPagesFactory` with new tab registration
2. Create page class extending `TerjeStartScreenPageBase`
3. Register server context in `PluginTerjeStartScreen`

Do not use `MissionBase.CreateScriptedMenu` for Terje pages.

**Source Found:** `TerjeStartScreen/Scripts/5_Mission/TerjeStartScreenPagesFactory.c:7-13`

---

## Related docs

- [02-terje-start-screen.md](02-terje-start-screen.md)
- [06-layouts-imagesets-config.md](06-layouts-imagesets-config.md)
- [../playz/01-playzcore-ui.md](../playz/01-playzcore-ui.md)
- [../BRIDGES.md](../BRIDGES.md)
