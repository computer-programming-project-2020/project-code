#include <stdlib.h>

void clearScreen() {
    #ifdef _WIN64
        system("cls");
    #else
        system("clear");
    #endif
}