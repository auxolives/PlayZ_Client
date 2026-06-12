# Terje HUD, skills, medicine, and radiation UI

Inventory skills panel and in-game HUD extensions. Owned by Terje mods — PlayZUI documents only; behavior changes go in PlayZTerje*.

## HUD extension chain

`modded class IngameHud` merges in load order:

1. TerjeCore — infrastructure
2. TerjeMedicine — disease/healing badges + notifiers
3. TerjeRadiation — radiation badges
4. TerjeStartScreen — souls counter badge
5. PlayZTerjeMedicine — suppresses selected badges
6. PlayZExpansion — nametag bridges (not Terje HUD)

**Source Found:** `TerjeCore/Scripts/5_Mission/MissionGameplay.c:7-10` (`InitConditionalTerjeBadgesAndNotifiers`)

Mission tick hooks:
- `OnUpdateTerjeCustomBadges`
- `OnUpdateTerjeCustomGUI`

**Source Found:** `TerjeCore/Scripts/5_Mission/MissionGameplay.c:37-65`

---

## Badge registration (TerjeCore)

**Source Found:** `TerjeCore/Scripts/5_Mission/IngameHud.c:108-196`

### RegisterTerjeBadgetWidget

Clones `TerjeCore/Layouts/BadgeTemplate.layout`, adds to vanilla `m_Badges` panel.

Badge types (`TerjeCore/Scripts/5_Mission/TerjeBadgeType.c:1-4`):
- `DEFAULT`, `COUNTER`, `LEVELED`

`DisplayBadge` override: Roman numerals for `LEVELED`, numeric for `COUNTER`, optional colorization via `GetTerjeBadgeColor` when `CORE_COLORIZED_HUD_BADGES` enabled (144-196).

### RegisterTerjeNotifierWidget

**Source Found:** `TerjeCore/Scripts/5_Mission/IngameHud.c:18-106`

Clones `TerjeCore/Layouts/TendencyTemplate.layout`, extends `NotifiersPanel`, loads 5 icon frames from `{ID}` placeholder in imageset path.

### Overlay root

**Source Found:** `TerjeCore/Scripts/5_Mission/IngameHud.c:230-233`

`GetTerjeOverlayRoot()` — full-screen `FrameWidget` for mod HUD overlays.

---

## TerjeMedicine HUD

**Source Found:** `TerjeMedicine/Scripts/5_Mission/IngameHud.c:47-135`

### Conditional notifiers (60-84)

| Notifier | Imageset | Gate |
|----------|----------|------|
| `TERJE_NOTIFIER_SLEEPING` | `TerjeMedicine_icon image:tm_sleeping_{ID}` | `MEDICINE_SLEEPING_ENABLED` |
| `TERJE_NOTIFIER_MIND` | `TerjeMedicine_icon image:tm_mind_{ID}` | `MEDICINE_MIND_ENABLED` |

### Badges (86-135)

11 disease + 22 healing/treatment badges. Replaces vanilla bleeding icon with Terje scratch (91-95).

### Knockout overlay

**Source Found:** `TerjeMedicine/Scripts/5_Mission/IngameHud.c:47-57,196-219`

Creates `TerjeCore/Layouts/TerjeWidgetTextCentered.layout` on HUD panel; shows `#STR_TERJEMED_KNOCKOUT_INFO` when `MEDICINE_KNOCKOUT_SHOW_INFO`.

### Badge updates

**Source Found:** `TerjeMedicine/Scripts/5_Mission/MissionGameplay.c:40-101`

Settings: `CORE_DETAILED_DISEASE_HUD_BADGES`, `CORE_DETAILED_HEALING_HUD_BADGES` (`TerjeCore/Scripts/5_Mission/MissionGameplay.c:48-49`).

---

## TerjeRadiation HUD

**Source Found:** `TerjeRadiation/Scripts/5_Mission/IngameHud.c:6-11`

| Badge | Imageset | Type |
|-------|----------|------|
| `TERJE_BADGE_RADIATION` | `TerjeRadiation_icon image:tr_rad_sickness` | LEVELED |
| `TERJE_BADGE_ANTIRAD` | `TerjeRadiation_icon image:tr_antirad` | LEVELED |

Updates: `TerjeRadiation/Scripts/5_Mission/MissionGameplay.c:15-35`

PPE radiation effect in `OnUpdateTerjeCustomGUI` (30-35).

---

## PlayZTerjeMedicine HUD suppressions

**Source Found:** `PlayZ_Client/PlayZTerjeMedicine/scripts/5_mission/IngameHud.c:1-16`

Suppresses registration of:
- `"TerjeMind"` notifier
- `"TerjeVacinaC"` badge

---

## Skills panel (inventory UI)

Not HUD — lives in inventory right column.

### Insertion point

**Source Found:** `TerjeSkills/Scripts/5_Mission/RightArea.c:15-52`

Lazy `TerjeSkillsContainer` when `GetTerjeSkillsRegistry().IsReadyToDisplay()`.

### TerjeSkillsContainer

**Source Found:** `TerjeSkills/Scripts/5_Mission/TerjeSkillsContainer.c:5-31`

Header: `#STR_TERJESKILL_HEADER`. Hidden skills respect `SKILLS_HIDDEN_SKILLS` settings (28-31).

### TerjeSkillWidget

**Source Found:** `TerjeSkills/Scripts/5_Mission/TerjeSkillWidget.c:51-376`

| Asset | Path |
|-------|------|
| Skill row | `TerjeSkills/Layouts/TerjeSkillLayout.layout` |
| Perk row | `TerjeSkills/Layouts/TerjePerkLayout.layout` |
| Tooltips | `TerjeSkillTooltip.layout`, `TerjePerkTooltip.layout` |

RPC: `TRPC_PLAYER_PERK_APPLY`, `TRPC_PLAYER_PERKS_RESET` (141, 233).

Imagesets: `TerjeSkillBorders_icon`, `TerjePerkLevels_icon` (364-376).

### PlayZTerjeSkills overrides

**Source Found:** `PlayZ_Client/PlayZTerjeSkills/scripts/5_mission/TerjeSkillWidget.c:1-78`

- Hides `terje_skill_header_points`
- Aggregates points into container header with `#STR_PLAYZ_GLOBAL_PTS_LABEL`
- Custom perk highlight behavior

### Tooltip host

**Source Found:** `TerjeSkills/Scripts/5_Mission/ItemManager.c:23-69`

Separate from vanilla tooltip; uses `m_RootWidget` as parent.

---

## PlayZUI scope

PlayZUI does **not** reskin Terje HUD badges or skills panel in milestone 2 unless explicitly scoped. Start Screen pages only.

## Related docs

- [05-playz-bridge-patterns.md](05-playz-bridge-patterns.md)
- [../playz/02-sibling-modules.md](../playz/02-sibling-modules.md)
- [../expansion/03-ingame-hud.md](../expansion/03-ingame-hud.md)
