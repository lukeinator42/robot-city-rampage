//
// Created by Lukas Grasse on 2017-03-18.
//

#ifndef HW_OPENGL_BUILDING_H
#define HW_OPENGL_BUILDING_H
#include <cstdlib>
#include <ctime>
#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif


class Building {
public:
    Building(float x, float y, float height, float r, float g, float b, int type)
            : x(x), y(y), height(height), r(r), g(g), b(b), type(type), display(true)  {


    }

    void draw();

private:
    float x, y,  height, r, g, b;
public:
    float getX() const;

    float getY() const;

public:
    float getR() const;

    float getG() const;

    float getB() const;

private:
    int type;
    bool display;

public:
    bool isDisplay() const;

    void setDisplay(bool display);


};


#endif //HW_OPENGL_BUILDING_H
