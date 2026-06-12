# Expansion menu overrides

Expansion patches vanilla shell menus via `modded class` + `super.Init()` first. PlayZUI must follow the same pattern and preserve widget names Expansion consumes.

## Golden pattern

```c
modded class MainMenu
{
    override Widget Init()
    {
        layoutRoot = super.Init();
        // mutate widgets
        return layoutRoot;
    }
}
```

**Source Found:** `DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/MainMenu/MainMenu.c:15-19`

---

## MainMenu — two layers

### Core (version text)

**Source Found:** `DayZExpansion/DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/MainMenu/MainMenu.c:15-27`

- `super.Init()` → `Expansion_SetGameVersionText(m_Version)`
- `Refresh()` override (22-26)

### Scripts bundle (branding)

**Source Found:** `DayZExpansion/DayZExpansion/Scripts/5_Mission/DayZExpansion/GUI/MainMenu/MainMenu.c:15-46`

Gated by GeneralSettings:
- `UseExpansionMainMenuLogo` → swaps `dayz_logo`
- `UseExpansionMainMenuIcons` → `tutorial_button_image`, `message_button_image`, `settings_button_image`, `exit_button_image`

Intro scene: `DayZIntroScenePC.c:19-23` when `UseExpansionMainMenuIntroScene`.

---

## InGameMenu — Core + Scripts

### Core layer

**Source Found:** `DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/InGameMenu.c:27-58`

- `super.Init()` first
- Hides `server_info` when `StreamerMode`
- `SetGameVersion()` override

### Scripts bundle (death UI)

**Source Found:** `DayZExpansion/Scripts/5_Mission/DayZExpansion/GUI/InGameMenu/InGameMenu.c:74-327`

Wrapped `#ifndef CF_DebugUI` (12, 328).

- Death overlay: `DayZExpansion/GUI/layouts/ui/expansion_dead_screen.layout` (92-118)
- News feed: `ExpansionNewsFeed` (124-129)
- Settings callbacks: `Expansion_OnGeneralSettingsUpdated()` (149-164)
- Death fade in `Update()` (314-327)

**Critical widgets:** `dayz_logo`, `Licensing`, `version`, `copyright`, `ModdedWarning`, `server_info`.

**Anti-pattern:** Replacing `Init()` without `super.Init()` breaks death screen and news feed.

---

## LoadingScreen

Expansion patches constructor — swaps logo images on existing widget handles:

**Source Found:** `DayZExpansion/Scripts/3_Game/DayZExpansion/Client/LoadingScreen/ExpansionLoadingScreen.c:13-29`

```c
if (m_ImageLogoMid)
    m_ImageLogoMid.LoadImageFile(0, "set:expansion_iconset image:logo_expansion_white");
```

No `super` — runs after vanilla `LoadingScreen` constructor binds widgets.

PlayZUI must preserve `ImageLogoMid`, `ImageLogoCorner`, `LoadingBar` names.

See [vanilla/04-loading-screen-lifecycle.md](../vanilla/04-loading-screen-lifecycle.md).

---

## OptionsMenu — EXPANSION tab

**Source Found:** `DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/Options/OptionsMenu.c:23-57`

```c
layoutRoot = super.Init();
int expansionTabIndex = m_Tabber.AddTab("EXPANSION");
m_ExpansionTab = new OptionsMenuExpansion(
    layoutRoot.FindAnyWidget("Tab_" + expansionTabIndex), ...);
```

Tab layout: `DayZExpansion/Core/GUI/layouts/ui/options/expansion_tab.layout`

**Source Found:** `DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/Options/OptionsMenuExpansion.c:33`

Forwards `OnChanged()`, `Apply()`, `Refresh()` to expansion tab.

Downstream: PlayZGunPlay hides sUDE tab **after** Expansion tab injection.

**Source Found:** `PlayZ_Client/PlayZGunPlay/scripts/5_Mission/sUDE/gui/optionsMenu/OptionsMenu.c:12-32`

---

## KeybindingsMenu

Version text only:

**Source Found:** `DayZExpansion/Core/Scripts/5_Mission/DayZExpansion_Core/GUI/KeybindingsMenu/KeybindingsMenu.c:13-28`

---

## LogoutMenu (Namalsk Adventure — reference)

Cosmetic recolor after `super.Init()`:

**Source Found:** `DayZExpansion/NamalskAdventure/Scripts/5_Mission/DayZExpansion_NamalskAdventure/GUI/LogoutMenu.c:14-29`

Not Sakhal scope but shows safe pattern using protected members `m_bCancel`, `m_bLogoutNow`.

---

## MissionBase factory extensions

Expansion adds custom menu ids via `modded class MissionBase`:

**Source Found:** `DayZExpansion/Navigation/Scripts/5_Mission/DayZExpansion_Navigation/MissionBase.c:15-49`

PlayZUI does **not** extend vanilla `MENU_*` ids — use `modded class` on menu classes.

---

## Related docs

- [05-general-settings-gates.md](05-general-settings-gates.md)
- [07-bridge-patterns-conflicts.md](07-bridge-patterns-conflicts.md)
- [../vanilla/12-extension-points-mod-overrides.md](../vanilla/12-extension-points-mod-overrides.md)
