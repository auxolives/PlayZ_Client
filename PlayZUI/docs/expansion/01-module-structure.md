# Expansion module structure

How DayZ Expansion splits GUI assets from script modules. Relevant for understanding layout paths referenced in menu overrides.

## GUI vs Scripts PBO pattern

Every Expansion feature module follows:

| Layer | CfgPatches class | Contents |
|-------|------------------|----------|
| **GUI** | `DayZExpansion_<Module>_GUI` | Layouts, `.edds`, imagesets — no script defs |
| **Scripts** | `DayZExpansion_<Module>_Scripts` | `CfgMods` with script modules |
| **Stub** (Core) | `DayZExpansion_Core` | Depends on GUI + Scripts |

**Source Found:** `DayZExpansion/Core/GUI/config.cpp:1-10` → `DayZExpansion_Core_GUI`
**Source Found:** `DayZExpansion/Core/Scripts/config.cpp:3-109` → `DayZExpansion_Core_Scripts`
**Source Found:** `DayZExpansion/Core/Stub/config.cpp:3-12`

Core Scripts registers GUI asset paths in mod defs:

**Source Found:** `DayZExpansion/Core/Scripts/config.cpp:43-62`

## Shared bundle GUI

**Source Found:** `DayZExpansion/GUI/config.cpp:3` → `DayZExpansion_GUI`

Used by main Scripts module for shared layouts (death screen, NV overlay, earplugs):

**Source Found:** `DayZExpansion/Scripts/5_Mission/DayZExpansion/GUI/InGameMenu/InGameMenu.c:92`

Path example: `DayZExpansion/GUI/layouts/ui/expansion_dead_screen.layout`

## UI-capable modules (both GUI + Scripts)

From workspace inventory:

`Core`, `Scripts`, `AI`, `BaseBuilding`, `Book`, `Chat`, `Garage`, `Groups`, `Hardline`, `Market`, `NamalskAdventure`, `NameTags`, `Navigation`, `P2PMarket`, `PersonalStorage`, `PlayerList`, `Quests`, `SpawnSelection`, `Teleporter`, `VanillaFixes`, `Vehicles`

Each Scripts config declares addon like `DayZExpansion_NameTags_Scripts`:

**Source Found:** `DayZExpansion/NameTags/Scripts/config.cpp:16-18`

NameTags GUI stub:

**Source Found:** `DayZExpansion/NameTags/GUI/config.cpp:3-11`

## Expansion menu ID range

Mod menus use ids 1000+ to avoid vanilla collision:

**Source Found:** `DayZExpansion/Core/Scripts/3_Game/DayZExpansion_Core/ExpansionConstants.c:43-48`

| Constant | Value |
|----------|-------|
| `MENU_EXPANSION_MENU_START` | 1000 |
| `MENU_EXPANSION_CODELOCK_MENU` | 1000 |
| `MENU_EXPANSION_NUMPAD_MENU` | 1001 |
| `MENU_EXPANSION_MAP` | 1002 |
| `MENU_EXPANSION_FLAG_MENU` | 1003 |
| `MENU_EXPANSION_MENU_END` | 1004 |

`ExpansionUIManager` filters menus in `[MENU_EXPANSION_MENU_START, MENU_EXPANSION_MENU_END)`.

**Source Found:** `DayZExpansion/Core/Scripts/3_Game/DayZExpansion_Core/ExpansionUIManager.c:93`

## PlayZ sub-mod wiring

PlayZExpansion lists only Expansion script addons it patches:

**Source Found:** `PlayZ_Client/PlayZExpansion/config.cpp:8-21`

PlayZUI declares Core + Scripts deps:

**Source Found:** `PlayZ_Client/PlayZUI/config.cpp:13-14`

## Preload folders

Documented in `DAYZ_EXPANSION_SAKHAL.md:56-67` as `0_DayZExpansion_*_Preload` — may be absent from workspace clone; verify after Steam/sync.

## Related docs

- [02-menu-overrides.md](02-menu-overrides.md)
- [06-sakhal-limited-scope.md](06-sakhal-limited-scope.md)
