//
// Created by Lukas Grasse on 2017-03-18.
//

#ifndef HW_OPENGL_BUILDINGFACTORY_H
#define HW_OPENGL_BUILDINGFACTORY_H
#include "Building.h"
#include <vector>

class BuildingFactory {
public:
    BuildingFactory(float min, float max, float grid_size) : min(min), max(max), grid_size(grid_size) {

    }

    void draw();

    void generate();

private:
    float min, max, grid_size;
    std::vector<Building> buildings;
public:
    const std::vector<Building> &getBuildings() const;
};


#endif //HW_OPENGL_BUILDINGFACTORY_H
