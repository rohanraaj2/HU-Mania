#include <iostream>
#include "HUMania.hpp"
#include <ctime>

void HUMania::drawObjects()
{
    // call draw functions of all the objects here
    p1.draw();
    p1.fly(); // this function is called to move the pigeon

    for(unsigned int i = 0; i < pigeons.size(); i++) //iterating over pigeons' vector
    {
        (*pigeons[i]).draw(); // this function is called to draw the pigeon
        (*pigeons[i]).fly(); // this function is called to move the pigeon
    }
    for(unsigned int i = 0; i < bees.size(); i++) //iterating over bees' vector
    {
        (*bees[i]).draw(); // this function is called to draw the bee
        (*bees[i]).fly(); // this function is called to move the bee
        if ((*bees[i]).exit()) // if bee has exceeded the right most corner
        {
            delete bees[i]; // this particular object is removed
            bees[i] = nullptr;
            bees.erase(bees.begin()+i);
        }
    }
    for(unsigned int i = 0; i < butterflies.size(); i++) //iterating over butterflies' vector
    {
        (*butterflies[i]).draw(); // this function is called to draw the butterfly
        (*butterflies[i]).fly(); // this function is called to move the butterfly
    }
}

void HUMania::createObject(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    int random = 1 + rand()%3; // random number is generated from 0, 1 and 2, to which 1 is added. Hence, we get either 1, 2 or 3
    if (random == 1) // 1 corresponds to pigeons
    {
        pigeons.push_back(new Pigeon ({7,88,160,103}, {x, y, 50, 50})); // object is pushed in pigeons' vector
    }
    else if (random == 2) // 2 corresponds to butterflies
    {
        butterflies.push_back(new Butterfly ({256, 24, 174, 134}, {x, y, 50, 50})); // object is pushed in butterflies' vector
    }
    else if (random == 3) // 3 corresponds to bees
    {
        bees.push_back(new Bee ({63, 619, 151, 166}, {x, y, 50, 50})); // object is pushed in bees' vector
    }
}

HUMania::~HUMania()
{
    for(unsigned int i = 0; i < pigeons.size(); i++) //iterating over pigeons' vector
    {
        delete pigeons[i]; // the corresponding pigeon object is removed from the vector
        pigeons[i] = nullptr;
    }
    for(unsigned int i = 0; i < bees.size(); i++) //iterating over bees' vector
    {
        delete bees[i]; // the corresponding bee object is removed from the vector
        bees[i] = nullptr;
    }
    for(unsigned int i = 0; i < butterflies.size(); i++) //iterating over butterflies' vector
    {
        delete butterflies[i]; // the corresponding butterfly object is removed from the vector
        butterflies[i] = nullptr;
    }
}
