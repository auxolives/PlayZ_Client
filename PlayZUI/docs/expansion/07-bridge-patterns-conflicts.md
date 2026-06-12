# Expansion bridge patterns and conflicts

PlayZExpansion integration rules, `super.Init()` requirements, and merged conflict matrix for PlayZUI milestone 2.

## PlayZExpansion bridge inventory

**Location:** `PlayZ_Client/PlayZExpansion/`

| File | Override | Pattern |
|------|----------|---------|
| `4_World/PlayZExpansionTerjeName.c` | static helper | Server name resolve |
| `5_Mission/PlayZExpansionTerjeNameUI.c` | static helper | Client gating + RPC |
| `5_Mission/IngameHud.c` | nametag methods | `super` first on ShouldShow |
| `5_Mission/ActionTargetsCursor.c` | `GetItemDesc` | After `super` |
| `4_World/ExpansionGlobalChatModule.c` | **Full** `AddChatMessage_Server` | No smaller seam |
| `4_World/ExpansionKillfeedModule.c` | `GetIdentityName` | `super` fallback |
| `4_World/ExpansionP2PMarketListing.c` | `SetFromItem` | After `super` |

**Source Found:** respective files under `PlayZ_Client/PlayZExpansion/scripts/`

### Identity policy

**Source Found:** `.cursor/docs/ENGINE_TRUTH.md:353-363`

- **Meta surfaces** (P2P, killfeed, chat): always Terje full name
- **World UI** (nametags, corpse cursor): respect `DisplayPlayerNamesMode` / face cover

### AI cooldown suppression

**Source Found:** `PlayZ_Client/PlayZExpansion/scripts/5_Mission/IngameHud.c:64-71`

Forces aggression cooldown HUD hidden. Server logic unchanged.

Requires `DayZExpansion_AI_Scripts` in deps.

---

## super.Init() anti-patterns

| Anti-pattern | Breaks |
|--------------|--------|
| `MainMenu.Init()` without `super.Init()` | Expansion logo/icons, version text |
| `InGameMenu.Init()` without `super` | Death screen, news feed, licensing |
| `OptionsMenu.Init()` without `super` | EXPANSION tab; wrong tab indices for GunPlay hide |
| `LoadingScreen` ctor breaking vanilla widget bind | Progress/logo wiring |
| PlayZUI `modded class IngameHud` | Conflicts PlayZExpansion nametag bridges |

### Correct pattern

```c
layoutRoot = super.Init();
// mutate widgets / hide tabs by index
```

Refs:
- `DayZExpansion/Core/.../MainMenu.c:17`
- `DayZExpansion/Scripts/.../InGameMenu.c:76`
- `PlayZGunPlay/.../OptionsMenu.c:7`

---

## Bridge pattern summary

1. **Narrow seam preferred** — single method override, `super` first
2. **Full-method override when no hook** — `ExpansionGlobalChatModule`; diff upstream on upgrades
3. **Shared helpers** — server vs client name resolution split
4. **Load after PlayZUI** — PlayZExpansion wins symbol conflicts on PlayZ chain

**Source Found:** `PlayZ_Client/PlayZExpansion/config.cpp:19` (`PlayZUI` in requiredAddons)

---

## Conflict matrix

| # | Surface | Mods | Resolution |
|---|---------|------|------------|
| 1 | `MainMenu.Init` | Expansion → PlayZUI | `super.Init()`; preserve `dayz_logo`, `*_button_image` |
| 2 | `InGameMenu.Init` | Expansion → PlayZUI | `super.Init()`; death-screen widgets |
| 3 | `OptionsMenu` tabs | Expansion → GunPlay → PlayZUI | EXPANSION tab before sUDE hide |
| 4 | `LoadingScreen` | Expansion → PlayZUI | Keep logo + `LoadingBar` widget names |
| 5 | `LogoutMenu` | PlayZCore → PlayZUI | Preserve ACL widget names |
| 6 | `IngameHud` | Expansion → Terje → PlayZExpansion | PlayZUI must not touch |
| 7 | `Expansion_CanShowHUDElements` | Expansion Core | Pause hides HUD elements |
| 8 | Terje names | NameTags, chat, killfeed, P2P | PlayZExpansion bridges |
| 9 | AI cooldown HUD | AI → PlayZExpansion | Force hidden |
| 10 | Earplugs | PlayZCore vs menus | `GetMenu()==null` gate |
| 11 | Chat module | PlayZ full override | Diff on Expansion upgrade |
| 12 | ScriptView vs pause | Expansion MissionGameplay | Blocks `Pause()` |
| 13 | Terje Start Screen | Terje → PlayZUI | Layout-only overrides |
| 14 | Symbol winner | Reference vs PlayZ | **PlayZ wins** |

Full detail: [../playz/03-load-order-conflicts.md](../playz/03-load-order-conflicts.md)

---

## Testing checklist

1. Main menu: Expansion logo + PlayZ layout + version
2. Pause: death screen + news feed from GeneralSettings
3. Options: EXPANSION tab visible; sUDE hidden
4. Loading: both LoadingScreen paths
5. Nametags: Terje names; hidden on ESC
6. Corpse cursor: per face-cover mode
7. Chat/killfeed/P2P: Terje names live test

---

## Upgrade maintenance

On DayZ Expansion version bump:

1. Diff `AddChatMessage_Server` in Expansion Chat module
2. Diff menu `Init()` overrides in Core + Scripts bundles
3. Verify GeneralSettings version migration (`VERSION = 16`)
4. Re-run conflict matrix tests

**Source Found:** `.cursor/docs/ENGINE_TRUTH.md:364`

## Related docs

- [02-menu-overrides.md](02-menu-overrides.md)
- [03-ingame-hud.md](03-ingame-hud.md)
- [../BRIDGES.md](../BRIDGES.md)
- [../playz/02-sibling-modules.md](../playz/02-sibling-modules.md)
