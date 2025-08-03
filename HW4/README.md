# Homework 4: HUMania Game — OOP & Entities

This assignment builds on HW3 by introducing new game entities (Bee, Butterfly, Pigeon) and more advanced object-oriented programming concepts.

## Folder Structure
- `HUMania/`
  - `main.cpp`, `game.cpp`, `game.hpp`, `HUMania.cpp`, `HUMania.hpp`: Core game logic
  - `bee.cpp`, `bee.hpp`, `butterfly.cpp`, `butterfly.hpp`, `pigeon.cpp`, `pigeon.hpp`: Entity classes
  - `drawing.hpp`: Shared drawing utilities
  - `assets.png`, `hu.png`: Game graphics
  - `pigeon.mp3`: Audio asset
  - `How to Compile.txt`: Build instructions
  - `vectordemo.cc`: Vector demo

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
- Multiple entity classes (Bee, Butterfly, Pigeon)
- Inheritance and polymorphism
- Improved game loop and rendering
