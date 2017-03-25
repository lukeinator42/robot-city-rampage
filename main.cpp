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

Landscape landscape(-102.0f, 102.0f, 102);

/* Look at Variables */
float EyeX = 0;
float EyeY = 100;
float EyeZ = 0;

float LaX = 50;
float LaY = 0;
float LaZ = -50;

void draw(void) {
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluLookAt(EyeX, EyeY, EyeZ,
	       LaX,  LaY,  LaZ,
	         0,    1,    0);

    glMatrixMode(GL_MODELVIEW);

    
    glMatrixMode(GL_MODELVIEW);


    landscape.drawCityGround();

    glutWireCube(10.0f);


    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-110.0, 110.0, 0.0, 110.0, 5.0, 200.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myClick(int button, int state, int x, int y){}

void myCBKey(unsigned char key, int x, int y)
{
   /* Eye at var */
   if(key == 119){ EyeX += 0.5; LaX += 0.5; } /* w */
   if(key == 115){ EyeX -= 0.5; LaX -= 0.5; } /* s */

   if(key == 101){ EyeY += 0.5; LaY += 0.5; } /* e */
   if(key == 113){ EyeY -= 0.5; LaY -= 0.5; } /* q */

   if(key ==  97){ EyeZ += 0.5; LaZ += 0.5; } /* a */
   if(key == 100){ EyeZ -= 0.5; LaZ -= 0.5; } /* d */

   /* Look at var */
   if(key == 105){ LaX += 0.5; } /* i */
   if(key == 107){ LaX -= 0.5; } /* k */

   if(key == 117){ LaY += 0.5; } /* u */
   if(key == 111){ LaY -= 0.5; } /* o */

   if(key == 106){ LaZ += 0.5; } /* j */
   if(key == 108){ LaZ -= 0.5; } /* l */
}


//Main program

int main(int argc, char **argv) {

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
    return 0;
}
