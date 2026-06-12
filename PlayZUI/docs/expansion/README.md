# DayZ Expansion UI index

Read-only reference for Expansion UI modules. Implement PlayZ changes in `PlayZ_Client/` — primarily `PlayZExpansion` for HUD/name bridges, `PlayZUI` for shell menus.

## Sakhal scope

Sakhal runs **limited DayZ Expansion** — airdrops, trader, core UI shell, nametags/chat/killfeed/P2P patches. Not a full Expansion server identity.

**Source Found:** `.cursor/docs/DAYZ_EXPANSION_SAKHAL.md:29-35`

## Read-only policy

Canonical clone: `DayZExpansion/` at workspace root. **Do not edit** — lookup and diff only.

**Source Found:** `.cursor/docs/DAYZ_EXPANSION_SAKHAL.md:17`

## Mod load order

Third-party:
```text
… DayZ-Expansion-Core · DayZ-Expansion · DayZ-Expansion-NameTags · …
```

PlayZ:
```text
… PlayZUI · PlayZExpansion
```

**Source Found:** `PlayZ_Client/PlayZUI/README.md:15-19`

## Ownership split

| Surface | Owner |
|---------|-------|
| Main menu, loading, pause, options shell, logout | **PlayZUI** |
| Nametags, chat names, killfeed, EXPANSION options tab | **PlayZExpansion** / Expansion |
| Terje Start Screen skins | **PlayZUI** |
| Terje HUD badges | Terje mods |

**Source Found:** `PlayZ_Client/PlayZUI/README.md:21-30`

## Document map

| # | File | Topic |
|---|------|-------|
| 01 | [01-module-structure.md](01-module-structure.md) | GUI vs Scripts PBOs |
| 02 | [02-menu-overrides.md](02-menu-overrides.md) | MainMenu, InGameMenu, LoadingScreen, OptionsMenu |
| 03 | [03-ingame-hud.md](03-ingame-hud.md) | IngameHud chain, nametags, HUD gates |
| 04 | [04-expansion-ui-manager-scriptview.md](04-expansion-ui-manager-scriptview.md) | EXPANSIONUI, ScriptView menus |
| 05 | [05-general-settings-gates.md](05-general-settings-gates.md) | GeneralSettings.json UI keys |
| 06 | [06-sakhal-limited-scope.md](06-sakhal-limited-scope.md) | Sakhal pillar vs off-pillar modules |
| 07 | [07-bridge-patterns-conflicts.md](07-bridge-patterns-conflicts.md) | super.Init rules, conflict matrix |

## PlayZExpansion deps

**Source Found:** `PlayZ_Client/PlayZExpansion/config.cpp:8-21`

`DayZExpansion_Core_Scripts`, `DayZExpansion_Scripts`, `DayZExpansion_Market_Scripts`, `DayZExpansion_P2PMarket_Scripts`, `DayZExpansion_Chat_Scripts`, `DayZExpansion_NameTags_Scripts`, `DayZExpansion_AI_Scripts`, `PlayZUI`, Terje mods.

## Related docs

- [../vanilla/](../vanilla/)
- [../playz/](../playz/)
- [../BRIDGES.md](../BRIDGES.md)
