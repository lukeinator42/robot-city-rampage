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
   // draw the grey ground
   glColor3f(0.5f, 0.5f, 0.5f);
   glBegin(GL_QUADS);
   glVertex3f(MIN, 0.f, MIN);
   glVertex3f(MIN, 0.f, MAX);
   glVertex3f(MAX, 0.f, MAX);
   glVertex3f(MAX, 0.f, MIN);
   glEnd();

   

   // draw the grass on the ground
   for (GLfloat i = MIN+1; i < MAX; i+=6.f)
      for (GLfloat j = MIN+1; j < MAX; j+=6.f)
      {
	 glColor3f (0.2f, 0.39f, 0.f);
	 glBegin (GL_QUADS);
	 glVertex3f (i    , 0.f, j    );
	 glVertex3f (i    , 0.f, j+3.f);
	 glVertex3f (i+3.f, 0.f, j+3.f);
	 glVertex3f (i+3.f, 0.f, j    );
	 glEnd();
      }

   // draw Lines on the ground
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

