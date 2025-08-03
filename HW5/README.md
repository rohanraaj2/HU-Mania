# Homework 5: HUMania Game — Inheritance & Abstraction

This assignment further abstracts the game logic by introducing a `Unit` base class and additional features. It demonstrates advanced C++ OOP concepts in the context of SDL2 game development.

## Folder Structure
- `HUMania/`
  - `main.cpp`, `game.cpp`, `game.hpp`, `HUMania.cpp`, `HUMania.hpp`: Core game logic
  - `Unit.cpp`, `Unit.hpp`: Abstract base class for game entities
  - `bee.cpp`, `bee.hpp`, `butterfly.cpp`, `butterfly.hpp`, `pigeon.cpp`, `pigeon.hpp`: Derived entity classes
  - `drawing.hpp`: Shared drawing utilities
  - `listdemo.cc`: STL list demo
  - `assets.png`, `hu.png`: Game graphics
  - `pigeon.mp3`: Audio asset
  - `How to Compile.txt`: Build instructions

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
- Abstract base class (`Unit`) for all entities
- Inheritance and polymorphism
- STL list usage
- Enhanced game logic
