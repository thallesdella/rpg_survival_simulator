//
// Created by Thalles on 24/10/2019.
//

#include <stdio.h>
#include <string.h>
#include "Elf.h"
#include "../../App/PlayerController.h"
#include "../../App/RoomController.h"
#include "../../Helpers/Helpers.h"

void initElf() {
    dOptionsElf[0].iSecret = 1;
    strcpy(dOptionsElf[0].sKey, "42");
    strcpy(dOptionsElf[0].sOption, "Ele quer que advinhe o numero que esta pensando");
    dOptionsElf[0].fAction = answerElfA;

    dOptionsElf[1].iSecret = 0;
    strcpy(dOptionsElf[1].sKey, "A");
    strcpy(dOptionsElf[1].sOption, "Voltar para margem do rio");
    dOptionsElf[1].fAction = answerElfB;

    rRooms[ROOM_ELF].iConcluded = 0;
    rRooms[ROOM_ELF].iVisited = 0;
    rRooms[ROOM_ELF].iOptions = OPTIONS_ELF;
    rRooms[ROOM_ELF].dOptions = dOptionsElf;
    rRooms[ROOM_ELF].fRoom = bannerElf;
    rRooms[ROOM_ELF].fRequirements = requirementsElf;
    rRooms[ROOM_ELF].pOption = &oOptions;
}

int requirementsElf() {
    if (carlos.iEnergy >= 3) {
        return 0;
    }
    return 1;
}

void bannerElf() {
    if (rRooms[ROOM_ELF].iVisited % 7 == 0) {
        printf("Voce pensa, se ao menos existice uma resposta pra tudo...\n");
    }
    printf("Voce olha pro duende, o duende olha para voce. Ele sussurra alguma coisa. ");
}

void answerElfA() {
    ++carlos.iEnergy;
    printf("O duende te entrega um pessego e voce come...\n\n");
    pause();
    callRoom(ROOM_RIVER);
}

void answerElfB() {
    callRoom(ROOM_RIVER);
}