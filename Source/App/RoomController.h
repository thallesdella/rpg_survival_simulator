//
// Created by Thalles on 24/10/2019.
//

#ifndef RPG_ROOMCONTROLLER_H
#define RPG_ROOMCONTROLLER_H

#define ROOM_NUMBER 9
#define ROOM_SERVICE 3

#define ROOM_START 0
#define ROOM_INTRODUCTION 1
#define ROOM_GAMEOVER 2
#define ROOM_FOREST 3
#define ROOM_RIVER 4
#define ROOM_CAVE 5
#define ROOM_ELF 6
#define ROOM_TRAIL 7
#define ROOM_RUINS 8

typedef struct dialog {
    int iSecret;
    char sKey[30];
    char sOption[150];

    void (*fAction)(void);
} Dialog;

typedef struct rooms {
    int iVisited;
    int iConcluded;
    int iOptions;
    Dialog *dOptions;

    void (*fRoom)(void);

    int (*fRequirements)(void);

    void *pOption;
} Room;

int serviceRooms[ROOM_SERVICE];

int currentRoom;

char cOption[50];

Room rRooms[ROOM_NUMBER];

void initRooms(void);

void callRoom(int iRoomNumber);

int checkAnswer(Dialog *dOptions, int n);

void printDialog(Dialog *dialog, int n);

int dialog(void);

int command(void);

#endif //RPG_ROOMCONTROLLER_H