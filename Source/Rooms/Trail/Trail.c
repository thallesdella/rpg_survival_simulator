//
// Created by Thalles on 25/10/2019.
//

#include <stdio.h>
#include <string.h>
#include "Trail.h"
#include "../../App/GameController.h"
#include "../../App/PlayerController.h"
#include "../../App/RoomController.h"
#include "../../Helpers/Helpers.h"

void initTrail() {
    rRooms[ROOM_TRAIL].iConcluded = 0;
    rRooms[ROOM_TRAIL].iVisited = 0;
    rRooms[ROOM_TRAIL].fRoom = bannerTrail;
    rRooms[ROOM_TRAIL].fRequirements = requirementsTrail;
    rRooms[ROOM_TRAIL].pOption = &oOptionsTrail;

    dOptionsTrail[0].iSecret = 0;
    dOptionsTrail[0].fAction = answerTrailA;

    dOptionsTrail[1].iSecret = 0;
    dOptionsTrail[1].fAction = answerTrailB;

    dOptionsTrail[2].iSecret = 0;
    dOptionsTrail[2].fAction = answerTrailC;

    if (rRooms[ROOM_TRAIL].iConcluded == 0) {
        strcpy(dOptionsTrail[0].sKey, "A");
        strcpy(dOptionsTrail[0].sOption, "Tentar atacar o urso");

        strcpy(dOptionsTrail[1].sKey, "B");
        strcpy(dOptionsTrail[1].sOption, "Tentar correr para as ruinas");
    }

    strcpy(dOptionsTrail[2].sKey, "C");
    strcpy(dOptionsTrail[2].sOption, "Voltar para margem do rio");

    rRooms[ROOM_TRAIL].iOptions = OPTIONS_TRAIL;
    rRooms[ROOM_TRAIL].dOptions = dOptionsTrail;
}

void refreshRoom() {
    if (rRooms[ROOM_TRAIL].iConcluded == 1) {
        strcpy(dOptionsTrail[0].sKey, "A");
        strcpy(dOptionsTrail[0].sOption, "Comer restos do urso");

        strcpy(dOptionsTrail[1].sKey, "B");
        strcpy(dOptionsTrail[1].sOption, "Ir para ruinas");
    }
}

int requirementsTrail() {
    return 1;
}

void bannerTrail() {
    refreshRoom();
    if (rRooms[ROOM_TRAIL].iConcluded == 0) {
        printf("Seguindo a trilha voce avista o que parecem ser silhuetas de ruinas, mas entre voce e elas\n");
        printf("esta o urso. voce encontra o urso distraido. Percebe que sera o melhor momento para ataca-lo. ");
    } else {
        printf("Voce passa pelo local do combate e memorias do periodo da aeronaltica vem a mente. ");
    }
}

void answerTrailA() {
    if (rRooms[ROOM_TRAIL].iConcluded == 0) {
        if (carlos.iEnergy >= 1) {
            rRooms[ROOM_TRAIL].iConcluded = 1;
            --carlos.iEnergy;

            callRoom(ROOM_TRAIL);
        } else {
            printf("Por não ter energia, voce nao e rapido o sucifiente para um ataque rapido...");
            pause();
            gameOver();
        }
    } else {
        printf("Voce se alimenta dos restos do urso...");
        pause();
        ++carlos.iEnergy;
        callRoom(ROOM_TRAIL);
    }
}

void answerTrailB() {
    if (rRooms[ROOM_TRAIL].iConcluded == 0) {
        printf("Por não ter energia, voce nao e rapido o sucifiente para um ataque rapido...");
        pause();
        gameOver();
    } else {
        callRoom(ROOM_RUINS);
    }
}

void answerTrailC() {
    callRoom(ROOM_RIVER);
}