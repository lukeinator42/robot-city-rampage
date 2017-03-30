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

BuildingFactory::BuildingFactory(float min, float max, float grid_size) : min(min), max(max), grid_size(grid_size) {
    srand (time(NULL));
}

void BuildingFactory::draw() {
    for(int i=0; i<buildings.size(); i++)
        buildings[i]->draw();

}

void BuildingFactory::generate() {

    for (GLfloat i = min; i < max; i+=1.f) {
        for (GLfloat j = min; j < max; j += 1.f) {
            if(     ((int) i+6)%6 == 5 ||
                    ((int) i+6)%6 == 0 ||
                    ((int) i+6)%6 == 1 ||
                    ((int) j+6)%6 == 5 ||
                    ((int) j+6)%6 == 0 ||
                    ((int) j+6)%6 == 1
                )
                continue;

            int draw = rand();

            if(draw % 3 == 1 || draw %3 == 2)
                continue;

            float rGen = (rand()%10000)/10000.0f;
            float gGen = (rand()%10000)/10000.0f;
            float bGen = (rand()%10000)/10000.0f;

            buildings.push_back(new Building(i, j, i-1, j-1, rand()%10+1, rGen, gGen, bGen));
        }
    }
}

const std::vector<Building*> &BuildingFactory::getBuildings() const {
    return buildings;
}

BuildingFactory::~BuildingFactory() {
    for(int i=0; i<buildings.size(); i++)
        delete buildings[i];
}
