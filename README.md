# PlayZ_Client

Shared PlayZ sub-mods for the **Sakhal** server. Everything here is packed into PBOs loaded by **both** clients and the dedicated server through `-mod=`.

No DayZ Expansion modules on Sakhal — client features are vanilla + PlayZ only.

## Rules

- Entity/config classes, UI, inputs, models, sounds, textures, NetSync variables, and client-observable RPC contracts belong here.
- Every sub-mod must have its own `config.cpp` with its own `CfgPatches.<Name>` entry so it packs as an independent PBO.
- Script `files[]` paths use the workspace prefix `PlayZ_Client/<AddonName>/scripts/...` (see existing `PlayZ_Core/config.cpp`).
- `requiredAddons[]` may list engine addons (`DZ_Data`, `DZ_Scripts`) or other `PlayZ_Client/` sub-mods.
- **Must not** require or reference any `PlayZ_Server/` addon or class.
- **Must not** depend on DayZ Expansion.

## Split-mod pattern (when a feature needs both sides)

Some server features need a client-only API (e.g. `GetCurrentCameraPosition()`). Keep the client footprint minimal:

- `PlayZ_Client/<Feature>Client/` (client + server) — shared RPC constants and the client-side handler that samples state and echoes it back. Nothing else.
- `PlayZ_Server/<Feature>/` (server only) — all logic, I/O, config, scheduling, detection. Lists `"<Feature>Client"` in `requiredAddons[]`.

Legacy reference (Namalsk era): `Archives/PlayZ_ZZ_Legacy/PlayZAntiCheatClient/` + `PlayZ_Server/PlayZAntiCheat/`.

## Deployment

Dedicated server and clients share the same `-mod=` chain:

```text
DayZServer_x64.exe -mod="@PlayZ_Core;..." -servermod="@PlayZLogs;@..." -config=serverDZ.cfg
```

Clients never receive `-servermod=`.

## Packing

- Workspace sources: `PlayZ_Client/<AddonName>/`
- Mikero mirror (pack script): `P:\PlayZ_Client\` — map P: to this tree or edit `SOURCE_ROOT` in `[Build-PlayZ_Client.bat](../Build-PlayZ_Client.bat)`.
- Cursor/VS Code: **Ctrl+Shift+B** → **PlayZ: Build Client PBOs (all)** — see `[.cursor/docs/BUILD_PLAYZ_CLIENT.md](../.cursor/docs/BUILD_PLAYZ_CLIENT.md)`.

Set `MOD_OUT` in `Build-PlayZ_Client.bat` to your Sakhal CFTools `@PlayZ_Client` deployment folder when ready.

## Current sub-mods

- `PlayZ_Core` — anti-combat logout, mouth-cover eat/drink block (`#STR_PlayZ_MouthBlocked`), attached-backpack cargo hide (waist bags exempt), shortcuts (`V` lie down, `B` backpack, `M` face cover), crafting/environment tweaks. Config: `$profile:PlayZ/Core.json`.

## Adding a new shared sub-mod

1. Confirm clients must observe the behavior (UI, assets, sync, or a split-mod client stub).
2. Grep `PlayZ_Server/` — if the feature is server-only with no client surface, put it in `PlayZ_Server/` instead.
3. Add `config.cpp` + `CfgPatches` + `CfgMods` with `files[]` under `PlayZ_Client/<Name>/`.
4. Pack to `@PlayZ_Client` and add to server and client `-mod=` launch lists.

