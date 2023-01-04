#include "drawing.hpp"
#include<SDL.h>
class Butterfly
{
    SDL_Rect srcRect, moverRect;
    bool bottom;

public:
    void draw();
    void fly();
    Butterfly(); 

    // you may add other overloaded constructors here... 
    Butterfly(SDL_Rect R, SDL_Rect M);
};
