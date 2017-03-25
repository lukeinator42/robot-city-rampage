#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif

#include <string.h>
#include "Landscape.h"

Landscape landscape(-51.0f, 51.0f, 102);

/* Look at Variables */
float EyeX = 0;
float EyeY = 1;
float EyeZ = -2;

float LaX = 0;
float LaY = 0;
float LaZ = 0;


void myClick(int button, int state, int x, int y){}

void myCBKey(unsigned char key, int x, int y)
{
   /* Eye at var */
   if(key == 119){ EyeZ += 0.5; LaZ += 0.5; } /* w */
   if(key == 115){ EyeZ -= 0.5; LaZ -= 0.5; } /* s */

   if(key == 101){ EyeY += 0.05; LaY += 0.05; } /* e */
   if(key == 113){ EyeY -= 0.05; LaY -= 0.05; } /* q */

   if(key ==  97){ EyeX += 0.5; LaX += 0.5; } /* a */
   if(key == 100){ EyeX -= 0.5; LaX -= 0.5; } /* d */

   /* Look at var */
   if(key == 105){ LaZ += 0.5; } /* i */
   if(key == 107){ LaZ -= 0.5; } /* k */

   if(key == 117){ LaY += 0.5; } /* u */
   if(key == 111){ LaY -= 0.5; } /* o */

   if(key == 106){ LaX += 0.5; } /* j */
   if(key == 108){ LaX -= 0.5; } /* l */
}



void draw() {

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    /* clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);

    /* Set the color to black */
    glColor3f (1.0, 1.0, 1.0);

    /* Clear the current matrix */
    glLoadIdentity();

    /* Viewing transformation */
    gluLookAt(EyeX, EyeY, EyeZ,   /* Eye */
              LaX, LaY, LaZ,   /* Look at */
              0.0, 1.0, 0.0);  /* Up vector */


    landscape.drawCityGround();

    //glTranslatef(0, 0, 1.0f);
    glutSolidCube(0.25);

    glutSwapBuffers();
}


void reshape(int w, int h)
{
    /* Set the view port */
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);

    /* Projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, /* Left and right boundary */
              -1.0, 1.0, /* bottom and top boundary */
              1.5, 20.0); /* near and far boundary */
    glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char** argv) {
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