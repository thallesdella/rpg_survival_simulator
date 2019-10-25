//
// Created by Thalles on 24/10/2019.
//

#include <stdio.h>
#include <string.h>
#include "Cave.h"
#include "../../App/GameController.h"
#include "../../App/PlayerController.h"
#include "../../App/RoomController.h"
#include "../../Helpers/Helpers.h"

void initCave() {
    dOptionsCave[0].iSecret = 0;
    strcpy(dOptionsCave[0].sKey, "A");
    strcpy(dOptionsCave[0].sOption, "Ataca o urso");
    dOptionsCave[0].fAction = answerCaveA;

    dOptionsCave[1].iSecret = 0;
    strcpy(dOptionsCave[1].sKey, "B");
    strcpy(dOptionsCave[1].sOption, "Foge para a floresta");
    dOptionsCave[1].fAction = answerCaveB;

    dOptionsCave[2].iSecret = 0;
    strcpy(dOptionsCave[2].sKey, "C");
    strcpy(dOptionsCave[2].sOption, "Deita e chora");
    dOptionsCave[2].fAction = answerCaveC;

    rRooms[ROOM_CAVE].iConcluded = 0;
    rRooms[ROOM_CAVE].iVisited = 0;
    rRooms[ROOM_CAVE].iOptions = OPTIONS_CAVE;
    rRooms[ROOM_CAVE].dOptions = dOptionsCave;
    rRooms[ROOM_CAVE].fRoom = bannerCave;
    rRooms[ROOM_CAVE].fRequirements = requirementsCave;
}

int requirementsCave() {
    if (rRooms[ROOM_CAVE].iConcluded) {
        return 0;
    }
    return 1;
}

void bannerCave() {
    printf("Voce entra na caverna e ve um urso. ");
}

void answerCaveA() {
    if (carlos.inventory.iMetal) {
        printf("Seu pedaco de metal nao e pario para a forca do urso...\n");
        pause();
        gameOver();
    } else {
        printf("Como voce ataca um urso sem arma???\n");
        pause();
        gameOver();
    }
}

void answerCaveB() {
    callRoom(ROOM_FOREST);
}

void answerCaveC() {
    printf("O urso sente pena de voce e vai embora. Voce acha um salmao na caverna, come e sai dela.\n\n");
    carlos.iEnergy = 1;

    rRooms[ROOM_CAVE].iConcluded = 1;
    pause();
    callRoom(ROOM_FOREST);
}