# PlayZ_Client

Shared PlayZ sub-mods for the **Sakhal** server. Everything here is packed into PBOs loaded by **both** clients and the dedicated server through `-mod=`.

Sakhal also loads **DayZ Expansion** as a separate third-party mod (limited scope — mainly airdrops). That stack is **not** part of `PlayZ_Client/`. See [.cursor/docs/DAYZ_EXPANSION_SAKHAL.md](../.cursor/docs/DAYZ_EXPANSION_SAKHAL.md).

## Rules

- Entity/config classes, UI, inputs, models, sounds, textures, NetSync variables, and client-observable RPC contracts belong here.
- Every sub-mod must have its own `config.cpp` with its own `CfgPatches.<Name>` entry so it packs as an independent PBO.
- Script `files[]` paths use the workspace prefix `PlayZ_Client/<AddonName>/scripts/...` (see existing `PlayZCore/config.cpp`).
- `requiredAddons[]` may list engine addons (`DZ_Data`, `DZ_Scripts`), other `PlayZ_Client/` sub-mods, or DayZ Expansion script addons when a sub-mod integrates Expansion (e.g. `PlayZExpansion`). List only the Expansion modules the sub-mod actually uses; load `@PlayZExpansion` after Expansion workshop PBOs on the mod line.
- **Must not** require or reference any `PlayZ_Server/` addon or class.

## Split-mod pattern (when a feature needs both sides)

Some server features need a client-only API (e.g. `GetCurrentCameraPosition()`). Keep the client footprint minimal:

- `PlayZ_Client/<Feature>Client/` (client + server) — shared RPC constants and the client-side handler that samples state and echoes it back. Nothing else.
- `PlayZ_Server/<Feature>/` (server only) — all logic, I/O, config, scheduling, detection. Lists `"<Feature>Client"` in `requiredAddons[]`.

## Deployment

Dedicated server and clients share the same `-mod=` chain:

```text
DayZServer_x64.exe -mod="@PlayZCore;@PlayZAntiCheatClient;..." -servermod="@PlayZAntiCheat;@PlayZLogs;..." -config=serverDZ.cfg
```

Clients never receive `-servermod=`.

## Packing

- Workspace sources: `PlayZ_Client/<AddonName>/`
- Mikero mirror (pack script): `P:\PlayZ_Client\` — map P: to this tree or edit `SOURCE_ROOT` in `.vscode/scripts/Build-PlayZ_Client.bat`.
- Cursor/VS Code: **Ctrl+Shift+B** → **PlayZ: Build Client PBOs (all)** (workspace `.vscode/tasks.json`).

Set `MOD_OUT` in `.vscode/scripts/Build-PlayZ_Client.bat` to your CFTools `@PlayZ_Client` deployment folder.

## Current sub-mods

- `PlayZCore` — anti-combat logout, mouth-cover eat/drink block (`#STR_PlayZ_MouthBlocked`), attached-backpack cargo hide (waist bags exempt), shortcuts (`V` lie down, `B` backpack, `M` face cover), crafting/environment tweaks. Config: `$profile:PlayZ/Core.json`.
- `PlayZAntiCheatClient` — client stub for `PlayZ_Server/PlayZAntiCheat` camera spot-check (RPC constants + `GetCurrentCameraPosition` response). Load before or with server `-servermod=@PlayZAntiCheat`; server `requiredAddons[]` already lists this patch.
- `PlayZWeather` — scenario-driven weather + client PPE on **Sakhal** (`modded class SakhalData`). Config: `$profile:PlayZ/Weather.json`, `$profile:PlayZ/PPE.json`. Toggle with `m_EnablePlayZWeather` to fall back to vanilla Sakhal weather.
- `PlayZCOTWeather` — optional COT Weather panel **scenario:** buttons (one per PlayZ scenario, natural transition via `ApplyScenario`). Requires `JM_COT_Scripts` + `PlayZWeather` in `-mod=` on server and admin clients. Grant COT permission `Weather.Scenario`.
- `PlayZLighting` — custom global lighting profiles (server `lightingConfig` IDs **60–64**). Map-agnostic; vanilla Sakhal ID **2** still works via `super` when those IDs are not used.
- `PlayZSakhal` — altitude hypoxia on **Sakhal** only: stamina cap penalty above **350 m** (full at **600 m**), client chrom/blur PPE, sprint breath audio. Winter headgear + glasses soften PPE only (no stamina mitigation without pressurized gear). Tunables in `GameConstants.c` (`PLAYZ_SAKHAL_HYPOXIA_*`).
- `PlayZAsmond` — vanilla-name aliases for Asmond clothing (~900) and weapons (~300) under `DZ/characters/` and `DZ/weapons/`. Requires `AsmondClothing` and `AsmondWeapons` in `-mod=`; assets stay in those mods, PlayZ only forwards `Asmond_*` into vanilla class names (`scope=2`).
- `PlayZTerjeRadiation` — vanilla clothing radiation protection, dry bag/drysack isolation, two-stack client PPE (requires `TerjeRadiation` in `-mod=`). **Environmental** (outdoors): zone + rain/snow dose on Terje 0.6–5.0 scale — full desaturation 0.6→1.1, film grain 1.2→5.0. **Body buffer** (`GetTerjeRadiation()` 0–5000, works indoors): olive vignette 500→2000, Gauss fever blur 1000→3000, radial blur 1000→5000, HMP ghost pulses 2000→5000. Replaces Terje’s default sickness colorization. Tunables in `PlayZRadPPE.c`.
- `PlayZTerjeStartScreen` — when `StartScreen.LastNameEnabled = true`, last name is shown but optional; first name stays required. Custom `page_name.layout` + `STR_PLAYZ_TERJESTARTSCREEN_*` strings in `PlayZTerjeCore`. Load after `TerjeStartScreen`, before `PlayZUI` / `PlayZExpansion`.
- `PlayZUI` — Sakhal UI rework (menus, loading, Terje Start Screen skins). Load after `PlayZCore` / `PlayZTerje*` and before `PlayZExpansion`. See [PlayZUI/README.md](PlayZUI/README.md).
- `PlayZInedia` — Inedia infected AI pathgraph tweaks (see `PlayZInedia/config.cpp`).
- `PlayZInfectedSounds` — config-only infected voice retune (`DZ/sounds/config.cpp` voice banks + screamers; `DZ/sounds/mindstate/config.cpp` generated mind-state overrides; `DZ/characters/zombies/config.cpp` AnimEvents). Regenerate mind-state: `.vscode/scripts/Generate-PlayZInfectedMindState.ps1`. Patches: `DZ_Sounds_PlayZInfectedSounds`, `DZ_Sounds_PlayZInfectedSounds_MindState`, `PlayZInfectedSounds_Zombies`.
- `PlayZJammingSyncFix` — disables firearm jamming (`JamCheck` false, blocks `SetJammed(true)`, clears persisted jam on load). Load after third-party weapon jam overrides when present.
- `PlayZTerjeJMPlayerFormCOTFix` — drop-in replacement for workshop `TerjeCompatibilityCOT` (fixed COT Player perks tab: no `CreateGridSpacer(result, skillCount, 1)` overflow). **Remove `TerjeCompatibilityCOT` from `-mod=`** when this sub-mod is packed; keep `JM_COT_Scripts` + `TerjeSkills`.
- `PlayZsVisual` — disables sVisual bleeding PPE (`SPPERequester_BloodLoss`) and blood overlay (`SCOBleeding`); Terje pain PPE only. Load after workshop `sVisual`. Hit-flash (`SPPERequester_HitReceived`) unchanged.
- `PlayZmCommandWeaponsFix` — guards null `m_CommandWeapons` in `DayZPlayerCamera1stPerson` (`UpdateUDAngleUnlocked` access violation). Load **last** in `@PlayZ_Client` (after `sVisual` / Expansion).
- `PlayZNoBase` — blocks crafting `FenceKit`, `WatchtowerKit`, and `TerritoryFlagKit` (recipe `CanDo` false). Looted/spawned kits still deploy. Load after Expansion Base Building if that workshop module is on the mod line.
- `PlayZGas` — gas contaminated zones (`ContaminatedArea_Static`): gas mask + filter on MASK slot is sufficient; skips NBC body-slot bleeding from `AreaExposureMdfr`. Halves mask filter/oxygen consumption (vanilla `MaskMdfr` + Terje `Radiation.ZoneGasMaskFilterConsumption`). Cold cyan particles (`graphics/particles/playz_gas_*`) + `PPERequester_PlayZGasAreaTint` (reference in mission `cfgeffectarea.json`). Load after `DZ_Scripts`; clients need `@PlayZGas` for particles/PPE.
- `PlayZNotes` — write/read/placed survivor notes (pen + paper → `PlayZNote`). Vanilla-font GUI, paper stacking, pen ink consumption, fireplace fuel, damage overlay. Config: `$profile:PlayZ/Notes.json` (`PenConsumeQuantity`, `MaxNoteLength`, `DeleteAllNotes` one-shot wipe). Requires `PlayZTerjeCore` (strings). Note writes logged via `PlayZLogs` (`EnableLogNotes` in `$profile:PlayZ/Log.json`). Based on ZenNotes by Zenarchist. Load after `PlayZCore`.
- `PlayZNotification` — center-screen sequential toast queue (title + message, no icons/sound). Intercepts `NotificationSystem.AddNotif` for Terje, Inedia type-2, Expansion, and COT toasts; drops Expansion killfeed. Config: **server** `$profile:PlayZ/Notification.json` (`ShowTitle`, `ShowMessage`, `MarginX`/`MarginY` offset from center, `UsePayloadDuration`, queue cap) synced to clients on connect. Load **after** workshop `DayZ-Expansion-Core` and `PlayZUI`, before `PlayZExpansion`.

## Adding a new shared sub-mod

1. Confirm clients must observe the behavior (UI, assets, sync, or a split-mod client stub).
2. Grep `PlayZ_Server/` — if the feature is server-only with no client surface, put it in `PlayZ_Server/` instead.
3. Add `config.cpp` + `CfgPatches` + `CfgMods` with `files[]` under `PlayZ_Client/<Name>/`.
4. Pack to `@PlayZ_Client` and add to server and client `-mod=` launch lists.
