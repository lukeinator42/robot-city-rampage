//
// Created by Lukas Grasse on 2017-03-18.
// Added Code by Mitchell Wever on 2017-03-29
//
#include <stdlib.h>
#include <stdio.h>    
#include <string.h>  // For spring operations.
#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif
#include "Robot.h"

Robot::Robot(){
  
}

Robot::Robot(float ROT){
   /*glPushMatrix();
   body();
   glPopMatrix();
   
   //neck
   neck();
   
   //head
   glPushMatrix();
   glTranslatef(2,25,3);
   glRotatef(ROT, 0,1,0);
   glTranslatef(-2,-25,-3);
   head();
   glPopMatrix();
   glLoadIdentity();
   glPopMatrix();*/
}
void Robot::head(float ROTa){
   //top
   glPushMatrix();
   glColor3f(1,0,0);
   glBegin(GL_QUADS);
   glVertex3f(-2, 2, 7);
   glVertex3f(5, 2, 7);
   glVertex3f(5, 2, 0);
   glVertex3f(-2, 2, 0);
   glEnd();
   glLoadIdentity();
   glPopMatrix();

   //antenna
   glPushMatrix();
   glColor3f(0,0,1);
   glTranslatef(2,4,4);
   glRotatef(-ROTa,0,1,0);
   glTranslatef(1,0,0);
   //glRotatef(ROTa,0,1,0);
   glRotatef(90,1,0,0);
   glBegin(GL_POLYGON);
   GLUquadricObj *obj2 = gluNewQuadric();
   gluCylinder(obj2, 1.0, 1, 2, 100, 100);
   glEnd();
   glLoadIdentity();
   glPopMatrix();

   //rest of head
   glPushMatrix();
   glColor3f(0,1,0);
   glTranslatef(0,0,0);

   //front
   glBegin(GL_QUADS);
   glVertex3f(-2,2,0);
   glVertex3f(5,2,0);
   glVertex3f(5,-5,0);
   glVertex3f(-2,-5,0);
   glEnd();
   //left side
   glBegin(GL_QUADS);
   glVertex3f(-2, -5, 0);
   glVertex3f(-2, -5, 7);
   glVertex3f(-2, 2, 7);
   glVertex3f(-2, 2, 0);
   glEnd();
   //back
   glBegin(GL_QUADS);
   glVertex3f(-2, -5, 7);
   glVertex3f(5,-5, 7);
   glVertex3f(5,2,7);
   glVertex3f(-2, 2, 7);
   glEnd();
   //right side
   glBegin(GL_QUADS);
   glVertex3f(5, 2, 7);
   glVertex3f(5, -5, 7);
   glVertex3f(5, -5, 0);
   glVertex3f(5, 2, 0);
   glEnd();
   
   glBegin(GL_QUADS);
   glVertex3f(-2, -5, 0);
   glVertex3f(5, -5, 0);
   glVertex3f(5, -5, 7);
   glVertex3f(-2, -5, 7);
   glEnd();
   glLoadIdentity();
   glPopMatrix();

   //left eye
   glPushMatrix();
   glColor3f(1,0,0);
   glTranslatef(3,0,-0.01);
   glBegin(GL_POLYGON);
   GLUquadricObj *obj = gluNewQuadric();
   gluCylinder(obj, 1.0, 1, 0.05, 100, 100);
   glEnd();
   glLoadIdentity();
   glPopMatrix();

   //right eye
   glPushMatrix();
   glColor3f(1,0,0);
   glTranslatef(0,0,-0.01);
   glBegin(GL_POLYGON);
   GLUquadricObj *obj1 = gluNewQuadric();
   gluCylinder(obj1, 1.0, 1, 0.05, 100, 100);
   glEnd();
   glLoadIdentity();
   glPopMatrix();
}
void Robot::body(){
   glPushMatrix();
   glColor3f(0.5,0,1);
   glBegin(GL_POLYGON);
   glVertex3f(0,0,10);
   glVertex3f(0,20,10);
   glVertex3f(0,20,0);
   glVertex3f(0,0,0);
   glEnd();
   glLoadIdentity();
   glPopMatrix();
   
   //left
   glPushMatrix();
   glColor3f(0.5,1,0);
   glBegin(GL_POLYGON);
   glVertex3f(10,20,0);
   glVertex3f(10,20,10);
   glVertex3f(10,0,10);
   glVertex3f(10,0,0);
   glEnd();
   glLoadIdentity();
   glPopMatrix();
  
   
//front
   glPushMatrix();
   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex3f(0,0,10);
   glVertex3f(10,0,10);
   glVertex3f(10,20,10);
   glVertex3f(0,20,10);
   glEnd();
   glLoadIdentity();
   glPopMatrix();

//back
   glPushMatrix();
   glColor3f(1,0,1);
   glBegin(GL_POLYGON);
   glVertex3f(0,0,0);
   glVertex3f(0,20,0);
   glVertex3f(10,20,0);
   glVertex3f(10,0,0);
   glEnd();
   glLoadIdentity();
   glPopMatrix();

//back panels
   glPushMatrix();
   glColor3f(0,0.5,1);
   glBegin(GL_POLYGON);
   glVertex3f(2,10,-0.01);
   glVertex3f(5,18,-0.01);
   glVertex3f(8,10,-0.01);
   glEnd();
   glBegin(GL_POLYGON);
   glVertex3f(2,2,-0.01);
   glVertex3f(5,10,-0.01);
   glVertex3f(8,2,-0.01);
   glEnd();
   glLoadIdentity();
   glPopMatrix();
   
   //front panel
   glPushMatrix();
   glColor3f(0,0.5,1);
   glBegin(GL_POLYGON);
   glVertex3f(2,2,10.01);
   glVertex3f(8,2,10.01);
   glVertex3f(8,18,10.01);
   glVertex3f(2,18,10.01);
   glEnd();
   glLoadIdentity();
   glPopMatrix();
   //top
   glPushMatrix();
   glColor3f(1,1,0);
   glBegin(GL_POLYGON);
   glVertex3f(0,20,0);
   glVertex3f(0,20,10);
   glVertex3f(10,20,10);
   glVertex3f(10,20,0);
   glEnd();
   glLoadIdentity();
   glPopMatrix();
}
void Robot::neck(){
   glPushMatrix();
   glTranslatef(7,26,9);
   glRotatef(180, 0,1,0);
   glPushMatrix();
   glColor3f(0,1,1);
   glTranslatef(1.5,-5,3.8);
   glRotatef(90,1,0,0);
   glBegin(GL_POLYGON);
   GLUquadricObj *obj4 = gluNewQuadric();
   gluCylinder(obj4, 3.5, 3.5, 1, 100, 100);
   glEnd();
   glLoadIdentity();
   glPopMatrix();
}

void Robot::draw(float rot, float rota){
   glPushMatrix();
   body();
   glPopMatrix();
   
   //neck
   neck();
   //head
   glPushMatrix();
   glTranslatef(2,25,3);
   glRotatef(rota, 0,1,0);
   glTranslatef(-2,-25,-3);
   head(rot);
   glPopMatrix();
   glLoadIdentity();
   glPopMatrix();
}
