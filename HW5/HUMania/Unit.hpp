#include<SDL.h>
#include "drawing.hpp"
#pragma once

class Unit
{
    protected:
    SDL_Rect srcRect, moverRect;
    // int frame = 0;

    public:

    void draw();
    virtual void fly();
    bool checker();
    Unit();
    Unit (int x, int y);
    Unit (SDL_Rect R, SDL_Rect M);
};