#include "Unit.hpp"

void Unit::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect); // drawing the object
}
void Unit::fly() 
{
    moverRect.x += 5; // moving 5 units towards right
}
bool Unit::checker() {return false;} // initializing the signal for bee exceeding right most corner to false

Unit::Unit() {}

Unit::Unit (int x, int y) {}

Unit::Unit (SDL_Rect R, SDL_Rect M): srcRect(R), moverRect(M) {}