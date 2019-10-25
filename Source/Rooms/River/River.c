//
// Created by Thalles on 24/10/2019.
//

#include <stdio.h>
#include <string.h>
#include "River.h"
#include "../../App/GameController.h"
#include "../../App/PlayerController.h"
#include "../../App/RoomController.h"
#include "../../Helpers/Helpers.h"

void initRiver() {
    dOptionsRiver[0].iSecret = 0;
    strcpy(dOptionsRiver[0].sKey, "A");
    strcpy(dOptionsRiver[0].sOption, "Interagir com duende");
    dOptionsRiver[0].fAction = answerRiverA;

    dOptionsRiver[1].iSecret = 0;
    strcpy(dOptionsRiver[1].sKey, "B");
    strcpy(dOptionsRiver[1].sOption, "Atravessar o rio");
    dOptionsRiver[1].fAction = answerRiverB;

    dOptionsRiver[2].iSecret = 0;
    strcpy(dOptionsRiver[2].sKey, "C");
    strcpy(dOptionsRiver[2].sOption, "Seguir trilha");
    dOptionsRiver[2].fAction = answerRiverC;

    rRooms[ROOM_RIVER].iConcluded = 0;
    rRooms[ROOM_RIVER].iVisited = 0;
    rRooms[ROOM_RIVER].iOptions = OPTIONS_RIVER;
    rRooms[ROOM_RIVER].dOptions = dOptionsRiver;
    rRooms[ROOM_RIVER].fRoom = bannerRiver;
    rRooms[ROOM_RIVER].fRequirements = requirementsRiver;
}

int requirementsRiver() {
    if (carlos.iEnergy == 0 && rRooms[ROOM_CAVE].iConcluded == 0) {
        return 0;
    }
    return 1;
}

void bannerRiver() {
    printf("Na outra margem do rio voce nao sabe se e uma aluciacao da sua cabeca por causa da queda\n");
    printf("ou se esta ficando maluco, mas voce voce um duende.");
}

void answerRiverA() {
    callRoom(ROOM_ELF);
}

void answerRiverB() {
    if (carlos.iEnergy > 0) {
        --carlos.iEnergy;
        callRoom(ROOM_FOREST);
    } else {
        printf("Voce morreu afogado ao tentar atravessar o rio por estar muito cansado...\n\n");
        pause();
        gameOver();
    }
}

void answerRiverC() {
    callRoom(ROOM_TRAIL);
}