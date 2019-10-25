//
// Created by Thalles on 24/10/2019.
//

#include "PlayerController.h"

void birth() {
    carlos.iLife = 0;
    carlos.iEnergy = 0;

    Items inventory;
    inventory.iMetal = 0;

    carlos.inventory = inventory;
}

void death() {
    ++carlos.iLife;
}