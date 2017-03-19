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
    // User defined init


    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glutSwapBuffers();
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


    landscape.initLandScape();
    landscape.drawCityGround();
    
    // Loop require by OpenGL
    glutMainLoop();
    return 0;
}
