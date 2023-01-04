#include<SDL.h>
#include "pigeon.hpp"
#include "bee.hpp"
#include "butterfly.hpp"
#include "Unit.hpp"
#include<vector>
#include<list>
using namespace std;

class HUMania{

    //Right now we're creating one pigeon, just for practice. for details follow the guidlines 
    Pigeon p1;

    //Create your list here
    vector<Unit*> animal;

    public:

    
    void drawObjects(); 
    void createObject(int, int);
    
    // create destructor which deletes all dynamic objects
    ~HUMania();
};

