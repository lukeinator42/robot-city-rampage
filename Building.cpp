//
// Created by Lukas Grasse on 2017-03-18.
//

#include "Building.h"
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

void Building::draw() {
    glBegin(GL_QUADS);

    // Far face.  
    glNormal3f( 0.0f, 0.0f, -y2);
    glColor4f(r,g,b,y2);

    glVertex3f(x1,  0,      y1);
    glVertex3f(x1,  height, y1);
    glVertex3f(x2,  height, y1);
    glVertex3f(x2,  0,      y1);

    // Right face. 
    glNormal3f( 1.0f, 0.0f, 0.0f);

    glVertex3f( x2, 0,       y1);
    glVertex3f( x2,  height, y1);
    glVertex3f( x2,  height, y2);
    glVertex3f( x2, 0,       y2);

    // Front face;
    glNormal3f( 0.0f, 0.0f, y2);

    glVertex3f( x1, 0,       y2);
    glVertex3f( x2, 0,       y2);
    glVertex3f( x2,  height, y2);
    glVertex3f( x1,  height, y2);
    
    // Left Face;
    glNormal3f(0, 0.0f, 0.0f);

    glVertex3f( x1, 0, y1);
    glVertex3f( x1, 0,  y2);
    glVertex3f( x1,  height, y2);
    glVertex3f( x1,  height, y1);


    glEnd();
}