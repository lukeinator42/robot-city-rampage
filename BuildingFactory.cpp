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
    // draw the grass on the ground
    for (GLfloat i = min; i < max; i+=6.f) {
        for (GLfloat j = min; j < max; j += 6.f) {
            int randX = rand() % 4;
            int randY = rand() % 4;
            buildings.push_back(new Building(i+randX, j+randY, i+randX+1, j+randY+1, rand()%10+1, 0.8235, 0.7059, 0.5490));
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
