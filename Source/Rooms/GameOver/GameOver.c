//
// Created by Thalles on 24/10/2019.
//

#include <stdio.h>
#include "GameOver.h"
#include "../../App/RoomController.h"
#include "../../Helpers/Helpers.h"

void initGameOver() {
    rRooms[ROOM_GAMEOVER].iConcluded = 0;
    rRooms[ROOM_GAMEOVER].iVisited = 0;
    rRooms[ROOM_GAMEOVER].iOptions = OPTIONS_GAMEOVER;
    rRooms[ROOM_GAMEOVER].dOptions = &dOptionsGameOver;
    rRooms[ROOM_GAMEOVER].fRoom = bannerGameOver;
    rRooms[ROOM_GAMEOVER].fRequirements = requirementsGameOver;
}

int requirementsGameOver() {
    return 1;
}

void bannerGameOver() {
    printf("  ________                       \n");
    printf(" /  _____/_____    _____   ____  \n");
    printf("/   \\  ___\\__  \\  /     \\_/ __ \\ \n");
    printf("\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ \n");
    printf(" \\______  (____  /__|_|  /\\___  >\n");
    printf("        \\/     \\/      \\/     \\/ \n");
    printf("                                 \n");
    printf("________                         \n");
    printf("\\_____  \\___  __ ___________    \n");
    printf(" /   |   \\  \\/ // __ \\_  __ \\   \n");
    printf("/    |    \\   /\\  ___/|  | \\/    \n");
    printf("\\_______  /\\_/  \\___  >__|       \n");
    printf("        \\/          \\/           \n");
    printf("\n");

    pause();

    callRoom(ROOM_START);
}