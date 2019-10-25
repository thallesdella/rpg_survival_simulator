//
// Created by Thalles on 25/10/2019.
//

#ifndef RPG_TRAIL_H
#define RPG_TRAIL_H

#include "../../App/RoomController.h"

#define OPTIONS_TRAIL 3

typedef struct optionsTrail {

} OptionsTrail;

Dialog dOptionsTrail[OPTIONS_TRAIL];
OptionsTrail oOptionsTrail;

void initTrail(void);

int requirementsTrail(void);

void bannerTrail(void);

void answerTrailA(void);

void answerTrailB(void);

void answerTrailC(void);

#endif //RPG_TRAIL_H
