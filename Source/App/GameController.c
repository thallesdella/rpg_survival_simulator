//
// Created by Thalles on 24/10/2019.
//

#include "GameController.h"
#include "PlayerController.h"
#include "RoomController.h"
#include "TimeController.h"

void startGame() {
    initRooms();
    initTimer();
    birth();
    callRoom(ROOM_START);
}

void gameOver() {
    death();
    callRoom(ROOM_GAMEOVER);
}