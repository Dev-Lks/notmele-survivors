# Notmele Survivors

A from-scratch Vampire Survivors-inspired prototype built with C++ and raylib.

This is a personal game programming project focused on learning by implementation: first a small 2D survival loop, then a deliberate move toward a 2.5D orthographic presentation. The project is intentionally kept close to the code while the gameplay foundation is still being explored.

## Current state

- Raylib window and game loop
- `Game` and `Player` modules
- WASD movement
- Shift sprint modifier
- Frame-time based movement
- Normalized diagonal movement
- Debug logging through raylib's `TraceLog`
- Player rendered as a primitive while gameplay is prototyped

## Build and run

Requirements:

- C++17 compiler
- GNU Make
- raylib installed and available to the linker

On Linux:

```bash
make
./build/notmele
```

Clean the local executable with:

```bash
make clean
```

## Controls

| Input | Action |
| --- | --- |
| `WASD` | Move |
| `Left Shift` / `Right Shift` | Sprint |
| `Escape` | Close the window |

## Project layout

```text
src/
├── main.cpp              # Application entry point
├── game/
│   ├── Game.h            # Game lifecycle and ownership
│   └── Game.cpp
└── player/
    ├── Player.h          # Player state and interface
    └── Player.cpp
```

`Game` currently owns the player and coordinates the update/draw loop. Gameplay is being kept deliberately small before introducing larger systems such as enemies, weapons, progression, and an ECS layer.

## Roadmap

1. Add a world-space arena and `Camera2D`.
2. Add one enemy with simple pursuit behavior.
3. Add an automatic weapon and projectile lifetime.
4. Add damage, death, experience, and level-ups.
5. Introduce assets and a focused debug overlay.
6. Evaluate Flecs against the working non-ECS prototype.
7. Explore a 2.5D orthographic rendering pass.

The roadmap is intentionally incremental: each step should produce a playable, inspectable result before the next system is introduced.
