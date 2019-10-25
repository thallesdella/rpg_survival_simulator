//
// Created by Thalles on 24/10/2019.
//

#include <stdio.h>
#include "Introduction.h"
#include "../../App/RoomController.h"
#include "../../Helpers/Helpers.h"

void initIntroduction() {
    rRooms[ROOM_INTRODUCTION].iConcluded = 0;
    rRooms[ROOM_INTRODUCTION].iVisited = 0;
    rRooms[ROOM_INTRODUCTION].iOptions = OPTIONS_INTRODUCTION;
    rRooms[ROOM_INTRODUCTION].dOptions = &dOptionsIntroduction;
    rRooms[ROOM_INTRODUCTION].fRoom = bannerIntroduction;
    rRooms[ROOM_INTRODUCTION].fRequirements = requirementsIntroduction;
}

int requirementsIntroduction() {
    return 1;
}

void bannerIntroduction() {
    printf("Carlos passou varios anos de sua vida servindo a aeronautica. Agora nao o faz mais, ja esta\n");
    printf("aposentado. Passa o resto da vida aproveitando um rancho no alaska.\n");
    printf("Um dia, estava pilotando seu pequeno aviao quando uma falha no motor fez ele perder o controle\n");
    printf("e cair inconciente no meio de uma floresta. Quando recobrou a conciencia perbecebeu que...\n\n");

    pause();
    callRoom(ROOM_FOREST);
}