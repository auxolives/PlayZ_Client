# PlayZ_Client UI compatibility index

Documentation for existing PlayZ_Client UI patches that PlayZUI must not break. PlayZUI rewrites vanilla shell menus; siblings patch behavior around those shells.

## Mod load order

```text
PlayZCore · PlayZGunPlay · PlayZTerje* · PlayZUI · PlayZExpansion
```

**Source Found:** `PlayZ_Client/PlayZUI/README.md:9-19`

## Documents

| File | Topic |
|------|-------|
| [01-playzcore-ui.md](01-playzcore-ui.md) | Earplugs overlay, ACL logout, inputs, stringtable |
| [02-sibling-modules.md](02-sibling-modules.md) | Full grep inventory — Expansion, GunPlay, Terje* |
| [03-load-order-conflicts.md](03-load-order-conflicts.md) | Conflict matrix + testing checklist |
| [04-death-screen.md](04-death-screen.md) | Custom death screen — flow, layout, script map, do-not-regress |

## Milestone 2 — do not break PlayZCore checklist

Before merging any PlayZUI screen rewrite:

- [ ] **Logout layout** preserves `txtLogoutTime`, `txtDescription`, `bLogoutNow`, `bCancel`
- [ ] **LogoutMenu** — no `Init()` override unless widget re-bind matches vanilla + PlayZCore members
- [ ] **MissionGameplay.OnUpdate** — not blocked or overridden by PlayZUI
- [ ] **Earplugs** — `UAEarPlugsToggle` still gated on `GetMenu() == NULL`
- [ ] **OptionsMenu** — calls `super.Init()` so Expansion tab + GunPlay hide still run
- [ ] **IngameHud** — no PlayZUI patches (nametags stay in PlayZExpansion)

## Ownership reminder

| Surface | Owner |
|---------|-------|
| Main menu, loading, pause, death screen, options, logout layouts | **PlayZUI** |
| Earplugs flash, ACL logout logic | **PlayZCore** |
| Nametags, chat names, killfeed, EXPANSION options tab | **PlayZExpansion** |
| Terje HUD badges, skills panel | **Terje mods** / **PlayZTerje*** |
| Terje Start Screen page skins | **PlayZUI** (`GetNativeLayout()` only) |

**Source Found:** `PlayZ_Client/PlayZUI/README.md:21-30`

## Related docs

- [../vanilla/](../vanilla/)
- [../terje/](../terje/)
- [../expansion/](../expansion/)
- [../BRIDGES.md](../BRIDGES.md)
