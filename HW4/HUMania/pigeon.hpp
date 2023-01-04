#include<SDL.h>
#include "drawing.hpp"
class Pigeon
{
    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void fly();
    Pigeon();


    // you may add other overloaded constructors here... 
    Pigeon(SDL_Rect R, SDL_Rect M);
};
