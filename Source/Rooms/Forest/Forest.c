//
// Created by Thalles on 24/10/2019.
//

#include <stdio.h>
#include <string.h>
#include "Forest.h"
#include "../../App/GameController.h"
#include "../../App/PlayerController.h"
#include "../../App/RoomController.h"
#include "../../Helpers/Helpers.h"

void initForest() {
    dOptionsForest[0].iSecret = 0;
    strcpy(dOptionsForest[0].sKey, "A");
    strcpy(dOptionsForest[0].sOption, "Pegar destroco no arbusto");
    dOptionsForest[0].fAction = answerForestA;

    dOptionsForest[1].iSecret = 0;
    strcpy(dOptionsForest[1].sKey, "B");
    strcpy(dOptionsForest[1].sOption, "Atravessar o rio");
    dOptionsForest[1].fAction = answerForestB;

    dOptionsForest[2].iSecret = 0;
    strcpy(dOptionsForest[2].sKey, "C");
    strcpy(dOptionsForest[2].sOption, "Entrar na caverna");
    dOptionsForest[2].fAction = answerForestC;

    rRooms[ROOM_FOREST].iConcluded = 0;
    rRooms[ROOM_FOREST].iVisited = 0;
    rRooms[ROOM_FOREST].iOptions = OPTIONS_FOREST;
    rRooms[ROOM_FOREST].dOptions = dOptionsForest;
    rRooms[ROOM_FOREST].fRoom = bannerForest;
    rRooms[ROOM_FOREST].fRequirements = requirementsForest;
}

int requirementsForest() {
    return 1;
}

void bannerForest() {
    printf("Voce esta em uma clareira. Percebe que um dos destrocos preso em um arbusto pode ser\n");
    printf("util. Continua olhando em volta e observa um pequeno corrego e uma caverna. ");
}

void answerForestA() {
    if (carlos.inventory.iMetal) {
        printf("Voce ja coletou o pedaco de metal.\n\n");
        pause();
        callRoom(ROOM_FOREST);
    } else {
        carlos.inventory.iMetal = 1;
        printf("Pedaco de metal coletado.\n\n");
        pause();
        callRoom(ROOM_FOREST);
    }
}

void answerForestB() {
    if (carlos.iEnergy > 0) {
        --carlos.iEnergy;
        callRoom(ROOM_RIVER);
    } else {
        printf("Voce morreu afogado ao tentar atravessar o rio por estar muito cansado...\n\n");
        pause();
        gameOver();
    }
}

void answerForestC() {
    callRoom(ROOM_CAVE);
}