//
// Created by Thalles on 25/10/2019.
//

#include <stdio.h>
#include <string.h>
#include "Ruins.h"
#include "../../App/GameController.h"
#include "../../App/RoomController.h"
#include "../../Helpers/Helpers.h"

void initRuins() {
    rRooms[ROOM_RUINS].iConcluded = 0;
    rRooms[ROOM_RUINS].iVisited = 0;
    rRooms[ROOM_RUINS].fRoom = bannerRuins;
    rRooms[ROOM_RUINS].fRequirements = requirementsRuins;
    rRooms[ROOM_RUINS].pOption = &oOptionsRuins;

    dOptionsRuins[0].iSecret = 0;
    dOptionsRuins[0].fAction = answerRuinsA;

    dOptionsRuins[1].iSecret = 0;
    dOptionsRuins[1].fAction = answerRuinsB;

    dOptionsRuins[2].iSecret = 0;
    dOptionsRuins[2].fAction = answerRuinsC;

    strcpy(dOptionsRuins[0].sKey, "A");
    strcpy(dOptionsRuins[0].sOption, "Examinar artefato");

    strcpy(dOptionsRuins[1].sKey, "B");
    strcpy(dOptionsRuins[1].sOption, "Esperar ajuda");

    strcpy(dOptionsRuins[2].sKey, "C");
    strcpy(dOptionsRuins[2].sOption, "Voltar para trilha");

    rRooms[ROOM_RUINS].iOptions = OPTIONS_RUINS;
    rRooms[ROOM_RUINS].dOptions = dOptionsRuins;
}

int requirementsRuins() {
    return 1;
}

void bannerRuins() {
    printf("Ao chegar nessas ruinas voce percebe que algumas pessoas estiveram ali estudando o local.\n");
    printf("Existe uma pedra esquisita emitindo uma especie de luz. Voce nao entende muito bem o que e aquilo,\n");
    printf("mas sabe que provavelmente os pesquisadores vão voltar. ");
}

void answerRuinsA() {
    printf("Em Construcao... Proxima atualizacao...\n\n");
    pause();
    gameOver();
}

void answerRuinsB() {
    printf("Apos um dia os pesquisadores voltam e te encontram. Eles chamam socorro e tudo fica bem...\n\n");
    pause();
    gameOver();
}

void answerRuinsC() {
    callRoom(ROOM_TRAIL);
}
