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

Landscape::Landscape(const float min, const float max, const int grid_size)
   : MIN(min), MAX(max), GRID_SIZE(grid_size)
{
   GridSize = new int(grid_size);
   // init the stored city
   memset(CITY, -1, sizeof CITY);
}

void Landscape::drawCityGround()
{

   glBegin(GL_QUADS);

   // GREY GROUND
   glNormal3f( 0.0f, 1.0f, 0.0f );
   glColor4f ( 128.f, 128.f, 128.f, 1.f);
   glVertex3f(   MIN,   MIN,  0.0f );
   glVertex3f(   MIN,   MAX,  0.0f );
   glVertex3f(   MAX,   MAX,  0.0f );
   glVertex3f(   MAX,   MIN,  0.0f );

   glEnd();
   

   for(int i=0; i< this->GRID_SIZE; i++) {
        for (int j = 0; j < this->GRID_SIZE; j++) {

        }
    }
}

void Landscape::draw() {

}

