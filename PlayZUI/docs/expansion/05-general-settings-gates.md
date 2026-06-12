# GeneralSettings UI gates

Ops levers in Expansion profile JSON — toggle UI features without script overrides. PlayZUI authors should know these keys before reskinning menus.

## File location

**Path:** `$profile:ExpansionMod/Settings/GeneralSettings.json`

**Class:** `ExpansionGeneralSettings`

**Source Found:** `DayZExpansion/Scripts/3_Game/DayZExpansion/Settings/General/ExpansionGeneralSettings.c:25`

**Constant:** `EXPANSION_GENERAL_SETTINGS` (266, 382)

**Version:** `VERSION = 16` (line 25)

Settings sync to clients via `OnRecieve` / `OnSend` (105-127, 165-175).

---

## UI-relevant keys

| JSON key | Default | Consumer |
|----------|---------|----------|
| `UseDeathScreen` | `true` (:421) | Death overlay enable |
| `UseDeathScreenStatistics` | `true` (:422) | Stats panel on death screen |
| `UseExpansionMainMenuLogo` | `true` (:424) | MainMenu logo swap |
| `UseExpansionMainMenuIcons` | `true` (:425) | Main menu button icons |
| `UseExpansionMainMenuIntroScene` | `true` (:426) | Custom intro scene |
| `UseNewsFeedInGameMenu` | `true` (:427) | Pause menu news feed |
| `UseHUDColors` | `false` (:429) | Custom notifier/stamina colors |
| `HUDColors` | nested object | `ExpansionHudIndicatorColors` |
| `EnableEarPlugs` | `true` (:432) | Expansion earplugs HUD panel |
| `InGameMenuLogoPath` | `"set:expansion_iconset image:logo_expansion_white"` (:433) | Pause menu logo |
| `EnableHUDNightvisionOverlay` | `true` (:415) | NV panel |
| `DisableMagicCrosshair` | `false` (:417) | Crosshair |
| `EnableAutoRun` | `true` (:419) | Auto-run feature |

### Code references

| Key | Source |
|-----|--------|
| MainMenu logo/icons | `Scripts/.../MainMenu/MainMenu.c:19-26` |
| InGameMenu death/news | `Scripts/.../InGameMenu/InGameMenu.c:149-164` |
| InGameMenu logo | `InGameMenu.c:152-156` |
| HUD colors | `Scripts/.../GUI/Hud/IngameHud.c:95-99,280-308` |
| Earplugs HUD | `Scripts/.../GUI/Hud/IngameHud.c:78` |
| Intro scene | `DayZIntroScenePC.c:19-23` |

---

## Non-UI keys (same file)

Server/world sim — not PlayZUI scope:

`DisableShootToUnlock`, gravecross fields, `Mapping`, lamps/generators/lighthouses (27-38, 400-413).

---

## NameTagsSettings (separate file)

**Path:** `$profile:ExpansionMod/Settings/NameTagsSettings.json`

| Key | Effect |
|-----|--------|
| `EnablePlayerTags` | Master switch for floating nametags |

**Source Found:** `.cursor/docs/ENGINE_TRUTH.md:362`

PlayZExpansion Terje name bridges still respect `DisplayPlayerNamesMode` from Terje Start Screen settings.

---

## PlayZUI workflow

Before reskinning a screen, check if GeneralSettings already toggles the feature:

1. Main menu logo → `UseExpansionMainMenuLogo` — PlayZUI layout may override logo widget regardless
2. Death screen → `UseDeathScreen` — must keep `super.Init()` for Expansion overlay
3. News feed → `UseNewsFeedInGameMenu` — widget created in Expansion `InGameMenu.Init`

Disabling via JSON is faster than script override for ops testing.

## Related docs

- [02-menu-overrides.md](02-menu-overrides.md)
- [03-ingame-hud.md](03-ingame-hud.md)
- [../vanilla/13-dz-and-config-notes.md](../vanilla/13-dz-and-config-notes.md)
