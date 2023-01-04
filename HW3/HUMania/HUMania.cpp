#include<iostream>
#include "HUMania.hpp"
#include <vector>

#include <ctime>

using namespace std;

Unit pigeon = {{7,88,155,103}, {30, 40, 50, 50}}; // A unit is defined for each animal's each state
Unit pigeon1 = {{7,88,155,103}, {30, 40, 50, 50}}; 
Unit pigeon2 = {{0, 237, 153, 84}, {30, 40, 50, 50}};
Unit pigeon3 = {{2, 361, 159, 124}, {30, 40, 50, 50}};
Unit bee = {{527, 138, 194, 115.5}, {30, 40, 50, 50}};
Unit bee2 = {{527, 254, 194, 115.5}, {30, 40, 50, 50}};
Unit bee3 = {{540, 370, 193, 115}, {30, 40, 50, 50}};
Unit butterfly = {{257, 24, 173, 134}, {30, 40, 50, 50}};
Unit butterfly2 = {{257, 182, 192, 214}, {30, 40, 50, 50}};
Unit butterfly3 = {{248, 432, 248, 179}, {30, 40, 50, 50}};

// First rectangle is srcRect, second is moverRect
// these values are taken from the corresponding image in assets file
// use spritecow.com to find exact values of other asset images


vector<Unit> pigeons; // a vector is created for each animal
vector<Unit> bees;
vector<Unit> butterflies;
//create 2 more vectors for bees and butterflies

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets)
{
    // this function is drawing one pigeon only right now
    SDL_RenderCopy(gRenderer, assets, &pigeon.srcRect, &pigeon.moverRect); // a pigeon is drawn
    pigeon.moverRect.x+=2; // moves the pigeon two pixel towards right

    // TODO: Write code to iterate over all the vectors and draw objects here:
    
    if (SDL_RectEquals (&pigeon.srcRect, &pigeon3.srcRect)) // checking the state of the first pigeon by comparing srcRect of pigeon's current state and pigeon's 3rd state
    {
        pigeon.srcRect = pigeon2.srcRect; // pigeon's state set to 2nd state.
        pigeon.srcRect = {7,88,155,103}; // pigeon's state set to 1st state.
    }
    else if (SDL_RectEquals (&pigeon.srcRect, &pigeon2.srcRect)) // checking the state of the first pigeon by comparing srcRect of pigeon's current state and pigeon's 2nd state
    {
        pigeon.srcRect = pigeon3.srcRect; // pigeon's state set to 3rd state.
    }
    else if (SDL_RectEquals (&pigeon.srcRect, &pigeon1.srcRect)) // checking the state of the first pigeon by comparing srcRect of pigeon's current state and pigeon's 1st state
    {
        pigeon.srcRect = pigeon2.srcRect; // pigeon's state set to 2nd state.
    }

    if (pigeon.moverRect.x > 999) //pigeon exceeds the right most corner
    {
        pigeon.moverRect.x = 0; //pigeon reappears at the left most corner
    }

    for(unsigned int i = 0; i < pigeons.size(); i++) //iterating over pigeons' vector
    {
        SDL_RenderCopy(gRenderer, assets, &pigeons[i].srcRect, &pigeons[i].moverRect); // a pigeon is drawn

        if (SDL_RectEquals(&pigeons[i].srcRect, &pigeon3.srcRect)) // checking the state of the pigeon by comparing srcRect of pigeon's current state and pigeon's 3rd state
        {
            pigeons[i].srcRect = pigeon2.srcRect; // pigeon's state set to 2nd state.
            pigeons[i].srcRect = pigeon1.srcRect; // pigeon's state set to 1st state.
        }
        else if (SDL_RectEquals(&pigeons[i].srcRect, &pigeon2.srcRect)) // checking the state of the first pigeon by comparing srcRect of pigeon's current state and pigeon's 2nd state
        {
            pigeons[i].srcRect = pigeon3.srcRect; // pigeon's state set to 3rd state.
        }
        else if (SDL_RectEquals(&pigeons[i].srcRect, &pigeon.srcRect)) // checking the state of the first pigeon by comparing srcRect of pigeon's current state and pigeon's 1st state
        {
            pigeons[i].srcRect = pigeon2.srcRect; // pigeon's state set to 2nd state.
        }
        pigeons[i].moverRect.x+=2; // moves the pigeon two pixel towards right
        if (pigeons[i].moverRect.x > 999) //pigeon exceeds the right most corner
        {
            pigeons[i].moverRect.x = 0; //pigeon reappears at the left most corner
        }
    }
    for(unsigned int i = 0; i < bees.size(); i++) //iterating over bees' vector
    {
        SDL_RenderCopy(gRenderer, assets, &bees[i].srcRect, &bees[i].moverRect); // a bee is drawn
        if (SDL_RectEquals(&bees[i].srcRect, &bee3.srcRect)) // checking the state of the bee by comparing srcRect of bee's current state and bee's 3rd state
        {
            bees[i].srcRect = bee2.srcRect; // bee's state set to 2nd state.
            bees[i].srcRect = bee.srcRect; // bee's state set to 1st state.
        }
        else if (SDL_RectEquals(&bees[i].srcRect, &bee2.srcRect)) // checking the state of the bee by comparing srcRect of bee's current state and bee's 2nd state
        {
            bees[i].srcRect = bee3.srcRect; // bee's state set to 3rd state.
        }
        else if (SDL_RectEquals(&bees[i].srcRect, &bee.srcRect)) // checking the state of the bee by comparing srcRect of bee's current state and bee's 2nd state
        {
            bees[i].srcRect = bee2.srcRect; // bee's state set to 2nd state.
        }
        bees[i].moverRect.x+=2; // moves the bee two pixel towards right
        if (bees[i].moverRect.x > 999) //bee exceeds the right most corner
        {
            bees[i].moverRect.x = 0; //bee reappears at the left most corner
        }
    }
    for(unsigned int i = 0; i < butterflies.size(); i++) //iterating over butterflies' vector
    {
        SDL_RenderCopy(gRenderer, assets, &butterflies[i].srcRect, &butterflies[i].moverRect); // a butterfly is drawn
        if (SDL_RectEquals(&butterflies[i].srcRect, &butterfly3.srcRect)) // checking the state of the butterfly by comparing srcRect of butterfly's current state and butterfly's 3rd state
        {
            butterflies[i].srcRect = butterfly2.srcRect; // butterfly's state set to 2nd state.
            butterflies[i].srcRect = butterfly.srcRect; // butterfly's state set to 1st state.
        }
        else if (SDL_RectEquals(&butterflies[i].srcRect, &butterfly2.srcRect)) // checking the state of the butterfly by comparing srcRect of butterfly's current state and butterfly's 2nd state
        {
            butterflies[i].srcRect = butterfly3.srcRect; // butterfly's state set to 3rd state.
        }
        else if (SDL_RectEquals(&butterflies[i].srcRect, &butterfly.srcRect)) // checking the state of the butterfly by comparing srcRect of butterfly's current state and butterfly's 2nd state
        {
            butterflies[i].srcRect = butterfly2.srcRect; // butterfly's state set to 2nd state.
        }
        butterflies[i].moverRect.x+=2; // moves the butterfly two pixel towards right
        if (butterflies[i].moverRect.x > 999) //butterfly exceeds the right most corner
        {
            butterflies[i].moverRect.x = 0; //butterfly reappears at the left most corner
        }
    }
}
    // changing the srcRect to other positions of pigeon will make the fly animation
    // SDL_RenderPresent is already called in game.cpp file, you don't need to call here

void createObject(int x, int y)
{

    // TODO: create an object randomly, and push it into corresponding vector
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
    srand(time(NULL)); // random values are generated based on time
    int random = 1 + rand()%3; // random number is generated from 0, 1 and 2, to which 1 is added. Hence, we get, either 1, 2 or 3
    Unit u; // An object is created
    if (random == 1) // 1 corresponds to pigeons
    {
        u = {pigeon.srcRect, {x, y, 50, 50}}; // pigeon's position is set to x, y coordinates which correspond to the point where we clicked
        pigeons.push_back(u); // object is pushed in pigeons' vector
    }
    else if (random == 2) // 2 corresponds to bees
    {
        u = {bee.srcRect, {x, y, 50, 50}}; // bee's position is set to x, y coordinates which correspond to the point where we clicked
        bees.push_back(u); // object is pushed in bees' vector
    }
    else if (random == 3) // 3 corresponds to butterflies
    {
        u = {butterfly.srcRect, {x, y, 50, 50}}; // butterfly's position is set to x, y coordinates which correspond to the point where we clicked
        butterflies.push_back(u); // object is pushed in butterflies' vector
    }
}