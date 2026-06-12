# Terje UI stack index

Third-party Terje mod UI documentation for PlayZUI. Sources at workspace root: `TerjeCore/`, `TerjeStartScreen/`, `TerjeSkills/`, `TerjeMedicine/`, `TerjeRadiation/`, `TerjeCompatibilityCOT/`.

## Architecture

```
TerjeCore (widget framework + HUD registration)
    ├── TerjeStartScreen (post-spawn wizard)
    ├── TerjeSkills (inventory skills panel)
    ├── TerjeMedicine (badges + notifiers)
    ├── TerjeRadiation (badges + PPE)
    └── TerjeCompatibilityCOT (COT admin UI)
PlayZTerje* (PlayZ gameplay bridges)
PlayZUI (Start Screen layout skins via GetNativeLayout())
```

## Mod load order

Third-party:
```text
… TerjeCore · TerjeStartScreen · TerjeSkills · TerjeMedicine · TerjeRadiation · …
```

Within `@PlayZ_Client`:
```text
… PlayZTerje* · PlayZUI · PlayZExpansion
```

**Source Found:** `PlayZ_Client/PlayZUI/README.md:9-19`

## PlayZ bridge philosophy

| Surface | Owner | PlayZUI action |
|---------|-------|----------------|
| Terje Start Screen page skins | **PlayZUI** | `GetNativeLayout()` overrides only |
| Terje HUD badges, skills, notifiers | **Terje mods** | Document only; extend via PlayZTerje* |
| Terje widget framework | **TerjeCore** | Do not fork — use `modded class` on page subclasses |

Terje Start Screen is a **post-spawn wizard**, not a main-menu replacement.

**Source Found:** `TerjeStartScreen/Scripts/5_Mission/MissionGameplay.c:28-60`

## Document map

| # | File | Topic |
|---|------|-------|
| 01 | [01-terje-core-widgets.md](01-terje-core-widgets.md) | `TerjeWidgetBase`, `TerjeScriptedMenu`, `TerjeUiManager` |
| 02 | [02-terje-start-screen.md](02-terje-start-screen.md) | Flow, pages, RPC, hooks |
| 03 | [03-terje-hud-skills-medicine-radiation.md](03-terje-hud-skills-medicine-radiation.md) | HUD badges, skills panel, notifiers |
| 04 | [04-terje-cot-compatibility.md](04-terje-cot-compatibility.md) | COT `JMPlayerForm` perks tab |
| 05 | [05-playz-bridge-patterns.md](05-playz-bridge-patterns.md) | PlayZUI + PlayZTerje* bridge rules |
| 06 | [06-layouts-imagesets-config.md](06-layouts-imagesets-config.md) | Layout paths, imagesets, config deps |

## Entry points

| API | File | Line |
|-----|------|------|
| `TerjeUiManager.GetInstance().ShowScriptedMenu` | `TerjeCore/Scripts/3_Game/Widgets/TerjeUiManager.c` | 46-55 |
| `MissionGameplay.OnUpdateTerjeCustomBadges` | `TerjeCore/Scripts/5_Mission/MissionGameplay.c` | 37-65 |
| `TerjeStartScreenPagesFactory` | `TerjeStartScreen/Scripts/5_Mission/TerjeStartScreenPagesFactory.c` | 7-13 |

## Related docs

- [../playz/](../playz/)
- [../BRIDGES.md](../BRIDGES.md)
- [../vanilla/01-core-framework.md](../vanilla/01-core-framework.md) (`TerjeScriptedMenu` note)
