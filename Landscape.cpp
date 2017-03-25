//
// Created by Lukas Grasse on 2017-03-18.
//

#include "Landscape.h"
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

Landscape::Landscape(const float min, const float max, const int grid_size)
   : MIN(min), MAX(max), GRID_SIZE(grid_size)
{
   GridSize = new int(grid_size);
   // init the stored city
   memset(CITY, -1, sizeof CITY);
}

void Landscape::drawCityGround()
{

   glColor3f(1.0, 1.0, 1.0);
   glBegin(GL_LINES);
   for (GLfloat i = MIN; i <= MAX; i += 1.0) {
      glVertex3f(i, 0, MAX); glVertex3f(i, 0, MIN);
      glVertex3f(MAX, 0, i); glVertex3f(MIN, 0, i);
   }
   glEnd();
   

}

void Landscape::draw() {

}

