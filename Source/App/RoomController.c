//
// Created by Thalles on 24/10/2019.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "RoomController.h"
#include "GameController.h"
#include "PlayerController.h"
#include "TimeController.h"
#include "../Helpers/Helpers.h"
#include "../Helpers/Colors.h"
#include "../Rooms/Start/Start.h"
#include "../Rooms/Introduction/Introduction.h"
#include "../Rooms/GameOver/GameOver.h"
#include "../Rooms/Forest/Forest.h"
#include "../Rooms/River/River.h"
#include "../Rooms/Cave/Cave.h"
#include "../Rooms/Elf/Elf.h"
#include "../Rooms/Trail/Trail.h"
#include "../Rooms/Ruins/Ruins.h"

void initRooms() {
    currentRoom = 0;

    serviceRooms[0] = ROOM_START;
    serviceRooms[1] = ROOM_INTRODUCTION;
    serviceRooms[2] = ROOM_GAMEOVER;

    initStart();
    initIntroduction();
    initGameOver();
    initForest();
    initRiver();
    initCave();
    initElf();
    initTrail();
    initRuins();
}

void callRoom(int iRoomNumber) {
    countTime();

    if (rRooms[iRoomNumber].fRequirements()) {
        ++rRooms[iRoomNumber].iVisited;
        rRooms[iRoomNumber].fRoom();
        currentRoom = iRoomNumber;

        if (rRooms[iRoomNumber].iOptions != 0) {
            printDialog(rRooms[iRoomNumber].dOptions, rRooms[iRoomNumber].iOptions);

            while (dialog() == 0 || checkAnswer(rRooms[iRoomNumber].dOptions, rRooms[iRoomNumber].iOptions) == 0) {
                printDialog(rRooms[iRoomNumber].dOptions, rRooms[iRoomNumber].iOptions);
            }
        }

    } else {
        printf("Nao ha o que fazer por aqui...\n\n");
        pause();
        callRoom(currentRoom);
    }
}

int checkAnswer(Dialog *dOptions, int n) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(cOption, dOptions[i].sKey) == 0) {
            dOptions[i].fAction();
            return 1;
        }
    }
    return 0;
}

void printDialog(Dialog *dOptions, int n) {
    char sMsg[30];
    printf("O que voce faz?\n\n");

    for (int i = 0; i < n; ++i) {
        strcpy(sMsg, (dOptions[i].iSecret ? " " : dOptions[i].sKey));

        if (i == n - 1) {
            printf("\t%s - %s\n\n", sMsg, dOptions[i].sOption);
        } else {
            printf("\t%s - %s\n", sMsg, dOptions[i].sOption);
        }
    }
}

int dialog() {
    char color[30];
    strcpy(color, "Escolha: ");
    yellow(color);

    printf("%s", color);
    scanf("%s", cOption);

    return command();
}

int command() {
    if (strcmp(cOption, "/help") == 0) {
        printf("\t/help  - Lista de comandos\n");
        printf("\t/stats - Status do personhagem e do jogo\n");
        printf("\t/kill  - Suicidio\n\n");
        return 0;
    }

    if (strcmp(cOption, "/stats") == 0) {
        char sAmmount[10], color[30];


        if (carlos.iEnergy <= 0) {
            strcpy(color, "EMPTY");
            red(color);

            strcpy(sAmmount, color);
        } else if (carlos.iEnergy == 1) {
            strcpy(color, "LOW");
            yellow(color);

            strcpy(sAmmount, color);
        } else if (carlos.iEnergy == 2) {
            strcpy(color, "MEDIUM");
            yellow(color);

            strcpy(sAmmount, color);
        } else {
            strcpy(color, "MAX");
            green(color);

            strcpy(sAmmount, color);
        }

        printf("Player:\n\tEnergia: %s\n", sAmmount);
        printf("Jogo:\n\tRound: %i\n\tTentativa: %.0lf\n\n", iRounds, floor(iAttempts / 3.0));
        return 0;
    }

    if (strcmp(cOption, "/kill") == 0) {
        printf("Voce cometeu suicidio...");
        gameOver();
        return 0;
    }
    return 1;
}