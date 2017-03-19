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

Landscape landscape(0.0f, 102.0f, 102);


void draw(void) {
    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    landscape.drawCityGround();

    // User defined init
    glFrustum(-10.0, 110.0, -10.0, 110.0, -10, 100.0);

    gluLookAt(0, 5, 0, 50, 0, 50, 1, 0, 0);




    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-10.0, 110.0, -10.0, 110.0, -5.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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
    glutDisplayFunc(draw);

    glutReshapeFunc(& reshape);


    
    // Loop require by OpenGL
    glutMainLoop();
    return 0;
}
