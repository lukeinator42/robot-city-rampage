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
#include "Robot.h"

Robot R;

Landscape landscape(-59.0f, 59.0f, 118);

BuildingFactory buildingFactory(-59.0f, 59.0f, 118);

/* Look at Variables */
float EyeX = 0.f;
float EyeY = 10.5f;
float EyeZ = -5.0f;

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

//                           EyeX   EyeY  EyeZ
float viewChange[5][3] = { {  0.f,  EyeY, -2.f },   // F4
			   { -2.f,  EyeY, -2.f },   // F5
			   {  2.f,  EyeY, -2.f },   // F6
			   {  2.f,  EyeY,  2.f },   // F7
			   { -2.f,  EyeY,  2.f } }; // F8

/* PAUSE */
bool PAUSEBOOL = true;

//
// turns the robot based on
// a specified direction
// true  - left
// false - right
//
void turn(bool direction)
{
   // control direction
   float dir = -1;
   if(direction){ dir = 1; }  

   // if the bot is in the center
   // of a street it can turn
   if((int)botX % 6 == 0 && (int)botZ % 6 == 0)
   { rot += (dir*90); rotNorm = (rotNorm + (int)dir + 4) % 4; }
}

//
// reset the robot to center
//
void origin()
{
   EyeX =  0.f; LaX = 0.f; botX = 0.f; rot = 0.f;
   EyeY = 1.5f; LaY = 0.f; botY = 0.f; rotNorm = 0;
   EyeZ = -2.f; LaZ = 0.f; botZ = 0.f; 
}

//
// change the current view
//
void view(int changeView)
{
   EyeX = botX + viewChange[changeView][0];
   EyeY = viewChange[changeView][1];
   EyeZ = botZ + viewChange[changeView][2];
}

//
// Adds functionality for the following keys
// p - pause the game
// a - turn robot right
// q - turn robot left
// r - move robot back to center
// z - push the robot forward
//
void myCBKey(unsigned char key, int x, int y)
{
   if(key == 112) { PAUSEBOOL = !PAUSEBOOL; }

   if(PAUSEBOOL)
   {
      if(key == 122) /* z - push forward */
      {
	 botX += pos[0][rotNorm];
	 botZ += pos[1][rotNorm];
	 
	 EyeX += pos[0][rotNorm];
	 EyeZ += pos[1][rotNorm];

	 LaX += pos[0][rotNorm];
	 LaZ += pos[1][rotNorm];
      }
   
      else if(key == 113){ turn(true);  } /* q - turn left        */
      else if(key ==  97){ turn(false); } /* a - turn right       */
      else if(key == 114){ origin();    } /* r - return to origin */
   }
}

//
// Adds functionality for the following keys
// F1 - turn head forward
// F2 - turn head right
// F3 - turn head left
// F4 - move the camera back to default
// F5 - move the camera to view 1
// F6 - move the camera to view 2
// F7 - move the camera to view 3
// F8 - move the camera to view 4
// 
void specialCBKey(int key, int x, int y)
{
   if(PAUSEBOOL)
   {
      /* Head Turning Commands */
      if(key == GLUT_KEY_F1){ /*turn head forward*/; }
      else if(key == GLUT_KEY_F2){ /*TURN HEAD RIGHT*/; }
      else if(key == GLUT_KEY_F3){ /*TURN HEAD LEFT*/; }
      
      /* Look at Changing Commands */
      else if(key == GLUT_KEY_F4){ view(0); }
      else if(key == GLUT_KEY_F5){ view(1); }
      else if(key == GLUT_KEY_F6){ view(2); }
      else if(key == GLUT_KEY_F7){ view(3); }
      else if(key == GLUT_KEY_F8){ view(4); }
   }
}

//
// Returns the robots head when
// F2 or F3 key is released
//
void specialUpCBKey(int key, int x, int y)
{
   if(PAUSEBOOL)
   {
      if(key == GLUT_KEY_F2 || key == GLUT_KEY_F3)
      {
	 /* turn head forward */;
      }
   }
}

//
// Building destruction on left clicks
// 
void myClick(int button, int state, int x, int y)
{
   if(PAUSEBOOL)
   {
      
   }
}

//
// Main Drawing done here
// 
void draw()
{

   /* Clear buffer and set backdrop color */
   glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(0.1, 0.39, 0.88, 1.0);
   glMatrixMode(GL_MODELVIEW);

    /* Clear the current matrix */
    glLoadIdentity();

    /* Viewing transformation */
    gluLookAt(EyeX, EyeY, EyeZ, /*    Eye    */
              LaX, LaY, LaZ,    /*  Look at  */
              0.0, 1.0, 0.0);   /* Up vector */
  
    /* Draw the landscaps */
    landscape.drawCityGround();
    
  
    /* Draw the buildings */
    buildingFactory.draw();

    /* temp robot */
    glPushMatrix ();
    //glColor3f (0.0, 0.0, 0.0);
    glTranslatef (botX, botY, botZ);
    glRotatef (rot, 0.f, 1.f, 0.f);
    glScalef(0.1,0.1,0.1);
    R.draw();
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
    glutMouseFunc(& myClick);
    glutKeyboardFunc(& myCBKey);
    glutSpecialFunc(& specialCBKey);
    glutSpecialUpFunc(& specialUpCBKey);
    glutReshapeFunc(& reshape);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    // Loop require by OpenGL
    glutMainLoop();
}
