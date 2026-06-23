# PlayZNotification

Center-screen sequential toast queue for Sakhal. Intercepts the global `NotificationSystem.AddNotif` pipeline (Terje, Inedia type-2, Expansion, COT). No icons, no sound. Expansion killfeed dropped silently.

## Config (server only)

`$profile:PlayZ/Notification.json` on the **dedicated server** profile (e.g. server `PlayZ` folder). Created on first server start. Synced to each client on connect via RPC — clients do not read or write this file.

Key toggles: `Enabled`, `ShowTitle`, `ShowMessage`, `UsePayloadDuration`, `FixedHoldSeconds`, `MinHoldSeconds`, `MaxHoldSeconds`.

Position: toasts are centered on screen. `MarginX` / `MarginY` are pixel offsets from that center (positive = right/down, negative = left/up), scaled when `ScaleToScreen` is enabled. Example to clear the crosshair: `"MarginY": -80`.

Edit on the server; players receive updated settings on reconnect.

## Load order

Inside `@PlayZ_Client`, **after** workshop `DayZ-Expansion-Core` and `PlayZUI`:

```text
… PlayZUI · PlayZNotification · PlayZExpansion · …
```

## Behavior

- One toast at a time (FIFO, max queue 5, drop oldest on overflow).
- Queued while menu or Terje Start Screen is open; stale entries purged after `BlockedQueueStaleSeconds` (default 30s).
- Hold duration from mod RPC `show_time` when `UsePayloadDuration` is true, clamped by min/max.
- Until server config RPC arrives, toasts are held (Expansion UI suppressed); they play after sync.
- **Terje skill level-ups:** message-only sentence (`Your STRENGTH skill has ranked up to 13` — MSG1 + skill name + MSG2 + level, no inventory hint). Requires `ShowMessage: 1` (default). Other Terje toasts (skillbooks, perk gates) unchanged.
