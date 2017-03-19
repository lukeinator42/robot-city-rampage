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


const float MIN = 0.f;
const float MAX = 101.f;

int CITY[102][102][2];

void draw(void) {

    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glutSwapBuffers();
}

void initLandScape()
{
   // init the stored city
   memset(CITY, -1, sizeof CITY);
}

void drawCityGround()
{
   glBegin(GL_QUADS);

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

    // User defined init
    initLandScape();
    

    
    // Loop require by OpenGL
    glutMainLoop();
    return 0;
}
