#include "pigeon.hpp"
// pigeon implementation will go here.

Pigeon pigeon_state_1 = {{7,88,160,103}, {30, 40, 50, 50}};
Pigeon pigeon_state_2 = {{0, 237, 153, 84}, {30, 40, 50, 50}};
Pigeon pigeon_state_3 = {{2, 361, 159, 124}, {30, 40, 50, 50}};
// in project implementation this draw function should only be in superclass

// fly() is overrided from the superclass
void Pigeon::fly()  
{
    Unit::fly();
    // you have to do flying animations here
    if (SDL_RectEquals (&srcRect, &pigeon_state_3.srcRect)) // checking the state of the pigeon by comparing srcRect of pigeon's current state and pigeon's 3rd state
    {
        srcRect = pigeon_state_1.srcRect; // pigeon's state set to 2nd state.
    }
    else if (SDL_RectEquals (&srcRect, &pigeon_state_2.srcRect)) // checking the state of the pigeon by comparing srcRect of pigeon's current state and pigeon's 2nd state
    {
        srcRect = pigeon_state_3.srcRect; // pigeon's state set to 3rd state.
    }
    else if (SDL_RectEquals (&srcRect, &pigeon_state_1.srcRect)) // checking the state of the pigeon by comparing srcRect of pigeon's current state and pigeon's 1st state
    {
        srcRect = pigeon_state_2.srcRect; // pigeon's state set to 2nd state.
    }

    if (moverRect.x > 999) //pigeon exceeds the right most corner
    {
        moverRect.x = -5; //pigeon reappears at the left most corner
    }
}
bool Pigeon::checker()
{
    return false; // checking if it is a bee
}  

Pigeon::Pigeon()
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {7,88,160,103};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {30, 40, 50, 50};
}
Pigeon::Pigeon(int x, int y) 
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {7,88,160,103};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {x, y, 50, 50};
}

Pigeon::Pigeon(SDL_Rect R, SDL_Rect M): Unit(R, M) {}



