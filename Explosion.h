//
// Created by Lukas Grasse on 2017-04-07.
//

#ifndef HW_OPENGL_EXPOSION_H
#define HW_OPENGL_EXPOSION_H
#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif


class Explosion {

private:
    float x, y, radius;
    bool exploding;
    float r, g, b;
public:
    void setR(float r);

    void setG(float g);

    void setB(float b);

public:
    Explosion(float x, float y);
    void draw();
    void start();


public:
    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);
};


#endif //HW_OPENGL_EXPOSION_H
