//
// Created by Lukas Grasse on 2017-03-18.
//

#ifndef HW_OPENGL_LANDSCAPE_H
#define HW_OPENGL_LANDSCAPE_H


class Landscape {
public:
    Landscape(const float min, const float max, const int grid_size);
    void initLandScape();

    const int getGRID_SIZE() const;

    void drawCityGround();


private:
    const float MIN;
    const float MAX;
    const int GRID_SIZE;
    int CITY[GRID_SIZE][GRID_SIZE][2];
};


#endif //HW_OPENGL_LANDSCAPE_H
