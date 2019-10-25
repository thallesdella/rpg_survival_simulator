//
// Created by Thalles on 25/10/2019.
//

#include "TimeController.h"
#include "RoomController.h"

void initTimer() {
    iRounds = 0;
    iAttempts = 0;
}

void countTime() {
    incrementRound();
    incrementAttempt();
}

void incrementRound() {
    int iIncrement = 1;

    for (int i = 0; i < ROOM_SERVICE; ++i) {
        if (serviceRooms[i] == currentRoom) {
            iIncrement = 0;
        }
    }

    if (iIncrement == 1) {
        ++iRounds;
    }
}

void incrementAttempt() {
    if (currentRoom == ROOM_START) {
        ++iAttempts;
    }
}