//
// Created by Lukas Grasse on 2017-03-18.
//

#include "BuildingFactory.h"
#include <algorithm>
#include <string.h>

#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif

#include <cstdlib>
#include <ctime>
#include <iostream>

BuildingFactory::BuildingFactory(int min, int max, int grid_size) : min(min), max(max), grid_size(grid_size) {
    srand (time(NULL));
}

void BuildingFactory::draw() {
    for(int i=0; i<buildings.size(); i++) {
            buildings[i]->draw();
    }

}

void BuildingFactory::generate() {
    std::cout << "Generating" << std::endl;

    for (int i =  min; i <= max; i++) {
        for (int j =  min; j <= max; j++) {
            if((i + 20*6) % 6 == 1 || (j + 20*6) % 6 == 1 || (i + 20*6) % 6 == 0 || (j + 20*6) % 6 == 0)
                continue;

            int draw = rand();

            if(draw % 3 == 1 || draw %3 == 2)
                continue;

            float rGen = (rand()%10000)/10000.0f;
            float gGen = (rand()%10000)/10000.0f;
            float bGen = (rand()%10000)/10000.0f;

            int type = rand() %3;

            buildings.push_back(new Building(i, j, rand()%10+1, rGen, gGen, bGen, type));
        }
    }
}

std::vector<Building*> &BuildingFactory::getBuildings()  {
    return buildings;
}

BuildingFactory::~BuildingFactory() {
    for(int i=0; i<buildings.size(); i++)
        delete buildings[i];
}
