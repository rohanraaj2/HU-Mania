#include "butterfly.hpp"
// butterfly implementation will go here.

Butterfly butterfly_state_1 = {{256, 24, 174, 134}, {30, 40, 50, 50}};
Butterfly butterfly_state_2 = {{257, 182, 192, 214}, {30, 40, 50, 50}};
Butterfly butterfly_state_3 = {{248, 433, 247, 178}, {30, 40, 50, 50}};
// in project implementation this draw function should only be in superclass

// fly() is overrided from the superclass
void Butterfly::fly(){
    Unit::fly();
    if (moverRect.y >= 599) // Butterfly has reached the bottom of the screen
    {
        bottom = true;
    }
    else if (moverRect.y <= 0) // Butterfly has reached the top of the screen
    {
        bottom = false;
    }
    if (bottom == false)
    {
        moverRect.y += 5; // Butterfly moves 5 units below
    }
    else if (bottom = true)
    {
        moverRect.y -= 5; // Butterfly moves 5 units above
    }
    if (SDL_RectEquals(&srcRect, &butterfly_state_3.srcRect)) // checking the state of the butterfly by comparing srcRect of butterfly's current state and butterfly's 3rd state
    {
        srcRect = butterfly_state_1.srcRect; // butterfly's state set to 1st state.
    }
    else if (SDL_RectEquals(&srcRect, &butterfly_state_2.srcRect)) // checking the state of the butterfly by comparing srcRect of butterfly's current state and butterfly's 2nd state
    {
        srcRect = butterfly_state_3.srcRect; // butterfly's state set to 3rd state.
    }
    else if (SDL_RectEquals(&srcRect, &butterfly_state_1.srcRect)) // checking the state of the butterfly by comparing srcRect of butterfly's current state and butterfly's 1st state
    {
        srcRect = butterfly_state_2.srcRect; // butterfly's state set to 2nd state.
    }
    if (moverRect.x > 999) //butterfly exceeds the right most corner
    {
        moverRect.x = -5; //butterfly reappears at the left most corner
    }
}

bool Butterfly::checker()
{
    return false; // checking if it is a bee
}  

Butterfly::Butterfly(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {256, 24, 174, 134};

    // it will display butterfly on x = 30, y = 40 location, the size of butterfly is 50 width, 60 height
    moverRect = {30, 40, 50, 50};
    bottom = false; // indicator is set that the butterfly is not at the bottom;
}
Butterfly::Butterfly(int x, int y)
{
    srcRect = {256, 24, 174, 134};

    // it will display butterfly on x = 30, y = 40 location, the size of butterfly is 50 width, 60 height
    moverRect = {x, y, 50, 50};
    bottom = false; // indicator is set that the butterfly is not at the bottom;
}

Butterfly::Butterfly(SDL_Rect R, SDL_Rect M): Unit(R, M) {
    bottom = false; // indicator is set that the butterfly is not at the bottom;
}

