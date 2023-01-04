#include<SDL.h>
#include "drawing.hpp"
class Bee
{
    SDL_Rect srcRect, moverRect;
    int count;

public:
    void draw();
    void fly();
    bool exit();
    Bee(); 

    // you may add other overloaded constructors here... 
    Bee(SDL_Rect R, SDL_Rect M);
};
