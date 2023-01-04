#include "bee.hpp"
// bee implementation will go here.

// in project implementation this draw function should only be in superclass

Bee bee_state_1 = {{63, 619, 151, 166}, {30, 40, 50, 50}};
Bee bee_state_2 = {{234, 630, 163, 162}, {30, 40, 50, 50}};
Bee bee_state_3 = {{409, 650, 171, 147}, {30, 40, 50, 50}};
// fly() is overrided from the superclass
void Bee::fly()
{
    if (count == 0)
    {
        int random = 1 + rand()%100; // random number is generated from 0 to 99, to which 1 is added. Hence, we get numbers from 1 to 100
        if (random > 5) // probability of not hovering
        {
            moverRect.x += 5; // Bee moves 5 units to the right
        }
        else // it starts hovering
        {
            count = 10; // initializing frames hovering for one particular bee to 10
        }
    }
    else
    {
        count -= 1; // reducing the frames left for hovering
    }
    if (SDL_RectEquals(&srcRect, &bee_state_3.srcRect)) // checking the state of the bee by comparing srcRect of bee's current state and bee's 3rd state
    {
        srcRect = bee_state_1.srcRect; // bee's state set to 1st state.
    }
    else if (SDL_RectEquals(&srcRect, &bee_state_2.srcRect)) // checking the state of the bee by comparing srcRect of bee's current state and bee's 2nd state
    {
        srcRect = bee_state_3.srcRect; // bee's state set to 3rd state.
    }
    else if (SDL_RectEquals(&srcRect, &bee_state_1.srcRect)) // checking the state of the bee by comparing srcRect of bee's current state and bee's 1st state
    {
        srcRect = bee_state_2.srcRect; // bee's state set to 2nd state.
    }
}

bool Bee::checker()
{
    if (moverRect.x > 999) //bee exceeds the right most corner
    {
        return true; // signal on for destroying it
    }
    return false; // signal off for destorying it
}  

Bee::Bee(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {63, 619, 151, 166};

    // it will display bee on x = 30, y = 40 location, the size of bee is 50 width, 60 height
    moverRect = {30, 40, 50, 50};
    count = 0; // frame for the object is initialized

}
Bee::Bee(int x, int y) 
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {63, 619, 151, 166};

    // it will display bee on x = 30, y = 40 location, the size of bee is 50 width, 60 height
    moverRect = {x, y, 50, 50};
    count = 0; // frame for the object is initialized
}

Bee::Bee(SDL_Rect R, SDL_Rect M): Unit(R, M) {
    count = 0; // frame for the object is initialized
}