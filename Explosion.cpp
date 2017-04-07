//
// Created by Lukas Grasse on 2017-04-07.
//

#include "Explosion.h"
#include <cmath>


float Explosion::getX() const {
    return x;
}

void Explosion::setX(float x) {
    Explosion::x = x;
}

float Explosion::getY() const {
    return y;
}

void Explosion::setY(float y) {
    Explosion::y = y;
}
void Explosion::draw() {
    if(radius<10.0f && exploding) {

        for(int j=0; j<10; j++) {
            float ev = 0.1f;

            for (float i = (float) -acos(-1.0f); i < acos(-1.0f); i+=ev) {
                glPushMatrix();
                glTranslatef(x + radius * (float) cos(i), (float) j, y + radius * (float) sin(i));
                glutSolidCube(0.1f);
                glColor3f(r, g, b);
                glPopMatrix();
                ev += 0.05f;
            }

        }

    radius += 0.6f;

    } else {
        radius = 0.0f;
        exploding = false;
    }

}
void Explosion::start() {
    radius = 0.0f;
    exploding = true;

}

Explosion::Explosion(float x, float y) : x(x), y(y) { exploding = false; }

void Explosion::setR(float r) {
    Explosion::r = r;
}

void Explosion::setG(float g) {
    Explosion::g = g;
}

void Explosion::setB(float b) {
    Explosion::b = b;
}
