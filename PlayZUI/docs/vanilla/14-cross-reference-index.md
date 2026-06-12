# Cross-Reference Index — Screens, Classes, Layouts

Master lookup table for PlayZUI milestone 2. All paths relative to workspace root.

## Shell menus

| Screen | MENU_* | Value | Class | Script | Layout | Key widgets |
|--------|--------|-------|-------|--------|--------|-------------|
| Main menu | MENU_MAIN | 13 | MainMenu | `scripts/5_Mission/GUI/NewUI/MainMenu/MainMenu.c` | `gui/layouts/new_ui/main_menu.layout` | play, exit_button, settings_button, version, ModdedWarning, character_rotation_frame |
| Pause | MENU_INGAME | 9 | InGameMenu | `scripts/5_Mission/GUI/InGameMenu.c` | `gui/layouts/day_z_ingamemenu.layout` | continuebtn, exitbtn, optionsbtn, hint_frame, server_info |
| Logout | MENU_LOGOUT | 26 | LogoutMenu | `scripts/5_Mission/GUI/LogoutMenu.c` | `gui/layouts/day_z_logout_dialog.layout` | txtLogoutTime, txtDescription, bLogoutNow, bCancel |
| Options (PC) | MENU_OPTIONS | 14 | OptionsMenu | `scripts/5_Mission/GUI/NewUI/Options/OptionsMenu.c` | `gui/layouts/new_ui/options/pc/options_menu.layout` | Tabber, Tab_0…, apply, back, settings_details |
| Loading menu | MENU_LOADING | 12 | LoadingMenu | `scripts/5_Mission/GUI/LoadingMenu.c` + `PlayZUILoadingMenu.c` | `PlayZ_Client/PlayZUI/gui/layouts/playz_loading.layout` | TextWidget, LoadingBar, ImageBackground |
| Loading screen | — | — | LoadingScreen | `scripts/3_Game/DayZGame.c` + `PlayZUILoadingScreen.c` | `PlayZ_Client/PlayZUI/gui/layouts/playz_loading.layout` | LoadingBar, ImageLogoMid, ImageBackground |
| Login queue | MENU_LOGIN_QUEUE | 30 | LoginQueueBase / LoginQueueStatic | `scripts/3_Game/DayZGame.c` + `PlayZUILoginQueueBase.c` | `PlayZ_Client/PlayZUI/gui/layouts/playz_dialog_queue_position.layout` | txtPosition, btnLeave, Background |
| Login timer | MENU_LOGIN_TIME | 38 | LoginTimeBase / LoginTimeStatic | `scripts/3_Game/DayZGame.c` + `PlayZUILoginTimeBase.c` | `PlayZ_Client/PlayZUI/gui/layouts/playz_dialog_login_time.layout` | txtLabel, txtDescription, btnLeave, Background |
| Server password | — | — | engine C++ | — | `gui/layouts/dialog_input_password.layout` (PlayZUI override) | PrimaryPasswordEditBox, ButtonOk, ButtonCancel, Background |
| Loading hints (child) | — | — | UiHintPanelLoading | `scripts/3_Game/GUI/Hints/UiHintPanel.c:293-299` | `gui/layouts/new_ui/hints/in_game_hints_load.layout` | HeadlineLabel, HintDescLabel; data: `scripts/data/hints.json` |
| Pause hints (child) | — | — | UiHintPanel | `scripts/3_Game/GUI/Hints/UiHintPanel.c:5-290` | `gui/layouts/new_ui/hints/in_game_hints.layout` | HeadlineLabel, HintDescLabel, LeftButton, RightButton |
| Keybindings | MENU_KEYBINDINGS | 34 | KeybindingsMenu | `scripts/5_Mission/GUI/NewUI/Keybindings/KeybindingsMenu.c` | `gui/layouts/new_ui/options/pc/` (child) | — |
| Presets | MENU_CONTROLS_PRESET | 20 | PresetsMenu | `scripts/5_Mission/GUI/PresetsMenu.c` | options pc child layouts | — |

Source Found: `scripts/3_Game/constants.c:170-215`
Source Found: `scripts/5_Mission/mission/missionBase.c:185-299`

## Factory entry

| Layer | Method | File |
|-------|--------|------|
| UIManager | `CreateScriptedMenu(id, parent)` | `scripts/3_Game/tools/UIManager.c:5` |
| DayZGame | `CreateScriptedMenu(id)` | `scripts/3_Game/DayZGame.c:1380` |
| Mission | `CreateScriptedMenu(id)` switch | `scripts/5_Mission/mission/missionBase.c:185` |

## Mission flows

| Flow | Method | File |
|------|--------|------|
| Open pause | `EnterScriptedMenu(MENU_INGAME, …)` | `scripts/5_Mission/mission/missionGameplay.c:1285` |
| Create logout | `CreateLogoutMenu(parent)` | `scripts/5_Mission/mission/missionGameplay.c:1328` |
| Start countdown | `StartLogoutMenu(time)` | `scripts/5_Mission/mission/missionGameplay.c:1359` |

## Options tab handlers

| Tab | Class | Script |
|-----|-------|--------|
| Game | OptionsMenuGame | `scripts/5_Mission/GUI/NewUI/Options/OptionsMenuGame.c` |
| Sounds | OptionsMenuSounds | `scripts/5_Mission/GUI/NewUI/Options/OptionsMenuSounds.c` |
| Video | OptionsMenuVideo | `scripts/5_Mission/GUI/NewUI/Options/OptionsMenuVideo.c` |
| Controls | OptionsMenuControls | `scripts/5_Mission/GUI/NewUI/Options/OptionsMenuControls.c` |

## PlayZ_Client overlays (not vanilla)

| Feature | Class | Script | Layout |
|---------|-------|--------|--------|
| Earplugs | EarPlugsWidget | `PlayZ_Client/PlayZCore/scripts/5_Mission/EarPlugsWidget.c` | `PlayZ_Client/PlayZCore/gui/earplugs.layout` |
| ACL logout | LogoutMenu (modded) | `PlayZ_Client/PlayZCore/scripts/5_Mission/gui/LogoutMenu_AntiCombatLog.c` | uses vanilla widget names |

## Terje (post-spawn)

| Screen | Class | Script | Layout override |
|--------|-------|--------|-----------------|
| Start wizard | TerjeStartScreenMenu | `TerjeStartScreen/Scripts/5_Mission/TerjeStartScreenMenu.c` | Terje internal + page GetNativeLayout |
| Page name | TerjeStartScreenPageName | `TerjeStartScreen/Scripts/5_Mission/TerjeStartScreenPageName.c` | `TerjeStartScreen/Layouts/TerjeStartScreenPageName.layout` |

## Expansion menu mods (read-only)

| Class | Script |
|-------|--------|
| MainMenu | `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/MainMenu/MainMenu.c` |
| InGameMenu | `DayZExpansion/DayZExpansion/Scripts/5_Mission/DayZExpansion/GUI/InGameMenu.c` |
| OptionsMenu | `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/Options/OptionsMenu.c` |

## PlayZUI milestone 2 targets (planned)

| Screen | Planned PlayZ layout |
|--------|---------------------|
| Main | `PlayZ_Client/PlayZUI/gui/layouts/playz_main_menu.layout` |
| Pause | `PlayZ_Client/PlayZUI/gui/layouts/playz_ingamemenu.layout` |
| Logout | `PlayZ_Client/PlayZUI/gui/layouts/playz_logout_dialog.layout` |
| Loading | `PlayZ_Client/PlayZUI/gui/layouts/playz_loading.layout` — **implemented** |
| Login queue | `PlayZ_Client/PlayZUI/gui/layouts/playz_dialog_queue_position.layout` — **implemented** |
| Login timer | `PlayZ_Client/PlayZUI/gui/layouts/playz_dialog_login_time.layout` — **implemented** |
| Server password | `PlayZ_Client/PlayZUI/gui/layouts/dialog_input_password.layout` — **implemented** |
| Options PC | `PlayZ_Client/PlayZUI/gui/layouts/new_ui/options/pc/playz_options_menu.layout` |

Implementation status: connect shell **implemented** (milestone 2 slice); other screens docs only.

**Connect shell:** see [15-linked-screen-flows.md](15-linked-screen-flows.md).
