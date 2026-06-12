# Terje layouts, imagesets, and config

Complete path reference for Terje UI assets and module dependencies.

## Layout inventory by mod

### TerjeCore (42 files)

**Path:** `TerjeCore/Layouts/`

Widget primitives, `TerjeScriptedMenu.layout`, `BadgeTemplate.layout`, `TendencyTemplate.layout`, `ModalDialogYesNo.layout`, markdown subtree.

Default empty widget: `TerjeCore/Layouts/TerjeWidgetEmpty.layout`

**Source Found:** `TerjeCore/Scripts/3_Game/Widgets/TerjeWidgetBase.c:25-28`

### TerjeStartScreen (12 files)

**Path:** `TerjeStartScreen/Layouts/`

| File | Used by |
|------|---------|
| `PageRules.layout` | `TerjeStartScreenPageRules` |
| `PageName.layout` | `TerjeStartScreenPageName` |
| `PageFace.layout` | `TerjeStartScreenPageFace` |
| `PageSkills.layout` | `TerjeStartScreenPageSkills` |
| `PageOverview.layout` | `TerjeStartScreenPageOverview` |
| `PageLoadout.layout` | `TerjeStartScreenPageLoadout` |
| `PageMap.layout` | `TerjeStartScreenPageMap` |
| `ItemSkill.layout` | `TerjeStartScreenItemSkill` |
| `ItemFace.layout` | `TerjeStartScreenItemFace` |
| `ItemLoadoutPoints.layout` | `TerjeWidgetLoadoutPoints` |
| `TerjeLoadoutItemPoints.layout` | `TerjeWidgetLoadoutItemPoints` |

### TerjeSkills (5 files)

**Path:** `TerjeSkills/Layouts/`

- `TerjeSkillLayout.layout`
- `TerjePerkLayout.layout`
- `TerjeSkillTooltip.layout`
- `TerjePerkTooltip.layout`
- `TerjeBlankLayout.layout`

### TerjeCompatibilityCOT

**Path:** `TerjeCompatibilityCOT/GUI/Layouts/GridSpacer11.layout`

COT perk grid spacer only.

### Vanilla layouts reused

**Source Found:** `TerjeCore/Scripts/5_Mission/Widgets/TerjeWidgetEntityIcon.c`

`gui/layouts/inventory_new/day_z_inventory_new_tooltip.layout` for entity icon tooltips.

---

## Imagesets (CfgMods defs)

| Mod | Path | Prefix |
|-----|------|--------|
| TerjeStartScreen | `TerjeStartScreen/Textures/startscreen_icons.imageset` | startscreen |
| TerjeMedicine | `TerjeMedicine/Textures/icon_medicine.imageset` | `TerjeMedicine_icon` |
| TerjeRadiation | `TerjeRadiation/Textures/icon_radiation.imageset` | `TerjeRadiation_icon` |
| TerjeSkills | 5 files under `TerjeSkills/Textures/Icons/` | `TerjeSkills_icon`, `TerjeSkillBorders_icon`, `TerjePerkLevels_icon`, `TerjePerk_icon`, `TerjePerkBlack_icon` |

Skills HUD references: `set:TerjeSkills_icon image:ts_*` in `CfgTerjeSkills`:

**Source Found:** `TerjeSkills/config.cpp:83+`

---

## requiredAddons dependency graph

```
DZ_Data, DZ_Scripts
    └── TerjeCore
            ├── TerjeStartScreen
            ├── TerjeSkills
            ├── TerjeMedicine (+ DZ_Gear_Medical)
            ├── TerjeRadiation
            └── TerjeCompatibilityCOT (+ JM_COT_Scripts)

PlayZCore
    └── PlayZTerjeCore (+ TerjeCore)
            ├── PlayZTerjeSkills (+ TerjeSkills)
            ├── PlayZTerjeMedicine (+ TerjeMedicine)
            └── PlayZTerjeRadiation (+ TerjeRadiation)

PlayZUI (+ TerjeCore, TerjeStartScreen, Expansion)
```

**Source Found:** `PlayZ_Client/PlayZUI/config.cpp:8-15`

---

## Script module paths

| Mod | 3_Game | 4_World | 5_Mission |
|-----|--------|---------|-----------|
| TerjeCore | ✓ | ✓ | ✓ |
| TerjeStartScreen | ✓ | ✓ + 4_Compatibility | ✓ + 5_Compatibility |
| TerjeSkills | ✓ | ✓ | ✓ |
| TerjeMedicine | ✓ | ✓ | ✓ |
| TerjeRadiation | ✓ | ✓ + 4_Compatibility | ✓ |
| TerjeCompatibilityCOT | — | ✓ | ✓ |

---

## GetNativeLayout() migration checklist (PlayZUI)

| Class | Vanilla path → PlayZUI target |
|-------|------------------------------|
| `TerjeStartScreenPageRules` | `PlayZUI/gui/layouts/terje/page_rules.layout` |
| `TerjeStartScreenPageName` | `.../page_name.layout` |
| `TerjeStartScreenPageFace` | `.../page_face.layout` |
| `TerjeStartScreenPageSkills` | `.../page_skills.layout` |
| `TerjeStartScreenPageOverview` | `.../page_overview.layout` |
| `TerjeStartScreenPageLoadout` | `.../page_loadout.layout` |
| `TerjeStartScreenPageMap` | `.../page_map.layout` |
| Item/sub-widgets | Match Terje widget `FindAnyWidget` names from source page classes |

PlayZUI milestone 2 should register PlayZ imagesets in `PlayZUI/config.cpp` when adding Terje page skins.

---

## Compile flags

| Define | Source mod | Effect |
|--------|------------|--------|
| `TERJE_CORE_MOD` | TerjeCore | Core widget framework |
| `TERJE_START_SCREEN_MOD` | TerjeStartScreen | Start Screen wizard |
| `TERJE_SKILLS_MOD` | TerjeSkills | Skills panel + COT perks tab |

---

## Related docs

- [02-terje-start-screen.md](02-terje-start-screen.md)
- [05-playz-bridge-patterns.md](05-playz-bridge-patterns.md)
- [../vanilla/10-gui-layouts-and-naming.md](../vanilla/10-gui-layouts-and-naming.md)
