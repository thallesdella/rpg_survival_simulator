//
// Created by Thalles on 24/10/2019.
//

#ifndef RPG_ELF_H
#define RPG_ELF_H

#include "../../App/RoomController.h"

#define OPTIONS_ELF 2

typedef struct optionsElf {

} OptionsElf;

Dialog dOptionsElf[OPTIONS_ELF];
OptionsElf oOptions;

void initElf(void);

int requirementsElf(void);

void bannerElf(void);

void answerElfA(void);

void answerElfB(void);

#endif //RPG_ELF_H
