# Sakhal limited Expansion scope

What PlayZUI owns vs PlayZExpansion vs off-pillar Expansion modules on Sakhal.

## Deployment model

- Expansion = third-party `-mod=`, separate from `PlayZ_Client/`
- PlayZ integrates via scoped sub-mods with explicit `requiredAddons[]`
- Do not add Expansion deps to unrelated PlayZ PBOs

**Source Found:** `.cursor/docs/DAYZ_EXPANSION_SAKHAL.md:21`
**Source Found:** `.cursor/docs/DAYZ_EXPANSION_SAKHAL.md:42` (PlayZ wins symbol conflicts)

## Sakhal pillars vs off-pillar

| Area | Sakhal status | UI impact |
|------|---------------|-----------|
| **Missions / Airdrops** | Primary pillar | No menu stack; mission JSON |
| **Licensed plane** | On mod line | None |
| **Core UI shell** | Partial | Main menu branding, pause/death, earplugs via GeneralSettings |
| **NameTags + Chat + Killfeed + P2P** | Patched by PlayZExpansion | Terje identity bridges |
| **Market, Quests, Territory, Garage** | Not design pillars | ScriptView menus may exist in repo but not server identity |

**Source Found:** `.cursor/docs/DAYZ_EXPANSION_SAKHAL.md:29-35`

## PlayZ UI ownership

**Source Found:** `PlayZ_Client/PlayZUI/README.md:21-30`

| Surface | Owner | Notes |
|---------|-------|-------|
| Main menu, loading, pause, options, logout | **PlayZUI** | Shell reskins |
| Terje Start Screen page skins | **PlayZUI** | `GetNativeLayout()` only |
| Expansion nametags, chat, killfeed, EXPANSION tab | **PlayZExpansion** | After PlayZUI |
| Terje HUD badges, skills | Terje / PlayZTerje* | Documented, not PlayZUI |
| Earplugs flash overlay | **PlayZCore** | Independent of menus |

## Mod-line order

```text
… TerjeStartScreen · DayZ-Expansion-* · … · PlayZUI · PlayZExpansion
```

Within `@PlayZ_Client`:

```text
PlayZCore · PlayZGunPlay · PlayZTerje* · PlayZUI · PlayZExpansion
```

**Source Found:** `PlayZ_Client/PlayZUI/README.md:9-19`

## Read-only reference policy

`DayZExpansion/` workspace clone is lookup-only. Steam Workshop PBOs (tag **1.9.69**) are what runs.

**Source Found:** `.cursor/docs/DAYZ_EXPANSION_SAKHAL.md:15-17`

## PlayZExpansion scope on Sakhal

Patches listed in config:

**Source Found:** `PlayZ_Client/PlayZExpansion/config.cpp:14-20`

- NameTags, Chat, Killfeed, P2P (Terje names)
- AI aggression cooldown suppression
- Does **not** add new GUI PBO — scripts only

## Milestone 2 screen priority (Sakhal)

| Priority | Screen | Why |
|----------|--------|-----|
| 1 | Loading | First player touchpoint |
| 2 | Main menu | Expansion branding coexist |
| 3 | Pause + logout | Death screen + PlayZCore ACL |
| 4 | Options | EXPANSION tab + GunPlay hide |
| 5 | Terje Start Screen | Post-spawn wizard skins |

Off-pillar Expansion menus (Market UI, Quest UI) — out of scope unless mod line adds them.

## Related docs

- [01-module-structure.md](01-module-structure.md)
- [07-bridge-patterns-conflicts.md](07-bridge-patterns-conflicts.md)
- [../playz/03-load-order-conflicts.md](../playz/03-load-order-conflicts.md)
