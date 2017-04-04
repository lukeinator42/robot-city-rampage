//
// Created by Lukas Grasse on 2017-03-18.
//

#ifndef HW_OPENGL_BUILDINGFACTORY_H
#define HW_OPENGL_BUILDINGFACTORY_H
#include "Building.h"
#include <vector>

class BuildingFactory {
public:
    BuildingFactory(int min, int max, int grid_size);

    void draw();

    void generate();

private:
    int min, max, grid_size;
    std::vector<Building*> buildings;
public:
    virtual ~BuildingFactory();

    std::vector<Building*> &getBuildings() ;
};


#endif //HW_OPENGL_BUILDINGFACTORY_H
