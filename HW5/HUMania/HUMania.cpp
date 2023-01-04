#include <iostream>
#include "HUMania.hpp"

void HUMania::drawObjects()
{
    // call draw functions of all the objects here
    p1.draw(); 
    p1.fly(); // this function is called to move the pigeon

    for(int i = 0; i < animal.size(); i++) //iterating over animal vector
    {
        (*animal[i]).draw(); // this function is called to draw the animal
        (*animal[i]).fly(); // this function is called to move the animal
        if ((*animal[i]).checker()) // checking if it is a bee and has exceeded right most corner
        {
            delete animal[i]; // destroying the object
            animal[i] = nullptr;
            animal.erase(animal.begin()+i);
        }
    }
}

// creates new objects 
void HUMania::createObject(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    int random = 1 + rand()%3; // random number is generated from 0, 1 and 2, to which 1 is added. Hence, we get either 1, 2 or 3
    if (random == 1) // 1 corresponds to pigeons
    {
        animal.push_back(new Pigeon ({7,88,160,103}, {x, y, 50, 50})); // object is pushed in pigeons' vector
    }
    else if (random == 2) // 2 corresponds to butterflies
    {
        animal.push_back(new Butterfly ({256, 24, 174, 134}, {x, y, 50, 50})); // object is pushed in butterflies' vector
    }
    else if (random == 3) // 3 corresponds to bees
    {
        animal.push_back(new Bee ({63, 619, 151, 166}, {x, y, 50, 50})); // object is pushed in bees' vector
    }
}

HUMania::~HUMania()
{
    for(unsigned int i = 0; i < animal.size(); i++) //iterating over animal vector
    {
        delete animal[i]; // the corresponding object is removed from the vector
        animal[i] = nullptr;
        animal.erase(animal.begin()+i); // removes object from vector list 
    }
    delete [] &animal;
}

