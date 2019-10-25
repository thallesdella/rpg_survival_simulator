//
// Created by Thalles on 25/10/2019.
//

#ifndef RPG_RUINS_H
#define RPG_RUINS_H

#include "../../App/RoomController.h"

#define OPTIONS_RUINS 3

typedef struct optionsRuins {

} OptionsRuins;

Dialog dOptionsRuins[OPTIONS_RUINS];
OptionsRuins oOptionsRuins;

void initRuins(void);

int requirementsRuins(void);

void bannerRuins(void);

void answerRuinsA(void);

void answerRuinsB(void);

void answerRuinsC(void);

#endif //RPG_RUINS_H
