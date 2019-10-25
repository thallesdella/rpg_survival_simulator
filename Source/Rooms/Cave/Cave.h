//
// Created by Thalles on 24/10/2019.
//

#ifndef RPG_CAVE_H
#define RPG_CAVE_H

#include "../../App/RoomController.h"

#define OPTIONS_CAVE 3

Dialog dOptionsCave[OPTIONS_CAVE];

void initCave(void);

int requirementsCave(void);

void bannerCave(void);

void answerCaveA(void);

void answerCaveB(void);

void answerCaveC(void);

#endif //RPG_CAVE_H