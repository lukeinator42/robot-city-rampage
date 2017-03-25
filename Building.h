//
// Created by Lukas Grasse on 2017-03-18.
//

#ifndef HW_OPENGL_BUILDING_H
#define HW_OPENGL_BUILDING_H


class Building {
public:
    Building(float x1, float y1, float x2, float y2, float height, float r, float g, float b )
            : x1(x1), y1(y1), x2(x2), y2(y2), height(height), r(r), g(g), b(b)  {

    }

    void draw();

private:
    float x1, y1, x2, y2, height, r, g, b;
};


#endif //HW_OPENGL_BUILDING_H
