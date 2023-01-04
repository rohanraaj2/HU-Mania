#include "butterfly.hpp"
#include "drawing.hpp"


Butterfly butterfly_state_1 = {{256, 24, 174, 134}, {30, 40, 50, 50}};
Butterfly butterfly_state_2 = {{257, 182, 192, 214}, {30, 40, 50, 50}};
Butterfly butterfly_state_3 = {{248, 433, 247, 178}, {30, 40, 50, 50}};

void Butterfly::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Butterfly::fly()
{
    // you have to do flying animations here
    moverRect.x += 5; // Butterfly moves 5 units to the right
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

Butterfly::Butterfly()
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {256, 24, 174, 134};

    // it will display butterfly on x = 30, y = 40 location, the size of butterfly is 50 width, 60 height
    moverRect = {30, 40, 50, 50};
    bottom = false; // indicator is set that the butterfly is not at the bottom;
}

Butterfly::Butterfly(SDL_Rect R, SDL_Rect M): srcRect(R), moverRect(M)
{
    bottom = false; // indicator is set that the butterfly is not at the bottom;
}


