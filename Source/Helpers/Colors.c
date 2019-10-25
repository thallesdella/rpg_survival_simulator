//
// Created by Thalles on 25/10/2019.
//

#ifdef __unix__

#include <string.h>
#include "Colors.h"

void red(char *sMsg){
    unsigned int iSize = strlen(sMsg);
    char sResult[iSize + 20];

    strcpy(sResult, "\\033[31m");
    strcat(sResult, sMsg);
    strcat(sResult, "\\033[0m");
    strcpy(sMsg, sResult);
}

void green(char *sMsg){
    unsigned int iSize = strlen(sMsg);
    char sResult[iSize + 20];

    strcpy(sResult, "\\033[32m");
    strcat(sResult, sMsg);
    strcat(sResult, "\\033[0m");
    strcpy(sMsg, sResult);
}

void yellow(char *sMsg){
    unsigned int iSize = strlen(sMsg);
    char sResult[iSize + 20];

    strcpy(sResult, "\\033[33m");
    strcat(sResult, sMsg);
    strcat(sResult, "\\033[0m");
    strcpy(sMsg, sResult);
}

void blue(char *sMsg){
    unsigned int iSize = strlen(sMsg);
    char sResult[iSize + 20];

    strcpy(sResult, "\\033[34m");
    strcat(sResult, sMsg);
    strcat(sResult, "\\033[0m");
    strcpy(sMsg, sResult);
}

void magenta(char *sMsg){
    unsigned int iSize = strlen(sMsg);
    char sResult[iSize + 20];

    strcpy(sResult, "\\033[35m");
    strcat(sResult, sMsg);
    strcat(sResult, "\\033[0m");
    strcpy(sMsg, sResult);
}
void cyan(char *sMsg){
    unsigned int iSize = strlen(sMsg);
    char sResult[iSize + 20];

    strcpy(sResult, "\\033[36m");
    strcat(sResult, sMsg);
    strcat(sResult, "\\033[0m");
    strcpy(sMsg, sResult);
}

#elif defined(_WIN32) || defined(WIN32)

void red(char *sMsg) {}

void green(char *sMsg) {}

void yellow(char *sMsg) {}

void blue(char *sMsg) {}

void magenta(char *sMsg) {}

void cyan(char *sMsg) {}

#endif