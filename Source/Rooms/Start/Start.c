//
// Created by Thalles on 24/10/2019.
//

#include <stdio.h>
#include "Start.h"
#include "../../App/RoomController.h"
#include "../../Helpers/Helpers.h"

void initStart() {
    rRooms[ROOM_START].iConcluded = 0;
    rRooms[ROOM_START].iVisited = 0;
    rRooms[ROOM_START].iOptions = OPTIONS_START;
    rRooms[ROOM_START].dOptions = &dOptionsStart;
    rRooms[ROOM_START].fRoom = bannerStart;
    rRooms[ROOM_START].fRequirements = requirementsStart;
}

int requirementsStart() {
    return 1;
}

void bannerStart() {
    printf(" _____ _   _______ _   _ _____ _   _  ___  _           \n");
    printf("/  ___| | | | ___ | | | |_   _| | | |/ _ \\| |          \n");
    printf("\\ `--.| | | | |_/ | | | | | | | | | / /_\\ | |          \n");
    printf(" `--. | | | |    /| | | | | | | | | |  _  | |          \n");
    printf("/\\__/ | |_| | |\\ \\\\ \\_/ /_| |_\\ \\_/ | | | | |____      \n");
    printf("\\____/ \\___/\\_| \\_|\\___/ \\___/ \\___/\\_| |_\\_____/      \n");
    printf("                                                       \n");
    printf("                                                       \n");

    printf(" _____ ________  ____   _ _      ___ _____ ___________ \n");
    printf("/  ___|_   _|  \\/  | | | | |    / _ |_   _|  _  | ___ \\\n");
    printf("\\ `--.  | | | .  . | | | | |   / /_\\ \\| | | | | | |_/ /\n");
    printf(" `--. \\ | | | |\\/| | | | | |   |  _  || | | | | |    / \n");
    printf("/\\__/ /_| |_| |  | | |_| | |___| | | || | \\ \\_/ | |\\ \\ \n");
    printf("\\____/ \\___/\\_|  |_/\\___/\\_____\\_| |_/\\_/  \\___/\\_| \\_|\n");
    printf("                                                       \n");
    printf("         ################################              \n");
    printf("         ###  An Adventure of Carlos  ###              \n");
    printf("         ################################              \n");
    printf("                                                       \n");

    printf("Lista de comandos disponivel em /help\n\n");

    pause();
    callRoom(ROOM_INTRODUCTION);
}