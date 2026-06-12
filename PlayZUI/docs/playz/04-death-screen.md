# PlayZ custom death screen

PlayZ-native minimalist death flow in `PlayZUI`. Replaces vanilla “YOU ARE DEAD” text fade and the DayZ Expansion death overlay (`UseDeathScreen: false` on Sakhal).

**Status:** verified in-game (2026-06-12).

## Player flow

| Phase | Timing | What the player sees |
|-------|--------|----------------------|
| **Blackout** | Instant on death | Pitch black (`UIManager.ScreenFadeIn(0)`), world audio muted |
| **Hold** | `DEATH_BLACK_HOLD_SEC` (default 2s) | Stays black; ESC blocked |
| **Picture reveal** | `DEATH_REVEAL_PICTURE_SEC` | Deathscreen image + 70% overlay fade in under a dissolving black cover |
| **Button reveal** | `DEATH_REVEAL_BUTTONS_DELAY_SEC` then `DEATH_REVEAL_BUTTONS_SEC` | Respawn / Exit fade in under a second cover (staggered) |
| **Hold** | Until action | Layout stays visible — no fade-out |

Tune all durations in `PlayZUIPaths.c`.

**Source Found:** `PlayZ_Client/PlayZUI/scripts/3_Game/PlayZUIPaths.c:16-19`

## Layout (`playz_death_screen.layout`)

Z-order (bottom → top):

| Widget | Role |
|--------|------|
| `death_black_backdrop` | Solid black fallback behind everything |
| `death_background` | `Deathscreen_01.edds` (`mode blend`) |
| `death_overlay` | 70% black wash |
| `death_picture_cover` | Full-screen black panel; alpha 1→0 during picture reveal |
| `death_actions` | Respawn (`respawn_button`) + Exit (`exitbtn`) |
| `death_buttons_cover` | Full-screen black panel; alpha 1→0 after button delay |

**Critical design rule:** Content widgets (image, overlay, buttons) stay at **full opacity**. Reveal is driven only by the two **cover panels**. Do not animate `SetAlpha()` on `death_background` or `death_actions` — that pattern caused post-reveal fade-out bugs when combined with engine darkening.

Widget names `respawn_button` and `exitbtn` match vanilla / Terje pause bindings.

## Script map

| File | Role |
|------|------|
| `PlayZUIPaths.c` | Layout paths, texture path, timing constants |
| `PlayZUIDeathScreenState.c` | Intro/menu flags, blackout, `OpenDeathMenu()`, audio silence, `MaintainDeathMenuView()` |
| `PlayZUIPPEDeathDarkening.c` | Blocks `PPERequester_DeathDarkening.OnStart` while custom death is active |
| `PlayZUIDayZPlayerImplement.c` | Custom `SimulateDeath` / `ShowDeadScreen`; no vanilla death timer or `ScreenFadeIn(duration)` |
| `PlayZUIPlayerBase.c` | No-op `SetDeathDarknessLevel` on local player; clears sVisual overlays on death |
| `PlayZUIDeathScreenCompat.c` | Terje maintenance / Start Screen guards (`PlayZDeathScreen_ShouldUseCustomFlow`) |
| `PlayZUIInGameMenu.c` | Death vs pause `Init()`; cover-based reveal in `Update(timeslice)` |
| `PlayZUIMissionGameplay.c` | Pause/continue blocks; `MaintainDeathMenuView()` while menu open |

`InGameMenu.Init()` does **not** call `super.Init()` in death mode — death layout is standalone. Pause mode uses `playz_ingamemenu.layout` and Expansion news feed as before.

## Why vanilla darkening was breaking the UI

Three engine systems were re-darkening the framebuffer **after** the reveal finished:

1. **`DeathEffectTimer`** — `SimulateDeath()` starts a 50ms timer calling `SetDeathDarknessLevel()`, which restarts `PPERequester_DeathDarkening` with rising progress (~2.5s). **Fix:** custom `SimulateDeath` skips the timer; `SetDeathDarknessLevel` is a no-op on the local player during custom death.

2. **`PPERequester_DeathDarkening`** — Terje Medicine sets exposure to `-1000` on start. Affects the whole screen, not just the 3D world. **Fix:** `PlayZUIPPEDeathDarkening.c` refuses `OnStart` while `PlayZDeathScreen_IsCustomDeathActive()`; `StopBlackout()` runs every frame while the death menu is open.

3. **`UIManager.ScreenFadeIn(duration)`** — vanilla `ShowDeadScreen(true, 2.5)` fades the full screen to black over `DEFAULT_DYING_TIME`. **Fix:** custom flow never calls `super.ShowDeadScreen` on death; `PlayZDeathScreen_ClearEngineFade()` forces `ScreenFadeOut(0)` while the menu is open.

**Source Found:** `scripts/4_World/Entities/DayZPlayerImplement.c:835-872` (vanilla timer + `ShowDeadScreen`)
**Source Found:** `TerjeMedicine/Scripts/3_Game/PPEManager/Requesters/PPERequester_DeathDarkening.c:1-8`

Re-entry guards on `SimulateDeath` / `ShowDeadScreen` prevent `CheckDeath` from restarting the flow.

## Third-party compatibility

| Mod | Behaviour |
|-----|-----------|
| **DayZ Expansion** | `GeneralSettings.UseDeathScreen: false` — Expansion death overlay unused. Pause news feed unchanged. |
| **Terje Start Screen** | Maintenance / not-ready deaths bypass custom flow (`PlayZUIDeathScreenCompat.c`) → vanilla path. |
| **sVisual** | `SCameraOverlaysManager.deactivateAll()` on custom death (`PlayZUIPlayerBase.c`). |
| **Terje Medicine PPE** | Death darkening blocked during custom death via `PlayZUIPPEDeathDarkening.c`. |

## ESC and pause

- **Intro (black hold):** `PlayZDeathScreen_ShouldBlockPause()` → ESC ignored.
- **After menu open:** player is dead → pause still blocked; only Respawn / Exit.
- **Terje maintenance death:** vanilla pause/death behaviour (guards in `PlayZUIMissionGameplay.c`).

## Maintenance helpers

```text
PlayZDeathScreen_IsIntroActive()   — black hold before menu
PlayZDeathScreen_IsMenuMode()      — death layout open (MENU_INGAME)
PlayZDeathScreen_IsCustomDeathActive() — intro OR menu (3_Game flag API)
PlayZDeathScreen_MaintainDeathMenuView() — Stop PPE + clear engine screen fade
```

After reveal completes, `PlayZUIInGameMenu.Update` keeps cover alphas at 0 and calls `MaintainDeathMenuView()` every frame.

## Do not regress

- [ ] Reveal uses **cover panels only** — never fade content widget alpha for the deathscreen/buttons.
- [ ] Custom `SimulateDeath` must **not** start `DeathEffectTimer` or call vanilla `ShowDeadScreen(show, duration>0)`.
- [ ] Keep `PlayZUIPPEDeathDarkening` and per-frame `MaintainDeathMenuView()` while menu is open.
- [ ] Death `Init()` must not call `super.Init()` (would mount Expansion death widgets on the wrong layout).
- [ ] Preserve `respawn_button` / `exitbtn` widget names for Terje respawn wiring.
- [ ] Pack `Deathscreen_01.edds` via `.edds.meta` scaffold under `gui/textures/`.

## Related docs

- [../BRIDGES.md](../BRIDGES.md) — integration checklist
- [../vanilla/06-screen-ingame-menu.md](../vanilla/06-screen-ingame-menu.md) — vanilla / Expansion pause context
- [../expansion/05-general-settings-gates.md](../expansion/05-general-settings-gates.md) — `UseDeathScreen` gate
- [../terje/02-terje-start-screen.md](../terje/02-terje-start-screen.md) — Terje death / respawn interaction
