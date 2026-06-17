# Terje COT compatibility

Reference documentation for Community Online Tools integration. PlayZUI does not modify COT UI — admin tooling only.

## Mod dependency

**Source Found:** `PlayZTerjeJMPlayerFormCOTFix/config.cpp` — replaces workshop `TerjeCompatibilityCOT` (do not load both).

```
requiredAddons[] = { "TerjeCore", "JM_COT_Scripts", "TerjeSkills" }
```

Perks tab requires `TERJE_SKILLS_MOD` compile flag from TerjeSkills:

**Source Found:** `TerjeSkills/config.cpp:25`

## JMPlayerForm extension

**Source Found:** `TerjeCompatibilityCOT/Scripts/5_Mission/JMPlayerForm.c:30-125`

Hooks COT player detail panel via `override private Widget InitActionWidgetsStats`.

### Terje Stats tab (always)

**Source Found:** `TerjeCompatibilityCOT/Scripts/5_Mission/JMPlayerForm.c:34-58`

- Tab selector: `"Terje Stats"` / `"Terje Perks"` (or stats-only without skills, 34-42)
- Sliders from `GetTerjeAdmintoolSupport().GetPlayerStats()` (51-58)
- Apply → `m_Module.SetTerjeValue(id, value, players)` (384-398)
- Refresh pulls `m_SelectedInstance.GetTerjeStat(id)` (354-375)

### Terje Perks tab (TERJE_SKILLS_MOD)

**Source Found:** `TerjeCompatibilityCOT/Scripts/5_Mission/JMPlayerForm.c:69-123`

- Reuses `TerjeSkills/Layouts/TerjePerkLayout.layout` per perk
- Grid rows via `PlayZTerjeJMPlayerFormCOTFix/GUI/Layouts/GridSpacer11.layout` (perk rows; skills use `CreateWrapSpacer` on the stats panel — not `CreateGridSpacer(result, skillCount, 1)`)
- Composite widget name: `skillId:perkId`
- Mouse: left = `TRPC_PLAYER_PERK_APPLY`, right = `TRPC_PLAYER_PERK_DEC` (243-246)
- Tooltip: `TerjePerkTooltip.GetPerkTooltipWidget` (180-190)
- Visual state: same border/level imagesets as inventory panel (287-337)

Tab switch (`OnTerjeTabChanged`, 342-352): toggles `m_TerjeStatsPanel` / `m_TerjePerksPanel` visibility.

## Supporting COT classes

| File | Role |
|------|------|
| `JMPlayerModule.c` | `SetTerjeValue` RPC; `Exec_Heal` calls `GetTerjeAdmintoolSupport().OnHeal` |
| `JMPlayerInstance.c` | Syncs Terje stats + perk status maps (server tick, 8-40) |

**Source Found:** `TerjeCompatibilityCOT/Scripts/5_Mission/JMPlayerModule.c`, `JMPlayerInstance.c`

## Vanilla COT base

**Source Found:** `COT/Scripts/5_Mission/CommunityOnlineTools/modules/Player/JMPlayerForm.c:1`

`JMPlayerForm extends JMFormBase`.

## PlayZUI relevance

None for milestone 2 shell menus. Document for completeness when debugging Terje perk state on admin clients.

## Related docs

- [03-terje-hud-skills-medicine-radiation.md](03-terje-hud-skills-medicine-radiation.md)
- [06-layouts-imagesets-config.md](06-layouts-imagesets-config.md)
