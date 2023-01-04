#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"

class Bee : public Unit
{
    int count;
    
public:
    // add the fly function here as well.
    void fly () override;
    bool checker();
    Bee(); 
    // may add other overloaded constructors here... 
    Bee(int x, int y);
    Bee(SDL_Rect R, SDL_Rect M);

};
