//
// Created by Lukas Grasse on 2017-03-18.
//

#include "Building.h"
#include <algorithm>
#include <string.h>



void Building::draw() {
    if(!display)
        return;

//    glBegin(GL_QUADS);
//
//    // Far face.
//    glNormal3f( 0.0f, 0.0f, -y2);
//    glColor4f(r,g,b,y2);
//
//    glVertex3f(x1,  0,      y1);
//    glVertex3f(x1,  height, y1);
//    glVertex3f(x2,  height, y1);
//    glVertex3f(x2,  0,      y1);
//
//    // Right face.
//    glNormal3f( 1.0f, 0.0f, 0.0f);
//
//    glVertex3f( x2, 0,       y1);
//    glVertex3f( x2,  height, y1);
//    glVertex3f( x2,  height, y2);
//    glVertex3f( x2, 0,       y2);
//
//    // Front face;
//    glNormal3f( 0.0f, 0.0f, y2);
//
//    glVertex3f( x1, 0,       y2);
//    glVertex3f( x2, 0,       y2);
//    glVertex3f( x2,  height, y2);
//    glVertex3f( x1,  height, y2);
//
//    // Left Face;
//    glNormal3f(0, 0.0f, 0.0f);
//
//    glVertex3f( x1, 0, y1);
//    glVertex3f( x1, 0,  y2);
//    glVertex3f( x1,  height, y2);
//    glVertex3f( x1,  height, y1);
//

   // glEnd();
    glPushMatrix();
    glColor3f(r, g, b);





    if(type == 0) {
        glTranslatef(x-0.5f, height/2, y-0.5f);
        glScalef(1.0, height, 1.0);
        glutSolidCube(1.0);

    } else if(type == 1) {
        glTranslatef(x-0.5f,0.0f, y-0.5f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
       // glScalef(0.25, height, 0.25);
        glutSolidCone(0.5f, height, 10, 10);
    } else if(type == 2) {
        glTranslatef(x-0.5f, 0.0f, y-0.5f);
        glScalef(0.75, height*2.0f, 0.75);
        //glutSolidIcosahedron();
        glutSolidTetrahedron();
    }



    glPopMatrix();
}

float Building::getR() const {
    return r;
}

float Building::getG() const {
    return g;
}

float Building::getB() const {
    return b;
}

bool Building::isDisplay() const {
    return display;
}

void Building::setDisplay(bool d) {
    this->display = d;
}

float Building::getX() const {
    return x;
}

float Building::getY() const {
    return y;
}
