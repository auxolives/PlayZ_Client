# PlayZWelcomeMessage

Timed fading welcome overlay shown once per session when a player joins Sakhal.

Based on [Ironhorde Welcome Message](https://steamcommunity.com/sharedfiles/filedetails/?id=3723248277) by DeafFeliciaPlaysDayZ (repack/modification allowed by author).

## Config

`$profile:PlayZ/WelcomeMessage.json`

Server creates the file on first start. Text is resolved client-side from `stringtable.csv` via `STR_PlayZ_Welcome_*` keys in the JSON.

## Behavior

- Server syncs config to the client on connect (5s delay).
- Client waits until Terje Start Screen closes and no menu is open.
- Vanilla SDF Metron fonts only; no custom PAAs.

## Load order

Inside `@PlayZ_Client`, after `PlayZCore`, near `PlayZUI`.
