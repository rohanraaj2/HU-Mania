#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"


class Butterfly : public Unit
{
    bool bottom;

public:
    // add the fly function here as well.
    void fly () override;
    bool checker();

    Butterfly(); 
    // may add other overloaded constructors here... 
    Butterfly(int x, int y);
    Butterfly(SDL_Rect R, SDL_Rect M);

};
