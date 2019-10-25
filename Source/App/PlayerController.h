//
// Created by Thalles on 24/10/2019.
//

#ifndef RPG_PLAYERCONTROLLER_H
#define RPG_PLAYERCONTROLLER_H

typedef struct items {
    int iMetal;
} Items;

typedef struct player {
    int iLife;
    int iEnergy;
    Items inventory;
} Player;

Player carlos;

void birth(void);

void death(void);

#endif //RPG_PLAYERCONTROLLER_H