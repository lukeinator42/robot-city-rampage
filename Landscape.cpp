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

   glBegin(GL_QUADS);

   // GREY GROUND
   //glNormal3f(  0.0f,  1.0f,  0.0f );
   glColor4f (  0.5f,  0.5f , 0.5f, 1.f);
   glVertex3f(   MIN,   0.0f,  MIN );
   glVertex3f(   MIN,   0.0f,  MAX );
   glVertex3f(   MAX,   0.0f,  MAX );
   glVertex3f(   MAX,   0.0f,  MIN );

   glEnd();
   

}

void Landscape::draw() {

}

