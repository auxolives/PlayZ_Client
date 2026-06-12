# UIManager Flow — Mission Integration

This document traces how menus open and close across `MissionMainMenu`, `MissionGameplay`, and `DayZGame` load states. PlayZUI shell rewrites must respect these flows so pause, logout, and loading transitions keep working.

## Entry points

### Main menu mission (`MissionMainMenu`)

On mission start the main menu is shown via `EnterScriptedMenu(MENU_MAIN, null)`. `MainMenu.Init()` sets load state `DayZLoadState.MAIN_MENU_CONTROLLER_SELECT` and fades out the screen.

Source Found: `scripts/5_Mission/GUI/NewUI/MainMenu/MainMenu.c:53-130`

Intro scene (`DayZIntroScenePC`) is owned by `MissionMainMenu` and referenced from `MainMenu.m_ScenePC`.

Source Found: `scripts/5_Mission/GUI/NewUI/MainMenu/MainMenu.c:46-47`

### Gameplay mission (`MissionGameplay`)

Gameplay owns:

- `m_Logout` — `ref LogoutMenu` instance created as submenu of pause menu.
- Inventory lazy-init: `CreateScriptedMenu(MENU_INVENTORY, null)` on first open.

Source Found: `scripts/5_Mission/mission/missionGameplay.c:16`
Source Found: `scripts/5_Mission/mission/missionGameplay.c:212`

## Pause menu flow

Opening pause:

```c
UIScriptedMenu menu = GetUIManager().EnterScriptedMenu(MENU_INGAME, g_Game.GetUIManager().GetMenu());
```

`InGameMenu.Init()` calls `mission.Pause()` and `HudShow(false)` to hide the HUD.

Source Found: `scripts/5_Mission/GUI/InGameMenu.c:36-77`

Closing pause (`~InGameMenu`) calls `HudShow(true)` and `mission.Continue()`.

Source Found: `scripts/5_Mission/GUI/InGameMenu.c:27-34`

## Logout flow

### Creation (`CreateLogoutMenu`)

Triggered when player chooses exit from pause. Guards:

1. Skip if input buffer full (`m_InputBufferFull`).
2. Skip if top menu is closing and not already `MENU_LOGOUT` (DZ-23150).
3. Skip if player dead — calls `AbortMission()` immediately.

On success:

```c
m_Logout = LogoutMenu.Cast(parent.EnterScriptedMenu(MENU_LOGOUT));
m_Logout.SetLogoutTime();
```

`parent` is typically the open `InGameMenu`.

Source Found: `scripts/5_Mission/mission/missionGameplay.c:1328-1356`

### Countdown (`StartLogoutMenu`)

```c
m_Logout.SetTime(time);      // server-provided seconds
m_Logout.Show();
CallLater(m_Logout.UpdateTime, 1000, true);
```

When timer reaches zero, `LogoutMenu.Exit()` → `mission.Continue()` + `AbortMission()`.

Source Found: `scripts/5_Mission/mission/missionGameplay.c:1359-1376`
Source Found: `scripts/5_Mission/GUI/LogoutMenu.c:184-194`

### Cancel path

`LogoutMenu.Cancel()` → `mission.Continue()`, removes timer, `g_Game.LogoutRequestCancel()`.

Source Found: `scripts/5_Mission/GUI/LogoutMenu.c:196-203`

## Menu stack during pause + logout

```
[null or other]
  └── InGameMenu (MENU_INGAME)
        └── LogoutMenu (MENU_LOGOUT)   ← visible during countdown
```

`MissionGameplay` input gate treats `MENU_INGAME`, `MENU_LOGOUT`, and `MENU_RESPAWN_DIALOGUE` specially when paused.

Source Found: `scripts/5_Mission/mission/missionGameplay.c:1303`

## DayZGame load states

`MainMenu.Init()` sets `DayZLoadState.MAIN_MENU_CONTROLLER_SELECT`. Loading screens use a separate native `LoadingScreen` class (not `MENU_LOADING`) during mission connect — see [04-loading-screen-lifecycle.md](04-loading-screen-lifecycle.md).

`DayZGame.CreateScriptedMenu` is the global factory entry used by `UIManager`.

Source Found: `scripts/3_Game/DayZGame.c:1380-1389`

## Screen fade and dialogs

- `g_Game.GetUIManager().ScreenFadeOut(0)` — main menu clears fade on show.
- `ShowDialog(caption, text, id, ...)` — modal overlays; `Back()` does not close menus while dialog visible.

Source Found: `scripts/5_Mission/GUI/NewUI/MainMenu/MainMenu.c:107`
Source Found: `scripts/3_Game/tools/UIManager.c:45-64`

## GetMenu() and gameplay overlays

PlayZCore earplugs toggle checks `GetUIManager().GetMenu() == NULL` before processing `UAEarPlugsToggle`. Any menu on the stack (including hidden logout layout) blocks earplugs.

Source Found: `PlayZ_Client/PlayZCore/scripts/5_Mission/MissionGameplay.c:42`

PlayZUI must not leave orphan menus on the stack or hold invisible menus that block gameplay shortcuts.

## UIManager stack helpers

| Method | Behavior |
|--------|----------|
| `Back()` | Close top menu if no dialog. |
| `CloseAll()` | Walk to root parent, close root. |
| `CloseAllSubmenus()` | Close deepest submenu chain. |
| `HideMenu(id)` | Hide without destroy. |

Source Found: `scripts/3_Game/tools/UIManager.c:62-151`

## Random loading background (shared helper)

`GetRandomLoadingBackground()` in `UIManager.c` returns one of two `Gui/textures/loading_screens/` edds paths. Used by `LoadingMenu`, not the native `LoadingScreen` (which uses `ProgressAsync`).

Source Found: `scripts/3_Game/tools/UIManager.c:251-257`

## PlayZUI flow checklist (milestone 2)

- [ ] Custom `InGameMenu` must still call `mission.Pause()` / `Continue()` via super or explicit calls.
- [ ] Custom `LogoutMenu` layout keeps widget names for PlayZCore ACL patch.
- [ ] Do not intercept `CreateLogoutMenu` without understanding DZ-23150 guard.
- [ ] Test: pause → exit → countdown → cancel → earplugs still work.
