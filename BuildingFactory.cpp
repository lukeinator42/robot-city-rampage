//
// Created by Lukas Grasse on 2017-03-18.
//

#include "BuildingFactory.h"

void BuildingFactory::draw() {
    for(int i=0; i<buildings.size(); i++)
        buildings[i].draw();

}

void BuildingFactory::generate() {

}

const std::vector<Building> &BuildingFactory::getBuildings() const {
    return buildings;
}
