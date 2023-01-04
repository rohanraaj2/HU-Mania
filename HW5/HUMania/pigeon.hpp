#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"

class Pigeon : public Unit
{

public:

    // add the fly function here as well.
    void fly() override;
    bool checker();

    Pigeon();

    // may add other overloaded constructors here... 
    Pigeon(int x, int y);
    Pigeon(SDL_Rect R, SDL_Rect M);

};
