//
// Created by Lukas Grasse on 2017-03-18.
//

#include "Landscape.h"
#include <algorithm>
#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif

Landscape::Landscape(const float min, const float max, const int grid_size)  : MIN(min), MAX(max), GRID_SIZE(grid_size) {
    GridSize = new int(grid_size);

}

void Landscape::initLandScape() {
    // init the stored city
    memset(CITY, -1, sizeof CITY);

}

void Landscape::drawCityGround()
{
    glBegin(GL_QUADS);

    for(int i=0; i< this->GRID_SIZE; i++) {
        for (int j = 0; j < this->GRID_SIZE; j++) {

        }
    }
}

void Landscape::draw() {

}

