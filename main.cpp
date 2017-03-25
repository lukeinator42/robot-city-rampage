#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif

#include <iostream>
#include <string.h>
#include "Landscape.h"
#include "Building.h"
#include "BuildingFactory.h"

Landscape landscape(-59.0f, 59.0f, 118);

BuildingFactory buildingFactory(-59.0f, 59.0f, 118);

/* Look at Variables */
float EyeX = 0.f;
float EyeY = 1.5f;
float EyeZ = -2.f;

float LaX = 0.f;
float LaY = 0.f;
float LaZ = 0.f;

float botX = 0.f;
float botY = 0.f;
float botZ = 0.f;


int rotNorm = 0;
float rot = 0.f;
float pos[2][4] = { {0.f, -1.f,  0.f, 1.f},
		    {1.f,  0.f, -1.f, 0.f} };

void myClick(int button, int state, int x, int y){}

void turn(bool direction)
{
   float dir = -1;
   if(direction)
      dir = 1;
   
   if((int)botX % 6 == 0 && (int)botZ % 6 == 0)
   {
      // NOTE
      // should be 90 in post
      rot += (dir*90);
      rotNorm = (rotNorm + (int)dir) % 4;
   }
}


void myCBKey(unsigned char key, int x, int y)
{
   if(key == 122) /* z - push forward*/
   {
      botX += pos[0][rotNorm];
      botZ += pos[1][rotNorm];
      
      EyeX += pos[0][rotNorm];
      EyeZ += pos[1][rotNorm];

      LaX += pos[0][rotNorm];
      LaZ += pos[1][rotNorm];
   }
   
   else if(key == 113){ turn(true);  } /* q - turn left*/
   else if(key ==  97){ turn(false); } /* a - turn right*/
   else
      std::cout << "No function for key: " << key << "\n";  
}

void draw() {

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    
    /* clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);

    /* Clear the current matrix */
    glLoadIdentity();

    /* Viewing transformation */
    gluLookAt(EyeX, EyeY, EyeZ,  /*  Eye  */
              LaX, LaY, LaZ,    /* Look at */
              0.0, 1.0, 0.0);  /* Up vector */


    landscape.drawCityGround();

    buildingFactory.draw();
    
    /* temp robot */
    glPushMatrix ();
    glColor3f (0.0, 0.0, 0.0);
    glTranslatef (botX, botY, botZ);
    glRotatef (rot, 0.f, 1.f, 0.f);
    glutSolidCube (0.25);
    glLoadIdentity ();
    glPopMatrix ();
    /* end of temp-bot */

    glutSwapBuffers();
}


void reshape(int w, int h)
{
    /* Set the view port */
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);

    /* Projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0,   /* Left and right boundary */
              -1.0, 1.0,   /* bottom and top boundary */
              1.5, 200.0); /* near and far boundary   */
    glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char** argv) {

    buildingFactory.generate();

    glutInit(&argc, argv);

    /*Setting up  The Display
    /    -RGB color model + Alpha Channel = GLUT_RGBA
    */
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    //Configure Window Postion
    glutInitWindowPosition(50, 25);

    //Configure Window Size
    glutInitWindowSize(480,480);

    //Create Window
    glutCreateWindow("Robot City Rampage!!");

    //Call to the drawing function
    glutDisplayFunc(& draw);
    glutIdleFunc(& draw);
    glutMouseFunc(&myClick);
    glutKeyboardFunc(&myCBKey);
    glutReshapeFunc(& reshape);

    // Loop require by OpenGL
    glutMainLoop();
}
