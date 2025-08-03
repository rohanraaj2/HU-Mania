# Homework 3: HUMania Game (SDL2)

This assignment introduces the basics of SDL2-based game development in C++. You will set up a simple game window, load assets, and render objects using object-oriented programming.

## Folder Structure
- `HUMania/`
  - `main.cpp`, `game.cpp`, `game.hpp`, `HUMania.cpp`, `HUMania.hpp`: Main game logic and entry point
  - `assets.png`, `hu.png`: Game graphics
  - `pigeon.mp3`: Audio asset
  - `How to Compile.txt`: Build instructions
  - `vectorDemo.cpp`: Demo for vector usage

## How to Build & Run
See `How to Compile.txt` for full details. In summary:
1. Open the `HUMania` folder in VS Code.
2. Compile all `.cpp` files with:
   ```sh
   g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
   ```
3. Run the game with:
   ```sh
   ./a.exe
   ```

## Key Features
- SDL2 window and renderer setup
- Asset loading and rendering
- Basic game loop
